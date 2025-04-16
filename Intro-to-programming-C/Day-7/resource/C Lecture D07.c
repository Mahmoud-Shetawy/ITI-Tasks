//casting
//pointers revision
//dynamic allocation
//recursive function
/////////////////////////////////////////////////////////

#include<stdio.h>

int main()
{
    int x=10;
    int* ptr;
    ptr=&x;

    printf("%d",*ptr);
    return 0;
}

////////////array of pointers///////////////////////////
int main()
{
    int a=1,b=2,c=3,d=4;
    int * arr[4];
    //array of pointers 4

    //
    arr[0]=&a; //or
    arr=&a;
    
    arr[1]=&b;
    arr[2]=&c;
    arr[3]=&d
    //
    //arr++ XXX=>array =>constant pointer


    //default value
    int* arr2[4]={&a,&b,&c,&d};
    //
    return 0;
}


/////////////////////////////
int main()
{
    int arr[4]={1,2,3,4};

    int* ptrarr[4];

    ptrarr[0]=&arr[0];
    ptrarr[0]=&arr;
    ptrarr[0]=arr;
    ptrarr=arr;

    ptrarr[1]=&arr[1];
    //ptrarr[1]=arr+1;

    //int *ptr=&x;
    


    return 0;
}


//////////////////////////////////

struct Employee 
{
    int id;
    char name[10];
    int age;
};

int main()
{
    struct Employee e1; //18Byte

    struct Employee * ptr; //4Byte

    ptr=&e1;

    (*ptr).id=10;
    //arrow ->
    ptr->age=22;
    strcpy(ptr->name,"Sara");

    return 0;
}

////////////////////////////////////
//casting
//data type can be converted to another one ,,, True
//latest c Versions , this will be done Implicitly
//Implicitly =>compiler will do it itself 
//Explicitly => you [developer ] will do it yourself


int main()
{
    int x=22;  //4byte 2billion
    double y=22222222222; //8byte 10po123

    //y=x; //implicitly

    x=y;   //c implicitly   //C# Compiler error

    x=(int)y; //casting explicitly


    printf("x=>%i \n",x); //rubbish
    printf("y=>%lf \n",y);//22222222

    return 0;
}

//////////////////////////////////
int main()
{
    int x=3,y=4;
    float z;
    z=(float)x/y;  //explicit cast  (int)x    /    y 
    printf("%f",z);  //0.75
    return 0;
}

//promotion
//high datatype to datatype higher
//int => float => long => double

int main()
{
    int x=2B,y=2B;

    double z=(double)x+y; //???? 

    int a=10;
    double b=20;

    double c=a+b;
    return 0;
}


/////////////////////////////////
int main()
{
    char ch='M';
    int x=3;
    int z=x+ch;
    printf("%d",z);
    return 0;
}

///pointer to void/////////////////////////////
int main()
{
    int x=10;
    void* ptr=&x;

    printf("%d",*ptr); //compile error

    //#1
    int* tmpptr=(int*)ptr;
    //unnecessary
    //comiler casting implicitly
    int* tmpptr=ptr;
    printf("%d",*tmpptr); //10

    //#2
    printf("%d",(int*)ptr); //address
    printf("%d",*((int*)ptr)); //10



    return 0;
}

//////////////////////////////////////////
//dynamic Allocation

//array => fixed size
/////we cannot declare array based on specific/different size in runtime
/////array when declared ,cannot be modified or deleted ->end of scope

////think to allocate dynamic place in runtime
////based on specific value



/////dynamic allocation
///allocate specific value/values in runtime
///based on specific size

//syntax      HLL===>new
//in c
/////    void* malloc(size in bytes); 


///data allocated via dynamic allocation
///stored in Heap


int main()
{
    int *arr; //4byte

    //allocate 4 places of integer
    //arr=(int*)malloc(16);
    arr= malloc(16);

    ///arr acts as an array

    return 0;
}


int main()
{
    char * cptr;
    //5 characters
    //ptr=(char*)malloc(5);
    ptr=malloc(5);
    return 0;
}

//////////////////////////

