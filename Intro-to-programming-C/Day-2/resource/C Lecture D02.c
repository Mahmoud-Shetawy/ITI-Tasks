//hackerrank
//Scanf
//Loops
//Conditions
//Buffer
//Magic Box
///////////////////////////////////////////////////////
//Read data from user in runtime
//printf
int x=22;
char ch='A';
printf("value of x is %i",x);
printf("value of ch is %c",ch);


//[scanf] read stream of inputs from user in runtime untill press enter
//scanf("%i",address of variable);

//o/p
22

#include<stdio.h>
int main()
{
    int x=22,y=33;
    char ch;
    printf("Plz enter value of x \n");
    scanf("%i",x); ///BIG WRONG  compiler will put value in address 0
    scanf("%d",&x);// x=>value of x  , &x=> address of x
    
    //WRONG
    scanf(" %d",&x);// x=>value of x  , &x=> address of x
    scanf("%c",&x);// x=>value of x  , &x=> address of x
    scanf("enter x %d",&x);// x=>value of x  , &x=> address of x
    _flushall();
    scanf("%lf%d",&x);// x=>value of x  , &x=> address of x

    printf("Enter character\n");
    scanf("%c",&ch);

    
    return 0;
}
///////////////////////////////////////////////////////
//c not standard
//restrict declare variable in beginning of code
/*int main()
{
    int x;
    int i;
    printf("Ay 7aga");
    int y; ///XXXX Compile Error
    for(int j=5;;){}
}*/
///////////////////////////////////////////////////////
///if
//if(condition)
//{
    //code here executed if condition is true 1
//}

////////////////
//if(condition)
//{
    //code executed if true
//}
//else
//{  
    //code executed if false
//}

/////////////////85
///if(condition)
///{
    //code executed if true
///}
///else if (condition)
///{
    //code executed if this condition is true
//}
///else if (condition)
///{
    //code executed if this condition is true
//}
///else
//{
    //code executed if all branches is false
//}
/////////////////////////////////////////
//if(condition)
///{
    //code executed true
///}
//if(condition)
///{
    //code executed true
///}
//if(condition)
///{
    //code executed true
///}
////////////////////////////////////////
//if(condition 1)
//{
    //if(condition 1)
    //{}
    //else{}
//}
///////////////////////////////////////
//int x=10;
//if(x=0)
//{
    //Code Executed if true
//}
//else
//{
    //code executed if false
//}

///////////////////////////////////////
///85->100 A
///75->84  B
///65->74  C
///  F


#include<stdio.h>
int main()
{
    int grade;
    printf("Plz enter Grade\n");
    scanf("%d",&grade);//74

    if(grade>=85)
    {
        printf("A");
    }
    else if(grade>=75&&grade<84)
    {
        printf("B");
    }
    else if(grade>=65&&grade<75)
    {
        printf("C");
    }
    else
    {
        printf("Wrong Input");
    }
    return 0;
}



#include<stdio.h>
int main()
{
    int grade;

    printf("Plz Enter Grade");
    scanf("%i",&grade); //60

    if(grade>=85)
    {
        printf("A");
    }
    else if (grade>=75 && grade<85)
    {
        printf("B");
    }
    else if (grade>=65 && grade<=74)
    {
        printf("C");
    }
    else
    {
        printf("F");
    }

    return 0;
}

/////////////////////////////////////////////////

#include<stdio.h>
int main()
{
    char grade;//='A';

    printf("Enter Grade A,B,C,d or F");
    scanf("%c",&grade); //X      execute    excellent

    if(grade=='A')    // || grade=='a')
    {
        printf("Excellent");
    }
    else if(grade=='B')
    {
        printf("V Good");
    }
    else if(grade=='C')
    {
        printf("Good");
    }
    else if(grade=='D')
    {
        printf("Fair");
    }
    else if(grade=='F')
    {
        printf("Fail");
    }
    else
    {
        printf("WRONG INPUT !!!");
    }

    return 0;
}

////////////////////////////////////////////
#include<stdio.h>
int main()
{
    int grade =22;

    if(grade=33)  //normal assignment =
    {
        printf("Good"); //>>- Here
    }
    else
    {
        printf("WRONG"); 
    }

    return 0;
}
////////////////////////////////////////////////////////////
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
    printf("enter month");
    scanf("%i",&month);// 4

    switch (month) //4
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
        break;
    }
    //
    return 0;
}


//////////////////////////////////////////

int main()
{
    char grade;

    printf("Enter Grade");
    scanf("%c",&grade);//b B

    switch (grade)
    {
        case 'A':
        case 'a':
        printf("Excellent");
        break;

        case 'B':
        case 'c':
        printf("V good");
        break;

        case 'C':
        printf("Good");
        break;
    
        default:
        printf("NA");
        break;
    }
    return 0;
}


//////////////////////////////////////////////////////
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
    for(int i=1; i<6;  i++)
    {
        //#3
        printf("Hello SDUI \n");
    }
    //memory i 1 2 3 4 5 6
    //x 
    //o/p
    //Hello SDUI
    //Hello SDUI
    //Hello SDUI
    //Hello SDUI
    //Hello SDUI
    

    for(int i=10;i>0;i++)
    {

    }




    //10,9,8,7,6
    for(int i=10;i>5;i--)
    {
        //code
    }

    //more than initial value
    for(int i=0,j=0;i<11||j<9 ;i++,j++)
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
    //memory i 0 1  j 0 1 2 3 4 0

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
        scanf("%d",&num);

        container+=num;
    }while(container<=100);

    //10    10
    //70    80
    //-10   70
    //100   170  EXIT
}


