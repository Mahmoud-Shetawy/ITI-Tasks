#include <stdio.h>
#include <stdlib.h>
#define Row 3
#define Col 4

int main()
{
int arr[Row][Col];
for(int i =0 ; i<Row ; i++){
    for(int j= 0 ; j<Col ; j++){
            printf("please , Enter number [%i][%i] = \n",i+1,j+1);
            scanf("%i",&arr[i][j]);
    }
}
    int sum[Row]={0};
for(int i =0 ; i<Col ; i++){
    for(int j= 0 ; j<Row ; j++){
        sum[i]+=arr[j][i];
    }
}
    for(int j= 0 ; j<Col ; j++){
            printf("please , average of columns %i= %i  \n",j+1,sum[j]/3);

    }
    return 0;
}
