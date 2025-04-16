///c language keywords is lower case
///int main float  DoubleXXXX

///c lang. is case sensitive
//int x=3;int y=33;int z=55;
//int X=3;


//Skeleton of C
///file.c
///1-Preprocessing
#include<stdio.h>  //console   read & write in console
#include<math.h>
//#define Later

///2-Global Declaration
///global variable
///function
///struct

///3- Entry point
int main()
{
    ///4-local declaration 
    ///local variable
    ///processing
    ///operators   5/0   prog. returns -65432345654

    ///5-end of program
    return 0; //when program return zero 
    //,it means program runs successfully  
}

///6- c is case sensitive   =>  x !=X  
///int x=2;
///int X=3;

///7- c keywords is small letter 

//////////////////////////////////////////////////////////
///program to print hello PD and OS MNF
#include<stdio.h> //printf()

int main()
{
    int age=50;
    //printf("Hello SD , Hello OS");
    printf("Hello SD\t");
    printf("Hello OS\n");
    printf("age =22");
    return 0;
}
//o/p
//hello SD  Hello OS
//age=22



//\n new line
//\t tab

////////////////////////////////////////////////////////////
///program to print your age
#include<stdio.h>
int main()
{
    char ch='A';
    int age=55;
    
    //printf("Your age is 22"); //XXXX
    printf("Your age is %i",age); 
    //o/p
    ///your age is 55

    printf("Your character is %c",ch);
    //o/p
    //your character is A 

    float y=1.2;
    printf("y is %f",y);
    //o/p
    //y is 1.2

    //print all variables is single printf
    printf("age=%i , ch=%c , y=%f",age,ch,y);

    return 0;
}
//o/p

///format specifier
///%d,%i  => integer
///%f  float
///%c  char
///%x  hexa
///%o  octal
///%s  string  later
///%lf   double   
///%l    long
////////////////////////////////////////////////////////////
//print decimal,octal ,hexadecimal for number
#include<stdio.h>

int main()
{
    int num=10;

    printf("Decimal for number is %i",num);
    printf("octal for number is %o",num);
    printf("HexaDecimal for number is %x",num);

    printf("Decimal for number %i is %i",num,num);


    return 0;
}


/////////////////////////////////////////////////////////////
//character and print ascii
#include<stdio.h>
int main()
{
    char ch='M';  //77
    float y=1.2;
    
    printf("Character is %c",ch); //M
    printf("ASCII is %i",ch); //77

    return 0;
}

//o/p 

/////////////////////////////////////////////////////////
//Later to be discussed [Address]
#include<stdio.h>
int main()
{
    int x=22;
    char ch='M';

    printf("Address of x in ram is %x",&x); //0x22
    printf("Address of ch in ram is %x",&ch); //0x55

    return 0;
}





////////////////////////////////////////////////////////////
///program to print hexa and octal and decimal for number

#include<stdio.h>
int main()
{
int b = 5;
printf("Result: %d  ", ++b);                   // الناتج: 6
printf("New value of b: %d ", b);            // الناتج: 6

    
    return 0;
}

///////////////////////////////////////////////////////////
///operators
///1- arithmatic operators
    ///A. Binary arithmatic operator  +,-,*,/,%
    int x=3,y=4;
    int z;
    z=y%x;
    printf("%i",x); //3
    printf("%i",y); //4
    printf("%i",z); //1

    ///B. Unary Operator  ++,--  increment/decrement by 1
        ///variable++ => POSTFIX
        ///++Variable => PREFIX

        int x=3;
        int z;
        //x++;
        //printf("%i",x); //4

        // ++x;
        // printf("%i",x); //4

        // z=x++; //execution #1 z=x  #2x++
        // printf("%i",x); //4
        // printf("%i",z); //3

        // printf("%i",x++); //3 x in memory 4
        // printf("%i",x); //4
        // //o/p 3

        z=++x;
        printf("%i",x); //4
        printf("%i",z); //4


//REMEMBER
int x=1,z;
z=x+1;
//print x 1
//print z 2
z=++x;
//print x 2
//print z 2


//////////////////////////
///2-Compound Operator +=,-=,*=,/=,%=    ==XXXX
int x=3,y=4,z=5;

x+=y; //x=x+y
x*=y; //x=x*y

//////////////////////////

///3- Comparison operator >,<,>=,<=,==,!=   //1 for true  //0 for false
int x=3,y=4,z=5;

//x>y  
//when true => 1
//when false =>0
printf("%i",x>=y); //1


///4-Logical operator &&,||    Later,<<,>>,&,|,!
int x=3,y=4,z=5;

printf("%d",x>y&&y<z&&x<z);  //0
//&& return 1 if all braches are 1
//&& returns 0 if ANY branch is 0

printf("%d",x<y||y>z||x>z);  //1
//|| return 0 if all braches are 0
//|| returns 1 if ANY branch is 1



/////////////////////////////////////////////////////////

//read input from user in runtime   stdio.h--> scanf

#include<stdio.h>  //printf()   //scanf()
int main()
{
    int age=22;
    printf("your age is %i",age);
    return 0;
}
//o/p
//age is 22

//o/p
//please enter your age
//21 Enter
//your age is 21

////
scanf("format for what you'll write",address of variable that value will put in);
////

#include<stdio.h>

int main()
{
    int age=123;

    printf("Plz enter your age\n");
    //scanf("%i",age); ///runtime error
    scanf("%i",&age); //77


    //scanf
    //read stream of characters from user in runtime
    //untill press enter
    //you must specify format of input 
    //when press enter 
    //then you must specify address of variable 
    //to put value into it

    printf("Your age is %i",age);


    char ch;
    printf("Enter ch\n");
    scanf("%c",&ch);
    printf("Ascii is %i",ch);

    float y;
    printf("Enter y\n");
    scanf("%f",&y);

    return 0;
}




