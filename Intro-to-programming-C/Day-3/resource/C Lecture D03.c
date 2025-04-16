//Arrays
//Functions
//Variables
//Preprocessor #define
//Memory
///////////////////////////////////////////////////
//20 students
//5 subjects
float std1sub1;
float std1sub2;
float std1sub3;
float std1sub4;
float std1sub5;
float std2sub1;
..
100 variables

//solution 
//create ONE variable carries all 5 subjects

////////////////////////////////////////////////////////////////
///Array:variable is a collection of data with the same type
////stored sequentially in memory

// int x=10; //4byte
// x=20;
// //int arr[3]; //variable carries collection of 3 integers stored
//             //sequentially in memory
//             //size 3*4 Bytes


// int arr[10]; //|1|#|#|#|#|9|#|#|#|#|
// //      //index 0 1 2 3 4 5 6 7 8 9
// //Index of array

// //setter  change left value with another value 
// arr[0]=1;   //setter
// arr[5]=9;

// //Getter => retrieve value wihout change it
// printf("%d",arr[0]);   //1
// printf("%d",arr[1]);   //Rubbish

// //z setter
// //right value =>getter
// //int z=arr[5];
//////////////////////////////////////////////////


#include<stdio.h>
int main()
{
    int arr[10];  //40 Byte   // |1|2|3|4|5|6|7|8|9|10|

    arr[0]=1;
    arr[1]=2;
    arr[2]=3;
    arr[3]=4;
    arr[4]=5;
    arr[5]=6;
    arr[6]=7;
    arr[7]=8;
    arr[8]=9;
    arr[9]=10;

    printf("%d\n",arr[0]);
    printf("%d",arr[1]);
    printf("%d",arr[2]);
    printf("%d",arr[3]);
    printf("%d",arr[4]);
    printf("%d",arr[5]);
    printf("%d",arr[6]);
    printf("%d",arr[7]);
    printf("%d",arr[8]);
    printf("%d",arr[9]);

    int x=1 2;
    //arr |1|2|3|4|5|6|7|8|9|10|
    //memory i 0 1 2
    for(int i=0;i<10;i++,x++)
    { 
        //arr[i]=i+1;
        arr[i]=x;
        //x++;
        //arr[i]=i++;//BIG WRONG
    }

    //Print
    for(int i=0;i<10;i++)
    {
        printf("%d\n",arr[i]);
    }
    //o/p
    // 1
    // 2
    // 3
    // 4
    // 5
    // 6
    // 7
    // 8
    // 9
    // 10

    return 0;
}


//////////////////////////////////////////////////
//read from user in runtime
#include<stdio.h>
int main()
{
    int arr[10];  //|10|#|#|#|#|#|#|#|#|
    //1-arr itself is an address 
    //2-arr is an address of the first element of the array [constant]

    printf("%x",arr); //Print Address of fst element of array 0x02
    print("%x",&arr[0]); //Print Address of fst element of array 0x02


    //Read
    printf("Enter Elelmet At index 0");
    scanf("%d",&arr[0]);
    scanf("%d",arr);

    for(int i=0;i<10;i++)
    {
        printf("Enter element At index %d",i);
        scanf("%i",&arr[i]);
    }

    //clear screen

    for(int i=0;i<10;i++)
    {
        printf("the value at index %d is %d\n",i,arr[i]);
    }


    //o/p
    //Enter element At index 0
    //10



    return 0;
}


///////////////////////////////////////////////////////

///default value

#include<stdio.h>
int main()
{
    char carr[10]; //10 Byte
    int arr[10];   //|.|.|.|.|.|.|.|.|.|.|
    int arr[10]={0,0,0,0,0,0,0,0,0,0};  //|0|0|0|0|0|0|0|0|0|
    int arr[10]={0};  //|0|0|0|0|0|0|0|0|0|0|
    int arr[10]={1,2,3}; //|1|2|3|0|0|0|0|0|0|0|
    int arr[3]={1,2,3,4,5,6,7,8,9,10};   //|1|2|3|4567810
    int arr[]; //compile error

    int arr[3];
    arr={1,2,3}; //compile error

    return 0;
}


