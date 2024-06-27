# cli-pong

[![License](https://img.shields.io/badge/License-MIT-green)](https://github.com/Oakamoore/cli-pong/blob/main/LICENSE) ![Platform](https://img.shields.io/badge/Platform-Windows-blue) 

## Overview

A command line implementation of **two player** pong, built using [WinAPI](https://learn.microsoft.com/en-us/previous-versions/aa383723(v=vs.85)). 

![demo](demo/demo.gif)

### Controls 

Player controls are `W, S`, and `I, K` 

This can be changed from within in [`config.h`](https://github.com/Oakamoore/cli-pong/blob/main/include/config.h) - must be an **uppercase alphabetic** character, or a valid [virtual key code](https://learn.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes)

## Installation

1. Clone this project

```shell
git clone https://github.com/Oakamoore/cli-pong.git
```

2. Step into the repository

```shell
cd cli-pong
```

3. Build the project using CMake

```shell
cmake -S . -B build
cmake --build build
```

## Usage 

Once the project is built, navigate to the newly created build directory `cli-pong/build/`, locate the executable and run the program using:

```shell
./cli-pong
```