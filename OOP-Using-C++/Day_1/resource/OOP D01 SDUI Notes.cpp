///Draft

#include<iostream>

///cout<<,cin>>,endl  => inside namespace called
///   std
int main()
{
    int x;

    std::cout<<"Plz Enter x\n";
    std::cin>>x;//2

    std::cout<<"The value of x is "<<x<<"\n";
    std::cout<<"The value of x is "<<x<<std::endl;

    return 0;
}


//Standard skeleton of cPP
#include<iostream>

using namespace std;
//using namespace abc;

int main()
{
    cin>>x;
    //std::ali("hello");
    return 0;
}

//Dynamic Allocation in c
int* ptr=malloc(40);

//in c++
int main()
{
    int* arr=new int[10];  //int* arr=malloc(40);
    char* cptr=new char[10];

    delete [] arr;
    delete cptr;
}

///In cPP  => Reference
int x=10;

///End Of Draft


//in c
#include<stdio.h>  
int main()
{
    return 0;
}

///////////////////////////////
//in c++   -> built in headers
#include<conio>
#include<string>
int main()
{
    return0;
}
////////////////////////////////
//read / write in c
int main()
{
    int x=2;
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    char ch='M';
    char carr[10]="mohamed";
    printf("%d",x);
    printf("%i",arr[0]);
    printf("%s",carr);

    scanf("%d",&x);
    scanf("%d",arr);
    scanf("%d",&arr);
    scanf("%d",&arr[0]);

}

//////////////////
//read / write in c++
#include<iostream>  //cout<<  write     //cin>>  read
int main()
{
    //string str="Ali";  //in cpp  no
    int x=10;

    cout<<"plz enter x\n"<<endl;
    cin>>x; ///>>endl   remember WRONG

    cout<<"the value of x is"<<x<<endl;
    cout<<&x;  //print address of x  int vs. hexa [T]  ???

    char carr[11];
    cin>>carr;

    return 0;
}


////////////////////////////////////////////////////////
//namespace

#include<iostream>

namespace Asmaa{
    struct Book{};  //book reading
}

namespace Ali{
    struct Book{};  //reserve Ticket
}


int main()
{
    Ali::Book
    return 0;
}

///////////////////////////////////////////
//in c++
//All Built in libraries is built over namespaces
///iostream.h
///
/////namspace std
//{
////////cin>>

////////cout<<

//}
#include<iostream>
namespace abc
{

}
int main()
{
    int x=10;
    std::cout<<"Enter x"<<std::endl;
    std::cin>>x;
    std::cout<<"Value of x is "<< x<<std::endl;
    return 0; 
}

///
#include<iostream>
using namespace std;
using namespace Asmaa;
int main()
{
    int x=10;
    cout<<"Enter x"<<endl;
    cin>>x;
    cout<<"Value of x is "<< x<<endl;
    return 0; 
}

//////////////////////////////////
///Object declaration in c

struct Employee
{
    /* data */
};

int main()
{
    struct Employee e1;
}


//////////////////////////////
///Object declaration in c++
struct Employee
{
    /* data */
};

int main()
{
    Employee e1;
}

///////////////////////////////////
//dynamic allocation in c

int main()
{
    int *ptr;
    ptr=(int*)  malloc(40);
    ptr= malloc(40);

    free(ptr);

}

///////////////////////////////////
//dynamic allocation in c++
int main()
{
    int *ptr;
    int size=10;
    ptr=new int[size];
    
    for(int i=0;i<10;i++)
    {
        ptr[i]=10+i;
    }
    
    //free 
    delete [] ptr;   //arrays


    ptr=new int;
    delete ptr;   //non arrays

}

//////////////////////////////////////////////////
///in cpp  keyword called reference
#include<iostream>
using namespace std;
int main()
{
    int x=10;

    int& y=x;
    //place of x in memory had another name called y
    //alias name for x named y 

    cout<<x<<endl;  //10
    cout<<&x<<endl; //0x10

    cout<<y<<endl;  //10
    cout<<&y<<endl; //0x10


    //int& z;   //Compile Error

    int& z=x;


    return 0;
}


//////////////////////////////////////////
//pass by value
void SwapValue(int x,int y)
{
    int tmp=x;
    x=y;
    y=tmp;
}
int main()
{
    int a=10,b=20;
    SwapValue(a,b);  //pass values
    //print a  10
    //print b  20
}

//pass by Address
void SwapAddress(int* x,int* y)
{
    int tmp=*x;
    *x=*y;
    *y=tmp;
}
int main()
{
    int a=10,b=20;
    SwapAddress(&a,&b);  //pass values
    //print a  20
    //print b  10
}


//pass by Reference
void SwapReference(int& x,int& y)
{
    int tmp=x;
    x=y;
    y=tmp;
}
int main()
{
    int a=10,b=20;
    SwapReference(a,b);  //pass values
    //print a  20
    //print b  10
}

///////////////////////////////////////
///in c++ there is no major
//difference bet. struct and class


