///pointers
///casting
//////////////////////////////////////////////////////////////
#include<stdio.h>
int main()
{
    int x=22;
    float y=33;

    printf("x=%i",x);
    printf("y=%i",y);

    //print address
    printf("&x=%x",&x);
    printf("&x=%y",&y);
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
    int x;     // x|#|0x10
    float y;   // y|#|0x30

    int *ptr;
    //create pointer to variable
    //create pointer that can carry
    //address of integer variable 
    
    float *fPtr;
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

    //ptr=x; //No Compile Error
    //Logic error will cause later Runtime error
    //once you try to access that address
    ptr=&x;
    


    printf("%?",x);
    printf("%?",&x);
    printf("%?",ptr);
    printf("%?",&ptr);
    

}


int main()
{
    float y=1.2;     
    float *fptr; 
    fptr=&y;
    printf("%?",y);
    printf("%?",&y);
    printf("%?",fptr);
    printf("%?",&fptr);

}
////////////////////////////////////////////////
//print value of x;
int main()
{
    int x=10;
    int *ptr;
    ptr=&x;
    printf("%i",x); //10
    //print value of x via ptr
    printf("%i",*ptr);
    //print value that pointer points at


    float y=1.2;
    float *fptr=&y;
    //see in memory
    
    
}
/////////////////////////////////////////////
//Access variable via pointer
int main()
{
    int x=10;
    int *ptr=&x;  //|0x10|

    //ptr=22; //|22|
    //printf("%i",*ptr); //RUNTIME ERROR
    ////logic error will cause runtime error 

    //ptr=&x;  

    /////change x to 22 then print
    // x=22;
    // printf("%i",x); //22

    ///change x to 22 then print via pointer
    *ptr=22;
    printf("%i",*ptr); //22

    // //
    // int* ptr=22;
    // //

    float y=44;
    //logic error
    float* fptr=y;
    
    //runtime error -> when trying to access address
    *fptr=1.2;
    //

}

int main()
{
    int x=10;
    int *ptr;
    ptr=&x;

    printf("%i",x);
    printf("%x",&x);
    printf("%x",ptr);
    printf("%x",&ptr);

    printf("%i",*ptr);
    printf("%i",*x);
}

//////////////////////////////////////////////////
//read variable in runtime
int main()
{
    int x=22;             //x|22|0x10
    int *ptr=&x;          //ptr|0x10|0x30

    //scanf("%i",0x10); 
    scanf("%i",x); //X
    scanf("%i",&x); //T

    scanf("%i",ptr); //T
    scanf("%i",&ptr); //F  //555ENTER  

    printf("%i",x);
    printf("%i",*ptr);


}

/////////////////////////////////////////////////////
//size of pointer

///////////////////////////////////////////////////////////pointer ALWAYS CARRIES Address another variable
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
    printf("%i",sizeof(int*)); //4 or 8  
    printf("%i",sizeof(ptr)); // 4 or 8 
    printf("%i",sizeof(*ptr)); //4
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
    int x=22;
    int *ptr=&x;
    ptr++;

    double y=1.2;
    double *dptr=&y;
    dptr++;

    char ch='A';
    char* cptr=&ch;
    cptr++;

    ////REMEMBER
    //ptr |0x10| 0x30
    ptr++; //4 steps   0x14
    ///printf %x ptr   0x14
    //ptr+1; //4 steps   0x14
}
///ابعدوا عن المشتبهات
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
    void *ptr;

    printf("%i",sizeof(ptr));             //4 or 8
    printf("%i",sizeof(void*));           //4 or 8
    int x=22;                            //x|22|0x10
    ptr=&x;                              //ptr|0x10|0x30
    printf("%i",x);                      //22
    printf("%x",ptr);                    //0x10
    
    printf("%i",*x);                     //Compile Error
    printf("%x",&x);                     //0x10
    printf("%x",&ptr);                   //0x30

    printf("%x",*ptr);                   //Compile Error
    
    ///gpp dosen't have arithmatic operators
    ptr++; //Compile Error

    //soln1
    int *tmpPtr=ptr;
    printf("%i",*tmpPtr); //22
    //sol2 casting
    //Later

}
//RECAP
int main()
{
    int x=22;
    int *ptr;
    ptr=&x; //Most Important Code

    //print  x
    //print  &x
    //print  *x
    //print  ptr
    //print  &ptr
    //print  *ptr
}

