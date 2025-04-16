//casting
//pointers revision
//dynamic allocation
//recursive function
////////////////////////////////////////////////////////
int main()
{
    int a=1,b=2,c=3,d=4;
    int* ptrarr[4];  //4*4B  or 4*8B
    //put in fst elemt of array address of a
    ptrarr[0]=a; //F
    ptrarr[0]=&a; //T
    ptrarr=&a;  //F //LValue -> constant address

    *ptrarr=a; //F     
    *ptrarr=&a; //T
    ptrarr[0]=&a;
    ptrarr[1]=&b;
    ptrarr[2]=&c;
    ptrarr[3]=&d;

    int* ptrArr[4]={&a,&b,&c,&d};

    ///array of pointers   |address|address|address|address|
    ///ptrarr itself address fst element of array
    // ptrarr   |add a| add b|add c|add d|
    ptrarr=a; //
    ptrarr=&a;//
    ptrarr[0]=a; //                                   //logic Error cause Runtime error
    ptrarr[0]=&a; //
    ptrarr[1]=&b; //
    ptrarr[2]=&c; //
    ptrarr[3]=&d; //

    

}

int main()
{
    int arr[4]={1,2,3,4};  
    int* ptrArr[4];
    
    ptrArr=arr; //F   //lvalue
    ptrArr[0]=arr;//T
    ptrArr[0]=&arr;//T
    *ptrArr=arr; //T
    ptrArr[0]=arr; //T
    *ptrArr=&arr;//T
    *ptrArr=arr[0]; //F
    //ptrArr   |Add arr[0]|Add arr[1]|Add arr[2]|Add arr[3]|    
    ptrArr=arr; //
    ptrArr[0]=arr; //
    ptrArr[0]=&arr;//
    ptrArr[0]=arr[0];//
    ptrArr[0]=&arr[0];//
    ptrArr[1]=&arr[1];//
    *ptrArr=arr; //RValue
}
/////////////////////////////////////////////
//Casting
///Convert value from data type to another
// data type
//casting
//value of data type can be converted to another one ,,, True
//latest c Versions , this will be done Implicitly
//Implicitly =>compiler will do it itself 
//Explicitly => you [developer ] will do it yourself


int main()
{
    int x=22;      //4B   //+-2Billion
    double y=33;   //8B   //444Billion

    //safe casting
    //implicit casting
    //y=x;

    //explicit casting [USELESS]
    //y=(double)x;

    //unsafe casting-> developer will do business himself
    //implicit casting
    x=y;   ///No Error

    //explicit casting [USELESS]
    x=(int)y;

    printf("%d",x);  //Rubbish
    printf("%lf",y); //444B

}


int main()
{
    int x=3;
    int y=4;
    float z;

    z=x/(float)y;

    printf("%f",z); //0.75

}
//////////////////////////////////////
///promotion
///char->int -> long -> float -> double

int main()
{

    char ch='M'; //77
    int x=3;

    int z=x+(int)ch;   //[useless]
    printf("%i",z); 80;

    //print z   80
}

//////////////////////////////////////////
///GPP Pointer

int main()
{
    int x=10;   // |10| 0x10
    void *ptr=&x;  //|0x10| 0x20

    printf("%x",ptr); //0x10
    printf("%x",&ptr); //0x20
    printf("%x",*ptr); //Compile Error

    //workaround soln
    //casting  [Implicitly]
    //int* tmpPtr= ptr;
    //casting  [Explicitly] //Useless
    int* tmpPtr= (int*)ptr;
    printf("%x",*tmpPtr); //10

    //another soln
    //casting [Explicit]
    printf("%i", *((int*)ptr) ); //10
}

////////////////////////////////////////////////////
//array of 24 students

//array resized to 25 students=> Impossible

//////////////////////////////////////////////////////////////
//dynamic Allocation

//array => fixed size
/////we cannot declare array 
//based on specific/different size in runtime
/////array when declared ,
//cannot be modified or deleted ->end of scope

//RUNTIME 
////think to allocate dynamic place in runtime
////based on specific value/size
//think of deallocate this place whenever i want


/////dynamic allocation
///allocate specific value/values in runtime
///based on specific size 
////deallocate whenever i want to.
///Stored in Heap  =>c,c++,java,c#

//syntax      HLL===>new
//in c   stdlib.h
/////    void* malloc(size in bytes){code} 
//allocate based on size
//then returns address fst byte
//of allocated data as a void*
//////////////////////////////////////////////
#include<stdio.h>
#include<stdlib.h>  //malloc()
int main()
{
    //malloc(16);
    //allocate 16 bytes in heap
    //and return address of fst Byte 

    //implicit cast
    int* ptr= malloc(16);

    //explicit cast -> useless  ///this is done impicitly
   int* ptr2=(int*) malloc(16);
}

