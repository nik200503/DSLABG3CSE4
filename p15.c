#include <stdio.h>
#define MAX_SIZE 100

typedef struct {
    int row;
    int col;
    int value;
} Element;

typedef struct {
    Element data[MAX_SIZE];
    int size;
} SparseMatrix;

void printMatrix(SparseMatrix mat) {
    for (int i = 0; i < mat.size; i++) {
        printf("(%d, %d) = %d\n", mat.data[i].row, mat.data[i].col, mat.data[i].value);
    }
}

SparseMatrix addMatrices(SparseMatrix mat1, SparseMatrix mat2) {
    SparseMatrix result;
    result.size = 0;
    int i = 0, j = 0;

    while (i < mat1.size && j < mat2.size) {
        if (mat1.data[i].row == mat2.data[j].row && mat1.data[i].col == mat2.data[j].col) {
            if (mat1.data[i].value + mat2.data[j].value != 0) {
                result.data[result.size].row = mat1.data[i].row;
                result.data[result.size].col = mat1.data[i].col;
                result.data[result.size].value = mat1.data[i].value + mat2.data[j].value;
                result.size++;
            }
            i++;
            j++;
        } else if (mat1.data[i].row < mat2.data[j].row ||
                   (mat1.data[i].row == mat2.data[j].row && mat1.data[i].col < mat2.data[j].col)) {
            result.data[result.size] = mat1.data[i];
            result.size++;
            i++;
        } else {
            result.data[result.size] = mat2.data[j];
            result.size++;
            j++;
        }
    }

    while (i < mat1.size) {
        result.data[result.size] = mat1.data[i];
        result.size++;
        i++;
    }

    while (j < mat2.size) {
        result.data[result.size] = mat2.data[j];
        result.size++;
        j++;
    }

    return result;
}

int main() {
    SparseMatrix mat1 = {{
        {0, 0, 5},
        {1, 1, 8},
        {2, 2, 3}
    }, 3};

    SparseMatrix mat2 = {{
        {0, 0, 1},
        {1, 1, 2},
        {2, 2, 7}
    }, 3};

    printf("Matrix 1:\n");
    printMatrix(mat1);
    printf("\nMatrix 2:\n");
    printMatrix(mat2);

    SparseMatrix result = addMatrices(mat1, mat2);
    printf("\nResult:\n");
    printMatrix(result);

    return 0;
}