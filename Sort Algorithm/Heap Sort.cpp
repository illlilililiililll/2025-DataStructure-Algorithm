#include <stdio.h>

void heapify(int arr[], int n) {
    int root;

    for (int i = n / 2 - 1; i >= 0; i--) {
        root = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[left] > arr[root]) {
            root = left;
        }

        if (right < n && arr[right] > arr[root]) {
            root = right;
        }

        if (root != i) {
            int _ = arr[i];
            arr[i] = arr[root];
            arr[root] = _;

            heapify(arr, n);
        }
    }
}

void heapSort(int arr[], int n) {
    heapify(arr, n);

    for (int i = n - 1; i > 0; i--) {
        int _ = arr[0];
        arr[0] = arr[i];
        arr[i] = _;

        heapify(arr, i);
    }
}

int main() {
    int arr[] = {5, 15, 7, 20, 1 ,
                 4, 10, 2, 8, 11,
                 9, 6, 13, 18, 3,
                 16, 12, 14, 17, 19};

    heapSort(arr, 20);

    for (int i = 0; i < 20; i++)
        printf("%d ", arr[i]);
}