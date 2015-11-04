# Raster Library
# Copyright (C) 2015 David Capello

cmake_minimum_required(VERSION 2.6)

project(raster CXX)
option(RASTER_TESTS "Compile raster tests" on)

include_directories(.)

if(WIN32)
  add_definitions(-D_SCL_SECURE_NO_WARNINGS)
endif()

if(UNIX)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")
endif()

if(RASTER_TESTS)
  enable_testing()
  add_subdirectory(tests)
endif()
