// Raster Library
// Copyright (C) 2015 David Capello

#include "raster/image_spec.h"
#include "test.h"

using namespace raster;

int main() {
  // 1bpp

  image_spec   img1x1x1bpp(1, 1, 1);
  EXPECT_EQ(1, img1x1x1bpp.width());
  EXPECT_EQ(1, img1x1x1bpp.height());
  EXPECT_EQ(1, img1x1x1bpp.rowstride());
  EXPECT_EQ(1, img1x1x1bpp.required_size());

  image_spec   img7x2x1bpp(7, 2, 1);
  EXPECT_EQ(7, img7x2x1bpp.width());
  EXPECT_EQ(2, img7x2x1bpp.height());
  EXPECT_EQ(1, img7x2x1bpp.rowstride());
  EXPECT_EQ(2, img7x2x1bpp.required_size());

  image_spec   img9x2x1bpp(9, 2, 1);
  EXPECT_EQ(9, img9x2x1bpp.width());
  EXPECT_EQ(2, img9x2x1bpp.height());
  EXPECT_EQ(2, img9x2x1bpp.rowstride());
  EXPECT_EQ(4, img9x2x1bpp.required_size());

  image_spec    img32x2x1bpp(32, 2, 1);
  EXPECT_EQ(32, img32x2x1bpp.width());
  EXPECT_EQ( 2, img32x2x1bpp.height());
  EXPECT_EQ( 4, img32x2x1bpp.rowstride());
  EXPECT_EQ( 8, img32x2x1bpp.required_size());

  // 2bpp

  image_spec   img1x1x2bpp(1, 1, 2);
  EXPECT_EQ(1, img1x1x2bpp.width());
  EXPECT_EQ(1, img1x1x2bpp.height());
  EXPECT_EQ(1, img1x1x2bpp.rowstride());
  EXPECT_EQ(1, img1x1x2bpp.required_size());

  image_spec   img8x1x2bpp(8, 2, 2);
  EXPECT_EQ(8, img8x1x2bpp.width());
  EXPECT_EQ(2, img8x1x2bpp.height());
  EXPECT_EQ(2, img8x1x2bpp.rowstride());
  EXPECT_EQ(4, img8x1x2bpp.required_size());

  // 4bpp

  image_spec   img1x1x4bpp(1, 1, 4);
  EXPECT_EQ(1, img1x1x4bpp.width());
  EXPECT_EQ(1, img1x1x4bpp.height());
  EXPECT_EQ(1, img1x1x4bpp.rowstride());
  EXPECT_EQ(1, img1x1x4bpp.required_size());

  // 8bpp

  image_spec   img1x1x8bpp(1, 1, 8);
  EXPECT_EQ(1, img1x1x8bpp.width());
  EXPECT_EQ(1, img1x1x8bpp.height());
  EXPECT_EQ(1, img1x1x8bpp.rowstride());
  EXPECT_EQ(1, img1x1x8bpp.required_size());

  image_spec    img32x2x8bpp(32, 2, 8);
  EXPECT_EQ(32, img32x2x8bpp.width());
  EXPECT_EQ( 2, img32x2x8bpp.height());
  EXPECT_EQ(32, img32x2x8bpp.rowstride());
  EXPECT_EQ(64, img32x2x8bpp.required_size());

  // 15bpp

  image_spec   img1x1x15bpp(1, 1, 15);
  EXPECT_EQ(1, img1x1x15bpp.width());
  EXPECT_EQ(1, img1x1x15bpp.height());
  EXPECT_EQ(2, img1x1x15bpp.rowstride());
  EXPECT_EQ(2, img1x1x15bpp.required_size());

  // 16bpp

  image_spec   img1x1x16bpp(1, 1, 16);
  EXPECT_EQ(1, img1x1x16bpp.width());
  EXPECT_EQ(1, img1x1x16bpp.height());
  EXPECT_EQ(2, img1x1x16bpp.rowstride());
  EXPECT_EQ(2, img1x1x16bpp.required_size());

  // 24bpp

  image_spec   img1x1x24bpp(1, 1, 24);
  EXPECT_EQ(1, img1x1x24bpp.width());
  EXPECT_EQ(1, img1x1x24bpp.height());
  EXPECT_EQ(3, img1x1x24bpp.rowstride());
  EXPECT_EQ(3, img1x1x24bpp.required_size());

  // 32bpp

  image_spec   img1x1x32bpp(1, 1, 32);
  EXPECT_EQ(1, img1x1x32bpp.width());
  EXPECT_EQ(1, img1x1x32bpp.height());
  EXPECT_EQ(4, img1x1x32bpp.rowstride());
  EXPECT_EQ(4, img1x1x32bpp.required_size());
}
