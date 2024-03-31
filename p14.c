#include <stdio.h>
#include <limits.h>

int findPivot(int arr[], int low, int high) {
    if (high < low)
        return -1;
    if (high == low)
        return low;

    int mid = (low + high) / 2;
    if (mid < high && arr[mid] > arr[mid + 1])
        return mid;
    if (mid > low && arr[mid] < arr[mid - 1])
        return mid - 1;
    if (arr[low] >= arr[mid])
        return findPivot(arr, low, mid - 1);
    return findPivot(arr, mid + 1, high);
}

int findMin(int arr[], int n) {
    int pivot = findPivot(arr, 0, n - 1);
    return (pivot == -1) ? arr[0] : arr[pivot + 1];
}

int findFloor(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    if (x < arr[0])
        return arr[0];
    if (x > arr[n - 1])
        return arr[n - 1];

    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == x)
            return arr[mid];
        else if (arr[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return arr[high];
}

int findCeil(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    if (x < arr[0])
        return arr[0];
    if (x > arr[n - 1])
        return INT_MAX;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == x)
            return arr[mid];
        else if (arr[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return arr[low];
}

int findPeak(int arr[], int n) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if ((mid == 0 || arr[mid] >= arr[mid - 1]) &&
            (mid == n - 1 || arr[mid] >= arr[mid + 1]))
            return mid;
        else if (mid > 0 && arr[mid] < arr[mid - 1])
            high = mid - 1;
        else
            low = mid + 1;
    }

    return -1;
}

int main() {
    int arr[] = {5, 6, 1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 3;

    printf("Sorted rotated array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    printf("Minimum element: %d\n", findMin(arr, n));
    printf("Floor of %d: %d\n", x, findFloor(arr, n, x));
    printf("Ceil of %d: %d\n", x, findCeil(arr, n, x));
    printf("Peak element index: %d\n", findPeak(arr, n));

    return 0;
}