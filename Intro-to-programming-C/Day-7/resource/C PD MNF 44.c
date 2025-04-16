//casting
//dynamic allocation
//recursive function
///////////////////////////////////////////////
//pointers Revision
#include<stdio.h>
int main()
{
    int a=1,b=2,c=3,d=4;
    int* ptrarr[4];  //4*4B or 4*8B
    
    //put address of a in fst elemet of array
    ptrarr[0]=a; //F
    ptrarr[0]=&a; //T
    ptrarr=&a;    //F  -> ptrarr itself constant address

    ptrarr[1]=&b;
    //..

    int* ptrArr[4]={&a,&b,&c,&d};
    // //
    // int arr[5];
    // int *ptr=arr;
    // //
}

int main()
{
    int arr[4]={1,2,3,4};
    int* ptrArr[4];  //|&arr[0]|..|..|..|

    ptrArr=arr; //F  -> LValue
    ptrArr[0]=arr; //T
    ptrArr[0]=&arr; //T
    ptrArr[0]=&arr[0]; //T
    *ptrArr=arr; //T
}
//////////////////////////////////////////////////////
//Casting
///Convert value from data type to another data type
//Casting
//data type can be converted to another one ,,, True
//latest C Versions , this will be done Implicitly
//Implicitly =>compiler will do it itself 
//Explicitly => you [developer ] will do it yourself

int main()
{
    int x=22;     //4B => +-2Billion
    double y=33333333333;  //8B => +-222,222Billion

    // //implicit casting
    // //safe casting
    // y=x;
    // //explicit casting [useless]
    // y=(double)x;
    
    //NO ERROR
    //implicit cast
    //unsafe casting [developer must be catious]
    x=y;
    //explicit cast[useless]
    x=(int)y;

    printf("x=>%i\n",x); //rubbish 
    printf("y=>%lf",y);  //333333333333
}
/////////////////////////////////////////////////
int main()
{
    int x=3,y=4;
    float z;

    z=(float)x/y;

    printf("%f",z); //0.75
}

//DT promotion
//int -> long -> float -> double

int main()
{
    char ch='M'; 
    int x=3;

    int z=x+ch;
    printf("%i",z); //80
    int _size=10;
    int arr[_size];
}

////////////////////////////////////////////////////////
////////////////////////////////////////////////////
//array of 24 students

//array resized to 25 students=> Impossible
//Array -> Fixed size [up and running applocation]

//////////////////////////////////////////////////////////////
//dynamic Allocation [allocation at runtime]

//array => fixed size
/////we cannot declare array based on 
//specific/different size in runtime
/////array when declared 
//,cannot be modified or deleted ->end of scope

//RUNTIME 
////think to allocate dynamic place in runtime
////based on specific value
//Think of deallocate this place whenever i want


/////dynamic allocation
///allocate specific value/values in runtime
///based on specific size 
///Stored in Heap  =>c,c++,java,c#

//syntax      HLL===>new
//in c   stdlib.h
/////    void* malloc(size in bytes)
/////    {code} 

//////////////////////////////////////////////
#include<stdio.h>
#include<stdlib.h> //malloc()
int main()
{
    malloc(40);
    //40 bytes have been allocated 
    //in heap
    //and malloc  
    //return address of fst element as pointer to void

    //at this point
    //pointer to void is returned to nothing
    return 0;
}

#include<stdio.h>
#include<stdlib.h> //malloc()
int main()
{
    //REMEMBER CAREFULLY WHEN Allocate 
    //then allocate right based on your DT
    int * ptr;
    ptr= malloc(15); //|#|#|#|...|
    //ptr=(int*)malloc(16); //useless //its done implicitly
    return 0;
}

#include<stdlib.h> //malloc()
int main()
{
    double * ptr;
    ptr= malloc(16);
    //ptr=(double*)malloc(16); //useless //its done implicitly
    *ptr=10; //T
    ptr++;
    *ptr=20; //T
    ptr++;
    *ptr=30; //T
    ptr++;
    *ptr=40; //T
    ptr++;
    *ptr=50; //T


    return 0;
}

