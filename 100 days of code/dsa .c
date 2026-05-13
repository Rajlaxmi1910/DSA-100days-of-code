#include <stdio.h>
int main()
{
    int n, i, found = 0;
    float arr[100], key;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d numbers:\n", n);
    for(i = 0; i < n; i++)
    {
        scanf("%f", &arr[i]);
    }
    printf("Enter number to search: ");
    scanf("%f", &key);

    for(i = 0; i < n; i++)
    {
        if(arr[i] == key)
        {
            found = 1;
            break;
        }
    }

    if(found == 1)
        printf("Search successful: element found\n");
    else
        printf("Search failed: element not found\n");

    return 0;
}

