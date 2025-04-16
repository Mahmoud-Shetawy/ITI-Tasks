///*this
///const
///Function Overloading
///Default Arguments
///Constructor
///Destructor
///Stack
///template
///static
///friend function
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
    void SetX(/*Draft *this,*/int _x)
    {
        (*this).x=_x;
        this->x=_x;
        x=_x;
    }
    int GetX(/*Draft *this*/)
    {
        return this->x;
        return (*this).x;
        return x;
    }
    void SetY(/*Draft *this*/int _y)
    {
        this->y=_y;
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
    Draft obj;  //stack  //8B  obj x|| y||
    obj.SetX(10); //Compiler Draft::SetX(&obj,10);
    
    cout<<obj.GetX();  //Compiler Draft::GetX(&obj);
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
    void SetReal(/*Complex *this,*/int _real)
    {
        (*this).real=_real;
        this->real=_real;
        real=_real;
    }
    int GetReal() const
    {
        //real=-123; //compile error
        return real;
    }
    void SetImg(int _img)
    {
        this->img=_img;
    }
    int GetImg() const
    {
        return (*this).img;
    }
    void Print() const
    {
        cout<<this->real <<"+" <<img <<"i"<<endl;
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
    Complex Add(const Complex& right)
    {
        //Compile Error
        //right.real=-123;
        //
        Complex result;
        result.real=/*caller*/real+right.real;
        result.img=/*caller*/img+right.img;
        return result;
    }
    //
};
///standalone fn add 2 complex Numbers
Complex AddComplex(const Complex& left,const Complex& right)
{
    //Compile Error
    //left.SetReal(-123);
    //
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
    Complex c1,c2,c3;

    c1.SetReal(3);   //Compiler Complex::SetReal(&c1,3)
    c1.SetImg(4);
    c2.SetReal(5);
    c2.SetImg(6);
    //c3=c1.Add(c2);   ///Complex::Add(&c1,c2) //c2 pass by VALUESSSS
    
    //c3=AddComplex(c1,c2); //pass by VALUESSS
    c3=AddComplex(c1,c2); //pass by REFERENCE
    //  c1 real|-123| img|4|
    //c1.SetReal(3);

    //
    // int *ptr=new int[10];
    // ptr[0]=10;

    // Complex *thisComplex=&c1;
    // (*thisComplex).SetAge();
    // thisComplex->SetReal(3);

    
    return 0;
}

///////////////////////////////////////////////
///overloading
//Function overloading
//Function/S -in the same scope- have same //name but
//IGNORE RETURN TYPE 
//different input parameters number
//Or Different data type or ORDER

////Add(int,int)
////Add(int)
////Add(char)
////Add(char,double)
////Add(double,char)

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
    cout<<obj.Add(11,22); //33    //Search Add(int,int)
    cout<<obj.Add(1,2,3);//6
    return 0;
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
    int Mul(int x=1,int y=1,int z=1)
    {}
}

int main()
{
    Math obj;
    cout<<obj.Add(1,2,3); //6
    cout<<obj.Add(1,2);   //3
    cout<<obj.Add(1);     //1
    cout<<obj.Add();      //0
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
    cout<<obj.Add(1,2);   //3
    cout<<obj.Add(1);     //1
    cout<<obj.Add();      //Compile Error
    
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
    cout<<obj.Add(1,2);   //3
    cout<<obj.Add(1);     //Cmpile Error
    cout<<obj.Add();      //Compile Error
}

//v4 WRONG
class Math
{
    public:
    int Add(int x=0,int y,int z) //Compile Error
    {
        return x+y+z;
    }
}

int main()
{
    Math obj;
    //cout<<obj.Add(,2,3); 
}

//v5 [dont use default argument with fn overloading]
class Math
{
    public:
    int Add(int x=0,int y=0 ,int z=0)
    {
        return x+y+z;
    }
    int Add(int x,int y)
    {
        return x+y;
    }
    int Add(double x,double y)
    {
        return x+y;
    }
};

int main()
{
    Math obj;
    cout<<obj.Add(11); //T
    cout<<obj.Add(11,22,33); //T
    cout<<obj.Add(); //T

    cout<<obj.Add(11lf,22lf); //compile Error  //ambiguty

}

///////////////////////////////////////////////
#include<iostream>
using namespace std;
struct Complex
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
    //default ctor parameterless that generated 
    //by o.s if there is nooo explicit ctor exists
    Complex()
    {
        real=this->img=0;
        cout<<"def ctor called"<<endl;
    }
    Complex(int _real,int _img)
    {
        real=_real;this->img=_img;
        cout<<"2p ctor called"<<endl;
    }
    Complex(int _num)
    {
        real=this->img=_num;
        cout<<"1p ctor called"<<endl;
    }
    //

    //dest [useless]
    //for tracing purpose
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



