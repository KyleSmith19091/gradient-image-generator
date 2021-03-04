#ifndef CAMERA_H 
#define CAMERA_H

#include "Vec3.h"
#include "Vec3Utils.h"
#include "Image.h"

using namespace Vec3Utils;

class Camera{
    private:
        double viewport_height;
        double viewport_width;
        double focal_length;
        Point3 origin;
        Vec3 horizontal;
        Vec3 vertical;
        Vec3 lower_left_corner;

    public:
        Camera(double vh, double fl, Point3 o, Image& img) noexcept {
            this->viewport_height = vh;
            this->viewport_width = img.aspectRatio() * viewport_height;
            this->focal_length = fl;
            this->origin = o;
            this->horizontal = Vec3(viewport_width,0,0);
            this->vertical = Vec3(0,viewport_height, 0);
            this->lower_left_corner = origin - horizontal/2 - vertical/2 - Vec3(0,0,focal_length);
        }

        constexpr double viewportWidth() const noexcept { return this->viewport_width; };
        constexpr double viewportHeight() const noexcept { return this->viewport_height; };
        constexpr double focalLength() const noexcept { return this->focal_length; };
        constexpr Point3 Origin() const noexcept { return this->origin; };
        constexpr Vec3 Horizontal() const noexcept { return this->horizontal; };
        constexpr Vec3 Vertical() const noexcept { return this->vertical; };
        constexpr Vec3 LowerLeftCorner() const noexcept { return this->lower_left_corner; };
};	

#endif
