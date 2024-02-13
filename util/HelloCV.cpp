#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
    Mat src = imread("C:/Users/EMBEDDED/Desktop/CV/images/airplane2.jpg", IMREAD_COLOR);
    Mat dst = imread("C:/Users/EMBEDDED/Desktop/CV/images/red_sky.jpg", IMREAD_COLOR);
    
    //마스크를 저장할 Mat 형식의 변수를 생성
    Mat src_mask(src.rows, src.cols, CV_8UC1);
    Mat dst_mask(dst.rows, dst.cols, CV_8UC1);

    vector<Point> pts;                        //다각형을 구성하는 꼭지점을 저장하기 위한 벡터를 생성
    pts.push_back(Point(0, 40));
    pts.push_back(Point(150, 60));
    pts.push_back(Point(203, 56));
    pts.push_back(Point(200, 100));
    pts.push_back(Point(88, 103));
    pts.push_back(Point(1, 75));

    fillPoly(src_mask, pts, (255, 255, 255)); //pts에 저장된 꼭지점을 이용하여 다각형을 생성

    Point center(600, 150);                   //클론을 삽입할 위치의 중심점
    Mat output;                               //출력 이미지를 저장할 Mat 변수
    seamlessClone(src, dst, src_mask, center, output, NORMAL_CLONE);
    //src_mask사용하여 src 이미지의 일부 영역만을 선택하여 시프트하거나 삽입
    //NORMAL_CLONE: 클론을 시행할 때 사용되는 플래그로, 일반적인 복제 작업을 수행


    TickMeter tm; //이미지를 역방향으로 변환하는 데 걸리는 시간을 측정
    tm.start();

    for (int j = 0; j < dst.rows; j++) {
        for (int i = 0; i < dst.cols; i++) {
            dst_mask.at<uchar>(j, i) = 255 - dst.at<uchar>(j, i);
        }
    }

    tm.stop();
    cout << "Image inverse took " << tm.getTimeMilli() << "ms." << endl;

    imshow("image", src);
    imshow("output", output);
    imshow("dst", dst);

    waitKey(); 
    destroyAllWindows();

    return 0;
} 
