//Copy Constructor
//operator overloading V1.0
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
    Complex (const Complex &old )
    {
        //may be useless here
        cout<<"ctor";
        this->real=old.real;
        this->img=old.img;
    }
    ~Complex()
    {
        //For tracing purpose
        cout<<"Dest";
    }
    void printComplex()
    {
        cout<<real<<"+"<<img<<"i";
    }
    Complex addComplex(Complex right)
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
    //friend Complex subComplex(Complex left,Complex right);
};
Complex subComplex(Complex left,Complex right)
{
    Complex retVal;
    retVal.setReal(left.getReal()-right.getReal());
    retVal.setImg(left.getImg()-right.getImg());
    return retVal;
    //return by value  tmp object
}

int main()
{
    //#1
    Complex c1,c2(3,4),c3;
    //#2  passing by value
    //c3=c1.addComplex(c2);//Complex::addComplex(&c1,c2);  
                        //=> fn in class addComplex(*this,right);

    //#3
    c3=subComplex(c1,c2);  //passing 2 objects by value
    return 0;
}


//
int Add(int x,int y)
{
    int retval;
    //
    return retval;
}
main()
{
    int a=10,b=20;    //memory  a  b  c   xa   yb  retval  tmpVariable[retVal]   
    int c=Add(a,b);
}
//


//////////////////////////////////////////////////////////////
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
    //this new object param   ,old =>s1
    //this new object tmp   ,old =>retVal
    Stack(const Stack &old)//10 20 30 40 50  without &endless loop
    {
        cout<<"ctor";
        this->tos=old.tos;
        this->size=old.size;
        //VIP
        this->arr=new int[size];
        for(int i=0;i<tos;i++)
        {
            arr[i]=old.arr[i];
        }
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
void printStack(Stack param) //call cpy ctor
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
    //#4
    Stack s1,s2(10);
    s1=s2;   //memberwise copy
    //push 10,20,30,40,50 in both of objects

    //#5
    //printStack(s1);  //pass by ??? VALUE
    //printStack(s1);  //-1-1-1-1-1-1   -1 0 0 termitated  Rubbish

    //#6
    //Stack s3;
    //s3=s1.reverseStack();  //50 40 30 20 10



    //#7 with cpy ctor
    //printStack(s1); ///pass by value
    //printStack(s1);


    //#8 with cpy ctor
    //Stack s3;
    //s3=s1.reverseStack();  //return object by value

    Stack s3(s1); //call cpy ctor //this new object=>s3    old=>s1


    return 0;
}


////////////////////////////////////////////////////////////
//Copy [Constructor]:method called when we create object
//constructor method called automatically -we cannot call it-
//in three cases:
//1- pass object by value
//2- return object by value
//3- create object from object اصنع كائن بدلاله كائن اخر

className(Reference of same class)
class ABC
{
    ABC(ABC& old)  //ABC(new object will be created *this ,ABC& old)
    {

    }
};


////////////////////////////////////////////////////////////////
//Operators  c++ can be overloaded
//+
//operator overloading can be member and standalone function
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
    Complex (const Complex &old )
    {
        //may be useless here
        cout<<"ctor";
        this->real=old.real;
        this->img=old.img;
    }
    ~Complex()
    {
        //For tracing purpose
        cout<<"Dest";
    }
    void printComplex()
    {
        cout<<real<<"+"<<img<<"i";
    }
    Complex addComplex(Complex right)
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
    //friend Complex subComplex(Complex left,Complex right);
    
    //operators overloading
    //this =>c1
    //right=>c2
    Complex operator+(const Complex& right)
    {
        /*this->real=this->real+right.real;
        this->img=this->img+right.img;   
        return *this;*/
        Complex retVal;
        retVal.real=real+right.real;
        retVal.img=img+right.img;
        return retVal;
    }
    Complex& operator+=(const Complex& right)
    {
        real+=right.real;
        img+=right.img;
        return *this;
    }
    //prefix
    Complex operator++()
    {
        real++;//this
        return *this;
    }
    //Postfix
    Complex operator++(int)
    {   
        //Complex retVal(real++,img);//Must use cpy ctor  =>Complex(complex)
        Complex retVal(*this);//Must use cpy ctor  =>Complex(complex)
        ++real;
        return retVal;
    }
    Complex operator+(int num)
    {
        Complex retVal;
        retVal.real=real+num;
        retVal.img=img;
        return retVal;
    }
    Complex operator>(Complex right)
    {
        //in right way
        return real>right.real && img>right.img;
    }

    //useless
    Complex operator=(Complex right)
    {
        real=right.real;
        img=right.img;
        return *this;
    }
    //
};

//
Complex operator+(int num,Complex right)
{
    Complex retVal;
    retVal.setReal(num+right.getReal());
    retVal.setImg(right.getImg);
    return retVal;

    //return right+num;//WORST in performance
}
//
Complex subComplex(Complex left,Complex right)
{
    Complex retVal;
    retVal.setReal(left.getReal()-right.getReal());
    retVal.setImg(left.getImg()-right.getImg());
    return retVal;
    //return by value  tmp object
}

//Not recommended
/*Complex operator+(Complex left,Complex right)
{
    Complex retVal;
    retVal.setReal(left.getReal()+right.getReal());
    retVal.setImg(left.getImg()+right.getImg());
    return retVal;
}*/

int main()
{
    Complex c1(1,2),c2(3,4),c3;

    
    int z=c1>c2;
    

    c3=c1;  //c3.operator=(c1)//equalize values
    
    c3=10+c1; //10.operator+(Complex) =>MUST Standalone
    //c1(1,2)
    //c3(11,2)


    c3=c1+10;  //c1.operator+(int 10)
    //c1(1,2)
    //c3(11,2)

    c3=c1++;
    //c3(1,2)
    //c1(2,2)    

    c3=++c1;
    //c1.operator++()
    //c3(2,2)
    //c1(2,2)


    c1+=c2;
    //c1.operator+=(c2)
    //c1(4,6)
    //c2(3,4)
    
    
    //c3=c1+c2;   //c1.operator+(c2)
    //c1(1,2)
    //c2(3,4)
    //c3(4,6)








    /*int x=10;
    int y=20;
    int z;
    z=x+y;   //x10  y20  z30
    //z=x.operator+(y);
    x++;
    //x.operator++();
    x+=y;
    //x.operator+=(y);
    Complex c1(1,2),c2(3,4),c3;
    c3=c1.addComplex(c2);   //c1(1,2)   c2(3,4)   c3(4,6)
    c3=c1+c2;
    //c1.operator+(c2)

    */
    //operator+(c1,c2)    c1.operator+(c2)

    return 0;
}


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

//Stack
//cpy ctor
//reverse stack 
//s3=s1.reversestack(); 

