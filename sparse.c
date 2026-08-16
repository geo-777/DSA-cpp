#include <stdio.h>

#define MAX 100

struct Element {
    int row;
    int col;
    int value;
};

void transpose(struct Element A[], struct Element B[]) {

    int rows = A[0].row;
    int cols = A[0].col;
    int nonZero = A[0].value;

    B[0].row = cols;
    B[0].col = rows;
    B[0].value = nonZero;

    int k = 1;

    for (int col = 0; col < cols; col++) {

        for (int i = 1; i <= nonZero; i++) {

            if (A[i].col == col) {

                B[k].row = A[i].col;
                B[k].col = A[i].row;
                B[k].value = A[i].value;

                k++;
            }
        }
    }
}

void display(struct Element A[]) {

    int nonZero = A[0].value;

    printf("Row\tCol\tValue\n");

    for (int i = 0; i <= nonZero; i++) {
        printf("%d\t%d\t%d\n",
               A[i].row,
               A[i].col,
               A[i].value);
    }
}

int main() {

    struct Element A[MAX] = {
        {4, 4, 4},   
        {0, 2, 3},
        {1, 3, 5},
        {2, 0, 7},
        {3, 1, 2}
    };

    struct Element B[MAX];

    transpose(A, B);

    printf("Original:\n");
    display(A);

    printf("\nTranspose:\n");
    display(B);

    return 0;
}