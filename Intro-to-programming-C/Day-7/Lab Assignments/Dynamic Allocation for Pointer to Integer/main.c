#include <stdio.h>
#include <stdlib.h>

int main() {
    int _size;
    printf("Enter  size of the array: ");
    scanf("%d", &_size);

    int *ptr = (int *)malloc(_size * sizeof(int));

     /// way #1

//    for (int i = 0; i < _size; i++) {
//        printf("Enter value for element %i: ", i);
//        scanf("%i", &ptr[i]);
//    }
//
//
//    printf("Values in the array:\n");
//    for (int i = 0; i < _size; i++) {
//        printf("ptr[%i] = %i\n", i, ptr[i]);
//    }




         ///  way #2
    for (int i = 0; i < _size; i++) {
        printf("Enter value for element %i (second method): ", i);
        scanf("%i", (ptr + i));
    }



    printf("Values in the array:\n");
    for (int i = 0; i < _size; i++) {
        printf("ptr[%i] = %i\n",i,*(ptr + i));
    }
    free(ptr);
    return 0;
}
