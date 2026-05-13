#include <stdio.h>

#define MAX 100

int heap[MAX];
int size = 0;

// Insert into Min Heap
void insert(int value) {
    int i;
    size++;
    heap[size] = value;
    i = size;

    // Heapify Up
    while (i > 1 && heap[i/2] > heap[i]) {
        int temp = heap[i];
        heap[i] = heap[i/2];
        heap[i/2] = temp;
        i = i / 2;
    }
}

// Delete from Min Heap
void deleteMin() {
    int i, smallest;

    if (size == 0) {
        printf("Heap is empty\n");
        return;
    }

    printf("Deleted element: %d\n", heap[1]);

    heap[1] = heap[size];
    size--;

    i = 1;

    // Heapify Down
    while (2 * i <= size) {
        smallest = i;

        if (heap[2*i] < heap[smallest])
            smallest = 2*i;

        if (2*i + 1 <= size && heap[2*i + 1] < heap[smallest])
            smallest = 2*i + 1;

        if (smallest != i) {
            int temp = heap[i];
            heap[i] = heap[smallest];
            heap[smallest] = temp;
            i = smallest;
        } else {
            break;
        }
    }
}

// Display Heap
void display() {
    int i;

    if (size == 0) {
        printf("Heap is empty\n");
        return;
    }

    printf("Heap elements: ");
    for (i = 1; i <= size; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

// Main Function
int main() {
    int choice, value;

    while (1) {
        printf("\n--- MIN HEAP MENU ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insert(value);
                break;

            case 2:
                deleteMin();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
