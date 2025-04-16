///pointers
///Datatype  can carry address of another data type in memory
//////////////////////////////////////////////////////////////
///


///Declatation for pointer
int x;

int* ptr; //pointer can carry address of integer variable
float* fptr; //pointer can carry address of float variable

/////////////////////////////////////////////////////////////
#include<stdio.h>
int main()
{
    int x=10;

    int* ptr;

    ptr=x; //WRONG  //Logic Error    //Cause Runtime Error 

    ptr=&x;


    float y=1.2;

    float* fptr=&y;

    return 0;
}


////////////////////////////////////////////////////
///access variable via pointer
int main()
{
    int x=10;

    int* ptr=&x;

    scanf("%d",x);//XXXX
    scanf("%d",&x);//T

    printf("%d",x);   //10
    printf("%x",&x);  //0x10

    printf("%x",ptr); //0x10
    printf("%x",&ptr); //0x20
    
    
    //get value of variable that pointer points at
    printf("%d",*ptr); //10

}


//////////////////////////////////////////////////
int main()
{
    float y=1.2;
    float* fptr=&y;

    printf("%f",y);
    printf("%x",&y);

    printf("%x",fptr);
    printf("%x",&fptr);
    printf("%f",*fptr);


    printf("%d",*y); ///COMPILE ERROR


    y=3.3;
    fptr=7.7; ///WRONG NOT COMPILE ERROR
    *fptr=7.7; //T

    printf("%f",*fptr);  //7.7
    printf("%x",fptr);  //0x10

}


//////////RUNTIME ERROR//////////////////////////
int main()
{
    int x=10;    //address 0x10
    int* ptr=x;  //address 0x20

    printf("%d",x); //10
    printf("%x",&x);//0x10

    printf("%x",ptr); //10
    printf("%x",&ptr);//0x20
    
    printf("%d",*ptr); //RUNTIME ERROR


}
///////////////////////////////////


///Size of Pointers
int main()
{
    int* ptr;
    float* fptr;
    char* cptr;
    //size
    //4B
    //8B
    //based of O.S 

    printf("%d",sizeof(int*));  //codblock17 4B  ...//codblock20 8B
    printf("%d",sizeof(ptr));  //codblock17 4B  ...//codblock20 8B

    printf("%d",sizeof(fptr));  //4B  
    printf("%d",sizeof(cptr));  //4B


    return 0;
}


//////////////////////////////////////////////////////////////////
//binary arithmatic operators on pointers 

int main()
{
    int x=10;
    int z=++x;
    int * ptr=&x;

    //ptr++;
    //inctrment value of pointer [0x10] by size of data type in bytes
    ???=ptr+1


    char ch='A';
    char * cptr=&ch;
    cptr++;
    ///inctrment value of pointer [0x10] by size of data type in bytes

}

////////////////////////////////////////////////////////////
//NOT RECOMMENDED

int main()
{
    float y=1.2;

    int* ptr=&y;

    *ptr=22; //logic error
    printf("%d",*ptr); //logic error

}


//////////////////////////////////////////////////////////
//General purpose pointer
//void* ptr;
///Dynamic Allocation
int main()
{
    int x=10;

    void* ptr;

    printf("%d",sizeof(void*));  //4B

    ptr=&x;

    printf("%x",ptr);  //0x10
    printf("%x",&ptr); //0x20
    printf("%x",*ptr); //Compile ERROR

    //workaround soln.
    int * tmp=ptr;

    //another soln;
    //CASTING


    ///GPP cannot be incremented
    ptr++; //Compile Error
}

