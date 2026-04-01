def is_min_heap(arr, n):
    for i in range(n):
        left = 2 * i + 1
        right = 2 * i + 2

        # Check left child
        if left < n and arr[i] > arr[left]:
            return "NO"

        # Check right child
        if right < n and arr[i] > arr[right]:
            return "NO"

    return "YES"
n = int(input())
arr = list(map(int, input().split()))

# Output
print(is_min_heap(arr, n))