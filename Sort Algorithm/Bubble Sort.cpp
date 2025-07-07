#include <stdio.h>

void bubbleSort(int a[], int n) {
    int temp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-(i+1); j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {5, 15, 7, 20, 1 ,
                 4, 10, 2, 8, 11,
                 9, 6, 13, 18, 3,
                 16, 12, 14, 17, 19};

    bubbleSort(arr, 20);

    for (int i = 0; i < 20; i++)
        printf("%d ", arr[i]);
}