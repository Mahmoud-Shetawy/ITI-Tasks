//Scanf cont'd
//Buffer
//Loops
//Conditions
//Magic Box
//array
////////////////////////////////////////////////////////
//turnary operator ---> search
////////////////////////////////////////////////////////
//goto -> forbidden keyword
////////////////////////////////////////////////////////
// //scanf
//("format specifier of whats written till Enter",Address of variable to put value into it);
// int abc=33;  memory abc |33| 0x44
// scanf("%i",abc); //BIG WRONG //NOT Compile Error //runtime Error
// DON'T FORGET
// scanf("%i",&abc);
///////////////////////////////////////////////////////
#include<stdio.h>
int main()
{
    int x,y;
    printf("Enter x \n");
    scanf("%i",&x);
    printf("Enter y \n");
    scanf("%i",&y);

    printf("x=%i,y=%i",x,y);
    return 0;
}
//////////////////////////////////////////////
#include<stdio.h>
int main()
{
    char ch1,ch2;

    printf("Enter ch1 \n");
    scanf("%c",&ch1);
    printf("Enter ch2 \n");
    scanf("%c",&ch2);
    return 0;
}

////////////////////////////////////////////
#include<stdio.h>
int main()
{
    int x;
    char ch;

    printf("Enter ch \n");
    scanf("%c",&ch);
    printf("Enter x \n");
    scanf("%i",&x);
    return 0;
}

////////////////////////////////////////////////
#include<stdio.h>
int main()
{
    int x;
    char ch;
    printf("Enter x \n");
    scanf("%i",&x);
    printf("Enter ch \n");
    //clear buffer
    _flushall();
    scanf("%c",&ch); 
    return 0;
}
///////////////////////////////////////////////
//REMEMBER
///with scanf's with different data types
///REMEMBER USE _flushall()
/////////////////////////////////////////////// 


///if(condition)
///{
    ///code here if condition is 1[true]
///}

///if(condition)
///{
    ///code here if condition is 1[true]
///}
///else
///{
    ///code here if condition is 0[false]
///}


///if(condition)
///{
    ///code here if condition is 1[true]
///}
///else if(condition)
///{
    ///code here if condition is 1[true]
///}
///else if(condition)
///{
    ///code here if condition is 1[true]
///}
///else
///{
    ///code here if condition is 0[false]
///}


///if(condition)
///{
        ///if(condition)
        ///{
            ///code here if condition is 1[true]
        ///}
///}

///if(condition)
///{
    ///code here if condition is 1[true]
///}
///if(condition)
///{
    ///code here if condition is 1[true]
///}
///if(condition)
///{
    ///code here if condition is 1[true]
///}

////////////////////////////////////////////////
#include<stdio.h>
int main()
{
    int grade;
    printf("Enter grade \n");
    scanf("%i",&grade);

    if(grade>=85)
    {
        printf("A");
    }
    else if(grade>=75 && grade<85)
    {
        printf("B");
    }
    else if(grade>=65 && grade<75)
    {
        printf("C");
    }
    else
    {
        printf("NA");
    }

    return 0;
}
///////////////////////////////////////////////
int main()
{
    int  month;
    printf("Enter month \n");
    scanf("%i",&month); //13

    if(month==1)
    {
        printf("Jan");
    }
    else if(month==2)
    {
        printf("F");
    }
    else if(month==3)
    {
        printf("Ma");
    }
    else if(month==4)
    {
        printf("Ap");
    }
    else
    {
        //NA <<<<
    }
}

///if condition with specific value is not recommended
///switch

int main()
{
    int x;
    //printf   -8765434567
    if(x=3)
    {
        printf("T",); 
    }
    else
    {
        printf("F");
    }
}
////////////////////////////////////////////////////////
///switch
///alternative way for if with specific values
//not range

//switch is applicaple with char,int ONLY

//switch(variable)
//{
    ///case value1:
    ///code
    ///break;
    ///case value2:
    ///code
    ///break;
    ///case value3:
    ///code
    ///break;
    ///case value4:
    ///code
    ///break;
    ///default:
    ///code
    ///break;
//}

//////////////////////////////////
int main()
{
    int month;
    printf("Enter month \n");
    scanf("%i",&month); //1
    //o/p
    //jan
    //Feb
    switch(month)
    {
        case 1:
        printf("Jan");
        break;  //fall through
        case 2:
        printf("Feb");
        break;
        case 3:
        printf("Mar");
        break;
        case 4:
        printf("Apr");
        break;
        default:
        printf("NA");
        break;
    }
    //
}

int main()
{
    char grade;
    printf("Enter grade \n");
    scanf("%c",&grade); //A  
    switch(grade)
    {
        case 'a':
        case 'A':
        printf("Exce...");
        break;
        case 'b':
        case 'B':
        printf("VG");
        break;
        case 'C':
        case 'c':
        printf("g");
        break;
        default:
        printf("NA");
        break;
    }
}