///////////////////////////////////////////////////
///pointer to array

int main()
{
    int arr[5];   //arr[0x10]||||||
    //printf("%x",arr); //0x10
    //printf("%x",&arr);//0x10
    
    int *ptr;

    //ptr point address fst element of array
    ptr=arr[0]; //X
    ptr=&arr[0];//T
    ptr=arr; //T
    ptr=&arr; //T

    //most used
    ptr=arr;
    
    //put data then print
    //V0
    for(int i=0;i<5;i++)
    {arr[i]=10;}
    for(int i=0;i<5;i++)
    {printf("%i",arr[i]);}

    //V1 Rarely used
    *ptr=10;
    ptr++;
    *ptr=10;
    ptr++;
    *ptr=10;
    ptr++;
    *ptr=10;
    ptr++;
    *ptr=10;
    ptr++;
    for(int i=0;i<5;i++,ptr++)
    {
        *ptr=10;
        //ptr++;
    }
    //REMEMBER
    //to make ptr point fst element of
    //arrar AGAIN
    ptr=arr;
    printf("%i",*ptr);
    ptr++;
    printf("%i",*ptr);
    ptr++;
    printf("%i",*ptr);
    ptr++;
    printf("%i",*ptr);
    ptr++;
    printf("%i",*ptr);
    ptr++;
    for(int i=0;i<5;i++/*,ptr++*/)
    {
        printf("%i",*ptr);
        ptr++;
    }
    /////REMEMBER
    //to make ptr point fst element of
    //arrar AGAIN
    ptr=arr;

    

}

int main()
{
    int arr[5];
    int *ptr=arr;
    //V2
    *(ptr+0)=10;
    *(ptr+1)=10;
    *(ptr+2)=10;
    *(ptr+3)=10;
    *(ptr+4)=10;
    printf("%i",*(ptr+0));
    printf("%i",*(ptr+1));
    printf("%i",*(ptr+2));
    printf("%i",*(ptr+3));
    printf("%i",*(ptr+4));
    
    for (int i = 0; i < 5; i++)
    {
        *(ptr+i)=10;
    }
    
    for (int i = 0; i < 5; i++)
    {
        printf("%i",*(ptr+i));
    }
}


int main()
{
    int arr[5];
    int *ptr=arr;

    //V3 [Most commonly used]
    //when pointer points array 
    //,it acts like an array [indexer]
    
    for (int i = 0; i < 5; i++)
    {
        ptr[i]=10;
    }
    for (int i = 0; i < 5; i++)
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
    ///arr constant pointer
    //v1 WRONG
    //*arr=10;
    //arr++; //Compile Error

    //v2
    *(arr+0)=10;
    printf("%i",*(arr+0));

    //v3
    arr[0]=3;
    printf("%i",arr[0]);
}

/////////////////////////////////////////////////////
//read array via pointer
int main()
{
    int arr[5];
    int *ptr=arr;
    //v1
    for (int i = 0; i < 5; i++,ptr++)
    {
        printf("Enter # at index %i\n",i);
        scanf("%i",ptr);
    }
    //REMEMBER 
    ptr=arr;
    for (int i = 0; i < 5; i++,ptr++)
    {
        printf("# at index %i=%i\n",i,*ptr);
    }
    //REMEMBER 
    ptr=arr;
    
    //v2
    for (int i = 0; i < 5; i++)
    {
        printf("Enter # at index %i\n",i);
        scanf("%i",(ptr+i));
    }
    
    for (int i = 0; i < 5; i++)
    {
        printf("# at index %i=%i\n",i,*(ptr+i));
    }
    
    //v3 pointer points array,acts like an array [indexr]
    for (int i = 0; i < 5; i++)
    {
        printf("Enter # at index %i\n",i);
        scanf("%i",&ptr[i]);
    }
    for (int i = 0; i < 5; i++)
    {
        printf("# at index %i=%i\n",i,ptr[i]);
    }
}

///////////////////////////////////////////////////

