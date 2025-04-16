#include<iostream>

int main()
{
    int x;
    char name[10];

    cout<<"plz Enter x"<<endl;
    cin>>x;
    cout<<"Value of x is "<<x<<endl;

    cin>>name;

    return 0;
}

//////////////////////////////////////////////////
//namespace : logical grouping for some data types
    ///to acheve identity

#include<iostream>

namespace bookRead
{
    struct Book
    {
        int isbn;
        char name[10];
        char authorName[10];
    };

}
namespace bookTicket
{
    struct Book
    {
        int ticketNo;
        char passName[10];
        char from[10];
        char to[10];
    };
}

using namespace bookRead;
using namespace bookTicket;

int main()
{
    bookRead::Book b1;
    bookTicket::Book b2;
    return 0;
}

//////////////////////////////////////////////////
#include<iostream>  ///  namespace std{  cin cout endl}

int main()
{
    int x;
    char name[10];

    std::cout<<"plz Enter x"<<std::endl;
    std::cin>>x;
    std::cout<<"Value of x is "<<x<<std::endl;

    std::cin>>name;

    return 0;
}

////////////////////////////////////////////
///c++ skeleton

#include<iostream>
using namespace std;
using namespace abc;

int main()
{
    std::cout<<"Hello";
    return 0;
}

/////////////////////////////////////////////////
//dynamic allocation
///c
int main()
{
    int* ptr=(int*)malloc(size in bytes)

    free(ptr);
}

//int c++
int main()
{
    int* ptr=new int[10];
    int* ptr2=new int;

    delete [] ptr;  //remove aray
    //delete ptr;     //remove non array

}
//////////////////////////////////////////////
///c++ Reference
int main()
{
    int x=10;

    int& y=x;
    ///create alias name for x named y

    cout<<&x<<endl; //0x10
    cout<<&y<<endl; //0x10

    y=22;
    cout<<x; //22

    int &z; //Compile Error

}

////////////////////////////////////////////

void SwapValue(int x,int y)
{
    int tmp=x;
    x=y;
    y=tmp;
}

void SwapAddress(int* x,int* y)
{
    int tmp=*x;
    *x=*y;
    *y=tmp;
}

void SwapReference(int& x,int& y)
{
    int tmp=x;
    x=y;
    y=tmp;
}

int main()
{
    int a=3,b=4;
    SwapValue(a,b);
    SwapAddress(&a,&b);
    SwapReference(a,b);
}



/////////////////////////////////////////////////
//struct ====  class in c++
/////////////////////////////////////////////////
//RULES
///ssn , age, salary   -> member inside employee DT
///Member in called by object/instance name

///struct def access modifier => public
///class def access modifier => private

//private:
////member can be accessed inside class/struct ONLY

//public:
////member can be accessed inside/otside class/struct
/////////////////////////////////////////////////
#include<iostream>
using namespace std;

class Employee
{
    private:
    int ssn;
    int age;
    float salary;
    //password
    public: 
    //setters& getters
    ///we can write functin inside class/struct
    void setSsn(int _ssn)
    {
        ///REMEMBER: private foels in LVALUE
        /*caller*/ssn=_ssn;
    }
    int getSsn()
    {
        return ssn;
    }
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
        ///salary bet 5000 and 10000
        if(_salary>=5000 && _salary<=1000)
        {
            salary=_salary;
        }
        else
        {
            salary=5000;
        }
    }
    float getSalary()
    {
        return salary;
    }

    void printEmployee()
    {
        ///caller
        cout<<ssn<<endl;
        cout<<age<<endl;
        cout<<salary<<endl;
    }
};

//V02
int main()
{
    Employee e1,e2; //12  //Stack  e1=> ssn10 age# salary#
    

    e1.setSsn(10);
    e1.setAge(22);
    e1.setSalary(80000);

    e2.setSsn(11);
    e2.setAge(23);
    e2.setSalary(2345);

    cout<<e1.getSsn()<<e1.getSalary()<<e1.getAge();

    e1.printEmployee();
    e2.printEmployee();
}

//V01
int main()
{
    //Employee e1,e2;   
    //e1   object/Instance from Employee  //12B
    
    // ///OOP Violation -> encapsulation
    // e1.ssn=10;
    // e1.salary=1234;
    // e1.age=22;
    // cout<<e1.ssn<<e1.salary<<e1.age;

    ////afer private
    //e1.ssn=10;  //Compile Error -> Inaccessible

    return 0;
}

///////////////////////////////////////////////
class Complex
{
    private:
    int real;
    int img;
    public:
    void setReal(int _real)
    {
        /*caller*/real=_real;
    }
    int getReal() const
    {
        return real;
    }
    void setImg(int _img)
    {
        /*caller*/img=_img;
    }
    int getImg() const
    {
        return img;
    }

    void printComplex()
    {
        cout<< /*caller*/real <<"+" <</*caller*/img <<"i" <<endl;
    }

    //Add Two Complexes
    //Two params :  right , caller

    Complex addComplex(/*Complex left,*/const Complex& right)
    {
        ///WRONG
        right.real=777;  //after const -> Compile Error
        ///
        Complex retVal;
        retVal.real=/*caller*/real+right.real;
        retVal.img=/*caller*/img+right.img;
        return retVal;
    }
    //
};
///Stand alone fn subComplex
Complex subComplex(const Complex& left,const Complex& right)
{
    ///
    //left.setReal(777);
    ///
    Complex retVal;
    retVal.setReal(left.getReal()- right.getReal());
    retVal.setImg(left.getImg()-right.getImg());
    return retVal;
}
///
int main()
{
    Complex c1,c2,c3;  //each object  c1 real3 img4

    c1.setReal(3);
    c1.setImg(4);

    c2.setReal(5);
    c2.setImg(6);

    c1.printComplex();
    c2.printComplex();

    //
    c3=c1.addComplex(c2); //pass VALUES

    c3=subComplex(c1,c2);

    return 0;
}


//////////////////////////////////////////////

///Lab 

///Complex
//{
///real,img
///setters& getters
///print
///Add 
//};
 
 //
 //Sub
 //



///print

//real   img
3   4    3+4i
3  -4    3-4i
3   1    3+i
3   -1   3-i
3    0   3
0    3   3i
0    -3  -3i
0    -1  -i
0    1   i
0   0    0

