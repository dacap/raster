// Raster Library
// Copyright (C) 2019 David Capello

#ifndef RASTER_IMAGE_ITERATOR_H
#define RASTER_IMAGE_ITERATOR_H
#pragma once

namespace raster {

  template<typename Pixel>
  class image_iterator {
  public:
    typedef typename Pixel::value_type value_type;
    typedef typename Pixel::pointer pointer;

    image_iterator(const image_spec& spec,
                   buffer_view::pointer ptr) :
      m_spec(spec),
      m_ptr((pointer)ptr) {
    }
    bool operator!=(const image_iterator& that) const {
      return m_ptr != that.m_ptr;
    }
    value_type operator*() const {
      return Pixel::get_value_from_address(m_ptr);
    }
    image_iterator& operator++() {
      Pixel::advance_pointer(m_ptr);
      return *this;
    }
  private:
    const image_spec& m_spec;
    pointer m_ptr;
  };

} // namespace raster

#endif
