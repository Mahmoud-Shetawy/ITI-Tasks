///there is no DT Called string in C
///Array of character as a string
///Delimeter[String Terminator] is MUST '\0'
/////////////////////////////////////////////////
#include<stdio.h>
#include<string.h>
int main()
{
    int x=0;
    char name[30];
    ///read string from user in runtime
    //1- for loop => Not recommended
    //2-
    while ((ch=getche())!=13)
    {
        name[x++]=ch;
        //x++;
    }
    name[x]='\0';
    //3-
    scanf("%s",name);//scanf("%s",&name);
    //4-string.h   
    ///gets(array of character); like scanf %s
    ///read stream of characters from user
    ///in runtime untill user press Enter
    ///after thar it will fill in array
    ///plus string terminator
    gets(name);
    /////////////////////////
    ///Print string in o/p
    //1-
    x=0;
    while (name[x]!=13)
    {
        printf("%c",name[x++]);
    }
    //2-
    printf("%s",name);
    //3-string.h  
    //puts(array of characters)
    puts(name);  
    //print untill \0
}

/////////////////////////////////////////////
//string.h
int main()
{
    char fname[11+1];
    char lname[10+1];
    //ALWAYS Consider \0 in declare string
    printf("Enter fst name\0");
    scanf("%s",fname);
    printf("Enter lst name\0");
    gets(lname);

    printf ("name is %s %s",fname,lname);
    printf("name is");
    puts(fname);
    printf(" ");
    puts(lname);
}

///////////////////////////////////////////////////
///default values for array of characters
int main()
{
    char arr[30]={'a','l','i','\0'};
    char arr[30]={'a','b','d','e','l','\0','','',''};
    char arr[30]="Abdelrahman";
}
///default values for array of array of characters
///2D array of characters
int main()
{
    char arr[3][30];

    scanf("%s",arr[0]);
    scanf("%s",arr[1]);
    scanf("%s",arr[2]);

    arr[0][0]  //character
    scanf("%s",arr[0][0]); //XXXX
    scanf("%c",arr[0][0]); //T

    char arr[3][30]={{'a','l','i','\0'},{'s','a','r','a','\0'},{'s','\0'}};
    char arr[3][30]={"Sara","Ali","Omar"};
}

//REMEMBER
int main()
{
    char fname[30]="Sara";
   
    char fullname[30];
    fullname="Eman"; ///Compile Error //fullname itself address fst element of array 

    fullname=fname; //Compile Error [lvalue][fullname]
    ///fullname addres fst element of array
    ///fullname constant address
    ///fullname=0x30
}
////////////////////////////////////////////////
#include<string.h>
int main()
{
    char fname[10]="Ahmed"; //\0
    char lname[10]="Osama"; //\0
    char fullname[21];  //" "

    //strcpy(array of charactersLEFT,array of charactersRIGHT);
    //Assign characers from right to left
    strcpy(fullname,fname);
    //strcat(array of charactersLEFT,array of charactersRIGHT);
    //concat characers from right to left
    strcat(fullname," ");
    strcat(fullname,lname);
    
    //
    puts(fullname); //o/p ahmed osama

    //Traditional
    fullname[0]=fname[0];
    fullname[1]=fname[];
    fullname[2]=fname[2];
    fullname[3]=fname[3];
    fullname[4]=fname[4];
    fullname[5]=' ';
    fullname[6]=lname[0];
    //

}

///////////////////////////////////////////

int main()
{
    char arr[10]="33";
    ///string.h Functions
    //strcmp(Array of Char,Array of Char);
    //strcmpi(Array of Char,Array of Char);
    //strlen(array of character);
    //int atoi(Array Of Char)
    //float atof(Array Of Char)
    //int x=atoi(arr);
}
////////////////////////////////////////////
///Highlighted menu
#include<stdio.h>
#include <stdlib.h>
#include <windows.h>

#define EXTENDED -32
#define Up 71
#define down ?
#define Home ?
#define End ?
#define Enter ?
#define Esc ?


void gotoxy( int column, int line )
{
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ),coord);
}
void textattr(int i)
{   
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
}

