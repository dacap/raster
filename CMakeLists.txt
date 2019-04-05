# Raster Library
# Copyright (C) 2015-2019 David Capello

cmake_minimum_required(VERSION 3.4)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(raster CXX)
option(RASTER_TESTS "Compile raster tests" on)
option(RASTER_TOOLS "Compile raster tools" on)
option(RASTER_BENCHMARKS "Compile raster benchmarks" on)

if(UNIX AND NOT APPLE)
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -pthread")
endif()

include_directories(.)

if(WIN32)
  add_definitions(-D_SCL_SECURE_NO_WARNINGS)
endif()

if(RASTER_TESTS)
  enable_testing()
  add_subdirectory(tests)
endif()

if(RASTER_TOOLS)
  add_subdirectory(tools)
endif()

if(RASTER_BENCHMARKS)
  add_subdirectory(benchmarks)
endif()
