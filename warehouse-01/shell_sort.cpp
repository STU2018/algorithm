#include <iostream>

using namespace std;

void shellSort(int arr[], int n) {
    int gap, i, j, temp;
    for (gap = n / 2; gap > 0; gap /= 2) {
        for (i = gap; i < n; i++) {
            for (j = i - gap; j >= 0 && arr[j] > arr[j + gap]; j -= gap) {
                temp = arr[j];
                arr[j] = arr[j + gap];
                arr[j + gap] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {3, 1, 5, 7, 2, 4, 9, 6};
    int n = 8;
    shellSort(arr, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}