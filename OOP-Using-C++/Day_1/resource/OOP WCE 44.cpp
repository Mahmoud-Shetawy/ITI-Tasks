//file.c
#include<stdio.h>
int Add(){}
int Add(int x,int y){}  //compile Error
int main()
{
    
}

///
//file.cpp
#include<???>
int Add(){}
int Add(int x,int y){}  //Runs Successfully
int main()
{
    Add();
    Add(22,33);
}


///////////////////////////////////////////////
#include<iostream>
struct Student
{

}e1;
int main()
{
    typedef struct employee mohamed
    struct Employee e1;
    int id;
    char name[10];

    cout<<"enter id"<<endl;
    cin>>id;
    cout<<"enter name"<<endl;
    cin>>name;

    cout<<"id is"<<id<<"\nname is"<<name<<endl;

    return 0;
}
//////////////////////////////////////////////////
//namespace:
//logical groupring for one or more data types
//to achieve identity


#include<iostream>

namespace BookRead
{
    struct Book
    {
        id
        name
        author
        isbn
    };
}
namespace BookTicket
{
    struct Book
    {
        TicketNo
        PassengerName
        From
        to
    };
}

using namespace BookRead;


int main()
{
    Book b1;  //fully name qualified
    BookRead::Book b2;  //fully name qualified
    BookRead::Book b3;  //fully name qualified
    BookRead::Book b4;  //fully name qualified
    BookRead::Book b5;  //fully name qualified
    BookRead::Book b6;  //fully name qualified
    BookTicket::Book b7;
    return 0;
}


//iostream   namespace std{  cin cout}
#include<iostream>

using namespace std;
int main()
{
    int id;
    char name[10];

    std::cout<<"enter id"<<std::endl;
    cin>>id;
    cout<<"enter name"<<endl;
    cin>>name;

    cout<<"id is"<<id<<"\nname is"<<name<<endl;

    return 0;
}


////////////////////////////////////////
//cpp skeleton
#include<iostream>
using namespace std;

int main()
{
    return 0;
}
//////////////////////////////////////////
//C
///dynamic allocation
///void* malloc(size in bytes){}
#include<stdlib.h>
int main()
{
    int * ptr=malloc(40);
    free(ptr);
}

///////////////////////////
//cpp

int main()
{
    int * ptr=new int[10]; 

    delete[] ptr;  //free array
    //delete ptr;    //free non array
}


//////////////////////////////////////////////
//Reference :alias name for another variable in memory
#include<iostream>
using namespace std;
int main()
{
    int x=10;
    int& y=x;  //alias name for x named y
    int& z=y;

    int& a; //compile Error
    return 0;
}

//////////////////////////////////////////////////
#include<iostream>
using namespace std;
void SwapV(int left,int right)
{
    int tmp=left;
    left=right;
    right=tmp;
}

void SwapA(int* left,int* right)
{
    int tmp=*left;
    *left=*right;
    *right=tmp;
}

void SwapR(int& left,int& right)
{
    int tmp=left;
    left=right;
    right=tmp;
}


int main()
{
    int x=3,y=5;
    cout<<"before Swap"<<endl;
    cout<<"x="<<x<<endl; //3
    cout<<"y="<<y<<endl; //5
    //SwapV(x,y); //pass VALUES  SwapV(3,5)
    //SwapA(&x,&y);
    SwapR(x,y); //PAss Reference
    cout<<"after Swap"<<endl;
    cout<<"x="<<x<<endl;//5
    cout<<"y="<<y<<endl;//3
    return 0;
}

//RULES//////////////////////////////////////////////////
//in c++ class === struct
//except 
//struct default access modifier : public
//class default access modifier : private
//any member is called by object name
//private:member can be accessed inside class/struct scope ONLY
//public:member can be accessed inside and outside class/struct scope ONLY
/////////////////////////////////////////////////////////
#include<iostream>
using namespace std;
struct Employee
{
    private:
    //member of employee
    int id;
    int age;
    float salary; 
    //password  //set only
    public:
    //setter for id
    void SetId(int _id)
    {
        id=_id;
    }
    //getter for id
    int GetId()
    {
        return id;
    }

