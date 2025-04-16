#include <stdio.h>

int main() {
    int x;
    int *ptr = &x;
    int **ptrToPtr = &ptr;

    printf("Enter a value for x: ");
    scanf("%i", &x);

    printf("Enter a new value for x via the pointer: ");
    scanf("%i", *ptrToPtr);  //

    printf("New value of x = %i\n", x);
    return 0;
}
