//Pointer To Object/Array
//Aggregation/Association
//virtual 
//abstract
//////////////////////////////////////////////////////////////////
#include<iostream>
using namespace std;

class Point
{
    private:
    int x,y;
    public:
    void setX(int _x){x=_x;}
    void setY(int _y){y=_y;}
    int getX(){return x;}
    int getY(){return y;}
    Point()  //start    //end
    {
        x=y=0;
        cout<<"Point ctor";
    }
    //ul     1        2
    //lr     3        4
    Point(int _x,int _y)
    {
        x=_x;
        y=_y;
        cout<<"Point ctor";
    }
    Point(const Point& old)
    {
        x=old.x;y=old.y;
    }
    ~Point()
    {
        cout<<"Point dest";
    }
    void Print()
    {
        cout<<x<<y<<endl;
    }
};


int main()
{
    //Point p1(3,4); //8B
    //o/p
    //ctor point
    //dest point

    //Point parr[3];
    //Array of 3 Object from Point   |00|00|00|
    //o/p
    //point def ctor
    //point def ctor
    //point def ctor
    //dest point
    //dest point
    //dest point


    //anonymous object
    //Point(3,4);
    //constructor & destructor will be 
    //called sequentially
    //
    //Point parr2[3]={Point(1,2),Point(3,4),Point(5,6)};
    //point 2p ctor
    //point 2p ctor
    //point 2p ctor
    //dest point
    //dest point
    //dest point

    // Point p1(3,4);  //stack
    // Point *ptr; //4B or 8B

    // ptr=&p1;
    // ptr->setX(33);
    // (*ptr).setX(33);

    //Point * ptr;
    //ptr=new Point[3];  //24Bytes in heap  3*8
    //o/p
    //point def ctor
    //point def ctor
    //point def ctor
    //dest point
    //dest point
    //dest point


    //Point *ptr=new Point[3]={Point(),Point(),Point()};
    //not supported
    //parametrised ctor as default 
    //creation is not supported
    //with dynamic allocation
    // Point *ptr=new Point[3];
    // ptr[0].setX(1);
    // ptr[0].setY(2);
    // ptr->setX(1);
    // ptr->setY(2);
    // ptr++;
    //(ptr+0)->setX(1);
    //(ptr+1)->setX(3);


    //Point *ptr=new Point[3];
    //point def ctor
    //point def ctor
    //point def ctor

    //delete [] ptr;   ///dest called 3 times
    //o/p
    //point dest
    //point dest
    //point dest

    // Point *ptr=new Point(3,4);
    // //point 2p ctor
    // delete ptr;  //delete non array

    return 0;
}

///////////////////////////////////////////////////////////
//Aggregation // Association

#include<iostream>
using namespace std;

class Point
{
    private:
    int x,y;
    public:
    void setX(int _x){x=_x;}
    void setY(int _y){y=_y;}
    int getX(){return x;}
    int getY(){return y;}
    Point()  //start    //end
    {
        x=y=0;
        cout<<"Point ctor";
    }
    //ul     1        2
    //lr     3        4
    Point(int _x,int _y)
    {
        x=_x;
        y=_y;
        cout<<"Point ctor";
    }
    Point(const Point& old)
    {
        x=old.x;y=old.y;
    }
    ~Point()
    {
        cout<<"Point dest";
    }
};

class Rect
{
    private:
    Point ul;
    Point lr;
    public:
    void setUL(Point _ul){ul=_ul;}
    void setLR(Point _lr){lr=_lr;}
    Point getUL(){return ul;}
    Point getLR(){return lr;}
    Rect()
    {
        cout<<"Rect ctor";
    }
    Rect(int x1,int y1,int x2,int y2)
    :ul(x1,y1),lr(x2,y2)
    {
        cout<<"Rect ctor";
        //Jumb 2 times
    }
    Rect(Point _ul,Point _lr)
    {
        ul=_ul;
        lr=_lr;
    }
    Rect(const Rect& old)
    {
        ul=old.ul;
        this->lr=old.lr;
    }
    void Draw()
    {
        cout<<"UL ("<<ul.getX()<<","<<ul.getY()<<") ";
        cout<<"LR ("<<lr.getX()<<","<<lr.getY()<<") "<<endl;
    }
};


