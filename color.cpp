#include "opencv2/core/core.hpp"

#include "opencv2/highgui/highgui.hpp"

#include "opencv2/imgproc/imgproc.hpp"

#include <opencv2/opencv.hpp>
#include <iostream>



using namespace cv;

using namespace std;



int main()

{

	Mat img = imread("A.jpg");

	imshow("A,jpg", img);

	int n = 0;
	int count=0, mode=0;
	int sum_r=0, sum_g = 0, sum_b = 0, mean_r=0, mean_g = 0, mean_b = 0;

	int intensity_r, intensity_g, intensity_b;
	  
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			intensity_b = img.at<Vec3b>(i, j)[0]; // blue channel

			intensity_g = img.at<Vec3b>(i, j)[1]; // green channel

			intensity_r = img.at<Vec3b>(i, j)[2]; // red channel
			n++;
			printf("%d - %d, %d, %d \n", n, intensity_b, intensity_g, intensity_r);

			sum_r = sum_r + intensity_r;
			sum_g = sum_g + intensity_g;
			sum_b = sum_b + intensity_b;
		}
	}

	



	waitKey(0);

	return 0;

}