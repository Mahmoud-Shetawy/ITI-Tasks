//Copy Constructor
//operator overloading V1.0
////////////////////////////////////////////////
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
    //cpy ctor [USELESS]
    Complex(Complex& old)
    {
        cout<<"cpy ctor";
        this->real=old.real;
        img=old.img;
    }
    //
};
Complex AddComplex(Complex left,Complex right)
{
    Complex result;
    int tmp=left.GetReal()+right.GetReal();
    result.SetReal(tmp);
    result.SetImg(left.GetImg()+right.GetImg());
    return result;  
}

int main()
{
    Complex c1(3,4),c2(5,6),c3;
    c3=AddComplex(c1,c2); //Pass VALUES 3,4 , 5,6
    c3.Print(); //8+10i
    return 0;
}
//////////////////////////////////////////////////

class Stack
{
    private:
    int* arr;
    int size;
    int tos;
    public:
    //ctor
    Stack()
    {
        tos=0;
        size=5;
        arr=new int[size];
    }
    Stack(int _size)
    {
        tos=0;
        size=_size;
        arr=new int[size];
    }
    ~Stack()
    {
        delete[] arr;
    }

    //Stack Functions
    void Push(int value)
    {
        //if(tos!=size)
        if(!IsFull())
        {
            arr[tos]=value;
            tos++;
        }
        else
        {
            cout<<"FULL!!!";
        }
    }

    int Pop()
    {
        int result=-12345;
        //if(tos!=0)
        if(!IsEmpty())
        {
            tos--;
            result=arr[tos];
            //return result;
        }
        else
        {
            cout<<"EMPTY!!!";
            //return -12345;  //NOT EFFECTIVE
            //throw runtime error
        }
        return result;
    }

    int IsFull(){return tos==size;}
    int IsEmpty(){return this->tos==0;}

    //
    friend void ViewStack(Stack param);
    //

    //cpy ctor
    //this-> pointer carry address param
    //oldObject alias name for s1
    Stack(const Stack& oldObject)
    {
        cout<<"cpy ctor";
        this->tos=oldObject.tos;
        size=oldObject.size;
        this->arr=new int[size];
        for(int i=0;i<tos;i++)
        {
            this->arr[i]=oldObject.arr[i];
        }
    }
    //

    //
    Stack Reverse()
    {
        Stack result;

        return result;
    }
    //
};

//for learning purpose
//standalone fn to view Stack Data Without any change
void ViewStack(Stack param)
{
    for(int i=0;i<param.tos;i++)
    {
        cout<<param.arr[i]<<endl;
    }
}

int main()
{
    Stack s1(10);
    s1.Push(10);
    s1.Push(20);
    s1.Push(30);
    s1.Push(40);
    s1.Push(50);
    ViewStack(s1);  //pass by Value // bitwise copy  //or param call cpy ctor
    ViewStack(s1);
    //o/p
    //ctor s1
    //cpy ctor param
    //dest param
    //dest s1

    Stack s2(s1); //call cpy ctor
    Stack s3=s1;  //call cpy ctor

    // Stack s4;
    // s4=s1;


    Stack s5;

    s5=s1.Reverse();
    s5.Pop(); //10
}


////////////////////////////////////////////////////
//Copy Constructor  [if not exists [bitwise copy]]
//Copy [Constructor]:method called
// when we create object
//constructor method called automatically -we cannot call it-
//in three cases:
//1- pass object by value
//2- return object by value
//3- create object from object اصنع كائن بدلاله كائن اخر

///When cpy ctor IS MUST???
///When use class contains variable carries Address

///how to write cpy ctor explicitly

class Draft
{
    public:
    //this
    //oldObject
    Draft(Draft& oldObject)
    {

    }
};

