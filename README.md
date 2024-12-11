# Calculator
Calculator I created as part of Software Engineering at Full Sail University. Uses WxWidgets GUI library

![Demonstration of the Calculator evaluating 2 times 2](.github/readme-assets/Demo.gif)

## Build & run

### Pre-requisites

- [cmake](https://cmake.org/download/) (Version 3.31 or later)
- [vcpkg Package Manager](https://github.com/microsoft/vcpkg)
- After these are installed, follow the instructions in [CMakeUserPresets.template.json](/Calculator/CMakeUserPresets.template.json)

### Build

From the terminal of your choice, run:

```zsh
# This example uses Unix Makefiles as the generator. Use the build command for the generator you specified in CMakeUserPresets.json

cd ./Calculator
cmake --preset=default -S . -B ./build/
cd ./build
make 
``` 