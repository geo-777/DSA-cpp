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
    int i, j, temp;

    for(i=0; i<n-1; i++) {
        for(j=0; j < n-i-1; j++) {
            if(arr[j]>arr[j+1]) {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    //printing the array after each round
    printArray(arr, n);

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