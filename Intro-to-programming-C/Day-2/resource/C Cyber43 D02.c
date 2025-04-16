//Scanf
//Loops
//Conditions
//Buffer
//Magic Box
////////////////////////////////////////////////////////
//goto -> forbidden keyword
////////////////////////////////////////////////////////
///print
//int x=22;
//char ch='M';
//Read input from user in runtime [app up and running]
///please enter x
///10 Enter
//the hexa of 10 is A
////////////////////////////////////////////////////////
//scanf
///read stream of characters from user 
///in runtime untill press enter
///when press enter , the value entered will bee assign 
///to the address you've written
///
////scanf("format specifier of what you wrote",Address of variable);
///
#include<stdio.h>
int main()
{
    //int x=22;
    //printf("%d",x);//22
    //printf("%x",&x);//0x10
    int x;
    printf("Plz enter value of x \n");
    scanf("%d",&x); //55 enter
    printf("value of x is %d",x); //value of x is 55
    
    char ch;
    printf("Plz enter value of ch \n");
    scanf("%c",&ch);
    printf("value of ch is %c",ch);
    
    ///BIG WRONG WITH SCANF
    int y=22;
    scanf("%d",y); //will cause runtime error
    //o/p
    //100 Enter
    scanf("Enter value of y %d",&y);
    scanf(" %d",&y);
    //o/p
    //space22 Enter
    //
    int z;
    int a;
    scanf("%d%d",&z,&a);  //right but not recommended
    //o/p
    //22 enter
    //33 enter

    //REMEMBER
    scanf("%d",&z);
    return 0;
}

//////////////////////////////////////////////////
//buffer

int main()
{
    int x;

    printf("Enter x \n");
    scanf("%d",&x);
}

int main()
{
    char ch;
    printf("Enter character \n");
    scanf("%c",&ch);
}

int main()
{
    int x;
    char ch;

    printf("Enter character \n");
    scanf("%c",&ch);


    printf("Enter x \n");
    scanf("%d",&x);
}

//ISSUE
int main()
{
    int x;
    char ch;
    
    printf("Enter x \n");
    scanf("%d",&x);


    printf("Enter character \n");
    scanf("%c",&ch);

    printf("Value of x is %d",x);
    printf("Value of ch is %c",ch);
}

//Solution => delete buffer
int main()
{
    int x;
    char ch;
    
    printf("Enter x \n");
    scanf("%d",&x);

    _flushall();
    printf("Enter character \n");
    scanf("%c",&ch);

    printf("Value of x is %d",x);
    printf("Value of ch is %c",ch);
}

//////////////////////////////////////////////
///c old versions
//restrict variable declaration on start of main
int main()
{
    int i;
    int x;
    printf("fdfdf");
    int y; //Compile Error
    for(i=0;;){}
}
//new version of c ==> declare anywhere
int main()
{
    int x;
    printf("fdfdf");
    int y; 
    for(int i=0;;){}
}
///////////////////////////////////////////////
//if with grade
int main()
{
    int grade;
    printf("Enter grade\n");
    scanf("%d",&grade); //
    if(grade>=85)
    {
        printf("A");
    }
    else if(grade>=75 && grade<85)
    {
        printf("B");
    }
    else if(grade>=65 && grade<=74)
    {
        printf("C");
    }
    else
    {
        printf("WRONG Input");
    }
}

/////////////////////////////////////
int main()
{
    char grade;
    printf("Enter Grade \n");
    scanf("%c",&grade); //C Enter

    if(grade=='A')
    {
        printf("Excellent")
    }
    else if(grade=='B')
    {
        printf("V Good"); 
    }
    else if(grade=='C')
    {
        printf("Good"); 
    }
    else
    {
        printf("Fail");
    }
}

//1 jan   2 feb
///if Condition with specific values is not RECOMMENDED
///switch

///if Practice
int main()
{
    int x=22;
    //
    if(x)
    {
        printf("Y");
    }
    else
    {
        printf("N");
    }

    //
    if(x=33)
    {
        printf("Y");  //Executed  x 33
    }
    else
    {
        printf("N");
    }

    //
    if(x=0)
    {
        printf("Y");
    }
    else
    {
        printf("N"); //Executed x 0
    }

    if(0)
    {
        //unreachable code
    }
}
///
////////////////////////////////////////////////////
///Switch
///switch can be applicable with int ,char ONLY

///[if condition] used in specific values is not recommended
//if(month==1) else if (month==2)
///switch
///switch with int , char only


