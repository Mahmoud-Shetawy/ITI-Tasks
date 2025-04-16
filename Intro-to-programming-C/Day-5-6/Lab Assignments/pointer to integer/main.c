#include <stdio.h>

int main() {
    int x = 10;
    int *ptr = &x;
    printf("Enter an integer: ");
    scanf("%d", ptr);
    printf("Before: x = %i\n", *ptr);
    *ptr = 20;
    printf("After: x = %i\n", *ptr);
    return 0;
}
