// Raster Library
// Copyright (C) 2019 David Capello

#ifndef RASTER_ALGORITHM_INCLUDED_H
#define RASTER_ALGORITHM_INCLUDED_H
#pragma once

#include "raster/image_view.h"
#include "raster/primitives.h"

namespace raster {

  // For each pixel with get pixel
  template<typename Pixel, typename Pred>
  void for_each_pixel(image_view& img, Pred pred) {
    for (int y=0; y<img.height(); ++y)
      for (int x=0; x<img.width(); ++x)
        pred(direct_get_pixel<Pixel>(img, x, y));
  }

  // For each pixel with iterators
  template<typename Pixel, typename Pred>
  void for_each_pixel2(image_view& img, Pred pred) {
    for (auto pixel : img.view_as<Pixel>())
      pred(pixel);
  }

} // namespace raster

#endif
