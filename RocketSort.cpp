#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

void printArray(const int arr[], int size) {
    std::cout << "[";
    for (int i = 0; i < size; ++i) {
        cout << arr[i];
        if (i < size - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}


bool below(int x, int n, int sum) {
    return x * n < sum;
}

void RocketSort(int nums[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += nums[i];
    }

    int split = 0;
    for (int i = 0; i < n; i++) {
        if (below(nums[i], n, sum)) {
            split++;
        }
    }
    
    int left = split - 1;
    int right = split;

    while (left >= 0 || right < n) {
        if (left >= 0) {
            int best = -1;
            for (int i = 0; i < n; i++) {
                if (i > left && i < right) {
                    continue;
                }
                if (!below(nums[i], n, sum)) {
                    continue;
                }
                if (best == -1 || nums[i] > nums[best]){ 
                    best = i;
                }
            }
            swap(nums[left], nums[best]);
            left--;
        }
        if (right < n) {
            int best = -1;
            for (int i = 0; i < n; i++) {
                if (i > left && i < right) {
                    continue;
                }
                if (below(nums[i], n, sum)) {
                    continue;
                }
                if (best == -1 || nums[i] < nums[best]) {
                    best = i;
                }
            }
            swap(nums[right], nums[best]);
            right++;
        }
    }
}

int main() {
    int nums[50] = {
    73, 19, 88, 42, 5, 91, 64, 27, 14, 99,
    38, 53, 81, 11, 67, 29, 95, 48, 3, 76,
    60, 22, 84, 35, 17, 92, 50, 8, 71, 44,
    13, 89, 31, 66, 2, 97, 55, 24, 79, 41,
    16, 85, 39, 62, 7, 94, 46, 20, 74, 33};
    RocketSort(nums, 50);
    printArray(nums, 50);
}

