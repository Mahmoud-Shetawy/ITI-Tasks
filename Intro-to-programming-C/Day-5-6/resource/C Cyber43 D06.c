//////////////////////////////////////////////////////
//pointers
//casting
//////////////////////////////////////////////////////
///pointer
//=> variable carries address of another variable 
//in memory
//////////////////////////////////////////////////////
#include<stdio.h>
int main()
{
    int x=10;
    float y=20;

    printf("x=>%d\n",x); //10
    printf("y=>%f\n",y); //20

    printf("address x=>%x\n",&x); //0x10
    printf("Address y=>%x\n",&y); //0x20
}
/////////////////////////////////////////
//We wanna carry address of x or y 
//in variable

//that is called pointer
/////////////////////////////////////////

int main()
{
    int x;

    //pointer declaration
    int* ptr;
    //declare variable can carry address
    //of integer variable   //?B

    float* fPtr;
    //declare variable can carry address
    //of float variable   //?B

    //Value of ptr,fptr  is NULL

}

//////////////////////////////////////////
int main()
{
    int x=10;

    int* ptr;

    //ptr=x;
    //Logical Error will cause later
    //Runtime Error

    //ptr carriess address of x
    ptr=&x;
    printf("%d",x); //
    printf("%x",&x);
    printf("%x",ptr);
    printf("%x",&ptr);
}
/////////////////////////////////////

int main ()
{
    float y=1.2;    //&y in address 0x10    |1.2|

    float* fPtr=&y;    //&fPtr in address 0x20  |0x10|

    printf("%f",y);  //1.2
    printf("%x",&y); //0x10
    printf("%x",fPtr); //0x10
    printf("%x",&fPtr); //0x20

    //print Value of y Via Pointer
    printf ("%f",*fPtr);  //1.2
    ///*fPtr => get value of variable
    ///that pointer points at

} 


int main()
{
    int x=10;   //  |10| address0x10
    int *ptr=&x; //|0x10| address0x20

    printf("%d",x);  //10
    printf("%x",&x); //0x10

    printf("%x",ptr); //0x10
    printf("%x",&ptr);//0x20

    printf("%d",*ptr); //10
    ///*ptr => get value of variable
    ///that pointer points at

    //
    printf("%d",*x);  //Compile Error
    //

}

//
int main()
{
    int x=10;  // |10| address 0x10
    int ptr=0x10;  //TRUE

    printf("%d",*ptr);//Compile Error

}
//

///////////////////////////////////////////////
///size of pointer
///4B
///8B
////based on O.S  and Compiler
///O.S 32bit   GCC 32bit   => pointer size 4B
///O.S 64bit   GCC 64bit   => pointer size 8B
///O.S 64bit   GCC 32bit   => pointer size 4B

int main()
{
    int* ptr;
    double* dPtr;
    char * cPtr;

    printf("%d",sizeof(ptr));  
    //codeblocks 17.12   => 4
    //codeblocks 20.02   => 8

    printf("%d",sizeof(dPtr)); //4 or 8  
    printf("%d",sizeof(cPtr)); //4 or 8 
    printf("%d",sizeof(int*)); //4  or 8

}

////////////////////////////////////////////
//Change value of variable via pointer that points at
int main()
{
    int x=10;

    int*ptr=&x;

    printf("%d",*ptr);//10

    *ptr=22;  //assign 22 to variable that 
    //pointer points at

    //logical error will cause runtime error
    int y=11;
    //Logic Error
    int* pptr=y;
    printf("%d",*pptr);  //RUNTIME ERROR
    *pptr=55; //RUNTIME ERROR
    //
}

/////////////////////////////////////////////
///NOT Recommended
///Remember to assign pointer with variable with
//same DT
int main()
{
    int x=10;
    float *fPtr=&x;
    float y=1.2;
    int* ptr=&y;
    printf("%f",*fPtr); //Not right
    printf("%d",ptr); //Not right
}
/////////////////////////////////////////////////
///arithmatic operator on pointer

int main()
{
    int x=10;

    int *ptr=&x;

    ptr++;
    ///when increment pointer
    //it will increment by size of its data type

    double y=2;
    double* dptr=&y;
    dptr++;

    char ch='A';
    char *cptr=&ch;
    cptr++;
}

