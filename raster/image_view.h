// Raster Library
// Copyright (C) 2015-2017 David Capello

#ifndef RASTER_IMAGE_VIEW_INCLUDED_H
#define RASTER_IMAGE_VIEW_INCLUDED_H
#pragma once

#include "raster/buffer_view.h"
#include "raster/image_spec.h"
#include <cassert>

namespace raster {

  class image_view {
  public:
    image_view(const image_spec& spec, buffer_view& buf)
      : m_spec(spec)
      , m_buf(buf) {
    }

    const image_spec& spec() const { return m_spec; }
    const buffer_view& buf() const { return m_buf; }
    buffer_view& buf() { return m_buf; }

    const buffer_view::pointer line(const int y) const {
      assert(y >= 0 && y < m_spec.height());
      return &m_buf[y*m_spec.rowstride()];
    }

    buffer_view::pointer line(const int y) {
      assert(y >= 0 && y < m_spec.height());
      return &m_buf[y*m_spec.rowstride()];
    }

  private:
    image_spec m_spec;
    buffer_view& m_buf;
  };

} // namespace raster

#endif
