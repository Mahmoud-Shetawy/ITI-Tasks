//Copy Constructor
//Operator Overloading V1.0
///////////////////////////////////////////////////////
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
    Complex(const Complex& old)
    {
        cout<<"cpy ctor";
        real=old.real;
        img=old.img;
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
    c3=subComplex(c1,c2);//pass VALUES

}

////////////////////////////////////////////////////
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
    }
    Stack(int _size)
    {
        cout<<"Stack Const";
        tos=0;
        size=_size;
        arr=new int[size];
    }

    //Cpy ctor
    ///this ->param
    ///old -> s1

    /// reverse Stack
    ///  this ->tmp
    ///  retval->old 
    Stack(const Stack& old)
    {
        cout<<"cpy ctor";
        this->tos=old.tos;
        size=old.size;
        arr=new int[size];
        for(int i=0;i<tos;i++)
        {
            arr[i]=old.arr[i];
        }
    }
    //
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
    Stack s1(5),s2,s3;
    s1.push(10);
    s1.push(20);
    s1.push(30);

    s3=s1.reverseStack();

    printStack(s1);
    printStack(s2);
    //pass VALUES


    Stack s4(s1);  //call cpy ctor
}


/////////////////////////////////////////////////////
//Copy Constructor
//Copy [Constructor]:method called
// when we create object
//constructor method called automatically -we cannot call it-
//in three cases:
//1- pass object by value
//2- return object by value
//3- create object from object اصنع كائن بدلاله كائن اخر

///When cpy ctor IS MUST???
///When use class contains variable carries Address


class Trial
{
    public:
    Trial(/*Trial* this,*/Trial& old)
    {}
};


/////////////////////////////////////////////////////
///Operator Overloading
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
    Complex(const Complex& old)
    {
        cout<<"cpy ctor";
        real=old.real;
        img=old.img;
    }
    //
    void printComplex()
    {
        cout<<real<<"+"<<img<<"i";
    }
    //operator Overloading
    //c1+c2
    Complex operator+(const Complex& right)
    {
        Complex retVal;
        retVal.real=real+right.real;
        retVal.img=img+right.img;
        return retVal;
    }
    //c1+=c2
    Complex& operator+=(const Complex& right)
    {
        real=real+right.real;
        img+=right.img;
        return *this;    //c1+=c2+=c3;
    }

    //++c1
    Complex& operator++()
    {
        real++;
        img++;
        return *this;
    }

    //c1++
    Complex operator++(/**/int)
    {
        Complex retVal(real,this->img);
        real++;
        img++;
        return retVal;  //original values
    }

    //c1+10
    Complex operator+(int num)
    {
        Complex retVal(real+num,img);
        return retVal;
    }
    //c1>c2
    int operator>(Complex right)
    {
        return this->real>right.real;
    }
    //(int)c1
    operator int()
    {
        return real;
    }

    //c1=c3   USELESS
    Complex& operator=(const Complex& right)
    {
        real=right.real;
        img=right.img;
        return *this;
    }
    //
};

//10+c1
Complex operator+(int num,Complex right)
{
    Complex retVal(right.getReal()+num,right.getImg());
    return retVal;

    //return right+num;
}

int main()
{
    Complex c1(3,4),c2(5,6),c3;
    //c3=c1+c2;
    //member fn  c1.operator+(c2)==> Complex::operator+(&c1,c2)
    //standalone   operator+(c1,c2)
    
    //c1+=c2;

    //c3=++c1;
    //c3=c1++;

    //c3=c1+10;

    //c3=10+c1;

    //if(c1>c2){}
    //else{}

    ////Casting
    //int z=c1;
    //z=(int)c1;

    c3=c1; //Normal Assignment assign VALUES

    c1.printComplex();//3 4
    //c2.printComplex();//5 6
    c3.printComplex();//13 4



    // Complex c1(3,4),c2(5,6),c3;
    // c3=c1+c2; //Compile Error
    // //no function named operator+(Complex,Complex)

    // int x=3,y=4,z;
    // z=x+y;   
    // ///Compiler call operator+ function
    // //int operator+(int left,int right){}  
    // //float operator+(float left,float right){}  
    // //Complex operator+(Complex left,Complex right){}  
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
    }
    Stack(int _size)
    {
        cout<<"Stack Const";
        tos=0;
        size=_size;
        arr=new int[size];
    }

    //Cpy ctor
    ///this ->param
    ///old -> s1

    /// reverse Stack
    ///  this ->tmp
    ///  retval->old 
    Stack(const Stack& old)
    {
        cout<<"cpy ctor";
        this->tos=old.tos;
        size=old.size;
        arr=new int[size];
        for(int i=0;i<tos;i++)
        {
            arr[i]=old.arr[i];
        }
    }
    //
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

    //s2=s1
    Stack& operator=(const Stack& right)
    {   
        //REMEMBER
        delete[] this->arr;
        this->tos=right.tos;
        this->size=right.size;
        arr=new int[size];
        for(int i=0;i<tos;i++)
        {
            this->arr[i]=right.arr[i];
        }
        //REMEMBER
        return *this;
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
    Stack s1(10),s2(5),s3;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);

    s2.push(77);
    s2.push(88);

    s2=s1;  
    //Without operator=   
    ///Compiler will do memberwise copy

    s3=s1+s2;   ///Concatenation
}

///REMEMBER
//When create class contains variables carry address
///THis class MUST Contains also
/////Copy ctor
/////= operator 


///////////////////////////////////////////////////////
//Lab Assignments

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
    //s1+s2
    //Stack reverseStack()
