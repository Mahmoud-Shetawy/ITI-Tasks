#include <stdio.h>
#include <stdlib.h>
#define sizeArray 15

int main()
{
int arr[15];

for(int i = 0 ; i<sizeArray;i++){
    printf("please , Enter number %i = \n",i+1);
    scanf("%i",&arr[i]);
}

printf("please , Enter  number you want to search = \n");
int number =0;
scanf("%i",&number);


for(int i = 0 ; i<sizeArray;i++){
if(arr[i]==number){
    printf("done at index  = %i \n" , i);
}
}
    return 0;
}
