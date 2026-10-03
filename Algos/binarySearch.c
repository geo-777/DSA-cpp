#include <stdio.h>


int binarySearchIterative(int arr[],int key,int len) {
    int left=0;
    int right = len-1;
    while(left<=right) {
        int mid = left + (right - left)/2;
        
        if(arr[mid]==key){
            return mid;
        }else if(arr[mid] > key){
            right=mid-1;
        }else{
            left=mid+1;
        }
    }
    return -1; //incase not found
}

int binarySearchRecursive(int arr[], int low, int high, int key)
{
    if (low > high)
        return -1;

    int mid = (low + high) / 2;

    if (arr[mid] == key)
        return mid;

    if (key < arr[mid])
        return binarySearchRecursive(arr, low, mid - 1, key);

    return binarySearchRecursive(arr, mid + 1, high, key);
}


int main() {
    int arr[] = {-1,2,3,4,5,6,7,8,9,10,15,55,200};
    int n=13;
    int key=201;
    //iterative search
    printf("Found %d at index : %d",key,binarySearchIterative(arr,key,n));
    //recursive
     key=55;
    printf("\nFound %d at index : %d",key,binarySearchRecursive(arr,0,n-1,key));

}