int main()
{
    char menu[4][10]={"New","Display","Edit","Exit"};
    int cursor=0;
    int flag=1;
    char ch;
    do
    {
        //clear screen o/p
        system("cls");
        //
        for(int i=0;i<4;i++)
        {
            if(cursor==i){textattr(11);}
            else{textattr(7);}

            gotoxy(15,15+i*2);
            _cprintf("%s",menu[i]);
        }
        //read key from user
        ch=getch(); //Enter
        //
        switch(ch)
        {
            case EXTENDED:
            ch=getch();
            switch(ch)
            {
                case up:
                cursor--;
                if(cursor<0){cursor=3;}
                break;
                case down:
                cursor++;
                if(cursor>3){cursor=0;}
                break;
                case Home:
                cursor=0;
                break;
                case end:
                cursor=3;
                break;
            }
            break;
            case Enter:
            switch(cursor)
            {
                case 0:
                system("cls");
                printf("New Page");
                //wait untill see o/p
                getch();
                break;
                case 1:
                system("cls");
                printf("Disp Page");
                //wait untill see o/p
                getch();
                break;
                case 2:
                system("cls");
                printf("Edit Page");
                //wait untill see o/p
                getch();
                break;
                case 3:
                flag=33;
                break;
            }
            break;
            case Esc:
            flag=22;
            break;
        }
    }
    while(flag==1);
    

    return 0;
}

//REMEMBER
int main()
{


    ch=getch();
    switch(ch)
    {
        case NULL:
        ch=getch();
        switch(ch)
        {
            case up:
            break;
            case down:
            break;
        }
        break;
        case Enter:
        break;
        case Esc:
        break;
    }

    ch=getch();

    switch(ch)
    {
        case Null:
        ch=getch();
        switch(ch)
        {
            case up:
            //

        }
        break;
        case enter:
        break;

    }

}

//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
//store grade of 5 subjects for 20 stds
///100 variable ??? XXX
///1D array 20 variable
///2D Array  1 Variable

///STORING DATA FOR THE SAME DATA TYPE

/////issue
///store data for Employee
///int ssn
///char name[20]
///int age
///float salary

///??Question => Use Array???
///Array can store data for same data type

//////////////////////////////////////////////////////////
//Struct:
///////Data type created with my own definitions
///////Data type can carry several unrelated Data types

///Syntax

///struct Employee
//{//Filds};   

// struct [DatatypeName] 
// {
//     int ssn;
//     float salary;
//      char name[10];
//      char fullName[20];
//     //Data  //  Fields
// };

///
//General
//struct Name => fst letter must be capital letter
////////////////must represent by one   singularize ,not pluralize

//C
//struct MUST come before main ()

//////////////////////////////////////////////////////

#include<stdio.h>


struct Point
{
    int x;
    int y;
};
//
int DistanceBetTwoPoints
(struct Point left,struct Point right)
{
    return 33;
}
//
int main()
{
    //declare variable from Point
    struct Point p1,p2;  //8B   //stack p1  x# y#
    p1.x=3;
    p1.y=4;
    p2.x=5;
    p2.y=6;

    int dis=DistanceBetTwoPoints(p1,p2);
    //pass VALUES
    return 0;
}

////////////////////////////////////////////////
struct Employee
{
    int id;
    char name[10];
    int age;
    float salary;
};
//Function to Print Employee
void PrintEmployee(struct Employee param)
{
    printf("Id => %d\n",param.id);
    printf("Name => %s\n",param.name); //gets(param.name);
    printf("Age => %d\n",param.age);
    printf("Salary => %f\n",param.salary);
}
//

int main()
{
    struct Employee e1;  //22B
    e1.id=1;
    //e1.name="Sara"; //Compile Error
    strcpy(e1.name,"Sara");
    e1.age=22;
    e1.salary=1234;

    printf("Id => %d\n",e1.id);
    printf("Name => %s\n",e1.name); //gets(e1.name);
    printf("Age => %d\n",e1.age);
    printf("Salary => %f\n",e1.salary);
}


