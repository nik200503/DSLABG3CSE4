#include <stdio.h>

int main() {
    int arr[] = {1, 3, 5, 7, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key, low = 0, high = n - 1, mid, found = 0;

    printf("Enter the element to search: ");
    scanf("%d", &key);

    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] == key) {
            found = 1;
            break;
        } else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    if (found)
        printf("Element found at index %d\n", mid);
    else
        printf("Element not found\n");

    return 0;
}