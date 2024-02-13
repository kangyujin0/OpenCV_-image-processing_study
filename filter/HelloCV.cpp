#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void filter_embossing();
int main()
{
    filter_embossing();    
}
//이미지에 엠보싱 필터를 적용하여 이미지의 윤곽을 강조
void filter_embossing()
{
    Mat src = imread("C:/Users/EMBEDDED/Desktop/CV/images/flower1.jpg");
    if (src.empty()) {
        cerr << "Image load fail" << endl;
        return ;
    }

    float data[] = {
        -1,-1, 0,
        -1, 0, 1,
         0, 1, 1
    };

    Mat emboss(3, 3, CV_32FC1, data); //3x3 크기의 행렬을 생성하여 엠보싱 필터를 정의
    //엠보싱 필터는 이미지에서 각 픽셀의 주변 픽셀과의 차이를 계산하여 이미지의 윤곽을 강조
    
    Mat dst;

    filter2D(src, dst, -1, emboss);

    imshow("src", src);
    imshow("dst", dst);
    waitKey();
    destroyAllWindows();
}
