/*
 * Author      : Shiva Agrawal
 * Date        : 07.09.2018
 * Version     : 1.1
 * Description : This file contains the image editing function using opencv
 * 				 1. Change brighness of Image
 *               2. Change Contrast of Image
 *				 3. Histogram Equalizer - Grayscale Image
 *				 4. Histogram Equalizer - RGB Image
 *               5. Image Rotation
 *               6. Changing Image size
 *
 * Steps to use: All the individual functionalities are implemented as preprocessor blocks inside main function. 
 *               Please activate one block at a time and use as reference recipe for image processing techniques.
 *				 One can just activate macro by uncommenting the corrsponding #define line and use it.
 */
 
#include<opencv2/opencv.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>

using namespace cv;
using namespace std;

// #define CHANGE_BRIGHTNESS_OF_IMAGE
// #define CHANGE_CONTRAST_OF_IMAGE
// #define GRAYSCALE_IMAGE_HISTOGRAM_EQUILIZER
// #define RGB_IMAGE_HISTOGRAM_EQUILIZER
// #define ROTATE_IMAGE
// #define CHANGE_IMAGE_SIZE


int main()
{
#ifdef CHANGE_BRIGHTNESS_OF_IMAGE

	/*
	 * Increase brightness means adding more value (mostly a constant) to all the pixel values of an Image
	 * Decresing brighness means subtarcting value from all the pixels of an Image
	 * For grayscale image, we can add one scalar value to its single channel - say. Scalar(50)
	 * For RGB image, we can add a constant value to one or more of the 3 channels - say. Scalar(50,40,50), Scalar(0,50,0)
	 */

	Mat normalImage, brightImage, lowBrightImage;
	normalImage = imread("sky.jpeg");  //load color image
	brightImage = normalImage + Scalar(50,50,50);  // increase brightness of complete image
	lowBrightImage = normalImage - Scalar(50,50,50); // decrease the brightness of complete image

	// display images
	imshow("Original Image", normalImage);
	imshow("high Brightness Image", brightImage);
	imshow("low Brightness Image", lowBrightImage);

	waitKey(0);

#endif

#ifdef CHANGE_CONTRAST_OF_IMAGE

	/*
	 * Changing the contrast means increasing the weight of the pixels. More the contrast is, the sharper the image is.
	 * originalImage.convertTo(destinationMatrix, depth, multiplicationValue, value of border)
	 */

	Mat normalImage1, contrastImage[2];
	normalImage1 = imread("sky.jpeg");
	normalImage1.convertTo(contrastImage[0],-1,2,0); // increase contract value greater than 1
	normalImage1.convertTo(contrastImage[1],-1,0.5,0); // increase contract value greater than 1

	// display images
	imshow("Original Image", normalImage1);
	imshow("High Constrast Image", contrastImage[0]);
	imshow("Low Constrast Image", contrastImage[1]);

	waitKey(0);
	
#endif

#ifdef GRAYSCALE_IMAGE_HISTOGRAM_EQUILIZER

	/*
	 * equalizeHist(sourceImage,destinationImage);
	 *
	 */
	Mat normalImage2, histEqualizedImage;
	normalImage2 = imread("sky.jpeg", IMREAD_GRAYSCALE);
	equalizeHist(normalImage2,histEqualizedImage);
	
	// display images
	imshow("Original Grayscale Image", normalImage2);
	imshow("Histogram Equalized Grayscale Image", histEqualizedImage);

	waitKey(0);

#endif

#ifdef RGB_IMAGE_HISTOGRAM_EQUILIZER

	/*
	 * to apply histogram equalizer on multi channel image, we have to first separate the channel and then apply
	 * on that channel because equlizer is applicable to only single channel at a time.
	 * So for RGB, first split the channels- split()
	 * Then apply equalizeHist() to one or more channels
	 * Then merge the channels - merge()
	 */

	Mat normalImage3, histEqualizedImage[4];
	vector <Mat> channels;
	normalImage3 = imread("sky.jpeg");
	cout << normalImage3.channels()<<endl;
	cout<< normalImage3.size()<<endl;

	// apply equalizer to only red channel
	split(normalImage3,channels);
	equalizeHist(channels[2],channels[2]);  // on red channel
	merge(channels,histEqualizedImage[0]);

	// apply equalizer to only green channel
	split(normalImage3,channels);
	equalizeHist(channels[1],channels[1]);  // on green channel
	merge(channels,histEqualizedImage[1]);

	// apply equalizer to only blue channel
	split(normalImage3,channels);
	equalizeHist(channels[0],channels[0]);  // on blue channel
	merge(channels,histEqualizedImage[2]);

	// apply equalizer to only red and blue channel
	split(normalImage3,channels);
	equalizeHist(channels[2],channels[2]);  // on blue channel
	equalizeHist(channels[0],channels[0]);  // on blue channel
	merge(channels,histEqualizedImage[3]);
	
	// NOTE: similar to shoen above, other combinations of channels can also be implemented
	
	// display images
	imshow("Original RGB Image", normalImage3);
	imshow("Histogram Equalizer on Red channel of RGB Image", histEqualizedImage[0]);
	imshow("Histogram Equalizer on Green channel of RGB Image", histEqualizedImage[1]);
	imshow("Histogram Equalizer on Blue channel of RGB Image", histEqualizedImage[2]);
	imshow("Histogram Equalizer on Red and Blue channel of RGB Image", histEqualizedImage[3]);

	waitKey(0);

#endif

#ifdef ROTATE_IMAGE
	/*
	 * For rotating the matrix, two functions are used
	 * 1. getRotationMatrix2D(Point centrePoint(x,y), int RotationAngle, int ScalingFactor)
	 * When RotationAngle is positive, image rotates counter-clockwise, when negative, clockwise
	 *
	 * 2. warpAffine(Mat sourceMatrix, Mat destinationMatrix, Mat affineMatrix,sizeOfDestinationImage)
	 * This function just applies the affine defined in affineMatrix to the sourceMatrix. It is not just for rotation.
	 */

	Mat originalImage, rotatedImage, affineMatrix;
	originalImage = imread("rgb.jpg");
	namedWindow("Original Image", WINDOW_AUTOSIZE);
	imshow("Original Image", originalImage);

	// find centre point of original image
	int x = originalImage.rows / 2;
	int y = originalImage.cols / 2;

	Point centrePoint(x,y);

	// define rotation Angle
	int rotationAngle = -90;  // degree

	// int scaling factor
	int scalingFactor = 1;  // keep the same size of image

	//create affine Matrix using the getRotationMatrix2D()
	affineMatrix = getRotationMatrix2D(centrePoint, rotationAngle, scalingFactor);

	// apply this affineMatrix to actual image to rotate it
	warpAffine(originalImage, rotatedImage, affineMatrix, originalImage.size());

	//display the rotated image
	namedWindow("Rotated Image", WINDOW_AUTOSIZE);
	imshow("Rotated Image", rotatedImage);
	waitKey(0);

#endif

#ifdef CHANGE_IMAGE_SIZE

	/*
	 * For changing the image size, two functions are used
	 * 1. getRotationMatrix2D(Point centrePoint(x,y), int RotationAngle, float ScalingFactor)
	 * When we keep rotation angle as 0. and image size changes using ScalingFactor value
	 * ScalingFactor value = 1, same size
	 * 					less than 1,  reduce size
	 * 					more than 1, increase size
	 *
	 * 2. warpAffine(Mat sourceMatrix, Mat destinationMatrix, Mat affineMatrix,sizeOfDestinationImage)
	 * This function just applies the affine defined in affineMatrix to the sourceMatrix.
	 */

	Mat originalImage, newSizeImage, affineMatrix;
	originalImage = imread("rgb.jpg");
	namedWindow("Original Image", WINDOW_AUTOSIZE);
	imshow("Original Image", originalImage);

	// find centre point of original image
	int x = originalImage.rows / 2;
	int y = originalImage.cols / 2;

	Point centrePoint(x, y);

	// define rotation Angle
	int rotationAngle = 0;  // 0 degree to avoid rotation

	// int scaling factor to change image size
	float scalingFactor = 0.5;  // this reduce size to half

	//create affine Matrix using the getRotationMatrix2D()
	affineMatrix = getRotationMatrix2D(centrePoint, rotationAngle,
			scalingFactor);

	// apply this affineMatrix to actual image to rotate it
	warpAffine(originalImage, newSizeImage, affineMatrix, originalImage.size());

	//display the rotated image
	namedWindow("New Sized Image", WINDOW_AUTOSIZE);
	imshow("New Sized Image", newSizeImage);
	waitKey(0);

#endif

	return 0;
}


