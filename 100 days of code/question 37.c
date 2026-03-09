#include <stdio.h>
#define MAX 100
int pq[MAX];
int size = 0;
void insert(int x) {
    pq[size] = x;
    size++;
}
void deleteElement() {
    if (size == 0) {
        printf("-1\n");
        return;
    }
    int minIndex = 0;
    for (int i = 1; i < size; i++) {
        if (pq[i] < pq[minIndex]) {
            minIndex = i;
        }
    }
    printf("%d\n", pq[minIndex]);
    for (int i = minIndex; i < size - 1; i++) {
        pq[i] = pq[i + 1];
    }
    size--;
}
void peek() {
    if (size == 0) {
        printf("-1\n");
        return;
    }
    int min = pq[0];
    for (int i = 1; i < size; i++) {
        if (pq[i] < min) {
            min = pq[i];
        }
    }
    printf("%d\n", min);
}
int main() {
    int N, x;
    char op[10];
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%s", op);
        if (op[0] == 'i') {   // insert
            scanf("%d", &x);
            insert(x);
        }
        else if (op[0] == 'd') { // delete
            deleteElement();
        }
        else if (op[0] == 'p') { // peek
            peek();
        }
    
    return 0;
}