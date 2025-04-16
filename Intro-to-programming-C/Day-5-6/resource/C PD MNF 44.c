///pointers
///casting
//////////////////////////////////////////////////////////////
#include<stdio.h>
int main()
{
    int x=22;
    float y=33;

    printf("%i",x); //22
    printf("%f",y); //33

    printf("%x",&x);//0x10
    printf("%x",&y);//0x20
}

//if i want variable to carry address
//of another variable in memory?

//thats called pointer 
//////////////////////////////////////////////////////////////
///pointer:
///Datatype can carry address of another data type 
//in memory
/////////////////////////////////////////////////////////

int main()
{
    int x; // x|#|0x10
    float y;

    int *ptr;
    //create pointer to variable
    //create pointer that can carry
    //address of integer variable 
    float *fptr;
    //create pointer that can carry
    //address of float variable

    //VALUE-address- for ptr and fptr is NULL -NOT RUBBISH-
}   

////////////////////////////////////////////////////

//make pointer points[address] another variable in memory

int main()
{
    int x=22;

    int *ptr;

    //ptr=x; 
    //Logic error will cause later Runtime error
    //once you try to access that address

    ptr=&x;

    printf("%i",x); //22
    printf("%x",&x);//0x10

    printf("%x",ptr);//0x10
    printf("%x",&ptr);//0x20
}


int main()
{
    float y=1.2;     //y|1.2| 0x10
    float *fptr=&y;  //fptr|0x10| 0x20
    printf("%x",&fptr);

    //c#
    //int x;|unassigned|  VT
    //cw(x) ; compile error
}
////////////////////////////////////////////////
//print value of x;
int main()
{
    int x=10;
    int *ptr;
    ptr=&x;

    //
    printf("%i",x); //10
    printf("%i",*ptr);
    //print value that pointer points at
    //


    float y=1.2;
    float *fptr=&y;

    printf("%f",y);//1.2
    printf("%f",*fptr);//1.2
    
}
/////////////////////////////////////////////

//Access variable via pointer
int main()
{
    int x=10;

    int *ptr=&x;

    x=22;
    //ptr=33; //logic error will cause runtime error
    *ptr=33;

    printf("%i",x); //33

    ////logic error will cause runtime error
    float y=44;
    //logic error
    float* fptr=y;
    //runtime error -> when trying to access address
    printf("%f",*fptr);
    *fptr=55;
    //
}

//////////////////////////////////////////////////
//read variable in runtime
int main()
{
    int x=22;
    int *ptr=&x;

    scanf("%i",x); //XXXX
    scanf("%i",&x); //T
    scanf("%i",ptr); //T
    scanf("%i",&ptr); //XXXXX

}

/////////////////////////////////////////////////////
//size of pointer

///pointer ALWAYS CARRIES Address another variable
int main()
{
    //pointer size
    //32bit O.S -> 4B  RARELY USED
    //64bit O.S -> 8B
    //apps -> 32Bit or 64bit

    //32bit O.S + codeblocks 32Bit => pointer 4B
    //64bit O.S + codeblocks 32Bit => pointer 4B
    //64bit O.S + codeblocks 64Bit => pointer 8B

    //codeblocks17.12 -> 32bit  
    //codeblocks20.03 -> 64bit

    int *ptr;
    printf("%i",sizeof(int*)); //  
    printf("%i",sizeof(ptr)); // 
    //4B or 8B 
}
/////////////////////////////////////////////
//NOT RECOMMENDED
int main()
{
    int x=22;
    float *fptr=&x;

    printf("%f",*fptr); //will not work properly //0
    //Recommended: make pointer of same type of variable
}

////////////////////////////////////////////////////////
//arithmatic operator on pointer ++,--
int main()
{
    int x=22;   //0x10
    int *ptr=&x;
    ptr++;

    printf("%x",(ptr+1)); //0x18
    printf("%x",ptr); //0x14


    double y=1;
    double *dptr=&y;
    dptr++;//8 steps

    //pointer will be incremented by size of its DT in bytes

    char ch='A';
    char *cptr=&ch;
    cptr++;



}

