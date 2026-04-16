#include <stdio.h>

int maxLen(int arr[], int n) {
    int sum = 0, max_len = 0;

    // HashMap using arrays (simple approach)
    // Assume range of sum is manageable
    int hash[10000] = {0};  // initialize with 0
    int visited[10000] = {0};

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (sum == 0)
            max_len = i + 1;

        if (visited[sum + 5000]) {
            int len = i - hash[sum + 5000];
            if (len > max_len)
                max_len = len;
        } else {
            hash[sum + 5000] = i;
            visited[sum + 5000] = 1;
        }
    }

    return max_len;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d", maxLen(arr, n));

    return 0;
}