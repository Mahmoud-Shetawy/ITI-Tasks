//Copy Constructor
//Operator Overloading V1.0
/////////////////////////////////////////////
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
    void printComplex()
    {
        cout<<real<<"+"<<img<<"i";
    }
    Complex addComplex(Complex right)
    {
        Complex retVal;
        retVal.real=this->real+right.real;  
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
    ///NOT RECOMMENDED
    //friend Complex subComplex(Complex left,Complex right);

    //cpy ctor  USELESS
    Complex(const Complex& old)
    {
        this->real=old.real;
        this->img=old.img;
        cout<<"ctor"<<endl;
    }
    //


};
Complex subComplex(Complex& left,Complex& right)
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
    c3=c1.addComplex(c2);
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
    Stack reverseStack()
    {
        Stack retVal;
        //for loop go upword  //do it in lab
        return retVal;   //call cpy ctor
        //tmp anonymous object
    }
    friend void printStack(Stack param);

    ///copy Ctor
    Stack(const Stack& old)
    {
        //this param  , old s1
        this->tos=old.tos;
        this->size=old.size;
        this->arr=new int[size];
        for(int i=0;i<tos;i++)
        {
            this->arr[i]=old.arr[i];
        }
    }
    ///
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
    Stack s1(5);//,s2,s3;
    s1.push(10);
    s1.push(20);
    s1.push(30);

    //s3=s1.reverseStack();
    
    printStack(s1);
    printStack(s1);
    //pass VALUES
    //o/p
    //ctor s1
    //cpy ctor param
    //dest param
    //cpy ctor param
    //dest param
    //dest s1


    Stack s4(s1); 
}
////////////////////////////////////////////
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
    int x;
    public:
    //funtwo
    //this-> tmp anonymous object
    //old -> retVal

    ///funone
    ///this -> param
    ///old -> obj
    Trial(/**this*/Trial& old)
    {
        cout hello;
    }
};

void FunOne(Trial param)
{}

Trial FunTwo()
{
    Trial retVal;
    return retVal;   //return VALUe
}

main()
{
    Trial obj;
    //FunOne(obj);  //pass VALUE

    obj= FunTwo();


    Trial o2(obj);
}


////////////////////////////////////////////////
///Operator Overloading
//Operators  c++ can be overloaded
//+
//operator overloading can
// be member and standalone function

// int x=3,y=4,z;
    // z=x+y;     int operator+(int left,int right)
    // ///Compiler call operator+ function
    // //int operator+(int left,int right){}  
    // //float operator+(float left,float right){}  
    
    // //Complex operator+(Complex left,Complex right){}

    class Draft
    {
        int x,y;
        public:
        Draft operator+(Draft right)
        {

        }
    };
    //
    Draft operator+(Draft left ,Draft right)
    {

    }
    //

    int main()
    {
        Draft d1,d2,d3;
        d3=d1+d2;  //Ambiguty   //Compile Error
    }



//////////////////////////////////////////////////////

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
    void printComplex()
    {
        cout<<real<<"+"<<img<<"i";
    }

    //cpy ctor  USELESS
    Complex(const Complex& old)
    {
        this->real=old.real;
        this->img=old.img;
        cout<<"ctor"<<endl;
    }
    //Operators
    //c1+c2
    Complex operator+(const Complex& right)
    {
        Complex retVal;
        retVal.real=this->real+right.real;
        retVal.img=img+right.img;
        return retVal;
    }

    //c1+=c2
    Complex& operator+=(/* *this */const Complex& right)
    {
        this->real=this->real+right.real;
        this->img+=right.img;
        return *this;  //return object by VALUE
        ///return typr
        //Complex  => create tmp object
        //Complex& => not create tmp object
    }
    //

    //++c1
    Complex& operator++()
    {
        real++;
        img++;
        return *this;
    }
    //c1++
    //Complex operator++(int dummy)
    Complex operator++(int) //caller c1 3,4
    {
        Complex retVal(this->real,this->img);
        real++;
        img++;
        return retVal;  //3,4
        //any code here is unreachable
    }

    //c1+10;
    Complex operator+(int num)
    {
        Complex retVal;
        retVal.real=real+num;
        retVal.img=img;  //REMEMBER
        //Complex retVal(real+num,img);
        return retVal;
    }

    //c1>c2
    int operator>(Complex right)
    {
        return this->real > right.real && this-> img>right.img;
    }

    //(int)c1
    operator int ()
    {
        return real;
    }

    //c1=c3  // USELESS
    Complex& operator=(const Complex& right)
    {
        real=right.real;
        this->img=right.img;
        return *this;
    }
};
//10+c1
operator+(int num,const Complex& right)
{
    Complex retVal(right.getReal()+num,right.getImg());
    return retVal;

    //return right+num;
}
//
int main()
{
    Complex c1(3,4),c2(5,6),c3;
    

    c3=c1;

    //casting
    //int x=c1;
    //int x=(int)c1;

    cout<<x; //3

    //if(c1>c2){}else{}

    //c3=10+c1;

    ///c3=c1+10;

    // c3=c1++;  //c1.operator++(int)
    // c1.printComplex();  //4+5i
    // c3.printComplex();  //3+4i

    // c3=++c1;  //c1.operator++()
    // c1.printComplex();  //4+5i
    // c3.printComplex();  //4+5i



    // c1+=c2;  //c1.operator+=(&c1,c2)
    // c1+=c2+=c3;
    // c1.printComplex();  //8+10i
    // c2.printComplex();  //5+6i
    
    
    //c3=c1+c2;  //c1.operator+(c2)   OR  operator+(c1,c2)
    //c1.printComplex(); //3+4i
    //c2.printComplex(); //5+6i
    //c3.printComplex(); //8+10i

    return 0;
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
    Stack reverseStack()
    {
        Stack retVal;
        //for loop go upword  //do it in lab
        return retVal;   //call cpy ctor
        //tmp anonymous object
    }
    friend void printStack(Stack param);

    ///copy Ctor
    Stack(const Stack& old)
    {
        //this param  , old s1
        this->tos=old.tos;
        this->size=old.size;
        this->arr=new int[size];
        for(int i=0;i<tos;i++)
        {
            this->arr[i]=old.arr[i];
        }
    }
    ///

    ////operator=
    Stack& operator=(const Stack& right)
    {
        //REMEMBER
        delete [] this-> arr;
        this->tos=right.tos;
        size=right.size;
        arr=new int [size];
        for(int i=0;i<tos;i++)
        {
            arr[i]=right.arr[i];
        }
        //REMEMBER
        return *this;
    }
    ////
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
    Stack s1(10),s2(5);
    s1.push(10);
    s1.push(20);
    s1.push(30);

    s2=s1;

    cout<< s1.pop();  //30 
    cout<< s2.pop();  //###

    return 0;
}



///////////////////////////////////////////////
///Lab
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

////////////////

//2- Stack
    //cpy ctor  MUST
    //= operator MUST
    //s1+s2
    //Stack reverseStack()

    ///s3=s1+s2;  //concatenation
    ///if(s1==s2){ALL}