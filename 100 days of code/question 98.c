#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start, end;
} Interval;

int compare(const void *a, const void *b) {
    return ((Interval *)a)->start - ((Interval *)b)->start;
}

int main() {
    int n;
    scanf("%d", &n);

    Interval arr[n];

    for (int i = 0; i < n; i++)
        scanf("%d %d", &arr[i].start, &arr[i].end);

    qsort(arr, n, sizeof(Interval), compare);

    int index = 0;

    for (int i = 1; i < n; i++) {
        if (arr[index].end >= arr[i].start) {
            if (arr[i].end > arr[index].end)
                arr[index].end = arr[i].end;
        } else {
            index++;
            arr[index] = arr[i];
        }
    }

    for (int i = 0; i <= index; i++)
        printf("%d %d\n", arr[i].start, arr[i].end);

    return 0;
}