class Picture
{
    private:
    Rect *rPtr;
    int rSize;
    //8fields
    public:
    Picture()
    {
        rPtr=NULL;
        rSize=0;
    }
    void setRects(Rect* _rPtr,int _rSize)
    {
        rPtr=_rPtr;
        rSize=_rSize;
    }

    void Process()
    {
        for(int i=0;i<rSize;i++)
        {
            rPtr[i].Draw();
        }



    }

}


int main()
{
    Rect r(3,4);
    Rect *ptr=new Rect[4];
    Picture p1;
    p1.setRects(&r,1);
    p1.Process();
    //
    p1.setRects(NULL,0);
    //
    p1.setRects(ptr,4);
    p1.Process();
    //
    p1.setRects(NULL,0);
    //here
    ///Dependency Injection    

}


///////////////////////////////////////////////////////////////
//Every Code below will inherit from public
//Virtual

class Base
{
    protected:
    int x;
    public:
    void setX(int _x){x=_x;}
    int getX(){return x;}
    Base()
    {
        x=0;
    }
    Base(int _x)
    {
        x=_x;
    }
    Base(const Base & old){}
    ~Base(){}

    void Show()
    {
        cout<<"I'm Base"<<endl;
    }
    
};

class Derived:public Base
{
    protected:
    int y;
    public:
    void setY(int _y){y=_y;}
    int getY(){return y;}
    Derived(){y=0;}
    Derived(int _x,int _y):Base(_x)
    {
        y=_y;
    }
    //cpy
    ~Derived(){}
    void Show()
    {
        cout<<"I'm Derived"<<endl;
    }

};

class Derived2:public Derived
{
    protected:
    int z;
    public:
    void setZ(int _z){z=_z;}
    int getZ(){return z;}
    Derived2(){z=0;}
    Derived2(int _x,int _y,int _z):Derived(_x,_y)
    {
        z=_z;
    }
    //cpy
    ~Derived2(){}
    void Show()
    {
        cout<<"I'm another Derived"<<endl;
    }

};


int main()
{
    // Base b1; //Stack => 4B
    // b1.Show(); //I'm Base
    // Base* bPtr;
    // bPtr=&b1;
    // bPtr->Show(); //I'm Base
    // Base* bPtr2=new Base(22);
    // (*bPtr2).Show();//I'm Base

    // Derived d;
    // d.Show();//I'm Derived
    // Derived * dPtr=&d;
    // dPtr->Show();
    // dPtr=new Derived(3,4);
    // dPtr->Show();//I'm Derived



    // Base * bPtr=new Derived(3,4);
    // //الأب يحتوي جميع ابناؤه

    // //car is a viechle
    // //truck is a viechle
    // //viechle is a car ??? No
    // //bPtr->y=33;//Compile Error

    // bPtr->Show(); //I'm Base


    Base *bPtr=new Derived2(1,2,3);
    bPtr->Show(); //i'm base

    Derived *dptr=new Derived2(5,6,7);
    dptr->Show(); //i'm Derived

    return 0;
}



//////Early/Static Binding
////when pointer from parent points object from child
////when call overriden method
////Complier will EARLY Retrieve copy of Pointer
/////not copy of Object


//Business logic

    Base *bPtr=new Derived2(1,2,3);
    bPtr->Show(); //i'm another derived

    Derived *dptr=new Derived2(5,6,7);
    dptr->Show(); //i'm another Derived

    Base * bPtr=new Derived(3,4);
    bPtr->show(); //i'm derived


///Is there a solution make pointer of Base
//Will Retrieve copy of overriden method 
//that belong to object not pointer???
////YES

/////Late/Dynamic Binding
////when pointer from parent points object from child
////when call overriden method
////Complier will Later Retrieve copy of Object
/////not copy of Pointer

