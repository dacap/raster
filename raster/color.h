// Raster Library
// Copyright (C) 2015-2017 David Capello

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

  struct ColorR8G8B8 {
    typedef uint32_t value_type;
    typedef uint8_t component_type;
    static const ColorType type = ColorType::Rgb;
    static const uint32_t r_mask = 0x00ff0000;
    static const uint32_t g_mask = 0x0000ff00;
    static const uint32_t b_mask = 0x000000ff;
    static const uint32_t a_mask = 0;
    static const uint32_t r_shift = 16;
    static const uint32_t g_shift = 8;
    static const uint32_t b_shift = 0;
    static const uint32_t a_shift = 0;
    static const uint32_t r_bits = 8;
    static const uint32_t g_bits = 8;
    static const uint32_t b_bits = 8;
    static const uint32_t a_bits = 0;
  };

  struct ColorB8G8R8 {
    typedef uint32_t value_type;
    typedef uint8_t component_type;
    static const ColorType type = ColorType::Rgb;
    static const uint32_t r_mask = 0x000000ff;
    static const uint32_t g_mask = 0x0000ff00;
    static const uint32_t b_mask = 0x00ff0000;
    static const uint32_t a_mask = 0;
    static const uint32_t r_shift = 0;
    static const uint32_t g_shift = 8;
    static const uint32_t b_shift = 16;
    static const uint32_t a_shift = 0;
    static const uint32_t r_bits = 8;
    static const uint32_t g_bits = 8;
    static const uint32_t b_bits = 8;
    static const uint32_t a_bits = 0;
  };

  struct ColorR5G6B5 {
    typedef uint16_t value_type;
    typedef uint8_t component_type;
    static const ColorType type = ColorType::Rgb;
    static const uint32_t r_mask = 0xf800;
    static const uint32_t g_mask = 0x07e0;
    static const uint32_t b_mask = 0x001f;
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
    static const uint32_t r_mask = 0x001f;
    static const uint32_t g_mask = 0x07e0;
    static const uint32_t b_mask = 0xf800;
    static const uint32_t r_shift = 0;
    static const uint32_t g_shift = 5;
    static const uint32_t b_shift = 11;
    static const uint32_t r_bits = 5;
    static const uint32_t g_bits = 6;
    static const uint32_t b_bits = 5;
    static const uint32_t a_bits = 0;
  };

  struct ColorB4G4R4 {
    typedef uint16_t value_type;
    typedef uint8_t component_type;
    static const ColorType type = ColorType::Rgb;
    static const uint32_t r_mask = 0x00f;
    static const uint32_t g_mask = 0x0f0;
    static const uint32_t b_mask = 0xf00;
    static const uint32_t r_shift = 0;
    static const uint32_t g_shift = 4;
    static const uint32_t b_shift = 8;
    static const uint32_t r_bits = 4;
    static const uint32_t g_bits = 4;
    static const uint32_t b_bits = 4;
    static const uint32_t a_bits = 0;
  };

  struct ColorR4G4B4 {
    typedef uint16_t value_type;
    typedef uint8_t component_type;
    static const ColorType type = ColorType::Rgb;
    static const uint32_t r_mask = 0xf00;
    static const uint32_t g_mask = 0x0f0;
    static const uint32_t b_mask = 0x00f;
    static const uint32_t r_shift = 8;
    static const uint32_t g_shift = 4;
    static const uint32_t b_shift = 0;
    static const uint32_t r_bits = 4;
    static const uint32_t g_bits = 4;
    static const uint32_t b_bits = 4;
    static const uint32_t a_bits = 0;
  };

  struct ColorB1G1R1 {
    typedef uint8_t value_type;
    typedef uint8_t component_type;
    static const ColorType type = ColorType::Rgb;
    static const uint32_t r_mask = 0x1;
    static const uint32_t g_mask = 0x2;
    static const uint32_t b_mask = 0x4;
    static const uint32_t r_shift = 0;
    static const uint32_t g_shift = 1;
    static const uint32_t b_shift = 2;
    static const uint32_t r_bits = 1;
    static const uint32_t g_bits = 1;
    static const uint32_t b_bits = 1;
    static const uint32_t a_bits = 0;
  };

  struct ColorR1G1B1 {
    typedef uint8_t value_type;
    typedef uint8_t component_type;
    static const ColorType type = ColorType::Rgb;
    static const uint32_t r_mask = 0x4;
    static const uint32_t g_mask = 0x2;
    static const uint32_t b_mask = 0x1;
    static const uint32_t r_shift = 2;
    static const uint32_t g_shift = 1;
    static const uint32_t b_shift = 0;
    static const uint32_t r_bits = 1;
    static const uint32_t g_bits = 1;
    static const uint32_t b_bits = 1;
    static const uint32_t a_bits = 0;
  };

  // Max value for each component

  template<typename C>
  constexpr typename C::component_type maxr() { return (C::r_mask >> C::r_shift); }
  template<typename C>
  constexpr typename C::component_type maxg() { return (C::g_mask >> C::g_shift); }
  template<typename C>
  constexpr typename C::component_type maxb() { return (C::b_mask >> C::b_shift); }
  template<typename C>
  constexpr typename C::component_type maxa() { return (C::a_mask >> C::a_shift); }

  // Get color components

  template<typename C>
  typename C::component_type getr(const typename C::value_type color) {
    return ((color & C::r_mask) >> C::r_shift);
  }
  template<typename C>
  typename C::component_type getg(const typename C::value_type color) {
    return ((color & C::g_mask) >> C::g_shift);
  }
  template<typename C>
  typename C::component_type getb(const typename C::value_type color) {
    return ((color & C::b_mask) >> C::b_shift);
  }
  template<typename C>
  typename C::component_type geta(const typename C::value_type color) {
    return ((color & C::a_mask) >> C::a_shift);
  }

  // Convert a color components to other range (e.g. 5bits to 8bits)

  template<typename F, typename T>
  typename T::component_type getr2(const typename F::value_type color) {
    if constexpr (maxr<F>() == maxr<T>())
      return getr<F>(color);
    else
      return getr<F>(color) * maxr<T>() / maxr<F>();
  }

  template<typename F, typename T>
  typename T::component_type getg2(const typename F::value_type color) {
    if constexpr (maxg<F>() == maxg<T>())
      return getg<F>(color);
    else
      return getg<F>(color) * maxg<T>() / maxg<F>();
  }

  template<typename F, typename T>
  typename T::component_type getb2(const typename F::value_type color) {
    if constexpr (maxb<F>() == maxb<T>())
      return getb<F>(color);
    else
      return getb<F>(color) * maxb<T>() / maxb<F>();
  }

  template<typename F, typename T>
  typename T::component_type geta2(const typename F::value_type color) {
    if constexpr (maxa<F>() == maxa<T>())
      return geta<F>(color);
    else
      return geta<F>(color) * maxa<T>() / maxa<F>();
  }

  // Create new colors

  template<typename C>
  typename C::value_type rgba(const typename C::component_type r,
                              const typename C::component_type g,
                              const typename C::component_type b,
                              const typename C::component_type a) {
    return
      (typename C::value_type(r << C::r_shift) & C::r_mask) |
      (typename C::value_type(g << C::g_shift) & C::g_mask) |
      (typename C::value_type(b << C::b_shift) & C::b_mask) |
      (typename C::value_type(a << C::a_shift) & C::a_mask) ;
  }

  template<typename C>
  typename C::value_type rgb(const typename C::component_type r,
                             const typename C::component_type g,
                             const typename C::component_type b) {
    return
      (typename C::value_type(r << C::r_shift) & C::r_mask) |
      (typename C::value_type(g << C::g_shift) & C::g_mask) |
      (typename C::value_type(b << C::b_shift) & C::b_mask);
  }

  template<typename F, typename T>
  color_t convert_color(const color_t color) {
    if constexpr (F::type == ColorType::Rgba) {
      // No conversion
      if constexpr (T::type == ColorType::Rgba &&
                    F::r_mask == T::r_mask &&
                    F::g_mask == T::g_mask &&
                    F::b_mask == T::b_mask &&
                    F::a_mask == T::a_mask) {
        return color;
      }
      // RGBA -> RGBA
      else if constexpr (T::a_bits != 0) {
        return
          (getr2<F, T>(color) << T::r_shift) |
          (getg2<F, T>(color) << T::g_shift) |
          (getb2<F, T>(color) << T::b_shift) |
          (geta2<F, T>(color) << T::a_shift);
      }
      // RGBA -> RGB (Alpha channel is lost)
      else {
        return
          (getr2<F, T>(color) << T::r_shift) |
          (getg2<F, T>(color) << T::g_shift) |
          (getb2<F, T>(color) << T::b_shift);
      }
    }
    else if constexpr (F::type == ColorType::Rgb) {
      // No conversion
      if constexpr (T::type == ColorType::Rgb &&
                    F::r_mask == T::r_mask &&
                    F::g_mask == T::g_mask &&
                    F::b_mask == T::b_mask) {
        return color;
      }
      // RGB -> RGBA, so we use Alpha = Opaque color
      else if constexpr (T::a_bits != 0) {
        return
          (getr2<F, T>(color) << T::r_shift) |
          (getg2<F, T>(color) << T::g_shift) |
          (getb2<F, T>(color) << T::b_shift) |
          T::a_mask;            // Alpha = opaque
      }
      // RGB -> RGB
      else {
        return
          (getr2<F, T>(color) << T::r_shift) |
          (getg2<F, T>(color) << T::g_shift) |
          (getb2<F, T>(color) << T::b_shift);
      }
    }
    else {
      static_assert("Color conversion not supported");
    }
  }

} // namespace raster

#endif