///any thing written inside class/struct is a member variable/function
///any member in class/struct is called by object/instance name
//public :member can be accessed
// inside/outside class/struct
struct Employee 
{
    //fields/Data fields
    public:
    int id;
    int age;
    float salary;

    //in struct/class in c++ , 
    //it can also contain functions
    //caller is e1
    void Print()
    {
        //related to caller
        cout<<id<<endl;
        cout<<age<<endl;
        cout<<salary<<endl;
    }
    
};

//sdUI43
int main()
{
    Employee e1;  //instace/object of Employee
    //e1.id=10;//Comile Error  //private
    e1.id=1;
    e1.age=22;
    e1.salary=1234;

    cout<<e1.id;
    cout<<e1.age;
    cout<<e1.salary;
    e1.Print();  //caller

    Employee e2;
    e2.Print();
}


//old
int main()
{
    Employee e1,e2;    //12B
    //id=10; ///XXX
    e1.id=10;
    e1.age=22;
    e1.salary=1234;

    e2.id=20;

    cout<<e1.id<<endl;
    cout<<e1.age<<endl;
    cout<<e1.salary<<endl;

    e1.Print();  //caller is e1
    e1.id=33;
    e1.Print();  //caller is e2
    
    return 0;
}

//////////////////////////////////////////////////
///OOP
///any thing written inside class/struct is a member
///any member in class is called by object/instance name
//public :member can be accessed inside/outside class/struct
//private:member can be accessed inside class/struct ONLY
struct Student 
{
    //fields/Data fields
    private:
    int id;
    int age;
    float salary;

    //in struct/class in c++ , it can also contain functions
    //caller is e2
    public:
    void setAge(int _age)
    {
        age=_age;
    }
    int getAge()
    {
        return age;
    }


    void setSalary(float _salary)
    {
        if(_salary>=1200 && _salary<=6000)
            salary=_salary;
        else
            salary=1200;
    }
    float getSalary()
    {
        return salary;
    }
    //setters and getters
    void setId(int x)
    {
        //related to caller
            id=x;
    }
    int getId()
    {
        //related to caller
        return id;
    }
    void Print()
    {
        //related to caller
        cout<<id<<endl;
        cout<<age<<endl;
        cout<<salary<<endl;
    }
    
};

int main()
{
    Student s1;   //12B
    
    //s1.id=10;//Compile Error //Inaccessible
    //s1.age=22;//Compile Error //Inaccessible

    //s1.setMyId(22);
    //cout<<s1.getMyId();  ///22
    //s1.Print(); //Right  rubbish

    s1.setId(10);
    s1.setSalary(1260);
    s1.setAge(22);

    cout<<s1.getId;
    cout<<s1.getAge;
    cout<<s1.getSalary;

    s1.Print();

}


///////////////////////////////////////////////////
class AnyNum
{
    int x,y;
}
//Complex Numbers  real +imaginary #    3+4i
///int real
///int img

class Complex
{
    private:
    int real;
    int img;
    public:
    //setters and getters
    void setReal(int _real)
    {
        real=_real;
    }
    int getReal()
    {
        return real;
    }
    void setImg(int _img)
    {
        img=_img;
    }
    int getImg()
    {
        return img;
    }
    //print    in main c1.Print()
    void Print()
    {
        if(img<0)
            cout<<real<<img<<"i"<<endl;
        else
            cout<<real<<"+"<<img<<"i"<<endl;
    }
    //Add complex over complex [as member function]
    //c1.Add(c2)
    Complex Add(Complex right)
    {
        //caller c1 real1 ,img2---   right real3, img4 
        Complex retVal;
        retVal.real=real+right.real;
        retVal.img=img+right.img;
        return retVal;  //real4 img6
    }
};

///standalone function Sub two Complex
Complex Sub(Complex left,Complex right)
{
    Complex retVal;
    retVal.setReal(left.getReal()-right.getReal()); 
    retVal.setImg(left.getImg()-right.getImg());
    return retVal;
}
///

int main()
{
    Complex c1,c2,c3;
    //AnyNum a1;
    c1.setReal(1);
    c1.setImg(2);
    c2.setReal(3);
    c2.setImg(4);
    
    //assign values
    //Casting
    //c1=a1;
    //
    //c1=c2;


    cout<<c1.getReal()<<"+"<<c1.getImg()<<"i"<<endl;
    //cout<<c1.real<<c1.img<<endl; //Compile Error private
    
    
    
    c2.Print();
        


    //c3 real#  img#
    //Remember member function
    c3=c1.Add(c2); //complex  reAL 4    img 6
    //assignment values
    //c3 real4  img6
    c3.Print();   //4+6i


    //1,2    3,4
    c3=Sub(c1,c2);
    c3.Print();   //-2+-2i

    return 0;
}


///Lab Assignment

//class Complex
//real
//img
//setters & getters
//Print member
//Add member

//Sub standalone


//Print

// r   i
// 3   4    3+4i
// 3  -4    3-4i
// 3   1    3+i
// 1   1    1+i
//-1   -1   -1-i
//1    0    1
//0    1    i
//0   -1    -i
//0    0     0  







