///*this
///const
///Function Overloading
///Default Arguments
///Constructor
///Destructor
///////////////////////////////////////////////////////
//in c++ struct === class
//except default access modifier
//class => private
//struct=> public
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//in any member function[method]
//there is hidden input parameter [You cannot declare it explicitly]
//called classname *this
//////////////////////////////////////////////////////
#include<iostream>
using namespace std;
class Draft
{
    private:
    int x;
    int y;
    public:
    //caller->obj
    void SetX(/*Draft *this,*/int _x)
    {
        (*this).x=_x;
        this->x=_x;
        x=_x;
    }
    int GetX(/*Draft *this*/)
    {
        return (*this).x;
        return this->x;
        return x;
    }
    void SetY(/*Draft *this,*/int _y)
    {
        y=_y;
    }
    int GetY(/*Draft *this*/)
    {
        return y;
    }
    void Print(/*Draft *this*/)
    {
        cout<<x<<","<<this->y<<endl;
    }
};

int main()
{
    Draft obj;  //8B stack  obj x|| y||
    obj.SetX(10);   ///Draft::SetX(&obj,10);
    obj.SetY(20);   ///Draft::SetY(&obj,20)
    cout<<obj.GetX();   //Getx(&obj)
    return 0;
}

//////////////////////////////////////////////////////
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
        this->real=_real;
        (*this).real=_real;
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
    //member fn to add 2 complex numbers
    // Complex Add(Complex left,Complex right)
    // {
    //     Complex result;
    //     result.real=left.real+right.real;
    //     result.img=left.img+right.img;
    //     return result;
    // }
    //caller c1
    Complex Add(Complex right)
    {
        //real;img; ====> caller c1
        Complex result;
        result.real=/*caller*/real+right.real;
        result.img=/*caller*/img+right.img;
        return result;
    }
    //
};
///standalone fn add 2 complex Numbers
Complex AddComplex(Complex left,Complex right)
{
    Complex result;
    //result.real=left.real+right.real; //Compile Error
    int r=left.GetReal()+right.GetReal();
    int i=left.GetImg()+right.GetImg();
    result.SetReal(r);
    result.SetImg(i);
    return result;
}

int main()
{
    Complex c1;
    Complex c2;
    Complex c3;

    c1.SetReal(3); // Complex::SetReal(&c1,3);
    c1.SetImg(4);
    c2.SetReal(5);
    c2.SetImg(4);
    c3=AddComplex(c1,c2); //pass VALUES
    return 0;
}

///////////////////////////////////////////////\
///overloading
//Function overloading
//Function/S -in the same scope- have same //name but
//IGNORE RETURN TYPE 
//different input parameters number
//Or Different data type

////Add(int,int)
////Add(int)
////Add(char)
////Add(char,double)

//defult Argument :must be from right to left in params
//if there is  def argument in middle,
//must ALL of right of it be default also
///////////////////////////////////////////////////////
class Math
{
    public:
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
    Math obj;
    cout<<obj.Add(11,22); //33
    cout<<obj.Add(11,22,11); //44
}

//////////////////////////////////////////////////////
///default Arguments
//v1
class Math
{
    public:
    int Add(int x=0,int y=0,int z=0)
    {
        return x+y+z;
    }
}

int main()
{
    Math obj;
    cout<<obj.Add(1,2,3); //6
    cout<<obj.Add(1,2); //3
    cout<<obj.Add(1); //1
    cout<<obj.Add(); //0
}

//v2
class Math
{
    public:
    int Add(int x,int y=0,int z=0)
    {
        return x+y+z;
    }
}

int main()
{
    Math obj;
    cout<<obj.Add(1,2,3); //6
    cout<<obj.Add(1,2); //3
    cout<<obj.Add(1); //1
    cout<<obj.Add(); //Compile Error
}

//v3
class Math
{
    public:
    int Add(int x,int y,int z=0)
    {
        return x+y+z;
    }
}

int main()
{
    Math obj;
    cout<<obj.Add(1,2,3); //6
    cout<<obj.Add(1,2); //3
    cout<<obj.Add(1); //Compile Error
    cout<<obj.Add(); //Compile Error
}

//v4 WRONG
class Math
{
    public:
    int Add(int x,int y=0,int z) //compile Error
    int Add(int x=0,int y,int z) //compile Error
    int Add(int x,int y=0,int z=0) 
    {
        return x+y+z;
    }
}

int main()
{
    Math obj;
    cout<<obj.Add(,33,44);  //compile Error
}

//v5 [dont use default argument with fn overloading]
class Math
{
    public:
    // int Add(int x,int y)
    // {
    //     return x+y;
    // }
    // int Add(int x,int y,int z)
    // {
    //     return x+y;
    // }
    
    //
    
    int Add(int x=0,int y=0,int z=0)
    {
        return x+y+z;
    }
};

