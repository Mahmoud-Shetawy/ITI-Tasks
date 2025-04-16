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
    ~Complex()
    {
        //For tracing purpose
        cout<<"Dest";
    }
    //
    //cpy ctor [USELESSSSSSSSSS]
    Complex(const Complex& oldOne)
    {
        this->real=oldOne.real;
        this->img=oldOne.img;
        cout<<"cpy ctor";
    }
    //
    //
    void print()
    {
        cout<<real<<"+"<<img<<"i";
    }
    Complex add(Complex right)
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
    //friend Complex AddComplex(Complex left,Complex right);
};
Complex AddComplex(Complex left,Complex right)
{
    Complex retVal;
    //retVal.real=left.real+right.real;
    retVal.setReal(left.getReal()+right.getReal());
    retVal.setImg(left.getImg()+right.getImg());
    return retVal;
    //return by value  tmp anonymous object
}

int main()
{
    Complex c1(3,4),c2(5,6),c3;
    c3=AddComplex(c1,c2); //PaSSS VALUESSS 
    //bitwise copy
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
        //USELESS
        for(int i=0;i<size;i++)
        {
            arr[i]=-1;
        }
        //
        delete [] arr;
    }
 
    friend void ViewStack(Stack param);
};
//standalone function (Print Stack)
//standalone fn not contains this

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
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);
    ViewStack(s1); //pass values //Bitwise copy
    ViewStack(s1);
}
////////////////////////////////////////////////////////
////////////////////////////////////////////////////
//Copy Constructor  [if not exists [bitwise copy]]
//Copy [Constructor]:method called
// when we create object
//constructor method called automatically -we cannot call it-
//in three cases:
//1- pass object by value
//2- return object by value
//3- create object from object اصنع كائن بدلاله كائن اخر
//
//When cpy ctor IS MUST???
//When use class contains variable carries Address

//how to write cpy ctor explicitly
class Trial
{
    int *ptr;
    public:
    Trial(){}
    Trial(int _x){}
 
    Trial( Trial oldOne)
    {
        cout<<"Hello from cpy ctor"<<endl;
    }
};

void TryMe(Trial param)
{

}

int main()
{
    Trial obj;
    TryMe(obj); //pass by VALUES
    //o/p
    //def ctor obj
    //Hello from cpy ctor
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
    //
    //cpy ctor
    //this -> param  ,tmp anonymous object
    //oldOne-> reference from s1   ,result
    Stack(const Stack& oldOne)
    {
        this->tos=oldOne.tos;
        this->size=oldOne.size;
        this->arr=new int[size];
        for (int i = 0; i < tos; i++)
        {
            this->arr[i]=oldOne.arr[i];
        }
        cout<<"cpy ctor"<<endl;
    }
    //
    ~Stack()
    {
        cout<<"Stack Dest"<<endl;
        //USELESS
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
    Stack reverse()
    {
        Stack result(this->size);
        //for loop go upword  //do it in lab
        return result; 
        //return object By Value   
        //tmp anonymous object bitwise
        // copy from result
    }
    friend void ViewStack(Stack param);
};
//standalone function (Print Stack)
//standalone fn not contains this
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
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);
    ViewStack(s1); //pass valuess //Bitwise copy
    ViewStack(s1);


    Stack s2(s1); 
    //call cpy ctor -> this s2 ,oldOne  s1

    Stack s3;
    s3=s1.reverse();
    //s3.pop(); //10
}