/////////////////////////////////////////////
///hello MNF
///hello MNF
///hello MNF
///hello MNF
///hello MNF

//Copy & paste  -> bad programming
//effort redundant

//for(initial value;contition [true];increment/decrement)
//{
//code executed if condition 1
//}

int main()
{
        //      #5  
        //#1    #2   #4
    for(int i=1;i<6;i++)
    {
        //#3
        printf("Hello MNF\n");
    }
    //
}
//memory i 1 2 3 4 5 6

//o/p
//Hello MNF
//Hello MNF
//Hello MNF
//Hello MNF
//Hello MNF

//////////////////////////////////
//nested for loop
int main()
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            printf("%i,%i\n",i,j);
        }
    }
    //memory i 0 1  j 0 1 2 3 4 0
    //o/p
    //0,0
    //0,1
    //0,2
    //0,3
    //1,0

}

///////////////////////////////////////////////////
//loop non specific # of times
//do- while
//while

//do
//{
///code here
//}
//while(condition 1);

int main()
{
    int container=0;
    int num;

    do
    {
        printf("Enter #\n");
        scanf("%i",&num); //800
        container+=num; //860
    }
    while(container<=100);
    printf("container=%i",container); //860
}

//restrict read age from user between 18 and 60 
int main()
{
    int age;
    //scanf
    //while(age>18 age>60)
    {
        //scanf
    }

    do
    {
        printf("Enter age\n");
        scanf("%i",&age); //25
    }
    while( age<18 || age>60);
    printf("your age is %i",age);


    int evenNum;
    do
    {   
        printf("Enter even #\n");
        scanf("%i",&evenNum);
    }
    while(evenNum%2!=0);
    //
}

////////////////////////////////////////////
//while(condition)
//{
//code here
//}

int main()
{
    int container=0;
    int num;

    while(container<=100)
    {
        printf("Enter #\n");
        scanf("%i",&num); //800
        container+=num; //860
    }
    printf("container=%i",container); //860
}

//////////////////////////////////////////////////\
//Magic Box

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void gotoxy( int column, int row )
{
    COORD coord;
    coord.X = column;
    coord.Y = row;
    SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ),coord);
}

int main()
{
    int size; //=-6464151445
    printf("Enter box size\n");
    scanf("%i",&size);
    int col=size/2+1;
    int row=1;

    for(int i=1;i<=size*size;i++)
    {
        gotoxy(col,row);
        printf("%i",i);
        //check coordinates to put new number
        if(i%size!=0)
        {
            row--;
            col--;
            if(row<1){row=size;}
            if(col<1){col=size;}
        }
        else
        {
            row++;
            //if(row>size){row=1;} //never happened
        }
    }

    return 0;
}

/////
int main()
{
    int size; //=-6464151445
    printf("Enter box size\n");
    scanf("%i",&size);
    int col=size/2+1;
    int row=1;
    system("cls"); //clear screen
    for(int i=1;i<=size*size;i++)
    {
        gotoxy(col*3,row*3);
        printf("%i",i);
        //check coordinates to put new number
        if(i%size!=0) //reminder exists
        {
            row--;
            col--;
            if(row<1){row=size;}
            if(col<1){col=size;}
        }
        else //no reminder
        {
            row++;
            //if(row>size){row=1;} //never happened
        }
    }

    return 0;
}


//////////////////////////////////////////////
///Lab Assignments

////////////////////
///1,3,5,7,8,10,12     31days
///4,6,9,11           30 days
///2      28,29 leap year    2000,2004,2008,2020,2024 


///while ->   do while

///1- Birthdate
///plz enter your year from 1980->2023
1900
///plz enter your year from 1980->2023
1900
///plz enter your year from 1980->2023
200
///plz enter your month 1-12
22
///plz enter your month
23
///plz enter your month
4
///plz enter your day
31
///plz enter your day
32
///plz enter your day
32
///plz enter your day
29
///plz enter your day
28

///you're 22y  3 months and 5 days

int currentday=16;
int currentmonth=10;
int currentyear=2024;

int day,month,year;

//2-magic box  3*3


///3- dynamic magic box based on input   not eveen nor 1

//plz enter odd size
2
//plz enter odd size
1
//plz enter odd size
44
//plz enter odd size
5
system("cls");  //clear screen



///3-Calculator
///plz enter #1
//2
//plz wnter #2
//3
//plz enter operator
//*

//2*3=6
//Continue ??? y or n 
//y Enter

///plz enter #1
//5
//plz wnter #2
//10
//plz enter operator
//_flushall()
//+

//5+10=15
//Continue ??? y or n 
//n

//program end