////1- Function in base class will be public and virtual
////2- class will inherits base must Inherit public 
////3- overridden function in derived class must be public
////4- pointer from parent points object from child
class Base
{
    protected:
    int x;
    public:
    void setX(int _x){x=_x;}
    int getX(){return x;}
    Base()
    {
        x=0;
    }
    Base(int _x)
    {
        x=_x;
    }
    Base(const Base & old){}
    ~Base(){}
    //#1
    virtual void Show()
    {
        cout<<"I'm Base"<<endl;
    }
    
};
              //#2
class Derived:public Base
{
    protected:
    int y;
    public:
    void setY(int _y){y=_y;}
    int getY(){return y;}
    Derived(){y=0;}
    Derived(int _x,int _y):Base(_x)
    {
        y=_y;
    }
    //cpy
    ~Derived(){}
    //#3 public
    void Show() override
    {
        cout<<"I'm Derived"<<endl;
    }

};
//override => safety factor

class Derived2:public Derived
{
    protected:
    int z;
    public:
    void setZ(int _z){z=_z;}
    int getZ(){return z;}
    Derived2(){z=0;}
    Derived2(int _x,int _y,int _z):Derived(_x,_y)
    {
        z=_z;
    }
    //cpy
    ~Derived2(){}
    void Show()
    {
        cout<<"I'm another Derived"<<endl;
    }

};


int main()
{
    Base* bPtr=new Derived(1,2);
    bPtr->Show(); //i'm derived

    Derived *dPtr=new Derived2(3,4,5);
    dptr->Show(); //i'm another derived

    Base *bPtr2=new Derived2(67,8,8);
    bPtr2->Show(); //i'm another derived

    Derived2 d2(3,4,5);
    Derived2 *dptr2=new Derived2(4,5,6);
    Derived2 darr[3]={Derived2(),Derived2(),Derived2()};

    Base *bPtr=&d2;
    bPtr=dptr2;
    
    bPtr=&darr[0];
    bPtr=darr;
    bPtr=&darr;

}

///////////////////////////////////////////////////////

class Geoshape
{
    protected:
    double dim1;
    double dim2;
    //
    public:
    void setDim1(double _dim1){dim1=_dim1;}
    void setDim2(double _dim2){dim2=_dim2;}
    double getDim1(){return dim1;}
    double getDim2(){return dim2;}
    Geoshape()
    {
        dim1=dim2=0;
    }
    Geoshape(double _dim1,double _dim2)
    {
        dim1=_dim1;
        dim2=_dim2;
    }
    Geoshape(const Geoshape& old){}
    ~Geoshape(){}

    //
    // virtual double CArea()
    // {
    //     return -1;
    // }
    //
    //pure virtual function
    virtual double CArea()=0;
    //
};

class Rect:public Geoshape
{
    //fields??? No
    public:
    Rect(){}
    Rect(double _dim1,double _dim2)
    :Geoshape(_dim1,_dim2)
    {
        //dim1=_dim1;dim2=_dim2;
    }
    Rect(const Rect& old){}
    ~Rect(){}
    double CArea() override     //=> normal virtual function 
    {
        return dim1*dim2;
    }
};


class Square:public Rect
{
    public:
    Square(){}
    Square(int _dim):Rect(_dim,_dim)
    {
        dim1=dim2=_dim;
    }
    double CArea() override
    {
        return dim1*dim2;
    }
};

class Circle:public Geoshape
{
    public:
    Circle(){}
    Circle(double _dim):Geoshape(_dim,_dim)
    {}
    double CArea()
    {
        return 3.14* dim1*dim2;
    }
};

class Tri:public Geoshape
{
    public:
    Tri(){}
    Tri(double _base,double _height ):Geoshape(_height,_base)
    {}
    double CArea()
    {
        return 0.5*dim1*dim2;
    }
};


