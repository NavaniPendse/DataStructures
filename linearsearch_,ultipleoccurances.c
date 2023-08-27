#include <stdio.h>

void linear_search_multiple_occurrences(int arr[], int size, int target) {
    printf("Occurrences of %d: ", target);

    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            printf("%d ", i);
        }
    }

    printf("\n");
}

int main() {
    int arr[] = {4, 2, 8, 2, 7, 2, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 2;

    linear_search_multiple_occurrences(arr, size, target);

    return 0;
}
