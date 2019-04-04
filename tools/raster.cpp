// Raster Library
// Copyright (C) 2019 David Capello

#include "raster/algorithm.h"
#include "raster/png.h"

#include <array>
#include <cstdio>

using namespace raster;

int main(int argc, char* argv[]) {
  if (argc < 2) {
    printf("Usage: raster image.png");
    return 1;
  }

  image img = raster::png::load_from_file(argv[1]);
  if (!img) {
    printf("Error loading image");
    return 2;
  }

  printf("Image %dx%d %dbpp\n", img.width(), img.height(), img.bits_per_pixel());
  std::array<unsigned int, 256> r, g, b;
  r.fill(0);
  g.fill(0);
  b.fill(0);
  unsigned int n = 0;

  for_each_pixel<Pixel24bpp>(
    img, [&](uint32_t value) {
           ++r[getr<ColorB8G8R8>(value)];
           ++g[getg<ColorB8G8R8>(value)];
           ++b[getb<ColorB8G8R8>(value)];
           ++n;
         });

  printf("Value\tR\tG\tB\n");
  for (int i=0; i<256; ++i) {
    printf("%u\t%.05f\t%.05f\t%.05f\n",
           i,
           double(r[i]) / n,
           double(g[i]) / n,
           double(b[i]) / n);
  }
}
