#include <stdio.h>

int partition(int a[], int start, int end) {
    int left, right;
    int pivot = a[start];

    left = start + 1;
    right = end;

    while (left <= right) {
        while (a[left] < pivot) left++;
        while (a[right] > pivot) right--;

        if (left <= right) {
            int _ = a[left];
            a[left++] = a[right];
            a[right--] = _;
        }
    }

    int _ = a[start];
    a[start] = a[right];
    a[right] = _;

    return right;
}

void sort(int a[], int left, int right) {
    if (left < right) {
        int pivot = partition(a, left, right);

        sort(a, left, pivot-1);
        sort(a, pivot+1, right);
    }
}

void quickSort(int a[], int n) {
    sort(a, 0, n-1);
}

//int main() {
//    int arr[] = {5, 15, 7, 20, 1 ,
//                 4, 10, 2, 8, 11,
//                 9, 6, 13, 18, 3,
//                 16, 12, 14, 17, 19};
//
//    quickSort(arr, 20);
//
//    for (int i = 0; i < 20; i++)
//        printf("%d ", arr[i]);
//}