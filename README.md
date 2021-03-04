# Gradient Image Generator
## What is this all about
This is a simple tool that generates a PPM file using some basic raytracing along with some
linear interpolation to generate a gradient image which transitions from one colour to another.

You end up with something that looks like this:

<div align="center">
    <img src="./images/image.png"/>
</div>

The above image is gradient of white to blue.

The image can be changed by changing the attributes in the config file which is located in **include/Config.h**
directory

## Customising
The Config.h has some settings that can be changed by the user to alter the output:

```c++
typedef struct CONFIG_STRUCT {
  // Colour gradient options (RGB)
  double beginRed = 256;
  double beginGreen = 256;
  double beginBlue = 256;

  double endRed = 128;
  double endGreen = 179.2;
  double endBlue = 256;

  // Image settings
  double aspect_ratio = 16.0 / 9.0;
  int image_width = 900; // Image height is calculated according to width

  // Camera settings
  double viewportHeight = 2.0;
  double focalLength = 1.0;
  double originX = 0;
  double originY = 0;
  double originZ = 0;

  // Renderer settings
  std::ostream &out = std::cout;
} Config;
```

## PPM File Format

This project uses the PPM (Portable Pixelmap Format) file format, this allows us to write RGB values to a file in plaintext format and
then open using a typical image viewer.

A typical PPM file looks like this:

```text
P3 # Means this is a RGB color image in ASCII
3 2 # width * height
255 # Max colour value

255 0 0 # RGB triplets
0 255 0
0 0 255
255 255 0
255 255 255
0 0 0
```

## How to use this
After changing the config file to your preference, you can simply run the following in your terminal of choice

To compile the file and export data to image file in **res/image.ppm**
```bash
$ make
```

To open the image after compiling
```bash
$ make open-image
```

To do all of the above in one statement
```bash
$ make create-image
```

## Simplicity
This project was designed to use no dependencies except the C++ standard library, this is a C++11 project
because we are using constexpr to speed up some of the vector operations. 




