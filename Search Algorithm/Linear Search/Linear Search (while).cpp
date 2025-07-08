#include <stdio.h>

int linearSearch(int array[], int n, int key) {
    int i = 0;

    while (i < n) {
        if (array[i] == key)
            return i;
        i++;
    }
    return -1;
}

int main() {
    int a[] = {1, 2, 3, 4, 5, 6, 7};
    printf("%d\n", linearSearch(a, 7, 5));
    printf("%d\n", linearSearch(a, 7, 8));

    return 0;
}