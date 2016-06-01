// Raster Library
// Copyright (C) 2015-2016 David Capello

#ifndef RASTER_BUFFER_VIEW_INCLUDED_H
#define RASTER_BUFFER_VIEW_INCLUDED_H
#pragma once

#include <cassert>
#include <cstddef>
#include <cstdint>
#include <vector>

#include "raster/image_spec.h"

namespace raster {

  // Wrapper for an array of bytes. It doesn't own the data.
  class buffer_view {
  public:
    typedef std::uint8_t value_type;
    typedef value_type* pointer;
    typedef value_type& reference;

    buffer_view(std::size_t size, pointer data)
      : m_size(size)
      , m_data(data) {
    }

    template<typename T>
    buffer_view(std::vector<T>& vector)
      : m_size(vector.size())
      , m_data(&vector[0]) {
    }

    std::size_t size() const { return m_size; }
    pointer begin() { return m_data; }
    pointer end() { return m_data+m_size; }
    const pointer begin() const { return m_data; }
    const pointer end() const { return m_data+m_size; }

    reference operator[](int i) const {
      assert(i >= 0 && i < int(m_size));
      return m_data[i];
    }

  private:
    size_t m_size;
    pointer m_data;
  };

} // namespace raster

#endif
