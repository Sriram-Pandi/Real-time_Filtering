#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
using namespace cv;

int main(int argc, char* argv[])
{
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " IMAGE_PATH\n";
        return 1;
    }

    cv::Mat img = cv::imread(argv[1]);
    if (img.empty()) {
        std::cerr << "Could not read image: " << argv[1] << '\n';
        return 1;
    }
    namedWindow("First_Window", WINDOW_AUTOSIZE);
    cv::imshow("First_Window", img);
    char key = 0;
    while (key != 'q') {
        key = cv::waitKey(0);
    }


    return 0;
}

