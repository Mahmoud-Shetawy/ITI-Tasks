#include<iostream>

int main()
{
    int x;
    char arr[10];
    cout<<"plz enter x \n";
    cout<<"plz enter x"<<endl;
    cin>>x;
    cout<<"enter name"<<endl;
    cin>>arr;

    cout<<"your x is"<<endl;
    cout<<x;

    cout<<"your x is "<<x<<endl;

    cout<<"your name is"<<endl;
    cout<<arr; //'\0'
    
    return 0;
}


///////c/////////////////////////////////////
#include<stdio.h>
//struct Employee;

int main()
{
    struct Employee emp;
    int x;
    double x;
    return 0;
}
struct Struct
{
    /* data */
};
////namespace :logical grouping for specefic values/////////////////////////////////////
#include<iostream>
using namespace n1;
using namespace n2;
//
int main()
{
    //n1::x;
    x
    
    return 0;
}

namespace n1
{
    int x;
    struct employee {};
}
namespace n2
{
    double y;
}


////////////////////////////////////
#include<iostream>

using namespace std;
int main()
{
    int x;
    //cin ,cout   iostream  namespace std
    std::cout<<"Enter x"<<endl;
    cout<<"Enter x"<<endl;
    std::cin>>x;
    cin>>x;
    return 0;
}


/////default skeleton of cpp/////////////////////////////////
#include<iostream>
using namespace std;
using namespace yehia;  //xx ,yy
int main()
{
    xx=4;
    yehia::cout<<
    return 0;
}

///c dynamic allocation///////////////////////////////////////////
int main()
{
    int arr[10];
    //arr++;  //constant pointer 
            //to first element of array

    int *ptr; //8 byte
    struct employee *eptr; //8 byte

    int size=10;
    ptr= (int *) malloc(size*sizeof(int));
    ptr= malloc(sizeof(int));
    eptr=/**/malloc(sizeof(struct employee));

    //ptr act as array
    //ptr references on first 
    //element of array in heap
    ptr[2]
    
    //ptr++;  //Not Recommended
    //int *xptr;
    //xptr=ptr;
    //xptr++;


    free(ptr);

}

///////c++ Dynamin allocation/////////////////////////////////
#include<iostream>
using namespace std;
int main()
{
    int *ptr;
    ptr=new int; 
    delete ptr;
    //free FIRST Element allocated in heap
    return 0;
}

#include<iostream>
using namespace std;
int main()
{
    int *ptr;
    int size=10;
    ptr=new int[size]; 
   
    delete [] ptr;
    
    return 0;
}


////reference////////////////////////////////////////
int main()
{
    int x=10; //address 0x10

    int& y=x;

    int& z;//Compile error
    int & z=x;

    cout<<x;10
    cout<<y;10
    cout<<&x;0x10
    cout<<&y;0x10

    return 0;
}

///pass by val,address///////////////////////////////////////
//


void swap(int x,int y)
{
    int tmp=x;
    x=y;
    y=tmp;
}

void swapAdd(int * x,int* y)
{
    int tmp=*x;
    *x=*y;
    *y=tmp;
}

//pass by reference
void swapRef(int& x, int& y)
{
    int tmp=x;
    x=y;
    y=tmp;
}

int main()
{
    int a=10,b=20;
    //swap(a,b); //passing values
    //swapAdd(&a,&b); //passing address
    swapRef(a,b); //passing reference
    cout<<a;//20
    cout<<b;//10
    return 0;
}

//////////////////////////////////////////
//struct in c
//has fields  id,name,age,salary
//Doesn't have functions
struct ABC
{
    /* data */
    //void Print(){} //not supported
};

///////////////////////////////////////////
//struct in c++
//has function inside it

//////////////////////////////////////////
//class === struct  in c++
//except one thing:
//.......
//not important
class X
{
    //in class :access modifier by default PRIVATE
    int id;
};

struct Y
{
    //in struct :access modifier by default PUBLIC
    int id;
};

