#include <stdio.h>
#include <stdlib.h>
#define rows 3
#define cols 4

int main() {

    int **arr = (int *)malloc(rows * sizeof(int *));

    for (int i = 0; i < rows; i++) {
        arr[i] = (int *)malloc(cols * sizeof(int));
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter value for arr[%i][%i]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    printf("Values in the 2D array:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("arr[%i][%i] = %i\n", i, j, arr[i][j]);
        }
    }

    for (int i = 0; i < rows; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}
