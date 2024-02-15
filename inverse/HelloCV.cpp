#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;


int main()
{

    Mat src = imread("C:/Users/EMBEDDED/Desktop/CV/images/butterfly.jpg");

    if (src.empty()) {
        cerr << "Image load failed!" << endl;
        return 0;
    }

    Mat dst(src.rows, src.cols, src.type());

    for (int j = 0; j < src.rows; j++) {
        for (int i = 0; i < src.cols; i++) {
            Vec3b& p1 = src.at<Vec3b>(j, i); // 좌표 픽셀 값을 각각 p1과 p2 변수에 참조로 받아 옵니다
            Vec3b& p2 = dst.at<Vec3b>(j, i);

            p2[0] = 255 - p1[0]; // B, p1 픽셀의 세 개 색상 성분 값을 모두 반전시켜 p2 픽셀 값으로 설정
            p2[1] = 255 - p1[1]; // G
            p2[2] = 255 - p1[2]; // R
        }
    }

    imshow("src", src);
    imshow("dst", dst);
    waitKey();
    destroyAllWindows();

    Vec3b& pixel = src.at<Vec3b>(0, 0);
    uchar b1 = pixel[0];
    uchar g1 = pixel[1];
    uchar r1 = pixel[2];

    Vec3b* ptr = src.ptr<Vec3b>(0);
    uchar b2 = ptr[0][0];           // ptr[0] 첫 번째 요소, ptr[0][0] 첫 번째 요소의 첫 번째 채널 값
    uchar g2 = ptr[0][1];
    uchar r2 = ptr[0][2];

    printf("파란색 성분 값: %d\n", b2);
    printf("초록색 성분 값: %d\n", g2);
    printf("빨간색 성분 값: %d\n", r2);

    return 0;
}
