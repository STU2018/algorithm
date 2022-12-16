#include <iostream>

using namespace std;

void MergeSort(int arr[], int left, int right) {
    if (left >= right)
        return;
    int mid = (left + right) / 2;
    MergeSort(arr, left, mid);
    MergeSort(arr, mid + 1, right);
    int i = left;
    int j = mid + 1;
    int k = 0;
    int temp[right - left + 1];
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= right)
        temp[k++] = arr[j++];
    for (int i = 0; i < k; i++)
        arr[left + i] = temp[i];
}

int main() {
    int arr[] = {3, 5, 2, 4, 1};
    MergeSort(arr, 0, 4);
    for (int i = 0; i < 5; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}