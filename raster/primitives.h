// Raster Library
// Copyright (C) 2015-2019 David Capello

#ifndef RASTER_PRIMITIVES_INCLUDED_H
#define RASTER_PRIMITIVES_INCLUDED_H
#pragma once

#include "raster/buffer_view.h"
#include "raster/color.h"
#include "raster/pixel.h"
#include "raster/image_view.h"

namespace raster {

  class image_view;

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
        (typename Pixel::pointer)(img.line(y) + (x / (8 / Pixel::bits_per_pixel)));
    }
    else if constexpr (Pixel::bits_per_pixel == 24) {
      return
        (typename Pixel::pointer)(img.line(y) + 3*x);
    }
    else {
      return
        ((typename Pixel::pointer)img.line(y)) + x;
    }
  }

#ifdef _MSC_VER
#pragma warning(pop)
#endif

  template<typename Pixel>
  void direct_put_pixel(image_view& img, const int x, const int y, const typename Pixel::value_type value) {
    assert(img.spec().bits_per_pixel() == Pixel::bits_per_pixel);

    if constexpr (Pixel::bits_per_pixel < 8) {
      auto p = pixel_address<Pixel>(img, x, y);
      *p = ((*p) & ~Pixel::get_pixel_mask(x))
         | (value << Pixel::get_pixel_shift(x));
    }
    else if constexpr (Pixel::bits_per_pixel == 24) {
      auto p = pixel_address<Pixel>(img, x, y);
      *(p++) = (value & 0x0000ff);
      *(p++) = (value & 0x00ff00) >> 8;
      *(p++) = (value & 0xff0000) >> 16;
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
    else if constexpr (Pixel::bits_per_pixel == 24) {
      auto p = pixel_address<Pixel>(img, x, y);
      return (p[0] | (p[1] << 8) | (p[2] << 16));
    }
    else {
      return *pixel_address<Pixel>(img, x, y);
    }
  }

  inline void put_pixel(image_view& img, const int x, const int y, const color_t value) {
    switch (img.spec().bits_per_pixel()) {
      case 1: direct_put_pixel<Pixel1bpp>(img, x, y, value); break;
      case 2: direct_put_pixel<Pixel2bpp>(img, x, y, value); break;
      case 4: direct_put_pixel<Pixel4bpp>(img, x, y, value); break;
      case 8: direct_put_pixel<Pixel8bpp>(img, x, y, value); break;
      case 16: direct_put_pixel<Pixel16bpp>(img, x, y, value); break;
      case 24: direct_put_pixel<Pixel24bpp>(img, x, y, value); break;
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
      case 24: return direct_get_pixel<Pixel24bpp>(img, x, y);
      case 32: return direct_get_pixel<Pixel32bpp>(img, x, y);
    }
    assert(false);
    return 0;
  }

} // namespace raster

#endif
