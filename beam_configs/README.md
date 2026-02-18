# Beam Configuration Files

This directory contains YAML configuration files for EIC beam parameters.

## Format

Each YAML file defines beam parameters for a specific configuration. The format is:

```yaml
---
# Configuration name/description
crossing_angle:
  horizontal: <value>    # rad
  vertical: <value>      # rad

ion_beam:
  beta_crab_horizontal: <value>
  divergence_horizontal: <value>
  divergence_vertical: <value>
  beta_star_horizontal: <value>      # mm
  beta_star_vertical: <value>        # mm
  rms_emittance_horizontal: <value>  # m
  rms_emittance_vertical: <value>    # m
  rms_bunch_length: <value>          # m

electron_beam:
  beta_crab_horizontal: <value>
  divergence_horizontal: <value>
  divergence_vertical: <value>
  beta_star_horizontal: <value>      # mm
  beta_star_vertical: <value>        # mm
  rms_emittance_horizontal: <value>  # m
  rms_emittance_vertical: <value>    # m
  rms_bunch_length: <value>          # m
```

## Usage

The afterburner automatically loads configurations by name. For example, to use the `ip6_hidiv_275x18` configuration:

```bash
abconv my.hepmc --preset ip6_hidiv_275x18
```

## Custom Configuration Directory

You can specify a custom directory for beam configurations using the `AFTERBURNER_BEAM_CONFIGS_DIR` environment variable:

```bash
export AFTERBURNER_BEAM_CONFIGS_DIR=/path/to/my/configs
abconv my.hepmc --preset my_custom_config
```

## Notes

- All values are in SI units unless otherwise specified
- Emittances are in meters (not nanometers as in the C++ code)
- Bunch lengths are in meters (not centimeters as in the C++ code)
- Scientific notation is supported (e.g., `25e-3` for 0.025)

## Configuration Naming Convention

Configurations follow the pattern: `{ip}{profile}_{energy_ion}x{energy_electron}`

Where:
- `ip`: Interaction point (ip6 or ip8)
- `profile`: Beam profile (hidiv, hiacc, eau, ep, etc.)
- `energy_ion`: Ion beam energy in GeV
- `energy_electron`: Electron beam energy in GeV

Examples:
- `ip6_hidiv_275x18`: IP6, High Divergence, 275 GeV ion, 18 GeV electron
- `ip8_hiacc_100x10`: IP8, High Acceptance, 100 GeV ion, 10 GeV electron
