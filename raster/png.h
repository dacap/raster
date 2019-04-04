// Raster Library
// Copyright (C) 2019 David Capello

#ifndef RASTER_PNG_INCLUDED_H
#define RASTER_PNG_INCLUDED_H
#pragma once

#include "raster/color.h"
#include "raster/image.h"
#include "raster/pixel.h"
#include "raster/primitives.h"

#include <cstdio>

#include <png.h>

namespace raster {
namespace png {

inline void report_png_error(png_structp png, png_const_charp error)
{
  printf("libpng: %s\n", error);
}

struct file_handle {
public:
  file_handle(FILE* handle) : m_handle(handle) { }
  ~file_handle() {
    if (m_handle)
      fclose(m_handle);
  }
  operator FILE*() { return m_handle; }
private:
  FILE* m_handle;
};

struct png_handle {
public:
  png_handle(png_structp png) : m_png(png) { }
  ~png_handle() {
    if (m_png)
      png_destroy_read_struct(&m_png, nullptr, nullptr);
  }
  operator png_structp() { return m_png; }
private:
  png_structp m_png;
};

image load_from_file(const char* filename)
{
  image img;
  file_handle file(std::fopen(filename, "rb"));
  if (!file)
    return img;

  png_handle png(png_create_read_struct(
    PNG_LIBPNG_VER_STRING, (png_voidp)nullptr,
    report_png_error, report_png_error));
  if (!png)
    return img;

  png_infop info = png_create_info_struct(png);
  if (!info)
    return img;

  if (setjmp(png_jmpbuf(png)))
    return img;

  png_init_io(png, file);
  png_set_sig_bytes(png, 0);
  png_read_info(png, info);

  png_uint_32 width, height;
  int bit_depth, color_type, interlace_type;
  png_get_IHDR(png, info, &width, &height,
               &bit_depth, &color_type, &interlace_type,
               nullptr, nullptr);

  int bpp = 8;
  switch (color_type) {
    case PNG_COLOR_TYPE_RGB_ALPHA:
      bpp = 32;
      break;
    case PNG_COLOR_TYPE_RGB:
      bpp = 24;
      break;
    case PNG_COLOR_TYPE_GRAY:
      bpp = 16;
      break;
    case PNG_COLOR_TYPE_PALETTE:
      bpp = 8;
      break;
  }

  img = image(image_spec(width, height, bpp));

  png_set_strip_16(png);        // Convert 16-bit/channel -> 8-bit/channel
  png_set_packing(png);         // Convert 1bpp, 2bpp, 4bpp -> 8bpp
  // Expand grayscale images to the full 8 bits from 1bpp, 2bpp, or 4bpp bits/pixel
  if (color_type == PNG_COLOR_TYPE_GRAY && bit_depth < 8)
    png_set_expand_gray_1_2_4_to_8(png);

  // Allocate the memory to hold the image using the fields of info_ptr.
  png_bytepp rows_pointer =
    (png_bytepp)png_malloc(png, sizeof(png_bytep) * height);
  for (int y=0; y<height; ++y)
    rows_pointer[y] = (png_bytep)png_malloc(png, png_get_rowbytes(png, info));

  const int number_passes = png_set_interlace_handling(png);
  for (int pass=0; pass<number_passes; ++pass) {
    for (int y=0; y<height; ++y)
      png_read_rows(png, rows_pointer+y, nullptr, 1);
  }

  // Convert rows_pointer into the doc::Image
  for (int y=0; y<height; ++y) {
    switch (color_type) {
      case PNG_COLOR_TYPE_RGB_ALPHA: {
        const uint8_t* src_address = rows_pointer[y];
        uint32_t* dst_address = (uint32_t*)img.line(y);

        for (int x=0; x<width; x++) {
          int r = *(src_address++);
          int g = *(src_address++);
          int b = *(src_address++);
          int a = *(src_address++);
          *(dst_address++) = rgba<ColorA8B8G8R8>(r, g, b, 255);
        }
        break;
      }
      case PNG_COLOR_TYPE_RGB: {
        const uint8_t* src_address = rows_pointer[y];

        for (int x=0; x<width; x++) {
          int r = *(src_address++);
          int g = *(src_address++);
          int b = *(src_address++);
          direct_put_pixel<Pixel24bpp>(img, x, y, rgb<ColorB8G8R8>(r, g, b));
        }
        break;
      }
    }
    png_free(png, rows_pointer[y]);
  }
  png_free(png, rows_pointer);
  return img;
}

} // namespace png
} // namespace raster

#endif
