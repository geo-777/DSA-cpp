#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

// Insert an element
void enqueue(int item)
{
    if (rear == MAX - 1)
    {
        printf("Queue Overflow\n");
        return;
    }

    if (front == -1)
        front = rear = 0;
    else
        rear++;

    queue[rear] = item;
    printf("%d inserted into queue.\n", item);
}

// Delete an element
void dequeue()
{
    if (front == -1)
    {
        printf("Queue Underflow\n");
        return;
    }

    printf("%d deleted from queue.\n", queue[front]);

    if (front == rear)
        front = rear = -1;
    else
        front++;
}

// Display front element
void peek()
{
    if (front == -1)
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("Front element: %d\n", queue[front]);
}

// Display queue
void display()
{
    int i;

    if (front == -1)
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue: ");

    for (i = front; i <= rear; i++)
        printf("%d ", queue[i]);

    printf("\n");
}

int main()
{
    int choice, item;

    while (1)
    {
        printf("\nQueue Operations\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter element: ");
            scanf("%d", &item);
            enqueue(item);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            peek();
            break;

        case 4:
            display();
            break;

        case 5:
            return 0;

        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}