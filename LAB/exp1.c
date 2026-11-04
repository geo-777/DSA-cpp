#include <stdio.h>

typedef struct {
    int coeff;int exp;
} Term;

void readPoly(Term A[],int size) {
    for(int i=0; i<size; i++) {
        scanf("%d %d", &A[i].coeff, &A[i].exp);
    }
}

void display(Term p[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%dx^%d", p[i].coeff, p[i].exp);

    if (i != size - 1) printf(" + ");
  }
  printf("\n");
}

int add(Term A[],Term B[],int m, int n, Term C[]) {
    int i=0,j=0,k=0;

    while(i<m && j<n) {
        if(A[i].exp == B[j].exp) {
            C[k++] = (Term){.coeff = A[i].coeff + B[j].coeff, .exp = A[i].exp};
            i++;j++;
        }else if(A[i].exp > B[j].exp) {
            C[k++]= A[i++];
        }else {
            C[k++]=B[j++];
        }
    }
    while(i<m)C[k++]= A[i++];
    while(j<n)C[k++]=B[j++];

    return k;
}

int main() {
    Term A[100],B[100],C[100];
    int m,n;
    printf("Enter sizes of polynomial : ");
    scanf("%d %d",&m,&n);

    printf("Enter polynomial 1:\n");
    readPoly(A,m);

    printf("Enter polynomial 2:\n");
    readPoly(B,n);

    display(A,m);
    display(B,n);

    int size = add(A,B,m,n,C);
    display(C,size);


    return 0;
}