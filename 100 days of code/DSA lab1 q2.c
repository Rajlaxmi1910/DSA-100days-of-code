#include <stdio.h>
int main() {
    int n, i, j, k, element;
    int size = 100; 
    int a1[size];
    printf("Enter number of elements (n): ");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);
    for( k = 0; k < n; k++) {
        scanf("%d", &a1[k]);
    }
    printf("\nOriginal array: ");
    for( k = 0; k < n; k++) {
        printf("%d ", a1[k]);
    }
    printf("\n\nEnter position i (1-based) for insertion: ");
    scanf("%d", &i);
    printf("Enter element to insert: ");
    scanf("%d", &element);
    if(i < 1 || i > n + 1) {
        printf("Invalid position for insertion!\n");
    } else {
        for( k = n; k >= i; k--) {
            a1[k] = a1[k - 1];
        }
        a1[i - 1] = element;  
        n++;  
        
        printf("Array after insertion: ");
        for( k = 0; k < n; k++) {
            printf("%d ", a1[k]);
        }
    }
    printf("\n\nEnter position j (1-based) for deletion: ");
    scanf("%d", &j);
    if(j < 1 || j > n) {
        printf("Invalid position for deletion!\n");
    } else {
        for( k = j - 1; k < n - 1; k++) {
            a1[k] = a1[k + 1];
        }
        n--;    
        printf("Array after deletion: ");
        for( k = 0; k < n; k++) {
            printf("%d ", a1[k]);
        }
    }
    return 0;
}
