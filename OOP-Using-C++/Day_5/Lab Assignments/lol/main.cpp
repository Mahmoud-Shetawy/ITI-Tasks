#include <iostream>

using namespace std;
//Lab Assignments
///1- geoshape ,rect,circle,tri,sq
//////SumOfAreas(Geoshapes ** ,int )

class Geoshape
{

protected:
    double dim1;
    double dim2;
public:
    void SetDim1(double _dim1){dim1=_dim1;}
    double Getdim1(){return dim1;}
    void SetDim2(double _dim2){dim2=_dim2;}
    double GetDim2(){return dim2;}

    Geoshape(){

    dim1=dim2=0;

    }
    Geoshape(double _dim1,double _dim2)
    {
        dim1=_dim1;
        dim2=_dim2;
    }
    Geoshape(double _dim)
    {
        dim1=dim2=_dim;
    }
    ~Geoshape(){}
    virtual double CArea()=0;


};

class Rect:public Geoshape
{
public:
    Rect()
    {
        dim1=dim2=0;

    }
    Rect(double _dim1,double _dim2)
    :Geoshape(_dim1,_dim2)
    {

    }
    ~Rect(){}
    double CArea()
    {
        return dim1*dim2;
    }


};
class Square:public Geoshape
{
public:
    Square()
    {
        dim1=dim2=0;
    }

    Square(double _dim)
    :Geoshape(_dim,_dim)
    {

    }
    ~Square(){}

    double CArea()
    {
        return dim1*dim2;
    }


};
class Circle:public Geoshape
{
public:
    Circle(){}
    Circle(double _radius):Geoshape(_radius)
    {

    }
    ~Circle(){}
    double CArea()
    {
        return dim1 * dim2 *(22/7);

    }
};

class Tri:public Geoshape
{
public:
    Tri(){}

    Tri(double _base,double _hieght):Geoshape(_base,_hieght)
    {

    }
    ~Tri(){}
    double CArea()
    {
        return 0.5*dim1 * dim2;
    }
};


double SumOfAreas(Geoshape** gptrArr,int gsize)
{
    double sum=0;
    for(int i=0;i<gsize;i++)
    {
        sum+=gptrArr[i]->CArea();
    }
    return sum;
}

int main()
{
    Rect rarr[2]={Rect(3,4),Rect(2,5)};
    Square sarr[3]={Square(10),Square(10),Square(10)};

    Circle c1(7);
    Tri t1(3,4);

    Geoshape *gptrArr[8]= {rarr,&rarr[1],sarr,&sarr[0],&sarr[1],&sarr[2],&c1,&t1};

    cout<<SumOfAreas(gptrArr,8)<<endl;


    return 0;
}