///switch(variable) 44
//{
    //case value1:
        //code here
    //break;
    
    //case value2:
        //code here
    //break;
    
    //case value3:
        //code here
    //break;
    
    //case value4:
        //code here
    //break;
    
    //default:
        //code here
    //break;
//}


///////////////////////////////////////////////////
#include<stdio.h>
int main()
{
    int month;
    printf("enter month\n");
    scanf("%d",&month);// 3

    switch (month) //
    {
        case 1:
        printf("Jan");
        break;   
        case 2:
        printf("Feb");
        break;  
        case 3:
        printf("Mar");
        //break;  //fall through
        case 4:
        printf("Apr");
        //break; //fall through
        case 5:
        printf("May");
        break;
        default:
        printf("WRONG Input !!!");
        //break; //useless
    }
    //
    return 0;
}
//o/p
//3
//mar
//apr
//may

//////////////////////////////////////////

int main()
{
    char grade;

    printf("Enter Grade");
    scanf("%c",&grade);//b B

    switch (grade)
    {
        case 'A':
        case 'x':
        printf("Excellent");
        break;

        case 'B':
        case 'b':
        printf("V good");
        break;

        case 'C':
        case 'c':
        printf("Good");
        break;
    
        default:
        printf("NA");
        break;
    }
    return 0;
}

/////////////////////////////////////////////////
//copy and paste -> bad programming
//for loop
//to execute code many specific times times

///for(initial value;condition[true];increment/decrement)
//{
    //code here if condition is true
//}

int main()
{
    //    #1     #2#5   #4
    for(int i=1; i<6 ;i++)
    {
        //#3
        printf("Hello Cyber \n");
    }
    //memory i 1 2 3 4 5 6
    //o/p
    //Hello Cyber
    //Hello Cyber
    //Hello Cyber
    //Hello Cyber
    //Hello Cyber
    
    

    for(int i=10; i>0 ;i--)
    {

    }




    //10,9,8,7,6
    for(int i=10;i>5;i--)
    {
        //code
    }

    //more than initial value
    for(int i=0,j=0;i<11&&j<9 ;i++,j++)
    {

    }


    //Try It
    for(int i=5;i>0;i--);
    {
        //code
    }

    //Try It
    for(;;)
    {
        //code
    }


    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            printf("%d,%d\n",i,j);
        }
    }
    //memory i 0 1   j 0 1 2 3 4 0

    //o/p
    //0,0
    //0,1
    //0,2
    //0,3
    //1,0

    
    return 0;
}

//////////////////////////////////////////////

//loop unspecific # of times
//do-while
//while

//do
//{
    //code here
//}
//while(condition true);

int main()
{
    int num;
    int container=0;


    do
    {
        printf("Enter #\n");
        scanf("%d",&num); //150

        container+=num;
        //memory container 200
    }
    while(container<100);

    printf("%d" ,container); //200
}

//////////

int main()
{
    int age;   //>18 to <60
    ///while(age<=18||age>=60){}
    do
    {
        printf("Enter age\n");
        scanf("%d",&age); //50
    }while(age<=18 || age>=60);

    printf("Age is %d",age); //50

    int salary;  //>1200   <6000

    do
    {
        //print
        //scanf salary
    }while(salary<=1200 || salary>=6000);

}


///While
//While(Condition)
//{
    //Code executed if true
//}

int main()
{
    int num;
    int container=0;

    while (container<=100)
    {
        scanf("%d",&num);
        container+=num;
    }
    
}

//////////////////////////////////////////////////

///Magic Box
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
    int size=3;
    int col;
    int row;
    row=1;
    col=size/2+1;
    for(int i=1;i<=size*size;i++)
    {
        gotoxy(col,row);
        printf("%d",i);  //i 2 //col 1 row 3 
        //Check before increment
        if(i%size!=0)//there is a reminder
        {
            row--;
            col--;
            if(row<1){row=size;}
            if(col<1){col=size;}
        }
        else
        {
            row++;
            //
        }

    }
}

////////////////////////////////////////
//Search
///Turnary operator

///Lab Assignments

////////////////////
///1,3,5,7,8,10,12     31days
///4,6,9,11           30 days
///2      28,29 leap year    2000,2004,2008,2020


///while ->   do while

///1- Birthdate
///plz enter your year
2001
///plz enter your month
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

int currentday=28;
int currentmonth=11;
int currentyear=2022;

int day,month,year;

//2-magic box  3*3


///3- dynamic magic box   not eveen nor one

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

//n
