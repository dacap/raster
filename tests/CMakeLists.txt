# Raster Library
# Copyright (C) 2015 David Capello

function(add_raster_test name)
  add_executable(${name} ${name}.cpp)
  add_test(NAME ${name} COMMAND ${name})
endfunction()

add_raster_test(bitsperpixel)
add_raster_test(colorconversion)
add_raster_test(rowstride)