int main()
{
    int age;  //From 18 to 60

    do
    {
        printf("Enter age\n");
        scanf("%i",&age); //22
    }
    while(age<18||age>60);

    printf("Your age is %d",age);
}




int main()
{
    int num;
    int container=0;

    do
    {
        printf("Enter number \n");
        scanf("%d",&num);

        container+=num;
    }
    while(container<=100);

    printf("Container = %d",container);

    //o/p
    //10     con10
    //50     con60
    //100    con160
    //done

}


int main()
{
    int num;
    int sum=0;

    do
    {
        printf("Enter #");
        scanf("%i",&num);
        sum+=num;

        //indicator
        printf("===>%d",sum);
    }
    while (sum<=100);
    printf("%d",sum);
    
    //o/p
    //enter # -1
    //===>-1
    //enter # 10
    //===>9
    //enter # 100
    //===>109
    //end
    

    ////enter # 200
    //===>200
    //end
    return 0;
}

////////////////////////////

int main()
{
    int evenNum;

    do
    {
        printf("Enter Even Number\n");
        scanf("%i",&evenNum); //6
    }
    while(evenNum%2!=0);

    //use it later
    printf("Even Number is %d",evenNum); //6

    return 0;
}


int main()
{
    int age;

    do
    {
        printf("Enter age bet 18 and 60\n");
        scanf("%d",&age); //20
    }
    while(age<=18 || age>=60);

    /*while(age<=18 || age>=60)
    {
        printf 
        scanf
    }*/

    printf("Your age is %d",age);
    return 0;
}



int main()
{
    int evenNum;

    do
    {
        printf("Enter Even Number");
        scanf("%d",&evenNum);
    }
    while (evenNum%2!=0);
    //system("cls");
    printf("Even Nums is %d",evenNum);

    //memory 
    //evenNum
    //o/p
    //Enter Even Num
    //13
    //Enter Even Num
    //11
    //Enter Even Num
    //22
    //Done
    return 0;
}

/////////////////////////////////
//while

//while(condition true)
//{
    //code here
//}


int main()
{
    int num;
    int container=0;

    while (container<=100)
    {
        printf("enter #");
        scanf("%i",&num);
        container+=num;
    }
    

    return 0;
}

///////////////////////////
////difference
///do while
///while


//-----------------------------------------------------------
//Buffer


int main()
{
    int x;
    printf("Enter x");
    scanf("%d",&x);

    printf("value of x is %d",x);
    return 0;
}


int main()
{
    char ch;
    printf("Enter ch");
    scanf("%c",&ch);

    printf("value of ch is %c",ch);

    return 0;
}


int main()
{
    char ch;
    int x;
    printf("Enter ch");
    scanf("%c",&ch);
    printf("value of ch is %c",ch);
    printf("Enter x");
    scanf("%d",&x);
    printf("value of x is %d",x);
    return 0;
}



int main()
{
    int x,y,z;
    scanf("%d",&x);
    scanf("%d",&y);
    scanf("%d",&z);
    return 0;
}

////REMEMBER
int main()
{
    char ch;
    int x;

    printf("Enter x");
    scanf("%d",&x);
    
    printf("Enter ch");
    _flushall();
    scanf("%c",&ch);    
    return 0;
}



///when use scanf
//when use it , the value you entererd is stored temporarily
//in place called buffer with same data type size
#include<stdio.h>
int main()
{
    int id;
    char grade;
    float salary;
    int age;
    printf("Enter Id\n");
    scanf("%d",&id);
    print("Enter grade");
    _flushall();  //clear buffer
    scanf("%c",&grade);
    printf("Enter Salary\n");
    scanf("%f",&salary);
    printf("Enter Age");
    _flushall();  //clear buffer
    scanf("%d",&age);  //XXXX
    printf("id=%d\nsalary=%f\nAge=%d\n",id,salary,age);

    return 0;
}
//memory id 1  salary 1000 
//o/p
//enter id
//1
//Enter Salary
//1000
//enter Age
//Skip
//id 1 
//salary 1000
//age rubbish


///////////Magic Box//////////////////////////
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
    int row,col;

    row=1;
    col=size/2 +1;

    for(int i=1;i<=size*size;i++)
    {
        gotoxy(col,row);
        printf("%d",i);
        //check for next iteration
        if(i%size!=0)
        {
            row--;
            col--;
            if(row<1)row=size;
            if(col<1)col=size;
        }
        else
        {
            row++;
            if(row>size)row=1; //useless
        }
        //
    }
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
        printf("%d",i);

        if(i%size!=0)
        {
            row--;
            col--;
            if(row<1){row=3;}
            if(col<1){col=3;}
        }
        else
        {
            row++;
            ///useless condition
            if(row>3){row=1;}
        }
    }

    return 0;
}








///////////OldMagic Box//////////////////////////
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
        gotoxy(col*3+6,row*3+6);
        printf("%i",i);
        //Checks before increment
        if(i%size!=0)
        {
            row--;
            col--;
            if(row<1){row=size;}
            if(col<1){col=size;}
        }
        else //if (i%size==0)
        {
            row++;
            //useless case
            if(row>size){row=1;}
        }
        //
    }

    return 0;
}


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
2000
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
23
///plz enter your day
28

///you're 22y  3 months and 5 days

int currentday=10;
int currentmonth=10;
int currentyear=2022;

int day,month,year;

//2-magic box  3*3


///3- dynamic magic box   not eveen and not one

//plz enter odd size
2
//plz enter odd size
1
//plz enter odd size
44
//plz enter odd size
5
system("cls");  //clear screen

