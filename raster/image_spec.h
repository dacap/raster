// Raster Library
// Copyright (C) 2015 David Capello

#ifndef RASTER_IMAGE_SPEC_INCLUDED_H
#define RASTER_IMAGE_SPEC_INCLUDED_H
#pragma once

namespace raster {

  class image_spec {
  public:
    image_spec()
      : m_width(0)
      , m_height(0)
      , m_bits_per_pixel(0) {
    }

    image_spec(int width, int height, int bits_per_pixel)
      : m_width(width)
      , m_height(height)
      , m_bits_per_pixel(bits_per_pixel) {
    }

    int width() const { return m_width; }
    int height() const { return m_height; }
    int bits_per_pixel() const { return m_bits_per_pixel; }

    int rowstride() const {
      if (m_bits_per_pixel == 0)
        return 0;
      else if (m_bits_per_pixel < 8)
        return ((m_width / (8 / m_bits_per_pixel)) +
                (m_width % (8 / m_bits_per_pixel) ? 1: 0));
      else
        return m_width * ((m_bits_per_pixel + 7) / 8);
    }

    int required_size() const {
      return rowstride() * height();
    }

  private:
    int m_width;
    int m_height;
    int m_bits_per_pixel;
  };

} // namespace raster

#endif
