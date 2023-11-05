#include <opencv2/opencv.hpp>
#include <cmath>
using namespace cv;

////////////Task-4/////////////////////////////////////////////////////////////////
/* The following code is a function that converts a color image (src) to greyscale (dst). It does this by looping over each row and column of the src image, using a pointer to access each pixel.
For each pixel, the code calculates its greyscale value using a weighted average of its R, G, and B components, where the weighting factors used are 0.6 for the green channel, 0.2 for the red channel,
and 0.2 for the blue channel. The result is stored in the dst image.*/

int greyscale1(cv::Mat& src, cv::Mat& dst) {


	for (int row = 0; row < src.rows; row++) {

		cv::Vec3b* srcrowpointer = src.ptr<cv::Vec3b>(row);
		//uchar *dstrowpointer = dst.ptr<CV_8U>(row);

		for (int col = 0; col < src.cols; col++)
		{
			dst.at<uchar>(row, col) = (0.6 * srcrowpointer[col][1]) + (0.2 * srcrowpointer[col][0]) + (0.2 * srcrowpointer[col][2]);


		}
	}
	return 0;
}
////////////Task-5///////////////////////////////////////////////////////////////////////////////////////////
/*
This code applies a 5x5 blur filter to the image. It does it by applying a 1-dimensional convolution filter in two passes, first in the row direction and then in the column direction.(as separable 1x5 filters)
The input image is stored in a matrix src and the filtered image is stored in a matrix dst. To avoid modifying the original image, an temps matrix temp is used to store temps results
In the first part of the code the pointer points the row of the image and then traverser along the columns and over the whole matrix and in the process each pixel is multiplied with the corresponding filter value
The second part also follows the same pattern except that in second case the filter is 5x1 filter so 5 pointers were declared to each row and the same process was followed again*/

int blur5x5(cv::Mat& src, cv::Mat& dst) {

	cv::Mat temp;
	src.copyTo(temp);
	for (int row = 0; row < src.rows; row++)
	{
		cv::Vec3b *srcrowpointer = src.ptr<cv::Vec3b>(row);
		cv::Vec3b *tempsrowpointer = temp.ptr<cv::Vec3b>(row);
		for (int col = 2; col < src.cols - 2; col++)
		{
			tempsrowpointer[col][0] = (srcrowpointer[col - 2][0] + (2 * srcrowpointer[col - 1][0]) + (4 * srcrowpointer[col][0])+ (2 * srcrowpointer[col + 1][0]) + srcrowpointer[col + 2][0]) / 10;
			tempsrowpointer[col][1] = (srcrowpointer[col - 2][1] + (2 * srcrowpointer[col - 1][1]) + (4 * srcrowpointer[col][1])+ (2 * srcrowpointer[col + 1][1]) + srcrowpointer[col + 2][1]) / 10;
			tempsrowpointer[col][2] = (srcrowpointer[col - 2][2] + (2 * srcrowpointer[col - 1][2]) + (4 * srcrowpointer[col][2])+ (2 * srcrowpointer[col + 1][2]) + srcrowpointer[col + 2][2]) / 10;
		}
	}

	for (int row = 2; row < src.rows - 2; row++)
	{
		cv::Vec3b *rowpointer = temp.ptr<cv::Vec3b>(row);
		cv::Vec3b *rowM2Ptr = temp.ptr<cv::Vec3b>(row - 2);
		cv::Vec3b *rowpointerM1 = temp.ptr<cv::Vec3b>(row - 1);
		cv::Vec3b *rowpointerP1 = temp.ptr<cv::Vec3b>(row + 1);
		cv::Vec3b *rowP2Ptr = temp.ptr<cv::Vec3b>(row + 2);
		cv::Vec3b *dstrowpointer = dst.ptr<cv::Vec3b>(row);
		for (int col = 0; col < src.cols; col++)
		{
			dstrowpointer[col][0] = (rowM2Ptr[col][0] + (2 * rowpointerM1[col][0]) + (4 * rowpointer[col][0]) + (2 * rowpointerP1[col][0]) + rowP2Ptr[col][0]) / 10;
			dstrowpointer[col][1] = (rowM2Ptr[col][1] + (2 * rowpointerM1[col][1]) + (4 * rowpointer[col][1]) + (2 * rowpointerP1[col][1]) + rowP2Ptr[col][1]) / 10;
			dstrowpointer[col][2] = (rowM2Ptr[col][2] + (2 * rowpointerM1[col][2]) + (4 * rowpointer[col][2]) + (2 * rowpointerP1[col][2]) + rowP2Ptr[col][2]) / 10;
		}
	}
	return 0;
}
/////////Task-6 Part-1////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*In the first part of code the image is convoluted by a [-1 0 1] filter and in the second part of code the image obtained in the previous step was convoluted by a vertical 1x3 matrix 1 2 1.the output was stored
in a dst variable*/

