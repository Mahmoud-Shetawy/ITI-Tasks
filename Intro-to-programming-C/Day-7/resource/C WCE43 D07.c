//casting
//pointers revision
//dynamic allocation
//recursive function
////////////////////////////////////////////////////////
int main()
{
    int x=10 ;   //0x10
    int * ptr=&x;  //0x20

    printf("%d",x);  //10
    printf("%x",&x); //0x10
    printf("%d",*x); //Compile Error

    printf("%x",ptr); //0x10
    printf("%x",&ptr); //0x20
    printf("%d",*ptr); //10

}


int main()
{
    int *tmpPtr;
    int a=1,b=2,c=3,d=4;

    int *ptr[4];


    //fst element in array
    ptr=a;//XXX Address
    ptr=&a;
    ptr[0]=a;  //Logic error
    ptr[0]=&a;  //T

    int *ptr[4]={&a,&b,&c,&d};

}

int main()
{
    int arr[4]={1,2,3,4};

    int * ptrArr[4];

    //fst elemet of ptrArr
    ptrArr=arr;
    ptrArr=&arr;
    ptrArr[0]=arr; //T
    ptrArr[0]=&arr; //T
    ptrArr[0]=&arr[0]; //T

    int* ptrArr[]={arr,&arr[1],&arr[2],&arr[3]};
}

//////////////////////////////////////////////////////////

//Casting
///Convert value from data type to another data type
//casting
//data type can be converted to another one ,,, True
//latest c Versions , this will be done Implicitly
//Implicitly =>compiler will do it itself 
//Explicitly => you [developer ] will do it yourself


int main()
{
    int x=22;//2B
    double y=33; ///222B

    ////implicit casting
    ////Safe casting
    //y=x;
    ////explicit casting
    //y=(double)x;

    //unsafe casting
    //implicit casting
    x=y;
    ////explicit casting
    x=(int)y;


    printf("x=> %d\n",x); //Rubbish
    printf("y=> %lf",y);  //222B
}


//////////////////////////////////////////////////
//Promotion  char ->int -> float -> long -> double

int main()
{
    int x=1;
    float y=3;


    float z=x/y;

    printf("z=> %d\n",z); //0.454

}

int main()
{
    int x=3;
    int y=4;


    float z=(float)x/y;

    printf("z=> %f\n",z); //0.454

}

int main()
{
    char ch='M';
    int x=3;

    int z=x+ch;
    //print z  => 80
}

struct Employee{int id;};

//GPP
int main()
{
    int x=10; //0x10
    void * ptr=&x;   //0x20

    printf("%d",*ptr);  //Compile Error
    
    printf("%d",   *((int*)ptr)  );  //10

    *((int*)ptr)=22;

    struct Employee e1;
    void* anotherPtr=&e1;
    ((struct Employee*)anotherPtr)->id=10;
}


/////////////////////////////////////////////////////////////////
//array of 24 students

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





//////////////////////////////////////////////
#include<stdlib.h>
int main()
{
    
    //explicit casting is not necessary
    int *ptr = (int *) malloc(16);
    //inmplicit casting is done automatically
    int* ptr=malloc(16);


    char *cptr=malloc(5);
}


//////////////////////////////////////
//allocate and write
int main()
{
    int*ptr=(int*) malloc(16);

    *ptr=10;
    ptr++;
    *ptr=20;
    ptr++;
    *ptr=30;
    ptr++;
    *ptr=40;
}

//WRONG
//allocate and write
int main()
{
    int*ptr=(int*) malloc(16);

    //Ver dangerous
    *ptr=10;
    ptr++;
    *ptr=20;
    ptr++;
    *ptr=30;
    ptr++;
    *ptr=40;

    //another soln
    *ptr=10;
    *(ptr+1)=20;
    *(ptr+2)=30;
    *(ptr+3)=40;

    //Best soln indexer
    ptr[0]=10;
    ptr[1]=20;
    ptr[2]=30;
    ptr[3]=40;
}


/////////////////////////////

