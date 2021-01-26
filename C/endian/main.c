#include <stdio.h>

int main() {
    int n = 1;
    if(*(char *)&n == 1)
    {
        printf("little\n");
    }
    else
    {
        printf("big\n");
    }
    printf("Hello, World!\n");
    return 0;
}