////C++//////////////////////////////////////
//in c++ there is dt named string
struct Student  //employees XXXX
{
    //anything inside class/struct scope
    //is member variable/function
    //member variable can be called by object name
    //Fields / Data
    //Fields small letter
    //access modifier
    //public: member can be accessed inside/outside class/struct
    //private: member can be accessed inside class/struct ONLYYYYY
    private: 
    int id;
    char name[10];
    double salary;
    //password
    //setter  and getter
    //as function
    public:
    //abc member ??? YES
    //any member can be called by?  object name
    void setId(int _id)  //emp
    {
        //if(_id>1 &&_id<10)
        //don't forget left value is private field
        id=_id;  //emp
    }
    void setName(char _name[])
    {
        strcpy(name,_name);
    }
    void setSalary(double _salary)
    {
        salary=_salary;
    }
    int getId()
    {
        return id;
    }
    char* getName()
    {
        return name;
    }
    double getSalary()
    {
        return salary;
    }

    void print()
    {
        cout<<id<<name<<salary<<endl;  //caller object will call
    }

    
};

int main()
{
    /*employee emp;
    Employee *ptr;
    ptr=emp;
    ptr->name*/

    
    /*typedef int integer;
    integer x;
    Employee emp; //??? No
    struct Employee emp; */
    
    
    /*
    //in cpp
    Student emp,emp2,emp3; //22 Byte
    //emp=>object/Instance from class/struct
    //id=10;
    emp.id=10;
    //emp2.name="Alaa"; XXXXX compile error
    strcpy(emp.name,"Alaa"); //#include<string.h>
    emp.salary=1234;
    //Violation of OOP Encapsulation
    cout<<emp.salary;
    */

    Student std,std2,std3;
    //emp.salary;  // Compile error Inaccessible 
    //emp.salary=234;
    //emp.abc();
    //std2.abc();
    //std3.abc();

    std.setId(1);
    std.setName("Alaa");
    std.setSalary(1234);
    std.id=1; //XXXXX

    std.getId();
    1;

    cout<<std.id<<endl; ///??? Compile error
    cout<<std.getId()<<std.getName()<<std.getSalary();
    cout<<std2.getId()<<std.getName()<<std.getSalary();
    cout<<std3.getId()<<std.getName()<<std.getSalary();

    std.print();
    std2.print();
    std3.print();
    //cout<<std.print();  XXXXXX

    return 0;
}


//////////////////////////////////////////////////////////////
//3+4i
//class represent Complex

#include<iostream>
using namespace std;

class Draft
{
    private:
    int x;
};
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
        void setI(int i)
        {
            img=i;
        }
        int getReal()
        {
            return real;
        }
        int getImg()
        {
            return img;
        }
        void printComplex()
        {
            cout<<real<<"+"<<img <<"i"<<endl;
        }
        Complex addComplex(Complex b)  //c1 (1,2)   b(3,4)
        {
            Complex x;   //x(4,6)
            x.real=real+b.real;   //===>real => c1
            x.img=img+b.img;
            return x;
        }
};

Complex subComplex(Complex left,Complex right)
{
    Complex tmp;
    //tmp.real????
    tmp.setReal(left.getReal()-right.getReal());
    tmp.setI(left.getImg()-right.getImg());
    return tmp;
}

int main()
{
    Complex c1,c2,c3;
    //c1.real=1;
    c1.setReal(1);
    c1.setI(2);
    c2.setReal(3);
    c2.setI(4);

    //c3=c1.addComplex(c2);   //Right Rvalue(4,6)
    //Equalize values
    //c3(4,6)
    //c1=c2;  ////Equalize values
    

    c3=subComplex(c1,c2);  //-2  -2

    c1.printComplex();  //1+2i
    c2.printComplex();  //3+4i
    c3.printComplex();  //-2+-2i

    return 0;
}


///printComplex
//r  i
//2  3    2+3i
//2  -3   2-3i
//2  1    2+i
//2  -1   2-i
//3  0    3
//0  3    3i
//0  1    i
//0  -1   -i
//0  0    0
