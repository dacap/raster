// Raster Library
// Copyright (C) 2015-2022 David Capello

#include "raster/raster.h"
#include "test.h"

#include <vector>

using namespace raster;

template<typename Pixel>
void expect_array(image_view& img, const std::vector<typename Pixel::value_type>& values)
{
  auto it = values.begin(), end = values.end();
  auto specific_img = img.view_as<Pixel>();
  int x = 0;
  for (auto p : specific_img) {
    printf("x=%d\n", x++);
    EXPECT_EQ(true, it != end);
    EXPECT_EQ((int)*it, (int)p);
    ++it;
  }
  EXPECT_EQ(true, it == end);
}

int main() {
  image_spec spec(2, 1, 32);
  std::vector<uint8_t> data(spec.required_size());
  buffer_view buf(data);
  image_view img32(spec, buf);

  // 00FF001E 80010032
  put_pixel(img32, 0, 0, 0x00FF001E);
  put_pixel(img32, 1, 0, 0x80010032);
  EXPECT_EQ(0x00FF001E, get_pixel(img32, 0, 0));
  EXPECT_EQ(0x80010032, get_pixel(img32, 1, 0));
  expect_array<Pixel32bpp>(img32, { 0x00FF001E, 0x80010032 });

  // 001E 00FF 0032 8001
  image_view img16(image_spec(4, 1, 16), buf);
  EXPECT_EQ(0x001E, get_pixel(img16, 0, 0));
  EXPECT_EQ(0x00FF, get_pixel(img16, 1, 0));
  EXPECT_EQ(0x0032, get_pixel(img16, 2, 0));
  EXPECT_EQ(0x8001, get_pixel(img16, 3, 0));
  expect_array<Pixel16bpp>(img16, { 0x001E, 0x00FF, 0x0032, 0x8001 });

  // 1E 00 FF 00 32 00 01 80
  image_view img8(image_spec(8, 1, 8), buf);
  EXPECT_EQ(0x1E, get_pixel(img8, 0, 0));
  EXPECT_EQ(0x00, get_pixel(img8, 1, 0));
  EXPECT_EQ(0xFF, get_pixel(img8, 2, 0));
  EXPECT_EQ(0x00, get_pixel(img8, 3, 0));
  EXPECT_EQ(0x32, get_pixel(img8, 4, 0));
  EXPECT_EQ(0x00, get_pixel(img8, 5, 0));
  EXPECT_EQ(0x01, get_pixel(img8, 6, 0));
  EXPECT_EQ(0x80, get_pixel(img8, 7, 0));
  expect_array<Pixel8bpp>(img8, { 0x1E, 0x00, 0xFF, 0x00, 0x32, 0x00, 0x01, 0x80 });

  // E 1 0 0 F F 0 0 2 3 0 0 1 0 0 8
  image_view img4(image_spec(16, 1, 4), buf);
  EXPECT_EQ(0xE, get_pixel(img4, 0, 0));
  EXPECT_EQ(0x1, get_pixel(img4, 1, 0));
  EXPECT_EQ(0x0, get_pixel(img4, 2, 0));
  EXPECT_EQ(0x0, get_pixel(img4, 3, 0));
  EXPECT_EQ(0xF, get_pixel(img4, 4, 0));
  EXPECT_EQ(0xF, get_pixel(img4, 5, 0));
  EXPECT_EQ(0x0, get_pixel(img4, 6, 0));
  EXPECT_EQ(0x0, get_pixel(img4, 7, 0));
  EXPECT_EQ(0x2, get_pixel(img4, 8, 0));
  EXPECT_EQ(0x3, get_pixel(img4, 9, 0));
  EXPECT_EQ(0x0, get_pixel(img4, 10, 0));
  EXPECT_EQ(0x0, get_pixel(img4, 11, 0));
  EXPECT_EQ(0x1, get_pixel(img4, 12, 0));
  EXPECT_EQ(0x0, get_pixel(img4, 13, 0));
  EXPECT_EQ(0x0, get_pixel(img4, 14, 0));
  EXPECT_EQ(0x8, get_pixel(img4, 15, 0));

  image_view img2(image_spec(32, 1, 2), buf);
  EXPECT_EQ(((1<<1) | (0)), get_pixel(img2, 0, 0)); // E
  EXPECT_EQ(((1<<1) | (1)), get_pixel(img2, 1, 0));
  EXPECT_EQ(((0<<1) | (1)), get_pixel(img2, 2, 0)); // 1
  EXPECT_EQ(((0<<1) | (0)), get_pixel(img2, 3, 0));
  EXPECT_EQ(((0<<1) | (0)), get_pixel(img2, 4, 0)); // 0
  EXPECT_EQ(((0<<1) | (0)), get_pixel(img2, 5, 0));
  EXPECT_EQ(((0<<1) | (0)), get_pixel(img2, 6, 0)); // 0
  EXPECT_EQ(((0<<1) | (0)), get_pixel(img2, 7, 0));
  EXPECT_EQ(((1<<1) | (1)), get_pixel(img2, 8, 0)); // F
  EXPECT_EQ(((1<<1) | (1)), get_pixel(img2, 9, 0));
  EXPECT_EQ(((1<<1) | (1)), get_pixel(img2, 10, 0)); // F
  EXPECT_EQ(((1<<1) | (1)), get_pixel(img2, 11, 0));
  EXPECT_EQ(((0<<1) | (0)), get_pixel(img2, 12, 0)); // 0
  EXPECT_EQ(((0<<1) | (0)), get_pixel(img2, 13, 0));
  EXPECT_EQ(((0<<1) | (0)), get_pixel(img2, 14, 0)); // 0
  EXPECT_EQ(((0<<1) | (0)), get_pixel(img2, 15, 0));
  EXPECT_EQ(((1<<1) | (0)), get_pixel(img2, 16, 0)); // 2
  EXPECT_EQ(((0<<1) | (0)), get_pixel(img2, 17, 0));
  EXPECT_EQ(((1<<1) | (1)), get_pixel(img2, 18, 0)); // 3
  EXPECT_EQ(((0<<1) | (0)), get_pixel(img2, 19, 0));
  EXPECT_EQ(((0<<1) | (0)), get_pixel(img2, 20, 0)); // 0
  EXPECT_EQ(((0<<1) | (0)), get_pixel(img2, 21, 0));
  EXPECT_EQ(((0<<1) | (0)), get_pixel(img2, 22, 0)); // 0
  EXPECT_EQ(((0<<1) | (0)), get_pixel(img2, 23, 0));
  EXPECT_EQ(((0<<1) | (1)), get_pixel(img2, 24, 0)); // 1
  EXPECT_EQ(((0<<1) | (0)), get_pixel(img2, 25, 0));
  EXPECT_EQ(((0<<1) | (0)), get_pixel(img2, 26, 0)); // 0
  EXPECT_EQ(((0<<1) | (0)), get_pixel(img2, 27, 0));
  EXPECT_EQ(((0<<1) | (0)), get_pixel(img2, 28, 0)); // 0
  EXPECT_EQ(((0<<1) | (0)), get_pixel(img2, 29, 0));
  EXPECT_EQ(((0<<1) | (0)), get_pixel(img2, 30, 0)); // 8
  EXPECT_EQ(((1<<1) | (0)), get_pixel(img2, 31, 0));

  image_view img1(image_spec(64, 1, 1), buf);
  EXPECT_EQ(0, get_pixel(img1, 0, 0)); // E
  EXPECT_EQ(1, get_pixel(img1, 1, 0));
  EXPECT_EQ(1, get_pixel(img1, 2, 0));
  EXPECT_EQ(1, get_pixel(img1, 3, 0));
  EXPECT_EQ(1, get_pixel(img1, 4, 0)); // 1
  EXPECT_EQ(0, get_pixel(img1, 5, 0));
  EXPECT_EQ(0, get_pixel(img1, 6, 0));
  EXPECT_EQ(0, get_pixel(img1, 7, 0));
  EXPECT_EQ(0, get_pixel(img1, 8, 0)); // 0
  EXPECT_EQ(0, get_pixel(img1, 9, 0));
  EXPECT_EQ(0, get_pixel(img1, 10, 0));
  EXPECT_EQ(0, get_pixel(img1, 11, 0));
  EXPECT_EQ(0, get_pixel(img1, 12, 0)); // 0
  EXPECT_EQ(0, get_pixel(img1, 13, 0));
  EXPECT_EQ(0, get_pixel(img1, 14, 0));
  EXPECT_EQ(0, get_pixel(img1, 15, 0));
  EXPECT_EQ(1, get_pixel(img1, 16, 0)); // F
  EXPECT_EQ(1, get_pixel(img1, 17, 0));
  EXPECT_EQ(1, get_pixel(img1, 18, 0));
  EXPECT_EQ(1, get_pixel(img1, 19, 0));
  EXPECT_EQ(1, get_pixel(img1, 20, 0)); // F
  EXPECT_EQ(1, get_pixel(img1, 21, 0));
  EXPECT_EQ(1, get_pixel(img1, 22, 0));
  EXPECT_EQ(1, get_pixel(img1, 23, 0));
  EXPECT_EQ(0, get_pixel(img1, 24, 0)); // 0
  EXPECT_EQ(0, get_pixel(img1, 25, 0));
  EXPECT_EQ(0, get_pixel(img1, 26, 0));
  EXPECT_EQ(0, get_pixel(img1, 27, 0));
  EXPECT_EQ(0, get_pixel(img1, 28, 0)); // 0
  EXPECT_EQ(0, get_pixel(img1, 29, 0));
  EXPECT_EQ(0, get_pixel(img1, 30, 0));
  EXPECT_EQ(0, get_pixel(img1, 31, 0));
  EXPECT_EQ(0, get_pixel(img1, 32, 0)); // 2
  EXPECT_EQ(1, get_pixel(img1, 33, 0));
  EXPECT_EQ(0, get_pixel(img1, 34, 0));
  EXPECT_EQ(0, get_pixel(img1, 35, 0));
  EXPECT_EQ(1, get_pixel(img1, 36, 0)); // 3
  EXPECT_EQ(1, get_pixel(img1, 37, 0));
  EXPECT_EQ(0, get_pixel(img1, 38, 0));
  EXPECT_EQ(0, get_pixel(img1, 39, 0));
  EXPECT_EQ(0, get_pixel(img1, 40, 0)); // 0
  EXPECT_EQ(0, get_pixel(img1, 41, 0));
  EXPECT_EQ(0, get_pixel(img1, 42, 0));
  EXPECT_EQ(0, get_pixel(img1, 43, 0));
  EXPECT_EQ(0, get_pixel(img1, 44, 0)); // 0
  EXPECT_EQ(0, get_pixel(img1, 45, 0));
  EXPECT_EQ(0, get_pixel(img1, 46, 0));
  EXPECT_EQ(0, get_pixel(img1, 47, 0));
  EXPECT_EQ(1, get_pixel(img1, 48, 0)); // 1
  EXPECT_EQ(0, get_pixel(img1, 49, 0));
  EXPECT_EQ(0, get_pixel(img1, 50, 0));
  EXPECT_EQ(0, get_pixel(img1, 51, 0));
  EXPECT_EQ(0, get_pixel(img1, 52, 0)); // 0
  EXPECT_EQ(0, get_pixel(img1, 53, 0));
  EXPECT_EQ(0, get_pixel(img1, 54, 0));
  EXPECT_EQ(0, get_pixel(img1, 55, 0));
  EXPECT_EQ(0, get_pixel(img1, 56, 0)); // 0
  EXPECT_EQ(0, get_pixel(img1, 57, 0));
  EXPECT_EQ(0, get_pixel(img1, 58, 0));
  EXPECT_EQ(0, get_pixel(img1, 59, 0));
  EXPECT_EQ(0, get_pixel(img1, 60, 0)); // 8
  EXPECT_EQ(0, get_pixel(img1, 61, 0));
  EXPECT_EQ(0, get_pixel(img1, 62, 0));
  EXPECT_EQ(1, get_pixel(img1, 63, 0));
}
