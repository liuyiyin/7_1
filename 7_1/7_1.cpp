// 7_1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <opencv.hpp>
using namespace cv;

int main()
{
	cv::Mat src = cv::imread("D:\\lena.jpg", 1);
	cv::Mat dst;
	float angle = -10.0, scale = 1;

	cv::Point2f center(src.cols / 2.0, src.rows / 2.0);
	cv::Mat rot = cv::getRotationMatrix2D(center, angle, scale);

	cv::Rect bbox = cv::RotatedRect(center, src.size(), angle).boundingRect();

	rot.at<double>(0, 2) += bbox.width / 2.0 - center.x;
	rot.at<double>(1, 2) += bbox.height / 2.0 - center.y;

	cv::warpAffine(src, dst, rot, bbox.size());

	cv::imshow("dst", dst);
	waitKey(0);
    return 0;
}

