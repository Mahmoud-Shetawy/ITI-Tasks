//Copy Constructor
//operator overloading V1.0
////////////////////////////////////////////////
#include<iostream>
using namespace std;
class Complex
{
    int real,img;
    public:
    void setReal(int _real){real=_real;}
    void setImg(int _img){img=_img;}
    int getReal(){return real;}
    int getImg(){return img;}
    Complex()
    {
        cout<<"ctor";
        real=img=0;
    }
    Complex(int _r,int _i)
    {
        cout<<"ctor";
        real=_r;
        img=_i;
    }
    ~Complex()
    {
        //For tracing purpose
        cout<<"Dest";
    }
    //cpy ctor=> useless code
    Complex(Complex& old)
    {
        this->real=old.real;
        img=old.img;
        cout<<"cpy ctor"<<endl
    }
    //
    void printComplex()
    {
        cout<<real<<"+"<<img<<"i";
    }
    Complex addComplex(/**/Complex right)
    {
        Complex retVal;
        retVal.real=this->real+right.real;  //(*this).real
        retVal.img=this->img+right.img;
        return retVal;
        //return by value
        //GCC Generate temporarily anonymous object
        //bitwise copy from retVal

        //Codeblocks
        //RVO   =>return value optimization  
        //prevent creattion tmp anonumous object
        
        //disable rvo  => -fno-elide-constructors

    }
    friend Complex subComplex(Complex left,Complex right);
};
Complex subComplex(Complex left,Complex right)
{
    Complex retVal;
    retVal.setReal(left.getReal()-right.getReal());
    retVal.setImg(left.getImg()-right.getImg());
    return retVal;
    //return by value  tmp anonymous object
}

int main()
{
    Complex c1(3,4),c2(5,6),c3;

    c3=subComplex(c1,c2); //passing VALUES

    //o/p
    //2p ctor c1
    //2p ctor c2
    //def ctor c3
    //cpy ctor left
    //cpy ctor right
    //def ctor retVal
    //cpy ctor tmp anonymous object
    //dest tmp
    //dest retval
    //dest right
    //dest left
    //dest c3
    //dest c2
    //dest c1

    
    return 0;
}

/////////////////////////////////////////////////////
class Stack
{
    int * arr;
    int tos;
    int size;
    public:
    Stack()
    {
        cout<<"Stack Const";
        tos=0;
        size=5;
        arr=new int[size];
        //size=5;
    }
    Stack(int _size)
    {
        cout<<"Stack Const";
        tos=0;
        size=_size;
        arr=new int[size];
    }

    ~Stack()
    {
        cout<<"Stack Dest"<<endl;
        //Redundant
        for(int i=0;i<size;i++)
        {
            arr[i]=-1;
        }
        //
        delete [] arr;
        
    }

    //Copy 
    //this => pointer to param [new object]
    //old  => s1 that is passed
    Stack(Stack& old)
    {   
        cout<<"cpy ctor";
        this->tos=old.tos;
        size=old.size;
        arr=new int[size];
        for(int i=0;i<tos;i++)
        {
            this->arr[i]=old.arr[i];
        }
    }
    //
    int isFull()
    {
        return tos==size;
    }
    int isEmpty() 
    {
        return tos==0;
    }
    void push(int num)
    {
        if(!isFull())
        {
            arr[tos]=num;
            tos++
        }
        else
        {
            cout<<"FULL !!!"<<endl;
        }  
    }
    int pop()
    {
        int retVal=-12345;
        if(!isEmpty())
        {
            tos--;
            retVal=arr[tos];
            //return retVal;
        }
        else
        {
            //cout<<"EMPTY !!!"<<endl;
        }
        return retVal;
        
    }
    Stack reverseStack()
    {
        Stack retVal;
        //for loop go upword  //do it in lab
        return retVal;   //call cpy ctor
        //tmp anonymous object
    }
    friend void printStack(Stack param);
};
//standalone function (Print Stack)
//standalone fn not contans this
void printStack(Stack param) 
{
    if(!param.isEmpty())
    {
        for(int i=0;i<param.tos;i++)
        {
            cout<<param.arr[i]<<endl;
        }
    }
}

