
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char name[50];
    int priority;
} Customer;

Customer *heap[MAX];
int size = 0;

void swap(int i, int j) {
    Customer *temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;
}

Customer *createCustomer(char name[], int priority) {
    Customer *cust = malloc(sizeof(Customer));

    if (cust == NULL)
        return NULL;

    strcpy(cust->name, name);
    cust->priority = priority;

    return cust;
}

void insertCustomer(char name[], int priority) {
    if (size == MAX) {
        printf("Heap is full\n");
        return;
    }

    if (strlen(name) >= 50) {
        printf("Name is too long\n");
        return;
    }

    Customer *customer = createCustomer(name, priority);

    if (customer == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    heap[size++] = customer;

    int i = size - 1;

    while (i > 0) {
        int parent = (i - 1) / 2;

        if (heap[parent]->priority < heap[i]->priority) {
            swap(parent, i);
        }
        else break;

        i = parent;
    }

    printf("Customer added successfully\n");
}

void serveCustomer() {
    if (size == 0) {
        printf("No customer left to serve\n");
        return;
    }

    swap(0, size - 1);

    Customer *customer = heap[--size];

    printf("Serving: %s, Priority: %d\n",
           customer->name, customer->priority);

    free(customer);

    // Heapify down
    int i = 0;
    int left, right, largest;

    while (1) {
        largest = i;
        left = 2 * i + 1;
        right = 2 * i + 2;

        if (left < size &&
            heap[left]->priority > heap[largest]->priority) {
            largest = left;
        }

        if (right < size &&
            heap[right]->priority > heap[largest]->priority) {
            largest = right;
        }

        if (largest != i) {
            swap(i, largest);
            i = largest;
        }
        else break;
    }
}

void displayCustomers() {
    if (size == 0) {
        printf("No customers in queue\n");
        return;
    }

    printf("\nCustomers in heap:\n");

    for (int i = 0; i < size; i++) {
        printf("%s - Priority: %d\n",
               heap[i]->name, heap[i]->priority);
    }
}

int main() {
    int choice, priority;
    char name[100];

    do {
        printf("\n1. Add Customer\n");
        printf("2. Serve Customer\n");
        printf("3. Display all customers\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1)
            break;

        switch (choice) {
            case 1:
                printf("Enter customer name: ");
                scanf(" %99[^\n]", name);

                printf("Enter priority: ");
                if (scanf("%d", &priority) != 1) {
                    printf("Invalid priority\n");
                    while (getchar() != '\n');
                    break;
                }

                insertCustomer(name, priority);
                break;

            case 2:
                serveCustomer();
                break;

            case 3:
                displayCustomers();
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while (choice != 4);

    // Free remaining customers
    while (size > 0) {
        free(heap[--size]);
    }

    return 0;
}
