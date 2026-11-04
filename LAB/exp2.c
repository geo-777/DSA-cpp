
#include <stdio.h>
#define MAX 100

typedef struct {
    int row, col, val;
} Field;

void read_sparse(Field A[]) {
    scanf("%d %d %d", &A[0].row, &A[0].col, &A[0].val);

    for (int i = 1; i <= A[0].val; i++) {
        scanf("%d %d %d", &A[i].row, &A[i].col, &A[i].val);
    }
}

void display_sparse(Field A[]) {
    for (int i = 0; i <= A[0].val; i++)
        printf("%d %d %d\n", A[i].row, A[i].col, A[i].val);
}

int compare(Field a, Field b) {
    if (a.row != b.row)
        return a.row - b.row;
    return a.col - b.col;
}

int add(Field A[], Field B[], Field C[]) {
    if (A[0].row != B[0].row || A[0].col != B[0].col)
        return 0;

    int i = 1, j = 1, k = 1;

    C[0].row = A[0].row;
    C[0].col = A[0].col;

    while (i <= A[0].val && j <= B[0].val) {
        int cmp = compare(A[i], B[j]);

        if (cmp == 0) {
            C[k] = A[i];
            C[k].val += B[j].val;
            i++;
            j++;
            if (C[k].val != 0) k++;
        }
        else if (cmp < 0)
            C[k++] = A[i++];
        else
            C[k++] = B[j++];
    }

    while (i <= A[0].val) C[k++] = A[i++];
    while (j <= B[0].val) C[k++] = B[j++];

    C[0].val = k - 1;
    return 1;
}

void transpose(Field A[], Field T[]) {
    T[0].row = A[0].col;
    T[0].col = A[0].row;
    T[0].val = A[0].val;

    int k = 1;

    for (int col = 0; col < A[0].col; col++) {
        for (int i = 1; i <= A[0].val; i++) {
            if (A[i].col == col) {
                T[k].row = A[i].col;
                T[k].col = A[i].row;
                T[k].val = A[i].val;
                k++;
            }
        }
    }
}

int main() {
    Field A[MAX], B[MAX], C[MAX], T[MAX];

    printf("Enter first matrix:\n");
    read_sparse(A);

    printf("Enter second matrix:\n");
    read_sparse(B);

    printf("\nA:\n");
    display_sparse(A);

    printf("\nB:\n");
    display_sparse(B);

    if (add(A, B, C)) {
        printf("\nSum:\n");
        display_sparse(C);
    } else {
        printf("Matrix dimensions must be equal.\n");
    }

    transpose(A, T);

    printf("\nTranspose of A:\n");
    display_sparse(T);

    return 0;
}
