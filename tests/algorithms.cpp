// Raster Library
// Copyright (C) 2019 David Capello

#include "raster/algorithm.h"
#include "raster/image.h"
#include "raster/primitives.h"
#include "test.h"

#include <vector>

using namespace raster;

template<typename Pixel>
void test(const std::vector<typename Pixel::value_type>& values) {
  assert(values.size() == 4);

  image img(image_spec(2, 2, Pixel::bits_per_pixel));
  put_pixel(img, 0, 0, values[0]);
  put_pixel(img, 1, 0, values[1]);
  put_pixel(img, 0, 1, values[2]);
  put_pixel(img, 1, 1, values[3]);
  assert(get_pixel(img, 0, 0) == values[0]);
  assert(get_pixel(img, 1, 0) == values[1]);
  assert(get_pixel(img, 0, 1) == values[2]);
  assert(get_pixel(img, 1, 1) == values[3]);

  int i = 0;
  for_each_pixel<Pixel>(
    img,
    [&](typename Pixel::value_type value) {
      assert(value == values[i++]);
    });
  assert(i == 4);

  i = 0;
  for_each_pixel2<Pixel>(
    img,
    [&](typename Pixel::value_type value) {
      printf("value = %d\n", value);
      assert(value == values[i++]);
    });
  assert(i == 4);
}

int main() {
  test<Pixel32bpp>({ rgba<ColorR8G8B8A8>(255, 0, 0, 255),
                     rgba<ColorR8G8B8A8>(0, 255, 0, 255),
                     rgba<ColorR8G8B8A8>(0, 0, 255, 255),
                     rgba<ColorR8G8B8A8>(128, 128, 128, 255) });
  test<Pixel24bpp>({ rgb<ColorR8G8B8>(255, 0, 0),
                     rgb<ColorR8G8B8>(0, 255, 0),
                     rgb<ColorR8G8B8>(0, 0, 255),
                     rgb<ColorR8G8B8>(128, 128, 128) });
  test<Pixel16bpp>({ rgb<ColorR5G6B5>(255, 0, 0),
                     rgb<ColorR5G6B5>(0, 255, 0),
                     rgb<ColorR5G6B5>(0, 0, 255),
                     rgb<ColorR5G6B5>(128, 128, 128) });
  test<Pixel8bpp>({ 1, 2, 3, 4 });
}
