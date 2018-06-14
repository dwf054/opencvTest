#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

int main(int argc,char **argv)
{
    Mat image,grayImage,edgeImage,thresholdImage;

    image = imread(argv[1]);

    imshow("Original image",image);
    cvtColor(image, grayImage, COLOR_BGR2GRAY);

    edgeImage.create(image.size(),image.type());
    thresholdImage.create(image.size(),image.type());

    blur(grayImage, edgeImage, Size(3, 3));

    Canny(edgeImage, edgeImage, 1, 2);

    imshow("Canny image",edgeImage);

    threshold(image, thresholdImage, 110, 100.0, CV_THRESH_BINARY); 

    imshow("Threshold image",thresholdImage);

    waitKey();

    return 0;
}

