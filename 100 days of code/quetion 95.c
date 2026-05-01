#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float values[100];
    int count;
} Bucket;

void insertionSort(float arr[], int n) {
    for (int i = 1; i < n; i++) {
        float key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

void bucketSort(float arr[], int n) {
    Bucket buckets[n];

    for (int i = 0; i < n; i++)
        buckets[i].count = 0;

    for (int i = 0; i < n; i++) {
        int index = arr[i] * n;
        buckets[index].values[buckets[index].count++] = arr[i];
    }

    for (int i = 0; i < n; i++)
        insertionSort(buckets[i].values, buckets[i].count);

    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < buckets[i].count; j++) {
            arr[k++] = buckets[i].values[j];
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    float arr[n];

    for (int i = 0; i < n; i++)
        scanf("%f", &arr[i]);

    bucketSort(arr, n);

    for (int i = 0; i < n; i++)
        printf("%.2f ", arr[i]);

    return 0;
}