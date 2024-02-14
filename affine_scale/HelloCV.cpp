#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;


int main()
{

    Mat img = imread("C:/Users/EMBEDDED/Desktop/CV/images/lena.jpg");

    // 크기 변환을 위한 변환 행렬 설정
    double scale = 2.0; // 0.5배 축소
    Mat scale_matrix = Mat::zeros(2, 3, CV_64F);
    scale_matrix.at<double>(0, 0) = scale; // x 방향 크기 변환 비율
    scale_matrix.at<double>(1, 1) = scale; // y 방향 크기 변환 비율

    scale_matrix.at<double>(0, 1) = 0; // x 방향 이동 필요하지 않아 0
    scale_matrix.at<double>(1, 0) = 0; // y 방향 이동 필요하지 않아 0
    scale_matrix.at<double>(0, 2) = 0; //
    scale_matrix.at<double>(1, 2) = 0; //

    Mat M = Mat_<double>({ 2, 3 }, { 2, 0, 0,
                                     0, 2, 0 }); // 방법2

    Mat affine_scale; // 크기 변환 적용
    cv::warpAffine(img, affine_scale, scale_matrix, Size(), INTER_LINEAR, BORDER_CONSTANT, Scalar());

    cv::imshow("src", img);
    cv::imshow("dst", affine_scale);
    cv::waitKey();
    cv::destroyAllWindows();

    return 0;
}
