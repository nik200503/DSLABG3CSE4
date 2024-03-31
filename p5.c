#include <stdio.h>

int main() {
   int arr[100];
   int n, choice, pos, i;

   printf("Enter the number of elements: ");
   scanf("%d", &n);

   printf("Enter the elements:\n");
   for (i = 0; i < n; i++) {
       printf("\nenter the %d element",i+1);
       scanf("%d", &arr[i]);
   }

   do {
       printf("\nMenu:\n");
       printf("1. Delete from beginning\n");
       printf("2. Delete from end\n");
       printf("3. Exit\n");
       printf("Enter your choice: ");
       scanf("%d", &choice);

       switch (choice) {
           case 1:
               if (n == 0) {
                   printf("Underflow condition: Array is empty.\n");
               } else {
                   for (i = 0; i < n - 1; i++) {
                       arr[i] = arr[i + 1];
                   }
                   n--;
                   printf("Element deleted from the beginning.\n");
               }
               break;

           case 2:
               if (n == 0) {
                   printf("Underflow condition: Array is empty.\n");
               } else {
                   n--;
                   printf("Element deleted from the end.\n");
               }
               break;

           case 3:
               printf("Exiting...\n");
               break;

           default:
               printf("Invalid choice. Please try again.\n");
               break;
       }

       if (n >= 100) {
           printf("Overflow condition: Array is full.\n");
       }
   } while (choice != 3);

   return 0;
}