////////////////////////////////////////////////////
//2D Array
//     
// int arr[3][4];  //array with 3 rows and 4 columns


//nested for loop
//memory
//i 0 1      j 0 1 2 3 4 0
for(int i=0;i<3;i++)
{
    for(int j=0;j<4;j++)
    {
        printf("%d,%d\n",i,j);
    }
}

//o/p
0,0
0,1
0,2
0,3
1,0
1,1


// int arr[rowsize][colsize];

#include<stdio.h>
int main ()
{
    int arr[3][4];   //size  3*4*4Bytes 

    arr[0][0]=10;
    arr[0][1]=20;
    arr[0][2]=30;
    arr[0][3]=40;
    arr[1][0]=50; 
    arr[1][1]=60; 

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            printf("Enter value at index %d,%d\n",i,j);
            scanf("%d",&arr[i][j]);
        }
    }

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            //printf("Value at index %d,%d is %d\n",i,j,arr[i][j]);
            printf("%i\t",arr[i][j]);
        }
        printf("\n");
    }
    //1  2  3  4
    //5  6  7  8


    return 0;
}


/////////////////////////////////////////
int main()
{
    int arr[3][4];
    int sumOfRows[3]={0};  //|#|#|#|
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            printf("Enter Value at index %d,%d \n",i,j);
            scanf("%d",&arr[i][j]);
        }
    }

    //sum[0] 100   sum[1] 50    i 0 1      j 0 1 2 3 4 0
    //
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            sumOfRows[i]+=arr[i][j];
        }
    }


    for(int i=0;i<3;i++)
    {
        printf("the sum of rows index %d is %d\n",i,sumOfRows[i]);
    }

    return 0;
}


/////////////////////////////////////////////////////
//2D Default values
int arr[3][4]={0};  //|0|0|0|0
int arr[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
int arr[2][4]={{1,2,3,4},{5,6,7,8}};
int arr[5][3]={{1,1,1},{2,2,2},{3,3,3},{4,4,4},{5,5,5}};
int arr[][]; //compile Error
//Try It
int arr[]={1,2,3,4,5};
int arr[][]={{1,1,1,1},{2,2,2,2},{3,3,3,3}};
/////////////////////////////////////////////////////

/////////////////////////////////////////////////////
//Preprocessor

//you can declare any value by # define
//and processor will replace it before compile time

#define abc 10
#define def 10;
///abc => symbol not a variable

int x=abc;
int y=def    //int y =10;

////////////////////////////////////////
#include<stdio.h>
#define A 10;
#define row 3
#define col 4
#define size 10
#define Mariem 3];
int man()
{
    int x=A
    int arr3[Mariem
    int arr[size];
    int arr2[row][col];
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
        }
    }
    printf("%d",x); //=>10
    printf("%d",A); //=>Try it   Compile Error   ;

    return 0;
}

///////////////////////////////////////////////////////
//Function: some piece of code grouping together with specif name
////////////when you wanna execute this code,you can call that name

///function must come before main()

int main()

{
    printf("Hello");
    printf("GM");
    printf("Gb");
    //
    //
    //
    //
    printf("Hello");
    printf("GM");
    printf("Gb");
    //
    //
    //
    printf("Hello");
    printf("GM");
    printf("Gb");
    return 0;
}


///functoin Syntax
////  returnType FunctionName(input parameter/s)
////  {
            //code here
////  }

////Return Type
//1- void  function returns nothing
//2- premitive  int
//with any return type except void,
//you must write [return] keyword

void Print()
{
    printf("Hello");
    printf("Hello2");
    printf("Hello3");
}

int main()
{
    //calling
    Print();
    //
    //
    //
    Print();
    return 0;
}


/////////////SOLID/////////////

void Add()
{
    int x=3,y=4,z;
    z=x+y;
    printf("%d",z);
}

int main()
{
    Add();
    return 0;
}

//////////////////////////////////////
//           3     4
void Add(int x,int y)
{
    int z;
    z=x+y;
    printf("%d",z);
}

