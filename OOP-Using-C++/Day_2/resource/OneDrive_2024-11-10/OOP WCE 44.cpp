///*this
///Function Overloading
///Default Arguments
///Constructor
///Destructor
///////////////////////////////////////////////////////
//in c++ struct === class
//except default access modifier
//class => private
//struct=> public
//2-template -> class ONLY
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
//in any member function
//there is fst hidden input parameter
//called classname* this
////////////////////////////////////////////////////////
class Trial
{
    private:
    int x;
    int y;
    public:
    //caller obj1
    void SetX(/*Trial *this,*/int _x)
    {
        (*this).x=_x;
        this->x=_x;
        x=_x;
    }
    int GetX(/*Trial *this,*/)
    {
        return x;
        return this->x;
        return (*this).x;
    }
    void SetY(/*Trial *this,*/int _y)
    {
        y=_y;
    }
    int GetY(/*Trial *this,*/)
    {
        return y;
    }
    void Print(/*Trial *this,*/)
    {
        cout<<x<<y<<endl;
    }
};

int main()
{
    Trial obj1; //object from trial 8B  //stack
    Trial obj2; //object from trial 8B  //stack
    obj1.SetX(3);  //Trial::SetX(&obj1,3);
    obj2.SetX(4);
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
    void SetReal(/*Complex *this*/int _real)
    {
        real=_real;
        this->real=_real;
        (*this).real=_real;
    }
    int GetReal() const
    {
        return this->real;;
    }
    void SetImg(int _img)
    {
        img=_img;
    }
    int GetImg() const
    {
        return (*this).img;
    }
    void Print()
    {
        cout<<real<<"+"<<this->img<<"i"<<endl;
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
    Complex Add(/*Complex *this*/const Complex& right)
    {
        //right.real=-1; //compile error
        Complex result;
        result.real=this->real+right.real;
        result.img=img+right.img;
        return result;  //return VALUE Complex
    }
    //
};
//standalone fn dosen't have *this
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
    Complex c1,c2,c3;
    c1.SetReal(3);  //Complex::SetReal(&c1,3)
    c3=c1.Add(c2);  //Complex::Add(&c1,c2)
    return 0;
}

//////////////////////////////////////////////////////
//Overloading
//Function overloading
//FunctionS -in the same scope- have same //name but
//IGNORE RETURN TYPE 
//different input parameters number
//Or Different data type


//deafult Argument :must be from right to left in params
//if there is  def argument in middle,
//must ALL of right of it be default also


#include<iostream>
using namespace std;
class MyMath
{
    public:
    int Add(int x)
    {
        return x+y;
    }
    int Add(int x,int y)
    {
        return x+y;
    }
    int Add(int x,int y,int z)
    {
        return x+y+z;
    }
};
int main()
{
    MyMath obj;
    cout<<obj.Add(3,4);
    return 0;
}

////////////////////////////////////////////////////
#include<iostream>
using namespace std;
int Add(int x)
{
    return x+y;
}
int Add(int x,int y)
{
    return x+y;
}
int Add(int x,int y,int z)
{
    return x+y+z;
}
int main()
{
    cout<<Add(3,4);
    cout<<Add(3,4,5);
}

//////////////////////////////////////////////////////
//default argument/s
//V01
#include<iostream>
using namespace std;

int Add(int x=0,int y=0,int z=0)
{
    return x+y+z;
}
int main()
{
    cout<<Add(1,2,3); //6
    cout<<Add(1,2);   //3
    cout<<Add(1);     //1
    cout<<Add();      //0
    return 0;
}

////////////////////
//V02
#include<iostream>
using namespace std;

int Add(int x,int y=0,int z=0)
{
    return x+y+z;
}
int main()
{
    cout<<Add(1,2,3); //6
    cout<<Add(1,2);   //3
    cout<<Add(1);     //1
    cout<<Add();      //Compile error
    return 0;
}

////////////////////
//V03
#include<iostream>
using namespace std;

int Add(int x,int y,int z=0)
{
    return x+y+z;
}
int main()
{
    cout<<Add(1,2,3); //6
    cout<<Add(1,2);   //3
    cout<<Add(1);     //Compile Error
    cout<<Add();      //Compile error
    return 0;
}
////////////////////
//V04 WRONG
#include<iostream>
using namespace std;

int Add(int x,int y=0,int z)
{
    return x+y+z;
}
int main()
{
    cout<<Add(,2,3); //NOT SUPPORTED
    return 0;
}
////////////////////////////////////////////////
//V05
//default argument connot go with overloading
#include<iostream>
using namespace std;

