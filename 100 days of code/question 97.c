#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start, end;
} Meeting;

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapify(int heap[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap[left] < heap[smallest])
        smallest = left;

    if (right < n && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapify(heap, n, smallest);
    }
}

void insertHeap(int heap[], int *size, int value) {
    int i = (*size)++;
    heap[i] = value;

    while (i != 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int extractMin(int heap[], int *size) {
    int root = heap[0];
    heap[0] = heap[--(*size)];
    heapify(heap, *size, 0);
    return root;
}

int compare(const void *a, const void *b) {
    return ((Meeting *)a)->start - ((Meeting *)b)->start;
}

int main() {
    int n;
    scanf("%d", &n);

    Meeting arr[n];

    for (int i = 0; i < n; i++)
        scanf("%d %d", &arr[i].start, &arr[i].end);

    qsort(arr, n, sizeof(Meeting), compare);

    int heap[n];
    int size = 0;
    int maxRooms = 0;

    for (int i = 0; i < n; i++) {
        while (size > 0 && heap[0] <= arr[i].start)
            extractMin(heap, &size);

        insertHeap(heap, &size, arr[i].end);

        if (size > maxRooms)
            maxRooms = size;
    }

    printf("%d\n", maxRooms);

    return 0;
}