//Read Employee From user in runtime
int main()
{
    struct Employee e1;   //22B   id name age salary

    printf("Enter Id\n");
    scanf("%d",&e1.id);
    printf("Enter Name\n");
    _flushall();
    scanf("%s",e1.name);
    
    _flushall();
    do{
        printf("Enter Age\n");
        scanf("%d",&e1.age);
    }while(e1.age<18||e1.age>60);

    printf("Enter Salary\n");
    _flushall();
    scanf("%f",&e1.salary);
    
    //Stack  e1  id 1 name sara age 22 salary 1234

    //Print Employee
    PrintEmployee(e1); //pass VALUES

}

//Array Of Employees Read& write
int main()
{
    struct Employee employees[3]; //66B

    for(int i=0;i<3;i++)
    {
        printf("Employee at index %d\n",i);
        printf("Enter Id\n");
        scanf("%d",&employees[i].id);
        printf("Enter Name\n");
        _flushall();
        scanf("%s",employees[i].name);
        
        _flushall();
        do{
            printf("Enter Age\n");
            scanf("%d",&employees[i].age);
        }while(employees[i].age<18||employees[i].age>60);

        printf("Enter Salary\n");
        _flushall();
        scanf("%f",&employees[i].salary);
    }

    //
    for(int i=0;i<3;i++)
    {
        PrintEmployee(employees[i]); //pass VALUES
    }
}

//Array of Employees & choose Index  ||||||
int main()
{
    struct Employee employees[5];
    int index;
    char ch;

    do
    {
        printf("Choose Index 0 to 4\n");
        scanf("%d",&index);

        printf("Employee at index %d\n",index);
        printf("Enter Id\n");
        scanf("%d",&employees[index].id);
        
        printf("Enter Name\n");
        _flushall();
        scanf("%s",employees[index].name);
        
        _flushall();
        do{
            printf("Enter Age\n");
            scanf("%d",&employees[index].age);
        }while(employees[index].age<18||employees[index].age>60);

        printf("Enter Salary\n");
        _flushall();
        scanf("%f",&employees[index].salary);

        printf("Continue y or n\n");
        //scanf or getch
        _flushall();
        scanf("%c",&ch);
    }
    while(ch=='y'||ch=='Y');

    for (int i = 0; i < 5; i++)
    {
        //chech if Employee at this index is entered
        PrintEmployee(employees[i]);
    }
    return 0;
}

/////////////////////////////////////////////////

void Swap(int left,int right)
{
    int tmp;
    tmp=left;
    left=right;
    right=tmp;
}

int main()
{
    int x=3,y=5;

    printf("Before Swap\n");
    printf("x=>%i",x); //3
    printf("x=>%i",y); //5
    Swap(x,y); //Pass VALUES 
    printf("After Swap\n");
    printf("x=>%i",x); //3
    printf("x=>%i",y); //5

    return 0;
}

/////////////////////////////
///Pass array is not supported for all versions of c
///Not Standard
void MultipleArrayByTen(int param[10])
void MultipleArrayByTen(int param[],int size)
{
    for (int i = 0; i < size; i++)
    {
        param[i]*=10;
    }    
}


///return array from function
///NOT SUPPORTed At ALLL
???? getArray()
{
    int arr[10];
    return arr;
}

int main()
{
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    MultipleArrayByTen(arr,10);
    return 0;
}


////////////////////////////////////////////////////
//Labs


///1-Read first name ,last name
///// then fill in container full name 
/////  and print it
//////strcat ,strcpy    fn[10]   ln[10]      fulln[21]
////// gets() puts()

///2- read string from user   char array[50]
///   then print it reversly
    //while();  Do it with while and read character by character
    ///Enter message
        /// my name is Mohamed
        ///demahoM si eman ym


        ///same array
        ///do it ya ali
        //ila ay ti od


///3- program to identify key ASCII  normal/extended  + ASCII # 
///4- Highlighted menu


//Struct Employee
//id
//name
//age
//salary
//commission
//deduction

//netsalary


//4- one Employee read and write

//5- three Employees read and write

//6- 10 employees with highlighted menu
///Array => Global Variable [Leakage]
#include<stdio.h>
#define Enter 13
//gotoxy
//textattr
struct Employee{};
//
struct Employee Employees[10];
//
int main()
{
    
}




