//--> turnary operator =>if else   
//int x=(condition)?Value true : value false
//getchar(),strcmp(,),strcmpi(,)
//////////////////////////////////////////////////////
//pointers
//casting
//////////////////////////////////////////////////////
//pointer:
///variable carries address of another variable

///int x=10;  
//store in Stack variable x with value 10
//inside address 0x10  size 4 byte

///int* ptr;
///sore in Stack variable ptr with value NULL
//inside address 0x30 size 8 byte 64Bit  4 Byte 32 Bit

///int *ptr=x;   //int* ptr=10;
///Runtime Error

///int *ptr=&x;
///sore in Stack variable ptr with value NULL
//inside address 0x30 size 8 byte 64Bit  4 Byte 32 Bit


/////////////////////////////////////////////////////////////
#include<stdio.h>
int main()
{
    int x=10;  //size 4byte value 10 in addres 0x10  
    int* ptr;  //size 4 Byte value NULL in address 0x20
    
    //int *ptr=&x;
    ptr=&x; //size 4 Byte value 0x10 in address 0x20

    printf("x=>%d\n",x);        //10
    printf("&x=>%x\n",&x);      //0x10
    printf("ptr=>%d\n",ptr);    //0x10
    printf("&ptr=>%x\n",&ptr);  //0x20
    
    return 0;
}


//////////////////////////////////////////////
//if we wanna print value for pointer points at not address

#include<stdio.h>
int main()
{
    int x=10;  //size 4byte value 10 in addres 0x10  
    int* ptr;  //size 4 Byte value NULL in address 0x20
    
    //int *ptr=&x;
    ptr=&x; //size 4 Byte value 0x10 in address 0x20

    printf("x=>%d\n",x);        //10
    printf("&x=>%x\n",&x);      //0x10
    printf("ptr=>%d\n",ptr);    //0x10
    printf("&ptr=>%x\n",&ptr);  //0x20
    printf("value for ptr points =>%d\n",*ptr);  //10
    //*ptr => get , set value for variable poiner points/references
    //on it 

    //setter
    ptr=22; //Runtime Error
    *ptr=22;
    
    return 0;
}

////////////////////////////////////////////////
//read from user by pointer

#include<stdio.h>
int main()
{
    int x=10;  //size 4byte value 10 in addres 0x10  
    int* ptr;  //size 4 Byte value NULL in address 0x20

    //printf("%d",*ptr); //runtime error error

    //int *ptr=&x;
    ptr=&x; //size 4 Byte value 0x10 in address 0x20

    //printf("%d",*ptr);   //10


    printf("Enter value of x\n");
    scanf("%d",&x);   //0x10
    printf("The value of x is %d",x);

    //via pointer
    printf("Enter value of x by pointer\n");
    scanf("%d",ptr);   //0x10 //ptr   , &ptr   , *ptr
    printf("The value of x by pointer is %d",*ptr);
    
    return 0;
}


/////////////////////////////////////////////////////////
///size of pointers
#include<stdio.h>
int main()
{
    int* iptr;  //4byte
    char* cptr; //4byte
    float* fptr;//4byte

    //printf("%d",sizeof(int*));
    //printf("%d",sizeof(iptr));
    //pointer of any datatype
    //carries always address

    int x=10;
    char ch='M';
    float fl=3.4;

    iptr=&x;
    cptr=&ch;
    fptr=&fl;

    //Print values
    printf("%d",*iptr); //10
    printf("%c",*cptr); //M
    printf("%f",*fptr); //3.4

    //Print Address contain
    printf("%d",iptr); //0x10
    printf("%d",cptr); //0x20
    printf("%d",fptr); //0x30

    ///Print  pointer Address itself 
    printf("%d",&iptr); //0x40
    printf("%d",&cptr); //0x50
    printf("%d",&fptr); //0x60

    

    return 0;
}

/////////////////////////////////////////////////////////
///increment or decrement pointers