#include<stdlib.h> //malloc()
int main()
{
    char * ptr;
    ptr= malloc(16);
    //ptr=(char*)malloc(16); //useless //its done implicitly
    return 0;
}

////////////////////////////////////////////////////
//to ask user number of integer element do you want

int main()
{
    int _size;

    printf("Enter array size\n");
    scanf("%i",&_size);

    // int* ptr=  malloc(_size*4);
    int* ptr=  malloc(_size* sizeof(int));
    
    // int* ptr=  (int*)malloc(_size* sizeof(int)); //useless

    //enter data of integer then print it
    //v1 [VERY DANGEROUS ISSUE]  int *tmpPtr=ptr; NOT RECOMMENDED
    for(int i=0;i<_size;i++)
    {
        printf("Enter # at index %i/n",i);
        scanf("%i",ptr); //T
        //scanf("%i",&ptr); //F
        ptr++;
    }
    //
    for(int i=0;i<_size;i++)
    {
        printf("# at index %i is %i/n",i,*ptr);
        ptr++;
    }

    //v2
    for(int i=0;i<_size;i++)
    {
        printf("Enter # at index %i/n",i);
        scanf("%i",ptr+i); //T
    }
    for(int i=0;i<_size;i++)
    {
        printf("# at index %i is %i/n",i,*(ptr+i));
    }

    //V3 Very RECOMMENDED
    //when pointer points array ,it acts like an array
    //int* ptr=  malloc(_size* sizeof(int));
    //at this moment we can consider int * ptr => int ptr[_size]

    for(int i=0;i<_size;i++)
    {
        printf("Enter # at index %i/n",i);
        scanf("%i",&ptr[i]); //T 
    }
    for(int i=0;i<_size;i++)
    {
        printf("# at index %i is %i/n",i,ptr[i]);
    }
}


int main()
{
    int charSize;

    printf("Enter char size");
    scanf("%i",&charSize);//10

    char* cptr= (char*) malloc(charSize * sizeof(char));
    //at this moment
    //we can consider char * cptr === char cptr[10]


    *(cptr+0)='A';
    *(cptr+0)='l';
    *(cptr+0)='i';
    *(cptr+0)='\0';

    cptr[0]='A';
    cptr[0]='l';
    cptr[0]='i';
    cptr[0]='\0';

    scanf("%s",cptr);
    gets(cptr);
}

///////////////////////////////////////////////////////
//deallocate at any time by 
//free(pointer);

int main()
{
    int *ptr=malloc(10 * sizeof(int));
    int *ptr2=malloc(10 * sizeof(int));
    for(int i=0;i<10;i++)
    {
        printf("Enter data\n");
        scanf("%i",&ptr[i]);  //|10|20|30|..|100|
    }

    //
    free(ptr);
    free(ptr2);
    //printf("%i",*ptr); //10 //RUBBISH
    //code
    return 0;
}

    //////free -> 
    //remove protection for allocated bytes
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

void TryMe()
{
    int *ptr=malloc(12);
}

int main()
{
    TryMe();
    TryMe();
    TryMe();
    //dangerous memory leackage
    //REMEMBER to deallocate at right point
}
/////
int* TryMe()
{
    int *tmpptr=malloc(12);
    return tmpptr;
}

int main()
{
    int * ptr=TryMe();
    ptr[0]=22;
    free(ptr);

    //*ptr++;  ربنا يوفقك
    //runs successfully
    //  ابعدوا عن المشتبهات
}

int main()
{
    int size=10;
    int arr[size];

    free(arr); //WRONG  -> from heap not stack

}
/////////////////////////////////////////////////////////
//dynamic allocation for array of pointers
int main()
{
    int* ptrArr[3];

    ptrArr[0]=malloc(4 * sizeof(int));
    ptrArr[1]=malloc(4 * sizeof(int));
    ptrArr[2]=malloc(4 * sizeof(int));

    ////at this moment
    //int* ptrArr[3] ===> int ptrArr[3][4];
    //like 2D Array

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            ptrArr[i][j]=10;
        }
    }

    //Deallocate
    //free(ptrArr);   //BIG WRONG

    free(ptrArr[0]);
    free(ptrArr[1]);
    free(ptrArr[2]);

    return 0;
}

