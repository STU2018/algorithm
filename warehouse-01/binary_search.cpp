#include <iostream>

using namespace std;

int binarySearch(int arr[], int n, int target) {
    int l = 0, r = n - 1; // 在[l...r]的范围里寻找target
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == target)
            return mid;
        if (target > arr[mid])
            l = mid + 1; // target在[mid+1...r]中;
        else
            r = mid - 1; // target在[l...mid-1]中;
    }
    return -1;
}

int main() {
    int arr[] = {1, 3, 5, 7, 9};
    int n = sizeof(arr) / sizeof(int);
    int target = 5;
    int res = binarySearch(arr, n, target);
    cout << res << endl;
    return 0;
}