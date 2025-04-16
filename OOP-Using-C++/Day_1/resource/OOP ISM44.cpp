#include<iostream>   //cout<<    ,,   cin>>

int main()
{
    int x;
    double y;
    char name[12];
    cout<<"plz Enter x"<<endl;
    cin>>x;
    cout<<"Enter y\n";
    cin>>y;
    cout<<"Enter Name";
    cin>>name;
    gets(name);

    cout<<"x="<<x<<". and y="<<y<<endl;
    cout<<name;
    puts(name);
    return 0;
}
/////////////////////////////////////////
//namespace :logical grouping
//for related datatypes under specific name
//to acieve identity
namespace BookRead
{
    struct Book
    {
        isbn;
        bookName;
        Year;
        Author
    };
}
namespace BookTicket
{
    struct Book
    {
        TicketNo;
        PassengerName;
        From;
        To;
    };
}

using namespace BookRead;
int main()
{
    //Book b1; //compile Error
    BookRead::Book b1;
    BookTicket::Book bt;

    Book b1;
    return 0;
}

///////////////////////////////////////////////
///iostream 
  //namespace std{  cin ,cout}
#include<iostream>   //cout<<    ,,   cin>>

using namespace std;
int main()
{
    int x;
    double y;
    char name[12];
    cout<<"plz Enter x"<<std::endl;
    std::cin>>x;
    std::cout<<"Enter y\n";
    cin>>y;
    cout<<"Enter Name";
    cin>>name;
    gets(name);

    cout<<"x="<<x<<". and y="<<y<<endl;
    cout<<name;
    puts(name);
    return 0;
}

//////////////////////////////////
//cpp skeleton
#include<iostream>

using namespace std;

int main()
{
    return 0;
}

//////////////////////////////////////
//dynamic allocation
//c
//stdlib.h
int main()
{
    int * ptr= malloc(40);

}

///////////////////////////////////////
//dynamic allocation
//cPP

int main()
{
    int * ptr=new int[5];   //int ptr[5]

    char * cptr=new char[5];

    double *dPtr=new double[10];

    delete[] ptr;
    delete[] cptr;
    delete[] dPtr;

    delete ptr; 

    //delete[] ptr ; when pointer points array
    //delete ptr ; when pointer points non array
}

///////////////////////////////////////////////
//exclusive with cPP
//reference
//alias name for another variable in memory
int main()
{
    int x=10;

    int& y=x;  //reference of x called y

    int& z=y;
    //
    int& z=x;


    int& a;  //Compile Error
    
    return 0;
}


///////////////////////////////////////////

void SwapR(int& left,int& right)
{
    int tmp=left;
    left=right;
    right=tmp;
}


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

int main()
{
    int x=3,y=5;

    SwapR(x, y);
    SwapA(&x,&y);
    SwapV(x,y);


}


//////////////////////////////////////////////////
//in c
struct ANY
{
    //fields ONLY
    int id;
    //void Print(){} //Not Supported
};



///////////////////////////////////////////////////
///class  
///struct
//there is NO Differece bet. class & struct in c++
//except//
//struct default access modifier : public
//class default access modifier : private
class X
{
    int id;
};
struct Y
{
    int id;
};
//////////////////////////////////////////////////
//in cPP
class Employee
{
    //any fields/method[Data] written inside class/struct called member
    //any member is called by Object/instance name
    //private: member can be accessed inside class scope ONLY
    //public: member can be accessed inside and outside class scope
    private:
    int id;
    int age;
    float salary;
    //password   setter only
    public:
    //setters and getters
    //who called SetId() ? CALLER
    void SetId(int _id)
    {
        //private friels in LValue
        /*caller*/id=_id;
    }
    int GetId()
    {
        return /*caller*/id;
    }

    void SetAge(int _age)
    {
        /*caller*/age=_age;
    }
    int GetAge()
    {
        return /*caller*/age;
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
    //
    //print
    void Print()
    {
        cout<</*caller*/id <<age<<salary<<endl;
    }

    //

};

int main()
{
    Employee e1,e2,e3;  //create object/instance from Employee
    
    //OOP Violation  [encapsulation]
    e1.id=10;
    strcpy(e1.name,"Ali");
    e1.age=22;
    e2.id=20;

    //after public:
    e1.id=10; //runs successful  OOP Violation
    
    
    //after private
    //e1.id=10; //Compile Error  //Inaccessible
    // //Compile Error  //Inaccessible
    // e1.id=10;
    // e1.name,"Abdelaziz"
    // e1.age=22

    //Employee e1;   Stack  e1  id|1| name|#| age|#|

}

int main()
{
    Employee e1,e2,e3;  //e1 i|10| n|#| a|#|

    e1.set


    e2.AbdelAziz(20);
}

int main()
{
    Employee e1,e2,e3;   

    e1.SetId(1);  //e1  i|1| a|22|  s||
    e1.SetAge(22);
    e1.SetSalary(100000); //e1  i|1| a|22|  s|1234|

    cout<<e1.GetId();
    cout<<e1.GetAge();
    cout<<e1.GetSalary(); //5000

    e1.Print();

    return 0;
}



////////////////////////////////////////////////

#include<iostream>
using namespace std;

class Complex
{
    private:
    int real;
    int img;
    public:
    //setters& getters
    void SetReal(int _real){real=_real;}
    void SetImg(int _img){img=_img;}
    int GetReal()const {return real;}
    int GetImg() const {return img;}

    //print
    void Print()
    {
        cout<<real <<"+" <<img <<"i"<<endl;
    }
    //


    //Add as a member fn
    // Complex Add(Complex left,Complex right)
    //who called Add -> caller
    Complex Add(const Complex& right)
    { 
        Complex obj;
        obj.real=/*caller*/real+right.real;
        obj.img=/*caller*/img+right.img;
        //right.img=-11111; //COMPILE ERROR
        return obj;
    }
    //
};
//AddComplex as standalone fn
Complex AddComplex(const Complex& left,const Complex& right)
{
    Complex obj;
    //obj.real=left.real+right.real; //Compile Error //inaccessible
    obj.SetReal(left.GetReal()+right.GetReal());
    obj.SetImg(left.GetImg()+right.GetImg());
    //left.SetImg(-1111111); //compile Error
    return obj;
}
//left.GetReal():
//compiler doesnt gurantee called funcion would change
//value of fn constant value
//
int main()
{
    Complex c1,c2,c3;
    int tmp;
    cout<<"Enter real for c1"<<endl;
    //cin>>c1.real; //COMPILE ERROR  //PRIVATE //INACCESSIBLE
    cin>>tmp;
    c1.SetReal(tmp);
    cout<<"Enter img for c1"<<endl;
    cin>>tmp;
    c1.SetImg(tmp);


    c2.SetReal(5);
    c2.SetImg(6);

    
    //c3=c1.Add(c1,c2);  //pass VALUES
    c3=c1.Add(c2);  //pass VALUES/Reference

    c3.Print(); //8+10i


    c3=AddComplex(c1,c2); //pass VALUES/REFERENCE
    c3.Print();
    return 0;
}