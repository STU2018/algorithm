#include <iostream>

using namespace std;

void insertSort(int arr[], int n) {
    int i, j;
    int temp;
    for (i = 1; i < n; i++) {
        temp = arr[i];
        for (j = i - 1; j >= 0; j--) {
            if (arr[j] > temp) {
                arr[j + 1] = arr[j];
            } else {
                break;
            }
        }
        arr[j + 1] = temp;
    }
}

int main() {
    int arr[] = {3, 5, 2, 4, 1};
    int n = 5;
    insertSort(arr, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}