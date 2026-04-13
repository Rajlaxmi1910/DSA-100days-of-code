#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    scanf("%s", s);

    int seen[26] = {0}; // for lowercase letters

    for (int i = 0; i < strlen(s); i++) {
        if (seen[s[i] - 'a'] == 1) {
            printf("%c", s[i]);
            return 0;
        }
        seen[s[i] - 'a'] = 1;
    }

    printf("-1");
    return 0;
}