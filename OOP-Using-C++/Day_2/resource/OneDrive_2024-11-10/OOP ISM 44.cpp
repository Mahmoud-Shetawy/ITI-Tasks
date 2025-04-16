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
//in any member function
//there is hidden input parameter [You cannot declare it explicitly]
//called classname *this
//////////////////////////////////////////////////////
#include<iostream>
using namespace std;
class Trial
{
    private:
    int x;
    int y;
    public:

    // void SetX(int x)
    // {
    //     //ابعدوا عن المشتبهات
    //     this->x=x;
    // }

    //who called function? caller [obj]
    void SetX(/*Trial *this,*/int _x)
    {
        (*this).x=_x;
        this->x=_x;
        x=_x;
    }
    int getX(/*Trial *this*/)
    {
        return x;
    }
    void SetY(/*Trial *this,*/int _y)
    {
        (*this).y=_y;
        this->y=_y;
        y=_y;
    }
    int getY(/*Trial *this*/)
    {
        return y;
    }

    void Print(/*Trial *this*/)
    {
        cout<<"x="<<x <<",and y="<<y<<endl;
    }
};

int main()
{
    int x=4;
    Trial obj;  //x|#| y|#| //Object/Instance from Trial 8B
    
    obj.SetX(3); //Compiler Trial::SetX(&obj,3);

    obj.SetY(x); //Compiler Trial::SetY(&obj,4);
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
    //setters& getters
    void SetReal(/*Complex *this,*/int _real)
    {
        real=_real;
        (*this).real=_real;
        this->real=_real;
        // cout<<*this; //0x10
    }
    void SetImg(int _img){this->img=_img;}
    int GetReal()const {return (*this).real;}
    int GetImg() const {return img;}

    //print
    void Print()
    {
        cout<<this->real <<"+" <<img <<"i"<<endl;
    }
    //


    //Add as a member fn
    // Complex Add(Complex left,Complex right)
    //who called Add -> caller
    Complex Add(const Complex& right)
    { 
        Complex obj;
        obj.real=this->real+right.real;
        obj.img=(*this).img+right.img;
        //right.img=-11111; //COMPILE ERROR
        return obj;
    }
    //
};
//AddComplex as standalone fn
//there is no *this in standalone fn
//its called by its name direct
Complex AddComplex(const Complex& left,const Complex& right)
{
    Complex obj;
    //obj.real=left.real+right.real; //Compile Error //inaccessible
    obj.SetReal(left.GetReal()+right.GetReal());
    obj.SetImg(left.GetImg()+right.GetImg());
    //left.SetImg(-1111111); //compile Error
    return obj;
}


int main()
{
    Complex c1,c2,c3;
    c3=AddComplex(c1,c2);
    return 0;
}

///////////////////////////////////////////////////////
//overloading
//Function overloading
//Function/S -in the same scope- have same //name but
//IGNORE RETURN TYPE 
//different input parameters number
//Or Different data type


//defult Argument :must be from right to left in params
//if there is  def argument in middle,
//must ALL of right of it be default also

////////////////////////////////////////////////////

class Draft
{
    public:
    int Add(int x)
    {
        return x;
    }
    int Add(int x,int y)
    {
        return x+y;
    }
    int Add(int x,int y,int z)
    {
        return x+y+z;
    }
    int Add(char l,char r){}
};
int main()
{
    Draft o1;
    cout<<o1.Add(22,33);  //55
    cout<<o1.Add(22,33,100);  //155
}


/////////////////////////////////////////////////
//V1
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
}

//////////////////
//V2
int Add(int x,int y=0,int z=0)
{
    return x+y+z;
}

int main()
{
    cout<<Add(1,2,3); //6
    cout<<Add(1,2);   //3
    cout<<Add(1);     //1
    cout<<Add();      //Compile Error
}

//////////////////
//V3
int Add(int x,int y,int z=0)
{
    return x+y+z;
}

int main()
{
    cout<<Add(1,2,3); //6
    cout<<Add(1,2);   //3
    cout<<Add(1);     //Compile Error
    cout<<Add();      //Compile Error
}

//////////////////
//V4
//COMPILE ERROR
int Add(int x=0,int y,int z)
{
    return x+y+z;
}

//COMPILE ERROR
int Add(int x,int y=0,int z)
{
    return x+y+z;
}

int Add(int x=0,int y=0,int z=0)
{
    return x+y+z;
}

int Add(int y,int z,int x=0)
{
    return x+y+z;
}

int main()
{
    Add(2,EMPTY,3);
    cout<<Add(EMPTY,2,3); // NOT SUPPORTED
    Add(1,2);
}

////////////////////////////////////////////////
//NOT RECOMMENDED

class Draft
{
    public:
    int Add(int x=0,int y=0,int z=0)
    {
        return x+y+z;
    } 
    int Add(int x,int y)
    {
        return x+y;
    }  
};

