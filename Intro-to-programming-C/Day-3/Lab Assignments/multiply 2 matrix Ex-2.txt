#include <stdio.h>
#include <stdlib.h>

int main()
{
        int arr1[3][3];
for(int i =0 ; i<3 ; i++){
    for(int j= 0 ; j<3 ; j++){
            printf("please , Enter number of Array #1 [%i][%i] = \n",i+1,j+1);
            scanf("%i",&arr1[i][j]);
    }
}

printf("==========================================\n");

    int arr2[3][2];
for(int i =0 ; i<3 ; i++){
    for(int j= 0 ; j<2 ; j++){
            printf("please , Enter number of Array #2 [%i][%i] = \n",i+1,j+1);
            scanf("%i",&arr2[i][j]);
    }
}
      int MUL[3][2] = {0};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 3; k++) {
                MUL[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }

    printf("Result of multiplying :\n");
    for (int i = 0; i < 3; i++) {
            for(int j = 0; j < 2; j++){
            printf("%i  ", MUL[i][j]);
            }
             printf("\n");
    }
    return 0;
}
