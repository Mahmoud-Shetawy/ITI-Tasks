//Arrays
//Functions
//Variables
//Preprocessor #define
//Memory
//ASCII & extended ascii
///////////////////////////////////////////////////////
int main()
{
    int x=10;
    double y=20;
    int arr[3];
    printf("%i",sizeof(x)); //4
    printf("%i",sizeof(int)); //4
    printf("%i",sizeof(y)); //8
    printf("%i",sizeof(double)); //8
    printf("%i",sizeof(arr)); //12
}

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

///fixed size collection of data with same 
//DT stored sequentially in memory

// int x=10; //4byte
// x=20;
//DTName variableName[arraySize];
// //int arr[3];
//stored collection of three integers 
//stored sequentially in memory
//under the name of arr
//Size of arr = 3 * sizeof(int)=3*4=12B

 //variable carries collection of 3 integers stored
//             //sequentially in memory
//             //size 3*4 Bytes


// int arr[10]; //memory//|1|#|#|#|#|9|#|#|#|#|
// //              //index 0 1 2 3 4 5 6 7 8 9
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
//LValue   RValue
//////////////////////////////////////////////////

//declare array and put data into it

#include<stdio.h>
int main()
{
    int arr[5];  //memory arr |#|#|#|#|#|   0x10
    
    //effort redundant
    arr[0]=10;
    arr[1]=20;
    arr[2]=30;
    arr[3]=40;
    arr[4]=50;
int numbers[5] = {10, 20, 30, 40, 50};
    printf("%i\n",arr[0]);
    printf("%i",arr[1]);
    printf("%i",arr[2]);
    printf("%i",arr[3]);
    printf("%i",arr[4]);


    //
    for(int i=0;i<5;i++)
    {
        printf("Enter # at index %i\n",i);
        scanf("%i",&arr[i]);
    }
    //
    for(int i=0;i<5;i++)
    {
        printf("# at index %i is %i\n",i,arr[i]);
    }
    return 0;
}




///Array itself value
int main()
{
    // int arr[5]; 
    // //memory arr|11|22|33|44|55|    0x55
    // printf("%i",arr[1]); //22
    // printf("%x",arr); //0x55

    // int x;
    // scanf("%i",&x);
    int arr[5];

    //arr itself is an address
    //VERY IMPORTANT .....
    //arr itself is an address fst element in array
    //arr Always is an address fst element in array
    
    //read integer from user and
    //put it into first element of array
    scanf("%i",arr[0]); //XXXX
    scanf("%i",&arr[0]); //T
    scanf("%i",arr); //T
    scanf("%i",&arr); //T
    //arr ====&arr   = 0x10

    
    int arr2[5];
    arr2[5]=55;   //WRONG
    //out of bounds of array
    //no Compile Error
    //May not fire runtime error
    //most -> no runtime error
    //printf %i arr[5]   &^%$#$%^

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

    int arr[5]; //|#|$|%|$|#|
    int arr[10]={1,2,3,4,5,6,7,8,9,10};  //|1|2|3|4|5|6|7|8|9|10|
    int arr[5]={1,2,3,4,5};
    int arr[10]={0,0,0,0,0,0,0,0,0,0};
    int arr[10]={1,2,3}; //|1|2|3|0|0|0|0|0|0|0|
    int arr[10]={0};
    int arr[5]={1,2,3,4,5,6,7,8,9,10}; //T
    int arr[]; //COMPILE ERROR
    int arr[]={1,2,3,4,5}; //T

    
    // int arr[10];
    // arr=33; 
    // //REMEMBER arr itself address fst element 
    // //of array always ever CANNOT BE CHANGED
    // arr=&arr[2];
    // //compile Error LValue

     int arr[10];
     arr={1,2,3,4,5,6,7,8,9,10}; //Compile Error
    // arr[0]={1,2,3,4,5,6,7,8,9,10}; //Compile Error
    // //REMEBER
    // //Array default values 
    // //Must be with array declaration
    // //int arr[5]={3,4,5,6,7};

    //BIG COmpile Error
    //default values WITH ARRAY DECLARATION
    //int arr[10]; //|#|#|#|#|#|#|#|#|#|#|
    //arr[0]={1,2,3,4,5};

    ////not standard -> work properly with gcc ->borlandc compile eror
    //int size=0;
    //printf("Enter array size\n");
    //scanf("%d",&size);//5
    //int arr[size];
    //int arr[size]={1,2,3,4,5}; //compile Error
    ////standard?  Dynamic alocation later

}
///////////////////////////////////////////////////////
//2D Array
//int arr[rowsize][colsize]