int main()
{
    int x=10;
    int* ptr=&x;

    ptr++;
    //increment value of ptr
    //increment by size of data type

    //
    printf("%d",*ptr);  //rubbish or runtime error 
    //

    char ch='M';
    char* cptr=&ch;

    cptr++;
    //increment value of cptr
    //increment by size of data type


    return 0;
}


/////////////////////////////////////////
int main()
{
    int x=10;

    float* ptr=&x;   //Run normally

    printf("%d",*ptr); //non Run normally

    *ptr=77.7;

    return 0;
}

//////////////////////////////////////////////////////////
///pointer to void
///general purpose pointer
///Later used
int main()
{
    int x=10;

    void* ptr=&x;

    printf("%d",sizeof(void*));  //4
    printf("%d",sizeof(ptr));  //4


    printf("%d",*ptr); //10

    *ptr=22;

    return 0;
}

/////////////////////////////////////////////////////////
//array

int main()
{
    int arr[10]={0};
    
    //int* ptr=&arr[0];
    //int* ptr=arr;
    int* ptr=&arr;
    
    for(int i=0;i<10;i++,ptr++)
    {
        printf("Enter Elelment At index %d\n",i);
        scanf("%d",ptr);//0x10
        //ptr++;
    }

    //DON'T FORGET Assign ptr again to first of array
    ptr=arr;
    //ptr=&arr;
    //ptr=&arr[0];
    for(int i=0;i<10;i++,ptr++)
    {
        printf("value at index %d is %d",i,*ptr);
    }

    
    //pointer when point arrays
    //it acts as an array
    for(int i=0;i<10;i++)
    {
        printf("Enter Elelment At index %d\n",i);
        scanf("%d",&ptr[i]);//0x10
        //ptr++;
    }

    
    for(int i=0;i<10;i++,ptr++)
    {
        printf("value at index %d is %d",i,ptr[i]);
    }


    /*
    for(int i=0;i<10;i++)
    {
        printf("enter element atindex %d",i);
        scanf("%d",&arr[i]);
    }

    for(int i=0;i<10;i++)
    {
        printf(" element at index %d is %d\n",i,arr[i]);
        
    }
    */

    /*
    printf("%x",&arr[0]); //0x10
    printf("%x",arr);  //0x10
    printf("%x",&arr); //0x10

    printf("%x",ptr); //0x10
    printf("%x",&ptr); //0x90
    */



    return 0;
}



/////////////////////////
///array itself is constant pointer
int main()
{
    int arr[10]={0};

    for(int i=0;i<10;i++)
    {
        printf("Enter elelment \n");
        scanf("%d",&arr);
        arr++; //Compile Error  //constant pointer
    }
    
    return 0;
}

///////////////////////////////////////////////////
////pointer to pointer to datatype[int]

int main()
{
    int x=10;

    int* ptr=&x;

    int** ptrToptr=&ptr;

    printf("%d",x); //10
    printf("%d",&x);//0x10
    printf("%d",*x);//Compile error
    
    printf("%d",ptr); //0x10
    printf("%d",&ptr);//0x20
    printf("%d",*ptr);//10

    printf("%d",ptrToptr);//0x20
    printf("%d",&ptrToptr);//0x30
    printf("%d",*ptrToptr);//0x10
    printf("%d",**ptrToptr);//10

    return 0;
}


/////////////////////////////////////////////////

//


void swap(int a,int b)
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
    int x=10;
    int y=20;
    /*
    printf("before Swap \n");
    printf("x=>%d\n",x); //10
    printf("y=>%d\n",y); //20

    swap(x,y); //pass by value

    printf("After Swap \n");
    printf("x=>%d\n",x); //10
    printf("y=>%d\n",y); //20
    */

    SwapAddress(&x,&y); //pass by address
    
    
    printf("x=>%d\n",x); //20
    printf("y=>%d\n",y); //10
    return 0;
}


////////////////////////////////////////////////////

//pointer to Array

#include<stdio.h>

