#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void noise_gaussian();
void bilateral();
void median();
int main()
{    
    //noise_gaussian();
    //bilateral();
    median();
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

void median()
{
    Mat src = imread("C:/Users/EMBEDDED/Desktop/CV/images/lena.jpg", IMREAD_GRAYSCALE);
        
    int num = (int)(src.total() * 0.1); //데이터 전체 크기의 10% 픽셀 값을 0 or 255로 설정
    for (int i = 0; i < num; i++) {
        int x = rand() % src.cols; //rand() 사용하여 0부터 src.cols - 1 
        int y = rand() % src.rows; //또는 src.rows - 1 사이의 임의의 정수를 선택
        src.at<uchar>(y, x) = (i % 2) * 255;
    }

    imshow("src", src);

    Mat dst1;
    GaussianBlur(src, dst1, Size(), 1);
    imshow("gaussian", dst1);

    Mat dst2;
    medianBlur(src, dst2, 3);
    imshow("dst2", dst2);

    waitKey();
    destroyAllWindows();

    return;
}
