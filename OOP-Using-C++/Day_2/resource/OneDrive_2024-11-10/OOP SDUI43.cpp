#include<iostream>
using namespace std;

struct Employee
{
    //data Fields
    private:
    int id;
    int age;
    float salary;

    public:
    //setters&getters function
    void Ali(int _x)
    {
        id=_x;
    }

    void Print()
    {
        cout<<id<<endl;
        cout<<age<<endl;
        cout<<salary<<endl;
    }
};


int main()
{
    Employee e1;
    e1.age=22;  //violation of OOP
    e1.Print();
    return 0;
}


///////////////////////////////////////////////////
//private: member can be accessed inside class/struct ONLY
//public:member can be accessed inside and outside class/struct ONLY
//Any member can be acceseed by object name
///////////////////////////////////////////////////
struct Employee
{
    //Data fields
    private:
    int id;
    int age;
    float salary;
    //setters&getters
    public:
    void setId(int _id)
    {
        //private field in setter must come in LVALUE
        id=_id;
    }
    int getId()
    {
        return id;
    }
    void setAge(int _age){
        age=_age;
    }
    int getAge()
    {
        return age;
    }
    void setSalary(float _salary)
    {
        if(_salary>=1200&&_salary<=8000)
        {
            salary=_salary;
        }
        else
        {
            salary=1200;
        }
    }
    float getSalary()
    {
        return salary;
    }

    void print()
    {
        cout<<"id is "<<id<<endl;
        cout<<"age is "<<age<<endl;
        cout<<"salary is "<<salary<<endl;
    }
};

int main()
{
    Employee e1,e2,e3;//instance/object from employee //12B
    //e1.id=22; //Compile Error //Inaccessible

    e1.setId(1);
    e1.setAge(22);
    e1.setSalary(1234);

    cout<<"id is "<<e1.getId()<<endl;
    cout<<"age is "<<e1.getAge()<<endl;
    cout<<"salary is "<<e1.getSalary()<<endl;

    e1.print();

}


//////////////////////////////////////////////
//
class Complex
{
    private:
        int real;
        int img;
    public:
        void setReal(int _real)
        {
            real=_real;
        }
        int getReal()
        {return real;}
        void setImg(int _img)
        {img=_img;}
        int getImg()
        {return img;}
        void printComplex()
        {
            cout<<real<<"+"<<img<<"i"<<endl;
        }

        Complex Add(Complex right)
        {
            //caller c1 //right c2
            Complex retVal;
            retVal.real=/*caller*/real+right.real;
            retVal.img=/*caller*/img+right.img;
            return retVal; 
            //return value
        }
};

Complex Sub(Complex left,Complex right)
{
    Complex retVal;
    //retVal.real=left.real-right.real;
    retVal.setReal(left.getReal()-right.getReal());
    retVal.setImg(left.getImg()-right.getImg());
    return retVal;
}

int main()
{
    Complex c1,c2,c3;

    c1.setReal(1);
    c1.setImg(2);
    c2.setReal(3);
    c2.setImg(4);

    c1.printComplex();
    c2.printComplex();

    //c1.Add(c1,c2); //passing values
    
    c3= c1.Add(c2);
    c3.printComplex();


    c3=Sub(c1,c2);
    c3.printComplex();

}

/////////////////////////////////////////////////
///Any member function 
//has hidden inpuut parameter called className *this

struct Employee
{
    //Data fields
    private:
    int id;
    int age;
    float salary;
    //setters&getters
    public:
    void setId(/*Employee *this,*/int _id) 
    {
        (*this).id=_id;
        this->id=_id;
        id=_id;
    }
    int getId(/*Employee *this,*/)
    {
        return this->id;
    }
    void setAge(/*Employee *this,*/int _age){
        (*this).age=_age;
    }
    int getAge(/*Employee *this,*/)
    {
        return age;
    }
    void setSalary(/*Employee *this,*/float _salary)
    {
        if(_salary>=1200&&_salary<=8000)
        {
            this->salary=_salary;
        }
        else
        {
            this->salary=1200;
        }
    }
    float getSalary(/*Employee *this,*/)
    {
        return salary;
    }

    void print(/*Employee *this,*/)
    {
        cout<<"id is "<<this->id<<endl;
        cout<<"age is "<<(*this).age<<endl;
        cout<<"salary is "<<salary<<endl;
    }
};

int main()
{
    Employee e1,e2,e3;
    e1.setId(2); //Compiler Employee::setId(&e1,2);
}


////////////////////////////////////////////////////////

class Complex
{
    private:
        int real;
        int img;
    public:
        void setReal(/*Complex*this*/int _real)
        {
            this->real=_real;
        }
        int getReal() const
        {return real;}
        void setImg(int _img)
        {img=_img;}
        int getImg() const 
        {return img;}
        void printComplex()
        {
            cout<<real<<"+"<<img<<"i"<<endl;
        }

        Complex Add(const Complex& right)
        {
            //caller c1 //right c2
            Complex retVal;
            retVal.real=this->real+right.real;
            retVal.img=this->img+right.img;
            //issue
            right.img=-1234;
            //
            return retVal; 
            //return value
        }
};

//standalone fn has no *this
Complex Sub( const Complex& left,const Complex& right)
{
    Complex retVal;
    //retVal.real=left.real-right.real;
    retVal.setReal(left.getReal()-right.getReal());
    retVal.setImg(left.getImg()-right.getImg());
    //ISSUE
    right.setReal(-1234);
    //
    return retVal;
}


int main()
{
    Complex c1,c2,c3;

    c1.setReal(1);
    c1.setImg(2);
    c2.setReal(3);
    c2.setImg(4);

    c1.printComplex();
    c2.printComplex();

    //c1.Add(c1,c2); //passing values
    
    c3= c1.Add(c2);
    c3.printComplex();


    c3=Sub(c1,c2);
    c3.printComplex();

}
///////////////////////////////////////////////////
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