int main()
{
    int arr[10]={0};
    
    //int* ptr=&arr[0];
    //int* ptr=arr;
    int* ptr=&arr;

    //
    //int x=10;   //0x10
    //int* tmpptr=&x;  
    ////tmpptr++;
    //int * anotherptr=tmpptr+10 ; //=> move 10*sizeof(int) //0x50
    //    
    for(int i=0;i<10;i++)
    {
        printf("Enter value at index %d\n",i);
        scanf("%d",ptr+i);
    }

    
    for(int i=0;i<10;i++)
    {
        printf("value at %d is %d",i,*ptr+i);
    }
}


//////////////////////////////////////////////
int main()
{
    char arr[5];
    char *ptr=arr;

    /*
    *ptr='A';
    *(ptr+1)='B';
    ptr[2]='C';
    */
   //#1
   *ptr='A';
   ptr++;
   *ptr='B';
    ptr++;
    //when print =< dont forget ptr=arr;

    //#2
    *(ptr+0)='A';
    *(ptr+1)='B';
    *(ptr+2)='C';
    //When print , no need to initiate ptr again

    //#3
    ptr[0]='A';
    ptr[1]='B';


    scanf("%s",ptr);
    gets(ptr);

    return 0;
}



////////////////////////////////////////////////////////////


void MultipleArrayByTen(int param[],int size)
{
    for (int i = 0; i < size; i++)
    {
        param[i]*=10;
        printf("%d\n",param[i]);
    }
    
}

//Standard code
void MultipleArrayByTenAddress(int* param,int size)
{
    for (int i = 0; i < size; i++)
    {
        param[i]*=10;
        printf("%d\n",param[i]);
    }
    //or  => not affective
    for (int i = 0; i < size; i++,param++)
    {
        *param*=10;
        //printf("%d\n",*param);
    }
    //or

    for (int i = 0; i < size; i++,)
    {
        *(param+i)*=10;
        printf("%d\n",*(param+i));
    }
    //print
    
}


int main()
{
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    
    //MultipleArrayByTen(arr,10);
    
    //MultipleArrayByTenAddress(&arr,10);
    MultipleArrayByTenAddress(arr,10);

}

/////////////////////////////////////////////////////

int* multipleArrayByTenAddress2 (int *param,int size)
{
    for(int i=0;i<size;i++)
    {
        param[i]*=10;
    }
    return param;
}

int main()
{
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    int *ptr =MultipleArrayByTenAddress2(arr,10);


    //for loop
    /print ptr[i]
    return 0;
}


/////////////////////////////////////////////////////
#define size 10;

int* GetNewArray()  //runtime error
{
    int arr[10]={1,2,3,4,5,6,7,8,9,10};  //0x10
    return arr;
}

int main()
{
    //int newarr[10]=GetNewArray(); //True
    
    //int x[10];
    //x=GetNewArray();
    
    int *ptr=GetNewArray();   //0x10   destructed
    //size undefined
    return 0;
}

////////////////////////////////////////////////////

struct Employee
{
    int id;
    char name[10];
    int age;
};

int main()
{
    struct Employee e1;   //14Byte
    e1.id=10;
    e1.name="Rehab";//CXXXXX
    strcpy(e1.name,"Rehab");

    struct Employee* ptr;  //4Byte
    ptr=&e1;

    (*ptr).id=22;
    strcpy((*ptr).name,"Mohamed");

    (*ptr).age=12;
    ///////// -> arrow
    ptr->id=10;
    strcpy(ptr->name,"Mariem");
    ptr->age=30;
    (*ptr).id=10;
    /////////

    return 0;
}

////////////////////////////////////////////////////


//Lab Assignments
//1- pointers to integers  read & write
//2- pointers to array  read and write   3 ways
//3- pointer to pointer of integer
//4- pass by value/address    swap
//5- pass array as input param []   ,pass pointer
//6- return [] as return type[not supported][compiler error]
        //and return pointer as a return type

//7- pointer to struct of employee   ->






