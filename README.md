# cli-pong

[![License](https://img.shields.io/badge/License-MIT-green)](https://github.com/Oakamoore/cli-pong/blob/main/LICENSE) ![Platform](https://img.shields.io/badge/Platform-Windows-blue) 

## Overview

A command line implementation of **two player** pong, built using [WinAPI](https://learn.microsoft.com/en-us/previous-versions/aa383723(v=vs.85)). 

<p align="center">
	<img src="demo/demo.gif">
</p>

### Controls 

Player controls are `W, S`, and `I, K` - this can be changed from within in [`config.h`](https://github.com/Oakamoore/cli-pong/blob/main/include/config.h) (must be an **uppercase alphabetic** character, or a valid [virtual key code](https://learn.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes))

## Installation

1. Clone this project

```shell
git clone https://github.com/Oakamoore/cli-pong.git
```

2. Step into the repository

```shell
cd cli-pong
```

3. Build the project using [CMake](https://cmake.org/)

```shell
# Configure the build
cmake -S . -B build

# Build project binaries 
cmake --build build
```

### Specifying a Build Configuration

Depending on the [configuration generator](https://cmake.org/cmake/help/latest/manual/cmake-generators.7.html) being used, a configuration type (`Debug`, `Release` etc.) can be specified as follows:

> In the snippets below, all instances of `value` should be replaced by the desired configuration type

#### Single Configuration Generator 

- During the build configuration step above, append `-D CMAKE_BUILD_TYPE=value` to the existing command, then build the project's binaries as normal. 

#### Multi-Configuration Generator

- Configure the build, as seen above, then during the building of the project's binaries append `--config value` to the existing command.

## Usage 

Once the project is built, navigate to the newly created build directory `cli-pong/build/`, locate the executable and run the program using:

```shell
./cli-pong
```