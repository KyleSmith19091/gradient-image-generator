#include "../include/Image.h"
#include "../include/Camera.h"
#include "../include/Render.h"
#include "../include/Config.h"

int main(int argc, const char* argv[]) {

    // Image
    Image image(config.aspect_ratio,config.image_width);

    // Camera
    Camera camera(config.viewportHeight,config.focalLength,Point3(config.originX,config.originY,config.originZ),image);

    // Render
    Renderer::writeImageToFile(config.out, image, camera);

}