///create 3 Complex with default initialization 0,0
//v1
int main()
{
    Complex c1,c2,c3; //c1 real|$|img|$|
    c1.SetReal(0);
    c1.SetImg(0);
    c2.SetReal(0);
    c2.SetImg(0);
    c3.SetReal(0);
    c3.SetImg(0);
}
//v2
int main()
{
    Complex c1,c2,c3; //c1 real|$|img|$|
    c1.Initialize();
    c2.Initialize(3,4);
    c3.Initialize(5);
}
//v3
int main()
{
    Complex c1; //ALL real|0|img|0|
    Complex c2(3,4);
    Complex c3(5);
    //o/p
    //def ctor called
    //2p ctor called
    //1p ctor called
    //dest called
    //dest called
    //dest called
    return 0;
}
/////////////////////////////////////////////
//Constructor:
// special method inside class/struct 
// implicitly exist [hidden]
// will be called automatically 
// -we cannot call it-
//Once we create object from that class/struct

//how to write ctor explicitly?
//1- has same name of class
//2- has no return type even void
//3- can be overloaded
//4- must be public [some cases private [Design patterns]]
class Trial
{
    public:
    Trial(){}
    Trial(int _x){}
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
    int *ptr;
    public:
    Trial()
    {
        ptr=new int[10];
    }
    //IMPORTANT
    ~Trial()
    {
        delete [] ptr;
    }
};
void TryFn()
{
    Trial obj;
}
int main()
{
    TryFn();
    TryFn();
    TryFn();
}

////////////////////////////////////////////////

class Trial1
{
    private:
    int *ptr;
    public:
    
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
///////////////////////////////////////////////////
#include<iostream>
using namespace std;
class Stack
{
    private:
    int arr[5];
    int tos;
    public:
    //setters & getters //NOOOOOO
    // int GetTos(){return tos;}
    // int* GetArr(){return arr;}
    Stack()
    {
        tos=0;
    }
    ~Stack() //useless
    {
        cout<<"Stack dest called"<<endl;
    }
    ///Stack Functions
    void Push(int value)
    {
        if(tos!=5)
        {
            arr[tos]=value;
            tos++
        }
        else
        {
            cout<<"FULL !!!!"<<endl;
        }
    }
    int Pop()
    {
        int result;
        if(tos!=0)
        {
            tos--;
            result=arr[tos];
            return result;
        }
        else
        {
            cout<<"EMPTY!!!!";
            return -1234; //not Effective
            //throw runtime error
        }
    }
    ///
};
int main()
{
    // Stack s1;  //Stack  s1 arr0x10||||||  tos|66|
    // s1.SetTos(66);

    // int *ptr= s1.GetArr();
    // ptr[3]=22;
    // ptr[0]=1000;
    return 0;
}

int main()
{
    Stack s1;  //Stack  s1 arr0x10||||||  tos|0|
    s1.Push(1);
    s1.Push(2);
    s1.Push(3);
    s1.Push(4);
    s1.Push(5);
    s1.Push(6);
    s1.Push(7);

    cout<<s1.Pop();
    cout<<s1.Pop();
    cout<<s1.Pop();
    cout<<s1.Pop();
    cout<<s1.Pop();
    cout<<s1.Pop();
    cout<<s1.Pop();
    return 0;
}
//o/p
//stack ctor
//full
//full
//5
//4
//3
//2
//1
//EMPTY -123
//EMPTY -123
//stack dest
//////////////////////////////////////////////////////

///cout<<enter stack size;
///cin>>size;
//stack s1(size);
#include<iostream>
using namespace std;
class Stack
{
    private:
    int* arr;
    int tos;
    int size;
    public:
    Stack()
    {
        tos=0;
        size=5;
        arr=new int[size];
        cout<<"ctor"<<endl;
    }
    Stack(int _size)
    {
        tos=0;
        size=_size;
        arr=new int[size];
        cout<<"ctor"<<endl;
    }
    ~Stack() //Important
    {
        //useless 
        for (int i = 0; i < size; i++)
        {
            arr[i]=-1;
        }
        //
        delete[] arr;
        cout<<"Stack dest called"<<endl;
    }
    ///Stack Functions
    void Push(int value)
    {
        //if(tos!=size)
        if(!IsFull())
        {
            arr[tos]=value;
            tos++
        }
        else
        {
            cout<<"FULL !!!!"<<endl;
        }
    }
    int Pop()
    {
        int result;
        //if(tos!=0)
        if(!IsEmpty())
        {
            tos--;
            result=arr[tos];
            return result;
        }
        else
        {
            cout<<"EMPTY!!!!";
            return -1234; //not Effective
            //throw runtime error
        }
    }
    int IsFull()
    { return tos==size; }
    int IsEmpty()
    { return tos==0;}
    ///
    //
    friend void ViewStack(Stack param);
    //
    
};

//for tracing purpose
//standalone function to print
//stack data without change it
void ViewStack(Stack param)
{
    for (int i = 0; i < param.tos; i++)
    {
        cout<<param.arr[i]<<endl;
    }   
} 
is there any way to make standalone funcion

can access private members of class? YES

if it became friend function
friend function:
stand alone fn but can access private members of class it is friend at.

int main()
{
    Stack s1(10);
    s1.Push(10);
    s1.Push(20);
    s1.Push(30);
    s1.Push(40);

    ViewStack(s1); //pass VALUESSSS [in stackM]
    return 0;
}

/////////////////////////////////////////////////////
#include<iostream>
using namespace std;
class Stack
{
    private:
    int* arr;
    int tos;
    int size;