//NOT RECOMMENDED
int age,salary;
printf("plz enter age\n");
scanf("%i%i",&age,&salary);  //33Enter44Enter
scanf("%i %i",&age,&salary);  //33 44 enter
scanf("%i,%i",&age,&salary);  //33,44 enter
scanf(" %i",&age);  //33
scanf("enter age %i",&age);  //33

//REMEMBER
scanf("%i",&age);

///////////////////////////////////////////////////////////

//not standard
/*void main(void)
{

}*/

int main()
{
    //code here
    //Error  return will be different

    //std for c when return 0 , it indicates to o.s this program
    //runs good
    return 0;    
}

--------------------------------------------------------


#include<stdio.h>

int main()
{
    printf("Hello Intro to Programming");


    return 0;
}


--------------------------------------------------------------
#include<stdio.h>
int main()
{
    int age=22;

    printf("your age is");
    printf(age);
    //your age is
    return 0;
}

///format specifier c
///when read or write variable , 
///you must tell o.s the type of this variable

///%d   %i   int
///%f     float
///%c     char
///%x    Hexadecimal
///%o    octal
//..
//...


#include<stdio.h>
int main()
{
    int age=22;

    printf("your age is");
    printf(" %i",age);
    //your age is 22
    return 0;
}


#include<stdio.h>
int main()
{
    int id=1;
    int age=22;

    printf("Your id is %d",id);
    printf(",Your age is %i",age);
    
    printf("Your Id is %d, Your age is %d",id,age);


    //your id is 1,your age is 22


    //\n new line
    //\t tab
    printf("Your Id is %d \n Your age is %d",id,age);

    //your id is 1
    //your age is 22


    printf("Your Id is %d \t Your age is %d",id,age);
    //your id is 1    your age is 22
    return 0;
}


////////////////////////////////////////////////

#include<stdio.h>
int main()
{
    //hexa  1,2,3,4,5,6,7,8,9,A,B,C,D,E,F,
    int x=10;

    printf("x is %i",x);
    //x is 10
    printf("x in hexa is %x",x)
    //x in hexa is A
    return 0;
}

------------------------------------
#include<stdio.h>
int main()
{
    char ch='M';

    printf("ch is %c",ch);
    //ch is M

    printf("ch ascii is %d",ch);
    //ch ascii is 77


    //
    int x=109;
    printf("ascii of 109 is %c",x);
    //


    return 0;
}

--------------------------------------
//Read in console
//scanf()
//scanf can take value and put is in the address of the variable
//When er press enter

///int x=10;    //in address
///&x address of x
///printf("%x",&x);  print address of x in hexa  0xF2
#include<stdio.h>

int main()
{
    int age;   //save variable named x 4Byte in address 0x345

    //printf("%d",age);  //Rubbish exists in that address

    printf("Plz Enter your Age\n");
    //scanf("%d",age);  //Runtime Error
    scanf("%d",&age);  
     //22 enter

    printf("your age is %i",age);


    return 0;    
}


-------------------------------------------
#include<stdio.h>
int main()
{
    int id,age;

    printf("Enter Id\n");
    scanf("%d",&id);
    printf("\nEnter Age\n");
    scanf("%d",&age);

    //not recommended
    //scanf("%d%d",&id,&age);

    ///clear screen
    clrscr(); //not standard
    system("cls");

    printf("ur id is %d\nYour age is %d",id,age);

    return 0;
}

///dont scanf with several datataypes
//int id
//scanf("%d",&id);
//float salary;
//scanf("%f",&salary);
///Buffer issue


////////////////////////////////////////////////////
///operators

///Arithmatic operator

//binary operator  + ,- ,*,/,%
int x=22;
int y=33;

int z=x+y;
print(x) //22
print(y) //33
print(z) //55

int z=x-y;
print(x) //22
print(y) //33
print(z) //-11

float z=x/y;
print(x) //1
print(y) //2
print(z) //0

int z=x%y;
print(x) //5
print(y) //3
print(z) //2


//unary operator  ++ , --

//variable++  postfix
//++variable prefix

int x=3;
int y=4;
int z=0;


//x++;
//++x;
//print(x); //4


z=x++;
print(x); //4
print(z); //3


print(x++); //3
print(x++)  //4
print(x)//5



z=++x;

print(x); //4
print(z); //4


int x=10;
print(++x);  //11


///aware
int x=1,y=2;
//int z=x+1;
//Different
int z=++x;
print(x) //2
print(z) //2
------------------------------------------------
//assignment operator =,+=,-=,*=,/=,%=    [== XXXXX]

int x=2,y=3;

x+=y;  //x=x+y;

----------------------------------------------------
//relational operator > ,< ,>= ,<= ,==,!=

// true =>1   , false=> 0


int x=1,y=2,z=1;

print(x>y)  //0
print(x>z)  //0
print(x>=z)  //1


//logical operator  &&,||
// true =>1   , false=> 0

//&& return 1[true] if all branches must be true
//if one branch is 0[false]  then all is 0[false]
int x=1,y=2,z=1;

print(x>y && y>z && z>x);  //0
print(x<y && y>z && z==x);  //1


//|| return 1[true] if one branch is true
//return 0 [false] if ALL Branches must be false
print(x<y || y>z || z>x);  //1
print(x>y || y<z || z!=x); //0


///////////////////////////////////////////////////////////


///Lab Assignments @12:30    Each in separated Projects
//1- print Hello World
//2- read Number and print hexadecimal of #
//3- read character and print ascii code


//4-[learn] read # from user and print address of this variable 
int z=22;
printf("%i",z); //22
printf("%x",&z); //&variable =>address of variable
