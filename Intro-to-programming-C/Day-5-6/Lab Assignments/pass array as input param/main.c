#include <stdio.h>
#include <stdlib.h>

void MultArrBy2(int* pram,int size)
{
    for(int i =0; i< size; i++)
    {
        pram[i] *= 2;
    }
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};

    int *ptr = arr;

    printf("The array before \n");
    for(int i =0; i < 5;i++)
    {
        printf("%i ", ptr[i]);
    }

    MultArrBy2(arr, 5);
    printf("\nThe array after \n");
    for(int i =0; i < 5;i++)
    {
        printf("%i ", ptr[i]);
    }

    return 0;
}
