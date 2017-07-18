#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(void)
{
	VideoCapture cap(0);

	if (!cap.isOpened())
		cout << "Cannot open camera !" << endl, exit(0);

	Mat frame, grayImage, edgeImage;
	
	while (1)
	{
		cap >> frame;
		if (frame.empty())
			break;

		cvtColor(frame, grayImage, COLOR_BGR2GRAY);
		Canny(grayImage, edgeImage, 80, 150, 3);

		imshow("Camera Image", frame);
		imshow("Edge Image", edgeImage);

		if (waitKey(10) == 27) break;
	}

	return 0;
}