int main()
{
    int a=3,b=4;

    Add();//compile error
    Add(a,b);  //=>passing value  => Add(3,4)    ==>7

    return 0;
}
//////SOLID/////////////////////////////////////////////////
//           3     4
int Add(int x,int y)
{
    int z;
    z=x+y;
    return z;
}

int main()
{
    int a=3,b=4;
    printf("Enter #1");
    scanf("%d",&a);

    printf("Enter #2");
    scanf("%d",&b);

    int result;
    result= Add(a,b);  //=>passing value  => Add(3,4)  
    //compiler   result=7; 
    printf("%d",result);

    printf("%d",Add(a,b));

    return 0;
}

//////////////////////////////////////////

int Add(int a,int b)
{
    return a+b;
}

int Add(int a,int b,int c)  //Compile Error  Add Declared Before
{
    return a+b+c;
}
//Overloading is not supported in c
int Add2(int a,int b,int c)  
{
    return a+b+c;
}


// int Add3(int a=1,int b=2,int c=3)   //Compile Error  Defaul Argument not supported 
// {
//     return a+b+c;
// }


int main()
{
    return 0;
}


//////////////////////////////////////////////////////
///Function Prototype :function header
int Add();
int Add2(int x,int y);
int Add3(float x ,float y ,float z);

int main()
{
    Add();
    Add2(3,4);
    Add3(3,3,4);
    return 0;
}

int Add()
{

}

int Add2(int x,int y)
{

}

int Add3(float x ,float y ,float z)
{
    
}


///////////////////////////////////////////////////////////////
//Variables:
//1-Local Variable
///Variable created inside scope {}
///Access: inside an below scope of it
///Life Time : At end of its scope
void Print(int y)
{
    int z;
    x=10; //>??? XXX
}

int main()
{
    
    //x=10; ???XXXX
    int x; //local variable inside main
    y=10; XXX
    z=10; XXX
    x=10;
    Print();


    for (int a=0;a<10;a++)
    {
        a=22;
    }

    a=10; ?? XXXXX




    do
    {
        //int abc;

        abc=22;
    }
    while (abc==22 XXXX);
    
    

}

void Add(int x){}

void Add2(int x,int y){}


int main()
{
    int i=0;

    for(int i=0;i<33;i++){} //compile error
    
    for(i=0;i<33;i++){} 

    return 0;
}




//2- global Variable RCU
//variable declared outside any scope /outside main
//Access:any scope inside program
//lifetime :at the end of program
#include<stdio.h>

int x;  //Global Variable
void Add()
{
    x=22; //True
}

int main()
{
    int x;  //TRUE
    x=10; //True  Local
    ::x=22; //Global
    return 0;
}


//3- static variable
//variable declared local with keyword static
//access: inside scope of it
//Lifetime : At the end of program
//static always be initialized 0 regadress you did it or not

int Print()
{   
    static int x=0;  //bss     x 0 1 2 3 4
    x++;
    return x;  //return value
}
int main()
{
    printf("%d",Print()); //1
    printf("%d",Print()); //2
    printf("%d",Print()); //3
    printf("%d",Print()); //4
    x=22; XXX
    return 0;
}

////////////////////////////////////////////////

////////////////////////////////////////////////////////////////
//Lab Assignment
//READ ALL DATA FROM USER IN RUNTIME  scanf
//int arr[10]={1,2,3,4,5};  XXXX

//1D Array size 10
//1- min value , max value    7,5,3,2,3,5,6,-1
//2- sort                     -1,2,3,3,5,5,6,7
//3-Bonus   [15]              1,2,3,4,2,1,7,4,3,2,6,1,2

//2D Array
//4- array [3][4]  =>sum of cols

//5-Multiply 2 matrixs   3*2   * 2*1    =  3*1

//6-Calculator using function
//enter #1
//10
//Enter #2
//20
//Enter operator
//+
//10+20=30
//continue y,n????
//y
//enter #1
//11
//Enter #2
//22
//Enter operator
//-
//11-22=-11
//continue y,n????
//N
//Program end

Add()
Sub()
Div()

main()






