//casting
//pointers revision
//dynamic allocation
//recursive function
////////////////////////////////////////////////////////
int main()
{
    int x=10;   //Address =>0x10
    int * ptr;  //Address =>0x20
    ptr=&x;
    
    printf("%d",x);    //10
    printf("%x",&x);   //0x10
    printf("%d",*x);   //Compile Error

    printf("%x",ptr);   //0x10
    printf("%x",&ptr);  //0x20
    printf("%d",*ptr);  //10
    return 0;
}
///////////////////////////////////////////////////////////
int main()
{
    int x=1,y=2,z=3,c=4;

    int* ptr[4];   //Array of pointers   //4*4B   |#|#|#|#|

    //default values
    int* ptr2[4]={x,y,z,c};  //WRONG
    int* ptr2[4]={&x,&y,&z,&c};  

    //ptr=x;//???
    ptr=&x; //
    ptr[0]=&x;  ///ptr[0]====ptr
    ptr[1]=&y;
    ptr[2]=&z;
    ptr[3]=&c;

    /*
    ptr=&x;
    ptr++;
    ptr=&y;
    ptr++;
    ..
    ///WRONG =>ptr=> constant pointer
    */

    return 0;
}
////////////////////////////////////////////////////////
int main()
{
    int arr[4]={1,2,3,4};
    int* ptr[4];           //|address arr[0]|address arr[1]|..|..|

    int* ptr2[4]={arr,&arr[1],&arr[2],&arr[3]};


    /*
    ptr=arr; //Compile Error
    ptr[0]=arr; //T
    ptr[0]=&arr;

    ptr[1]=&arr[1];
    //or
    ptr[1]=arr+1; //not recommended
    */
}

//////////////////////////////////////////////////////////////////////////
//Casting
///Convert value from data type to another data type
//casting
//data type can be converted to another one ,,, True
//latest c Versions , this will be done Implicitly
//Implicitly =>compiler will do it itself 
//Explicitly => you [developer ] will do it yourself

int main()
{
    int x=22;   //4B
    double y=33;//8B

    ////Implicit casting
    //y=x;

    ////Explicit Casting => in c=>no need to explicit cast
    //y=(double)x;

    x=y;
    x=(int)y;



    printf("x=>%d",x); //33
    printf("y=>%lf",y); //33


    return 0;
}

////////////////////////////////////////
int main()
{
    int x=2billion;   //4B   //2Billion
    double y=5555Billion;//8B   //5555B

    ///Safe casting
    //y=x;
    //y=(double)x;


    //unsafe casting
    //Compiler will not fire any Error  //NO RUNTIME ERROR
    x=y; 
    x=(int)y; 

    printf("x=>%d",x); //-15416141455
    printf("y=>%lf",y); //5555B


    return 0;
}

/////////////////////////////////////////////////////
//Promotion
//int -> float -> long -> double

int main()
{
    int x=2B;
    int y=2B;
    double z;

    z=(double)x+y;

    print(x); //2B
    print(y); //2B
    print(z); //4B  => explicit cast


    int a=3,b=4;
    float c;
    c=(float)a/b;

    return 0;
}

////////////////////////////////////////////

int main()
{
    char ch='M';
    int x=3;

    int z=x+ch;  //done implicitly

    print (z); //80
}

////////////////////////////////////////////////
//Pointer to void

int main()
{
    int x=22;          //address 0x10
    void* ptr =&x;     //address 0x20

    printf("%d",*ptr);  //Compile Error

    //work around soln;
    int* tmpPtr=ptr;  //Casting done Implicitly
    int* tmpPtr=(int*)ptr; //explicit cast //unnecessary
    printf("%d",*tmpPtr);


    //another soln
    printf("%d",*((int*)ptr));  // 22
}

//////////////////////////////////////////////////////////////
//array of 24 students
//salma   +1   => 25
//array resized to 25 students=> Impossible


//////////////////////////////////////////////////////////////
//dynamic Allocation

//array => fixed size
/////we cannot declare array based on specific/different size in runtime
/////array when declared ,cannot be modified or deleted ->end of scope

//RUNTIME 
////think to allocate dynamic place in runtime
////based on specific value



/////dynamic allocation
///allocate specific value/values in runtime
///based on specific size 
///Stored in Heap  =>c,c++,java,c#

