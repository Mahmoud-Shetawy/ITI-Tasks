//////////////////////////////////////////////////////
//pointers
//casting
//////////////////////////////////////////////////////
///pointers
//=> variable carries address of another variable in memory
//////////////////////////////////////////////////////

int main()
{
    int x=10;
    float y;
    printf("%d",x);
    printf("%x",&x);
    printf("%d",y);
    printf("%x",&y);
    return 0;
}

/////////////////////////////////////////////////////
///We wanna create variable carries addres of x
//or address of y
///thats called pointer
/////////////////////////////////////////////////////
int main()
{
    int x=77;

    int* ptr;
    ///create pointer of integer
    ///create variable can carries 
    //address of integer variable
    ///value of ptr=> null

    /////if we wanna assign address of x to ptr
    //ptr=x; //Logical error cause later runtime error 
    ////pointer carriess address another variable NOT Value
    ptr=&x; //TRUE


    return 0;
}

//////
int main()
{
    int x=77;
    int* ptr;  //???B
    
    ptr=&x; //TRUE

    printf("%d",x);
    printf("%x",&x);
    printf("%x",ptr); //print value of ptr -> address of x
    printf("%x",&ptr);

    ///If we wanna Print value of x via pointer
    printf("%d",*ptr); //77
    ///Print value of variable that pointer point at

    return 0;
}

//////////////////////////////////////////////////

int main()
{
    float y=1.2;      
    float* fptr;
    fptr=&y;

    printf("%f",y);
    printf("%x",&y);
    printf("%d",*y);  //Not A Pointer => Compile Error

    printf("%x",&fptr);
    printf("%x",fptr);
    printf("%f",*fptr);


    return 0;
}

/////////////////////////////////////////////////////
///Size of pointers

int main()
{
    int x=10;      //4B
    float y=20;    //4B    sizeof()
    char ch='m';   //1B

    int *iptr=&x;
    float* fptr=&y;
    char *cptr=&ch;

    ///pointer of any data type ALWAYS
    ///carriess address of another variable

    ///Pointer size 
    /// O.S 32Bit    4B    codeblocks 17.12  
    /// O.S 64Bit    8B    codeblocks 20.02
    printf("%d",sizeof(int*));  //B
    printf("%d",sizeof(float*));
    printf("%d",sizeof(char*));
    printf("%d",sizeof(iptr));
    printf("%d",sizeof(fptr));
    printf("%d",sizeof(cptr));

    return 0;
}

////////////////////////////////////////////////////
//Not Logic
int main()
{
    float y=1.234;
    int* ptr=&y;

    printf("%f",y);
    printf("%x",&y);
    printf("%x",ptr);
    printf("%x",&ptr);
    printf("%?",*ptr);

    //Program will Not work Properly
    //this is not Recommended

    //Remember: Pointer must be same data type of variable that will point
    return 0;
}

/////////////////////////////////////////////////////
///operators on pointer   [increment] [decrement]

int main()
{
    int x=10;
    int* ptr=&x;

    ptr++;
    //when increment pointer
    //it will be incremented by size of its datatype of variable\


    char ch='A';
    char* cptr=&ch;
    cptr++; 

    //???=cptr+1;   0x11


    double y=1.2;    //0x10
    double* dptr=&y;
    dptr++;  //0x18
    return 0;
}


////////////////////////////////////////////////////
//change value via pointer
int main()
{
    int x=10;

    int * ptr=&x;

    x=22; //True
    ptr=33; //FALSE
    *ptr=44;//TRUE
    return 0;
}
//////////////////////////////////////////////////////////////
///General purpose pointer ->>>  -> Dynamic Allocation
///pointer of void

int main()
{
    int x=10; //0x10

    void* ptr; //0x20
    printf("%d",sizeof(ptr));   //4B
    printf("%d",sizeof(void*)); //4B

    ptr=&x;

    printf("%d",x);
    printf("%d",&x);

    printf("%x",ptr);
    printf("%x",&ptr);

    printf("%d",*ptr);   //Compile Error  //compiler consider void
    //perfect solution => casting later
    
    //work round solution
    int * tmpptr=ptr;  //TRUE
    printf("%d",*tmpptr);  



    ///GPP cannot be incremented
    ptr++; //Compile Error

    return 0;
}

///////////////////////////////////////////////////////////
//pointer with array

int main()
{
    int arr[10]={1,2,3,4,5,6,7,8,9,10};

    int *ptr;

    ptr=arr; //T
    ptr=&arr;//T
    //ptr point fst element of array

    //1-print array via arr
    for(int i=0;i<10;i++)
    {
        printf("%d",arr[i]);
    }
    //2-print array via pointer ++
    for(int i=0;i<10;i++,ptr++)
    {
        printf("%d",*ptr/*++*/);
        /*ptr++;*/
    }
    //3-print array via pointer without ++  [+1]
    for(int i=0;i<10;i++)
    {
        printf("%d",*(ptr+i));   
    }
    //4-VIP [WHEN POINTER POINT ARRAY, IT ACTS LIKE ARRAY in using INDEXER]
    for(int i=0;i<10;i++)
    {
        printf("%d",ptr[i]);
        ///LIKE printf("%d",arr[i]);
    }
    return 0;
}

