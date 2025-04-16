//Copy Constructor
//operator overloading V1.0
////////////////////////////////////////////////
#include<iostream>
using namespace std;
class Complex
{
    private:
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
    //cpy ctor [useless]
    Complex(Complex& oldObj)
    {
        this->real=oldObj.real;
        this->img=oldObj.img;
        cout<<"cpy ctor";
    }
    //
    ~Complex()
    {
        //For tracing purpose
        cout<<"Dest";
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
    friend Complex AddComplex(Complex left,Complex right);
};
Complex AddComplex(Complex left,Complex right)
{
    Complex retVal;
    retVal.real=left.real+right.real;
    retVal.setReal(left.getReal()+right.getReal());
    retVal.setImg(left.getImg()+right.getImg());
    return retVal;
    //return by value  tmp anonymous object
}

int main()
{
    Complex c1(3,4),c2(5,6),c3;

    c3=AddComplex(c1,c2); //PASS VALUES

    return 0;
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
        return retVal;   
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
    Stack s1(10);
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);

    printStack(s1); //pass object by VALUES  bitwise copy
    printStack(s1);

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

//how to write cpy ctor explicitly
class Trial
{
    public:
    //this   -> object will be created
    //oldObj ->ref from object being copied
    
    
    //this-> param
    //oldObj -> t1
    Trial(Trial& oldObj)
    {
        //????
    }
};
void TryMe(Trial param)
{

}
int main()
{
    Trial t1;
    TryMe(t1);  //pass object by value //1- bitwise copy  //2- call cpy ctor if exists
}

//////////////////////////////////////////////////////
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
    //
    //cpy ctor
    //this->  pointer to param [new object]
    //oldObj -> reference to s1
    Stack(const Stack& oldObj)
    {
        cout <<"cpy ctor";
        (*this).tos=oldObj.tos;
        size=oldObj.size;
        this->arr=new int[size];
        for(int i=0;i<oldObj.tos;i++)
        {
            this->arr[i]=oldObj.arr[i];
        }
        //oldObj.tos=444;
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
        return retVal;   
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
    Stack s1(10);
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);

    printStack(s1); //pass object by VALUES  bitwise copy
    printStack(s1);

    Stack s3(s1);  //cpy ctor
    return 0;
}

///////////////////////////////////////////////
//operators on objects

//operators can be overloaded on objects
//operartos as a function can be written as member or standalone fn

#include<iostream>
using namespace std;
class Complex
{
    private:
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
    //cpy ctor [useless]
    Complex(Complex& oldObj)
    {
        this->real=oldObj.real;
        this->img=oldObj.img;
        cout<<"cpy ctor";
    }
    //
    ~Complex()
    {
        //For tracing purpose
        cout<<"Dest";
    }
    
    //
    void printComplex()
    {
        cout<<real<<"+"<<img<<"i";
    }
    
    //operators overloading
    //caller??? c1 3,4    c2 5,6
    //c1+c2
    Complex operator+(const Complex& right)
    {
        Complex retVal;
        retVal.real=real+right.real;
        retVal.img=img+right.img;
        return retVal;
        //Complex retVal(real+right.real,img+right.img);
        //return retVal;
    }

    //c1+=c2
    Complex& operator+=(const Complex& right)
    {
        this->real+=right.real;
        this->img=img+right.img;
        return *this; //retrn c1
        //return by value => bitwise copy or call cpy ctor for tmp object
        //return by reference -> no call for tmp object
    }

    //++c1
    Complex& operator++()
    {
        real++;
        img++;
        return *this;
    }

    //postfix
    //c1++
    Complex operator++(int ISLAM)
    {
        //Complex retVal(*this);
        Complex retVal(this->real,this->img);//retval 3 4
        real++;
        img++;
        return retVal;
        //unreachable code
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
        return real>right.real && img>right.img;
    }

    //c1=c2  [USELESS]
    Complex& operator=(const Complex& right)
    {
        real=right.real;
        img=right.img;
        return *this;
    }
    //(int)c1
    /*int*/operator int()
    {
        return real;
    }
    operator float(){}
    //

};

// //You've to create it as stand alone
//10+c1
Complex operator+(int num,Complex right)
{
    Complex retVal;//(right.real+num,right.img);
    retVal.setReal(right.getReal()+num);
    retVal.setImg(right.getImg());
    return retVal;

    //return right+num;
}


// //

int main()
{
    int x=3,y=4,z;
    double a=1,b,2,c;
    z=10;
    c=a+b;
    z=x+y; //compiler call
    //int  operator+(int left,int right);
    //double  operator+(double left,double right);
    //Complex operator+(Complex left,Complex right);
    //int operator=(int param);

    Complex c1(3,4),c2(5,6),c3;

    c3=AddComplex(c1,c2);
    c3=c1.add(c2);
    c3=c1+c2; //compile Error search on operator+(Complex left,Complex right)
    //compiler will search on
    //standalone fn
    //Complex operator+(Complex left,Complex right){}
    //or member fn 
    //Complex operator+(Complex right){}
    c3=c1+c2;
    //if standalone -> operator+(c1,c2)
    //if member ->    c1.operator+(c2)
    return 0;
}


int main()
{
    Complex c1(3,4),c2(5,6),c3;
    //c3=c1+c2;  //c1.op+(c2)

    //c1+=c2; //c1.operator+=(c2)

    //c3=++c1; //increment real ,img by one  c1.operator++()
    
    //c3=c1++;

    //c3=c1+10;  //c1.operator+(int right)

    //c3=10+c1;  //10.operator+(c1)

    //if(c1>c2){}

    //c1=c2;  //bitwise copy

    //Casting
    int x=c1;
    int y=(int)c1;

    c1.printComplex(); //4 5
    c3.printComplex(); //3,4
    return 0;
}

///////////////////////////////////////////////////
//operators on Stack
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
    //
    //cpy ctor
    //this->  pointer to param [new object]
    //oldObj -> reference to s1
    Stack(const Stack& oldObj)
    {
        cout <<"cpy ctor";
        (*this).tos=oldObj.tos;
        size=oldObj.size;
        this->arr=new int[size];
        for(int i=0;i<oldObj.tos;i++)
        {
            this->arr[i]=oldObj.arr[i];
        }
        //oldObj.tos=444;
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
        return retVal;   
        //tmp anonymous object
    }

    //s2=s1   -> is must
    Stack& operator=(const Stack& right)
    {
        delete[] this->arr;   //avoid memory leackage
        this->tos=right.tos;
        this->size=right.size;
        this->arr=new int[size];
        for(int i=0;i<tos;i++)
        {
            arr[i]=right.arr[i];
        }
        return *this;  //return by value call cpy ctor for tmp anonymous object
    }
    //


    friend void printStack(Stack param);
};
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
    Stack s1(10);
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);

    Stack s2(3);

    s2=s1;
}


//////////////////////////////////////////////////////
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