//syntax      HLL===>new
//in c
/////    void* malloc(size in bytes); 

//////////////////////////////////////////////////////
#include<stdlib.h>
int main()
{
    int* ptr;

    ptr=(int*)malloc(16);
    //No need to Explicit cast
    ptr=malloc(17);  //Compiler   ptr=(int*)malloc(16);
    //casting will be done implicitly

    char* cptr;
    cptr=(char*)malloc(5);
    cptr= malloc(5);
}


/////////////////////////////////////////////////////////

int main()
{
    int * ptr;

    ptr=(int*)malloc(16);

    *ptr=10;
    ptr++;
    *ptr=20;
    ptr++;
    *ptr=30;
    ptr++;
    *ptr=40;
    /*ptr++;
    *ptr=50;*/

   //DANGEROUS CODE
   //PTR Will Not Know fst Element of Allocated data

}

////////////////////////////////////////////////////////////


int main()
{
    int * ptr;
    ptr=(int*)malloc(15); //Allocated data will not fit 4 integer numbers
    ptr=(int*)malloc(16);

    //ptr point array of integers
    //when pointer point array of integer
    //it acts like an array [indexer]

    ptr[0]=10;
    ptr[1]=20;
    ptr[2]=30;
    ptr[3]=40;

    //Ptr value will not be changed

    //not recommended
    //but //Ptr value will not be changed
    *ptr=10;
    *(ptr+1)=20;
    *(ptr+2)=30;
    *(ptr+3)=40;


    //Print  //RECOMMENDED
    printf("%d",ptr[0]);
    printf("%d",ptr[1]);
    printf("%d",ptr[2]);
    printf("%d",ptr[3]);


    //
    printf("%d",*ptr);
    printf("%d",*ptr+1);
    printf("%d",*ptr+2);
    printf("%d",*ptr+3);

    //WRONG
    printf("%d",*ptr);
    ptr++;
}

//////////////////////////////////////////////////

int main()
{

    char * ptr;
    ptr=(char*)malloc(10);


    *ptr='A';
    *(ptr+1)='h';
    *(ptr+2)='m';
    *(ptr+3)='e';
    *(ptr+4)='d';
    *(ptr+4)='\0';

    ptr[0]='A';
    ptr[1]='h';
    ptr[2]='m';
    ptr[3]='e';
    ptr[4]='d';
    ptr[5]='\0';


    gets(ptr);
    scanf("%s",ptr);



    //
    puts(ptr);
    printf("%s",ptr);
    
    //With while untill \0
    printf("%c",*ptr);
    printf("%c",ptr[0]);




    //int *ptr
    ///after dunamic allocation
    //it acts like int ptr[size]
    ///int*ptr  ===== int ptr[size]
    ///char* cptr =====char cptr[size] 
}

///////////////////////////////////////////////////////

///Enter size in bytes ???

///Enter student Number???

int main()
{
    int studentSize;
    int *ptr;


    printf("How many Students will you Enter?\n");
    scanf("%d",&studentSize); //10

    ptr=/*(int*)*/ malloc(10 * 4);
    ptr=/*(int*)*/ malloc(studentSize * sizeof(int));


    int charsize;
    char* cptr;

    printf("How many Characters will you Enter?\n");
    scanf("%d",&charsize); //10

    cptr= malloc(charsize * sizeof(char));

}

////////////////////////////////////////////////
//Dynamic Allocation

///You can allocate any time you want while app is RUNNINg
///You can dellocate any time you want to keep Memory free

int main()
{
    int *ptr=/*(int *)*/malloc(10 * sizeof(int));

    //After Allocation
    ///int*ptr ====int ptr[10]
    for (int i = 0; i < 10;  i++)
    {
        scanf("%d",&ptr[i])
    }
    for (int i = 0; i < 10;  i++)
    {
        printf("%d",ptr[i])
    }
    
    //deallocate array from heap
    free(ptr);
    //
    ///free -> remove protection for allocated bytes
    ///so that any app can write in this place
    ///REMEMBER
    //ptr will still carries 0x10 =>undefined address
    //free doen't remove values => remove protection 
}
///////////////////////////////////////////////////////////
///Free -> WHY?????
void TryMe()
{
    int *ptr=malloc(5* sizeof(int));
    //
    //free(ptr);
    //
}

