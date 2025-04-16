//Scanf cont'd
//Buffer
//Loops
//Conditions
//Magic Box
////////////////////////////////////////////////////////
//turnary operator ---> search
////////////////////////////////////////////////////////
//goto -> forbidden keyword
////////////////////////////////////////////////////////
// //scanf("format specifier of whats written till Enter",Address of variable to put value into it);
// int abc=33;
// scanf("%i",abc); //BIG WRONG //NOT Compile Error //runtime Error
// //DON'T FORGET
// scanf("%i",&abc);
// //o/p -> 1000

///////////////////////////////////////////////////////

#include<stdio.h>
int main()
{
    int x;
    int y;
    printf("Enter value of x\n");
    scanf("%i",&x);

    printf("Enter value of y\n");
    scanf("%i",&y);

    printf("value of x is %i",x);
    printf("value of x is %i",y);
    return 0;
}

///////////////////////////////////////////

#include<stdio.h>
int main()
{
    int x;
    char ch;

    printf("Enter value of ch\n");
    scanf("%c",&ch);

    printf("Enter value of x\n");
    scanf("%i",&x);

    printf("value of x is %i",x);
    printf("value of x is %i",y);
    return 0;
}
///////////////////////////////////////////////
//NOT WORK PROPERLY
int main()
{
    int x;
    char ch;

    printf("Enter value of x\n");
    scanf("%i",&x);

    printf("Enter value of ch\n");
    scanf("%c",&ch);  //Unreachable code

    printf("value of x is %i",x);
    printf("value of x is %i",y);
    return 0;
}

/////////////////////////////////////////

//Use _flushall() to clear buffer
//always use _flushall()
//with small value after big value
//double ??? int
//float  ??? int
//char int  -> no need 
int main()
{
    int x;
    char ch;

    printf("Enter value of x\n");
    scanf("%i",&x);
    //
    _flushall();
    printf("Enter value of ch\n");
    scanf("%c",&ch);

    printf("value of x is %i",x);
    printf("value of x is %i",y);
    return 0;
}
////////////////////////////////////////////////////
//NOOO
scanf("%i",&abc);
/////////////////////////////////////////////////////
///if
//if(condition)
//{
    //code executed if condition is true
//}


//if(condition)
//{
    //code executed if condition is true
//}
//else
//{
    //code executed if condition is false
//}

int main()
{
    int x;

    printf("Enter x\n");
    scanf("%i",&x);  //22

    if(x%2==0)
    {
        printf("even number");
        printf("%i is even number",x);
    }
    else
    {
        printf("odd number")
    }
}


int main()
{
    //>85 A
    //75> <84 B
    int grade;
    printf("Enter grade\n");
    scanf("%i",&grade);  ///555

    if(grade >=85)
    {
        printf("A");
    }
    else if(grade>=75 && grade<85)
    {
        printf("B");
    }
    else if(grade>=65&& grade<75){
        printf("C");
    }
    else
    {
        printf("Invalid input !!!");
    }
}


int main()
{
    int x;
    if(x==22)
    {
        printf("Hello");
    }
    if(x>10)
    {
        printf("morning");
    }
    if(x%2==0)
    {
        printf("Bye");
    }
}

///////////////////////////////////
int main()
{
    int month;
    printf("Enter month\n");
    scanf("%i",&month);  ///18

    if(month==1){printf("Jan");}
    else if(month==2){printf("Feb");}
    else if(month==3){printf("Mar");}
    else if(month==4){printf("Apr");}
    else if(month==5){printf("May");}
    else{printf("Invalid");}

}

//if with specific values
//is not recommended
//execte more time

///////////////////////////////////////////////
int main()
{
    int x=4;
    if(x)
    {printf("Right");}
    else
    {printf("Wrong");}
    //right

    int x=4;
    if (x=55)
    {
        printf("Right");
        printf("%i",x);
    }else
    {printf("Wrong");}
    //no error
    //right 55

    int x=0;
    if (x)
    {
        printf("Right");
    }else
    {printf("Wrong");}
    //WRONG

    int x=22;
    if (x=0)
    {
        printf("Right");
    }else
    {printf("Wrong");}
    //wrong

}

///////////////////////////////////////////////
//switch
//switch is recommended with check specific values 
//switch can be used with char,int ONLY

///syntax
switch (variable)
{
    case value1:
    //code
    break;
    case value2:
    //code
    break;
    case value3:
    //code
    break;
    default:
    //code
    break;
}

