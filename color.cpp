#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <iostream>


using namespace cv;
using namespace std;


int main()
{

	Mat img = imread("A.jpg");
	Mat result = imread("chip.png");

	imshow("original", img);

	Size size = img.size();

	cout << size.height << endl;
	cout << size.width << endl;
	printf("size = %d * %d = %d \n", size.width, size.height, size.width*size.height);

	int n = 0;
	int count=0, mode=0;
	int sum_r=0, sum_g = 0, sum_b = 0, mean_r=0, mean_g = 0, mean_b = 0;

	int intensity_r, intensity_g, intensity_b;
	

	//rgb 추출
	for (int i = 0; i < size.height; i++) {
		for (int j = 0; j < size.width; j++) {
			intensity_b = img.at<Vec3b>(i, j)[0]; // blue channel

			intensity_g = img.at<Vec3b>(i, j)[1]; // green channel

			intensity_r = img.at<Vec3b>(i, j)[2]; // red channel
			n++;
			printf("%d - %d, %d, %d \n", n, intensity_r, intensity_g, intensity_b);
			printf("size = %d * %d = %d \n", size.width, size.height, size.width * size.height);

			sum_r = sum_r + intensity_r;
			sum_g = sum_g + intensity_g;
			sum_b = sum_b + intensity_b;
		}
	}

	//평균값
	mean_r = sum_r / n;
	mean_g = sum_g / n;
	mean_b = sum_b / n;

	printf("mean(rgb) - %d, %d, %d \n", mean_r, mean_g, mean_b);

	//최빈값
	

	//컬러칩 출력
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {

			result.at<Vec3b>(i, j)[0] = mean_b;
			result.at<Vec3b>(i, j)[1] = mean_g;
			result.at<Vec3b>(i, j)[2] = mean_r;
			
		}
	}

	imshow("result", result);

	waitKey(0);

	return 0;

}