//Arrays
//Functions
//Variables
//Preprocessor #define
//string
///////////////////////////////////////////////////////
//long   8B   12B   /*16B/*  %l 
//int x=22;         
//float  4B              %f
//double 8B              %lf
//printf("%d",sizeof(int));//4  //get size in byte
//printf("%d",sizeof(x));//4  //get size in byte

//Linking -> 1-Dynamic   2-Static  later  search
//turnary
////////////////////////////////////////////////////////
///50 students
///5  subjects
int std1sub1;
int std1sub2;
int std1sub3;
int std1sub4;
int std1sub5;
int std2sub1;
//..5 * 50 = 250 variables

//////////////////////////////////////////////////
//solution:
//think for a variable carries 5 subjects
//250 variable ->  50 variable
//think of a variable carries 50 variable that carry 5 varialbles
//50 variable -> 1 variable


///Arrays  [variable]
///fixed-size sequential data type 
//stores in memory

//Data type can carries fixed-size collection for same data types
//stored sequaentially in memory
//[Fixed size]
//[same Data type]

//declaration
int x; //4b
int arr[5];
//store fixed 5 places of integer sequentially in memory 
//size of arr 5 * sizeof(int)=20 bytes
printf("%d",sizeof(arr)); //20

////////////////////////////////////////////////////

int main()
{
    int arr[5];

    //setter   //assignment
    arr[0]=5;
    arr[1]=6;
    arr[2]=7;
    arr[3]=8;
    arr[4]=9;
    
    printf("%d",arr[0]); //5
    printf("%d",arr[1]); //6
    printf("%d",arr[2]); //7
    printf("%d",arr[3]); //8
    printf("%d",arr[4]); //9

    return 0;
}






#include<stdio.h>
int main()
{
    int x=10;
    int arr[5];

    printf("%x",arr); //0x10

    ///arr itself is an 
    //address of first element in the array
    ///arr carries constant #  => 
    //always carries address of fst element ONLY


    printf("%x",arr); //0x10
    printf("%x",&arr); //same


    return 0;
}


/////////////////////////////////////////////
//to set or get any data from array ,use indexer
int arr[10];   //index 0  -> 9
arr[10]=222;  ///logical WRONG  //there is no index 10 in array
/////////////////////////////////////////////
int main()
{
    
    int arr[10];  //allocate for 10 int places sequentially 
    //with rubbish values
    ///  memory   arr |#|#|#|#|#|#||||||||
    //           index 0  1 2 3 4 5    
    //setter   memory x  33
    //int x=5;
    //x=33;
    arr[0]=10;
    arr[1]=20;
    arr[2]=30;
    ..
    ..
    arr[9]=100;
    arr[10]=110; //XXXXX out of boundry of array



    //getter
    //int x=10;
    //int z=x;
    printf("%d",arr[0]);  //10
    printf("%d",arr[1]);  //20
    printf("%d",arr[2]);  //30
    ..
    ..
    printf("%d" ,arr[9]);  //100


    return 0;
}

//////////////////////////////////

int main()
{
    int arr[10];  //40B  //|#|#|#||||||
    int x=10;

    for(int i=0;i<10;i++)
    {
        printf("Enter value at index %d\n",i);
        scanf("%d",&arr[i]);
    }

    //printing  
    for(int i=0;i<10;i++)
    {
        printf("value at index %d is %d\n",i,arr[i]);
    }
    return 0;
}

/////////////////////////////////////////////////////////
int main()
{
    float arr[5];   //memory  |#|#|#|#|#|
    int x;
    //read into first element of array ONLY

    scanf("%f",arr); //T
    scanf("%f",&arr); //T
    scanf("%f",&arr[0]); //T
    scanf("%f",arr[0]); //F



    //scanf("%f",&arr[0]); //T
    //scanf("%f",arr);     //T why=>///arr itself is an address of first element in the array
    //scanf("%f",&arr);     //T why=>///arr itself is an address of first element in the array
    //scanf("%d",&x);

    for(int i=0;i<5;i++)
    {
        printf("Enter # at index %d\n",i);
        scanf("%f",&arr[i]);
    }

    for(int i=0;i<5;i++)
    {
        printf("Value at index %d is %f\n",i,arr[i]);
    }

    return 0;
}


/////////////////////////////////////////////////////////

