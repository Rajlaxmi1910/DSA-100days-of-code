#include <stdio.h>
#include <stdlib.h>
int main() {
    int n, key, i;
    int *arr;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed");
        return 0;
    }
    printf("Enter elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter element to search: ");
    scanf("%d", &key);
    for (i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("Element found at position %d", i + 1);
            
            break;
        }
    }
    if (i == n) {
        printf("Element not found");
    }
    free(arr);

    return 0;
}