int main()
{
    char* cptr=malloc(12);

    *cptr='A';
    cptr++;
    *cptr='l';
    cptr++;
    *cptr='i';
    cptr++;
    *cptr='\0';

    *cptr='A';
    *(cptr+1)='l';
    *(cptr+2)='i';
    *(cptr+3)='\0';

    gets(cptr);
    scanf("%s",cptr);
}


///////////////////////////////////////////

//dynamic allocation for 10 values read & write


int main()
{
    int *ptr;

    ptr=(int*)malloc(40);  //int ptr[10]

    for(int i=0;i<10;i++)
    {
        printf("Enter value at index %d\n",i);
        scanf("%d",&ptr[i]);
    }

    for(int i=0;i<10;i++)
    {
        printf("value at index %d is %d\n",i,*(ptr+i));//or
        printf("value at index %d is %d\n",i,ptr[i]);
       
    }

}

//////////////////////////////////////////////
int main()
{
    int size;

    printf("Enter Array size of integers\n");
    scanf("%d",&size); //10

    int *ptr=(int*) malloc(size* sizeof(int));
    //
    //
    //
    free(ptr);
    
    ///free -> remove protection for allocated bytes
    ///so that any app can write in this place
    ///REMEMBER
    //ptr will still carries 0x10 =>undefined address
    //free dosen't remove values => remove protection 
    //
    //print ptr[0] //rubbish
    //====>ptr=malloc(60);
    //
    //dangerous memory leackage
    //
}

//////////////////////////////////////////////////////
void Tryme()
{
    int *arr=(int*)malloc(10 * sizeof(int));
    //dangerous memory leackage
    free(arr);
}

int main()
{
    Tryme();
    Tryme();
    Tryme();
    Tryme();
}

/////////////////////////////////////////////////////

///array of Pointers
///2D Array

int main()
{
    int* ptrArr[3];

    ptrArr[0]=malloc(4 * sizeof(int));
    ptrArr[1]=malloc(4 * sizeof(int));
    ptrArr[2]=malloc(4 * sizeof(int));


    ptrArr[0][0]=10;

    ///*ptrArr[0]=10;

    free(ptrArr[0]);
    free(ptrArr[1]);
    free(ptrArr[2]);
    //WRONG
    free(ptrArr);
}

//////////////////////////////////////


int main()
{
    int row,col;

    printf("Enter Row size\n");
    scanf("%d",&row);
    printf("Enter Column size\n");
    scanf("%d",&col);

    int** ptrArr;


    ptrArr=/*(int**)*/malloc(row * sizeof(int *));

    ptrArr[0]=malloc(col * sizeof(int));
    ptrArr[1]=malloc(col * sizeof(int));
    ptrArr[2]=malloc(col * sizeof(int));


    //At this moment
    //ptr act like  int ptrArr[3][4]
    ptrArr[0][1]=10;

    //Itself WRONG ->memory leackage
    free(ptrArr);

    free(ptrArr[0]);
    free(ptrArr[1]);
    free(ptrArr[2]);
    free(ptrArr);


}

/////////////////////////////////////////////////

///WRONG CASE  ===> try it and see whats happened in ptrarr[0][0]=100;
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


    int *ptr  => malloc    ptr[5]
    int ** ptr => malloc   ptr[9][9]

}


///////////////////////////////////////////////////////////////

//void multipleArratByTen(int param[],int size)
void multipleArratByTen(int* param,int size)
{}

int* getArray()
{
    //static int arr[5]={1,2,3,4,5};
    int *arr=malloc(20);
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
    free(ptr);
    ptr=getArray();

    ptr[0]=100;
}


int** get2DArray()
{
    int arr[3][4]={{},{},{}};
    return arr;
}

///////////////////////////////////////////////////
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



///////////////
//power

            //2         3
int Power(int _base,int _power)
{
    if(_power==0)
    {
        return 1;
    }
    else
    {
        return _base * Power(_base,_power-1);
    }
}



///////////////////////////////////////////////////////
//Lab Assignment


///1- try dynamic allocation for pointer to integer read and write
///2- try dynamic allocation for pointer topointer to integer read and write
////  int arr[3][4]
///3- pass array to fn
///4- return array to fn














