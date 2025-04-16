#include <stdio.h>

void SwapA(int *left, int *right) {
    int temp = *left;
    *left = *right;
    *right = temp;
}

int main() {
    int x = 3;
    int y = 5;
    printf("Before: x = %i, y = %i\n", x, y);
    SwapA(&x, &y);
    printf("After: x = %i, y = %i\n", x, y);
    return 0;
}
