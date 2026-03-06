#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* top = NULL;
void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}
int pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    
    struct Node* temp = top;
    int value = temp->data;
    top = top->next;
    free(temp);
    
    return value;
}

int main() {
    int a, b, result;
    char exp[100];
    
    printf("Enter postfix expression: ");
    fgets(exp, sizeof(exp), stdin);

    for (int i = 0; exp[i] != '\0'; i++) {
        if (isdigit(exp[i])) {
            push(exp[i] - '0');
        }
        else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') {

            b = pop();
            a = pop();

            switch (exp[i]) {
                case '+':
                    result = a + b;
                    break;
                case '-':
                    result = a - b;
                    break;
                case '*':
                    result = a * b;
                    break;
                case '/':
                    result = a / b;
                    break;
            }

            push(result);
        }
    }

    printf("Result = %d\n", pop());

    return 0;
}