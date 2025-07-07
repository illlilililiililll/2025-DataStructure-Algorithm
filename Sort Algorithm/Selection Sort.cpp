#include <stdio.h>

void selectionSort(int a[], int n) {
    int key, minidx;
    for (int i = 0; i < n-1; i++) {
        key = a[i];
        minidx = i;
        for (int j = i+1; j < n; j++)
            if (a[minidx] > a[j])
                minidx = j;

        if (a[i] == a[minidx]) continue;

        a[i] = a[minidx];
        a[minidx] = key;
    }
}

int main() {
    int arr[] = {5, 15, 7, 20, 1 ,
                 4, 10, 2, 8, 11,
                 9, 6, 13, 18, 3,
                 16, 12, 14, 17, 19};

    selectionSort(arr, 20);

    for (int i = 0; i < 20; i++)
        printf("%d ", arr[i]);
}