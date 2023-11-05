#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>


int greyscale1(cv::Mat& src, cv::Mat& dst); // Task 4

int blur5x5(cv::Mat& src, cv::Mat& dst); // Task 5
int sobelX3x3(cv::Mat &src, cv::Mat3s &dst); //Task 6
int sobelY3x3(cv::Mat &src, cv::Mat3s &dst); //Task 6
int magnitude(cv::Mat &sx, cv::Mat &sy, cv::Mat &dst); //Task 7

int blurQuantize(cv::Mat &src, cv::Mat &dst, int levels); //Task 8
int cartoon(cv::Mat& src, cv::Mat& dst, int levels, int magThreshold); //Task 9

//Some additional functionalities
int negativeImage(cv::Mat& src, cv::Mat& dst); //Task 10
int color_crction_and_threshlding(cv::Mat& src, cv::Mat& dst);
int Popart_Processing(cv::Mat& src, cv::Mat& res);