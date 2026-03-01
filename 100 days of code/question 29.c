#include <stdio.h>
#include <stdlib.h>

// Structure definition
struct Node {
    int data;
    struct Node* next;
};

// Function to rotate list
struct Node* rotateRight(struct Node* head, int k) {
    if (head == NULL || head->next == NULL || k == 0)
        return head;

    struct Node *temp = head;
    int length = 1;

    // Find length and last node
    while (temp->next != NULL) {
        temp = temp->next;
        length++;
    }

    // Make it circular
    temp->next = head;

    // Effective rotations
    k = k % length;

    // Find new tail (length - k steps)
    int steps = length - k;
    struct Node *newTail = head;

    for (int i = 1; i < steps; i++) {
        newTail = newTail->next;
    }

    // Set new head
    struct Node *newHead = newTail->next;

    // Break circular link
    newTail->next = NULL;

    return newHead;
}

int main() {
    int n, k;
    scanf("%d", &n);

    struct Node *head = NULL, *temp = NULL, *newNode;

    // Create linked list
    for (int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    scanf("%d", &k);

    head = rotateRight(head, k);

    // Print rotated list
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}