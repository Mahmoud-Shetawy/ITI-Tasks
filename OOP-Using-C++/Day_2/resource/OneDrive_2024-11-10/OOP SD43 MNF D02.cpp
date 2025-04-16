///*this
///const
///Function Overloading
///Default Arguments
///Constructor
///Destructor
//////////////////////////////////////////////////////
//in c++ struct === class
//except default access modifier
//class => private
//struct=> public
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//in any member function
//there is hidden input parameter
//called classname* this
#include<iostream>
using namespace std;
class Trial
{
    private:
    int x;
    int y;
    public:
    //caller -> obj
    void setX(/*Trial* this,*/int _x)
    {
        //(*this).x=_x;
        //this->x=_x;
        /*caller*/x=_x;   //Compiler this->x=_x;  (*this).x=_x;
    }
    int getX(/*Trial* this*/)
    {
        //return (*this).x;
        //return this->x;
        return /*caller*/x;
    }
    void setY(/*Trial* this,*/int _y)
    {
        this->y=_y;
    }
    int getY(/*Trial* this*/)
    {
        return (*this).y;
    }
    void printTrial(/*Trial* this*/)
    {
        cout<< x<< this->y<<endl;
    }
};

int main()
{
    Trial obj; //stack  //8B    //x#   //y#

    obj.setX(10);  //compiler Trial::setX(&obj,10);

}

/////////////////////////////////////////////////////
#include<iostream>
using namespace std;

class Complex
{
    private:
    int real;
    int img;
    public:
    void setReal(/*Complex* this,*/int _real){real=_real;}
    int getReal(){return (*this).real;}
    void setImg(/*Complex* this,*/int _img){this->img=_img;}
    int getImg(){return img;}
    //Print  c3
    void printComplex()
    {
        cout<<this->real<<"+"<<img<<"i"<<endl;
    }
    
    Complex addComplex(/*Complex* this,*/Complex right)
    {
        Complex retVal;
        retVal.real=/*caller*/real+right.real;
        retVal.img=/*caller*/img+right.img;
        return retVal;
    }
};
///Subtract Two Complex Numbers
///Stand alone Function
///called by its name 
Complex subComplex(Complex& left,Complex& right)
{
    Complex retVal;
    //retval.real=left.real-right.real; //Compile Error
    retVal.setReal(left.getReal()-right.getReal());
    retVal.setImg(left.getImg()-right.getImg());
    return retVal;    
}
///
int main()
{
    Complex c1,c2,c3;
    c1.setReal(3);
    c1.setImg(4);
    c2.setReal(5);
    c2.setImg(6);
    c3=c1.addComplex(c2);  // Complex::addComplex(&c1,c2);
    return 0;
}