int main()
{
    TryMe();
    TryMe();
    TryMe();
    TryMe();
    ///Dangerous MEMORY LEAkage
    ///
    ///
    ///
}
//////////////////////////////////////////////////////////
///dynamic allocate Array of pointers

int main()
{
    int* ptrarr[3];
    

    ptrarr[0]=malloc(10* sizeof(int));
    ptrarr[1]=malloc(10* sizeof(int));
    ptrarr[2]=malloc(10* sizeof(int));

    ///int* ptrarr[3]  ===> int ptrarr[3][10]
    //2d Array

    ptrarr[0][0]=100;


    //
    free(ptr[0]);
    free(ptr[1]);
    free(ptr[2]);

}

////////////////////////////////////////////////////

int main()
{
    int row, col;

    printf("Enter # of Rows\n");
    scanf("%d",&row);//3
    printf("Enter # of Columns\n");
    scanf("%d",&col);//4

    int **ptrarr;

    ptrarr=malloc(row * sizeof(int*));

    ptrarr[0]=malloc(col * sizeof(int));
    ptrarr[1]=malloc(col * sizeof(int));
    ptrarr[2]=malloc(col * sizeof(int));

    ///int **ptrarr  --> malloc -> int * ptrarr[3]

    //int * ptrarr[3] + 3 malloc  int ptrarr[3][4]

    ptrarr[0][0]=100;

    //WRONG
    free(ptrarr);

    //Perfect
    free(ptrarr[0]);
    free(ptrarr[1]);
    free(ptrarr[2]);
    //then
    free(ptrarr);

}


///WRONG CASE  ===> try it ans see whats happened in ptrarr[0][0]=100;
int main()
{
    int row, col;

    printf("Enter # of Rows\n");
    scanf("%d",&row);//3
    printf("Enter # of Columns\n");
    scanf("%d",&col);//4

    int *ptrarr;

    ptrarr=malloc(row * sizeof(int*));

    ptrarr[0]=malloc(col * sizeof(int));
    ptrarr[1]=malloc(col * sizeof(int));
    ptrarr[2]=malloc(col * sizeof(int));

    ///int **ptrarr  --> malloc -> int * ptrarr[3]

    //int * ptrarr[3] + 3 malloc  int ptrarr[3][4]

    ptrarr[0][0]=100;

}


/////////////////////////////////////////////////////////////

//void PrintArray(int param[],int size)
void PrintArray(int* param,int size)
{
    param[0]=22;
    param[2]=44;
    for loop
     print param[i]    22,2,44,4,5,,,,,
}


int main()
{
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    PrintArray(arr,10);   //(0x10,10)

    for loop 
    print arr[i]  22,2,44,4,5,,,,,,, 

    return 0;
}


/////////////////////////////////////////////////

int* getArray()
{
    int arr[10]={1,,,,10};
    return arr;
}

int** get2DArray()
{
    int arr[10][3]={1,,,,10};
    return arr;
}

int main()
{
    int *ptr=getArray();

    ptr[0]=100;//runtime error
    return 0;
}


//////////////////////////////////////////////////

int* getAnotherArray(int size)
{
    int *ptr;
    ptr=malloc(size * sizeof(int));
    //int ptr[10]
    return ptr;
}

void getAnotherArray2(int size)
{
    int *ptr;
    ptr=malloc(size * sizeof(int));
    //int ptr[10]
    //forgot free   free(ptr);
    //memory leackage
}

main()
{
    int* x=getAnotherArray();
    x[0]=22; //TRUE


    getAnotherArray2();
    getAnotherArray2();
    getAnotherArray2();
    getAnotherArray2();
    getAnotherArray2();

    return 0;
}


/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////
///recursive function
//function calls itself
//functions contain
//1- for loop plus
//2- it ends with certain break
////1     0

//3- use with programming/mathematical equations
///

///Stack Overflow
void Print()
{
    print();
}
main()
{
    print();
}

/////////////////////////////////////////////////////////////
///Factorial

int Factorial(int num)
{
    if(num==1)
    {
        return 1;
    }
    else
    {
        return num * Factorial(num-1);
    }
}


int main()
{
    int res= Factorial(4);
}
