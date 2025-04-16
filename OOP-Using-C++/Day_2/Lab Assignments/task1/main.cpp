
#include<iostream>
using namespace std;
class Complex
{
    private:
    int real;
    int img;


    public:

    Complex()
    {

        cout<<"COMPLEX def ctor"<<endl;
        real=0;
        this->img=0;
    }
    Complex(int _real,int _img)
    {
        //learning purpose
        cout<<"COMPLEX 2p ctor"<<endl;
        real=_real;
        this->img=_img;
    }
    Complex(int _num)
    {
        //learning purpose
        cout<<"COMPLEX 1p ctor"<<endl;
        real=(*this).img=_num;
    }
    //

    //dest
    ~Complex()
    {
        cout<<"dest called"<<endl;
    }

    void SetReal(/*Complex *this*/int _real)
    {
        this->real=_real;
        (*this).real=_real;
        real=_real;
    }
    int GetReal()
    {
        return real;
    }
    void SetImg(int _img)
    {
        img=_img;
    }
    int GetImg()
    {
        return img;
    }
    void Print()
    {
        cout<<real <<"+" <<img <<"i"<<endl;
    }

    Complex Add(Complex right)
    {

        Complex result;
        result.real=/*caller*/real+right.real;
        result.img=/*caller*/img+right.img;
        return result;
    }
    //

    void Initialize()
    {
        this->real=img=0;
    }
    void Initialize(int _real,int _img)
    {
        this->real=_real;
        img=_img;
    }
    void Initialize(int _num)
    {
        this->real=img=_num;
    }


    //
};
///standalone fn add 2 complex Numbers
Complex AddComplex(Complex left,Complex right)
{
    Complex result;
    //result.real=left.real+right.real; //Compile Error
    int r=left.GetReal()+right.GetReal();
    int i=left.GetImg()+right.GetImg();
    result.SetReal(r);
    result.SetImg(i);
    return result;
}



///create 3 Complex with default initialization
//v1
int main()
{
    Complex c1;
    Complex c2;
    Complex c3;
    c1.SetReal(0);c1.SetImg(0);
    c2.SetReal(0);c2.SetImg(0);
    c3.SetReal(0);c3.SetImg(0);
      return 0;
}