int main()
{
    int size;
    int *ptr;
    printf("Enter Array Size\n");
    scanf("%d",&size); //10

    //ptr=(int*)malloc(size*sizeof(int));
    ptr=malloc(size*sizeof(int));

    //ptr acts as an array

    //normal
    for(int i=0;i<size;i++)
    {
        printf("Enter value at index %d\n",i);
        scanf("%d",&ptr[i]);
    }
    for(int i=0;i<size;i++)
    {
        printf("value at index %d is %d\n",i,ptr[i]);
    }
    //

    //Dangerous
    for(int i=0;i<size;i++,ptr++)
    {
        printf("Enter value at index %d\n",i);
        scanf("%d",ptr);
    }
    //print ???
    
    //

    //another solution
    int * tmp= ptr; 
    for(int i=0;i<size;i++,tmp++)
    {
        printf("Enter value at index %d\n",i);
        scanf("%d",tmp);
    }

    return 0;
}



////////////////////////////////
int main()
{
    int size;
    char *ptr;
    printf("Enter Array Size\n");
    scanf("%d",&size); //10

    ptr= malloc(size * sizeof(char));

    //
    gets(ptr);
    //
    scanf("%s",ptr);
    //while(Not Enter)
    //{
        //ptr[i]=ch;
    //}
    //ptr[i]='\0';
    
    return 0;
}

////deallocate data////////////////////////////


int main()
{
    int size;
    int *ptr;
    printf("Enter Array Size\n");
    scanf("%d",&size); //10

    //ptr=(int *)malloc(size  * sizeof(int));
    ptr=malloc(size  * sizeof(int));
    
    //
    free(ptr);
    //
    
    
    return 0;
}


//array of pointers////////////////////////////////////////////////

int main()
{
    int* ptr[3];

    ptr[0]=malloc(4 * sizeof(int));
    ptr[1]=malloc(4 * sizeof(int));
    ptr[2]=malloc(4 * sizeof(int));

    //int *ptr[3] === int ptr[3][4]
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            ptr[i][j];
        }
    }
    free(ptr[0]);
    free(ptr[1]);
    free(ptr[2]);

    return 0;
}

////////////////////////////////

int main()
{
    int row,col;

    printf("Enter Row\n");
    scanf("%d",&row); //3
    printf("Enter Column\n");
    scanf("%d",&col); //4

    int **ptr;   //jagged

    //ptr=(int **)malloc(row *sizeof(int *));
    ptr=malloc(row *sizeof(int *));
    //int **ptr ===> int * ptr[3]

    ptr[0]=malloc(col* sizeof(int));
    ptr[1]=malloc(col* sizeof(int));
    ptr[2]=malloc(col* sizeof(int));
    //int *ptr[3]====int arr[3][4]


    ptr[0][0]=10;


    free(ptr[0]);
    free(ptr[1]);
    free(ptr[2]);
    free(ptr);

    return 0;
}

/////////////////////////////////////////////

int *ptr;
//                          4
ptr= (int *) malloc(10* sizeof(int*));

//int *ptr  ===> ptr[10]   array of integers

ptr[i]=malloc(12);


////////////////////////////////////////////////
//

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


////////////////////////////////////

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



////int *ptr   =>  ptr[]
////int **ptr   => int *ptr[]   =>  int ptr[][]

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
    x[0]=22;


    getAnotherArray2();
    getAnotherArray2();
    getAnotherArray2();
    getAnotherArray2();
    getAnotherArray2();

    return 0;
}





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

//////////factorial///////////////////////////////////////
int Fact(int param)//1
{
    //int retVal;
    if(param==1)
    {
        return 1;
    }
    else
    {
        return param*Fact(param-1);
    }
}

int main()
{
    int x=4;
    int result=Fact(x);
    return 0;
}

//Power/////////////////////////////////////////////

int Pow(int b,int p)
{
    if(p==0)
    {
        return 1;
    }
    else
    {
        return b * Pow(b,p-1);
    }
}

int main()
{
    int x=2,y=4;
    
    int result=Pow(x,y); //16
}







//////////////////////////////////////////////////////////
//Lab Assignments
//1- Try Casting
//2- malloc with int * ptr 
//3- malloc with int ** ptr
//!!!- highlighted menu with 10 employees    [choose index] 
//5- highlighted menu with undefined employees    [choose index] 
struct Employee earr[10];

int size; //10

struct Employee * empptr=malloc(10 * sizeof(struct Employee));



/////////////////////////////////////////////////////////

struct Employee
{
    int id;
    char name[10];
    int age;
};

int main()
{
    int size=10;


    //

    //

    struct Employee *empPtr;

    empPtr=malloc(size  *  sizeof(struct employee));
    //empPtr act as an array

    empPtr[0].id=22;

    empPtr->id=22;
    (empPtr+1)->id=22;

    free(empPtr);

}
