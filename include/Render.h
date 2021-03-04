#ifndef RENDER_H
#define RENDER_H
#include "Image.h"
#include "Camera.h"
#include "Ray.h"
#include "Color.h"
#include "RayUtils.h"

#include <iostream>

namespace Renderer {
    
    void writeImageToFile(std::ostream& out, Image& img, Camera& camera) {
        out << "P3\n" << img.imageWidth() << " " << img.imageHeight() << "\n255\n";
        for(int j = img.imageHeight()-1; j >= 0; --j){
            std::cerr << "\rScanlines remaining: " << j << " " << std::flush;
            for(int i = 0; i < img.imageWidth(); ++i){
                double u = double(i) / (img.imageWidth() - 1);
                double v = double(j) / (img.imageHeight() - 1);
                Ray r(camera.Origin(), camera.LowerLeftCorner() + u * camera.Horizontal() + v * camera.Vertical() - camera.Origin());
                write_color(out, RayUtils::ray_color(r));
            }
        }
        std::cerr << "\nDone\n";
    }

}
#endif
