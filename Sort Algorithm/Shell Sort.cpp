#include <stdio.h>

void shellSort(int a[], int n) {
    for (int gap = n/2; gap > 0; gap /= 2) {
        if (!(gap%2)) gap++;

        int temp;
        for (int i = gap; i < n; i += 1) {
            temp = a[i];
            int j;
            for (j = i; j >= gap && a[j-gap] > temp; j -= gap)
                a[i] = a[j - gap];
            a[j] = temp;
        }
    }
}

int main() {
    int arr[] = {5, 15, 7, 20, 1 ,
                 4, 10, 2, 8, 11,
                 9, 6, 13, 18, 3,
                 16, 12, 14, 17, 19};

    shellSort(arr, 20);

    for (int i = 0; i < 20; i++)
        printf("%d ", arr[i]);
}