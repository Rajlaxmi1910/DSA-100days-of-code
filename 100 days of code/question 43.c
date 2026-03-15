#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Queue {
    struct Node* arr[100];
    int front, rear;
};

void enqueue(struct Queue* q, struct Node* node) {
    q->arr[++q->rear] = node;
}

struct Node* dequeue(struct Queue* q) {
    return q->arr[++q->front];
}

int isEmpty(struct Queue* q) {
    return q->front == q->rear;
}

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void inorder(struct Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    if(arr[0] == -1)
        return 0;

    struct Node* root = newNode(arr[0]);

    struct Queue q;
    q.front = q.rear = -1;
    enqueue(&q, root);

    int i = 1;

    while(i < n && !isEmpty(&q)) {
        struct Node* current = dequeue(&q);

        if(arr[i] != -1) {
            current->left = newNode(arr[i]);
            enqueue(&q, current->left);
        }
        i++;

        if(i < n && arr[i] != -1) {
            current->right = newNode(arr[i]);
            enqueue(&q, current->right);
        }
        i++;
    }

    inorder(root);

    return 0;
}