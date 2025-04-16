//in c
#include<stdio.h>
int main(){}

//in c++
#include<iostream>
#include<string>
int main()

///////////////////////////////////
//read and write
//in c   stdio.h
int x;
int arr[10];
printf("Enter x\n");
scanf("%d",&x);

//in cpp   iostream
int x;
int arr[10];

cout<<"Enter x"<<endl/*\n*/;
cin>>x; //10 Enter

cout<< "x value is" << x <<" ..."<<endl;

/////////////////////////////////////////////////////
//namespace :logical grouping for some datatype
//to achieve Identity

namespace bookRead
{
struct Book
{
    int isbn;
    authorname;
    year;
};
}
namespace bookTicket
{
struct Book
{
    int TicketNo;
    from;
    To;
    passengerName;
};
}
using namespace bookRead;
int main()
{
    Book b1;
    bookTicket::Book b2;
}

/////////////////////////////////////////////
///cin,cout,endl inside iostream.h -> inside namespace
///called std
#include<iostream>

int main()
{
    int x;
    std::cout<<"Plz Enter x"<<std::endl;
    std::cin>>x;
    std::cout<<"Value of x is" <<x <<std::endl;
    return 0;
}
///// c++ Skeleton
#include<iostream>
using namespace std;
int main()
{
    int x;
    cout<<"Plz Enter x"<<endl;
    cin>>x;
    cout<<"Value of x is" <<x <<endl;
    cout<< "Hello, Wrld"<<endl;
    return 0;
}
///////////////////////////////////////////////////
///Dynamic Allocation

//in c  stdlib
int *ptr=(int*)malloc(size in bytes);
free(ptr);


//in cpp
int *ptr=new int[10];  //10*sizeof(int)
delete[] ptr;
///Remember  delete ptr; WRONG  ,used with non array

////////////////////////////////////////
///Reference name
///Alias name for another datatype in memory

#include<iostream>
using namespace std;
int main()
{
    int x=10;

    int& y=x;  //create alias name for x
    //Reference of x called y

    cout<<&x; //0x10
    cout<<&y; //0x10

    y=33;

    cout<<x; //33
    cout<<y; //33

    int& z; //Compile Error


    return 0;
}

/////////////////////////////////////////////
void swap(int a,int b)
{
    int tmp;
    tmp=a;
    a=b;
    b=tmp;
}

int main()
{
    int x=3,y=7;
    swap(x,y); //Pass VALUES  //swap(3,7)
    cout<<x; //3
    cout<<y; //7
}

/////////////////////////////////////////////
///in cPP create variable from struct direct

struct Student
{
    int ssn;
};

int main()
{
    Student s1;
}

////////////////////////////////////////////////////
//OOP
/// in cPP ===>   struct === class
struct Employee
{
    //Data Fields
    //any data written inside class/struct
    //called MEMBER
    //Member is called By Object/Instance name
    ///private:member can be accessed inside 
    ///         class/struct scope ONLY
    ///public: member can be accessed 
    ///         inside and outside class
    private:
    int ssn;
    int age;
    float salary;
    public:
    //function->method
    //setters and getters -> methods
    void setSsn(int _ssn)
    {
        //REMEMBER PRIVATE fields must be on left side
        /*caller*/ssn=_ssn;
    }
    void setAge(int _age)
    {
        age=_age;
    }
    void setSalary(float _salary)
    {
        if(_salary>=1200&&_salary<=8000)
        {salary=_salary;}
        else
        {salary=1200;}
    }
    int getSsn(){return ssn;}
    int getAge(){return age;}
    int getSalary(){return salary;}

    //Print Function
    void print()
    {
        //CALLER e4  ssn  age salary
        cout<<ssn<<endl;
        cout<<age<<endl;
        cout<<salary<<endl;
    }
};

int main()
{

    // Employee e1;  //e1: object/Instance from Employee
    // e1.ssn=1;
    // e1.salary=1234;
    // e1.age=22;

    // cout<<e1.ssn;
    // cout<<e1.age;
    // cout<<e1.salary;
    // ///All Written
    // ///are OOP Violation
    // ///Encapsulation

    ///Employee e2; //object from Employee  12B  e2 ssn# age# salary#
    // e2.ssn=1;  //setter //Compile Error  //Inaccessible
    // cout<<e2.ssn; //getter //Compile Error  //Inaccessible

    ///Setters&getters
    Employee e3,e4;   
    //e3 ssn1 age# salary# |//e4 ssn100 age# salary#
    // e3.ahmed(1);
    // e4.ahmed(100);
    // cout<<e3.osama();
    // cout<<e4.osama();

    e3.setSsn(1);
    e3.setSalary(10000);
    e3.setAge(22);

    e4.setSsn(2);
    e4.setSalary(4000);
    e4.setAge(23);

    cout<<e3.getAge();
    cout<<e3.getSalary();
    cout<<e3.getSsn();

    e3.print();
    e4.print();

}

///Employee
/// ssn   name   age  salary  password  

///Any Datatype
//Consists of
//encapsulated Data fields
//public setters and getters
//public Print Function

///////////////////////////////////////////////////////
#include<iostream>
using namespace std;

class Complex
{
    private:
    int real;
    int img;
    public:
    //Setters&Getters
    void setReal(int _real){/*caller*/real=_real;}
    int getReal(){return real;}
    void setImg(int _img){img=_img;}
    int getImg(){return img;}
    //Print  c3
    void printComplex()
    {
        cout<</*caller*/real<<"+"<</*caller*/img<<"i"<<endl;
    }
    //Add Two Complex
    //Add-> Member Function  
    //caller c1
    //right c2
    Complex addComplex(/*Complex left,*/Complex right)
    {
        Complex retVal;
        retVal.real=/*caller*/real+right.real;
        retVal.img=/*caller*/img+right.img;
        return retVal;
    }
};
///Subtract Two Complex Numbers
///Stand alone Function
///called by its name 
Complex subComplex(Complex& left,Complex& right)
{
    Complex retVal;
    //retval.real=left.real-right.real; //Compile Error
    retVal.setReal(left.getReal()-right.getReal());
    retVal.setImg(left.getImg()-right.getImg());
    return retVal;    
}
///
int main()
{
    int tmp;
    Complex c1,c2,c3;   //8B in Stack
    c1.setReal(3);
    c1.setImg(4);
    //
    cout<<"Enter Real"<<endl;
    cin>>tmp;
    c2.setReal(tmp); //5
    cout<<"Enter Img"<<endl;
    cin>>tmp;
    c2.setImg(tmp); //6

    c1.printComplex(); //3+4i
    c2.printComplex(); //5+6i

    ///
    //c3=c1.addComplex(c1,c2);
    c3=c1.addComplex(c2); //passing values
    c3.printComplex();  //8+10i
    ///

    ///
    c3=subComplex(c1,c2);
    c3.printComplex();  //-2+-2i
    ///

    abc();
    return 0;
}


/////////////////////////////////////////////////
///Lab Assignments

//class Complex
{
//real
//img

//Setters& getters
//print
//AddComplex()

};

//
//subComplex()
//


//real img
3     4    3+4i
-2   -2    -2-2i 
3     1    3+i
3     -1   3-i
3      0   3
0      3   3i
0      -3  -3i
0      -1  -i
0       1    i
0      0     0