int sobelX3x3(cv::Mat &src, cv::Mat3s &dst) {

	cv::Mat3s temps;
	src.copyTo(temps);
	for (int row = 0; row < src.rows; row++)
	{
		cv::Vec3b *srcpointer = src.ptr<cv::Vec3b>(row);
		cv::Vec3s *temppointer = temps.ptr<cv::Vec3s>(row);
		for (int col = 0; col < src.cols; col++)
		{
			if (col == 0 or col == src.cols - 1)
			{
				temppointer[col][0] = srcpointer[col][0];
				temppointer[col][1] = srcpointer[col][1];
				temppointer[col][2] = srcpointer[col][2];
			}
			else {
			temppointer[col][0] =  (srcpointer[col + 1][0] - srcpointer[col - 1][0]) ;
			temppointer[col][1] = (srcpointer[col + 1][1] - srcpointer[col - 1][1]) ;
			temppointer[col][2] = (srcpointer[col + 1][2] - srcpointer[col - 1][2]) ;
			}
		}
	}

	for (int row = 1; row < src.rows - 1; row++)
	{
		cv::Vec3s* rowpointerM1 = temps.ptr<cv::Vec3s>(row - 1);
		cv::Vec3s* rowpointer = temps.ptr<cv::Vec3s>(row);
		cv::Vec3s* rowpointerP1 = temps.ptr<cv::Vec3s>(row + 1);
		cv::Vec3s* dstpointer = dst.ptr<cv::Vec3s>(row);
		for (int col = 0; col < src.cols; col++)
		{
			dstpointer[col][0] = (rowpointerM1[col][0] + (2 * rowpointer[col][0] ) + rowpointerP1[col][0]) / 4;
			dstpointer[col][1] = (rowpointerM1[col][1] + (2 * rowpointer[col][1] ) + rowpointerP1[col][1]) / 4;
			dstpointer[col][2] = (rowpointerM1[col][2] + (2 * rowpointer[col][2] ) + rowpointerP1[col][2]) / 4;
		}
	}

	return 0;
}
/////////////Task-6 Part-2/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*In the first part of code the image is convoluted by a [1 2 1] filter and in the second part of code the image obtained in the previous step was convoluted by a vertical 1x3 matrix -1 0 1.the output was stored
in a dst variable*/


