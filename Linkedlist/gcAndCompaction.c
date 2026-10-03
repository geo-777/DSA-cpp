//Garbage collection and compaction simulation using LL
#include <stdio.h>
#include <stdlib.h>

struct Block {
    int startAdress;
    int isFree;
    int size;

    struct Block *prev;
    struct Block *next;
};

struct Block* head=NULL;

struct Block* createBlock(int start, int size, int isFree) {
    struct Block* newBlock = (struct Block*) malloc(sizeof(struct Block));
    newBlock->startAdress=start;
    newBlock->size=size;
    newBlock->isFree=isFree;
    newBlock->prev=NULL;
    newBlock->next=NULL;
    return newBlock;
}

struct Block* insertBlock(struct Block* head, int start, int size, int isFree) {
    struct Block* newBlock = createBlock(start, size, isFree);
    if (head == NULL) {
        return newBlock;
    }
    struct Block* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newBlock;
    newBlock->prev = temp;
    return head;
}

void displayBlocks(struct Block* head) {
    printf("\nMemory Blocks:\n");
    printf("----------------------------\n");
    while (head != NULL) {
        printf("Start: %d, Size: %d, Status: %s\n",
               head->startAdress,
               head->size,
               head->isFree ? "Free" : "Used");
        head = head->next;
    }
    printf("----------------------------\n");
}

void garbageCollection(struct Block* head) {
    struct Block* temp = head;

    while(temp!=NULL && temp->next!=NULL) {
        if(temp->isFree && temp->next->isFree) {
            temp->size += temp->next->size;
            struct Block* toDelete = temp->next;
            temp->next = toDelete->next;

            if(toDelete->next != NULL) {
                toDelete->next->prev = temp;
            }
            free(toDelete);
        } else {
            temp = temp->next;
        }
    }
}

struct Block* compaction(struct Block* head) {
    struct Block* newHead = NULL;
    struct Block* lastAllocated = NULL;

    int currentAddress = 1000;

    //move allocated blocks to the front
    struct Block* temp = head;
    while(temp != NULL) {
        if(!temp->isFree) {
            struct Block* newBlock = createBlock(currentAddress, temp->size, 0);
            currentAddress += temp->size;

            if(newHead == NULL) {
                newHead = newBlock;
                lastAllocated = newBlock;
            } else {
                lastAllocated->next = newBlock;
                newBlock->prev = lastAllocated;
                lastAllocated = newBlock;
            }
        }
        temp = temp->next;
    }

    int freeSpace = 0; //calculate total free space
    temp = head;
    while(temp != NULL) {
        if(temp->isFree) {
            freeSpace += temp->size;  
        }
        temp = temp->next;
    }

    if(freeSpace > 0) {
        struct Block* freeBlock = createBlock(currentAddress, freeSpace, 1);
        if(newHead == NULL) {
            newHead = freeBlock;
        } else {
            lastAllocated->next = freeBlock;
            freeBlock->prev = lastAllocated;
        }
    }

    //free old list
    temp = head;
    while(temp != NULL) {
        struct Block* toDelete = temp;
        temp = temp->next;
        free(toDelete);
    }

    return newHead;
}

int main() {
    // Initial memory setup
    head = insertBlock(head, 1000, 200, 0); // Used
    head = insertBlock(head, 1200, 150, 1); // Free
    head = insertBlock(head, 1350, 300, 0); // Used
    head = insertBlock(head, 1650, 100, 1); // Free
    head = insertBlock(head, 1750, 200, 1); // Free

    printf("\nBefore Garbage Collection and Compaction:");
    displayBlocks(head);

    garbageCollection(head);
    printf("\nAfter Garbage Collection:");
    displayBlocks(head);

    head = compaction(head);
    printf("\nAfter Compaction:");
    displayBlocks(head);

    while (head != NULL) {
        struct Block* next = head->next;
        free(head);
        head = next;
    }

    return 0;
}
