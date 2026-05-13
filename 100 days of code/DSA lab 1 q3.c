#include<stdio.h>
int main() {
    char ch;
    printf("Enter uppercase char: ");
    scanf("%c", &ch);
    if (ch >= 'A' && ch <= 'Z') {
        ch += 32;  
    }
    printf("Lowercase: %c\n", ch);
    return 0;
}
