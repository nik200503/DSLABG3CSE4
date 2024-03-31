#include <stdio.h>

int main(){
    int arr[] = {5, 2, 8, 1, 9, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key, i, found = 0;

    printf("Enter the element to search: ");
    scanf("%d", &key);

    for (i = 0; i < n; i++) {
        if (arr[i] == key) {
            found = 1;
            break;
        }
    }

    if (found)
        printf("Element found at index %d\n", i);
    else
        printf("Element not found\n");

    return 0;
}