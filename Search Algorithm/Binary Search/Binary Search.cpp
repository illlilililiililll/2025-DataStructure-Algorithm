#include <stdio.h>

int binarySearch(int array[], int n, int key) {
    int low = 0;
    int high = n-1;
    int center;

    while (low <= high) {
        center = (low + high) / 2;

        if (array[center] == key)
            return center;

        else if (array[center] < key)
            low = center + 1;

        else
            high = center - 1;
    }

    return -1;
}

int main() {
    int a[] = {1, 2, 3, 4, 5, 6, 7};
    printf("%d\n", binarySearch(a, 7, 5));
    printf("%d\n", binarySearch(a, 7, 8));

    return 0;
}