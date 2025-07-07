#include <stdio.h>

void insertionSort(int a[], int n) {
    int i, j, key;

    for (i = 1; i < n; i++) {
        key = a[i];
        for (j = i-1; j >= 0 && a[j] > key; j--)
            a[j+1] = a[j];

        a[j+1] = key;
    }
}

int main() {
    int arr[] = {5, 15, 7, 20, 1 ,
                 4, 10, 2, 8, 11,
                 9, 6, 13, 18, 3,
                 16, 12, 14, 17, 19};

    insertionSort(arr, 20);

    for (int i = 0; i < 20; i++)
        printf("%d ", arr[i]);
}