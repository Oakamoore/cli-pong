cmake_minimum_required(VERSION 3.29)

project(cli-pong LANGUAGES CXX VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)

add_executable(
	cli-pong
	src/main.cpp
	src/game.cpp
	src/ball.cpp
	src/paddle.cpp
	src/console.cpp
	src/menu.cpp
)

target_include_directories(cli-pong PRIVATE include)