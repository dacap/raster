# Raster Library
# Copyright (C) 2019 David Capello

find_package(PNG)
if(PNG_FOUND)
  add_executable(raster raster.cpp)
  target_link_libraries(raster ${PNG_LIBRARIES})
  target_include_directories(raster PRIVATE ${PNG_INCLUDE_DIRS})
  target_compile_definitions(raster PRIVATE ${PNG_DEFINITIONS})
endif()
