// Raster Library
// Copyright (C) 2015-2019 David Capello

#ifndef RASTER_PIXEL_INCLUDED_H
#define RASTER_PIXEL_INCLUDED_H
#pragma once

namespace raster {

  struct Pixel1bpp {
    typedef uint8_t value_type;
    typedef value_type* pointer;
    enum { bits_per_pixel = 1 };
    const static int get_pixel_offset(const int x) { return x/8; }
    const static int get_pixel_shift(const int x) { return (x&7); }
    const static int get_pixel_mask(const int x) { return 1 << get_pixel_shift(x); }
  };

  struct Pixel2bpp {
    typedef uint8_t value_type;
    typedef value_type* pointer;
    enum { bits_per_pixel = 2 };
    const static int get_pixel_offset(const int x) { return x/4; }
    const static int get_pixel_shift(const int x) { return 2*(x&3); }
    const static int get_pixel_mask(const int x) { return 3 << get_pixel_shift(x); }
  };

  struct Pixel4bpp {
    typedef uint8_t value_type;
    typedef value_type* pointer;
    enum { bits_per_pixel = 4 };
    const static int get_pixel_offset(const int x) { return x/2; }
    const static int get_pixel_shift(const int x) { return 4*(x&1); }
    const static int get_pixel_mask(const int x) { return 15 << get_pixel_shift(x); }
  };

  struct Pixel8bpp {
    typedef uint8_t value_type;
    typedef value_type* pointer;
    enum { bytes_per_pixel = 1 };
    enum { bits_per_pixel = 8 };
    const static int get_pixel_offset(const int x) { return x; }
    const static int get_pixel_shift(const int x) { return 0; }
    const static int get_pixel_mask(const int x) { return 0xff; }
    const static value_type get_value_from_address(pointer ptr) { return *ptr; }
  };

  struct Pixel16bpp {
    typedef uint16_t value_type;
    typedef value_type* pointer;
    enum { bytes_per_pixel = 2 };
    enum { bits_per_pixel = 16 };
    const static int get_pixel_offset(const int x) { return x << 1; }
    const static int get_pixel_shift(const int x) { return 0; }
    const static int get_pixel_mask(const int x) { return 0xffff; }
    const static value_type get_value_from_address(pointer ptr) { return *ptr; }
  };

  struct Pixel24bpp {
    typedef uint32_t value_type;
    typedef uint8_t* pointer;
    enum { bytes_per_pixel = 3 };
    enum { bits_per_pixel = 24 };
    const static int get_pixel_offset(const int x) { return x*3; }
    const static int get_pixel_shift(const int x) { return 0; }
    const static int get_pixel_mask(const int x) { return 0xffffff; }
    const static value_type get_value_from_address(pointer ptr) {
      return (ptr[0] | (ptr[1] << 8) | (ptr[2] << 16));
    }
  };

  struct Pixel32bpp {
    typedef uint32_t value_type;
    typedef value_type* pointer;
    enum { bytes_per_pixel = 4 };
    enum { bits_per_pixel = 32 };
    const static int get_pixel_offset(const int x) { return x << 2; }
    const static int get_pixel_shift(const int x) { return 0; }
    const static int get_pixel_mask(const int x) { return 0xffffffff; }
    const static value_type get_value_from_address(pointer ptr) { return *ptr; }
  };

  struct Pixel48bpp {
    typedef uint64_t value_type;
    typedef value_type* pointer;
    enum { bytes_per_pixel = 6 };
    enum { bits_per_pixel = 48 };
    const static int get_pixel_offset(const int x) { return x*6; }
    const static int get_pixel_shift(const int x) { return 0; }
  };

  struct Pixel64bpp {
    typedef uint64_t value_type;
    typedef value_type* pointer;
    enum { bytes_per_pixel = 8 };
    enum { bits_per_pixel = 64 };
    const static int get_pixel_offset(const int x) { return x << 4; }
    const static int get_pixel_shift(const int x) { return 0; }
  };

} // namespace raster

#endif
