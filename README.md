# afterburner

EIC MC afterburner

The converter and benchmark require libyaml-cpp. Those are available in package managers for the most of systems:

```bash 
apt install libyaml-cpp-dev     # Debian/Ubuntu/Mint
yum install yaml-cpp-devel      # RHEL/CentOS/Fedora
```

To apply benchmarks one could go 

https://dtn01.sdcc.bnl.gov:9000/minio/eictest/ATHENA/WG/BeamEffects/

## Building

```bash
git clone https://eicweb.phy.anl.gov/monte_carlo/afterburner.git
mkdir -p afterburner/build
cd afterburner/build

# setup cmake (c++ code lives in cpp directory) 
cmake ../cpp

# to build all
cmake --build ../cpp --target all

# to install
cmake --build ../cpp --target install -- -j 8
```

## CLI command

### Examples:

```bash
# Process my whole file, add crossing angle, beam effects, do validation plots
abconv my.hepmc

# Same, but limit the number of events to 1000 and set the output name as 'test'
abconv my.hepmc -o test -l 1000

# Just convert hepmc3 to hepmc2 don't use afterburner, don't create plots
abconv my.hepmc -f hepmc2 --ab-off --plot-off 
```

### Options:

| Flag                 | Description                               |
|----------------------|-------------------------------------------|
| -h,--help            | Print this help message and exit|
| -o,--output TEXT     | Base name for Output files ((!) no extension)|
| -c,--config TEXT     | Beams configuration file|
| -i,--in-format TEXT  | Input format: auto [default], hepmc2, hepmc3, hpe, lhef, gz, treeroot, root|
| -f,--out-format TEXT | Output format: hepmc3 [default], hepmc2, dot, none (no events file is saved)|
| -s,--ev-start INT    | Start event index (all previous are skipped)|
| -e,--ev-end INT      | End event index (end processing after this event)|
| -l,--limit UINT      | Limit number of events to process. (Shutdown after this number of parsed events)|
| --ab-off             | No afterburner is applied|
| --plot-off           | Don't produce validation plots|
|--exit-ca             | Check existing crossing angle and exit if CA>1mrad (1) |

> (1) How `--exit-ca` works exactly: when afterburner processes the first event it checks if 
> it has 2 beam particles (fails with non zero code if not) and then calculates their crossing angle
> with the `--exit-ca` is set and crossing angle absolute value is > 1mrad program ends with 0 code.
> This method is very coarse as if in a source file the crossing angle is 0 but all beam effects do exist,
> beam effects will be applied twice

## Validation

The validation plots are generated and can be viewed in [python/comparison.ipynb](python/comparison.ipynb)

Essential plots from the latest validation run: 

<table>
  <tr>
    <td><img src="python/pics/eta_comparison.png" alt="Eta comparison"/></td>
    <td><img src='python/pics/phi_comparison.png' alt="Phi comparison"/></td>
  </tr>
  <tr>
    <td colspan="2"><img src='python/pics/phi_vs_eta_comparison.png' alt="Phi vs Eta comparison"/></td>
  </tr>
  <tr>
    <td colspan="2"><img src='python/pics/pt_vs_eta_comparison.png' alt="Pt vs Eta comparison"/></td>
  </tr>
</table>

## References

- [Accelerator and beam conditions critical for physics and detector simulations for the Electron-Ion Collider](https://github.com/eic/documents/blob/master/reports/general/Note-Simulations-BeamEffects.pdf)
- [Pythia8 beam effects](https://github.com/bspage912/eicSimuBeamEffects/blob/headonTestJin/Pythia8/PythiaBeamShape.cxx)
- [Fun4All code](https://github.com/sPHENIX-Collaboration/coresoftware/pull/1251)