int main()
{
      int arr[3][4];
      arr[0][0]=1;  
      arr[0][1]=2;  
      arr[0][2]=3;  
      arr[0][3]=4;  
      arr[1][0]=5;  
      arr[1][1]=6;  
      arr[1][2]=7;  
      arr[1][3]=8;  
      for(int i=0;i<3;i++)
      {
            for(int j=0;j<4,j++)
            {
                printf("Enter # at index %i,%i\n",i,j);
                scanf("%i",&arr[i][j]); //200
            }
        }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4,j++)
        {
            //printf("# at index %i,%i is %i\n",i,j,arr[i][j]);
            printf("%i\n",arr[i][j]);
        }
    }
}


int main()
{
    int arr[3][4];
    //see memory
}

//calculate sum of each row
int main()
{
    int arr[3][4];
    int sum[3]={0}; //REMEMBER 
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4,j++)
        {
            printf("Enter # at index %i,%i\n",i,j);
            scanf("%i",&arr[i][j]); //
        }
    }

    for(int i=0;i<3;i++)
    {
        
        for(int j=0;j<4;j++)
        {
            sum[i]+=arr[i][j];
        }
    }

    for(int i=0;i<3;i++)
    {
        printf("%i",sum[i]);
    }
}

//////////////////////////////////////
//default values with 2d Array
int main()
{
    int arr[3][4]={{1,1,1,1},{2,2,2,2},{3,3,3,3}};
    int arr[2][4]={{1,1,1,1},{2,2,2,2}};
    int arr[][]; //Compile Error
    int arr[][]={{1,1,1},{2,2,2},{3,3,3}};
    int arr[][]={{1,1,1},{2,2,2},{3,3,3,3,3}};
    //arr[0][0]=1000;
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
#define ABC 10
#define ROW 5
#define COL 6 
#define XYZ 3];  //NOT RECOMMENDED
int main()
{
    int arr2[XYZ
    int x=ABC;
    int arr[ROW][COL];
    for(int i=0;i<ROW;i++)
    {    
        for(int j=0;j<COL;j++)
        {}
    }
   for(int i=0;i<ROW;i++)
    {    
        for(int j=0;j<COL;j++)
        {}
    }
   
    return 0;
}

///////////////////////////////////////////////////////
//Function
int main()
{
    printf("Hello");
    printf("Good Morning");
    printf("Good Bye");
    //
    //
    //
    //
    //
    printf("Hello");
    printf("Good Morning");
    printf("Good Bye");
    //
    //
    //
    //
    printf("Hello");
    printf("Good Morning");
    printf("Good Bye");
    return 0;
}

//Copy&Paste => Bad Programming
//effort redundant
//cost of declaration
//cost of modification

//Solution ??? for loop ?? No

//group that code with specific name
//when need that code , call that name

//Function:
///1-some sort of code grouping together
///with specific name
///2-when to use that code ,,, call that name
///3- function must come before main  ->prototype
///Function Syntax

///ReturnType FunctionName(input parameter/s)
//{
    //code here
//}

//Return types
//return nothing -> void
//int,float ,array ,,.....
//if function return value
//IT MUST ENCLOSED BY KEYWORD NAMES
//return

///////////////////////////////////////////

#include<stdio.h>

void TryMe()
{
    printf("Hello");
    printf("Good Morning");
    printf("Good Bye");
    printf("------------------");
}

int main()
{
    //calling function
    TryMe();
    //
    //
    //
    TryMe();
    //
    //
    return 0;
}

////////////////////////////////////////////////
///SOILD Principles
//S -> single responsibility
void Add()
{
    int x,y,result;
    printf("Enter x\n");
    scanf("%i",&x);
    printf("Enter y\n");
    scanf("%i",&y);
    result=x+y;
    printf("%i",result);
}

int main()
{
    Add();
    
    return 0;
}
//////////////////////////////////////
//v2
//            11        22
void Add(int left,int right)
{
    int result;
    result=left+right;
    printf("%i",result); //33
}

int main()
{
    int x,y;
    printf("Enter x\n");
    scanf("%i",&x); //11
    printf("Enter y\n");
    scanf("%i",&y); //22
    
    //Add(); //Compile error
    Add(x,y); //Pass Values -> Add(11,22)
    return 0;
}
///////////////////////////////////////////////
//v3
//            11        22
int Add(int left,int right)
{
    int result;
    result=left+right;
    return result;  //Compiler retrns value -> return 33;
    //unreachable code
    return left+right;
}

int main()
{
    int x,y;
    printf("Enter x\n");
    scanf("%i",&x); //11
    printf("Enter y\n");
    scanf("%i",&y); //22
    
    
    Add(x,y); //Pass Values -> Add(11,22)
    //nothing happened ?? Why?

    int result=Add(x,y);
    printf("%i",result);

    printf("%i",Add(x,y));

    return 0;
}
///////////////////////////////////////////////
#include<stdio.h>
int Add(int left,int right);
int Add2(int left,int middle,int right);
int main()
{
    int result=Add(11,22); 
    //without prototype compile Error Add(int,int) not declared
    return 0;
}

int Add(int left,int right)
{
    return left+right;
}

int Add2(int left,int middle,int right)
{
    return left+middle+right;
}
///////////////////////////////////////////////////
//Overloading is not supported in c
//Default argument is not supported in c
////////////////////////////////////////////////
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
    //x=44; //XXX
    
    
}
int main()
{
    int x,y;
    //c=33; //XXX
    Add(33,44);

    for(int i=0;i<65;i++)
    {
        i=22;
    }
    //i=100 ; XXXX
    ///->>>HERE
    do
    {
        int flag;
    }
    while(flag==100); //compile error

    return 0;
}


///////////////////////////////////////////////////////
///2- Global variable
///////Variable declared outside any scope [before main]
///////access: any code in program
///////lifetime: at end of program
///////storage : Data Segment [bss]
#include<stdio.h>

int result=100;

void PrintMe()
{
   result=1;
}
int main()
{
    //result=3;
    //PrintMe();
    //print result  //100
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
    //1
    //1
    //1
    
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
//
//
void PrintMe()
{
    static int x;  //Execution Fst time ONLY  //BSS    x  3
    x++;
    printf("%d",x);
}
//
//
int main()
{
    //x=22;  //WRONG local variable
    PrintMe();  //1
    PrintMe();  //2
    PrintMe();  //3
    ///
    //x=22; //XXXX
    ///
    ///o/p
    ///1
    ///
    return 0;
}
////////////////////////////////////////////////
//program to input key and print ascii

int main()
{
    char ch;
    printf("Enter Key");
    scanf("%c",&ch);
    printf("ASCII = %i",ch);
    return 0;
}

//o/p
//enter key


//////////////////////////////////////////
//scanf
//scanf works with printed keys ONLY
//You must press Enter to process next

////////////////////////////////////////////
//syntax
//char getch(){}
//char getche(){}


///read any key -printed or - non printed keys then returns it direct
///can process without press enter
///getch() cannot print pressed key

//program to identify ascii for any normal ascii
int main()
{
    char ch;
    printf("Enter Key");
    ch=getch();
    printf("ASCII = %i",ch);
    return 0;
}



//program to identify ascii for any Extended ascii
int main()
{
    char ch;
    printf("Enter Key");
    ch=getch();
    ch=getch();
    printf("ASCII = %i",ch);
    return 0;
}

///////////////////////////////////////////////
//program to identify ascii for any normal or Extended ascii

int main()
{
    char ch;
    printf("Enter Key");
    ch=getch(); //up

    //NOOOOOOOOOOOOOOOO
    //if(isprint(ch)){}
    //

    if(ch==-32)
    {
        //extended
        ch=getch();
        printf("Extended key with ascii NULL|%i",ch);
    }
    else
    {
        //normal
        printf("normal key with ascii %i",ch);

    }

    switch(ch)
    {
        case -32:
        ch=getch();
        printf("Extended key with ascii %i",ch);
        break;
        default:
        printf("normal key with ascii %i",ch);
        break;
    }



    return 0;
}

//////////////////////////////////////////////////

//getchar()===> search
//getch()===> 
//getche()===> 

//////////////////////////////////////////////////////
///Lab Assignments

///Arrays of 15 places of integer int arr[15]
///Read ALL Data From user in Runtime
//XXX int arr[15]={1,2,3,4,5,6,7,8,9,0};

//1D Array
//1-Array min  and max value  |7|3|5|6|8|-1|-11|33|99| no built in fn
//2-Array sort    same array            |-11|-1|3|5|6||||||no built in fn
//3-search on array and return index
 |1|2|3|4|1|5|6|2|1|9|10|

//which number you want to search
///4
//done at index 3



//5-2D Array
//array [3][4]
//calculate average of columns
//int avg[4]

//6-Bonus multiply 2 matrix
//3*2    *  2*1  =  3*1


//7- bonus 3*3     *    3*2   =  3*2


//8-Calculator with function
int Add(int ,int)
Sub(,)
Div(,)

Main()
{}


//
///9- //program to identify ascii for any normal or Extended key
//////////////////////////////////////////////////////////