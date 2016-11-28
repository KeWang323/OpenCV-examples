#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>  
#include <iostream>  
using namespace std;
using namespace cv;

void colorReduce(Mat& inputImage, Mat& outputImage, int div);

int main() {
	Mat srcImage = imread("E:\\photos\\2015\\IMG_5577.JPG");
	imshow("原始图像", srcImage);

	Mat dstImage;
	dstImage.create(srcImage.rows, srcImage.cols, srcImage.type());

	double time0 = static_cast<double>(getTickCount());

	colorReduce(srcImage, dstImage, 32);

	time0 = ((double)getTickCount() - time0) / getTickFrequency();
	cout << "此方法的时间为" << time0 << "秒" << endl;

	imshow("效果图", dstImage);
	waitKey(0);
}

void colorReduce(Mat& inputImage, Mat& outputImage, int div) {

	outputImage = inputImage.clone();
	int rowNumber = outputImage.rows;
	int colNumber = outputImage.cols;

	for (int i = 0; i < rowNumber; i++) {
		for (int j = 0; j < colNumber; j++) {
			outputImage.at<Vec3b>(i, j)[0] = outputImage.at<Vec3b>(i, j)[0] / div * div + div / 2;
			outputImage.at<Vec3b>(i, j)[1] = outputImage.at<Vec3b>(i, j)[1] / div * div + div / 2;
			outputImage.at<Vec3b>(i, j)[2] = outputImage.at<Vec3b>(i, j)[2] / div * div + div / 2;
		}
	}
}