/////////////////////////////////////////////////////////
///Pointer To Array
int main()
{
    int arr[]={1,2,3,4,5};

    int* ptr=arr;  //T
    int* ptr=&arr; //T
    int* ptr=arr[0]; //F 
    int* ptr=&arr[0]; //T 

    //Read fst elemnt of array
    scanf("%d",arr); //T
    scanf("%d",&arr); //T
    scanf("%d",&arr[0]); //T
    scanf("%d",arr[0]); //F
    scanf("%d",ptr); //T 
    scanf("%d",&ptr); //F 

    //read & write all elements from user in runtime
    //#1 Dangerous
    for(int i=0;i<5;i++,ptr++)
    {
        printf("Enter value at index %d\n",i);
        //scanf("%d",&arr[i]);
        scanf("%d",ptr);
    }
    //---> ptr  0x30
    //when increment pointer
    //REMEMBER to assign ptr value to fst element of Array Again
    ptr=arr;
    for(int i=0;i<5;i++,ptr++)
    {
        //printf("Value at index %i is %i",i,arr[i]);
        printf("Value at index %i is %i\n",i,*ptr);
    }
    ptr=arr;


    //#2
    for(int i=0;i<5;i++)
    {
        printf("Enter value at index %d\n",i);
        //scanf("%d",&arr[i]);
        scanf("%d",ptr+i);  //10 20  scanf("%d",0x14);
    }
    for(int i=0;i<5;i++)
    {
        //printf("Value at index %i is %i",i,arr[i]);
        printf("Value at index %i is %i\n",i,*(ptr+i));
    }

    //#3 [Recommended]
    ///when pointer points arrar
    ///it acts like array [indexer]
    for(int i=0;i<5;i++)
    {
        printf("Enter value at index %d\n",i);
        scanf("%d",&ptr[i]);
        
    }

    for(int i=0;i<5;i++)
    {
        printf("Value at index %i is %i",i,ptr[i]);
        //printf("Value at index %i is %i\n",i,*(ptr+i));
    }

    return 0;
}



////////////////////////////////////////////////////
///array name is constant pointer

int main()
{
    int arr[]={1,2,3,4,5};

    scanf("%d",arr);
    arr++; //Compile Error
    ///arr is a constant pointer
    scanf("%d",&arr);

    //T
    scanf("%d",arr+0);
    scanf("%d",arr+1);
    scanf("%d",arr+2);

    printf("%d",*arr);
    printf("%d",*(arr+1));

}

///////////////////////////////////////////////////////


//pointer To poinnter to integer

int main()
{
    int x=10;

    int *ptr=&x;

    int* *ptrToPtr=&ptr;

    printf("%d",x);
    printf("%x",&x);
    printf("%x",*x);
    
    printf("%x",ptr);
    printf("%x",&ptr);
    printf("%d",*ptr);

    printf("%x",ptrToPtr);
    printf("%x",&ptrToPtr);
    printf("%d",*ptrToPtr);
    printf("%d",**ptrToPtr);
    return 0;
}


///WRONG
int main()
{
    int x=10;

    int *ptr=&x;

    int *ptrToPtr=&ptr;

    printf("%d",x);
    printf("%x",&x);
    printf("%x",*x);
    
    printf("%x",ptr);
    printf("%x",&ptr);
    printf("%d",*ptr);

    printf("%x",ptrToPtr);
    printf("%x",&ptrToPtr);
    printf("%d",*ptrToPtr);
    printf("%d",**ptrToPtr);  //COMPILE ERROR
    return 0;
}


/////////////////////////////////////////////////////////

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
    //Swap(x,y); //pass values  (10,20)

    //think of pass address
    SwapAddress(&x,&y); //pass address
    
    printf("%i",x); //10
    printf("%i",y); /20
}


///////////////////////////////////////////


void MultipleArrayByTen(int param[],int size)
//Standard Code
void MultipleArrayByTen(int* param,int size)
{

}

int main()
{
    int arr[]={1,2,3,4,5};
    MultipleArrayByTen(arr,5);
}


//Standard
int* GetArray()
{
    int arr[]={1,2,3,4,5};
    return arr;
}

int main()
{
    int* ptr=GetArray();

    *ptr=100;  //RUNTIME ERROR
    ptr[0]=100; //RUNTIME ERROR
}



///////////////////////////////////////////////////////
struct Employee
{
    int id;
    char name[10];
    int age;
    float salary;
};


int main()
{
    struct Employee e1;

    printf("%x",&e1);
    printf("%x",e1);

    e1.id=1;
    //e1.name="Ali";
    strcpy(e1.name,"Ali");
    e1.age=22;
    e1.salary=1234;

    struct Employee* empPtr;  //4B
    empPtr=&e;


    (*empPtr).id=2;
    strcpy((*empPtr).name,"Sara");
    (*empPtr).age=22;
    (*empPtr).salary=1234;

    //-> arrow
    empPtr->id=2; ///===(*empPtr).id=2;
    empPtr->age=33;
    empPtr->salary=1234;
    strcpy(empPtr->name,"Sara");


    scanf("%d",&empPtr->id);


}

/////////////////////////////////////////

int main()
{
    struct Employee employees[5];

    struct Employee * empptr;

    empptr=employees; //T
    empptr=&employees; //T
    empptr=&employees[0]; //T


    empptr[0].id=22;


    empptr->id=22
    empptr++;

    (empptr+1)->id=2;

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
