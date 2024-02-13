#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

Mat img;
Point ptOld;    //이전 마우스 이벤트 발생 위치를 저장 용도
void on_mouse(int event, int x, int y, int flags, void*);

int main()
{
    
    img = imread("C:/Users/EMBEDDED/Desktop/CV/images/lena.jpg");
    namedWindow("img");// setMouseCallback함수 사용 전 이벤트를 받을 창이 미리 생성되어 있어야 함
    setMouseCallback("img", on_mouse);

    imshow("img", img);
    waitKey();
    destroyAllWindows();

    return 0;
}

void on_mouse(int event, int x, int y, int flags, void*)
{
    switch (event) 
    {
    case EVENT_LBUTTONDOWN:
        ptOld = Point(x, y);
        cout << "Left_down" << x << "," << y << endl;
        break;
    case EVENT_LBUTTONUP:
        ptOld = Point(x, y);
        cout << "Left_up" << x << "," << y << endl;
        break;
    case EVENT_MOUSEMOVE:
        if (flags & EVENT_FLAG_LBUTTON) {
            line(img, ptOld, Point(x, y), Scalar(0, 255, 255), 2);
            imshow("img", img);
            ptOld = Point(x, y);
        }
        break;
    default:
        break;
    }  
}