int sobelY3x3(cv::Mat &src, cv::Mat3s &dst) {

	cv::Mat3s temps;
	src.copyTo(temps);
	for (int row = 0; row < src.rows; row++)
	{
		cv::Vec3b* srcpointer = src.ptr<cv::Vec3b>(row);
		cv::Vec3s* dstpointer = temps.ptr<cv::Vec3s>(row);
		for (int col = 0; col < src.cols; col++)
		{
			if (col == 0 or col == src.cols - 1)
			{
				dstpointer[col][0] = srcpointer[col][0];
				dstpointer[col][1] = srcpointer[col][1];
				dstpointer[col][2] = srcpointer[col][2];
			}
			else {
				dstpointer[col][0] = (srcpointer[col - 1][0] + (2 * srcpointer[col][0]) + srcpointer[col + 1][0]) / 4;
				dstpointer[col][1] = (srcpointer[col - 1][1] + (2 * srcpointer[col][1]) + srcpointer[col + 1][1]) / 4;
				dstpointer[col][2] = (srcpointer[col - 1][2] + (2 * srcpointer[col][2]) + srcpointer[col + 1][2]) / 4;
			}
		}
	}

	for (int row = 1; row < src.rows - 1; row++)
	{
		cv::Vec3s* rowpointerM1 = temps.ptr<cv::Vec3s>(row - 1);
		cv::Vec3s* rowpointerP1 = temps.ptr<cv::Vec3s>(row + 1);
		cv::Vec3s* dstpointer = dst.ptr<cv::Vec3s>(row);
		for (int col = 0; col < src.cols; col++)
		{
			dstpointer[col][0] = (rowpointerP1[col][0] - rowpointerM1[col][0]);
			dstpointer[col][1] = (rowpointerP1[col][1] - rowpointerM1[col][1]);
			dstpointer[col][2] = (rowpointerP1[col][2] - rowpointerM1[col][2]);
		}
	}

	return 0;
}
/////////Task-7//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int magnitude(cv::Mat& sx, cv::Mat& sy, cv::Mat& dst) {

	cv::Mat resx;
	cv::convertScaleAbs(sx,resx);

	cv::Mat resy;
	cv::convertScaleAbs(sy,resy);

	cv::Mat temps = cv::Mat(sx.size(), CV_8UC3);
	
	for (int row = 0; row < sx.rows; row++)
	{
		cv::Vec3b* sxrowpointer = resx.ptr<cv::Vec3b>(row);
		cv::Vec3b* syrowpointer = resy.ptr<cv::Vec3b>(row);
		cv::Vec3b* dstrowpointer = temps.ptr<cv::Vec3b>(row);
		for (int col = 0; col < sx.cols; col++) {
			for (int color = 0; color < 3; color++) {
				dstrowpointer[col][color] = sqrt((sxrowpointer[col][color] * sxrowpointer[col][color]) + (syrowpointer[col][color] * syrowpointer[col][color]));
			}
		}
	}

	cv::convertScaleAbs(temps, dst);
	return 0;
}

/////////Task-8/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int blurQuantize(cv::Mat &src, cv::Mat &dst, int levels) {
	
	cv::Mat blurred_image = cv::Mat(src.size(), src.type());
	cv::Mat temps;
	
	int status = blur5x5(src, blurred_image);
	if (status != 0)
	{
		exit(status);
	}
	
	int bucket_size = ceil(255.0 / levels);
	for (int row = 0; row < src.rows; row++)
	{
		cv::Vec3b* srcrowpointer = blurred_image.ptr<cv::Vec3b>(row);
		cv::Vec3b* dstrowpointer = dst.ptr<cv::Vec3b>(row);
		for (int col = 0; col < src.cols; col++)
		{
			dstrowpointer[col][0] = (floor(srcrowpointer[col][0] / bucket_size)) * bucket_size;
			dstrowpointer[col][1] = (floor(srcrowpointer[col][1] / bucket_size)) * bucket_size;
			dstrowpointer[col][2] = (floor(srcrowpointer[col][2] / bucket_size)) * bucket_size;
		}
	}
	cv::convertScaleAbs(dst, temps);
	return 0;
}

///////Task-9/////////////////////////////////////////////////////////////////////////////////////////////

int cartoon(cv::Mat& src, cv::Mat& dst, int levels, int magThreshold) {
	
	cv::Mat3s tempvar_sx, tempvar_sy;
	cv::Mat result, sx, sy;

	tempvar_sx = src.clone();
	tempvar_sy = src.clone();

	sobelX3x3(src, tempvar_sx);
	convertScaleAbs(tempvar_sx, sx);

	sobelY3x3(src, tempvar_sy);
	convertScaleAbs(tempvar_sy, sy);

	magnitude(sx, sy, result);
	blurQuantize(src, dst, levels);

	src.copyTo(result);
	for (int y = 0; y < src.rows; y++) {
		cv::Vec3b* strrowpointer = result.ptr<cv::Vec3b>(y);
		cv::Vec3b* dstrowpointer = dst.ptr<cv::Vec3b>(y);
		for (int x = 0; x < src.cols; x++) {
			if (strrowpointer[x][0] > magThreshold or strrowpointer[x][1] > magThreshold or strrowpointer[x][2] > magThreshold) {
				dstrowpointer[x][0] = 0;
				dstrowpointer[x][1] = 0;
				dstrowpointer[x][2] = 0;
			}
		}
	}


	cv::convertScaleAbs(dst, dst);
	cv::imshow("cart",dst);
	return 0;

}   

