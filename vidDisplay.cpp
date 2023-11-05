#include "filter.h"

using namespace cv;
///////The following piece of code snippet till calling the break function after key==q was taken from the assignement//////////////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[]) {
    cv::VideoCapture* capdev;
    bool display_gray = false;
    bool altgrey = false;

    // open the video device
    capdev = new cv::VideoCapture(0);
    if (!capdev->isOpened()) {
        printf("Unable to open video device\n");
        return(-1);
    }

    // get some properties of the imagew
    cv::Size refS((int)capdev->get(cv::CAP_PROP_FRAME_WIDTH),
        (int)capdev->get(cv::CAP_PROP_FRAME_HEIGHT));
    printf("Expected size: %d %d\n", refS.width, refS.height);

    cv::namedWindow("Video_o", 1); // identifies a window
    cv::Mat frame;
   
    char var;
    cv::Mat sx;
    cv::Mat sy;

    for (;;) {
        // pressa  a key cc becomes g or i or 

        *capdev >> frame; // get a new frame from the camera, treat as a stream
        
        if (frame.empty()) {
            printf("frame is empty\n");
            break;
        }
////////////Task-3///////////////////////////////////////////////////////////////////////////////////////////////
/*In this task we are taking the frameand converting it into grey scale using the in - built opencv function cv::cvtColor(frame, gray_frame, cv::COLOR_BGR2GRAY);*/

        if (display_gray) {
            cv::Mat gray_frame;
            cv::cvtColor(frame, gray_frame, cv::COLOR_BGR2GRAY);
            cv::imshow("Normal Grey", gray_frame);
        }
/////////////Task-2///////////////////////////////////////////////////////////////////////////////////////////////
/*This task displays the live-video*/ 
        else {
            cv::imshow("Video_o", frame);

        }
/*In the following steps we shall be creating a switch case structure to check which specific key is pressed and if a particlar key is pressed then the char variable "var" 
will be changed to that key and in the next piece of code conditional statements are written to execute respective functions defined in the filters.cpp*/
        char key = cv::waitKey(10);
        
        switch (key)
        {
        case 'g':
        {var = 'g'; }
        break;
        case 'h':
        {var = 'h'; }
        break;
        case 'b':
        {var = 'b'; }
        break;
        case 'x':
        {var = 'x'; }
        break;
        case 'y':
        {var = 'y'; }
        break;
        case 'm':
        {var = 'm'; }
        break;
        case 'l':
        {var = 'l'; }
        break;
        case 'c':
        {var = 'c'; }
        break;
        case 'n':
        {var = 'n'; }
        break;
        case 'e':
        {var = 'e'; }
        break;
        case 'w':
        {var = 'w'; }
        break;

        }
        
        
        if (key == 'q') {
            break;
        }
        else if (key == 's') {
            cv::imwrite("captured_image.jpg", frame);
            printf("Image saved to file\n");
        }
        else if (var == 'g') {
            display_gray = !display_gray;

        }
        else if (var == 'h') {

            cv::Mat gray;
            gray = Mat::zeros(frame.rows, frame.cols, CV_8UC1);
            greyscale1(frame, gray);
            cv::imshow("Alternate grey ", gray);
        }
        else if (var == 'b') {
            cv::Mat blurred;
            blurred = Mat::zeros(frame.rows, frame.cols, CV_8UC3);
            //greyscale1(frame, blurred);
            blur5x5(frame, blurred);
            cv::imshow("Blurred", blurred);
        }
        else if (var == 'x') {
            cv::Mat3s xsobel;
            cv::Mat res;
            //xsobel = Mat::zeros(frame.rows, frame.cols, CV_16S);
            res = frame.clone();
            xsobel = frame.clone();
            sobelX3x3(frame, xsobel);
            cv::convertScaleAbs(xsobel, res);
            cv::imshow("X Sobel", res);
        }
        else if (var == 'y') {
            cv::Mat3s ysobel;
            cv::Mat res;
            //xsobel = Mat::zeros(frame.rows, frame.cols, CV_16S);
            res = frame.clone();
            ysobel = frame.clone();
            sobelY3x3(frame, ysobel);
            cv::convertScaleAbs(ysobel, res);
            cv::imshow("y Sobel", res);
        }
        else if (var == 'm') {

            cv::Mat3s ysobel;
            cv::Mat resy;
            ysobel = Mat::zeros(frame.rows, frame.cols, CV_8UC3);
            sobelY3x3(frame, ysobel);
            //cv::convertScaleAbs(ysobel, resy);q

            cv::Mat3s xsobel;
            cv::Mat resx;
            xsobel = Mat::zeros(frame.rows, frame.cols, CV_8UC3);
            sobelX3x3(frame, xsobel);
            //cv::convertScaleAbs(xsobel, resx);

            cv::Mat mag;
            mag = Mat::zeros(frame.rows, frame.cols, CV_8UC3);
            int err = magnitude(xsobel, ysobel, mag);

            if (err) {
                printf("Error calculating magnitude\n");
            }
            else {

                cv::imshow("Magnitude", mag);
            }
        }
        else if (var == 'l') {
            cv::Mat blquant;
            blquant = Mat::zeros(frame.rows, frame.cols, CV_8UC3);
            blurQuantize(frame, blquant, 15);
            cv::imshow("blur-Quantize", blquant);
        }
        else if (var == 'c') {

            cv::Mat crt; 
            crt = Mat::zeros(frame.rows, frame.cols, CV_8UC3);
            cartoon(frame, crt, 15, 18);
            cv::imshow("cartoon", crt);
        }
        else if (var == 'n') {

            cv::Mat neg;
            neg = Mat::zeros(frame.rows, frame.cols, CV_8UC3);
            negativeImage(frame, neg);
            cv::imshow("Negative", neg);
        }
        else if (var == 'e')
        {
            cv::Mat ext;
            ext = Mat::zeros(frame.rows, frame.cols, CV_8UC3);
            color_crction_and_threshlding(frame, ext);
            cv::imshow("Negative", ext);
        }
        else if (var == 'w')
        {
            cv::Mat pop;
            pop = Mat::zeros(frame.rows, frame.cols, CV_8UC3);
            Popart_Processing(frame,pop);
            cv::imshow("pop_art", pop);
        }

    }
    
    delete capdev;
    return(0);
}