int main()
{
    Stack s1(5);
    s1.push(10);
    s1.push(20);
    s1.push(30);

    printStack(s1);
    printStack(s1);


    //cpy ctor called
    Stack s4(s1);
    Stack s5=s1;  //Stack s5(s1)  //cpy ctor


    ///NO Cpy ctor
    Stack s6;
    s6=s1;

}


///////////////////////////////////////////////////
//Copy Constructor
//Copy [Constructor]:method called
// when we create object
//constructor method called automatically -we cannot call it-
//in three cases:
//1- pass object by value
//2- return object by value
//3- create object from object اصنع كائن بدلاله كائن اخر


class Draft
{
    public:
    Draft(Draft& old)
    {

    }
};

//////////////////////////////////////////////////
//Operators  c++ can be overloaded
//+
//operator overloading can
// be member and standalone function
#include<iostream>
using namespace std;
class Complex
{
    int real,img;
    public:
    void setReal(int _real){real=_real;}
    void setImg(int _img){img=_img;}
    int getReal(){return real;}
    int getImg(){return img;}
    Complex()
    {
        cout<<"ctor";
        real=img=0;
    }
    Complex(int _r,int _i)
    {
        cout<<"ctor";
        real=_r;
        img=_i;
    }
    ~Complex()
    {
        //For tracing purpose
        cout<<"Dest";
    }
    //cpy ctor=> useless code
    Complex(Complex& old)
    {
        this->real=old.real;
        img=old.img;
        cout<<"cpy ctor"<<endl
    }
    //
    void printComplex()
    {
        cout<<real<<"+"<<img<<"i";
    }
    
    //Operator overloading
    
    //c1+c2
    Complex operator+(/**this*/const Complex& right)
    {
        //
        //Complex tmp(real+right.real,img+right.img);
        //
        Complex retVal;
        retVal.real=this->real+right.real;
        retVal.img=img+right.img;
        return retVal;
    }

    //c1+=c2
    Complex& operator+=(const Complex& right)
    {
        this->real=real+right.real;
        img+=right.img;
        return *this;
    }

    //++c1
    Complex operator++()
    {
        real++;
        img++;
        return *this;
    }

    //c1++
    Complex operator++(int /*dummy*/)
    {
        Complex retVal(this->real,this->img);
        //Complex retVal(*this);  //3+4i
        this->real++;
        img++;
        return retVal;
    }

    //c1+10
    Complex operator+(int num)
    {
        Complex retVal;
        retVal.real=this->real+num;
        retVal.img=img;
        return retVal;
    }
    //c1>c2
    int operator>(Complex right)
    {
        return this->real>right.real&&img>right.img;
    }

    //c1==c2
    int operator==(Complex right)
    {
        return this->real==right.real&&img==right.img;
    }

    //c3=c1 => useless
    Complex& operator=(const Complex& right)
    {
        this->real=right.real;
        img=right.img;
        return *this;
    }

    //int x=(int)c1;
    operator int()
    {
        return this->real;
    } 
    //


    
};
//10+c1
Complex operator+(int num,Complex right)
{
    Complex retVal;
    retVal.setReal(num+right.getReal());
    retVal.setImg(right.getImg());
    return retVal;

    //return right+num;
}

//

int main()
{
    Complex c1(3,4),c2(5,6),c3;


    
    //
    //c3=c1+c2;   //c1.operator+(c2)
    //c1+=c2;  //c1.operator+=(c2)
    //c3=++c1;  //c1.operator++()
    //c3=c1++;  //c1.operator++()
    //c3=c1+10;  //c1.operator+(int num)
    //c3=10+c1;    //10.operator+(Complex)

    if(c1>c2)
    {}
    else
    {}
    
    c3=c1;  //memberwise copy

    //Casting
    int x=(int)c1;

    //c3 3+4i
    //c1 4+5i
    //

    int x=3,y=4,z;
    z=x+y;
    z=x;
    //Compiler
    int operator+(int left,int right);
    int operator=(int left,int right);
    //int operator+(int a,int b){} XXXX
    Complex operator+(Complex left,Complex right){}

}



