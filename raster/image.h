// Raster Library
// Copyright (C) 2015 David Capello

#ifndef RASTER_IMAGE_INCLUDED_H
#define RASTER_IMAGE_INCLUDED_H
#pragma once

#include "raster/buffer_view.h"
#include "raster/image_spec.h"
#include "raster/image_view.h"
#include <vector>

namespace raster {

  namespace details {
    struct alloc_buffer {
      std::vector<uint8_t> m_buf;
      alloc_buffer(const image_spec& spec) :
        m_buf(spec.required_size()) {
      }
    };
  }

  class image {
  public:
    image() :
      m_alloc(image_spec()),
      m_view(image_spec(), buffer_view()) {
    }

    image(const image_spec& spec) :
      m_alloc(spec),
      m_view(spec, buffer_view(m_alloc.m_buf)) {
    }

    image(image&& that) noexcept :
      m_alloc(image_spec()),
      m_view(image_spec(), buffer_view()) {
      std::swap(m_alloc, that.m_alloc);
      std::swap(m_view, that.m_view);
    }

    image& operator=(image&& that) noexcept {
      std::swap(m_alloc, that.m_alloc);
      std::swap(m_view, that.m_view);
      return *this;
    }

    int width() const { return m_view.width(); }
    int height() const { return m_view.height(); }
    int bits_per_pixel() const { return m_view.bits_per_pixel(); }

    const buffer_view::pointer line(const int y) const {
      return m_view.line(y);
    }

    buffer_view::pointer line(const int y) {
      return m_view.line(y);
    }

    operator image_view&() { return m_view; }

    operator bool() const { return m_view.bits_per_pixel() != 0; }

  private:
    details::alloc_buffer m_alloc;
    image_view m_view;
  };

} // namespace raster

#endif
