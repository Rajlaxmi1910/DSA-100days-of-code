#include <stdio.h>

#define MAX 100

int heap[MAX];
int size = 0;

// Insert in Max Heap
void insert(int value) {
    size++;
    int i = size;
    heap[i] = value;

    while (i > 1 && heap[i/2] < heap[i]) {
        int temp = heap[i];
        heap[i] = heap[i/2];
        heap[i/2] = temp;
        i = i / 2;
    }
}

// Delete from Max Heap
void delete() {
    if (size == 0) {
        printf("Heap is empty\n");
        return;
    }

    printf("Deleted: %d\n", heap[1]);

    heap[1] = heap[size];
    size--;

    int i = 1;

    while (2*i <= size) {
        int largest = i;

        if (heap[2*i] > heap[largest])
            largest = 2*i;

        if (2*i+1 <= size && heap[2*i+1] > heap[largest])
            largest = 2*i+1;

        if (largest != i) {
            int temp = heap[i];
            heap[i] = heap[largest];
            heap[largest] = temp;
            i = largest;
        } else
            break;
    }
}

// Display
void display() {
    for (int i = 1; i <= size; i++)
        printf("%d ", heap[i]);
    printf("\n");
}

int main() {
    insert(10);
    insert(30);
    insert(20);
    insert(40);

    printf("Max Heap: ");
    display();

    delete();

    printf("After Deletion: ");
    display();

    return 0;
}
