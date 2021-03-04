#include "Ray.h"
#include "Color.h"
#include "Config.h"

namespace RayUtils {

    Color ray_color(const Ray &r) {
      Vec3 unit_direction = unit_vector(r.direction());
      double t = 0.5 * (unit_direction.y() + 1.0);
      return lerp(
              Color(config.beginRed/256,config.beginGreen/256,config.beginBlue/256),
              Color(config.endRed/256,config.endGreen/256,config.endBlue/256), 
              t);
    }

} 
