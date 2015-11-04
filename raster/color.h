// Raster Library
// Copyright (C) 2015 David Capello

#ifndef RASTER_COLOR_INCLUDED_H
#define RASTER_COLOR_INCLUDED_H
#pragma once

#include <cstdint>

namespace raster {

  // Biggest integer type to store an image color.
  typedef uint32_t color_t;

  enum class ColorType {
    Rgba,
    Rgb,
    Grayscale,
    Indexed,
  };

  struct ColorR8G8B8A8 {
    typedef uint32_t value_type;
    typedef uint8_t component_type;
    static const ColorType type = ColorType::Rgba;
    static const uint32_t r_mask = 0xff000000;
    static const uint32_t g_mask = 0x00ff0000;
    static const uint32_t b_mask = 0x0000ff00;
    static const uint32_t a_mask = 0x000000ff;
    static const uint32_t r_shift = 24;
    static const uint32_t g_shift = 16;
    static const uint32_t b_shift = 8;
    static const uint32_t a_shift = 0;
    static const uint32_t r_bits = 8;
    static const uint32_t g_bits = 8;
    static const uint32_t b_bits = 8;
    static const uint32_t a_bits = 8;
  };

  struct ColorB8G8R8A8 {
    typedef uint32_t value_type;
    typedef uint8_t component_type;
    static const ColorType type = ColorType::Rgba;
    static const uint32_t r_mask = 0x0000ff00;
    static const uint32_t g_mask = 0x00ff0000;
    static const uint32_t b_mask = 0xff000000;
    static const uint32_t a_mask = 0x000000ff;
    static const uint32_t r_shift = 8;
    static const uint32_t g_shift = 16;
    static const uint32_t b_shift = 24;
    static const uint32_t a_shift = 0;
    static const uint32_t r_bits = 8;
    static const uint32_t g_bits = 8;
    static const uint32_t b_bits = 8;
    static const uint32_t a_bits = 8;
  };

  struct ColorA8R8G8B8 {
    typedef uint32_t value_type;
    typedef uint8_t component_type;
    static const ColorType type = ColorType::Rgba;
    static const uint32_t r_mask = 0x00ff0000;
    static const uint32_t g_mask = 0x0000ff00;
    static const uint32_t b_mask = 0x000000ff;
    static const uint32_t a_mask = 0xff000000;
    static const uint32_t r_shift = 16;
    static const uint32_t g_shift = 8;
    static const uint32_t b_shift = 0;
    static const uint32_t a_shift = 24;
    static const uint32_t r_bits = 8;
    static const uint32_t g_bits = 8;
    static const uint32_t b_bits = 8;
    static const uint32_t a_bits = 8;
  };

  struct ColorA8B8G8R8 {
    typedef uint32_t value_type;
    typedef uint8_t component_type;
    static const ColorType type = ColorType::Rgba;
    static const uint32_t r_mask = 0x000000ff;
    static const uint32_t g_mask = 0x0000ff00;
    static const uint32_t b_mask = 0x00ff0000;
    static const uint32_t a_mask = 0xff000000;
    static const uint32_t r_shift = 0;
    static const uint32_t g_shift = 8;
    static const uint32_t b_shift = 16;
    static const uint32_t a_shift = 24;
    static const uint32_t r_bits = 8;
    static const uint32_t g_bits = 8;
    static const uint32_t b_bits = 8;
    static const uint32_t a_bits = 8;
  };

  struct ColorR5G6B5 {
    typedef uint16_t value_type;
    typedef uint8_t component_type;
    static const ColorType type = ColorType::Rgb;
    static const uint32_t r_mask = 0xF800;
    static const uint32_t g_mask = 0x07E0;
    static const uint32_t b_mask = 0x001F;
    static const uint32_t r_shift = 11;
    static const uint32_t g_shift = 5;
    static const uint32_t b_shift = 0;
    static const uint32_t r_bits = 5;
    static const uint32_t g_bits = 6;
    static const uint32_t b_bits = 5;
    static const uint32_t a_bits = 0;
  };

  struct ColorB5G6R5 {
    typedef uint16_t value_type;
    typedef uint8_t component_type;
    static const ColorType type = ColorType::Rgb;
    static const uint32_t r_mask = 0x001F;
    static const uint32_t g_mask = 0x07E0;
    static const uint32_t b_mask = 0xF800;
    static const uint32_t r_shift = 0;
    static const uint32_t g_shift = 5;
    static const uint32_t b_shift = 11;
    static const uint32_t r_bits = 5;
    static const uint32_t g_bits = 6;
    static const uint32_t b_bits = 5;
    static const uint32_t a_bits = 0;
  };

  template<typename Color>
  typename Color::value_type rgba(typename Color::component_type r,
                                  typename Color::component_type g,
                                  typename Color::component_type b,
                                  typename Color::component_type a) {
    return
      (typename Color::value_type(r << Color::r_shift) & Color::r_mask) |
      (typename Color::value_type(g << Color::g_shift) & Color::g_mask) |
      (typename Color::value_type(b << Color::b_shift) & Color::b_mask) |
      (typename Color::value_type(a << Color::a_shift) & Color::a_mask) ;
  }

  template<typename Color>
  typename Color::value_type rgb(typename Color::component_type r,
                                 typename Color::component_type g,
                                 typename Color::component_type b) {
    return
      (typename Color::value_type(r << Color::r_shift) & Color::r_mask) |
      (typename Color::value_type(g << Color::g_shift) & Color::g_mask) |
      (typename Color::value_type(b << Color::b_shift) & Color::b_mask);
  }

  template<typename FromColor, typename ToColor>
  color_t convert_color(color_t color) {
    if (FromColor::type == ToColor::type) {
      if (FromColor::type == ColorType::Rgba)
        return
          (((FromColor::r_mask & color) >> FromColor::r_shift) << ToColor::r_shift) |
          (((FromColor::g_mask & color) >> FromColor::g_shift) << ToColor::g_shift) |
          (((FromColor::b_mask & color) >> FromColor::b_shift) << ToColor::b_shift) |
          (((FromColor::a_mask & color) >> FromColor::a_shift) << ToColor::a_shift) ;
      else if (FromColor::type == ColorType::Rgb)
        return
          (((FromColor::r_mask & color) >> FromColor::r_shift) << ToColor::r_shift) |
          (((FromColor::g_mask & color) >> FromColor::g_shift) << ToColor::g_shift) |
          (((FromColor::b_mask & color) >> FromColor::b_shift) << ToColor::b_shift) ;
      else
        return (color & ToColor::mask);
    }
    else {
      return 0;
    }
  }

} // namespace raster

#endif
