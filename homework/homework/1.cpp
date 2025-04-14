#include <iostream>
#include <vector>
using namespace std;

int findMax(const vector<int>& arr) {
    if (arr.empty()) return 0;
    int maxVal = arr[0];
    for (int num : arr) {
        if (num > maxVal) maxVal = num;
    }
    return maxVal;
}

int main() {
    vector<vector<int>> testArrays = {
        {3, 7, 2, 9, 10, 5},
        {-10, -5, -3},
        {100, 200, 300, 50, 400},
        {0, 0, -2, 0},
        {10000}
    };

    for (const auto& arr : testArrays) {
        cout << "�Է� �迭: ";
        for (int num : arr) cout << num << " ";
        cout << "\n�ִ밪: " << findMax(arr) << "\n";
        cout << "--------------------------" << "\n";
    }
    return 0;
}
