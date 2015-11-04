// Raster Library
// Copyright (C) 2015 David Capello

#ifndef RASTER_IMAGE_VIEW_INCLUDED_H
#define RASTER_IMAGE_VIEW_INCLUDED_H
#pragma once

#include "raster/buffer_view.h"
#include "raster/image_spec.h"

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

  private:
    image_spec m_spec;
    buffer_view& m_buf;
  };

} // namespace raster

#endif
