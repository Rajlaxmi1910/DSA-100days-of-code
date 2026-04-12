#include <stdio.h>
#include <string.h>

#define EMPTY -1

int table[100]; // max size

// Initialize table
void init(int m) {
    for(int i = 0; i < m; i++)
        table[i] = EMPTY;
}

// Insert using quadratic probing
void insert(int key, int m) {
    int h = key % m;

    for(int i = 0; i < m; i++) {
        int index = (h + i * i) % m;

        if(table[index] == EMPTY) {
            table[index] = key;
            return;
        }
    }

    printf("Hash Table Full\n");
}

// Search using quadratic probing
void search(int key, int m) {
    int h = key % m;

    for(int i = 0; i < m; i++) {
        int index = (h + i * i) % m;

        if(table[index] == key) {
            printf("FOUND\n");
            return;
        }

        if(table[index] == EMPTY) {
            break;
        }
    }

    printf("NOT FOUND\n");
}

int main() {
    int m, n;
    char op[10];
    int key;

    scanf("%d", &m);  // size of table
    scanf("%d", &n);  // number of operations

    init(m);

    for(int i = 0; i < n; i++) {
        scanf("%s %d", op, &key);

        if(strcmp(op, "INSERT") == 0) {
            insert(key, m);
        }
        else if(strcmp(op, "SEARCH") == 0) {
            search(key, m);
        }
    }

    return 0;
}