//////////////////////////////////////////
//fullfill places with 4 integer values
int main()
{
    int*ptr= (int*) malloc(16);

    //2 double values 
    double* dptr=/*(double*)*/malloc(16);

    //5 characters
    char *cptr= malloc(5);
}




int main()
{
    char *ptr=  malloc(16);

}

////////////////////////////////////////////////
///Remember when to store integer values
///you must allocate based on its size in bytes CAREFULLY
//int _size
///please enter size of numbers in bytes
//scanf %i  _size    20
//int *ptr= malloc(_size);

//int _size
///please enter size of numbers 
//scanf %i  _size    5
//int *ptr= malloc(_size * sizeof(int));

int main()
{
    
    //int *ptr= (int*) malloc(16);
    int _size;
    printf("Enter Array Size\n");
    scanf("%i",&_size);

    int *ptr=(int*) malloc(_size * sizeof(int));
    //from this moment
    //int *ptr after malloc
    //=== int ptr[5];
    

    //write values in allocated palces
    //v1
    //Very dangerous
    //DON't move and change ptr value in memory 
    *ptr=10;
    ptr++;
    *ptr=20;
    ptr++;
    *ptr=30;
    ptr++;
    *ptr=40;

    //v2  //move ptr without change its value in memory
    *(ptr+0)=10;
    *(ptr+1)=20;
    *(ptr+2)=20;
    *(ptr+3)=20;

    //v3 //most commonly used
    ///when pointer points array , it acts like array [indexer]
    ptr[0]=10;
    ptr[1]=20;
    ptr[2]=30;
    ptr[3]=40;

}

int main()
{
    int _size;
    printf("Enter Array Size\n");
    scanf("%i",&_size); //5
    double *dptr=(double*)malloc(_size * sizeof(double));
    //from this moment 
    //double* dptr=double dptr[5];
    dptr[0]=1;
    dptr[0]=2;
    dptr[0]=3;
    dptr[0]=4;
    dptr[0]=5;
}

//////////////////////////////////////////
///read data from user in runtime
int main()
{
    int _size;
    printf("Enter Array Size\n");
    scanf("%i",&_size); //5
    int *ptr=malloc(_size * sizeof(int));
    
    //v1  [Dangerous]
   for(int i=0;i<_size;i++)
   {
        printf("Enter # at index %i\n",i);
        scanf("%i",ptr);
        ptr++;
   }
   
    //v2
    for(int i=0;i<_size;i++)
    {
        printf("Enter # at index %i\n",i);
        scanf("%i",(ptr+i));
        
    }
    
    for(int i=0;i<_size;i++)
    {
        printf("# at index %i=%i\n",i,*(ptr+i));
    }
    //v3 MCU
   for(int i=0;i<_size;i++)
    {
        printf("Enter # at index %i\n",i);
        scanf("%i",&ptr[i]);
        
    }
    
    for(int i=0;i<_size;i++)
    {
        printf("# at index %i=%i\n",i,ptr[i]);
    }
}

int main()
{
    char* ptr=/*(char*)*/ malloc(20);

    *ptr='A';
    ptr++;
    *ptr='l';
    ptr++;
    *ptr='i';
    ptr++;
    *ptr='\0';
    

    *(ptr+0)='A';
    *(ptr+1)='l';
    *(ptr+2)='i';
    *(ptr+3)='\0';

    ptr[0]='A';
    ptr[1]='l';
    ptr[2]='i';
    ptr[3]='\0';

    gets(ptr);
    scanf("%s",ptr);
}

////////////////////////////////////////

int main()
{
    int _size;
    printf("Enter Array Size\n");
    scanf("%i",&_size); //5
    int *ptr=malloc(_size * sizeof(int));

    for (int i = 0; i < _size; i++)
    {
        scanf("%i",&ptr[i]);
    }
    for (int i = 0; i < _size; i++)
    {
        printf("%i\n",ptr[i]);
    }

    ////we wanna deallocate place in heap we stored
    //free(ptr);
    //////free -> remove protection 
    //for allocated bytes
    ///so that any app can write in this place
    ///REMEMBER
    //ptr will still carries 0x10
    // =>undefined address
    //free dosen't remove values
    // => remove protection 
    //
    //print ptr[0] //rubbish
    //====>ptr=malloc(60);
    //
    //dangerous memory leackage
    //
    ///
    //
    ///
    ///
    //

}