//////Task-10 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int negativeImage(cv::Mat& src, cv::Mat& dst) {
	/*This function provides the negative version of the image. */
	for (int row = 0; row < src.rows; row++)
	{
		cv::Vec3b* srcrowpointer = src.ptr<cv::Vec3b>(row);
		cv::Vec3b* dstrowpointer = dst.ptr<cv::Vec3b>(row);
		for (int col = 0; col < src.cols; col++)
		{
			dstrowpointer[col][0] = 255 - srcrowpointer[col][0];
			dstrowpointer[col][1] = 255 - srcrowpointer[col][1];
			dstrowpointer[col][2] = 255 - srcrowpointer[col][2];
		}
	}
	return 0;
}

///Extension-1//////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
The method receives two input images (src and dst) and applies thresholding and color correction to the input image src. A gamma correction with a gamma value of 1.2 was used as the adjustment.The image is changed from BGR to YCrCb color space, and the Y channel is corrected. 

The image is then changed back to grayscale and BGR after being rectified. The grayscale picture is then given a binary threshold, transferred to the output image dst, and finally inverted.I was just trying to use multiple

inbuilt fucntoions and get an new filter.
*/
int color_crction_and_threshlding(cv::Mat& src, cv::Mat& dst) {

	float gamma = 1.2;
	cv::Mat image = src;
	cv::Mat ycrcb;

	cv::cvtColor(image, ycrcb, cv::COLOR_BGR2YCrCb);
	std::vector<cv::Mat> channels;
	cv::split(ycrcb, channels);

	cv::Mat correction = channels[0].clone();
	correction = correction / 255.0;
	correction = correction.mul(correction);
	correction = correction * 255.0;
	channels[0] = correction;

	cv::merge(channels, ycrcb);

	cv::Mat corrected;
	cv::cvtColor(ycrcb, corrected, cv::COLOR_YCrCb2BGR);

	cv::Mat dst1,dst2;
	cvtColor(corrected, dst, COLOR_BGR2GRAY);
	threshold(dst, dst1, 100, 255, THRESH_BINARY);
	bitwise_not(dst1, dst2);

	dst2.copyTo(dst);
	return 0;

}

/////////Extension-2//////////////////////////////////////////////////////////
/*This program's function applies the pop art effect to an image. Src and res are the two input parameters required. The function will return the processed image as res, and the original image as src.

The function first changes the input image's src color space from BGR to HSV. The cvtColor function is used to do this. The function then manipulates the HSV values for each pixel in the image by looping

through all of the pixels in the image. To do this, distinct transformations are first applied to each range of hue values after which they are divided into ranges. For instance, the function multiplies 

the hue and saturation values by two and adds 50 to the value if the hue value is between 0 and 30.The function then applies cvtColor to convert the image back to BGR color space before returning the edited image.

This was implemented taking reference from the following website link: https://www.analytics-link.com/post/2019/07/11/creating-pop-art-using-opencv-and-python but the output turned out to be very different*/

int Popart_Processing(cv::Mat& src, cv::Mat& res)
{
	cv::Mat img = src;

	cvtColor(img, res, COLOR_BGR2HSV);

	for (int i = 0; i < res.rows; i++) {
		for (int j = 0; j < res.cols; j++) {
			Vec3b &p = res.at<Vec3b>(i, j);
			int h = p[0];
			int s = p[1];
			int v = p[2];

			if (h >= 0 && h < 30) {
				p[0] = h * 2;
				p[1] = s * 2;
				p[2] = v + 50;
			}
			else if (h >= 30 && h < 60) {
				p[0] = h * 2;
				p[1] = s * 2;
				p[2] = v + 100;
			}
			else if (h >= 60 && h < 90) {
				p[0] = h * 2;
				p[1] = s * 2;
				p[2] = v + 150;
			}
			else if (h >= 90 && h < 120) {
				p[0] = h * 2;
				p[1] = s * 2;
				p[2] = v + 200;
			}
			else if (h >= 120 && h < 150) {
				p[0] = h * 2;
				p[1] = s * 2;
				p[2] = v + 250;
			}
			else if (h >= 150 && h < 180) {
				p[0] = h * 2;
				p[1] = s * 2;
				p[2] = v + 300;
			}
		}
	}

	cvtColor(res, res, COLOR_HSV2BGR);
	return 0;
}

