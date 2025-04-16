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
