/*
 * Author      : Shiva Agrawal
 * Date        : 07.09.2018
 * Version     : 1.0
 * Description : This file contains the functions to draw various geomery shapes using OpenCV
 *               1. Draw Line on image
 *				 2. Draw Circle on image
 *				 3. Draw Ellipse on image
 *				 4. Draw Rectangle on image
 *				 5. Write Text on image
 *
 * NOTE: Here image means can be actual image or just white bachground.
 *
 * Steps to use: All the individual functionalities are implemented as preprocessor blocks inside main function. 
 *               Please activate one block at a time and use as reference recipe for image processing techniques.
 *				 One can just activate macro by uncommenting the corrsponding #define line and use it.
 */



#include<opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp> // all drawing functions are defined here
#include <string>
	
using namespace cv;
using namespace std;

// #define DRAW_LINE
// #define DRAW_CIRCLE
// #define DRAW_ELLIPSE
// #define DRAW_RECTANGLE
// #define TEXT_ON_IMAGE

int main()		
{

#ifdef DRAW_LINE

	/*
	 * function -
	 * line(originalImageMatrix, startingPoint, endPoint, line_Color, thickness)
	 */

	//create white background
	Mat whiteMatrix(300,300,CV_8UC1,Scalar(255));

	// create 2 end-points of the line
	Point starting(0,0);
	Point ending(300,300);

	// set line color and thickness
	Scalar lineColor(100);
	int thickness = 2;

	// draw line on white background
	line(whiteMatrix,starting, ending, lineColor,thickness);
	imshow("Line on white background",whiteMatrix);
	
	// draw line on image
	Mat loadImg = imread("test.jpg");
	line(loadImg,starting, Point(400,300), Scalar(0,0,200),10);
	imshow("Line on color image",loadImg);

	waitKey(0);

#endif

#ifdef DRAW_CIRCLE

	/*
	 * function -
	 * circle(originalImageMatrix, centrePoint, radius, line_Color, thickness)
	 */

	//create white background
	Mat whiteMatrix(500,500,CV_8UC1,Scalar(255));

	// create 2 centre points and radius for 2 circles (2 circles are just for example)
	Point centrePoint1(100,100);
	Point centrePoint2(200,300);
	int radius1 = 100;
	int radius2 = 200;

	// set  color and thickness
	Scalar lineColor1(100),lineColor2(200);
	int thickness = 3;

	// draw circles on white background
	circle(whiteMatrix,centrePoint1, radius1, lineColor1,thickness);
	circle(whiteMatrix,centrePoint2, radius2, lineColor2,thickness);
	imshow("Two circles on white background",whiteMatrix);
	
	// draw circles on image
	Mat loadImg = imread("test.jpg");
	circle(loadImg,Point(530,485), radius1, Scalar(0,0,255),5);
	circle(loadImg,centrePoint2, radius2, Scalar(255,0,0),5);
	imshow("Two circles on color image",loadImg);

	waitKey(0);

#endif

#ifdef DRAW_ELLIPSE

	/*
	 * function -
	 * ellipse(originalImageMatrix, centrePoint, xy, angle,...
	 * startingPoint, endPoint, line_Color, thickness)
	 */

	//create white background
	Mat whiteMatrix(500,500,CV_8UC1,Scalar(255));

	//properties of ellipse
	Point centrePoint(250,250); // ellipse centre point
	Size xy(200,100);  // major and minor axis
	int angle = 30;  // angle of rotation
	int startingPoint = 0;
	int endPoint = 360; // to draw full ellipse
	Scalar lineColor(100); //line color
	int thickness = 3;    // line thickness

	// draw on white background
	ellipse(whiteMatrix,centrePoint, xy, angle, startingPoint,endPoint,lineColor,thickness);
	imshow("Ellipse on white background",whiteMatrix);

	// draw ellipse on image
	Mat loadImg = imread("test.jpg");
	ellipse(loadImg,centrePoint, xy, angle, startingPoint,endPoint,Scalar(0,0,200),thickness);
	imshow("Ellipse on color image",loadImg);

	waitKey(0);

#endif

#ifdef DRAW_RECTANGLE

	/*
	 * function -
	 * rectangle(originalImageMatrix, startingPoint, endingPoint, line_Color, thickness)
	 */

	//create white background
	Mat whiteMatrix(400,400,CV_8UC1,Scalar(255));

	// select top left (starting) and bottom right (ending) corner of rectangle
	Point starting(100,100);
	Point ending(300,300);

	// set color and thickness
	Scalar lineColor(100);
	int thickness = 3;

	// draw rectangle on white background
	rectangle(whiteMatrix,starting, ending, lineColor,thickness);
	imshow("rectangle on white background",whiteMatrix);

	// draw rectangle on image
	Mat loadImg = imread("test.jpg");
	rectangle(loadImg,starting, ending, Scalar(0,0,200),thickness);
	imshow("Rectangle on color image",loadImg);

	waitKey(0);

#endif

#ifdef TEXT_ON_IMAGE

	/*
	 * function -
	 * putText(originalImageMatrix, text, textPosition, fontType, fontSize, fontColor, fontWeight )
	 */

	//create white background
	Mat whiteMatrix(400,400,CV_8UC1,Scalar(255));

	// Properties of text
	string text = "opencv is amazing";  // just example text
	Point textPosition(10,50);

	int fontType = FONT_HERSHEY_SIMPLEX; //this are predefined font face names.

	// other are FONT_HERSHEY_PLAIN, FONT_HERSHEY_DUPLEX, FONT_HERSHEY_COMPLEX, FONT_HERSHEY_TRIPLEX,
	// FONT_HERSHEY_COMPLEX_SMALL, FONT_HERSHEY_SCRIPT_SIMPLEX, or FONT_HERSHEY_SCRIPT_COMPLEX

	double fontSize = 1;
	Scalar fontColor(100);
	int fontWeight = 3;

	// write text on white background
	putText(whiteMatrix,text, textPosition, fontType,fontSize, fontColor,fontWeight);
	imshow("Text on white background",whiteMatrix);

	// write text on image
	Mat loadImg = imread("test.jpg");
	putText(loadImg,text, textPosition, fontType,fontSize, Scalar(0,0,255),fontWeight);
	namedWindow("Text on color image",1);
	imshow("Text on color image",loadImg);

	waitKey(0);

#endif

	return 0;
}

