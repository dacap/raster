# Raster Library

[![build](https://github.com/dacap/raster/workflows/build/badge.svg)](https://github.com/dacap/raster/actions?query=workflow%3Abuild)
[![MIT Licensed](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE.txt)

A generic C++17 library to use raw buffers as images.

This is an experimental/work-in-progress library released under the
terms of the MIT license. There is no roadmap or specific goals, just
for experimental purposes and testing.

## Examples

```c++
#include "raster/png.h"

#include <cstdio>

int main() {
  raster::image img = raster::png::load_from_file("testing.png");
  if (img) {
    std::printf("Width %d Height %d\n",
                img.width(), img.height());
  }
}
```
