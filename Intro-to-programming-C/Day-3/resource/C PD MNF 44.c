//Arrays
//Functions
//Variables
//Preprocessor #define
//Memory
///////////////////////////////////////////////////////
//20 students
//5 subjects
float std1sub1;
float std1sub2;
float std1sub3;
float std1sub4;
float std1sub5;
float std2sub1;
..
//100 variables

//solution 
//create ONE variable carries all 5 subjects
//reduce 100 into 20
//later will be ONE variable
////////////////////////////////////////////////////////////////
///Array:
//variable is a collection of [FIXED SIZE]
//data with the same type
////stored sequentially in memory

// int x=10; //4byte
// x=20;
// //int arr[3];
//stored collection of three integers 
//stored sequentially in memory
//under the name of arr
//Size of arr = 3 * sizeof(int)=3*4=12B

 //variable carries collection of 3 integers stored
//             //sequentially in memory
//             //size 3*4 Bytes


// int arr[10]; //|1|#|#|#|#|9|#|#|#|#|
// //      //index 0 1 2 3 4 5 6 7 8 9
// //Index of array

// //setter  change left value [LValue] with another value 
// arr[0]=1;   //setter
// arr[5]=9;

// //Getter => retrieve value wihout change it
// printf("%i",arr[0]);   //1
// printf("%i",arr[1]);   //Rubbish

// //z setter
// //right value =>getter
// //int z=arr[5];
//////////////////////////////////////////////////

//declare array and put data into it

#include<stdio.h>
int main()
{
    int arr[5]; //storing 5*4 integers sequentially

    //setter
    arr[0]=10;
    arr[1]=20;
    arr[2]=30;
    arr[3]=40;
    arr[4]=50;
    //getter
    printf("%i\n",arr[0]);
    printf("%i",arr[1]);
    printf("%i",arr[2]);
    printf("%i",arr[3]);
    printf("%i",arr[4]);

    return 0;
}





int main()
{
    // int x;
    // scanf("%i",&x);
    int arr[5];

    //arr itself is an address
    //VERY IMPORTANT .....
    //arr itself is an address fst element in array
    //arr Always is an address fst element in array
    
    //read integer from user and
    //put it into first element of array
    scanf("%i",&arr[0]); //T
    scanf("%i",arr); //T

    for(int i=0;i<5;i++)
    {
        printf("Enter value at index %i\n",i);
        scanf("%i",&arr[i]);
    }

    for(int i=0;i<5;i++)
    {
        printf("Value at index %i is %i\n",i,arr[i]);
    }
}
//////////////////////////////////////////////////////
//default values with creation

int main()
{
    // int arr[5]; |#|#|#|#|#|
    // arr[5]=44;
    // arr[6]=55;
    //printf("%d",arr[5]); //44  //still rubbish
    // //may be no runtime error

    int arr[5]; //|#|#|#|#|#|
    int arr[5]={1,2,3,4,5}; //arr |1|2|3|4|5|
    int arr[10]={0,0,0,0,0,0,0,0,0,0}; //|0|0|0|0|0|0|0|0|0|0|
    int arr[10]={1,2,3}; //|1|2|3|0|0|0|0|0|0|0|
    int arr[10]={0};
    int arr[]; //Compile Error
    int arr[]={1,2,3,4,5};
    int arr[3]={1,2,3,4,5,6,7,8,9,10}; //T

    //BIG COmpile Error
    //default values WITH ARRAY DECLARATION
    //int arr[10]; //|#|#|#|#|#|#|#|#|#|#|
    //arr[0]={1,2,3,4,5};

    ////not standard -> work properly with gcc ->borlandc compile eror
    //int size=0;
    //scanf("%d",&size);//0
    //int arr[size];
    //int arr[size]={1,2,3,4,5};
    ////standard?  Dynamic alocation later

}
///////////////////////////////////////////////////////
//2D Array
//int arr[rowsize][colsize]

