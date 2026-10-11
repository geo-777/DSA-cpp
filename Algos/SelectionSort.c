#include <stdio.h>
void printArray(int arr[], int n) {
    for (int i=0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
void readArray(int arr[], int n) {
    for (int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    
}
void sort(int arr[], int n) {
    int i, j, temp, min_index;

    for(i=0; i<n-1; i++) {
        min_index = i;
        for(j=i+1; j < n; j++) {
            if(arr[j] < arr[min_index]) {
                min_index=j;
            }
        }

        if (min_index != i) {
            temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
        }
    }
}

int main() {
    int arr[50] ;
    int n;
    
    printf("Enter the number of elements \n");
    scanf("%d",&n);
    printf("Enter the array elements\n");
    readArray(arr,n);
    
    printf("Original array: ");
    printArray(arr, n);

    sort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}