///default values  => With declaration directly
int arr[10]; //|#|#|#|#|#|#|#|#|#|#|
int arr[10]={1,2,3,4,5,6,7,8,9,10};
int arr[10]={0,0,0,0,0,0,0,0,0,0};
int arr[10]={0,0,0,0,0}; //|0|0|0|0|0|0|0|0|0|0|
int arr[10]={1,2,3}; //|1|2|3|0|0|0|0|0|0|
int arr[10]={0}; //|0|0|0|0|0|0|0|0|0|
int arr[5]={1,2,3,4,5,6,7,8,9,10}; //|1|2|3|4|5| No Runtime
int arr[]; //Compile Error
int arr[]={1,2,3,4,5};

//BIG ERROR  => Compile Error
int arr[10];
arr[10]={1,2,3,4,5,6,7,8,9,10};
arr={1,2,3,4,5,6,7,8,9,10};

///not Standard
int size;
printf("Enter Array Size\n");
scanf("%d",&size);
int arr[size]; //Not Standard
//GCC Runs Successfully



int arr[10]; //|#|#|#|#|#|#|#|#|#|#|
int arr[10]={0,0,0,0,0,0,0,0,0,0}; //|0|0|0|0|0|0|0|0|0|0|
int arr[10]={0,0,0};  //|0|0|0|0|0|0|0|0|0|0|
int arr[10]={1,2,3}; //|1|2|3|0|0|0|0|0|0|0|
int arr[10]={0};
int arr[5]={1,2,3,4,5,6,7,8,9,10};  //T   |1|2|3|4|5|678910
int arr[]; //Compile Error
int arr[]={1,2,3};

//not Standard
int size;
printf("Enter size");
scanf("%d",&size);//0
int arr[size];//You Cannot declare default values

/////////Compile Error
int arr[10];
arr[10]={1,2,3,4,5,6,7,8,9,10};
/////////

int arr[10]; //40B //|#|#|#|#|#|#|#|#|#|#|

int arr[10]={0,0,0,0,0,0,0,0,0,0}; //40B //|0|0|0|0|0|0|0|0|0|0|

//WRONG compile error
int arr[10];
arr[10]={0,0,0,0,0,0,0,0,0,0};
arr={0,0,0,0,0,0,0,0,0,0};
//when use default value , use it in array declaration


///not standard
int size;
printf("Enter size");
scanf("%d",&size);//0
int arr[size];       //Runtime error={0};
///
///later -> dynamic allocation

//////////////////////////////////////////////////////////
int arr[10];

sizeof(arr)/sizeof(int); //10

for (int i=0;i<10;arr++)
{
    printf()
}
/////////////////////////////////////////////////////////
//nested for loop

for(int i=0;i<3;i++)
{
    for(int j=0;j<4;j++)
    {
        printf("%d,%d\n",i,j);
    }
}
//0,0
//0,1
//0,2
//0,3
//1,0


//////////////////////////////////////////////////////////
///2D Array
///int arr[rowsize][colsize]
int main()
{
    
    int arr[3][4];    //48B

    
    
    arr[0][0]=1;
    arr[0][1]=2;
    arr[0][2]=3;
    arr[0][3]=4;
    arr[1][0]=5;

    //memory i0  j01      1
    for(int i=0;i<3,i++)
    {
        for(int j=0;j<4;j++)
        {
            printf("Enetr value at index %d,%d\n",i,j);
            scanf("%d",&arr[i][j]); //20 Enter
        }
    }

    for(int i=0;i<3,i++)
    {
        for(int j=0;j<4;j++)
        {
            printf("value at index %d,%d is %d\n",i,j,arr[i][j]);
        }
    }


    //WCE
    //memory i 0 1  j 0 1 2 3 4 0
    for(int i=0;i<3;i++)
    {
        for (int j=0;j<4;j++)
        {
            sum[i]+=arr[i][j];
        }
    }


    for(int i=0;i<3;i++)
    {
        printf("%d\n",sum[i]);
    }



    ///MNF43
    int main()
    {
        int arr[3][4];
        int sum[3]={0};

        for(int i=0;i<3;i++)
        {
            for(int j=0;j<4;j++)
            {
                printf("plz enter value at index %d,%d\n",i,j);
                scanf("%d",&arr[i][j]);
            }
        }

        for(int i=0;i<3;i++)
        {
            for(int j=0;j<4;j++)
            {
                sum[i]+=arr[i][j];
            }
        }
    }

    for(int i=0;i<3,i++)
    {
        //sum[i]=0;
        for(int j=0;j<4;j++)
        {
            sum[i]+=arr[i][j];
        }
    }

    //print sum
    for(int i=0;i<3;i++)
    {
        printf("sum of row %i is %d\n",i,sum[i]);
    }

    return 0;
}


//////////////////////////////////////////////////////
//default values in 2D Array