int main()
{
    int arr[3][4];  //48B
    //we can access each element by index also
    //arr[rowindex][colindex]=value;

    arr[0][0]=10;
    arr[0][1]=20;
    arr[0][2]=30;
    arr[0][3]=40;
    arr[1][0]=50;
    arr[1][1]=60;
    arr[1][2]=70;
    arr[1][3]=80;

    for(int row=0;row<3;row++)
    {
        for(int col=0;col<4;col++)
        {
            printf("Enter # at index %i,%i",row,col);
            scanf("%i",&arr[row][col]);
        }
    }

    //to print 2d Array
    for(int row=0;row<3;row++)
    {
        for(int col=0;col<4;col++)
        {
            //printf("value at index %i,%i is %i\n",row,col,arr[row][col]);
            printf("%d\t",arr[row][col]);
        }
        printf("\n");
    }    
}

//calculate sum of each row
int main()
{
    int arr[3][4];  //48B
    int sum[3]={0};
    for(int row=0;row<3;row++)
    {
        for(int col=0;col<4;col++)
        {
            printf("Enter # at index %i,%i",row,col);
            scanf("%i",&arr[row][col]);
        }
    }
    //to print 2d Array
    for(int row=0;row<3;row++)
    {
        for(int col=0;col<4;col++)
        {
            //printf("value at index %i,%i is %i\n",row,col,arr[row][col]);
            printf("%d\t",arr[row][col]);
        }
        printf("\n");
    }    

    //calculate sum of rows
    for(int row=0;row<3;row++)
    {
        for(int col=0;col<4;col++)
        {
            sum[row]+=arr[row][col];
        }
    }

    //print sum of rows
    for(int i=0;i<3;i++)
    {
        printf("%i\n",sum[i]);
    }
}

