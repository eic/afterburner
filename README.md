# afterburner

EIC MC afterburner. Software package to provide framework independent
well validated crossing angle and beam effects C++ library and HepMC file converter (abconv) 
for Electron Ion Collider. 

**Physics simulated:**
- Crossing angle
- Beam effects (divergence, crabbing kick, etc.)
- Vertex spread (position, time)


**Software:**
- Standalone framework independent code
- Clean C++ API to embed in analysis scripts and/or frameworks
- Convenient Command Line Interface (CLI) HepMC2/3 and `root.hepmc` converter, that adds crossing_angle_hor and beam effects
- Configurable beam parameters interface (yaml files)


## Installation

The converter and benchmark require libyaml-cpp. Those are available in package managers for the most of systems:

```bash 
apt install libyaml-cpp-dev     # Debian/Ubuntu/Mint
yum install yaml-cpp-devel      # RHEL/CentOS/Fedora
```


```bash
git clone https://github.com/eic/afterburner.git
cd afterburner

# setup cmake (c++ code lives in cpp directory) 
cmake -B build -S cpp -DCMAKE_INSTALL_PREFIX=install

# to build all
cmake --build build

# to install
cmake --install build
```

**Preinstalled versions** are available in [ePIC containers](https://eic.github.io/tutorial-setting-up-environment/02-eic-shell/index.html). 


## CLI command

### Examples:

```bash
# Process my whole file, add crossing angle, beam effects, do validation plots
abconv my.hepmc

# Same, but limit the number of events to 1000 and set the output name as 'test'
abconv my.hepmc -o test -l 1000

# Just convert hepmc3 to hepmc2 don't use afterburner, don't create plots
abconv my.hepmc -f hepmc2 --ab-off --plot-off 

# Just convert hepmc3 to hepmc.root don't use afterburner, don't create plots
abconv my.hepmc -f treeroot --ab-off --plot-off 
```
Note: In the final example above, you want the `treeroot` option. The `root` option creates a (rather strange) flat file.

How exactly the afterburner works illustrated by `abconv my.hepmc` command. 


### Afterburner algorithm

1. AB opens the input file, gets beam particles and extract beam energy settings (from the first event). 
   See **beam energy settings** for the details below.

2. AB awaits that there is no crossing angle between beam particles. To check this 
   AB calculates a crossing angle between the beam particles. If the crossing angle is not zero
   and `--exit-ca` flag is set - AB exits; without the flag a warning is issued.

3. AB processes events applying crossing angle and beam effects for each event. 
   `-s,--ev-start`, `-e,--ev-end`, `-l,--limit` flags limit the number of events to process

   For each event AB draws the interaction point and the two beam directions (crossing angle, divergence, crab
   kicks), then moves the whole event, momenta and vertex positions, with one Lorentz transform: a rotation of +z
   onto the head-on beam axis, then a boost perpendicular to that axis. The boost is computed from the velocities
   |p|/E of the input's beam particles, so that both beams leave exactly along their drawn directions, a massive ion
   beam included. The beam along +z in the input becomes the ion beam.

   A Lorentz transform keeps √s, so the boost raises both beam energies by the same factor
   γ ≈ 1/cos(θ/2) ≈ 1 + θ²/8, where θ is the crossing angle (+7.8 × 10⁻⁵ at 25 mrad, +1.5 × 10⁻⁴ at 35 mrad). For nominal beam energies at the crossing, generate the head-on events at E·cos(θ/2).

4. By defaults AB also creates *.hist.root file that contains validation histograms  
   `--plot-off` flag can switch off histograms creation


P.S. Is one needs just HepMC3->HepMC2 converter one can use `--ab-off` flag to disable 
afterburner during conversion. This way **abconv** could be use as different HepMC formats
converter.


### Beam energy settings

- The input file events must have two beam particles (marked by status code 4)
- Beam particle energies should correspond to one of EIC beam energy setups:
  - ep \[GeV\]: 275x18, 275x10, 100x10, 100x5, 41x5
  - eAu \[GeV\]: 110x18, 110x10, 110x5, 41x5
- One can [the exact beam parameters](https://eicweb.phy.anl.gov/monte_carlo/afterburner/-/blob/main/cpp/afterburner/EicConfigurator.cc)
  that correspond to EIC CDR tables 3.3, 3.4, 3.5
- Using `-p/--preset` flag one can select a profile:
  - 0: IP6 High Divergence (higher luminosity) - default,
  - 1: IP6 High Acceptance
  - 2: IP6 eAu
  - 3: IP8 High Divergence (higher luminosity) - default,
  - 4: IP8 High Acceptance
  - 5: IP8 eAu
- Crossing angle is given in horizontal and vertical components
  - [Afterburner configuration](https://eicweb.phy.anl.gov/monte_carlo/afterburner/-/blob/main/cpp/afterburner/AfterburnerConfig.hh)
  
> (!) For now IP8 is a copy of IP6 parameters with 35 mrad crossing angle. It will be populated with IP8 own parameters as 
> soon as they are officially published.

### Coordinate system

AB writes events in the EIC/ePIC detector frame. The ePIC geometry and EICrecon use the same frame:

- **z** lies on the electron beam axis, which is also the detector (solenoid) axis. It points opposite to the
  electron beam's motion: electrons fly along −z, and +z is the hadron-going ("forward") direction.
- **x** points horizontally toward the center of the accelerator ring.
- **y** points up, from the ground to the sky.
- The frame is right-handed (x = y × z), with its origin at the nominal interaction point.

Seen from above, hadrons circulate counterclockwise and electrons clockwise. At either IP, +z therefore follows the
hadron beam and +x points to the ring center.

The preset beam angles are given in this frame:

- `crossing_angle_hor` is the hadron beam's angle to +z in the x-z plane, positive toward +x.
- `crossing_angle_ver` is its angle to +z in the y-z plane, positive toward +y.

| IP  | `crossing_angle_hor` | `crossing_angle_ver` | outgoing hadron beam                                        |
|-----|----------------------|----------------------|-------------------------------------------------------------|
| IP6 | −25 mrad             | +0.1 mrad            | toward the ring outside (−x), where the far-forward detectors are |
| IP8 | +35 mrad             | 0                    | toward the ring inside (+x)                                 |

<img src="docs/eic-frame.svg" alt="EIC/ePIC detector frame: ring seen from above, IP6 and IP8 in the x-z plane" width="100%"/>

Sources:

- E.C. Aschenauer, D. Holmes, K. Hamdi, *Coordinate systems used in EIC* (2022),
  [doi:10.5281/zenodo.14267257](https://doi.org/10.5281/zenodo.14267257), sec. 2 and Fig. 3:
  - hadrons circulate counterclockwise, electrons clockwise;
  - y points to the sky and x to the ring inside;
  - the detector is rotated by 8 mrad so that its z axis lies along the electron beam, with positive z in the
    hadron beam direction;
  - the outgoing hadron beam and the ZDC are on the ring-outside side.

  The [ePIC detector-integration page](https://www.epic-eic.org/detector/detector_integration.html) repeats sec. 2
  without the sentences on the electron beam.
- W. Li, CFNS summer school, 4 June 2026,
  [day 1, slide 8](https://indico.cfnssbu.physics.sunysb.edu/event/604/contributions/2328/attachments/1161/1844/2026_CFNS_summer_school_lectures_day_1.pdf):
  "Z-axis: -ve electron beam momentum", "X-axis: Points to the center of accelerator ring", "Y-Axis: Points upwards".
- The ePIC geometry sets `CrossingAngle = -0.025*rad` and `electronCrossingAngle = 0.0` in
  [`compact/definitions.xml`](https://github.com/eic/epic/blob/main/compact/definitions.xml) and places the
  far-forward magnets at x < 0.
- EICrecon gives the electron beams negative pz and the hadron beam px = pz sin(−0.025)
  ([`Beam.h`](https://github.com/eic/EICrecon/blob/main/src/algorithms/reco/Beam.h),
  `m_crossingAngle{-0.025}` in the kinematics algorithms).
- The beam-effects note (first entry of [References](#references)), sec. 3.1.1:
  - it names the same right-handed frame: z "anti-parallel to the electron direction of travel", y "to the sky",
    x "toward the inside of the ring";
  - at IP6 the beams enter from the ring inside and exit to the ring outside, and "the opposite is true for IP8".

The code fixes the signs of z and of the crossing angle. The direction of x, toward the ring center, comes from the
documents above.

### Input file requirements

- The CLI command can accept any file, that HepMC3 library can open:
  HepMC3 ascii, HepMC2 ascii, HepMC3 ROOT, HepEvt etc. 
- The input file events must have two beam particles (marked by status code 4)
- Input file should not have crossing angle and beam effects that AB simulates.
  **By default, it is not possible to apply just crossing angle or just beam effects.**
  **But!** in the upcoming version one can provide beam parameters through yaml config files,
  where one would be able to switch off crossing angle, beam effects, etc. 
- The beam energy spread must come from the generator. AB applies one Lorentz transform per event, which keeps
  the event's center-of-mass energy; independent energy spreads of the two beams change it (EIC beam-effects note,
  section 3.2.2). AB keeps the energies the input beams have, event by event.
- For the nominal beam energies after AB, generate the head-on events at E·cos(θ/2), θ the crossing angle
  (see **Afterburner algorithm**). With nominal head-on energies both beams come out higher by θ²/8.


### All options:

| Flag                 | Description                               |
|----------------------|-------------------------------------------|
| -h,--help            | Print this help message and exit|
| -v,--version         | Shows package version number |
| -o,--output TEXT     | Base name for Output files ((!) no extension)|
| -p,--preset TEXT     | Beams configuration 0: IP6 High divergence\[default\], 1: IP6 High acceptance, 2: IP6 eAu|
| -i,--in-format TEXT  | Input format: auto \[default\], hepmc2, hepmc3, hpe, lhef, gz, treeroot, root|
| -f,--out-format TEXT | Output format: hepmc3 \[default\], hepmc2, dot, none (no events file is saved)|
| -s,--ev-start INT    | Start event index (all previous are skipped)|
| -e,--ev-end INT      | End event index (end processing after this event)|
| -l,--limit UINT      | Limit number of events to process. (Shutdown after this number of parsed events)|
| --ab-off             | No afterburner is applied|
| --plot-off           | Don't produce validation plots|
| --exit-ca            | Check existing crossing angle and exit if CA>1mrad (1) |


> (1) How `--exit-ca` works exactly: when afterburner processes the first event it checks if 
> it has 2 beam particles (fails with non zero code if not) and then calculates their crossing angle
> with the `--exit-ca` is set and crossing angle absolute value is > 1mrad program ends with 0 code.
> This method is very coarse as if in a source file the crossing angle is 0 but all beam effects do exist,
> beam effects will be applied twice

-p,--preset flag, values \[0,1,2,3,4,5\] set config and auto determine energy from source file:

- "0": IP6, High divergence, auto read energy [default],
- "1": IP6, High acceptance, auto read energy
- "2": IP6, eAu, auto read energy
- "3": IP8, High divergence, auto read energy [default],
- "4": IP8, High acceptance, auto read energy
- "5": IP8, eAu, auto read energy

The other options sets energy settings manually, not checking the source file:

<table>
    <tr><td>ip6_hidiv_41x5</td><td>ip6_hidiv_100x5</td><td>ip6_hidiv_100x10</td><td>ip6_hidiv_275x10</td><td>ip6_hidiv_275x18</td></tr>
    <tr><td>ip6_hiacc_41x5</td><td>ip6_hiacc_100x5</td><td>ip6_hiacc_100x10</td><td>ip6_hiacc_275x10</td><td>ip6_hiacc_275x18</td></tr>
    <tr><td>ip6_eau_41x5  </td><td>ip6_eau_110x5  </td><td>ip6_eau_110x10  </td><td>ip6_eau_110x18  </td><td>-</td></tr>
    <tr><td>ip8_hidiv_41x5</td><td>ip8_hidiv_100x5</td><td>ip8_hidiv_100x10</td><td>ip8_hidiv_275x10</td><td>ip8_hidiv_275x18</td></tr>
    <tr><td>ip8_hiacc_41x5</td><td>ip8_hiacc_100x5</td><td>ip8_hiacc_100x10</td><td>ip8_hiacc_275x10</td><td>ip8_hiacc_275x18</td></tr>
    <tr><td>ip8_eau_41x5  </td><td>ip8_eau_110x5  </td><td>ip8_eau_110x10  </td><td>ip8_eau_110x18  </td><td>-</td></tr>
</table>

Example of manual configuration setting:

```bash
abconv -p ip6_hidiv_100x5 source_file.hepmc
``` 

> (!) For now IP8 is a copy of IP6 parameters with 35 mrad crossing angle. It will be populated with IP8 own parameters as
> soon as they are officially published.
> 

## Validation

The validation is performed by comparison of the resulting particle distributions with
[Pythia8 beam effects](https://github.com/bspage912/eicSimuBeamEffects) simulation. 
The later was also validated with Fun4All afterburner implementation. 


To apply benchmarks. Head-on data (no crossing angle nor effects) is located:

```
https://eics3.sdcc.bnl.gov:9000/minio/eictest/ATHENA/WG/BeamEffects/
```

The validation plots are generated and can be viewed in [python/comparison.ipynb](python/comparison.ipynb)

Essential plots from the latest validation run: 

> The discrepancy in low Eta has been explained by a slight phase space difference
> in generated headon and full beam effects files on Pythia8 side. 
> TL;DR; [It is Fine](https://cdn.vox-cdn.com/thumbor/qQPUPBlaiVYrsXg5QM1QQYVgH34=/0x0:900x500/1400x1400/filters:focal(378x178:522x322):format(jpeg)/cdn.vox-cdn.com/uploads/chorus_image/image/49493993/this-is-fine.0.jpg)

<table>
  <thead>
    <tr>
      <th>41x5 GeV</th>
      <th>100x10 GeV</th>
      <th>275x18 GeV</th>
    </tr>
  </thead>
  <tr>
    <td><img src="python/pics/41x5_eta_comparison.png" alt="Eta comparison"/></td>
    <td><img src="python/pics/100x10_eta_comparison.png" alt="Eta comparison"/></td>
    <td><img src='python/pics/275x18_eta_comparison.png' alt="Eta comparison"/></td>
  </tr>
  <tr>
    <td><img src="python/pics/41x5_phi_comparison.png" alt="Phi comparison"/></td>
    <td><img src="python/pics/100x10_phi_comparison.png" alt="Phi comparison"/></td>
    <td><img src='python/pics/275x18_phi_comparison.png' alt="Phi comparison"/></td>
  </tr>
  <tr>
    <td><img src="python/pics/41x5_atan2_pxpz_hadron.png" alt="atan2_pxpz hadron comparison"/></td>
    <td><img src="python/pics/100x10_atan2_pxpz_hadron.png" alt="atan2_pxpz hadron comparison"/></td>
    <td><img src='python/pics/275x18_atan2_pxpz_hadron.png' alt="atan2_pxpz hadron comparison"/></td>
  </tr>
  <tr>
    <td><img src="python/pics/41x5_atan2_pypz_hadron.png" alt="atan2_pypz hadron comparison"/></td>
    <td><img src="python/pics/100x10_atan2_pypz_hadron.png" alt="atan2_pypz hadron comparison"/></td>
    <td><img src='python/pics/275x18_atan2_pypz_hadron.png' alt="atan2_pypz hadron comparison"/></td>
  </tr>
  <tr>
    <td><img src="python/pics/41x5_atan2_pxpz_lepton.png" alt="atan2_pxpz lepton comparison"/></td>
    <td><img src="python/pics/100x10_atan2_pxpz_lepton.png" alt="atan2_pxpz lepton comparison"/></td>
    <td><img src='python/pics/275x18_atan2_pxpz_lepton.png' alt="atan2_pxpz lepton comparison"/></td>
  </tr>
  <tr>
    <td><img src="python/pics/41x5_atan2_pypz_lepton.png" alt="atan2_pypz lepton comparison"/></td>
    <td><img src="python/pics/100x10_atan2_pypz_lepton.png" alt="atan2_pypz lepton comparison"/></td>
    <td><img src='python/pics/275x18_atan2_pypz_lepton.png' alt="atan2_pypz lepton comparison"/></td>
  </tr>
  <tr>
    <td><img src="python/pics/41x5_vtx_x_comparison.png"   alt="Vertex X comparison"/></td>
    <td><img src="python/pics/100x10_vtx_x_comparison.png" alt="Vertex X comparison"/></td>
    <td><img src='python/pics/275x18_vtx_x_comparison.png' alt="Vertex X comparison"/></td>
  </tr>
  <tr>
    <td><img src="python/pics/41x5_vtx_z_comparison.png" alt="Vertex Z comparison"/></td>
    <td><img src="python/pics/100x10_vtx_z_comparison.png" alt="Vertex Z comparison"/></td>
    <td><img src='python/pics/275x18_vtx_z_comparison.png' alt="Vertex Z comparison"/></td>
  </tr>
<tr>
    <td><img src="python/pics/41x5_vtx_t_comparison.png"   alt="Vertex T comparison"/></td>
    <td><img src="python/pics/100x10_vtx_t_comparison.png" alt="Vertex T comparison"/></td>
    <td><img src='python/pics/275x18_vtx_t_comparison.png' alt="Vertex T comparison"/></td>
  </tr>
</table>

## References

- [Accelerator and beam conditions critical for physics and detector simulations for the Electron-Ion Collider](https://github.com/eic/documents/blob/master/reports/general/Note-Simulations-BeamEffects.pdf)
- [Pythia8 beam effects](https://github.com/bspage912/eicSimuBeamEffects/blob/headonTestJin/Pythia8/PythiaBeamShape.cxx)
- [Fun4All code](https://github.com/sPHENIX-Collaboration/coresoftware/pull/1251)