int arr[][]; //compile error
int arr[3][4]={{1,1,1,1},{2,2,2,2},{3,3,3,3}};
int arr[4][2]={{1,1},{1,1},{1,1},{1,1}};
int arr[3][4]={1};//try it
int arr[5]={5}; //|5|0|0|0|0|
int arr[][]={{1,1,1},{1,1,1},{1,1,1}};
int arr[][]={{1,1,1},{1,1,1},{1,1,1,4}}; //Try it

//////////////////////////////////////////////////////
//Function
int main()
{
    printf("Hello");
    printf("Good Morning");
    printf("Good Bye");
    printf("-----------");
    //
    //
    //
    //
    //
    printf("Hello");
    printf("Good Morning");
    printf("Good Bye");
    printf("-----------");
    //
    //
    //
    //
    printf("Hello");
    printf("Good Morning");
    printf("Good Bye");
    printf("-----------");
    return 0;
}

//Copy&Paste => Bad Programming
//effort redundant

//Solution ??? for loop ?? No

//group that code with specific name
//when need that code , call that name

//Function:
///1-some sort of code grouping together
///with specific name
///2-when to use that code ,,, call that name
///3- function must come before main  ->prototype
///Function Syntax

///void FunctionName()
//{
    //code here
//}

////////////////////////////////
#include<stdio.h>
//
void PrintMe()
{
    printf("Hello\n");
    printf("Good Morning\n");
    printf("Good Bye");
}
//
int main()
{
    //when call function
    PrintMe();
    //
    //
    //
    PrintMe();
    //
    //
    //
    PrintMe();

    return 0;
}


//////////////////////////////////////////////////

#include<stdio.h>
////SOLID Principles  -> single responsibility
////plural responsibility

void Add()
{
    int x=1;
    int y=2;

    printf("Enter #1\n");
    scanf("%d",&x); //11
    printf("Enter #2");
    scanf("%d",&y); //22

    int z=x+y;
    printf("%d",z);
}

int main()
{
    Add();
    return 0;
}


/////////////////////////////////////////
//SOLID Principles
/////////////////////////////////////////


///void FunctionName(input parameter/s  / Argument/s)
//{
    //code
//}

//           11    22
void Add(int a,int a)
{
    int c=a+b;
    printf("%d",c);
}

int main()
{
    int x;
    int y;
    printf("Enter #1\n");
    scanf("%d",&x); //11
    printf("Enter #2");
    scanf("%d",&y); //22

    Add(x,y); 
    //pass values
    //Compiler will see it like Add(11,22)

    return 0;
}



//////////////////////////////////////////

/// ReturnType  FunctionName (Argument/s)
//{
    //code
    //return [value]
//}

//ReturnType
//void  => function Returns nothing

//premitive int   => function body must include [return]



/////////////////////////////////////////////
//          11    22
int Add(int a,int b)
{
    int c=a+b;
    return c;
    //return value
    //compiler will see it return 33;
}

int Add2(int a,int b,int c)
{
    return a+b+c;
}

int main()
{
    int x;
    int y;
    printf("Enter #1\n");
    scanf("%d",&x); //11
    printf("Enter #2");
    scanf("%d",&y); //22

    Add(x,y);  ///pass Values
    //compiler after finish this line of code
    //it will be like
    //33;

    //#1
    int result=Add(x,y);  //int result=33;
    printf("%i",result);

    //#2
    printf("%i",Add(x,y));
    
    //WRONG  //Compile Error
    //printf("%i",c);


    return 0;
}

///////////////////////////////////////////////////

int Add(int x,int y)
{
    return x+y;
}

int Add2(int x,int y,int z)  //Compile Error Function Declared before
{
    return x+y+z;
}

float Add3(float x=0,float y=0,float z=0 ,float r=0)//Compile Error
{
    return x+y+z+r;
}

//Overloading is not supported in c
//Default argument is not supported in c

int main()
{
    int a=10,b=20,c=30;
    Add3();
    return 0;
}

////////////////////////////////////////////////////////////////
//Function Prototype: function header only before main
//for organizing code
int Add(int x,int y);
int Sub(int,int);
void PrintMe();
int main()
{
    Add(11,22);
    return 0;
}
int Add(int x,int y)
{
    return x+y;
}
int Sub(int x,int y)
{
    return x-y;
}
void PrintMe()
{
    printf();
    printf();
    printf();
}

////////////////////////////////////////////////////////////////
///Variables
///1- local variable
///2- global variable
///3- static variable
///////////////////////////////////////////////////
///1- Local variable
//////variable declared inside scope {}  , ()
//////Access :any code inside/below scope
//////life time: at end of its scope
//////storage => Stack