int main()
{
    Math obj;
    cout<<obj.Add(1); //T
    cout<<obj.Add(1,2,3); //T
    
    
    cout<<obj.Add(1,2); //compile Error //ambiguty
}

///////////////////////////////////////////////
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
        this->real=_real;
        (*this).real=_real;
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
    //member fn to add 2 complex numbers
    //caller c1
    Complex Add(Complex right)
    {
        //real;img; ====> caller c1
        Complex result;
        result.real=/*caller*/real+right.real;
        result.img=/*caller*/img+right.img;
        return result;
    }
    //
    //function to initialize object
    void Initialize()
    {
        this->real=img=0;
    }
    void Initialize(int _real,int _img)
    {
        this->real=_real;
        img=_img;
    }
    void Initialize(int _num)
    {
        this->real=img=_num;
    }
    //

    //ctor
    //default parameterless ctor generated by o.s IF THERE IS NOOOO CTOR EXISTS  
    Complex()
    {
        //learning purpose
        COUT<<"COMPLEX def ctor"<<endl;
        real=0;
        this->img=0;
    }
    Complex(int _real,int _img)
    {
        //learning purpose
        COUT<<"COMPLEX 2p ctor"<<endl;
        real=_real;
        this->img=_img;
    }
    Complex(int _num)
    {
        //learning purpose
        COUT<<"COMPLEX 1p ctor"<<endl;
        real=(*this).img=_num;
    }
    //

    //dest
    ~Complex()
    {
        cout<<"dest called"<<endl;
    }
    //
};
///standalone fn add 2 complex Numbers
Complex AddComplex(Complex left,Complex right)
{
    Complex result;
    //result.real=left.real+right.real; //Compile Error
    int r=left.GetReal()+right.GetReal();
    int i=left.GetImg()+right.GetImg();
    result.SetReal(r);
    result.SetImg(i);
    return result;
}



///create 3 Complex with default initialization
//v1
int main()
{
    Complex c1;
    Complex c2;
    Complex c3;
    c1.SetReal(0);c1.SetImg(0);
    c2.SetReal(0);c2.SetImg(0);
    c3.SetReal(0);c3.SetImg(0);
}
//v2
int main()
{
    Complex c1;
    Complex c2;
    Complex c3;
    c1.Initialize();
    c2.Initialize(3,4);
    c3.Initialize(5);
}
//v3
int main()
{
    Complex c1;
    Complex c2(3,4);
    Complex c3(5);
   //All real ,img ->0
   //o/p
   //cm def ctor
   //cm 2p ctor
   //cm 1p ctor
   //dest called
   //dest called
   //dest called
   return 0;
}
/////////////////////////////////////////////
//Constructor:
// special method inside class/struct 
// implicitly exist [hidden]
//  will be called automatically -we cannot call it-
//Once we create object from that class/struct

how to write ctor explicitly?
//1-has same name of class
//2- has no return type even void
//3- can be overloaded
//4- must be public
class Trial
{
    public:
    Trial(){} //default ctor //generate by O.S
    Trial(int _x){}
    Trial(int _x,int _y){}
};

//////////////////////////////////////////////////////
//Destructor

//Destructor:
//Special function inside class/struct will be 
//called automatically
//cannot be called
//implicitly exist
//once O.S will object destructed from memory
//once object reach end of its scope

///how to write destructor explicitly?
///1- has same name of class starts with ~ Tilda
///2- has no return type nor void
///3- cannot be overloaded -onle one parameterless copy-
///4- MUST be public 

///what is tha real purpose for dest?
///1- connect to Db
///2- read from file
///3- dynamic allocation
class Trial
{
    public:
    Trial(){} //default ctor //generate by O.S
    Trial(int _x){}
    Trial(int _x,int _y){}
    ~Trial()
    {}
};

////////////////////////////////////////////////

class Trial1
{
    private:
    int *ptr;
    public:
    Trial1()
    {
        ptr=new int[10];
    }
    // //Mandatory
    // ~Trial1()
    // {
    //     delete[] ptr;
    // }
};

void TryMe()
{
    Trial1 obj;
}

int main()
{
    TryMe();
    TryMe();
    TryMe();
    Trial1 obj;
    Trial1 obj;
    Trial1 obj;
    return 0;
}


////////////////////////////////////
///////////////////////////////////////////////////
//Lab assignment
///class Complex
///private fields
///setters & getters
///constructors  3 ctors  cout <<ctor called
///destructor  //useless
///print  real <<"+"<<img<<"i"<<endl
//member Add function
//standalone add function
//remember to use this  -> return this->real ,(*this).img=_img; , real=_real

///codeblocks-> settings -> compilers 
///tab [other compiler options]
///-fno-elide-constructors   [RVO]


///complex c1,c2,c3
///c3=addCom(c1,c2) ; pass VALUES
///count #of ctor against # of destructor 




