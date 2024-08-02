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

Depending on the type of [CMake generator](https://cmake.org/cmake/help/latest/manual/cmake-generators.7.html) being used, a build configuration (`Debug`, `Release` etc.) can be specified as follows:

#### Single Configuration Generator 

```shell
# Configure a release build
cmake -S . -B build -D CMAKE_BUILD_TYPE=Release

# Build release binaries
cmake --build build
```

#### Multi-Configuration Generator

```shell
# Configure the build
cmake -S . -B build 

# Build release binaries
cmake --build build --config Release
```

## Usage 

Once the project is built, navigate to the newly created build directory `cli-pong/build/`, locate the executable and run the program using:

```shell
./cli-pong
```