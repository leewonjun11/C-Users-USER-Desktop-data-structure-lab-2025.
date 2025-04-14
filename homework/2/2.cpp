#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main() {
    Mat image = imread("Lenna.png", IMREAD_GRAYSCALE);
    if (image.empty()) {
        cerr << "�̹����� �ҷ��� �� �����ϴ�." << endl;
        return -1;
    }
    double minVal, maxVal;
    minMaxLoc(image, &minVal, &maxVal);
    cout << "�ִ�ȭ�� ���: " << maxVal << endl;
    return 0;
}
