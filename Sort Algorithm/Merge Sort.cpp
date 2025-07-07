#include <stdio.h>
#include <stdlib.h>

int *sorted;

void merge(int a[], int left, int mid, int right) {
    int i, j, k;
    i = left;
    j = mid+1;
    k = left;

    while (i <= mid && j <= right)
        if (a[i] <= a[j])
            sorted[k++] = a[i++];
        else
            sorted[k++] = a[j++];

    while (i <= mid)
        sorted[k++] = a[i++];
    while (j <= right)
        sorted[k++] = a[j++];

    for (i = left; i <= right; i++)
        a[i] = sorted[i];
}

void sort(int a[], int left, int right) {
    if (left < right) {
        int mid = (right + left) / 2;
        sort(a, left, mid);
        sort(a, mid+1, right);
        merge(a, left, mid, right);
    }
}

void mergeSort(int a[], int n) {
    sorted = (int*)malloc(n * sizeof(int));
    sort(a, 0, n-1);
    free(sorted);
}

int main() {
    int arr[] = {5, 15, 7, 20, 1 ,
                 4, 10, 2, 8, 11,
                 9, 6, 13, 18, 3,
                 16, 12, 14, 17, 19};

    mergeSort(arr, 20);

    for (int i = 0; i < 20; i++)
        printf("%d ", arr[i]);
}