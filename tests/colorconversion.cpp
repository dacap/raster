// Raster Library
// Copyright (C) 2015 David Capello

#include "raster/color.h"
#include "test.h"

using namespace raster;

int main() {
  EXPECT_EQ(0x00000000, rgba<ColorR8G8B8A8>(0x00, 0x00, 0x00, 0x00));
  EXPECT_EQ(0x10203040, rgba<ColorR8G8B8A8>(0x10, 0x20, 0x30, 0x40));
  EXPECT_EQ(0x30201040, rgba<ColorB8G8R8A8>(0x10, 0x20, 0x30, 0x40));
  EXPECT_EQ(0x40102030, rgba<ColorA8R8G8B8>(0x10, 0x20, 0x30, 0x40));
  EXPECT_EQ(0x40302010, rgba<ColorA8B8G8R8>(0x10, 0x20, 0x30, 0x40));
  EXPECT_EQ(0xffffffff, rgba<ColorR8G8B8A8>(0xff, 0xff, 0xff, 0xff));

  EXPECT_EQ(0x0000, rgb<ColorR5G6B5>(0, 0, 0));
  EXPECT_EQ(0x56AD, rgb<ColorR5G6B5>(10, 53, 13));
  EXPECT_EQ(0x56BF, rgb<ColorR5G6B5>(10, 53, 31));
  EXPECT_EQ(0xFEAD, rgb<ColorR5G6B5>(31, 53, 13));
  EXPECT_EQ(0xffff, rgb<ColorR5G6B5>(31, 63, 31));
}