int Add(int a,int b)//local variable
{
    int c;
    //x=33;//XXX
    
    
}
int main()
{
    
    //x=10; XXXX
    int i;
    int x;//local variable

    for(i=0;i<5;i++)  //local variable
    {
        x=22;//??T
        char ch;
    }
    i=22;
    
    char ch ;
    for(j=0;j<5;j++)
    {
        
    }
    
    

    Add(11,22);
    Add(33,44);
    //i=22;   //XXX
    return 0;
}


///////////////////////////////////////////////////////
///2- Global variable
///////Variable declared outside any scope [before main]
///////access: any code in program
///////lifetime: at end of program
///////storage : Data Segment [bss]
#include<stdio.h>

int x=10; //global variable
int ali=0;

void PrintMe()
{
    int x=100; //T
    x=200; //local

    //scope operator
    ::x=300;
    ali=2;
}
int main()
{

    int x=1;

    x=33;
    ::x=22;  //scope operator
    ali=11;

    x=100; //local
    printf("%d",x); //local

    ::x=200; //global   //  :: scope operator
    printf("%d",::x);
    
    return 0;
}
////////////////////////////////////////////////
void TryMe()
{
    int x=0;
    x++;
    printf("%d",x);
}

int main()
{
    TryMe();
    TryMe();
    TryMe();
    //o/p
    
    return 0;
}


////////////////////////////////////////////////
///3- static variable
///////////Declared ONCE and only Once in memory
///////////local variable with keyword static
///////////access:any code inside scope
///////////life time: Alive Till Program end
///////////storage: data segment bss
//////////Static variable always declared with default 0

void PrintMe()
{
    static int x;  //Execution Fst time ONLY  //BSS    x  3
    x++;
    printf("%d",x);
}

int main()
{
    //x=22;  //WRONG local variable
    PrintMe();  //1
    PrintMe();  //2
    PrintMe();  //3
    ///
    x=22; //XXXX
    ///
    ///
    ///
    ///
    return 0;
}



////////////////////////////////////////////////////////////
//Preprocessor
#include

//#define [macros] is used to replace any keyword[macros] in program with specific
///value or expression

//Before Complilation:
//compiler will replace any ABC with 22 

#include <stdio.h>

#define ABC 22

#define DEF 33;

#define SIZE 10

#define SZ 10];  //NOT RECOMMENDED

#define ROW 4
#define COL 3
//#define ZZZ COL
//#define EEE  r%2==0

