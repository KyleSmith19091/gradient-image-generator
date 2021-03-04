#ifndef CONFIG_H
#define CONFIG_H

#include "Vec3.h"

#include <ostream>
#include <iostream>

typedef struct CONFIG_STRUCT {
  // Colour gradient options
  double beginRed = 256;
  double beginGreen = 256;
  double beginBlue = 256;

  double endRed = 128;
  double endGreen = 179.2;
  double endBlue = 256;

  // Image settings
  double aspect_ratio = 16.0 / 9.0;
  int image_width = 900;

  // Camera settings
  double viewportHeight = 2.0;
  double focalLength = 1.0;
  double originX = 0;
  double originY = 0;
  double originZ = 0;

  // Renderer settings
  std::ostream &out = std::cout;
} Config;

Config config;

#endif
