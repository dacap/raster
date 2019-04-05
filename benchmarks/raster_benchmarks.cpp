// Raster Library
// Copyright (c) 2019 David Capello
//
// This file is released under the terms of the MIT license.
// Read LICENSE.txt for more information.

#include "raster/raster.h"
#include <benchmark/benchmark.h>

using namespace raster;

template<typename Color>
static void BM_RasterForEach(benchmark::State& state) {
  image img(image_spec(state.range(0),
                       state.range(0), Color::bits_per_pixel));
  for (auto _ : state) {
    state.ResumeTiming();
    {
      int n = 0;
      for_each_pixel<Color>(
        img, [&n](int value) { n += value; });
    }
    state.PauseTiming();
  }
}
BENCHMARK_TEMPLATE(BM_RasterForEach, Pixel32bpp)->Range(256, 512);
BENCHMARK_TEMPLATE(BM_RasterForEach, Pixel24bpp)->Range(256, 512);
BENCHMARK_TEMPLATE(BM_RasterForEach, Pixel16bpp)->Range(256, 512);
BENCHMARK_TEMPLATE(BM_RasterForEach, Pixel8bpp)->Range(256, 512);

template<typename Color>
static void BM_RasterForEach2(benchmark::State& state) {
  image img(image_spec(state.range(0),
                       state.range(0), Color::bits_per_pixel));
  for (auto _ : state) {
    state.ResumeTiming();
    {
      int n = 0;
      for_each_pixel2<Color>(
        img, [&n](int value) { n += value; });
    }
    state.PauseTiming();
  }
}
BENCHMARK_TEMPLATE(BM_RasterForEach2, Pixel32bpp)->Range(256, 512);
BENCHMARK_TEMPLATE(BM_RasterForEach2, Pixel24bpp)->Range(256, 512);
BENCHMARK_TEMPLATE(BM_RasterForEach2, Pixel16bpp)->Range(256, 512);
BENCHMARK_TEMPLATE(BM_RasterForEach2, Pixel8bpp)->Range(256, 512);

BENCHMARK_MAIN();