////////////////////////////////////////////////////
///operator overloading
////operators can be overloaded
////overloaded fn can be member or standalone

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
    ~Complex()
    {
        //For tracing purpose
        cout<<"Dest";
    }
    //
    //cpy ctor [USELESSSSSSSSSS]
    Complex(const Complex& oldOne)
    {
        this->real=oldOne.real;
        this->img=oldOne.img;
        cout<<"cpy ctor";
    }
    //
    //
    void print()
    {
        cout<<real<<"+"<<img<<"i";
    }
    //
    //operators
    //c1+c2
    Complex operator+(const Complex& right)
    {
        Complex result;
        result.real=real+right.real;
        result.img=this->img+right.img;
        return result; //by value  -> cpy ctor -> tmp object
    }
    //c1+10
    Complex operator+(int _num)
    {
        Complex result(real+_num,img);
        return result;
    }
    //
    //++c1
    Complex& operator++()    //& avoid cpy ctor [faster]
    {
        real++;
        this->img++;
        return *this; //return object by value c1
    }
    //
    //c1++
    Complex operator++(int)
    {
        Complex result;
        result.real=this->real; //3
        result.img=this->img;  //4
        //
        this->real++;
        this->img++;
        //
        return result;  //3+4i
    }
    //
    //c1+=c2
    Complex& operator+=(const Complex& right)
    {
        real+=right.real;
        img+=right.img;
        return *this;
    }
    //
    //c1>c2
    int operator>(Complex right)
    {
        return this->real>right.real && this->img>right.img;
    }
    //
    //(int)c1
    operator int ()
    {
        return real;
    }
    //

    //useless c1=c3
    Complex& operator=(const Complex& right)
    {
        real=right.real;
        img=right.img;
        return *this;
    }
    //


};


//10+c1
Complex operator+(int _num,const Complex& right)
{
    Complex result;
    result.setReal(right.getReal()+_num);
    result.setImg(right.getImg());
    return result;
}
//

int main()
{
    int x=3,y=4,z;
    double a=3,b,4,c;
    z=x+y;  
    c=a+b;
    //int operator+(int left,int right){}
    //double operator+(double left,double right){}
    //Complex operator+(Complex left,complex right){}
    
    
    
    Complex c1(3,4),c2(5,6),c3;

    //c3=c1.Add(c2);
    //c3=AddComplex(c1,c2);
    //c3=c1+c2;   //Compile Error
    //Complex operator+(Complex left,complex right){}
    
    // c3=c1+c2;//  c1.operator+(c2) OR operator+(c1,c2)
    
    
    //c3=c1+10;

    //c3=++c1;
    
    //c3=c1++;

    //c3=10+c1;    //10.operator+(c1)

    //c1+=c2;  //c1.operator+=(c2)

    //if(c1>c2){}
    
    ///implicit casting
    int _real=(int)c1;
    _real=c1;


    c3=c1; //c3.operator=(c1) //Assign values //normal behavior

    c1.print(); //4+5i
    c3.print(); //3+4i

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
    //this -> param  ,tmp anonymous object
    //oldOne-> reference from s1   ,result
    Stack(const Stack& oldOne)
    {
        this->tos=oldOne.tos;
        this->size=oldOne.size;
        this->arr=new int[size];
        for (int i = 0; i < tos; i++)
        {
            this->arr[i]=oldOne.arr[i];
        }
        cout<<"cpy ctor"<<endl;
    }
    //
    ~Stack()
    {
        cout<<"Stack Dest"<<endl;
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
    Stack reverse()
    {
        Stack result(this->size);
        //for loop go upword  //do it in lab
        return result; 
        //return object By Value   
        //tmp anonymous object bitwise
        // copy from result
    }

    //s2=s1
    Stack& operator=(const Stack& right)
    {
        //Remember  -> to avoid memory leackage
        delete[] this->arr;

        this->tos=right.tos;
        this->size=right.size;
        this->arr=new int[size];

        for (int i = 0; i < tos; i++)
        {
            arr[i]=right.arr[i];
        }
        //REMEMBER
        return *this;
    }
    //

};

int main()
{
    Stack s1(10),s2;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);
    s1.push(60);

    s2=s1; //memberwise copy



    //
    Stack s3(s1); //cpy ctor
    
    Stack s4;
    s4=s1;    //= operator


    Stack s5=s1; //cpy ctor Stack s5(s1)
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