/////////////////////////////////
///read arrays via pointer
int main()
{
    int arr[10];
    int* ptr=arr;

    //#1
    for(int i=0;i<10;i++,ptr++)
    {
        printf("Enter value at index %i\n",i);
        scanf("%d",ptr); //T 
        //scanf("%d",&ptr);//FALSE  address of pointer ITSELF
        
    }
    ///Don't Forget to Reassign ptr to fst element of Array
    ptr=arr;
    //
    for(int i=0;i<10;i++,ptr++)
    {
        printf("Value at index %d is %d\n",i,*ptr);
    }

    //#2
    for(int i=0;i<10;i++)
    {
        printf("Enter value at index %i\n",i);
        scanf("%d",ptr+i); //T 
        //scanf("%d",&ptr);//FALSE  address of pointer ITSELF
        
    }
    
    for(int i=0;i<10;i++)
    {
        printf("Value at index %d is %d\n",i,*(ptr+i));
    }

    //#3 when pointer point array ,it acts like an array
    for(int i=0;i<10;i++)
    {
        printf("Enter value at index %i\n",i);
        scanf("%d",&ptr[i]); //T 
        //scanf("%d",&ptr);//FALSE  address of pointer ITSELF   
    }
    for(int i=0;i<10;i++)
    {
        printf("Value at index %d is %d\n",i,ptr[i]);
    }
    return 0;
}

//////////////////////////////////////////////////////////////////
///array itself is a constant pointer
int main()
{
    int arr[10];  // |10|20|||||||||
    //arr itself => constant pointer
    *arr=10;
    //arr++; ///Compile Error  //Constant pointer //cannot be changed

    *(arr+1)=20;

    int arr2[20];

    //arr2=arr; //Compile Error

}

/////////////////////////////////////////////////////
//Array of character with pointer
int main()
{
    char arr[10];

    char* cptr=arr;

    *cptr='A';
    cptr++;
    *cptr='l';
    cptr++;
    *cptr='i';
    cptr++;
    *cptr='\0';
    //REMEMBER
    cptr=arr;

    //
    *cptr='A';
    *(cptr+1)='L';
    *(cptr+2)='I';
    *(cptr+3)='\0';
    //
    cptr[0]='A';
    cptr[1]='L';
    cptr[2]='I';
    cptr[3]='\0';

    //
    scanf("%s",cptr);
    gets(cptr);

    printf("%s",cptr);
    puts(cptr);
    //

}

/////////////////////////////////////////////////////////
//Pointer To pointer

int main()
{
    int x=10;

    int * ptr=&x;

    int* * ptrToPtr=&ptr;

    printf("%d",x);
    printf("%x",&x);
    printf("%d",*x);

    printf("%x",ptr);
    printf("%x",&ptr);
    printf("%x",*ptr);

    printf("%x",ptrToPtr);
    printf("%x",&ptrToPtr);
    printf("%x",*ptrToPtr);
    printf("%x",**ptrToPtr);
    printf("%x",*(0x10));

    return 0;
}



int main()
{
    int x=10;
    int *ptr=&x;
    int *ptr2=&ptr;

    printf("%x",ptr2);//0x20
    printf("%x",&ptr2);//0x30
    printf("%x",*ptr2);//0x10   Compiler Consider it as Integer value

    printf("%d",**ptr2); //Compile Error
    //like
    printf("%d",*x);

}


//
int main()
{
    int *ptr;
    int **ptrToPtr;
    int ***ptrToPtrToPtr;
}
//

///////////////////////////////////////////////////////////////
//Swap

void Swap(int a,int b)
{
    int tmp;
    tmp=a;
    a=b;
    b=tmp;
}

void SwapAddress(int* a,int* b)
{
    int tmp;
    tmp=*a;
    *a=*b;
    *b=tmp;
}

int main()
{
    int x=10,y=20;

    //Swap(x,y);//passing values

    //pass by address
    SwapAddress(&x,&y);

    printf("%d",x);//20
    printf("%d",y);//10
}

///////////////////////////////////////////////////////
//Passing Array to Function
int multipleArray(int param[],int size)
int multipleArray(int param[10])
{
    int mul=1;
    for(int i=0;i<10;i++)
    {
        mul*=param[i];
    }
    return mul;
}

//standard code for passing array
int multipleArray(int* param,int size)
{
    int mul=1;
    for(int i=0;i<size;i++)
    {
        mul*=param[i];
    }
    return mul;
}

int main()
{
    int arr[10]={1,2,3,4,5,6,7,8,9,10};

    int res=multipleArray(arr,10);
}

//////////////////////////////////////////////////////
//return array from function

int* getArray()
{
    int arr[]={1,2,3,4,5};
    return arr; //return address of array [standard]   
}

int main()
{
    int *ptr=getArray(); //0x10

    printf("%d",*ptr);  //Rubbish //RUNTIME ERROR
    ///Arr became not exists after funcion call

}


///
int * SumArray(int * param)
{
    //for
    param[0]=33;

    return param;
}
int main()
{
    int arr[]={1,2,3,4,5};

    int * ptr=SumArray(arr); //address

    printf("%d",arr[0]); //33
}

/////////////////////////////////////////////////////////
//TypeDef

typedef struct Employee
{
    int id;
    char name[10];
    int age;
    float salary;
}; Employee 

int main()
{
    Employee e1;

    int x=3;

    typedef int Integer;

    Integer x=10;
}

/////////////////////////////////////
//Pointer to struct

struct Employee
{
    int id;
    char name[10];
    int age;
    float salary;
};

int main()
{
    struct Employee e1;   //22B
    e1.id=1;
    strcpy(e1.name,"Sara");
    e1.age=22;
    e1.salary=1234;

    struct Employee * empPtr;   //4B

    empPtr=&e1;

    (*empPtr).id=10;
    strcpy((*empPtr).name,"Ali");
    (*empPtr).age=22;
    (*empPtr).salary=1234;
    //Another simple solution
    //sugar syntax
    empPtr->id=10;
    strcpy(empPtr->name,"Ali");
    empPtr->age=22;
    empPtr->salary=1234;

}







