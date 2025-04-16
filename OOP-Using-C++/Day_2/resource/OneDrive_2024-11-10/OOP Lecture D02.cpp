////////*this////////////////////////////////

#include <iostream>
using namespace std;

class Draft
{
    int x,y;
    public:
    void setX(/*Draft *this*/int _x)
    {
        this->x=_x;
    }
};

class Complex
{
    int real, img;

//any member fn has fst param names *this for caller
public:
//                       &c1              1
    void setReal(int _real)//1
    {
        real=_real;  
    }
    void setImg(/*Complex *this,*/int _img)
    {
        this->img=_img;
        //img=_img;
    }
    int getReal(/*Complex *this,*/)
    {
        return this->real;
    }
    int getImg(/*Complex *this,*/)
    {
        return this->img;
    }
    void printComplex(/*Complex *this,*/)
    {
        cout << this->real << "+" << this->img << "i" << endl;
    }
    Complex addComplex(/*Complex *this,*/Complex right)
    {
        Complex retVal;
        retVal.real = this->real + right.real;
        retVal.img = this->img + right.img;
        return retVal;
    }
};
///there is no * this in standalone function
Complex subComplex(Complex left,Complex right)
{
    Complex retVal;
    retVal.setReal(left.getReal()-right.getReal());
    retVal.setImg(left.getImg()-right.getImg());
    return retVal;
}

int main()
{
    Complex c1,c2,c3;
    c1.setReal(1); //Compiler c1.setReal(&c1,1)
    c1.setImg(2);
    c2.setReal(3);
    c2.setImg(4);
    c1.printComplex();
    c2.printComplex();
    /*c1.real;*/  //*this  =====> c1
        Draft d;
    d.setX(9);  //d.setX(&d,9)
    return 0;
}


///Functions////////////////////////////////////////////////////////
//function overloading:
//FunctionS -in the same scope- have same 
//IGNORE RETURN TYPE 
//name but
//different input parameters number
//Or Different data type


//deafult Argument :must be from right to left in params
//if there is  def argument in middle,
//must ALL of right of it be default also
class Trial
{
    public:
    /*int Add(const int& x,const int& y)
    {
        //x=22; //compile error
        return x+y;
    }*/

    /*int Add(int a,int b)  //Compile error
    {
        return a+b;
    }*/
    /*char Add( int x, int y)
    {
        return 'A';
    }*/
    int Add( int x, int y)
    {
        return x+y;
    }
    int Add(float x,float y)
    {
        return x+y;
    }
    int Add(int x,int y,int z)
    {
        return x+y+z;
    }
    int Add(char c1,char c2)
    {
        return 22;
    }
    int Add(int x,char y)
    {
        return 33;
    }
    int Add(char y,int x)
    {
        return 33;
    }
///////////////////////////////////////
//             1        2       0
    int Add(int x=0,int y,int z)   //Compile Error
    {
        return x+y+z;
    }

    //Soln1
    int Add(int x=0,int y=9,int z=9,int t=9);

    //Soln2
    int Add(int y,int z,int x=0);

    int Add(int x=0,int y=0,int z)   //Compile Error
    {
        return x+y+z;
    }

    //Add(,2,3);  =>Not Supported for any lang.
    //Add(3)


    // x,y have no arguments
    //Add(1,2,3)  T
    //Add(1,2)    T
    //Add(1)      F
    //Add()       F



    // x has no def Argument
    //Add(1,2,3) T
    //Add(1,2)   T
    //Add(1)     T
    //Add()      F
///////////////////////////////////////////////////
    /*int Add(int x,int y)
    {
        return x+y;
    }*/
    int Add(int x=0,int y=0,int z=0)   
    {
        return x+y+z;
    }
    //call Fn  All Def Argument
    1 (1,2,3)
    2 (1,2)  //####  <=====Here   Ambigous
    3 (1)
    4 ()

};


int main()
{
    Trial obj;
    int num1=5,num2=6;
    obj.Add(5,4,3);  //ignore default arguments   //12

    obj.Add(1,2);   //z=0    //3

    obj.Add(1);   //1

    obj.Add();  //0







    obj.Add(3,4);  ///Add(int,int)
    obj.Add(3.4,4.5); //Add(fl,fl)
    obj.Add((float)5,(float)6);   //float  //try
    obj.Add(5.00f,6.00f);   //ambigous  =>//Suffix
    obj.Add(3,4,5);
    obj.Add('X','Y');
    obj.Add(2,'A');
    obj.Add('A',2);



    /*int num1=5,num2=6;
    int res=obj.Add(num1,num2);   //11;   ///search Add(int,int);
    cout<<res;*/
    return 0;
}
//Output

/////////////////////////////////////////////////////////////////
#include <iostream>
using namespace std;

class Complex
{
    int real, img;


public:
                                 
