/*
 * Author      : Shiva Agrawal
 * Date        : 07.09.2018
 * Version     : 1.0
 * Description : This file contains the basic image processing functions using OpenCV like 
 *				 1. Load Image
 *				 2. Write image
 *				 3. Create single channel image (ex. grayscale image)
 *				 4. Create multichannel image (ex. RGB image)
 *				 5. Finding number of channels in an image
 *				 6. Split channels of an image 
 *				 7. Changing Color space of an image
 *				 8. Binary images
 *				 9. Extract Pixel values of an image
 *				 10.Selection Region of Interest (ROI) of an image
 *
 * Steps to use: All the individual functionalities are implemented as preprocessor blocks inside main function. 
 *               Please activate one block at a time and use as reference recipe for image processing techniques.
 *				 One can just activate macro by uncommenting the corrsponding #define line and use it.
 *              
 */
 
#include<opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include<iostream>

using namespace cv;
using namespace std;

// #define READ_IMAGE
// #define WRITE_IMAGE
// #define ONE_CHANNEL_IMAGE
// #define MULTI_CHANNEL_IMAGE_RGB
// #define FIND_NUM_OF_CHANNELS_IN_IMAGE
// #define SPLIT_COLOUR_CHANNELS_OF_RGB
// #define CHANGE_COLOR_SPACE_OF_IMAGE
// #define MAKE_BINARY_IMAGE
// #define DISPLAY_PIXEL_VALUES_SINGLE_CHANNEL_IMAGE
// #define IMAGE_REGION_OF_INTEREST


