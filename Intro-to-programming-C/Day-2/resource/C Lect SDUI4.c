///85->100 A
///75->84  B
///65->74  C
///  F

#include<stdio.h>
int main()
{
    int grade;

    printf("Enter Grade\n");
    scanf("%d",&grade);

    if(grade>=85)
    {
        printf("Excellent");
    }
    else if(grade>=75 && grade<85)
    {
        printf("V Good");
    }
    else if(grade>=65 && grade<=74)
    {
        printf("Good");
    }
    else
    {
        printf("FAIL !!!!!");
    }
    return 0;
}

int main()
{
    char grade;

    printf("Enter Grade \n");
    scanf("%c",&grade); //d

    if(grade=='a')
    {
        printf("Excellent")
    }
    else if(grade=='b')
    {
        printf("V Good")
    }
    else if(grade=='c')
    {
        printf("Good")
    }
    else if(grade=='d')
    {
        printf("fair")
    }
    else
    {
        printf("Wrong i/p");
    }
}

//////////////////////////////////
int main()
{
    int num;
    int container=0;

    do
    {
        printf("Enter Number \n");
        scanf("%d",&num); //10  20 50 -50 1000

        container+=num;
    }while(container<=100);

    printf("Container= %d",container); //1030
}


int main()
{
    int age;

    do
    {
        printf("Enter Age \n");
        scanf("%i",&age);  //30
    }
    while(age<18 ||  age>60);

    printf("Your age is %i",age); //30
}

/////////////////////////////////////////
//Magic Box

#include<stdio.h>
#include <stdlib.h>
#include <windows.h>

void gotoxy( int column, int line )
{
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ),coord);
}

int main()
{
    int col,row;
    int size=3;

    row=1;
    col=size/2+1;

    for(int i=1;i<=size*size;i++)
    {
        gotoxy(col,row);
        printf("%d",i); //2
        if(i%size!=0)
        {
            row--;
            col--;
            if(col<1){col=size;}
            if(row<1){row=size;}
        }
        else
        {
            row++;
            //useless
            //if(row>size){row=1;}
        }
    }

    return 0;
}


