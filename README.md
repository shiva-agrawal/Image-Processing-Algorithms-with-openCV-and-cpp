# Image Processing with openCV,  C++ and Ubuntu 16.04

The aim of this project is to collect and provide basic image processing functionalities of OpenCV library. Here, various image processing functions are available and categorized. 

Each category of the functions is written as separate .cpp file. Inside each .cpp file, further each functionality is written as preprocessor #ifdef … #endif block which user can activate and deactivate as per requirement. Within each block of code, the respective function is well explained and tested using images.

For the development, I have used Eclipse CDT as IDE, OpenCV, C++ programming language and Ubuntu 16.04 (Linux OS).


Folder structure:
1. doc
	* Project details.pdf - Short project report
2. src
	* BasicImageProcessing.cpp, DrawShapes.cpp, ImageEditing.cpp - source code
  	* test.jpg, forest.jpg, rgb.jpg, sky.jpeg  - Images used in functions
  
# Table of Content

1. Basic Image Processing	
    * Load/Import/Read Image
    * Write image
    * Create single channel image (ex. grayscale image)
    * Create multichannel image (ex. RGB image)
    * Finding number of channels in an image
    * Split channels of an image 
    * Changing Color space of an image
    * Binary images
    * Extract Pixel values of an image
    * Select Region of Interest (ROI) of an image

2. Shapes and Text	
    * Draw Line on image
    * Draw Circle on image
    * Draw Ellipse on image
    * Draw Rectangle on image
    * Write Text on image
    
3. Image Editing
    * Change Brightness of Image
    * Change Contrast of Image
    * Histogram Equalizer - Grayscale Image
    * Histogram Equalizer - RGB Image
    * Image Rotation
    * Changing Image size

