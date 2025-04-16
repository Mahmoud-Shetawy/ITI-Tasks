#include <stdio.h>
void SwapV(int left, int right)
{
    int temp = left;
    left = right;
    right = temp;
}

int main()
{
    int x = 3;
    int y = 5;
    printf("Before: x = %i, y = %i\n", x, y);
    SwapV(x, y);
    printf("After: x = %i, y = %i\n", x, y);
    return 0;
}
