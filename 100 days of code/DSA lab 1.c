#include <stdio.h>
void insert(int arr[], int *n, int pos, int x) {
    if (pos < 0 || pos > *n) {
        printf("Invalid position for insertion.\\n");
        return;
    }
    for ( i = *n - 1; i >= pos; i--) {
        arr[i + 1] = arr[i]; 
    }
    arr[pos] = x;
    (*n)++;
}
int main() {
    int array[50] = {10, 20, 30, 40, 50};
    int n = 5; 
    int position_to_insert = 2; 
    int value_to_insert = 99;
    printf("Array before insertion: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\\n");
    insert(array, &n, position_to_insert, value_to_insert);
    
    printf("Array after insertion of %d at index %d: ", value_to_insert, position_to_insert);
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\\n");
    return 0;
}