///standalone fn to calculate sum of areas
///this code failed to defend itself
///open close principles
double SumOfAreasv1
(Rect *rptr,int rsize,Square *sptr,int ssize,Circle *cptr,int csize/**/)
{
    double sum=0;
    for(int i=0;i<rsize;i++)
    {
        sum+=rptr[i].CArea();
    }
    for(int i=0;i<ssize;i++)
    {
        sum+=sptr[i].CArea();
    }
    for(int i=0;i<csize;i++)
    {
        sum+=cptr[i].CArea();
    }
    return sum;
}


//SumOfAreas function that can receive any shape
double SumOfAreasv2(Geoshape* gPtr[],int gsize)
{
    double sum=0;
    for(int i=0;i<gsize;i++)
    {
        sum+=gPtr[i]->CArea();
    }
    return sum;
}

//Standard header
double SumOfAreasv3(Geoshape** gPtr,int gsize)
{
    double sum=0;
    for(int i=0;i<gsize;i++)
    {
        sum+=gPtr[i]->CArea();
    }
    return sum;
}

double SumOfAreasv4(Geoshape*** gPtr,int gsize)
{}

int main()
{

    // Rect rarr[3]={Rect(2,5),Rect(5,4),Rect(2,3)};
    // Square s(10);

    // cout<< SumOfAreas(rarr,3,&s,1);

    // Geoshape *gPtr=new Rect(3,4);
    // cout<<gPtr->CArea();  //=>   12

    // gPtr=new Tri(3,4);
    // cout<<gPtr->CArea();  //6


    Rect rarr[3]={Rect(2,5),Rect(5,4),Rect(2,3)};
    Square s(10);
    Tri *tP=new Tri(4,5);
    Circle c(7);
    Geoshape* garr[6]={rarr,&rarr[1],&rarr[2],&s,tP,&c};

    //  cout<<garr[0]->CArea();  //10
    //  cout<<garr[3]->CArea();  //100

    cout<<SumOfAreasv3(garr,6); //



    Geoshape obj;//object from geoshape //Issue
    cout<<obj.CArea(); //-1  //Issue

}

////////////////////////////////////////////////////////

///abstract class
////class we cannot create object from it

///How to make class abstract?
///abstract class is a class Contains
///at least one pure virtual function

//Pure virtual function        ===>abstract function
///virtual function header ONLY =0;


//concrete class : normal class Stack,Complex,Rect


///Pure Virtual function must be overridden

//////////////////////////////////////////////////////////
class TypeA
{
    protected:
    int x;
    public:
    void setX(int _x){x=_x;}
    int getX(){return x;}
    TypeA(){x=0;}
    TypeA(int _x){x=_x;}

    virtual void Show(){}  //virtual fn can[not must] be overridden

    virtual void funOne()=0;   //or abstract function
    virtual void funTwo()=0;

};

class TypeB:public TypeA
{
    protected:
    int y;
    public:
    //setter/Getters
    TypeB(){y=0;}
    TypeB(int _x,int _y):TypeA(_x){y=_y;}

    void funOne() override
    {
        cout<<"override Fn one inside TypeB";
    }

    
};

class TypeC:public TypeB
{
    protected:
    int z;
    public:

    void funTwo() override
    {
        cout<<"override Fn two inside Typec";
    }

    
};

int main()
{
    TypeA obj ;   //Compile Error abstract class
    TypeA *TAptr;  //True

    TypeB obj2;     //Compile Error abstract class

    TypeC obj3; //Run successfully


    Geoshape* gptr=new Rect(3,4);
    //o/p
    //point ctor
    //point ctor
    //Rect ctor

    delete gptr;  
    //call Which destructor???
    ///Geoshape
    ///or Rect

    //Geoshape dest
    //early binding 

    //Solution to call Rect dest??? Search
    //Hint: virtual destructor
}


///////////////////////////////////////////

//in c++
//multiple inheritance is supported


///////////////////////////////////////////

//Lab 

///1- Aggrigation on picture
///2- Geoshape abstract and sumOfAreas function
///3- try 2 pure virtual fn in class






