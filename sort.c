#include <stdio.h>

// Struct to hold both search result and count of comparisons
typedef struct {
    int index;
    int count;
} SearchResult;

// Binary Search function without pointer
SearchResult binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;
    int count = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        count++;  // comparison: arr[mid] == target
        if (arr[mid] == target)
            return (SearchResult){mid, count};

        count++;  // comparison: arr[mid] < target
        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    // Not found case
    return (SearchResult){-1, count};
}

int main() {
    int size, target;

    printf("Enter the size of the sorted array: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter %d sorted elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the target element to search: ");
    scanf("%d", &target);

    SearchResult result = binarySearch(arr, size, target);

    if (result.index != -1)
        printf("Element %d found at index %d\n", target, result.index);
    else
        printf("Element %d not found in the array\n", target);

    printf("Number of comparisons in binary search: %d\n", result.count);

    return 0;
}