/////////////////////////////////////////
///ptrarr[3][???]
///ptrarr[?][?]
int main()
{
    int col=4,row=3;
    int **ptrArr;

    ptrArr= (int **) malloc(row * sizeof(int*));  //codeblocks17 T ,codeblocks20 F
    //from this mement
    //int ** ptrarr ===int* ptrArr[3];
    ptrArr[0]=malloc(col * sizeof(int));
    ptrArr[1]=malloc(col * sizeof(int));
    ptrArr[2]=malloc(col * sizeof(int));

    //from this mement
    //int * ptrarr[3] ===int ptrArr[3][4];

    //2D Array

    //BIG MEMORY LEACKAGE
    free(ptrArr);

    //REMEMBER
    free(ptrArr[0]);
    free(ptrArr[1]);
    free(ptrArr[2]);
    free(ptrArr);
}

//////////////////////////////////////////////////
//WRONG
int main()
{
    int col=4,row=3;
    int *ptrArr;

    ptrArr= malloc(row * sizeof(int*));  //codeblocks17 T ,codeblocks20 F
    //from this mement
    //int ** ptrarr ===int* ptrArr[3];
    ptrArr[0]=malloc(col * sizeof(int));
    ptrArr[1]=malloc(col * sizeof(int));
    ptrArr[2]=malloc(col * sizeof(int));

    //from this mement
    //int * ptrarr[3] ===int ptrArr[3][4];

    //2D Array
    ptrarr[0][0]=22; //compile Error



    //BIG MEMORY LEACKAGE
    free(ptrArr);

    //REMEMBER
    free(ptrArr[0]);
    free(ptrArr[1]);
    free(ptrArr[2]);
    free(ptrArr);
}

////////////////////////////////////////////
//return Array from fn

int* getArray()
{
    int arr[5];
    return arr;
}

int ** get2DArray()
{
    int arr[3][4];
    return arr;
}

///////////////////////////////////////////////////
////////////////////////////////////////////
///recursive function
//function calls itself
//functions contain
//1- for loop plus
//2- it ends with certain break
////1     0

//3- use with programming/mathematical equations
///factorial    4! =
///power       2P3=   ZERO

//Stack Overflow
void Print()
{
    Print();
}
main()
{
    Print();
}

int Factorial(int num)
{
    if(num>=0)
    {
        if(num==1||num==0){return 1;}
        else
        {
            return num*Factorial(num-1);
            return -5; //unreachable code
        }
    }
    //throw runtime error
    //
}
int main()
{
    int result=Factorial(4);
    return 0;
}

///////////////////

int Power(int _base,int _power)
{
    if(_power==0){return 1;}
    else
    {
        return _base * Power(_base,_power-1);
    }
}

int main()
{
    int b=2;
    int p=3;

    int result=Power(b,p);
}

///////////////////////////////////////////////////////
//Lab Assignments


///1- try dynamic allocation
// for pointer to integer read and write  2ways
///2- try dynamic allocation for pointer
// topointer to integer read and write
//// int **arr -> int arr[3][4]
///3- pass array to fn
///4- return array to fn

//5- 10 Employees with highlighted menu
/////??? Employees with highlighted menu

struct Employee
{
    int id;
    char name[10];
};

int main()
{
    struct Employee* empPtr;
    int _size=10;

    empPtr= malloc(_size * sizeof(struct Employee));

    //from this moment
    //struct Employee* empPtr ====struct Employee empPtr[10]
    empPtr[0].id=1;
    strcpy(empPtr[0].name,"Sraa");
    free (empPtr);
}



//I'll Reciece ALL LABS from day 1
//in google drive 
//and send it as message to me in ms teams
//tomorrow @11 PM ISA