    // this line of code is executed once per program call
    
    static int counter=0;// =0 compile Error //suppose it carries 0
    
    
    public:
    //static fn has no *this
    static int GetCounter()
    {
        return counter;
    }
    //
    Stack()
    {
        counter++;
        tos=0;
        size=5;
        arr=new int[size];
        cout<<"ctor"<<endl;
    }
    Stack(int _size)
    {
        counter++;
        tos=0;
        size=_size;
        arr=new int[size];
        cout<<"ctor"<<endl;
    }
    ~Stack() //Important
    {
        counter--;
        //useless 
        for (int i = 0; i < size; i++)
        {
            arr[i]=-1;
        }
        //
        delete[] arr;
        cout<<"Stack dest called"<<endl;
    }
    ///Stack Functions
    void Push(int value)
    {
        //if(tos!=size)
        if(!IsFull())
        {
            arr[tos]=value;
            tos++
        }
        else
        {
            cout<<"FULL !!!!"<<endl;
        }
    }
    int Pop()
    {
        int result;
        //if(tos!=0)
        if(!IsEmpty())
        {
            tos--;
            result=arr[tos];
            return result;
        }
        else
        {
            cout<<"EMPTY!!!!";
            return -1234; //not Effective
            //throw runtime error
        }
    }
    int IsFull()
    { return tos==size; }
    int IsEmpty()
    { return tos==0;}
    ///
    //
    friend void ViewStack(Stack param);
    //  
};

//for tracing purpose
//standalone function to print
//stack data without change it
void ViewStack(Stack param)
{
    for (int i = 0; i < param.tos; i++)
    {
        cout<<param.arr[i]<<endl;
    }
} 


static variable initialization ONLY
regardless it is privte or not


int Stack::counter=0;


//
int main()
{
    Stack s1,s2(10),s3;
    
    cout<< s1.counter; //3  //not make sense //c++ ,java
    //after private
    cout<< Stack::counter; //3 //compile Error
    Stack::counter=333; //compile Error

    cout<< s1.GetCounter(); //3  //not make sense
    cout<< Stack::GetCounter(); //3
}

class Student{
    
    private:
    
    int RrollNumber;
    
    string Name;

    static int totalStudent =0 ;


    static int SettotalStudent(int _num){
        return totalStudent =_num;
    }

    Student(){
        totalStudent++;
    } 
    
    }

int main()
{
    Student s1,s2;
    
    cout<< s1.totalStudent; 
    
    cout<< Student::totalStudent; 
    
    Student::totalStudent=333;           

}
/////////////////////////////////////////////////
//Static Variable in c++ inside class/struct
///Static Variable, class variable ,shared variable 
//in class in cPP
///member variable with keyword static
///static variable make o.s will create ONLY 
///one copy of it in BSS regardless # of object created
///static variable is alive till program ends

//static variable is accessed by className not object name

///////////////////////////////////////////////////////

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
///c3=StandaloneAddCom(c1,c2) ; pass VALUES
///count #of ctor against # of destructor 
//ctor
//ctor
//ctor
//dest
//dest
//dest
//dest
//dest
//dest
//dest

//////////////////////////////////////////////////////
//2- dynamic Stack with static counter
/////   and standalone viewstack(stack param) as a friend

//main
//Stack s1(10);
//s1.push(10);
//s1.push(20);
//s1.push(30);
//s1.push(40);
//s1.push(50);
//ViewStack(s1); //Pass by Values 10,20,30,40,50
//ViewStack(s1); //RUBBISH and runtime Error

//3- (Later) implement Queue with cPP

///////////////////////////////////////
///tomorrow ISA
///cpy ctor
///operator overloading
///OOR [Composition]