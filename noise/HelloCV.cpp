#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void noise_gaussian();
void bilateral();
int main()
{    
    //noise_gaussian();
    bilateral();
}

void noise_gaussian()
{
    Mat src = imread("C:/Users/EMBEDDED/Desktop/CV/images/lena.jpg",IMREAD_GRAYSCALE);
    
    imshow("src", src);

    for (int stddev = 0; stddev <= 30; stddev += 10)
    {
        Mat noise(src.size(), CV_32SC1);
        randn(noise, 0, stddev); //평균이 0이고 표준 편차가 stddev인 가우시안 잡음 생성 noise행렬에 저장

        Mat dst;
        add(src, noise, dst, Mat(), CV_8U); //Mat() -> mask
        
        //imshow("noise", noise);
        imshow("dst", dst);
        waitKey();
    }
        
    waitKey();
    destroyAllWindows();

    return ;
}

void bilateral()
{
    Mat src = imread("C:/Users/EMBEDDED/Desktop/CV/images/lena.jpg", IMREAD_GRAYSCALE);
    Mat noise(src.size(), CV_32SC1);
    randn(noise, 0, 5); 

    Mat dst;
    add(src, noise, src, Mat(), CV_8U); //Mat() -> mask
    imshow("src", src);

    Mat dst1;
    GaussianBlur(src, dst1, Size(), 5);
    imshow("dst1", dst1);
    
    Mat dst2;
    bilateralFilter(src, dst2, -1, 10, 30);
    imshow("dst2", dst2);

    waitKey();
    destroyAllWindows();

    return;
}
