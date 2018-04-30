cmake_minimum_required(VERSION 3.5)
project(Info601_Project C)

set(CMAKE_C_STANDARD 11)

include_directories(src)
include_directories(src/client)
include_directories(src/viewer)

add_executable(Info601_Project
		src/include.h
		src/main.c
		src/ncurses.c
		src/ncurses.h
		src/scene.c
		src/scene.h
		src/tools_error.c
		src/tools_error.h)

add_executable(Client src/client/connection.h src/client/main.c src/tools_error.h src/tools_error.c)
