#include <stdio.h>
#define MAX 100
int queue[MAX];
int front = -1, rear = -1;
int n;
void enqueue(int value) {
    if ((rear + 1) % n == front) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1)
        front = 0;
    rear = (rear + 1) % n;
    queue[rear] = value;
}
void dequeue() {
    if (front == -1) {
        printf("Queue Underflow\n");
        return;
    }
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % n;
    }
}
void display() {
    if (front == -1) {
        printf("Queue is Empty");
        return;
    }
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % n;
    }
}
int main() {
    int m, i, value;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        enqueue(value);
    }
    scanf("%d", &m);

    for (i = 0; i < m; i++) {
        dequeue();
    }

    display();

    return 0;
}