//////////////////////////////////
//dangerous memory leackage
void Tryme()
{
    int* arr=(int*)malloc(10 * sizeof(int));
    //remember to use free(ptr)
    //to ensure clear heap
    free(arr);
}

int * Tryme2()
{
    int* arr=(int*)malloc(10 * sizeof(int));
    //remember to use free(ptr)
    //to ensure clear heap
    return arr;
}
int main()
{
    Tryme();
    Tryme();
    Tryme();
    Tryme();
    //
    //
    int *ptr=Tryme2();
    //
    free(ptr);
    //
    //
}
////////////////////////////////////////
///array of Pointers
///2D Array
int main()
{
    int mySize=4;
    int* ptrArr[3];

    ptrArr[0]=(int *) malloc(mySize * sizeof(int));
    ptrArr[1]=(int *) malloc(mySize * sizeof(int));
    ptrArr[2]=(int *) malloc(mySize * sizeof(int));
    //At this point int* ptrArr[3] -> int ptrArr[3][4]

    

    //free
    //free(ptrArr);  //NOOOOOOOOO
    //
    free(ptrArr[0]);
    free(ptrArr[1]);
    free(ptrArr[2]);
    
}

///////////////////////////////////////


///ptraArr [?] [?]

int main()
{
    int row;
    int col;
    scanf("%d",&row); //3
    scanf("%d",&col); //4

    int* *ptrArr;

    ptrArr=/*(int**)*/malloc(row * sizeof(int*));    

    ptrArr[0]=malloc(col * sizeof(int));
    ptrArr[1]=malloc(col * sizeof(int));
    ptrArr[2]=malloc(col * sizeof(int));
    //jagged Array
    //At this point
    ///int ** ptrArr after fst malloc -> int* ptrArr[3]
    //int* ptrArr[3] after rest of malloc -> int ptrArr[3][4]

    //int ptrArr[3][4];
    ptrArr[0][0]=100;

    ///Dangerous memory leackage
    //free(ptrArr);

    //Soln
    free(ptrArr[0]);
    free(ptrArr[1]);
    free(ptrArr[2]);
    free(ptrArr);
    //
}


///////////////////////////////////////
//ERROR
int main()
{
    int row;
    int col;
    scanf("%d",&row); //3
    scanf("%d",&col); //4

    int *ptrArr;  //||||  =>  |||||  |||||  |||||

    ptrArr= /*(int**)*/ malloc(row * sizeof(int*)); //codeblocks 20  pointer 8B

    ptrArr[0]=malloc(col * sizeof(int));
    ptrArr[1]=malloc(col * sizeof(int));
    ptrArr[2]=malloc(col * sizeof(int));


    //At this point
    ///int ** ptrArr after fst malloc -> int * ptrArr[3]
    //int* ptrArr[3] after rest of malloc -> int ptrArr[3][4]


    // int x=10;
    // x[0]=100;


    ptrArr[0][0]=100;   //CompileERROR

    ///Dangerous memory leackage
    free(ptrArr);
    ///

    //Soln
    free(ptrArr[0]);
    free(ptrArr[1]);
    free(ptrArr[2]);
    free(ptrArr);
    //
}

////////////////////////////////////////////////////////


//void multipleArratByTen(int param[],int size)
void multipleArratByTen(int* param,int size)
{}

int* getArray()
{
    //int arr[5]={1,2,3,4,5};
    int * arr=malloc(20);
    //arr[0]=10;arr[1]=20;....arr[4]=50;
    //10,20,30 ...
    return arr;
}

int** get2DArray()
{
    int arr[3][4]={{},{},{}};
    return arr;
}

int main()
{
    int arr[10]={1,2,3,4,5,6,7,8,9,10}
    multipleArratByTen(arr,10);


    int* ptr=getArray();
    ptr[0]=100; //Runs successfully
    free(ptr);
}

////////////////////////////////////////////
///recursive function
//function calls itself
//functions contain
//1- for loop plus
//2- it ends with certain break
////1     0

//3- use with programming/mathematical equations
///

//Stack overlflow
void Print()
{
    Print();
}
main()
{
    Print();
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
    int num=4;

    int res=  Factorial(num);
}


///////power [lab]
int Power(int b,int p)
{
    
}


int main()
{
    int _base=2;
    int _power=4;

    int res=Power(_base,_power);
}


//////////////////////////////////////////////
//Lab Assignment

///1- try dynamic allocation
// for pointer to integer read and write 2 ways
///2- try dynamic allocation for pointer
// topointer to integer read and write
////  int ** arr===int arr[3][4]
///3- pass array to fn
///4- return array to fn
///5- power recursive