int Add(int x=0,int y=0,int z=0)
{
    return x+y+z;
}
int Add(int x,int y)
{
    return x+y;
}
int main()
{
    int x=3;
    int y=4;
    int z=x+y;
    cout<<Add(3,4,5);

    //
    cout<<Add(3,4); //Compile Error //Ambiguty
    return 0;
}

///////////////////////////////////////////////////
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
    int GetReal() const
    {
        return this->real;;
    }
    void SetImg(int _img)
    {
        img=_img;
    }
    int GetImg() const
    {
        return (*this).img;
    }
    void Print()
    {
        cout<<real<<"+"<<this->img<<"i"<<endl;
    }
    //caller c1
    Complex Add(/*Complex *this*/const Complex& right)
    {
        Complex result;
        result.real=this->real+right.real;
        result.img=img+right.img;
        return result;  
    }
    //

    //initialize object
    void Initialize()
    {
        real=img=0;
    }
    void Initialize(int _real,int _img)
    {
        real=_real;img=_img;
    }
    void Initialize(int _num)
    {
        real=img=_num;
    }
    //

    //ctor
    //default ctor  o.s will generate it
    Complex()
    {
        this->real=img=0;
        //for tracing purpose
        cout<<"def ctor called"<<endl;
    }
    Complex(int _real,int _img)
    {
        this->real=_real;img=_img;
        //for tracing purpose
        cout<<"2p ctor called"<<endl;
    }
    Complex(int _num)
    {
        this->real=img=_num;
        //for tracing purpose
        cout<<"1p ctor called"<<endl;
    }
    //
    //destructor
    ~Complex()
    {
        //for learninig purpose
        cout<<"dest called";
    }
    //
};
Complex AddComplex(const Complex& left,const Complex& right)
{
    Complex result;
    int tmp=left.GetReal()+right.GetReal();
    result.SetReal(tmp);
    result.SetImg(left.GetImg()+right.GetImg());
    return result;  
}

//initialize any created object
//v01
int main()
{
    Complex c1,c2,c3; 
    c1.SetReal(0);
    c1.SetImg(0);
    c2.SetReal(0);
    c2.SetImg(0);
    c3.SetReal(0);
    c3.SetImg(0);
}

//v02
int main()
{
    Complex c1,c2,c3;
    c1.Initialize();
    c2.Initialize(3,4);
    c3.Initialize(5);
}


void TryMe()
{
    Complex tmp;
}
//v03
int main()
{
    // //
    // Complex * cptr=new Complex[3];
    // //
    Complex c1,c2,c3;  //All real 0 img 0
    //o/p
    //def ctor called
    //def ctor called
    //def ctor called

    Complex c4(3,4);
    //o/p
    //2p ctor called

    TryMe();

    Complex c5(5);
    //o/p
    //1p ctor called
    
    //dest called
    //dest called
    //dest called
    //dest called
    //dest called
    return 0;
}

/////////////////////////////////////////////

// class Student
// {
//     private:
//     int ssn=234567898765;
//     string name="Ahmed";
//     int age=22;

// };


////////////////////////////////////////////////////
//Constructor
// special method inside class/struct 
// implicitly exist  -hidden- -generated by o.s-
// will be called automatically -we cannot call it-
// Once we create object from that class/struct

//How to write ctor Explicitly?
///1- has same name of class
///2- has no return type even void
///3- can be overloaded 
///4- must be public


class Trial
{
    public:
    Trial(){}
    Trial(int _x){}
    ~Trial()
    {

    }

};

int main()
{
    Trial o1;
}
/////////////////////////////////////////////////

//Destructor:
//Special function inside class/struct will be 
//called automatically
//cannot be called
//implicitly exist -hidden-
//once O.S will object destructed from memory [stack]
//once object reach end of its scope

///how to write destructor Explicitly?
///1- has same name of class starts with ~
///2- has no return type even void
///3- cannot be overloaded -already only one parameterless copy exists-
///4- MUST be public

//What is real purpose for destructor
//1-dynamic alocation
//2-connect to DB
//3-read/write from file


class Draft
{
    private:
    int *ptr;
    public:
    Draft()
    {
        ptr=new int[5];
    }
    ~Draft()
    {
        delete[] ptr;
    }
    void Dispose()
    {
        delete[] ptr;
    }
};

void TryMe()
{
    Draft d1;

    //d1.Dispose();
}

int main()
{
    TryMe();
    TryMe();
    TryMe();
}

////////////////////////////////////////
////////////////////////////////////////
///Complex
///real 
///img
///setters & getters
///ctors
//dest
//print
//add member

//Add stanalone

///Codeblocks
///settings -> compiler
///tab [other compiler options]
///-fno-elide-constructors   ///RVO


//3 objects from complex
//then
//c3=Add(c1,c2);
//c3.Print();