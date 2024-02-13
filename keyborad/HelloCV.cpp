#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
	Mat img = imread("C:/Users/EMBEDDED/Desktop/CV/images/lena.jpg");

	imshow("image", img);
	
	while (true) 
	{
		int keycode = waitKey();

		if (keycode == 'i' || keycode == 'I')
		{
			img = ~img;
			imshow("image", img);
		}
		else if (keycode == 27 || keycode == 'q' || keycode == 'Q')
			break;
	}
	return 0;
}