//////////////////////////////////////
//default values with 2d Array
int main()
{
    int arr[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    int arr[3][4]={0}; //Try IT

    int arr[2][3]={{2,2,2},{2,2,2}};
    int arr[3][3]={{1},{2},{3}}; // 
    int arr[][]; //Compile Error
    int arr[][]={{1,1,1,1},{2,2,2,2}};

    int arr[][]={{1},{2,3},{4,5,6},{7,8,9,10}};//arr[4][4]

}
////////////////////////////////////////////////////
//#define
//preprocessor

//#define make create macro data before compile time
//#define is used to create constant values or expression[macro]
//under specific name
//and you can use it whatever you want
//#define CName CValue

#include<stdio.h>
#define Abc 22
#define def 4/2
#define X 3];
#define R 5
#define C 6

int main()
{
    int x=Abc;
    int age=def;
    int arr[X
    int arr[R][C];

    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {

        }
    }

    return 0;
}

////////////////////////////////////////////////////
///////////////////////////////////////////////////////
//Function: some piece of code grouping together with 
//specif name
////////////when you wanna execute
// this code,you can call that name

///function must come before main()

int main()
{
    printf("Hello");
    printf("GM");
    printf("Gbye");
    //
    //
    //
    //
    printf("Hello");
    printf("GM");
    printf("Gbye");
    //
    //
    //
    printf("Hello");
    printf("GM");
    printf("Gbye");
    return 0;
}

//Copy&paste -> bad programming
//cost of creation
//cost of modification

//solution ->  loops? No

//we can put this code
//under specific name
//when we need it
//just call that name

//thats called FUNCTION


/////////////////////////////////////////////////////
//function syntax

// ReturnType FunctionName(input parameter/s)
// {
//     //code here
// }

//if you dont want to return anything [void]
//function return void is called directly

///ReturnType
//int
//char
//Premitive DT

//if function return any premitive DT
//fn body must contains keyword [return VALUE] 

#include<stdio.h>

void Welcome()
{
    printf("Hello");
    printf("GM");
    printf("Gb");
}

int main()
{
    //how to call function
    Welcome();
    //
    //
    //
    Welcome();
    //
    //
    //
    Welcome();
    return 0;
}

//////////////////////////////////////////
//SOLID Principles
//S-> Single Responsibility
//////////////////////////////////////////
void Add()
{
    int x,y,z;
    printf("Enter x\n");
    scanf("%d",&x); //3
    printf("Enter y\n");
    scanf("%d",&y); //4
    z=x+y;
    printf("%i+%i=%i",x,y,z); //3+4=7
}

int main()
{
    Add();
    return 0;
}

///////////////////////////////////////

void Add(int left,int right)
{
    int z=left+right;
    printf("%d",z);
}
int main()
{
    int x=3;
    int y=4;

    //Add(); //Compile Error there is no fn take Zero Params
    Add(x,y); //Compiler Passes VALUES -> Add(3,4);
    return 0;
}

///////////////////////////
int Add(int left,int right)
{
    //int z=left+right;
    //return z; //Compiler Returns VALUE  -> return 7 
    return left+right;
}

int main()
{
    int x=4;
    int y=6;

    //Add(x,y); //PASS VALUES
    //When run ->o/p will not show anything
    //Add(x,y); -> 10;

    int result= Add(x,y); //int res=10;
    printf("%i",result);

    printf("%i",Add(x,y));

    return 0;
}

/////////////////////////////////////////////////

int Add(int x,int y)
{
    return x+y;
}

//Compile Error -> Add is used before
//overloading is not supported in c
//default argument also not supported in c
int Add2(int x,int y,int z)
{
    return x+y+z;
}

int Add3(int x,int y,int z,int a)
{
    return x+y+z;
}

int main()
{
    //print Add(3,4);
    //print Add2(3,4,5);
}


//////////////////////////////////////////////////
//you can write All function below main 
//with Function Prototype [header only] before main
int Add(int x);
int Add2(int x,int y);
int Add3(int,int,int);
int main()
{
    int res=Add2(3,4); //Compile Error Add2() is not defined
    return 0;
}
int Add(int x)
{
    return x;
}
int Add2(int x,int y)
{
    return x+y;
}
int Add3(int x,int y,int z)
{
    return x+y+z;
}

//////////////////////////////////////////////////////
//Memory Types
//Stack ->any variable studied before + funtcion call
//Heap -> dynamic allocation
//Data Segment [BSS] global,static

/////////////////////////////////////////////////////
//Variables:
//1-Local Variable
//2-Global Variable
//3-Static Variable


///1- Local Variable
//-variable declared any scope() {}
//-access: any code below it inside scope
//life time: till end of its scope
//Storage: in Stack
#include<stdio.h>

int Add(int x,int y) //x,y,z local variable
{
    int z;
}

int Add2(int x,int y) //x,y,z local variable
{
    int z;
}

int main()
{
    
    //a=44; //Compile Error
    int a; //localV
    //x=22; //compile Error
    for(int i=0;i<5;i++) //i->localV
    {
        
    }
    //
    //i=22; //Compile Error
    //
    for(int i=0;;){}

    do
    {
        int result;
    }
    while(result==10); //compile Error

    {
        int a;
    }
    
    int a=22;

    return 0;
}



//2-Global Variable [Rarely commonly used]
//-variable declared outside any scope [before main]
//access: any code in program
//lifetime:alive till end of application
//storage: data segment[BSS]

#include<stdio.h>
int result;
int x=22;
int i=0;
int Add()
{
    result=33;
}

int main()
{
    result=44;
    
    int x=100; //Runs Successful

    printf("%d",x);  //100
    x=-10; // local

    printf("%d",::x);  //22
    ::x=-10; // global

    for(int i=0;;){}
    return 0;
}



//3-Static Variable  -> rarely used
//-local variable with keyword static
//-variable that O.S will make ONLY ONE AND ONLY ONE copy of it 
//-access:any code inside scope
//-lifetime: alive till end of application
//-storage: in BSS[Data Segment]
//static variable is initiated by zero
void TryMe()
{
    static int x;  //Compiler will execute this line of code first time only regardless number of function calling
    x++;
    printf("%d",x);
}

int main()
{
    TryMe();
    TryMe();
    TryMe();
    //o/p
    //1
    //2
    //3
}

////////////////////////////////////////////////////
//Lab Assignment
//READ ALL DATA FROM USER IN RUNTIME  scanf
//int arr[10]={1,2,3,4,5};  XXXX
//EACH LAB IN SEPARATE PROJECT

//1D Array size 10
//1- min value , max value    7,5,3,2,3,5,6,-1
//2- sort   in main           -1,2,3,3,5,5,6,7
//3- seach on number and retrieve ALL of it index
//3_1- seach on number and retrieve fst index

//2D Array
//4- array [3][4]  =>average [float] of cols

//5-Multiply 2 matrixs   3*2   * 2*1    =  3*1

//Bonus: Multiply
//                   3*3    *  3*2   = 3*2

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
Mul()

main()







