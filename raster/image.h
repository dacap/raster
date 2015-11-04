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

  class image : private details::alloc_buffer,
                private buffer_view,
                public image_view {
  public:
    image(const image_spec& spec) :
      alloc_buffer(spec),
      buffer_view(alloc_buffer::m_buf),
      image_view(spec, *this) {
    }
  };

} // namespace raster

#endif