int main()
{

#ifdef READ_IMAGE

	Mat myImage[2];  // declare a varible of type Mat (similar to Matlab matrix)
	myImage[0] = imread("test.jpg",IMREAD_GRAYSCALE);
	myImage[1] = imread("test.jpg",IMREAD_COLOR);

	imshow("Butterfly_grey", myImage[0]);
	imshow("Butterfly_colour", myImage[1]);
	waitKey(0);
	
#endif

#ifdef WRITE_IMAGE

	Mat myImage;  // declare a varible of type Mat (similar to Matlab matrix)
	myImage = imread("test.jpg",IMREAD_GRAYSCALE);

	imwrite("test_grayscale.png",myImage);
	waitKey(0);
	
#endif

#ifdef ONE_CHANNEL_IMAGE

	/* grayscale images are single channel
	 * 8UC1 - 8 bits and total channel 1
	 * 8 bits means the pixel intensity is represented from 0 to 255
	 * for grayscale, 0 means no colour - black
	 * 				  1 means full colour - while (full intensity)
	 */
	Mat singleChannelImage1(480,640, CV_8UC1, Scalar(0));   // create image using pixel values
	Mat singleChannelImage2(480,640, CV_8UC1, Scalar(100));  // create image using pixel values
	Mat singleChannelImage3(280,340, CV_8UC1, Scalar(255));  // create image using pixel values

	imshow("Image1", singleChannelImage1);
	imshow("Image2", singleChannelImage2);
	imshow("Image3", singleChannelImage3);

	waitKey(0);

#endif

#ifdef MULTI_CHANNEL_IMAGE_RGB
	/*
	 * in opencv, RGB images is taken as BGR.
	 * Hence 1st channel is B (Blue), 2nd channel is G (Green) and 3rd is R (Red)
	 */

	Mat multiChannelImage1(200,200, CV_8UC3, Scalar(255,0,0)); // blue image
	Mat multiChannelImage2(200,200, CV_8UC3, Scalar(0,255,0));// green image
	Mat multiChannelImage3(200,200, CV_8UC3, Scalar(0,0,255)); // red image
	Mat multiChannelImage4(200,200, CV_8UC3, Scalar(100,100,100)); //mix colour

	imshow("Image1", multiChannelImage1);
	imshow("Image2", multiChannelImage2);
	imshow("Image3", multiChannelImage3);
	imshow("Image4", multiChannelImage4);

	waitKey(0);

#endif

#ifdef FIND_NUM_OF_CHANNELS_IN_IMAGE

	Mat loadImage;
	int numOfChannels;
	
	// load colour image and check number of channels
	loadImage = imread("test.jpg");
	numOfChannels = loadImage.channels();
	cout<<" Number of channels = "<< numOfChannels<< endl;

	// load same image in grayscale and check number of channels
	loadImage = imread("test.jpg",IMREAD_GRAYSCALE);
	numOfChannels = loadImage.channels();
	cout<<" Number of channels = "<< numOfChannels<< endl;

#endif

#ifdef SPLIT_COLOUR_CHANNELS_OF_RGB

	Mat loadImage;
	int numOfChannels;
	
	// load colour image and check number of channels
	loadImage = imread("rgb.jpg");
	numOfChannels = loadImage.channels();
	cout<<" Number of channels = "<< numOfChannels<< endl;

	// split the channels and save them in 3 different Mat variables
	Mat splitChannels[numOfChannels];
	split(loadImage, splitChannels);

	imshow("Blue Channel", splitChannels[0]);
	imshow("Green Channel", splitChannels[1]);
	imshow("Red Channel", splitChannels[2]);
	imshow("Original Channel", loadImage);

	waitKey(0);

#endif

#ifdef CHANGE_COLOR_SPACE_OF_IMAGE

	/* colour space of the image means the combinations of the colour used
	 * by the image. ex. grayscale, RGB, HSV, CYMK, etc.
	 * cvtColor() function from imgproc.hpp module header is used to change color space of an image
	 */

	Mat originalImage, convertedImage[3];
	originalImage = imread("rgb.jpg");
	cvtColor(originalImage, convertedImage[0],COLOR_RGB2BGR);
	cvtColor(originalImage, convertedImage[1],COLOR_RGB2GRAY);
	cvtColor(originalImage, convertedImage[2],COLOR_RGB2YCrCb);

	imshow("Original Image", originalImage);
	imshow("Converted Image RGB to BGR", convertedImage[0]);
	imshow("Converted Image RGB to GRAYSCALE", convertedImage[1]);
	imshow("Converted Image RGB to YCrCb", convertedImage[2]);

	waitKey(0);

#endif

#ifdef MAKE_BINARY_IMAGE

	/* Binary image is black and white image, it is different from grayscale image
	 * In grayscale image, we have single channel where say for 8 bits type,
	 * each pixel can have value between 0 and 255, but Binary image, each pixel has
	 * either 0 or 1.
	 * 0 means pure black color, 1 means pure white color
	 * To make binary image, one needs grayscale image as input
	 * Then required threshold range can be set to decide for 0 and 1 value of pixels
	 */

	Mat originalImage, convertedBinaryImage[3];
	originalImage = imread("test.jpg", IMREAD_GRAYSCALE); // loaded image as grayscale

	//pixels between values 100 and 255 get convert to 0 (pure black)
	// remaining will convert to 1 (pure white)
	threshold(originalImage, convertedBinaryImage[0],100,255,THRESH_BINARY);

	// different thresholds
	threshold(originalImage, convertedBinaryImage[1],175,255,THRESH_BINARY);

	// different thresholds
	threshold(originalImage, convertedBinaryImage[2],125,255,THRESH_BINARY);

	imshow("Binary image 1 - 100 to 255", convertedBinaryImage[0]);
	imshow("Binary image 2 - 175 to 255", convertedBinaryImage[1]);
	imshow("Binary image 3 - 25 to 150", convertedBinaryImage[2]);

	waitKey(0);
	
#endif

#ifdef DISPLAY_PIXEL_VALUES_SINGLE_CHANNEL_IMAGE

	Mat originalImage;
	originalImage = imread("test.jpg", IMREAD_GRAYSCALE); // loaded image as grayscale
	
	// size of the image (rows, cols)
	cout << originalImage.size() <<endl;
	
	// display complete image as pixel matrix
	cout << originalImage <<endl;
	
#endif

#ifdef IMAGE_REGION_OF_INTEREST

	/*
	 * Rect(x1,y1,x2,y2) coordinates of image where (0,0) is top left corner
	 */

	Mat originalImage, newImage[2];
	originalImage = imread("rgb.jpg");
	cout<< "Original Image size = "<< originalImage.size()<< endl;
	
	newImage[0]= originalImage(Rect(100,100,300,300));
	newImage[1]= originalImage(Rect(0,0,100,100));

	imshow("Original Image", originalImage);
	imshow("Region of Interest 1 -  Image", newImage[0]);
	imshow("Region of Interest 2 -  Image", newImage[1]);

	waitKey(0);

#endif

	return 0;
}

