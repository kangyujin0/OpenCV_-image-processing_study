#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void camera_in();
void video_in();
void camera_in_video_out();

int main() {
	//camera_in();
	//video_in();
	camera_in_video_out();
		
	return 0;
}

void camera_in() {
	VideoCapture cap(0, CAP_DSHOW);
	if (cap.isOpened() != true)
	{
		cerr << "Camera open error" << endl;
		return;
	}

	Mat frame, inversed;
	while (true)
	{
		cap >> frame;		// 카메라 장치로부터 한 프레임을 받아와 frmae변수에 저장
		if (frame.empty())      // 해당 프레임 영상이 비어 있으면 루프를 나감
		{
			break;
		}
		inversed = ~frame;
		imshow("frame", frame);
		imshow("inversed", inversed);

		if (waitKey(33) == 27) {
			break;
		}
	}

}

void video_in()
{
	VideoCapture cap("..\\images\\Puppies-HD.mp4");

	if (cap.isOpened() != true)
	{
		cerr << "Video open error" << endl;
		return;
	}

	Mat frame, inversed;
	while (true)
	{
		cap >> frame;		
		if (frame.empty())
		{
			break;
		}
		inversed = ~frame;
		
		imshow("frame", frame);
		imshow("inversed", inversed);

		if (waitKey(33) == 27) {
			break;
		}
	}
	destroyAllWindows();
}

void camera_in_video_out()
{
	VideoCapture cap(0, CAP_DSHOW);

	int w = cvRound(cap.get(CAP_PROP_FRAME_WIDTH));
	int h = cvRound(cap.get(CAP_PROP_FRAME_HEIGHT));
	//double fps = cap.get(CAP_PROP_FPS);
	double fps = cap.set(CAP_PROP_FPS, 30.0);
	fps = cap.get(CAP_PROP_FPS);
	int delay = cvRound(1000 / fps);

	int fourcc = VideoWriter::fourcc('D', 'I', 'V', 'X');
	
	VideoWriter outVideo("output.avi", fourcc, fps, Size(w, h));
	if (outVideo.isOpened() != true) {
		cout << "file open error" << endl;
		return;
	}

	Mat frame, inversed;
	while (true)
	{
		cap >> frame;

		inversed = ~frame;
		outVideo << inversed;

		imshow("frame", frame);
		imshow("inversed", inversed);

		if (waitKey(delay) == 27)
			break;
	}
	destroyAllWindows();
}
