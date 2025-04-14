#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main() {
    Mat image = imread("Lenna.png", IMREAD_GRAYSCALE);
    if (image.empty()) {
        cerr << "이미지를 불러올 수 없습니다." << endl;
        return -1;
    }
    double minVal, maxVal;
    minMaxLoc(image, &minVal, &maxVal);
    cout << "최대화소 밝기: " << maxVal << endl;
    return 0;
}
