#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

struct HeapNode {
    struct Node* node;
    int listIndex;
};

void swap(struct HeapNode* a, struct HeapNode* b) {
    struct HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(struct HeapNode heap[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap[left].node->data < heap[smallest].node->data)
        smallest = left;

    if (right < n && heap[right].node->data < heap[smallest].node->data)
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapify(heap, n, smallest);
    }
}

void buildHeap(struct HeapNode heap[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(heap, n, i);
}

struct Node* mergeKLists(struct Node* arr[], int k) {
    struct HeapNode* heap = (struct HeapNode*)malloc(sizeof(struct HeapNode) * k);
    int heapSize = 0;

    for (int i = 0; i < k; i++) {
        if (arr[i] != NULL) {
            heap[heapSize].node = arr[i];
            heap[heapSize].listIndex = i;
            heapSize++;
        }
    }
    buildHeap(heap, heapSize);

    struct Node dummy;
    struct Node* tail = &dummy;
    dummy.next = NULL;

    while (heapSize > 0) {
        struct HeapNode root = heap[0];

        tail->next = root.node;
        tail = tail->next;

        if (root.node->next != NULL) {
            heap[0].node = root.node->next;
        } else {
            heap[0] = heap[heapSize - 1];
            heapSize--;
        }

        heapify(heap, heapSize, 0);
    }

    return dummy.next;
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d--> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    int k = 3; 

    struct Node* arr[k];

    arr[0] = newNode(1);
    arr[0]->next = newNode(4);
    arr[0]->next->next = newNode(5);
    arr[0]->next->next->next=NULL;
    printf("List1\n");
    printList(arr[0]);
    arr[1] = newNode(1);
    arr[1]->next = newNode(3);
    arr[1]->next->next = newNode(4);
    arr[1]->next->next->next=NULL;
    printf("List2\n");
    printList(arr[1]);
    arr[2] = newNode(2);
    arr[2]->next = newNode(6);
    arr[2]->next->next=NULL;
    printf("List3\n");
    printList(arr[2]);
    struct Node* result = mergeKLists(arr, k);
    
    printf("Merged Sorted Linked List:\n");
    printList(result);

    return 0;
}