/////////////////////////////////////////////////////
//operator overloading
///in c++ operartors can be overloaded
//you can overload fn as a member or stand alone fn
int main()
{
    int x=3,y=4,z;
    double a=3,b=4,c;

    z=x+y;
    c=a+b;

    //compiler call
    //int operator+(int left,int right){}
    //double operator+(double left,double right){}
    //Complex operator+(Complex left,Complex right){}

    Complex c1(3,4),c2(5,6),c3;
    c3=AddComplex(c1,c2);
    c3=c1+c2; //compile error
    //search on   operator+(complex,Complex)

    return 0;
}


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
    //cpy ctor [USELESS]
    Complex(Complex& old)
    {
        cout<<"cpy ctor";
        this->real=old.real;
        img=old.img;
    }
    //

    //c1+c2
    Complex operator+(const Complex& right)
    {
        Complex result;
        result.real=real+right.real;
        result.img=this->img+right.img;
        return result;
    }

    //c1+=c2  //c1+=c2+=c3+=c4
    Complex operator+=(const Complex& right)
    {
        this->real=real+ right.real;
        img+=right.img;
        return *this;  //return by value
    }

    //++c1
    Complex operator++()
    {
        real++;
        return *this;
    }

    //c1++
    Complex operator++(int)
    {
        // //
        // Complex result(real,img);
        // //
        Complex result(*this);
        real++;
        return result; //3+4i
    }

    //c1+10
    Complex operator+(int _num)
    {
        //Complex result(real+_num,img);
        Complex result(*this);
        result.real+=_num;
        return result
    }

    //(int)c1
    operator int()
    {
        return real;
    }

    //c1>c2
    int operator>(Complex right)
    {
        return real>right.real && img>right.img;
    }

    //USELESS
    //= operator is exists [membercopy] c1=c2=c3
    Complex& operator=(const Complex& right)
    {
        real=right.real;
        img=right.img;
        return *this;
    }
    //


};
//10+c1 -> caller is not Complex
Complex operator+(int _num,Complex right)
{
    Complex result;
    result.SetReal(right.GetReal()+_num);
    result.SetImg(right.GetImg());
    return result;

    return right+_num;  ///right.operator+(_num)
}
//

int main()
{
    Complex c1(3,4),c2(5,6),c3;

    //c3=c1+c2;  //Standalone call  operator+(c1,c2);
    
    
    //c3=c1+c2;  //member call  c1.operator+(c2);
    //c1+=c2;  //c1.operator+=(c2)
    
    //c3=++c1;
    //c3=c1++;
    
    //c3=c1+10;

    //c3=10+c1;

    //casting
    //int z=(int)c1;
    //if( c1>c2){}

    c1=c2; //member copy

    c1.Print(); //3+4i
    //c2.Print(); //5+6i
    c3.Print(); //13+4i
}



class Stack
{
    private:
    int* arr;
    int size;
    int tos;
    public:
    //ctor
    Stack()
    {
        tos=0;
        size=5;
        arr=new int[size];
    }
    Stack(int _size)
    {
        tos=0;
        size=_size;
        arr=new int[size];
    }
    ~Stack()
    {
        delete[] arr;
    }

    //Stack Functions
    void Push(int value)
    {
        //if(tos!=size)
        if(!IsFull())
        {
            arr[tos]=value;
            tos++;
        }
        else
        {
            cout<<"FULL!!!";
        }
    }

    int Pop()
    {
        int result=-12345;
        //if(tos!=0)
        if(!IsEmpty())
        {
            tos--;
            result=arr[tos];
            //return result;
        }
        else
        {
            cout<<"EMPTY!!!";
            //return -12345;  //NOT EFFECTIVE
            //throw runtime error
        }
        return result;
    }

    int IsFull(){return tos==size;}
    int IsEmpty(){return this->tos==0;}

    //
    friend void ViewStack(Stack param);
    //

    //cpy ctor
    //this-> pointer carry address param
    //oldObject alias name for s1
    Stack(const Stack& oldObject)
    {
        cout<<"cpy ctor";
        this->tos=oldObject.tos;
        size=oldObject.size;
        this->arr=new int[size];
        for(int i=0;i<tos;i++)
        {
            this->arr[i]=oldObject.arr[i];
        }
    }
    //

    //
    Stack Reverse()
    {
        Stack result;

        return result;
    }
    //

    //s2=s1
    Stack operator=(const Stack& right)
    {
        //REMEMBER
        delete[] this->arr;
        //
        tos=right.tos;
        size=right.size;
        arr=new int[size];
        for (int i = 0; i < tos; i++)
        {
            arr[i]=right.arr[i];
        }
        //REMEMBER
        return *this;
        //
    }
    //s1==s2
    int operator==(Stack right){}
    //
};

//for learning purpose
//standalone fn to view Stack Data Without any change
void ViewStack(Stack param)
{
    for(int i=0;i<param.tos;i++)
    {
        cout<<param.arr[i]<<endl;
    }
}
int main()
{
    Stack s1(10),s2;
    s1.Push(10);s1.Push(20);
    s1.Push(30);s1.Push(40);
    s1.Push(50);s1.Push(60);
    s1.Push(70);

    s2=s1;  //member copy


    Stack s4(s1); //cpy ctor
    Stack s5=s1; //cpy ctor

    Stack s6;
    s6=s5; //= operator
    return 0;
}


///////////////////////////////////////////////
//Lab Assignment
//Complex
//1- Complex
    //cpy ctor useless
    //c1+c2
    //c1+=c2
    //++c1
    //c1++
    //c1+10
    //c1>c2
    //(int)c1
    //c1=c2  useless

//10+c1


//2- Stack
    //cpy ctor  MUST
    //= operator MUST
    //Stack reverseStack()
    //==
    //if(s1==s2){}
    //s3=s1+s2



