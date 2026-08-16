#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void display(struct Node *head){
    while(head!=NULL){
        printf("%d\n",head->data);
        head=head->next;
    }
}

void insertAtEnd(struct Node **head, int val){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

    if (*head==NULL){
        *head=newNode;
        return;
    }

    struct Node*temp=*head;
    while(temp->next!=NULL){temp=temp->next;}
    temp->next = newNode;
}

void insertAtFront(struct Node **head, int val){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = *head;
    *head=newNode;
}
void insertAtPos(struct Node **head, int val, int pos){
    if(pos < 0){
        printf("Invalid position!\n");
        return;
    }

    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

    if(pos == 0){
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node* temp = *head;

    for(int i = 0; i < pos - 1; i++){
        if(temp == NULL){
            printf("Invalid position!\n");
            free(newNode);
            return;
        }
        temp = temp->next;
    }

    if(temp == NULL){
        printf("Invalid position!\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteAtFront(struct Node **head){
    if(*head == NULL){
        return;
    }
    struct Node *temp=*head;
    *head = (temp)->next;

    free(temp);
}

void deleteAtEnd(struct Node **head) {
    if(*head == NULL){
        return;
    }
    if((*head)->next == NULL){
        free(*head);
        *head=NULL;
        return;
    }

    struct Node* temp = *head;
    while(temp->next->next != NULL){
        temp=temp->next;
    }
    free(temp->next);
    temp->next=NULL;
}

void deleteAtPos(struct Node **head, int pos) {
    if (*head == NULL) {
        return;
    }

    if (pos == 1) {
        struct Node *temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    struct Node *temp = *head;

    for (int i = 0; i < pos - 2; i++) {
        if (temp == NULL) {
            printf("Invalid position!\n");
            return;
        }
        temp = temp->next;
    }
    if (temp->next == NULL) {
        printf("Invalid position!\n");
        return;
    }

    struct Node *deleteNode = temp->next;
    temp->next = deleteNode->next;
    free(deleteNode);
}

int main() {

    struct Node *head=NULL;

    insertAtEnd(&head,10);
    insertAtFront(&head,20);
    insertAtFront(&head,100);

    insertAtPos(&head,69,1);
    display(head);

    return 0;
}