//Draft
class Trial
{
    Trial operator+(Trial right){}
};
//
Trial operator+(Trial left,Trial right){}
//
int main()
{
    Trial t1,t2,t3;
    t3=t1+t2;
}
//

/////////////////////////////////////////////////////


class Stack
{
    int * arr;
    int tos;
    int size;
    public:
    Stack()
    {
        cout<<"Stack Const";
        tos=0;
        size=5;
        arr=new int[size];
        //size=5;
    }
    Stack(int _size)
    {
        cout<<"Stack Const";
        tos=0;
        size=_size;
        arr=new int[size];
    }

    ~Stack()
    {
        cout<<"Stack Dest"<<endl;
        //Redundant
        for(int i=0;i<size;i++)
        {
            arr[i]=-1;
        }
        //
        delete [] arr;
        
    }

    //Copy 
    //this => pointer to param [new object]
    //old  => s1 that is passed
    Stack(const Stack& old)
    {   
        cout<<"cpy ctor";
        this->tos=old.tos;
        size=old.size;
        arr=new int[size];
        for(int i=0;i<tos;i++)
        {
            this->arr[i]=old.arr[i];
        }
    }
    //
    int isFull()
    {
        return tos==size;
    }
    int isEmpty() 
    {
        return tos==0;
    }
    void push(int num)
    {
        if(!isFull())
        {
            arr[tos]=num;
            tos++
        }
        else
        {
            cout<<"FULL !!!"<<endl;
        }  
    }
    int pop()
    {
        int retVal=-12345;
        if(!isEmpty())
        {
            tos--;
            retVal=arr[tos];
            //return retVal;
        }
        else
        {
            //cout<<"EMPTY !!!"<<endl;
        }
        return retVal;
        
    }
    Stack reverseStack()
    {
        Stack retVal;
        //for loop go upword  //do it in lab
        return retVal;   //call cpy ctor
        //tmp anonymous object
    }
    friend void printStack(Stack param);


    //s1=s2
    Stack& operator=(const Stack& right)
    {
        //REMEMBER
        delete [] this->arr;
        this->tos=right.tos;
        size=right.size;
        arr=new int[size];
        for(int i=0;i<tos;i++)
        {
            this->arr[i]=right.arr[i];
        }

        //REMEMBER
        return *this;
    }

    //s3=s1+s2
    Stack operator+(const Stack& right)
    {
        Stack retVal(this->size+right.size);  //tos 0  size15 arr 0x55

        return retVal;
    }

    //s1==s2
    int operator==(Stack right)
    {

    }
    //
};
//standalone function (Print Stack)
//standalone fn not contans this
void printStack(Stack param) 
{
    if(!param.isEmpty())
    {
        for(int i=0;i<param.tos;i++)
        {
            cout<<param.arr[i]<<endl;
        }
    }
}

int main()
{
    Stack s1(5);
    s1.push(10);
    s1.push(20);
    s1.push(30);

    Stack s2(10);
    s2.push(100); 
    s2.push(200); 
    s2.push(300); 
    s2.push(400); 
    s2.push(500); 
    s2.push(600);

    s1=s2; ///call = operator

    Stack s3(s2); //call cpy ctor
    Stack s4=s3;  //call cpy ctor

    Stack s5=s1.reverseStack();
    s5=s3; // = operator

}


////////////////////////////////////////////////
//Lab 

//Complex
cpy ctor
= useless
+
-
++v
v++
c+=c2
c=c2+10
c=10+c3
>
< 
==
castint to int


//Stack
==
+
Reverse