int main()
{
    int month;
    printf("Enter month\n");
    scanf("%i",&month);//5

    switch(month)
    {
        case 1:
            printf("Jan");
            //
            //
            //
        break;
        case 2:
            printf("Feb");
        break;
        case 3:
            printf("Mar");
        break;
        case 4:
            printf("Apr");
        break;
        case 5:
            printf("May");
        break;
        default:
            printf("Not VALID !!!");
        break;
    }
    //
    //  
}
int main()
{
    char grade;
    printf("Enter grade\n");
    scanf("%c",&grade);//B

    //o/p
    //V good
    //Good
    //fair

    switch(grade)
    {
        case 'A':
        printf("Excellent");
        break;
        case 'B':
        printf("V Good");
        //break; //code will fall through another one
        case 'C':
        printf("Good");
        //break;
        case 'D':
        printf("Fair");
        break;
        case 'F':
        printf("Fail");
        break;
        default:
        printf("Wrong Input !!!");
        break;
    }
}

///////////
int main()
{
    char grade;
    printf("Enter grade\n");
    scanf("%c",&grade);//B  //b

    //o/p
    //V good
    //Good
    //fair

    switch(grade)
    {
        case 'A':
        case 'a':
        printf("Excellent");
        break;
        case 'B':
        case 'b':
        printf("V Good");
        break; 
        case 'C':
        case 'c':
        printf("Good");
        break;
        case 'D':
        printf("Fair");
        break;
        case 'F':
        printf("Fail");
        break;
        default:
        printf("Wrong Input !!!");
        break;
    }
}
///////////////////////////////////////////////

// //print hello PD 5 times
// printf("Hello PD");
// printf("Hello PD");
// printf("Hello PD");
// printf("Hello PD");
// printf("Hello PD");

//Copy & paste 
//bad programming
//effort redundant

//write once and execute more

// //for loop
// for(initial value;condition[true] ;increment/decrement)
// {
//     //code
// }


int main()
{
//       #1      #2#5  #4
    for(int x=1; x<6 ;x++)
    {
        //#3
        printf("Hello PD\n");
    }

    //memory x 1 2 3 4 5 6
    //o/p
    //Hello PD
    //Hello PD
    //Hello PD
    //Hello PD
    //Hello PD


    for(int i=1 ;i<=10 ;i++){}

    for(int i=10 ;i>0 ;i--){}


    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            printf("%i,%i\n",i,j);
        }
    }

    //memory i01  j01234 0
    //o/p
    //0,0
    //0,1
    //0,2
    //0,3
    //1,0
}

//////////////////////////////////////////////////
//loop non specific number of times
//do- while
//while

// do
// {
//     //code here
// }
// while(condition true);

int main()
{
    int num;
    int container=0;

    do
    {
        printf("Enter num");
        scanf("%i",&num); //120
        container+=num;

        //printf("%i\n",container);
    }
    while(container<100);

    printf("%i\n",container); //120

}
///////////////////////////////////////////
//while

while(condition)
{
    //code here
}

int main()
{
    int num;
    int container=0;

    while(container<100)
    {
        printf("Enter num");
        scanf("%i",&num); //120
        container+=num;
    }

    printf("%i\n",container); //120

}

///////////////////////////////////////////

//do while is applicable
//when we need input to check it

///program to check entered number is even or odd

///
/////////////////////////////////////////////
//restrict user to enter age>18 age<60
int main()
{
    int age;


    do
    {
        printf("Enter age >18 and <60");
        scanf("%i",&age); //22
    }while(age<18 || age>60);

    printf("age is %i",age); //22


    int evenNum;
    do
    {
        printf("Enter evenNum");
        scanf("%i",&evenNum); //22
    }while(evenNum%2!=0);

    printf("evenNum is %i",evenNum); //22
}

///////////////////////////////////////////////

//Magic Box

#include <stdlib.h>
#include <stdio.h>
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
    int size=3;
    int col;
    int row;

    row=1;
    col=size/2+1;

    for(int i=1;i<=size*size;i++)
    {
        gotoxy(col*3+8,row*3+8);
        printf("%i",i);
        //check before increment
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
            //if case is useless
            //if(row>size){row=1;}
        }
    }
}


//////////////////////////////////////////////////////
//Lab Assignments

////////////////////
///1,3,5,7,8,10,12     31days
///4,6,9,11           30 days
///2      28,29 leap year    2000,2004,2008,2020


///while ->   do while

///1- Birthdate
///plz enter your year from 1980->2023
1900
///plz enter your year from 1980->2023
1910
///plz enter your year from 1980->2023
2020
///plz enter your month 1-12
22
///plz enter your month
23
///plz enter your month
2
///plz enter your day
30
///plz enter your day
32
///plz enter your day
32
///plz enter your day
29
///plz enter your day
28

///you're 22y  3 months and 5 days

int currentday=9;
int currentmonth=10;
int currentyear=2023;

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
//+

//5+10=15
//Continue ??? y or n 
//n

//program end











