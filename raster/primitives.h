// Raster Library
// Copyright (C) 2015-2017 David Capello

#ifndef RASTER_PRIMITIVES_INCLUDED_H
#define RASTER_PRIMITIVES_INCLUDED_H
#pragma once

#include "raster/buffer_view.h"
#include "raster/color.h"
#include "raster/image_view.h"

namespace raster {

  class image_view;

  //////////////////////////////////////////////////////////////////////

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
  };

  struct Pixel16bpp {
    typedef uint16_t value_type;
    typedef value_type* pointer;
    enum { bytes_per_pixel = 2 };
    enum { bits_per_pixel = 16 };
    const static int get_pixel_offset(const int x) { return x << 1; }
    const static int get_pixel_shift(const int x) { return 0; }
    const static int get_pixel_mask(const int x) { return 0xffff; }
  };

  struct Pixel32bpp {
    typedef uint32_t value_type;
    typedef value_type* pointer;
    enum { bytes_per_pixel = 4 };
    enum { bits_per_pixel = 32 };
    const static int get_pixel_offset(const int x) { return x << 2; }
    const static int get_pixel_shift(const int x) { return 0; }
    const static int get_pixel_mask(const int x) { return 0xffffffff; }
  };

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable:4723)
#endif

  template<typename Pixel, typename ImageView>
  typename Pixel::pointer pixel_address(ImageView& img, const int x, const int y) {
    assert(x >= 0 && x < img.spec().width());
    assert(y >= 0 && y < img.spec().height());
    assert(img.spec().bits_per_pixel() == Pixel::bits_per_pixel);

    if constexpr (Pixel::bits_per_pixel < 8) {
      return
        (typename Pixel::pointer)(&img.buf()[y*img.spec().rowstride()] +
                                  (x / (8 / Pixel::bits_per_pixel)));
    }
    else {
      return
        ((typename Pixel::pointer)&img.buf()[y*img.spec().rowstride()]) + x;
    }
  }

#ifdef _MSC_VER
#pragma warning(pop)
#endif

  template<typename Pixel>
  void direct_put_pixel(image_view& img, const int x, const int y, const typename Pixel::value_type value) {
    assert(img.spec().bits_per_pixel() == Pixel::bits_per_pixel);

    if constexpr (Pixel::bits_per_pixel < 8) {
      typename Pixel::pointer p = pixel_address<Pixel>(img, x, y);
      *p = ((*p) & ~Pixel::get_pixel_mask(x))
         | (value << Pixel::get_pixel_shift(x));
    }
    else {
      *pixel_address<Pixel>(img, x, y) = value;
    }
  }

  template<typename Pixel>
  typename Pixel::value_type direct_get_pixel(const image_view& img, const int x, const int y) {
    assert(img.spec().bits_per_pixel() == Pixel::bits_per_pixel);

    if constexpr (Pixel::bits_per_pixel < 8) {
      return ((*pixel_address<Pixel>(img, x, y)) & Pixel::get_pixel_mask(x))
             >> Pixel::get_pixel_shift(x);
    }
    else {
      return *pixel_address<Pixel>(img, x, y);
    }
  }

  //////////////////////////////////////////////////////////////////////

  inline void put_pixel(image_view& img, const int x, const int y, const color_t value) {
    switch (img.spec().bits_per_pixel()) {
      case 1: direct_put_pixel<Pixel1bpp>(img, x, y, value); break;
      case 2: direct_put_pixel<Pixel2bpp>(img, x, y, value); break;
      case 4: direct_put_pixel<Pixel4bpp>(img, x, y, value); break;
      case 8: direct_put_pixel<Pixel8bpp>(img, x, y, value); break;
      case 16: direct_put_pixel<Pixel16bpp>(img, x, y, value); break;
      case 32: direct_put_pixel<Pixel32bpp>(img, x, y, value); break;
      default: assert(false);
    }
  }

  inline color_t get_pixel(const image_view& img, const int x, const int y) {
    switch (img.spec().bits_per_pixel()) {
      case 1: return direct_get_pixel<Pixel1bpp>(img, x, y);
      case 2: return direct_get_pixel<Pixel2bpp>(img, x, y);
      case 4: return direct_get_pixel<Pixel4bpp>(img, x, y);
      case 8: return direct_get_pixel<Pixel8bpp>(img, x, y);
      case 16: return direct_get_pixel<Pixel16bpp>(img, x, y);
      case 32: return direct_get_pixel<Pixel32bpp>(img, x, y);
    }
    assert(false);
    return 0;
  }

} // namespace raster

#endif