int main()
{
    Draft o1;
    cout<<o1.Add(3,4,5); //12
    cout<<o1.Add(1);    //1
    cout<<o1.Add();    //0

    cout<<o1.Add(3,4); //Compile Error  //Ambiguty
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
    void SetReal(int _real){real=_real;}
    void SetImg(int _img){img=_img;}
    int GetReal()const {return real;}
    int GetImg() const {return img;}
    void Print()
    {
        cout<<real <<"+" <<img <<"i"<<endl;
    }
    Complex Add(const Complex& right)
    { 
        Complex obj;
        obj.real=this->real+right.real;
        obj.img=img+right.img;
        return obj;
    }
    //

    //Constructor/s
    //def constructor written explicitly
    Complex()
    {
        real=0;
        this->img=0;
        //for debugging purpose
        cout<<"0p ctor called"<<endl;  
    }
    Complex(int _real,int _img)
    {
        real=_real;
        (*this).img=_img;
        //for debugging purpose
        cout<<"2p ctor called"<<endl; 
    }
    Complex(int _num)
    {
        real=img=_num;
        //for debugging purpose
        cout<<"1p ctor called"<<endl;
    }
    //

    //destructor  -> is useless  -> for learning purpose
    ~Complex()
    {
        //for debugging purpose
        cout<<"destructor called"<<endl;
    }
    //

    //function to initiate
    void Initiate()
    {
        this->real=0;
        img=0;
    }
    void Initiate(int _real,int _img)
    {
        real=_real;
        (*this).img=_img;
    }
    void Initiate(int _num)
    {
        real=this->img=_num;
    }
    //
};//end of Complex class scope

//AddComplex as standalone fn
Complex AddComplex(const Complex& left,const Complex& right)
{
    Complex obj;
    obj.SetReal(left.GetReal()+right.GetReal());
    obj.SetImg(left.GetImg()+right.GetImg());
    return obj;
}

int main()
{
    Complex c1,c2,c3;   //ALL Data #  c2 r|#|  i|#|

    c1.SetReal(0);
    c1.SetImg(0);

    c2.SetReal(0);
    c2.SetImg(0);

    c3.SetReal(0);
    c3.SetImg(0);
}

int main()
{
    Complex c1,c2,c3;   //All DATA #

    c1.Initiate();    //c1 r|0| i|0|
    c2.Initiate(4,5); //c2 r|4| i|5|
    c3.Initiate(10);  //c3 r|10| i|10|
}

int main()
{
    Complex c1,c2,c3;  //All Data 0
}

int main()
{
    int x=3;
    Complex c1,c2,c3,c4;
    //o/p
    //0p ctor called
    //0p ctor called
    //0p ctor called
    //0p ctor called


    Complex c5(3,4);
    //o/p
    //2p ctor called

    Complex c6(10);
    //o/p
    //1p ctor called
    return 0;
}

//No ctor explicitly exists
//O.S will Generate Empty default parameterless ctor
int main()
{

    Complex c1;  //Runs successfully
    Complex c2(3,4); //Compile Error
    Complex c3(5);   ////Compile Error
}

//fn {Complex c1;}
//2pctor + 1pctor Exists
//when create any ctor , O.S will not generate def ctor
int main()
{

    Complex c1;  // Compile Error
    Complex c2(3,4); // T
    Complex c3(5);   // T
}

//after add destructor
int main()
{
    Complex c1,c2(3,4),c3(5);
    return 0;
}
//o/p
//0p ctor called
//2p ctor called
//1p ctor called
//dest called
//dest called
//dest called
/////////////////////////////////////////////////
//Constructor
///////////////////////////////////////////
//Constructor:
// special method inside class/struct 
// implicitly exist
//will be called automatically -we cannot call it-
//Once we create object from that class/struct

//how to write explicit ctor?
//1- the same name of class/struct
//2- has no return type even void
//3- can be overloaded
//4- MUST be public   //[private]=>we cannot create object design patterns    

class Trial
{   
    private:
    int x;
    public:
    Trial()
    {x=0;}
    Trial(int _x)
    {}
};

class Student
{
    int ssn=12345;
    string name ="Islam";
    int age=22;
    public:
    //ctor
    //setters  
};

//main
//Trial obj;


//Destructor:
//Special function inside class/struct will be 
//called automatically
//cannot be called
//implicitly exist
//once O.S will object destructed from memory
//once object reach end of its scope

class Trial
{   
    private:
    int x;
    public:
    Trial()
    {x=0;}
    Trial(int _x)
    {}
    ~Trial(){}
};

//how to write dest explicitly?
//1- the same name of class 
//2- start ~  [tilda]
//2-1- has no return type
//3-has no params -parameterless- cannot be overloaded -just one of it-
//4- must be public


//Main Usage of Destructor

//When to use destructor?
//1- dynamic allocation  [heap]
//2- connect to db
//3- read/write from file


class Trial
{
    private:
    int *ptr;
    public:
    Trial()
    {
        ptr=new int[10];
        //loop -> 10->100
    }
    ~Trial()  //IS MUST for DEALLOCATION
    {
        delete[] ptr;
    }
};

void TryMe()
{
    Trial o1;
}

int main()
{
    TryMe();
    TryMe();
    TryMe();
    return 0;
}

///////////////////////////////////////////////////
//Lab assignment
///class Complex
///private fields
///setters & getters
///constructors  3 ctors
///destructor
///print  real <<"+"<<img<<"i"<<endl
//member Add function
//standalone add function
//remember to use this  -> return this->real ,(*this).img=_img; , real=_real
///function to initiate
///count #of ctor against # of destructor 

