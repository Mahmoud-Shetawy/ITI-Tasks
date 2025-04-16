#include<iostream>  //namespace std{ //cout<<   ,cin>>}

using namespace std;
int main()
{
    int x;
    char arr[11];

    std::cout<<"Plz Enter x"<<std::endl;
    std::cin>>x;
    cout<<"value of x="<<x<<endl;

    cout<<"Enter name"<<endl;
    cin>>arr;

    cout<<"Ur name is"<<arr<<endl;
    return 0;
}
///////////////////////////////////////////////
//namespace with cPP :group of Data Type that related to 
///to each others grouping together
///to achieve identity 

namespace BookRead
{
    struct Book
    {
        isbn;
        authorNAme;
        year;
        publisher;
    };
}
namespace BookTicket
{
    struct Book
    {
        ticketNo;
        passengerName;
        from;
        to;
    };
}

using namespace BookRead;
//using namespace BookTicket;
int main()
{
    Book b1; //Compile Error
    //BookRead::Book br1;
    Book br1;
    BookTicket::Book bt1;
}

/////CPP Skeleton/////////////////////////////////////////
#include<iostream>
using namespace std;
int main()
{

    return 0;
}

///////////////////////////////////////////////
///dynamic allocation  new
#include<iostream>
using namespace std;
int main()
{
    //allocate 10 integers
    // int*ptr=malloc(40);
    int *ptr= new int[10];
    ptr[0]=10;ptr[1]=20;//.....
    
    delete [] ptr;

    delete [] ptr; //remove protection over array
    delete ptr; //remove protection over non array

    return 0;
}
///////////////////////////////////////////////////
//exclusive with cPP

///Reference:alias name for another variable in 
///memory

int main()
{
    int x=10;

    int& y=x;
    //reference 

    return 0;
}

/////////////////////////////////////////

void swapV(int left,int right)
{
    int tmp;
    tmp=left;
    left=right;
    right=tmp;
}
void swapA(int* left,int* right)
{
    int tmp;
    tmp=*left;
    *left=*right;
    *right=tmp;
}
void swapR(int& left,int& right)
{
    int tmp;
    tmp=left;
    left=right;
    right=tmp;
}
int main()
{
    int x=3,y=5;
    swapV(x,y);   //pass VALUES
    swapA(&x,&y); //pass Addresses
    swapR(x,y);   //PaSS REFERENCE
}

//////////////////////////////////////////////////
//struct========class 
///-> default access modifiers struct[public] class[private]
//any members inside class/struct is called by instance/object name
//private: member can be accessed inside class/struct scope ONLY
//public: member can be accessed inside and outside class/struct
//////////////////////////////////////////////////////
#include<iostream>
using namespace std;
struct Employee
{
    //members
    private:
    int id;
    int age;
    float salary;
    //password setter only
    public:
    //caller e2
    void SetId(int _id)
    {
        /*caller e2*/id=_id;
    }
    //caller e2
    int GetId()
    {
        return /*caller e2*/id;
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
        if(_salary>=5000 && _salary<=10000)
        {
            salary=_salary;
        }
        else
        {
            salary=5000;
        }
    }
    float GetSalary()
    {
        return salary;
    }

    //function to print object
    //caller e2
    void Print()
    {
        cout<</*caller*/id<<endl;
        cout<</*caller*/age<<endl;
        cout<</*caller*/salary<<endl;

        //cout<<id<<"\n"<<age<<endl<<salary<<endl;
    }
};
int main()
{
    Employee e1; //object/instance of employee //12B
    Employee e2; //object/instance of employee //12B
    ///VIOLATION For OOP [ENCAPSULATION]
    e1.id=1;
    e1.age=22;
    e1.salary=1234;

    cout<<e1.id<<endl;
    cout<<e1.age<<endl;
    cout<<e1.salary<<endl;
    //after private -> Compile Error inaccessible
    return 0;
}

int main()
{
    Employee e1; //Object from Employee Stack
    Employee e2; //Object from Employee Stack
    ///e1 id|1| age|| salary||
    ///e2 id|2| age|| salary||
    e1.SetId(1);
    e2.SetId(2);

    cout<<e1.GetId()<<endl;  //1
    cout<<e2.GetId()<<endl;  //2

    e1.SetId(1);
    e1.SetAge(22);
    e1.SetSalary(1234);

    e2.SetId(1);
    e2.SetAge(22);
    e2.SetSalary(1234);

    cout<<e1.GetSalary()<<endl;
    cout<<e1.GetId()<<endl;
    cout<<e1.GetAge()<<endl;

    e1.Print();
    e2.Print();
    
    return 0;
}
////////////////////////////////////////////////////
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
        real=_real;
    }
    int GetReal()
    {
        return real;
    }
    void SetImg(int _img)
    {
        img=_img;
    }
    int GetImg()
    {
        return img;
    }
    void Print()
    {
        cout<<real <<"+" <<img <<"i"<<endl;
    }
 
    //
};
///standalone fn add 2 complex Numbers

Complex AddComplex(Complex& left , Complex& right)
{
    Complex result;
    //result.real=left.real+right.real; //Compile Error
    int r = left.GetReal() + right.GetReal();
    int i = left.GetImg() + right.GetImg();
    result.SetReal(r);
    result.SetImg(i);

    return result;
}
///
int main()
{
    Complex c1,c2,c3;
    
    c1.SetReal(3);
    c1.SetImg(4);

    c2.SetReal(5);
    c2.SetImg(6);


    c3=AddComplex(c1,c2); //PASS VALUESSSSS OR REFERENCES
    c3.Print();
    return 0;
};

///////////////////////////////////////////////
//Lab Assignment
//class Complex
///real img
//setters getters
//print
//member Add


///standalone Add


///in Print Fn
//real  img   print
3        4    3+4i
3       -4    3-4i
3       1     3+i
3       -1    3-i
0       1     i
0       -1    -i
0       -3    -3i
0       0      0
10      0     10




