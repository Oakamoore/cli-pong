cmake_minimum_required(VERSION 3.29)

project(cli-pong 
	VERSION 1.0
	DESCRIPTION "A command line implementation of two player pong"
	HOMEPAGE_URL "https://github.com/Oakamoore/cli-pong"
	LANGUAGES CXX 
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(cli-pong
	src/main.cpp
	src/game.cpp
	src/ball.cpp
	src/paddle.cpp
	src/level.cpp
	src/console.cpp
	src/menu.cpp
)

target_include_directories(cli-pong 
	PRIVATE include
)