# cli-pong

[![License](https://img.shields.io/badge/License-MIT-green)](https://github.com/Oakamoore/cli-pong/blob/main/LICENSE) ![Platform](https://img.shields.io/badge/Platform-Windows-blue) 

## Overview

A command line implementation of **two player** pong, built using [WinAPI](https://learn.microsoft.com/en-us/previous-versions/aa383723(v=vs.85)). 

<p align="center">
	<video src="https://github.com/user-attachments/assets/e2144c96-abec-4349-879f-0844c1d55ef8" width=1100>
</p>

### Controls 

Player controls are `W, S`, and `I, K` - this can be changed from within in [`config.h`](https://github.com/Oakamoore/cli-pong/blob/main/include/config.h) (must be an **uppercase alphabetic** character, or a valid [virtual key code](https://learn.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes))

## Installation

> A C++20 compatible compiler is required for this program to function as expected

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

A build configuration (`Debug`, `Release` etc.) can also be [specified](https://gist.github.com/Oakamoore/685838c1b4a4c64a008f5461ac9323b5).

## Usage 

Once the project is built, navigate to the newly created build directory `cli-pong/build/`, locate the executable and run the program using:

```shell
./cli-pong
```