int main()
{
    
    int y=ABC;
    int z=DEF
    int arr[SIZE];//={0}XXX; //default values is no supported
    int arr2[SZ



    int x=ABC;
    printf("%d",ABC);


    int x=ABC;
    int y=ABC;
    int z=DEF

    int arr[SIZE];//={1,2,3,4}; XXXXXX
    int arr2[SZ


    int arr3[ROW][COL];

    //ZZZ q=22;

    for(int i=0;i<ROW;i++)
    {
        for (int j = 0; j < COL; j++)
        {
            /* code */
        }
        
    }

    return 0;
}
///////////////////////////////////////////////////////
///get character from user
//and print it

int main()
{
    char ch;
    
    printf("Enter Character\n");
    scanf("%c",&ch); //Mohamed Enter
    ///read stream on keys from keyboard untill I PRESS ENTER

    system("cls"); 
    
    printf("character is %c",ch); //M

}

//o/p
//enter character
//MohamedAhmedAliSara

//character is M

///scanf
///1-read stream of key from keyboard untill press enter
///2-PRESS ENTER IS MUST with SCANF
///3-scanf can read any printed keys ONLY

///get character from user
//and print ascii for it

int main()
{
    char ch;
    
    printf("Enter Character\n");
    scanf("%c",&ch);
    ///read stream on keys from keyboard untill I PRESS ENTER

    printf("ASCII character is %d",ch);

}
///when to get ascci for non printed keys
///scanf is not applicable

///////////////////////////////////////////////////////////
///    char getch()
///function get character from user and return it

///get character from user
//and print it

int main()
{
    char ch;
    
    printf("Enter Character\n");
    
    //scanf("%c",&ch);
    ch=getch();  //#include<conio.h>   enter


    printf("\n\nascii is %d",ch); //13

}

//getch()
//1- get only one character from user and return it
//      WITHOUT PRESS ENTER

//2- getch() can be applicable with printed and non printed keys

//3- getch() cannot print any printed key pressed [getche()]

//getchar()===> search

/////////////////////////////////////////////////////////
///normal ascii  1Byte

//Extended ASCII  2B   |NULL|####|


//processor      M 77     , up null 77


//borlandc    |NULL||
//Turboc    |NULL||
//CodeBlocks |-32||

////Write Program to identify normal or extended key and print ascii

#include<stdio.h>
#include<conio.h>
int main()
{
    char ch;

    printf("Enter Character \n");
    ch=getch();

    ch=getch();

    printf("ASCII is %d",ch);
}
//o/p
//Enter char
//ASCII is -32


#include<stdio.h>
#include<conio.h>
int main()
{
    char ch;
    printf("Enter Character \n");
    ch=getch();

    switch(ch)
    {
        case -32:
        ch=getch();
        printf("Extended key with ascii %d",ch);
        break;
        default:
        printf("Normal key with ascii %d",ch);
        break;;
    }


    return 0;
}











int main()
{
    while(1)
    {
        _flushall();
        printf("\nPress any key ...\n");
        ch=getch();

        /*if(ch==-32)
        {
            ch=getch();
            printf("this is extended %d",ch);
        }
        else
        {
            printf("this is normal %d",ch);
        }*/
        switch (ch)
        {
        case -32:
            ch=getch();
            printf("this is extended %d",ch);
            break;

        default:
            printf("this is normal %d",ch);
            break;
        }

    }


    return 0;
}


//////////////////////////////////////////////////////
///string v1.0
//String
///in C => there is no data type called string
///despite there are many libraries [headers] deal with string
///#include<string.h>
///we can create string   |M|o|h|a|m|e|d|
//by create array of characters

//create program to get full name from user and print it
int main()
{
    char name[15];

    printf("Enter your name\n");
    for(int i=0;i<15;i++)
    {
        scanf("%c",name[i]);
    }

    for(int i=0;i<15;i++)
    {
        printf("%c",name[i]);
    }
    //o/p
    //Enter your name
    //a enter h enter m enter e enter d enter  enterenterenterenterenter  

    return 0;
} 


int main()
{
    char name[15];

    printf("Enter name\n");
    for(int i=0;i<15;i++)
    {
        name[i]=getche();
    }

    for(int i=0;i<15;i++)
    {
        printf("%c",name[i]);
    }

    //o/p
    //Enter name
    //ahmed
}

int main()
{
    char name[15];
    char ch;
    int x=0;
    printf("Enter name\n");
    do
    {
        ch=getch();
        name[x]=ch;
        x++;

    } while(ch!=13);
    name[x]='\0';
}
//o/p
//enter name
//Ahmed Enter


///Delimeter ===> Null Terminator '\0'

int main()
{
    char name[15];
    char ch;
    int x=0;
    printf("Enter name\n");
    while((ch=getch())!=13)
    {    
        name[x]=ch;
        x++;
    }
    name[x]='\0';


    //sol3
    printf("%s",name);

    //sol2
    int a=0;
    while (name[a]!='\0')
    {
        printf("%c",name[a]);
        a++;
    }
    
    //sol1
    for(int i=0;i<15;i++)
    {
        if(name[i]!='\0')
        {
            printf("%c",name[i]);
        }else{
            break;
        }
    }


}



/////////////////////////////////////

char name[11]; //BIG WRONG
//ALWAYS Consider \0 in declare array of character
char name[11+1];

//default values
char arr[10]={'a','l','i','\0'};
char arr[10]="Mohamed"; //\0 is written by o.s

char arr[3][10]={{'','',''},{'','',''},{'','',''}}
char arr[3][10]={"Ali","Aya","Sara"};



//read array of character from user
char name[15];  //|a|h|m|e|d|\0||||
scanf("%s",&name); //ahmed Enter

///////////////////////////////////////////////////////

///Lab Assignments

///Arrays of 15 places of integer
///Read ALL Data From user in Runtime
//XXX int arr[15]={1,2,3,4,5,6,7,8,9,0};

//1D Array
//1-Array min  and max value  |7|3|5|6|8|-1|-11|33|99|
//2-Array sort    same array            |-11|-1|3|5|6||||||
//3- search on array and return index
//4- |1|2|3|4|1|5|6|2|1|9|10|

//3
//7
//5
//3



//5-2D Array
//array [3][4]
//calculate average of columns
//int avg[4]

//6- multiply 2 matrix
//3*2    *  2*1  =  3*1



//7- bonus 3*3     *    3*2   =  3*2


//8-Calculator with function
int Add(int ,int)
Sub(,)
Div(,)

Main()
{}


//