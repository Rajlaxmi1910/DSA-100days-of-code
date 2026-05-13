#include <stdio.h>
int main() {
    int a[10][10], row, col, i, j;
    int rowSum, colSum;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &row, &col);
    printf("Enter matrix elements:\n");
    for(i = 0; i < row; i++) {
        for(j = 0; j < col; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    printf("\nSum of each row:\n");
    for(i = 0; i < row; i++) {
        rowSum = 0;
        for(j = 0; j < col; j++) {
            rowSum += a[i][j];
        }
        printf("Row %d = %d\n", i + 1, rowSum);
    }
    printf("\nSum of each column:\n");
    for(j = 0; j < col; j++) {
        colSum = 0;
        for(i = 0; i < row; i++) {
            colSum += a[i][j];
        }
        printf("Column %d = %d\n", j + 1, colSum);
    }
    return 0;
}