#include<iostream>
using namespace std;

int Add(int x,int y){return x+y;}
int Add(int x,int y,int z){return x+y+z;}
int Add(float x,float y){return 1.2;}
int main()
{
    int a=10,b=20;
    int res=Add(a,b); //pass values

    res=Add(11,22,33);
    return 0;
}

/////////////////////////////////////////
//default arguments
#include<iostream>
using namespace std;

int Add(int x=0,int y=0,int z=0){return x+y+z;}

int main()
{
    cout<< Add(1,2,3);  // 6
    cout<< Add(1,2);  // 3
    cout<< Add(1);  // 1
    cout<< Add();  // 0

    return 0;
}
//V02
#include<iostream>
using namespace std;

int Add(int x,int y=0,int z=0){return x+y+z;}

int main()
{
    cout<< Add(1,2,3);  // 6
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

    cout<< Add(1,2);
    return 0;
}

/////////////////////////////////////////////////////
class Complex
{
    private:
        int real;
        int img;
    public:
        void setReal(/*Complex*this*/int _real)
        {
            this->real=_real;
        }
        int getReal() const
        {return real;}
        void setImg(int _img)
        {img=_img;}
        int getImg() const 
        {return img;}
        void printComplex()
        {
            cout<<real<<"+"<<img<<"i"<<endl;
        }

        Complex Add(const Complex& right)
        {
            //caller c1 //right c2
            Complex retVal;
            retVal.real=this->real+right.real;
            retVal.img=this->img+right.img;
            //issue
            right.img=-1234;
            //
            return retVal; 
            //return value
        }
        //initiate object
        void Initiate()
        {
            this->real=img=0;
        }
        void Initiate(int _real,int _img)
        {
            this->real=_real;
            img=_img;
        }
        void Initiate(int num)
        {
            this->real=img=num;
        }
        //

        //Constructors
        Complex()
        {
            cout<<"Def ctor"<<endl;
            this->real=0;
            img=0;
        }
        Complex(int _real,int _img)
        {
            cout<<"2P ctor"<<endl;
            real=_real;
            img=_img;
        }
        Complex(int _num)
        {
            cout<<"1P ctor"<<endl;
            this->real=_num;
            img=_num;
        }
        //
        //Destructor
        ~Complex()
        {
            cout<< "Dest called"<<endl;
        }
        //
};

//standalone fn has no *this
Complex Sub( const Complex& left,const Complex& right)
{
    Complex retVal;
    //retVal.real=left.real-right.real;
    retVal.setReal(left.getReal()-right.getReal());
    retVal.setImg(left.getImg()-right.getImg());
    //ISSUE
    right.setReal(-1234);
    //
    return retVal;
}


int main()
{
    // Complex c1,c2,c3;
    // c1.Initiate(1,2);
    // c2.Initiate(3);
    // c3.Initiate();  

    Complex c1,c2(3,4),c3(5);  
    //o/p
    //def ctor
    //2p ctor
    //1p ctor
    //dest
    //dest
    //dest



}


/////////////////////////////
//Constructor:
// special function inside class/struct 
// implicitly exist
//will be called automatically -we cannot call it-
//Once we create object from that class/struct

//how to write explicit ctor?
//1- the same name of class/struct
//2- has no return type
//3- can be overloaded
//4- MUST be public   //[private]=>we cannot create object design patterns    

class Draft
{
    private:
    public:
    Draft()
    {

    }
    Draft(int x)
    {

    }

    ~Draft()
    {

    }
};

//Destructor:
//Special function inside class/struct will be 
//called automatically
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


//Main Usage of Destructor

//When to use destructor?
//1- dynamic allocation  [heap]
//2- connect to db
//3- read/write from file


class Draft
{
    private:
    int * ptr;
    public:
    Draft()
    {
        ptr=new int[10];
    }

    ~Draft()
    {
        delete [] ptr;
    }
};
void TryMe()
{
    Draft d1;
}
int main()
{
    TryMe();
    TryMe();
    TryMe();

}



/////////////////////////////////////////

class Complex
{
    private:
        int real;
        int img;
    public:
        void setReal(/*Complex*this*/int _real);
        int getReal();
        void setImg(int _img);
        int getImg();
        void printComplex();

        Complex Add(const Complex& right);
        
        //initiate object
        void Initiate()
        {
            this->real=img=0;
        }
        void Initiate(int _real,int _img)
        {
            this->real=_real;
            img=_img;
        }
        void Initiate(int num)
        {
            this->real=img=num;
        }
        //

        //Constructors
        Complex()
        {
            cout<<"Def ctor"<<endl;
            this->real=0;
            img=0;
        }
        Complex(int _real,int _img)
        {
            cout<<"2P ctor"<<endl;
            real=_real;
            img=_img;
        }
        Complex(int _num)
        {
            cout<<"1P ctor"<<endl;
            this->real=_num;
            img=_num;
        }
        //
        //Destructor
        ~Complex()
        {
            cout<< "Dest called"<<endl;
        }
        //
};

//standalone fn has no *this
Complex Sub( const Complex& left,const Complex& right)
{
    Complex retVal;
    //retVal.real=left.real-right.real;
    retVal.setReal(left.getReal()-right.getReal());
    retVal.setImg(left.getImg()-right.getImg());
    //ISSUE
    right.setReal(-1234);
    //
    return retVal;
}


int main()
{
}


void Complex::setReal(int _real)
{
    real=_real;
}
        int Complex::getReal(){}
        void Complex::setImg(int _img){}
        



struct Trial
{
    int x;
}