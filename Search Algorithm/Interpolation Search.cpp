#include <stdio.h>

int interpolationSearch(int array[], int n, int key) {
    int low = 0;
    int high = n - 1;

    while (low <= high && key >= array[low] && key <= array[high]) {
        int index = low + (key - array[low]) / (array[high] - array[low]) * (high - low);

        if (key > array[index])
            low = index + 1;
        else if (key < array[index])
            high = index - 1;
        else
            return index;
    }

    return -1;
}

int main() {
    int a[] = {1, 2, 3, 4, 5, 6, 7};
    printf("%d\n", interpolationSearch(a, 7, 5));
    printf("%d\n", interpolationSearch(a, 7, 8));

    return 0;
}