//pointer to array of characters
int main()
{
    char carr[11];
    char *cptr;
    cptr=carr;
    //v1
    *cptr='A';
    cptr++;
    *cptr='l';
    cptr++;
    *cptr='i';
    cptr++;
    *cptr='\0';
    cptr++;
    //REMEMBER
    cptr=carr;

    //v2
    (cptr+0)='A';
    (cptr+1)='l';
    (cptr+2)='i';
    (cptr+3)='\0';

    //v3
    cptr[0]='A';
    cptr[0]='l';
    cptr[0]='i';
    cptr[0]='\0';

    //v4
    gets(cptr);
    puts(cptr);

    //v5
    scanf("%s",cptr);

}

///////////////////////////////////////////
//Pointer to Pointer to integer
int main()
{
    int x=10;
    int *ptr=&x;
    int* *ptrToPtr=&ptr;

    printf("%i",x);
    printf("%x",&x);
    printf("%i",*x);

    printf("%x",ptr);
    printf("%x",&ptr);
    printf("%i",*ptr);

    printf("%x",ptrToPtr);
    printf("%x",&ptrToPtr);
    printf("%x",*ptrToPtr);
    printf("%x",**ptrToPtr);

}

//REMEMBER
int main()
{
    int x=10;
    int *ptr=&x;
    int *ptrToPtr=&ptr;

    printf("%i",x); //10
    printf("%x",&x); //0x10
    printf("%i",*x); //compile Error

    printf("%x",ptr); //0x10
    printf("%x",&ptr);//0x30
    printf("%i",*ptr); //10

    printf("%x",ptrToPtr); //0x30
    printf("%x",&ptrToPtr);//0x50
    printf("%x",*ptrToPtr);//0x10
    printf("%x",*(*ptrToPtr)); //compile Error

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
    strcpy(e1.name,"Fatma");
    e1.age=22;

    struct Employee *empPtr;  //4 or 8 B

    empPtr=&e1;

    //model1
    (*empPtr).id=1;
    strcpy((*empPtr).name,"Fatma");
    (*empPtr).age=22;

    //model2
    //pointer to struct -> arrow operator
    (*empPtr).id=1;
    empPtr->id=1;
    printf("%i",(*empPtr).id);
    printf("%i",empPtr->id);

    empPtr->id=1;
    strcpy(empPtr->name,"Fatma");
    empPtr->age=22;


}
////////////////////////////////////////////////////
//pass by value
//pass by address
void SwapV(int left,int right)
{
    int tmp;
    tmp=left;
    left=right;
    right=tmp;
}
int main()
{
    int x=3;
    int y=5;
    SwapV(x,y); //PASS VALUESSSSS
    printf("x=%i\n",x); ///3
    printf("y=%i\n",y); ///5
}
//////
void SwapA(int* left,int* right)
{
    int tmp;
    tmp=*left;
    *left=*right;
    *right=tmp;
}
int main()
{
    int x=3;
    int y=5;
    SwapA(&x,&y); //PASS Addresses
    printf("x=%i\n",x); ///5
    printf("y=%i\n",y); ///3
}


///////////////////////////////////////////////
//pass array to fn
//void MultibleArrayByTen(int  param[],int size)
//void MultibleArrayByTen(int  param[5])
void MultibleArrayByTen(int*  param,int size)
{
    //same code
    param[0]*=10;
    param[1]*=10;
    param[2]*=10;
}

int main()
{
    int arr[5]={1,2,3,4,5};
    MultibleArrayByTen(arr,5); //Address
}
///////////////////////////////////////////////
void Multible2DArrayByTen(int**  param,int size)
{
    //same code
    param[0][0]*=10;
    param[1]*=10;
    param[2]*=10;
}

int main()
{
    int arr[3][4];
    Multible2DArrayByTen(arr,5); //Address
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
    ptr[0]=1000; //99.9% Runtime Error

    ptr[0]=1000; //runs successful
    //1- static
    //2-dynamic allocations
}
//////////////////////////////////////////////////////
//Lab Assignments
//1- pointer to integer  read & write
//2- pointer to array  read and write   3 ways
//3- pointer to pointer of integer Write ONLY
//4- pass by value/address    swap
//5- pass array as input param []   ,pass pointer
//6- return [] as return type[not supported][compiler error]
    //and return pointer as a return type

//7- pointer to struct of employee   ->


