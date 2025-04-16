///getch() ,getche()   => getchar()
///extended keys
///string
///Highlighted Menu
///struct
//////////////////////////////////////////////////////
//String:
//there is no DT Called string in C
//Despite there are many libraries 
//that can deal with string   <string.h>

we can create string by
create array of characters //|'A'|'l'|'i'|||||
/////////////////////////////////////////////////////
//program to read name and display it
//v1
#include<stdio.h>
int main()
{
    char name[30];  //30B //|#|#|#|...
    
    printf("Enter name\n");
    for(int i=0;i<30;i++)
    {
        scanf("%c",&name[i]);
    }
    //for loop to print name
    return 0;
}
//issue -> 30 iteration useless
//////////scanf can go with Enter
///o/p
//enter name
//MENTERoENTERhENTERaENTERmENTEReENTERdENTERENTERENTERENTERENTERENTER...

//v2
#include<stdio.h>
int main()
{
    char name[30];  //30B //|#|#|#|...
    char ch;
    printf("Enter name\n");
    for(int i=0;i<30;i++)
    {
        name[i]=getche();
    }
    //for loop to print name
    return 0;
}
//issue -> 30 iterators
///o/p
//enter name
//MohamedENTERENTERENTER+30
/////////////////////////////////////////////////////
//v3
#include<stdio.h>
int main()
{
    char name[30];  //30B //|#|#|#|...
    char ch;
    int i=0;
    printf("Enter Name\n");
    do
    {
        ch=getche();
        name[i]=ch;
        i++;
    }
    while(ch!=13); //compare with ascii
    name[i-1]='\0';
    //while(press any key except ENTER);
    //while(ch!=110);

    //print name
    //for loop 0-> 30 NOOO -> Rubbish
    i=0;
    while(name[i]!='\0')
    {
        printf("%c",name[i]);
        i++;
    }
    //->

    return 0;
}
//o/p
//enter name
//mohamedENTER
///////////////////////////////////////////////
//there is stadard terminator
//to use at end of string
//'\0'  [delimeter][string terminator][zero default value for chararter]

//when you finish your string
//YOU MUST PUT \0 at end of your string
/////////////////////////////////////////////////////
//v4   [best practice]
#include<stdio.h>
int main()
{
    char name[30];  //30B //|#|#|#|...
    char ch;
    int i=0;
    printf("Enter Name\n");
    while((ch=getche())!=13)
    {
        name[i]=ch;
        i++;
    }
    name[i]='\0';

    i=0;
    while (name[i]!='\0')
    {
        printf("%c",name[i]);
        i++;
    }
    return 0;
}
//v5
int main()
{
    char name[30];

    printf("Enter name");
    scanf("%s",name); //Ahmed ENTER
    //read stream of charachters from user 
    //untill press Enter
    //after press Enter
    //compiler will put characters to 
    //array names name + put \0 at end itself
    ///name |A|h|m|e|d|\0|||||||||

    printf("%s",name);
    //will print name till \0 
    //Ahmed
}

//v6
//<string.h>
//gets(address for array of characters)
////read stream of characters till press enter
////after press enter ,it puts \n at end of string
//puts(address for array of characters)
////will print name till \0 
#include<string.h>
int main()
{
    char name[30];
    printf("Enter name\n");
    gets(name);

    printf("Your name is \n");
    puts(name);
    return 0;
}

