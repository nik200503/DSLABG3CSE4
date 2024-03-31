#include <stdio.h>
#include <stdlib.h>

void convertPreToPost(int pre[], int n, int post[]) {
    int root = pre[0];
    post[n - 1] = root;

    int leftCount = 0;
    for (int i = 1; i < n; i++) {
        if (pre[i] < root)
            leftCount++;
        else
            break;
    }

    int leftPre[leftCount];
    int leftPost[leftCount];
    int rightPre[n - leftCount - 1];
    int rightPost[n - leftCount - 1];

    for (int i = 0; i < leftCount; i++) {
        leftPre[i] = pre[i + 1];
    }

    for (int i = 0; i < n - leftCount - 1; i++) {
        rightPre[i] = pre[leftCount + 1 + i];
    }

    convertPreToPost(leftPre, leftCount, leftPost);
    convertPreToPost(rightPre, n - leftCount - 1, rightPost);

    int j = 0;
    for (int i = 0; i < leftCount; i++) {
        post[j++] = leftPost[i];
    }

    for (int i = 0; i < n - leftCount - 1; i++) {
        post[j++] = rightPost[i];
    }
}

int main() {
    int pre[] = {1, 2, 4, 8, 9, 5, 3, 6, 7};
    int n = sizeof(pre) / sizeof(pre[0]);
    int post[n];

    convertPreToPost(pre, n, post);

    printf("Postorder Traversal: ");
    for (int i = 0; i < n; i++)
        printf("%d ", post[i]);

    return 0;
}