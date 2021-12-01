cmake_minimum_required(VERSION 3.18)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project(Hangman VERSION 1.0
	DESCRIPTION "An electronic version of the popular game hangman"
	LANGUAGES CXX)

add_executable(Hangman
	src/main.cpp
	src/game.cpp
	src/game.hpp)

target_include_directories(Hangman PUBLIC assets/ src/)

set_target_properties(Hangman PROPERTIES CXX_STANDARD 17)