    void SetAge(int _age)
    {
        age=_age;
    }
    int GetAge()
    {
        return age;
    }

    void SetSalary(float _salary)
    {
        if(_salary>5000&&_salary<10000)
        {salary=_salary;}
        else
        {
            salary=5000;
        }
    }
    float GetSalary()
    {
        return salary;
    }

    //caller e1
    void Print()
    {
        cout<<id<<endl;
        cout<<age<<endl;
        cout<<salary<<endl;
    }
};
//OOP Violation [encapsulation]
int main()
{
    //create instance/object from employee
    Employee e1; //12B
    Employee e2; //12B

    e1.id=1;
    e1.age=22;
    e1.salary=1234;

    cout<<e1.id;
    return 0;
}

//after private
int main()
{
    Employee e1;
    Employee e2;
    e1.id=1; //compile Error //Inaccessible
    cout<<e1.id; //compile Error //Inaccessible

    e1.Ahmed(22); //e1  id|22| age|#| salary|#|
    e2.Ahmed(44);

    cout<<e1.Osama(); //22

    e1.SetSalary(90000);
    cout<<e1.GetSalary(); //5000

}

int main()
{
    Employee e1;
    e1.SetId(1);
    e1.SetAge(22);
    e1.SetSalary(1234);

    cout<<e1.GetId();
    cout<<e1.GetAge();
    cout<<e1.GetSalary();
    e1.Print();
    return 0;
}

////////////////////////////////////////////////////////
#include<iostream>
using namespace std;
class Complex
{
    private:
    int real;
    int img;
    public:
    void SetReal(int _real)
    {
        /*caller*/real=_real;
    }
    int GetReal() const
    {
        return real;
    }
    void SetImg(int _img)
    {
        img=_img;
    }
    int GetImg() const
    {
        return img;
    }
    void Print()
    {
        cout<<real<<"+"<<img<<"i"<<endl;
    }
    //member fn to add 2 complex numbers
    // Complex Add( Complex left ,Complex right)
    // {
    //     Complex result;
    //     result.real=left.real+right.real;
    //     result.img=left.img+right.img;
    //     return result;  //return VALUE Complex
    // }

    //caller c1
    Complex Add(const Complex& right)
    {
        //right.real=-1; //compile error
        Complex result;
        result.real=/*caller*/real+right.real;
        result.img=/*caller*/img+right.img;
        return result;  //return VALUE Complex
    }
    //
};
//stand alone fn to add 2 complex numbers for learning purpose
//const + getReal() -> compiler doesnt gurantee called fn may affect constant object
Complex AddComplex(const Complex& left,const Complex& right)
{
    Complex result;
    //result.real=left.real+right.real;result.img=left.img+right.img; //Compile error Inaccessible
    
    //left.SetReal(-1); //compile Error
    int tmp=left.GetReal()+right.GetReal();
    result.SetReal(tmp);
    result.SetImg(left.GetImg()+right.GetImg());
    return result;  //return VALUE Complex
}

int main()
{
    int tmp;
    Complex c1,c2,c3;
    c1.SetReal(3);
    c1.SetImg(4);

    cout<<c1.GetReal();

    //read data from user at runtime
    cout<<"Enter real\n";
    cin>>tmp;
    c2.SetReal(tmp);
    cout<<"Enter img\n";
    cin>>tmp;
    c2.SetImg(tmp);

    //c3=c1.Add(c1,c2); //Pass VALUES Complex
    c3=c1.Add(c2); //Pass VALUES Complex
    c3.Print();
    c3=AddComplex(c1,c2);
    c3.Print();
    return 0;
}


//////////////////////////////////////////////
//Class Complex
//{
//real
//img
//setters & getters
//print
//Add MEMBER
//};

    //Add Standalone


// real img    print
// 3     4     3+4i
//3     -4     3-4i
//3     1      3+i
//3     -1     3-i
//0     3      3i
//0    -3      -3i
//0    1        i
//0    -1       -i
//0    0        0