int main()
{
    int x=10;

    int *ptr=&x;

    ptr+1;
    ///when increment pointer
    //it will increment by size of its data type
    ptr++;
    ///when increment pointer
    //it will increment by size of its data type

}


/////////////////////////////////////////////////////
///General purpose pointer ->>>  -> Dynamic Allocation
///pointer of void

int main()
{
    int x=10;      //|10|  address 0x10

    void *ptr=&x;  //|0x10| address 0x20
    printf("%d",sizeof(ptr));  //4 or 8
    printf("%d",sizeof(void*));  //4 or 8

    printf("%d",x);   //10 
    printf("%x",&x);  //0x10

    printf("%x",ptr); //0x10
    printf("%x",&ptr);//0x20
    printf("%x",*ptr);//Compile Error 

    //workaround solution
    int* tmpPtr=ptr;
    printf("%x",*tmpPtr);// 10
    //Best Solution => casting


    ///pointer to void cannot be incremented
    void* ptr;
    ptr++;  //compile error
}

//////////////////////////////////////////
//read input via pointer
int main()
{
    
    int x=10;
    int* ptr=&x;
    
    ///Read value to x variable
    scanf("%d",x);  //F
    scanf("%d",&x);  //T
    
    scanf("%d",ptr);  //T
    scanf("%d",&ptr);  //F  //BIG WRONG
}

//////////////////////////////////////////////
//pointer to Array
int main()
{
    int arr[]={1,2,3,4,5};
    int * ptr;
    //ptr will carry address of fst element of array
    ptr=arr;  //T
    ptr=&arr; //T
    ///print Array
    //1- normal way
    for(int i=0;i<5;i++)
    {
        printf("%d\n",arr[i]);
    }
    //2- print via pointer //ptr value will be changed
    for(int i=0;i<5;i++/*,ptr++*/)
    {
        printf("%d",*ptr);  //1 2 3 4 5
        ptr++;
    }
    //2- print via pointer //ptr value will NOT be changed
    for(int i=0;i<5;i++)
    {
        printf("%d", *(ptr+i) );  
    }
    //3- Most Commonly Used
    ///when pointer points Array
    ///it acts like an array with using indexer
    printf("%d", arr[0]); //1
    printf("%d", ptr[0]); //1 //ptr[0] VALUES NOT ADDRESS
    for(int i=0;i<5;i++)
    {
        printf("%d",ptr[i]);
    }
}   

///////////////////////////////////////////
///read data to array via pointer
int main()
{
    int arr[5];
    int *ptr=arr;

    //read data from user
    //1- normal array
    for(int i=0;i<5;i++)
    {
        scanf("%d",&arr[i]);
    }
    //2-pointer v01 with increment pointer
    for(int i=0;i<5;i++)
    {
        scanf("%d",ptr);
        ptr++;
    } 
    //REMEMBER
    //after finishing scanf
    //Remember to return ptr 
    //to points fst emelemt of array
    ptr=arr;
    for(int i=0;i<5;i++)
    {
        printf("%d",*ptr);
        ptr++;
    }
    ptr=arr;
    //3-pointer v01 with  no increment pointer
    for(int i=0;i<5;i++)
    {
        scanf("%d",ptr+i);
    }
    for(int i=0;i<5;i++)
    {
        printf("%d", *(ptr+i) );
    }
    //4- VIP when pointer points array
        ///it acts like an array [indexer]
    for(int i=0;i<5;i++)
    {
        //scanf("%d",ptr[i]);  //WRONG
        scanf("%d",&ptr[i]);  //T
    }
    for(int i=0;i<5;i++)
    {
        printf("%d",ptr[i]);
    }
}

//////////////////////////////
///read fst element of array via ptr
int main()
{
    int arr[5];
    int *ptr=arr;
    ///read fst element of array via ptr
    scanf("%d",arr); //T 
    scanf("%d",&arr); //T 
    scanf("%d",ptr); //T 
    scanf("%d",&ptr); //FALSE 

}

/////////////////////////////
//Array itself is a constant pointer

