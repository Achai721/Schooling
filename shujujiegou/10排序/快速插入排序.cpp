#include <iostream>
using namespace std;

void quickSort(int arr[], int left, int right) {
    if (left >= right) {
        return;
    }
    int i = left, j = right;
    int pivot = i;
    int pivokey =arr[pivot];
    while (i < j) {
        while (i < j && arr[j] >= pivokey) {
            j--;
        }
        arr[i] = arr[j];
        while (i < j && arr[i] <= pivokey) {
            i++;
        }
        arr[j] = arr[i];
    }
    arr[i] = pivokey;
    cout << "pivot=" << i << " "<<endl;
    for (int k = 0; k <= sizeof(arr); k++) {
        cout << arr[k] << " ";
    }
    cout << endl;
    quickSort(arr, left, i - 1);
    quickSort(arr, i + 1, right);
}

int main() {
    int arr[] = {1, 8, 6, 4, 10, 5, 3, 2, 22};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
//    for (int i = 0; i < n; i++) {
//        cout << arr[i] << " ";
//    }
    return 0;
}

