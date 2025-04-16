#include <stdio.h>

int power(int x, int y) {
    if (y == 0) {
        return 1;
    }
    else {
        return x * power(x, y - 1);
    }
}

int main() {
    int x, y;

    printf("Enter x: ");
    scanf("%i", &x);

    printf("Enter y: ");
    scanf("%i", &y);

    printf("%i^%i = %i\n", x, y, power(x, y));

    return 0;
}
