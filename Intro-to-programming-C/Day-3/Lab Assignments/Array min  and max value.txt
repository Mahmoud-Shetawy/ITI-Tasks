#include <stdio.h>
#include <stdlib.h>
#define sizeArray 15


void selectionSort(int array[]){

    for(int i = 0 ; i<=sizeArray-2; i++){
        int smallest =i;
        for(int j = i+1 ; j <=sizeArray-1;j++ ){
            if(array[j]<array[smallest]){
                smallest = j ;
            }
        }

        int Temp = array[i];
        array[i]=array[smallest];
        array[smallest] = Temp;

}
}
int main()
{
int arr[sizeArray];
for(int i = 0 ; i<sizeArray;i++){
    printf("please , Enter number %i = \n",i+1);
    scanf("%i",&arr[i]);
}

selectionSort(arr);


printf("Min Value = %i and Max Value = %i",arr[0] ,arr[14]);

    return 0;
}
