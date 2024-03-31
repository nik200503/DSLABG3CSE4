#include <stdio.h>
#include <stdlib.h>

void convertPostToPre(int post[], int n, int pre[]) {
    if (n <= 0) // Base case for empty tree
        return;

    int root = post[n - 1];
    pre[0] = root;

    int leftCount = 0;
    for (int i = 0; i < n - 1; i++) {
        if (post[i] < root)
            leftCount++;
        else
            break;
    }

    int *leftPost = malloc(leftCount * sizeof(int));
    int *leftPre = malloc(leftCount * sizeof(int));
    int *rightPost = malloc((n - leftCount - 1) * sizeof(int));
    int *rightPre = malloc((n - leftCount - 1) * sizeof(int));

    // Check if memory allocation failed
    if (!leftPost || !leftPre || !rightPost || !rightPre) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < leftCount; i++) {
        leftPost[i] = post[i];
    }

    for (int i = 0; i < n - leftCount - 1; i++) {
        rightPost[i] = post[leftCount + i];
    }

    convertPostToPre(leftPost, leftCount, leftPre);
    convertPostToPre(rightPost, n - leftCount - 1, rightPre);

    int j = 1;
    for (int i = 0; i < leftCount; i++) {
        pre[j++] = leftPre[i];
    }

    for (int i = 0; i < n - leftCount - 1; i++) {
        pre[j++] = rightPre[i];
    }

    free(leftPost);
    free(leftPre);
    free(rightPost);
    free(rightPre);
}

int main() {
    int post[] = {8, 9, 4, 5, 2, 6, 7, 3, 1};
    int n = sizeof(post) / sizeof(post[0]);
    int *pre = malloc(n * sizeof(int));

    if (!pre) {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }

    convertPostToPre(post, n, pre);

    printf("Preorder Traversal: ");
    for (int i = 0; i < n; i++)
        printf("%d ", pre[i]);

    free(pre);

    return 0;
}
