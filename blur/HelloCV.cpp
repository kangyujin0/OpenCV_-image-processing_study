#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void blurring_mean();
void blurring_gaussian();
void sharpen();
int main()
{    
    //blurring_mean();
    //blurring_gaussian();
    sharpen();
}

void blurring_mean()
{
    Mat img = imread("C:/Users/EMBEDDED/Desktop/CV/images/lena.jpg");
    Mat dst;

    imshow("image", img);
    for (int i = 1; i < 10; i++)
    {
        blur(img, dst, Size(i, i));
        imshow("blur", dst);
        waitKey(500);
    }

    waitKey();
    destroyAllWindows();

    return ;
}

void blurring_gaussian()
{
    Mat img = imread("C:/Users/EMBEDDED/Desktop/CV/images/lena.jpg");
    Mat dst;

    imshow("image", img);
    for (int i = 1; i < 10; i++)
    {
        GaussianBlur(img, dst, Size(0, 0),(double)(i));
        imshow("blur", dst);
        waitKey(500);
    }

    waitKey();
    destroyAllWindows();

    return;
}

void sharpen()
{
    Mat src = imread("C:/Users/EMBEDDED/Desktop/CV/images/lena.jpg");
    Mat dst;
    
    imshow("image", src);
    for (int i = 1; i < 10; i++)
    {
        Mat blurred;
        GaussianBlur(src, blurred, Size(), i);
        
        float alpha = 1.f;
        Mat dst = src + (alpha * src - alpha * blurred);

        imshow("blur", blurred);
        imshow("dst", dst);
        waitKey(500);
    }

    waitKey();
    destroyAllWindows();

    return;
}
  
