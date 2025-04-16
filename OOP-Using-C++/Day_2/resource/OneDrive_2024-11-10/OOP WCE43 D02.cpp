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
//there is hidden input parameter
//called classname* this
//////////////////////////////////////////////////////
#include<iostream>
using namespace std;
class Trial
{
    private:
    int x;
    int y;
    public:
    void setX(/*Trial* this*/int _x)
    {
        (*this).x=_x;
        this->x=_x;
        x=_x;
        ///*caller*/x=_x;
    }
    int getX(/*Trial* this*/)
    {
        return x;
        return this->x;
        return (*this).x;
    }
    void setY(/*Trial* this*/int _y)
    {
        y=_y;
    }
    int getY(/*Trial* this*/)
    {
        return this->y;
    }
    void printTrial(/*Trial* this*/)
    {
        cout<<this->x<<y;
    }
};

int main()
{
    Trial obj,obj2;  //8B
    obj.setX(10); //Compiler   Trial::setX(&obj,10)
}

///////////////////////////////////////////////////
class Complex
{
    private:
    int real;
    int img;
    public:
    void setReal(/*Complex* this*/int _real)
    {
        this->real=_real;
    }
    int getReal() const/*this*/
    {
        return this->real;
    }
    void setImg(int _img) 
    {
        this->img=_img;
    }
    int getImg() const
    {
        return img;
    }

    void printComplex()
    {
        cout<< this->real <<"+" <<this->img <<"i" <<endl;
    }

    //Add Two Complexes
    //Two params :  right , caller

    Complex addComplex(const Complex& right)
    {
        // right.real=777;  //XXXXX
        Complex retVal;
        retVal.real=this->real+right.real;
        retVal.img=(*this).img+right.img;
        return retVal;
    }
    //
};
///Stand alone fn subComplex
//standalone fn doesn't have *this
Complex subComplex(const Complex& left,const Complex& right)
{
    // left.setReal(777); //XXX
    Complex retVal;
    retVal.setReal(left.getReal()- right.getReal());
    retVal.setImg(left.getImg()-right.getImg());
    return retVal;
}

int main()
{
    Complex c1,c2,c3;
    c1.setReal(3);    /// Complex::setReal(&c1,10)
    c1.setImg(4);
    
    c2.setReal(5);    /// Complex::setReal(&c2,5)
    c2.setImg(6);

    c3=c1.addComplex(c2);
}


////////////////////////////////////////////
//Function overloading
//FunctionS -in the same scope- have same //name but
//IGNORE RETURN TYPE 
//different input parameters number
//Or Different data type


//deafult Argument :must be from right to left in params
//if there is  def argument in middle,
//must ALL of right of it be default also

class Draft
{
    public:
    //???
};
int Add(int x,int y)
{
    return x+y;
}
// char Add(int a,int b)
// {
//     return a+b;
// }

int Add(int x,int y,int z)
{
    return x+y+z;
}

float Add(float a,float b)
{

}
int main()
{
    cout<< Add(3.0,4.0);  //Compiler search on Add(int,int)
}

//////////////////////////////////////////////
//default arguments
#include<iostream>
using namespace std;

int Add(int x=0,int y=0,int z=0)
{
    return x+y+z;
}

int main()
{
    cout<< Add(1,2,3);  //6 
    cout<< Add(1,2);  //3 
    cout<< Add(1);  // 1
    cout<< Add();  // 0

    return 0;
}
//V02
#include<iostream>
using namespace std;

int Add(int x,int y=0,int z=0)
{
    return x+y+z;
}

int main()
{
    cout<< Add(1,2,3);  //6 
    cout<< Add(1,2);  // 3
    cout<< Add(1);  // 1
    cout<< Add();  // Compile Error

    return 0;
}
/////
//V03
#include<iostream>
using namespace std;

int Add(int x,int y,int z=0){return x+y+z;}

int main()
{
    cout<< Add(1,2,3);  // 6
    cout<< Add(1,2);  // 3
    cout<< Add(1);  // Compile Error
    cout<< Add();  // Compile Error

    return 0;
}

//////
//V04
#include<iostream>
using namespace std;

int Add(int x=1,int y,int z){return x+y+z;} //COMPILE ERROR

