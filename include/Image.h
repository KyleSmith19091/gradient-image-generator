#ifndef IMAGE_H 
#define IMAGE_H
#include <ostream>
class Image{
    private:
        double aspect_ratio;
        int image_width;
        int image_height;

    public:
        constexpr Image(double aspect_ratio, int image_width) noexcept : aspect_ratio(aspect_ratio), image_width(image_width), image_height((int) image_width / aspect_ratio) {};

        constexpr double aspectRatio() const noexcept { return this->aspect_ratio; };
        constexpr int imageWidth() const noexcept { return this->image_width; };
        constexpr int imageHeight() const noexcept { return this->image_height; };

};	
#endif
