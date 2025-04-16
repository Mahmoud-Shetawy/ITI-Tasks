//casting
//pointers revision
//dynamic allocation
//recursive function
////////////////////////////////////////////////////////
int main()
{
    int a=1,b=2,c=3,d=4;
    int* ptrarr[4];

    //ptrarr=a;
    //ptrarr=&a;

    ptrarr[0]=&a;
    ptrarr[1]=&b;
    ptrarr[2]=&c;
    ptrarr[3]=&d;

    int * ptrArr[4]={&a,&b,&c,&d};

}

int main()
{
    int arr[4]={1,2,3,4};
    int* ptrArr[4];

    //ptrarr=arr;
    ptrArr[0]=arr; //T
    ptrArr[0]=&arr; //T
    ptrArr[0]=&arr[0]; //T

}

/////////////////////////////////////////////

//Casting
///Convert value from data type to another data type
//casting
//data type can be converted to another one ,,, True
//latest c Versions , this will be done Implicitly
//Implicitly =>compiler will do it itself 
//Explicitly => you [developer ] will do it yourself


int main()
{
    int x=22;
    double y=33;//5,000,000,000

    ////implicit cast
    //safe casting
    //y=x;
    ////explicit cast => useless
    //y=(double)x;

    //unsafe casting
    x=y;
    x=(int)y;

    printf x  //Rubbish
    printf y  //5B
}

int main()
{
    int x=3,y=4;
    float z;

    z=(float)x/y;

    printf x //3
    printf y //4
    printf z //Zero
}

//promotion
//int->float->long -> double

int main()
{
    char ch='M';
    int x=3;

    int z=x+ch;

    printf z //80
}

///////////////////////////////////


//GPP Pointer
int main()
{
    int x=22;
    void* ptr=&x;

    printf("%d",*ptr); //Compile Error
    printf("%d",  *((int*)ptr)  ); 


    int *tmpPtr=ptr;
    int *tmpPtr=(int*)ptr;
}

//////////////////////////////////////////
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
///based on specific input 
///Stored in Heap  =>c,c++,java,c#

//syntax      HLL===>new
//in c
/////    void* malloc(size in bytes); 

//include<stdlib.h>




//////////////////////////////////////////////

int main()
{
    int size;

    printf("Enter Employee size\n");
    scanf("%d",&size); //10


    //
    int * ptr = /*(int*)*/ malloc(size * sizeof(int));

    ///
    //
    //
    //
    //
    free(ptr);



}






