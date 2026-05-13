#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
struct node {
    int data;
    struct node* next;
};
struct node* chainTable[SIZE];
void initChain() {
    int i;
    for(i = 0; i < SIZE; i++) {
        chainTable[i] = NULL;
    }
}
void insertChain(int key) {
    int index = key % SIZE;
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = key;
    newNode->next = chainTable[index];
    chainTable[index] = newNode;
}
void displayChain() {
    int i;
    struct node* temp;
    printf("\n--- Chaining Hash Table ---\n");
    for(i = 0; i < SIZE; i++) {
        temp = chainTable[i];
        printf("Index %d: ", i);
        while(temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}
int linearTable[SIZE];
void initLinear() {
    int i;
    for(i = 0; i < SIZE; i++) {
        linearTable[i] = -1;
    }
}
void insertLinear(int key) {
    int index = key % SIZE;
    while(linearTable[index] != -1) {
        index = (index + 1) % SIZE;
    }
    linearTable[index] = key;
}
void displayLinear() {
    int i;
    printf("\n--- Linear Probing Hash Table ---\n");
    for(i = 0; i < SIZE; i++) {
        printf("Index %d: %d\n", i, linearTable[i]);
    }
}
int main() {
    int keys[] = {10, 20, 15, 7, 32, 25};
    int n = 6, i;
    initChain();
    initLinear();
    for(i = 0; i < n; i++) {
        insertChain(keys[i]);
        insertLinear(keys[i]);
    }
    displayChain();
    displayLinear();
    return 0;
}
