#include <stdio.h>

char* isMinHeap(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        // Check left child
        if (left < n && arr[i] > arr[left]) {
            return "NO";
        }

        // Check right child
        if (right < n && arr[i] > arr[right]) {
            return "NO";
        }
    }
    return "YES";
}

int main() {
    int n;

    // Input size
    scanf("%d", &n);

    int arr[n];

    // Input elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Output result
    printf("%s\n", isMinHeap(arr, n));

    return 0;
}