int main()
{
    int x=22;   //0x10
    int *ptr=&x;
    

    printf("%i",(*ptr)++); //22 
    printf("%i",++(*ptr)); //24 
}
/////////////////////////////////////////////
//General purpose pointer
//applicabe Execlusive with dynamic allocation 
int main()
{
    int x=22;    //x    |22|0x10
    void *ptr;   //ptr  |0x10|0x20
    ptr=&x;

    printf("%i",sizeof(void*)); //4 or 8B
    printf("%i",sizeof(ptr)); //4 or 8B


    printf("%i",x);   //22
    printf("%x",ptr); //0x10

    printf("%x",&x);  //0x10
    printf("%x",&ptr);//0x20

    printf("%i",*ptr);//Compile Error
    //TRY ->printf("%i",&(*ptr));//Compile Error

    //soln1
    int* tmpPtr=ptr;
    printf("%i",*tmpPtr);//22
    //sol2 casting

}

int main()
{
    int x=22;
    int*ptr=&x;

    *ptr=33;

    printf("%i",x);   //33
    printf("%x",ptr); //0x10

    printf("%x",&x);  //0x10
    printf("%x",&ptr);//0x20

    printf("%i",*ptr); //33
    printf("%i",*x); //Compile ERROR
}

///////////////////////////////////////////////////
///pointer to array

int main()
{
    int arr[5];
    //printf("%x",arr);
    //printf("%x",&arr);
    int *ptr;

    //ptr point address fst element of array
    ptr=arr;    //T
    ptr=&arr;   //T
    ptr=arr[0]; //F
    ptr=&arr[0];//T
    
    //put data then print
    //V1
    // for(int i=0;i<5;i++,ptr++)
    for(int i=0;i<5;i++)
    {
        *ptr=10;
        ptr++;
    }
    //REMEMBER
    ptr=arr;
    for(int i=0;i<5;i++)
    {
        printf("%i",*ptr);
        ptr++;
    }
    //REMEMBER
    ptr=arr;

}

int main()
{
    int arr[5];
    int *ptr=arr;
    //V2
    for(int i=0;i<5;i++)
    {
        *(ptr+i)=10;
    }
    for(int i=0;i<5;i++)
    {
        printf("%i",*(ptr+i));
    }

}


int main()
{
    int arr[5];
    int *ptr=arr;

    //V3 [Most commonly used]
    //when pointer points array ,it acts like an array [indexer]
    for(int i=0;i<5;i++)
    {
        arr[i]=10;
    }
    //ptr=arr  => ptr is like an arr in index
    for(int i=0;i<5;i++)
    {
        ptr[i]=10;
    }

    for(int i=0;i<5;i++)
    {
        printf("%i",ptr[i]);
    }

    //ptr[i]===arr[i]  value not address
}

//////////////////////////////////////////////
//array itself address fst element of array
//array itself is a constant address
int main()
{
    int arr[5];
    //arr itself-> constant pointer 
    
    //*arr=10;  //T
    //arr++; //Compile Error //arr-> constant pointer

    *arr=10;
    *(arr+1)=20;
    *(arr+2)=30;
    *(arr+3)=40;
    *(arr+4)=50;

    arr[0]=10;
    arr[1]=20;
    arr[2]=30;
    arr[3]=40;
    arr[4]=50;

    scanf("%i",&arr[0]);
}

/////////////////////////////////////////////////////

//read array via pointer
int main()
{
    int arr[5];
    int *ptr=arr;
    //v1
    for(int i=0;i<5;i++)
    {
        printf("Enter value at index %i",i);
        scanf("%i",ptr);
        ptr++;
    }
    //
    ptr=arr;
    //
    for(int i=0;i<5;i++)
    {
        printf("value at index %i is %i",i,*ptr);
        ptr++;
    }
    //v2
    for(int i=0;i<5;i++)
    {
        printf("Enter value at index %i",i);
        scanf("%i",ptr+i);
    }
    for(int i=0;i<5;i++)
    {
        printf("value at index %i is %i",i,*(ptr+i));
        
    }
    //v3 pointer points array,acts like an array [indexr]
    for(int i=0;i<5;i++)
    {
        printf("Enter value at index %i",i);
        scanf("%i",&ptr[i]);
    }
    for(int i=0;i<5;i++)
    {
        printf("value at index %i is %i",i,ptr[i]);   
    }
}

///////////////////////////////////////////////////