//////////////////////////////////////////////////
///REMEMBER: when declare aarray of characters
///////////Remember to put string terminator '\0'
//array of characters with default values
int main()
{
    char arr[30]={'A','l','i','\0'};
    char arr[30]={'a','b','d','e','l','r','a','h','','','',''};

    char arr[30]="Ali";    
    //compiler will put character by character
    //to proper index then put \0 itself
    char arr[30]="AbdelRahman";

    //REMEMBER when declare Array
    //Make sure it has a place for string terminator

    char name[7+1];  ///|||||||||||.........

}
////////////////////////////////////////////////////
//string.h functions
//strcpy(Larray of characters,Rarray of characters);
//strcat(Larray of characters,Rarray of characters);
//strlen(array of characters)
//int x=atoi(array of characters)
//float y=atof(array of characters)
//strcmp(array of characters,array of characters);
//strcmpi(array of characters,array of characters);
int main()
{
    char fname[10]="Ahmed";
    char lname[10]="Osama";
    char fullName[20];

    //fullName=fname; 
    //fullname itself address fst element of array
    fullName[0]=fname[0];
    fullName[1]=fname[1];
    fullName[2]=fname[2];
    fullName[3]=fname[3];
    fullName[4]=fname[4];
    fullName[5]=' ';
    fullName[6]=lname[0];

    strcpy(fullName,fname);
    strcat(fullName,' '); //WRONG
    strcat(fullName," "); 
    strcat(fullName,lname);

    puts(fullName);
    //ahmed osama

    printf("%i",strlen(fullName)); //11  //till \0
    //ahmed 10B


    char number[10]="22";
    int x=atoi(number);
    //printf %i x //22
    /////line editor  98765445677654

    //search
    strcmp("ahmed","Ali");
    strcmpi("ahmed","Ali");
    return 0;
}

//////////////////////////////////////////////////////
//store grade of 5 subjects for 20 stds
///100 variables ??? XXX
///1D array 20 variables
///2D Array  1 Variable

///STORING DATA FOR THE SAME DATA TYPE

/////issue
///store data for Employee
///int ssn
///char name[20]
///int age
///float salary

///??Question => Use Array???No
///Array can store data for same data type

//////////////////////////////////////////////////////////
//Struct:
///////Data type created with my own definitions
///////Data type can carry several
/////// unrelated Data types

//DTName=>
///employeeXXX
///EmployeesXXX
///employeesXXX
///Employee,Person,Student,Department
///struct DTName
//{
    //data fields
    //fst ltr is lower case
    //id,name,age,salary,fullName
//};

///Syntax
// struct [DataTypeName] 
// {
//     int ssn;
//     float salary;
//     char name[10];
//     //char fullName
//     //Data  //  Fields   //ONLY
// };

///
//General
//struct Name => fst letter must be capital letter
////////////////must represent by one   singularize ,NOT pluralize

//C
//struct MUST come before main ()
////////////////////////////////////////////////////////
#include<stdio.h>
struct Point
{
    int x;
    int y;
};
void printPoint(struct Point param)
{
    printf("(%i,%i)\n",param.x,param.y);
}
int main()
{
    //2 variables from point
    struct Point p1; //stack  //8B  p1 x|#| y|#|
    struct Point p2; //stack  //8B  p1 x|#| y|#|

    //any field is accessed by its variable name
    p1.x=3;
    p1.y=4;

    p2.x=5;
    p2.y=6;

    printf("%i",p1); //XXXXXXX
    printf("p1(%i,%i)\n",p1.x,p1.y); //(3,4)
    printPoint(p1); //pass VALUES  3,4
    printPoint(p2);
    return 0;
}
////////////////////////////////////////////////////
#include<stdio.h>
#include<string.h>

struct Employee
{
    int id;
    char name[10];
    int age;
    float salary;
};

void PrintEmployee(struct Employee param)
{
    printf("Employee Data is \n");
    printf("id=%i\n",param.id);
    printf("name=%s\n",param.name);
    printf("age=%i\n",param.age);
    printf("salary=%f\n",param.salary);
}

//ex1 one employee then print
int main()
{
    struct Employee e1; //22B  id|| name||||  age|| salary||
    e1.id=1;
    //REMEMBER
    //e1.name="Sara"; //name itself
    strcpy(e1.name,"Sara");
    e1.age=22;
    e1.salary=1234;
    
    PrintEmployee(e1); //pass VALUES 1,sara,22,1234

    return 0;
}

