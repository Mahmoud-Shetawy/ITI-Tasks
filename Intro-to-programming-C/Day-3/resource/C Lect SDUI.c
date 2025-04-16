int main()
{
    int arr[3][4];  //3*4*int=48B

    int sum[3]={0};  //int sum1,sum2,sum3
    arr[0][0]=1;
    arr[0][1]=2;
    arr[0][2]=3;
    arr[0][3]=4;
    arr[1][0]=5;
    arr[1][1]=6;
    //memory i01 j012340
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            printf("Enter value at index %d,%d\n",i,j);
            scanf("%d",&arr[i][j]);//4
        }
    }

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            printf("Value at index %d,%d is %d\n",i,j,arr[i][j]);
        }
    }
    
    //Sum of rows
    for(int row=0;row<3;row++)
    {
        for(int col=0;col<4;col++)
        {
            sum[row]+= arr[row][col];
        }
    }

    for(int i=0;i<3;i++)
    {
        printf("Sum of rows at index %d is %d\n",i,sum[i]);
    }
}


/////////////////////////////////////////
//normal or extended key

int main()
{
    char ch;

    printf("Enter Key\n");
    ch=getch();

    switch(ch)
    {
        case -32:
        ch=getch();
        printf("Extended key with ascii %d",ch);
        break;
        default:
        printf("Normal key with ascii %d",ch);
        break;
    }
}