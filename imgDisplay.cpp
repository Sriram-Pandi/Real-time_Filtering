#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
using namespace cv;

int main()
{
    cv::Mat img = cv::imread("C:/Users/18573/Downloads/lenapic.jpg");
    namedWindow("First_Window", WINDOW_AUTOSIZE);
    cv::imshow("First_Window", img);
    char key = 0;
    while (key != 'q') {
        key = cv::waitKey(0);
    }


    return 0;
}