//ex2 one employee read and write
int main()
{
    struct Employee e1;
    printf("Enter id\n");
    scanf("%i",&e1.id);
    printf("Enter name\n");
    _flushall();
    gets(e1.name); //scanf("%s",e1.name);
    printf("Enter age\n");
    _flushall();
    scanf("%i",&e1.age);
    printf("Enter salary\n");
    _flushall();
    scanf("%f",&e1.salary);

    PrintEmployee(e1);
    return 0;
}

//ex3 array of 3 employees read and write
int main()
{
    struct Employee employees[3]; //Stack 66B

    for(int i=0;i<3;i++)
    {
        printf("Employee at index %i\n",i);
        printf("Enter id\n");
        scanf("%i",&employees[i].id);
        printf("Enter name\n");
        _flushall();
        gets(employees[i].name); //scanf("%s",employees[i].name);
        printf("Enter age\n");
        _flushall();
        scanf("%i",&employees[i].age);
        printf("Enter salary\n");
        _flushall();
        scanf("%f",&employees[i].salary);
    }

    for(int i=0;i<3;i++)
    {
        PrintEmployee(employees[i]);
    }
    return 0;
}

//ex4 array of 10 employees and choose index to enter

//employees |#|#|#|S|#|O|#|#|#|#|
///enter index 0->9
///3
///enter id 1
///enter name sara
///enter age 22
///enter Salary 1234

///continue y or n ?
//y
///enter index 0->9
///3 
////exist , overwrite y or n? y 
///enter id 1 
///enter name Osama
///enter age 23
///enter Salary 9999

///continue y or n ?
//n

//print All Employees ???No
//print entred data only

int main()
{
    struct Employee employees[10];
    int index;
    char ch;

    do
    {
        do
        {
            printf("Choose Index 0->9\n");
            scanf("%i",&index); 
        }while(index<0 || index>9);

        printf("Enter id\n");
        scanf("%i",&employees[index].id);
        
        printf("Enter name\n");
        _flushall();
        gets(employees[index].name); //scanf("%s",employees[index].name);
        
        printf("Enter age\n");
        _flushall();
        scanf("%i",&employees[index].age);
        
        printf("Enter salary\n");
        _flushall();
        scanf("%f",&employees[index].salary);

        _flushall();
        printf("Continue y or n\n");
        scanf("%c",&ch);  //y ENTER//press enter myself
        //ch=getch();
    }
    while(ch!='n');

    //print
    for(int i=0;i<10;i++)
    {
        if(/*employee Exists*/)
        {
            PrintEmployee(employees[i]);
        }
    }
    return 0;
}

//////////////////////////////////////////////////
//pass array to function
//Pass array with that way is NOT Standard
//void multiplyArrayByTen(int arr[5])
void multiplyArrayByTen(int arr[],int _size)
{
    //for loop
    arr[i]*=10;
}

int main()
{
    int arr[5]={1,2,3,4,5};
    multiplyArrayByTen(arr);
    multiplyArrayByTen(arr,5);
    return 0;
}

///Standard way to pass array to fn ???
///tomorrow


/////////////////////////////////////////////
///return array from fn
//compile Error
int[] TryMe()
{
    int arr[5]={1,2,3,4,5};
    return arr;
}

int main()
{

}

///Standard way to return array to fn ???
///tomorrow


///create variable carries address another variable
////Pointers


////////////////////////////////////////////////////////
//Lab Assignments

//1- array of 50 characters then print it reversly
    ///enter message
        ///my name is Mohamed
    //reversed message is
        ///demahoM si eman ym 

        ///enter msg
        ///Ahlan ya Moustafa
        ///afatsuom ay nalhA
    
//2- get first name,last name
    //from user
    //then put them into
    //fullname
    //strcpy
    //strcat


//struct employee
//{//ssn,name,age,salary,commission,deduction};

//print function(){}

//3-one employee read and write  name&netsalary

//4-array of 3 employees read and write

//5- array of 10 employees 
    //choose index whatever you want
    //when no continue
    //print entered employees only







