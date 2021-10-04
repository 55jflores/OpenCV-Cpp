#include "opencv2\opencv.hpp"
#include "opencv2\highgui.hpp"
#include <vector>
#include <thread>
using namespace std;
using namespace cv;

void turnFilter(Mat img, Mat canvas) {
	// Splitting img color channels
	vector<Mat> bgr;
	split(img, bgr);

	// Splitting canvas color channels
	vector<Mat>bgr2;
	split(canvas, bgr2);

	// Setting color to canvas
	bgr2[0] = bgr[0];
	bgr2[2] = bgr[2];

	// Merging color channels together
	Mat newpic;
	vector<Mat> channels = { bgr2[0],bgr2[1] ,bgr2[2] };
	merge(channels, newpic);

	// Saving to desktop
	imwrite("Resources/filter.jpg", newpic);
}

void edges(Mat img) {
	// Converting image to grayscale
	cvtColor(img, img, COLOR_BGR2GRAY);

	// Bluring the image to be smoother
	Mat imgBlur;
	GaussianBlur(img, imgBlur, Size(3, 3), 3, 0);

	// Drawing edges
	Mat imgCanny;
	Canny(imgBlur, imgCanny, 25, 75);

	// Saving to desktop
	imwrite("Resources/edges.jpg", imgCanny);

}

int main() {
	// Reading in image
	Mat myImage = imread("Resources/car1.jpg");
	
	// Black canvas of dimension myImage
	Mat canvas = Mat::zeros(Size(myImage.cols,myImage.rows),CV_8UC3);
	
	thread t1(turnFilter, myImage, canvas);
	t1.join();
	thread t2(edges, myImage);
	t2.join();

	cout << "Done" << endl;

	return 0;

}