//pointer to array of characters
int main()
{
    char carr[11];
    char *cptr=arr;

    *cptr='a';
    cptr++;
    *cptr='l';
    cptr++;
    *cptr='i';
    cptr++;
    *cptr='\0';
    cptr=carr;
    printf("%s",cptr);

    *(cptr+0)='a';
    *(cptr+1)='l';
    *(cptr+2)='i';
    *(cptr+3)='\0';
    printf("%s",cptr);

    gets(cptr);
    puts(cptr);
}

///////////////////////////////////////////
//Pointer to Pointer to integer
int main()
{
    int x=22;

    int *ptr=&x;
    
    int* *ptrToPtr=&ptr;

    printf("%i",x);         //22
    printf("%x",&x);        //0x10
    printf("%x",*x);        //Compile Error

    printf("%x",ptr);      //0x10
    printf("%x",&ptr);     //0x20
    printf("%i",*ptr);     //22

    printf("%x",ptrToPtr);  //0x20
    printf("%x",&ptrToPtr); //0x30
    printf("%x",*ptrToPtr); //0x10
    printf("%i",**ptrToPtr); //22
    
}

//REMEMBER
int main()
{
    int x=22;

    int *ptr=&x;

    int *ptrToPtr=&ptr;
    //
    *ptrToPtr
    //
    printf("%i",x);         //22
    printf("%x",&x);        //0x10
    printf("%x",*x);        //Compile Error

    printf("%x",ptr);      //0x10
    printf("%x",&ptr);     //0x20
    printf("%i",*ptr);     //22

    printf("%x",ptrToPtr);  //0x20
    printf("%x",&ptrToPtr); //0x30
    printf("%x",*ptrToPtr); //0x10
    printf("%i",**ptrToPtr); //Compile Error  
}


////////////////////////////////////////////////////
//pointer to struct
struct Employee
{
    int id;
    char name[10];
    int age;
};

int main()
{
    struct Employee e1; //18B
    e1.id=1;
    //e1.name="Fatma";
    e1.age=22;


    struct Employee * empPtr; //4 or 8 B
    empPtr=&e1;

    //empPtr.id=10; //WRONG
    (*empPtr).id=10;
    strcpy((*empPtr).name,"Fatma");
    (*empPtr).age=22;

    //pointer to struct -> access variable  -> arrow
    (*empPtr).id=30;
    empPtr->id=30;
    printf("%i",empPtr->id);
    strcpy(empPtr->name,"Fatma");
    empPtr->age=22;


}
////////////////////////////////////////////////////
//pass by value
//pass by address
void swapV(int left,int right)
{
    int tmp;
    tmp=left;
    left=right;
    right=tmp;
}

void swapA(int* left,int* right)
{
    int tmp;
    tmp=*left;
    *left=*right;
    *right=tmp;
}
int main()
{
    int x=22,y=33;
    //swapV(x,y); //pass VALUES
    swapA(&x,&y); //pass VALUES[Addresses]
    printf("x->%i",x);//33
    printf("y->%i",y);//22
}


///////////////////////////////////////////////
//pass array to fn
//void MultibleArrayByTen(int  param[],int size)
//void MultibleArrayByTen(int  param[5])

void MultibleArrayByTen(int * param,int size)
{
    //same code
    param[0]*=10;
    param[1]*=10;
    param[2]*=10;
}

int main()
{
    int arr[5]={1,2,3,4,5};
    MultibleArrayByTen(arr,5); //
}


//////////////////////////////////////////////////
//return array from fn

int* TryMe()
{
    int arr[5]={1,2,3,4,5};
    return arr;  //return address 0x10
}
int main()
{
    int *ptr=TryMe();  
    ptr[0]=55;
    ptr[1]=66;
    ptr[2]=77;

    //for loop
    //print ptr[i];

    //o/p
    //99.99% Runtime Error
}

//Lab Assignments
//1- pointers to integers  read & write
//2- pointers to array  read and write   3 ways
//3- pointer to pointer of integer
//4- pass by value/address    swap
//5- pass array as input param []   ,pass pointer
//6- return [] as return type[not supported][compiler error]
        //and return pointer as a return type

//7- pointer to struct of employee   ->

//+
///Previous Lab Assigments