int main()
{
    cout<< Add(,2,3); //Not Supported

    cout<< Add(1);
    return 0;
}
////////////////////////////////////////////////////
///REMEMBER : use def argument OR Overloading
int Add(int x,int y){}
int Add(int x=0,int y=0,int z=0){}
int Add(int x){}

int main()
{
    cout<< Add(11,22);  //Compile Error Ambiguty
}
////////////////////////////////////////////////////
class Complex
{
    private:
    int real;
    int img;
    public:
    void setReal(/*Complex* this*/int _real)
    {
        this->real=_real;
    }
    int getReal() const/*this*/
    {
        return this->real;
    }
    void setImg(int _img) 
    {
        this->img=_img;
    }
    int getImg() const
    {
        return img;
    }

    void printComplex()
    {
        cout<< this->real <<"+" <<this->img <<"i" <<endl;
    }

    //Add Two Complexes
    //Two params :  right , caller

    Complex addComplex(const Complex& right)
    {
        // right.real=777;  //XXXXX
        Complex retVal;
        retVal.real=this->real+right.real;
        retVal.img=(*this).img+right.img;
        return retVal;
    }
    //
    ///function/s to initiate Object
    void initiate()
    {
        real=img=0;
    }
    void initiate(int _num)
    {
        real=img=_num;
    }
    void initiate(int _real,int _img)
    {
        real=_real;img=_img;
    }
    ///

    ///ctors
    // //def ctor that is imilicitly exist
    Complex()
    {
        /// for debugging purpose
        cout<<"def ctor called"<<endl;
        this->real=img=0;
    }
    Complex(int _real,int _img)
    {
        /// for debugging purpose
        cout<<"2P ctor called"<<endl;
        this->real=_real;img=_img;
    }
    Complex(int _num)
    {
        /// for debugging purpose
        cout<<"1P ctor called"<<endl;
        this->real=img=_num;
    }
    ///

    ///dest
    ~Complex()
    {
        //for debugging purpose
        cout<<"Dest called"<<endl;
    }
    ///
};
///Stand alone fn subComplex
//standalone fn doesn't have *this
Complex subComplex(const Complex& left,const Complex& right)
{
    Complex retVal;
    retVal.setReal(left.getReal()- right.getReal());
    retVal.setImg(left.getImg()-right.getImg());
    return retVal;
}


///after ctor
int main()
{
    Complex c1,c2(3,4),c3(5);
    //o/p
    //def ctor
    //2p ctor
    //1p ctor
    //Dest called
    //Dest called
    //Dest called
    return 0;
}

//Before ctor
int main()
{
    //Complex c1,c2,c3;    //each real ,img  -> ### value
    // c1.setReal(0);
    // c1.setImg(0);
    // c2.setReal(0);
    // c2.setImg(0);
    // c3.setReal(0);
    // c3.setImg(0);

    // c1.initiate();
    // c2.initiate(3,4);
    // c3.initiate(5);

    ///solution
    //Complex c4; ///real0    img 0

}
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


class Draft
{
    int x;
    public:
    Draft(){}
    Draft(int _x){}

    ~Draft(){}
};


//Destructor:
//Special function inside class/struct will be 
//called automatically
//cannot be called
//implicitly exist
//once O.S will object destructed from memory
//once object reach end of its scope


//how to write dest explicitly?
//1- the same name of class 
//2- before it ~  [tilde]
//2-1- has no return type
//3-has no params -parameterless- cannot be overloaded -just one of it-
//4- must be public


//Main Usage of Destructor

//When to use destructor?
//1- dynamic allocation  [heap]
//2- connect to db
//3- read/write from file


////////////////////////////////////////////////

class Trial
{
    int *ptr;
    public:
    Trial()
    {
        ptr=new int [10];
    }
    ~Trial()
    {
        delete[] this->ptr;
    }
};

void TryMe()
{
    Trial obj;
}

int main()
{
    TryMe();
    TryMe();
    TryMe();
    Trial obj;
}

////////////////////////////////////////
///Complex
///real 
///img
///setters & getters
///ctors
//dest
//print
//add member

//sub stanalone

///Codeblocks
///settings -> compiler
///tab [other compiler options]
///-fno-elide-constructors   ///RVO


///main
//complex c1,c2,c3

//c3=c1.add(c2);  
//c3=sub(c1,c2);  
