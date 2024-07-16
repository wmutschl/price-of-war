[![Build LaTeX](../../actions/workflows/latex.yml/badge.svg)](../../actions/workflows/latex.yml)

# The Price of War
Replication package for the paper "The Price of War".

🚧 UNDER CONSTRUCTION 🚧

## DSGE model
You can find all replication files under [Releases](https://github.com/wmutschl/price-of-war/releases) or use these quick links:
- [PDF documentation of the DSGE model](https://github.com/wmutschl/price-of-war/releases/latest/download/dsge-model-appendix.pdf)

The mod file and latex appendix are created dynamically using [Dynare Mod Wizard](https://github.com/wmutschl/Dynare-Mod-Wizard), which is loaded as a submodule.
If you are not familiar with Dynare's [macro preprocessing language](https://www.dynare.org/manual/the-model-file.html#macro-processing-language), then you can also access the output of the macro processor by using the savemacro option of the dynare command:
- [PDF documentation of the DSGE model](https://github.com/wmutschl/price-of-war/releases/latest/download/dsge-model-appendix.pdf)

```matlab
dynare war_nk4 -DMATCHING -DSLICE -DSLICE_ROTATED -DMH_NBLOCKS=24 conffile=__parallelconf_mac_R2024a_arm64 parallel
```