    void setReal(int _real)
    {
        real=_real;  
    }
    void setImg(int _img)
    {
        this->img=_img;
        //img=_img;
    }
    int getReal()
    {
        //real=77;
        return this->real;
    }
    int getImg()
    {
        return this->img;
    }
    void printComplex()
    {
        cout << this->real << "+" << this->img << "i" << endl;
    }
    Complex addComplex(const Complex& right)
    {
        Complex retVal;
        retVal.real = this->real + right.real;
        retVal.img = this->img + right.img;
        return retVal;
    }
    void initiateComplex()
    {
        real=0;
        img=0;
    }
    void initiateComplex(int _real,int _img)
    {
        real=_real;
        img=_img;
    }
    void initiateComplex(int num)
    {
        real=img=num;
    }
    //ctors
    Complex()
    {
        cout<<"parameterless ctor"<<endl; //for tracing purpose
        real=0;
        img=0;
    }
    Complex(int _real,int _img)
    {
        cout<<"2 params ctor"<<endl;
        real=_real;
        img=_img;
    }
    Complex(int num)  //Here
    {
        cout<<"1 param ctor"<<endl;
        real=img=num;
    }
    //
    //dest
    ~Complex()
    {
        //there is nothing to do
        cout<<"Destructor called"<<endl;
        //For tracing purpose
    }
    //

};
///there is no * this in standalone function
//const here will cause compile error
//Compiler will be afraid of getReal() and getImg()
Complex subComplex( Complex& left, Complex& right)
{
    Complex retVal;
    retVal.setReal(left.getReal()-right.getReal());
    retVal.setImg(left.getImg()-right.getImg());
    return retVal;
}


int main()
{
    /*Complex c1,c2,c3,c4;   //4 objects
    c1.initiateComplex(3,4);
    c2.initiateComplex();
    c3.initiateComplex(3,4);
    c4.initiateComplex(6);
    c1.setReal(4);  //rarely used  Must be written
    c1.addComplex(c2);
    subComplex(c1,c2);

    //
    c3.setReal(5);*/
    //int x;
    Complex c1,c2;   //c1 r0 i0      c2  r0  i0  
    //Compile error
    //Compiler will generate parameterless ctor  
    //WHEN there is NOOOOO ctor exist
    Complex c3(3,4);
    Complex c4(6);
    return 0;
}

//output
//def ctor
//def ctor
//2 prams ctor
//1 param ctor
//dest called
//dest called
//dest called
//dest called



/////////////////////////////////////////
//Constructor:
// special function inside class/struct  implicitly exist
//will be called automatically -we cannot call it-
//Once we create object from that class/struct

//how to write explicit ctor?
//1- the same name of class/struct
//2- has no return type
//3- can be overloaded
//4- MUST be public   //[private]=>we cannot create object design patterns    

class Draft
{
    public:
    Draft(){}
    ~Draft(){}
    void print()
    {}
};


/////////////////////////////////////////////////////////
//Destructor:
//Special function inside class/struct will be called automatically
//cannot be called
//implicitly exist
//once object destructed from memory
//once object reach end of its scope


//how to write dest explicitly?
//1- the same name of class 
//2- before it ~  [tilde]
//2-1- has no return type
//3-has no params -parameterless- cannot be overloaded -just one of it-
//4- must be public


//When to use destructor?
//1- dynamic allocation  [heap]
//2- connect to db
//3- read/write from file


class Trial
{
    int* ptr;
    public:
    Trial()
    {
        ptr=new int [10];
    }
    ~Trial()
    {
        delete [] ptr;
    }
};

void Anyfun()
{
    Trial obj;
}

int main()
{
    Anyfun();
    Anyfun();
    Anyfun();
}

////////////////////////////////////////////////////////////
class Complex
{
    int real, img;
public:               
    void setReal(int _real);//here//
    void setImg(int _img);
    int getReal();
    int getImg();
    void printComplex();    
    Complex addComplex(const Complex& right);
    void initiateComplex();
    void initiateComplex(int _real,int _img);
    void initiateComplex(int num);
    //ctors
    Complex();
    Complex(int _real,int _img);
    Complex(int num) ; //Here
    //
    //dest
    ~Complex();
    
    //

};
///there is no * this in standalone function
//const here will cause compile error
//Compiler will be afraid of getReal() and getImg()
Complex subComplex( Complex& left, Complex& right)
{
    Complex retVal;
    retVal.setReal(left.getReal()-right.getReal());
    retVal.setImg(left.getImg()-right.getImg());
    return retVal;
}
main()
{

}

void Complex::setReal(int _real)
{

}

void Complex::setImg(/*complex * this*/int _img)
{
    this->img=_img;
}

Complex::Complex()
{}

Complex::~Complex()
{}


//inline function

////////////Lab Assignment//////////////////////////////////////

//try fn overloading
//try def argument



//class Complex
//private field
//Try this pointer
//setters and getters
//Print fn
//Constructors   cout<<ctor
//Destructor     cout<<dest
//Add member
//Sub standalone

//main
//Complex c1(1,2),c2(3,4),c3;

//c3=c1.addComplex(c2);

//c3=subComplex(c1,c2);


//Concern?? # ctor === # dest
//trace  # ctor != # dest
//trace Destructors From where ????



//codeblocks   => disable RVO
//settings-> complier -> other compliler  options
-fno-elide-constructors      //dash not underscore