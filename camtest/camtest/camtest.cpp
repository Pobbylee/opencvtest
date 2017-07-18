#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(void)
{
	VideoCapture cap(0);

	if (!cap.isOpened())
		cout << "Cannot open camera !" << endl, exit(0);

	Mat frame;

	while (1)
	{
		cap >> frame;
		imshow("Camera Image", frame);

		if (waitKey(10) == 27) break;
	}

	return 0;
}