int main()
{
    int arr[10];//={1,2,3,4,5,6,7,8,9,10};
    //arr is a constant pointer

    //read fst element of array
    scanf("%d",arr); //T
    scanf("%d",&arr); //T
    //Write fst element of array
    printf("%d",*arr); //T

    //v1
    *arr=10;  //T
    arr++; //Compile Error  //arr constant address fst elemt

    //V02   //TRUE
    *(arr+0)=10;
    *(arr+1)=20;
    *(arr+2)=30;
    *(arr+3)=40;
    *(arr+4)=50;

    //Indexer
    arr[0]=10;
    arr[1]=20;


    int arr2[5];

    arr=arr2; //LVAUE Compile Error
}

///////////////////////////////////////////////
///pointer to pointer to integer

int main()
{
    int x=10;

    int *ptr=&x;

    int* *ptrToPtr=&ptr;
    //4 or 8 B

    printf("%d", x);
    printf("%x", &x);
    printf("%d", *x);

    printf("%x", ptr);
    printf("%x", &ptr);
    printf("%d", *ptr);

    printf("%x", ptrToPtr);
    printf("%x", &ptrToPtr);
    printf("%x", *ptrToPtr);
    printf("%x", **ptrToPtr);
}

///REMEMBER WRONG
int main()
{
    int x=10;

    int *ptr=&x;

    int *ptrToPtr=&ptr;
    //4 or 8 B

    printf("%d", x);
    printf("%x", &x);
    printf("%d", *x);

    printf("%x", ptr);
    printf("%x", &ptr);
    printf("%d", *ptr);

    printf("%x", ptrToPtr);
    printf("%x", &ptrToPtr);
    printf("%x", *ptrToPtr); //0x10
    printf("%x", **ptrToPtr); 
    //*ptrToPtr  compiler considers it integer value
}

//////////////////////////////////////////////
///swap by value
///pass address

void swapValue(int a,int b)
{
    int tmp;
    tmp=a;
    a=b;
    b=tmp;
}

void swapAddress(int* a ,int* b)
{
    int tmp;
    tmp=*a;
    *a=*b;
    *b=tmp;
}
int main()
{
    int x=3,y=5;
    swapValue(x,y);  //pass VALUES  swap(3,5)

    swapAddress(&x,&y); //pass Address swapAd(0x10,0x20)

    printf("%d",x); //5
    printf("%d",y); //3

}



////////////////////////////////////////////////
///pass array to function

//int passArrayToFun(int param[5])
//int passArrayToFun(int param[],int size)
int passArrayToFun(int* param,int size)
{}
int main()
{
    int arr[]={1,2,3,4,5};
    passArrayToFun(arr,5);  //pass arr -> address
}


//return array from function

int* GetArray()
{
    int arr[]={1,2,3,4,5};
    return arr;  //return address
}

int main()
{
    int *ptr=GetArray(); //return address of dead array

    *ptr=22; //WRONG
}


/////////////////////////////////////////////////////
//pointer to struct

struct Employee
{
    int id;
    char name[10];
    int age;
    float salary
};

int main()
{
    struct Employee e1;  //22B

    struct Employee *empPtr; //4 or 8

    //empPtr=e1;  //Search
    empPtr=&e1;

    (*empPtr).id=1;
    strcpy((*empPtr).name,"Sara");
    (*empPtr).age=22;
    (*empPtr).salary=1234;


    (*empPtr).id=1;
    //pointer to struct called arrow op   ->
    (*empPtr).id=1;
    empPtr->id=1; //====(*empPtr).id=1;
    empPtr->age=22;
    strcpy(empPtr->name,"Sara");


    ///(*empPtr).id  VALUE
    ///empPtr->id    VALUE

    scanf("%d",&empPtr->id);
}


//////////////////////////////////////////

///pointer to array of characters
int main()
{
    char arr[10];

    char* cptr=&arr;
    //char* cptr=arr;

    *cptr='A';
    *(cptr+1)='l';
    *(cptr+2)='i';
    *(cptr+3)='\0';

    cptr[0]='A';
    cptr[1]='l';
    cptr[2]='i';
    cptr[3]='\0';

    scanf("%s", cptr);
    gets(cptr);
}


////////////////////////////////////////
//Lab Assignments
//1- pointers to integer variable  read & write
//2- pointers to array  read and write   3 ways
//3- pointer to pointer of integer
//4- pass by value/address    swap
//5- pass array as input param []   ,pass pointer
//6- return [] as return type[not supported][compiler error]
        //and return pointer as a return type

//7- pointer to struct of employee  read and write  ->

