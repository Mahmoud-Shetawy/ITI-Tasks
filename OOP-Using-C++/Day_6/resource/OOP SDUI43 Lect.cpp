///////////////////////////////////////////////////////////////
//[Inheritance]Every Code below will inherit from public
///////////////////////////////////////////////////////////////
#include<iostream>
using namespace std;

class Base
{
    protected:
    int x;
    int y;
    public:
    void setX(int _x){x=_x;}
    void setY(int _y){y=_y;}
    int getX(){return x;}
    int getY(){return y;}
    Base(){x=y=0;}
    Base(int _x,int_y){x=_x;y=_y;}
    Base(const Parent& old){}
    ~Base(){}

    void show()
    {
        cout<<"I'm Base"<<endl;
    }
};

class Derived:public Base
{
    protected:
    int z;
    public:
    void setZ(int _z){z=_z;}
    int getZ(){return z;}
    Derived(){x=y=z=0;}
    Derived(int _x,int _y,int _z){x=_x;y=_y;z=_z;}
    Derived(const Derived& old){}
    ~Derived(){}
    void show()
    {
        cout<<"I'm Derived"<<endl;
    }
};

class Derived2:public Derived
{
    protected:
    int j;
    public:
    void setJ(int _j){j=_j;}
    int getJ(){return j;}
    Derived2(){j=0;}
    Derived2(int _x,int _y,int _z,int _j):
    Derived(_x,_y,_z)
    {j=_j;}
    Derived2(const Derived2& old){}
    ~Derived2(){}
    void show()
    {
        cout<<"I'm Derived2"<<endl;
    }
};

int main()
{
    //#4
    Base* bPtr=new Derived(1,2,3);  //True
    //ألاب يحتوي جميع أبناؤه
    //is a
    ///car is a viehcle
    ///truck is a viehcle
    ///Rule: We can create object from child
    ///////and points it via pointer of its base
    //bPtr->setZ(22); //XXXX Error
    ///bPtr->z=22; //Error
    bPtr->show();  //I'm Base

    Derived* dptr=new Derived2(1,2,3,4);
    dptr->show(); //i'm Derived

    Base* b2Ptr=new Derived2(5,6,7,8);
    b2Ptr->show(); //I'm base



    // //#3
    // Derived2 d2; //16B 
    // //baseCtor->DerivedCtor->Derived2Ctor
    // d2.show(); //I'm Derived2
    // Derived2* d2Ptr=&d2;
    // d2Ptr->show(); //I'm Derived2
    // d2Ptr=new Derived2(1,2,3,4);
    // d2Ptr->show(); //i'm Derived2


    // //#2
    // Derived d1;  //12B   //x,y,z,show,show
    // d1.show();  //I'm Derived
    // Derived* dPtr=&d1;
    // dPtr->show(); //I'm Derived
    // dPtr=new Derived(3,4,5);
    // dPtr->show(); //I'm Derived

    ////#1
    // Base p1; //Stack    //8B
    // p1.show();  //I'm Base
    // Base *bPtr=new Base(3,4);
    // (*bPtr).show(); //I'm Base
    // bPtr->show();   //I'm Base
    // bPtr=&p1;
    // bPtr->show();   //I'm Base
}

//////////////////////////////////////////////////
///#4
////Early/static   Binding
////when pointer from parent points object from its child
////when call overriden method
////Complier will EARLY Retrieve copy of Pointer
/////not copy of Object

//Logic
    Base *bPtr=new Derived2(1,2,3);
    bPtr->Show(); //i'm derived2

    Derived *dptr=new Derived2(5,6,7);
    dptr->Show(); //i'm  Derived2

    Base * bPtr=new Derived(3,4);
    bPtr->show(); //i'm derived

//////////////////////////////////////////////////////

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

#include<iostream>
using namespace std;

class Base
{
    protected:
    int x;
    int y;
    public:
    void setX(int _x){x=_x;}
    void setY(int _y){y=_y;}
    int getX(){return x;}
    int getY(){return y;}
    Base(){x=y=0;}
    Base(int _x,int_y){x=_x;y=_y;}
    Base(const Parent& old){}
    ~Base(){}

    virtual void show()
    {
        cout<<"I'm Base"<<endl;
    }
};

class Derived:public Base
{
    protected:
    int z;
    public:
    void setZ(int _z){z=_z;}
    int getZ(){return z;}
    Derived(){x=y=z=0;}
    Derived(int _x,int _y,int _z){x=_x;y=_y;z=_z;}
    Derived(const Derived& old){}
    ~Derived(){}
    void show()
    {
        cout<<"I'm Derived"<<endl;
    }
};

class Derived2:public Derived
{
    protected:
    int j;
    public:
    void setJ(int _j){j=_j;}
    int getJ(){return j;}
    Derived2(){j=0;}
    Derived2(int _x,int _y,int _z,int _j):
    Derived(_x,_y,_z)
    {j=_j;}
    Derived2(const Derived2& old){}
    ~Derived2(){}
    /**/void show()
    {
        cout<<"I'm Derived2"<<endl;
    }
};

int main()
{
    Base *bPtr=new Derived2(1,2,3);
    bPtr->Show(); //i'm derived2

    Derived *dptr=new Derived2(5,6,7);
    dptr->Show(); //i'm  Derived2

    Base * bPtr=new Derived(3,4);
    bPtr->show(); //i'm derived
}

/////////////////////////////////////////////////////////

class Geoshape
{
    protected:
    float dim1,dim2;
    public:
    void setDim1(float _dim1){dim1=_dim1;}
    void setDim2(float _dim2){dim2=_dim2;}
    float getDim1(){return dim1;}
    float getDim2(){return dim2;}
    Geoshape(){dim1=dim2=0;}
    Geoshape(float _dim1,float _dim2){dim1=_dim1;dim2=_dim2;}
    Geoshape(const Geoshape& old){}
    ~Geoshape(){}
    virtual float CArea(){return -1;}
};

class Rect:public Geoshape
{
    
    public:
    Rect(){}
    Rect(float _dim1,float _dim2):Geoshape(_dim1,_dim2)
    {}
    float CArea()
    {
        return dim1*dim2;
    }
};

class Square:public Geoshape
{
    public:
    Square(){}
    Square(float dim):Geoshape(dim,dim)
    {
        
    }
    float CArea()
    {
        return dim1*dim2;
    }
};

class Circle:public Geoshape
{
    public:
    Circle(){}
    Circle(float _radius):Geoshape(_radius,_radius){}
    float CArea()
    {
        return 3.14* dim1*dim2;
    }
};

class Tri:public Geoshape
{
    public:
    Tri(){}
    Tri(float _base,float _height)
    {
        dim1=_base;
        dim2=_height;
    }
    float CArea()
    {
        return 0.5*dim1*dim2;
    }

};

//Calculate Sum Of Areas
///Business failure for Open Closed Principle
float SumOfAreas(Rect* rptr,int rSize,Square* sptr,int sSize,Tri* tptr,int tSize)
{
    float sum=0;
    for(int i=0;i<rSize;i++)
    {
        sum+=rptr[i].CArea();
    }
    for(int i=0;i<sSize;i++)
    {
        sum+=sptr[i].CArea();
    }
    for(int i=0;i<tSize;i++)
    {
        sum+=tptr[i].CArea();
    }
    return sum;
}
//
///Code To be applicable ALL THE time SOLID
float SumOfAreasV02(Geoshape* gparam[],int size)
{
    float sum=0;
    for(int i=0;i<size;i++)
    {
        sum+=gparam[i]->CArea();
    }
    return sum;
}

float SumOfAreasV03(Geoshape** gparam,int size)
{
    float sum=0;
    for(int i=0;i<size;i++)
    {
        sum+=gparam[i]->CArea();
    }
    return sum;
}
///

int main()
{
    // Rect r1(3,4);
    // Geoshape *gptr=&r1;
    // cout<< gptr->CArea(); //12

    //Geoshape* gPtr=new Rect[3];
    //gPtr[0].CArea();  //zero

    // Rect rarr[3]={Rect(3,4),Rect(1,2),Rect(2,2)};
    // Geoshape*gptr[3]={rarr,&rarr[1],&rarr[2]};
    // cout<<gptr[0]->CArea(); //12
    // cout<<(*gptr[1]).CArea(); //2
    // cout<<gptr[2]->CArea(); //4


    // Rect r1(3,4);
    // Square s1(10);
    // Tri t1(3,4);
    // Geoshape* gPtr[3]={&r1,&s1,&t1};  //T

    // gPtr[0]->CArea(); //12
    // gPtr[1]->CArea(); //100
    // gPtr[2]->CArea(); //6


    // Rect rarr[3]={Rect(3,4),Rect(2,2),Rect(10,1)};
    // Square s1(10);

    // cout<< SumOfAreas(rarr,3,&s1,1); //12+4+10+100



    //Geoshape obj;
    //cout<<obj.CArea(); //-1

    ///#1 SumOfAreas
    Rect rarr[3]={Rect(3,4),Rect(2,2),Rect(10,1)};
    Square s1(10);
    Tri tarr[2]={Tri(3,4),Tri(5,6)};
    Circle* cptr=new Circle(10);

    Geoshape* gptr[7]
    ={rarr,&rarr[1],&rarr[2],&s1,tarr,&tarr[1],cptr};

    Geoshape* gptr[3]
    ={rarr,&rarr[1],&rarr[2]};

    Geoshape* gptr[4]
    ={rarr,&rarr[1],&rarr[2],&tarr[1]};
    cout<<SumOfAreasV02(gptr,7);
    ///


    //#2 Restrict Create Object From Geoshape
    //
}
///////////////////////////////////////////////////////
//#2 Restrict Create Object From Geoshape

class Geoshape
{
    protected:
    float dim1,dim2;
    public:
    void setDim1(float _dim1){dim1=_dim1;}
    void setDim2(float _dim2){dim2=_dim2;}
    float getDim1(){return dim1;}
    float getDim2(){return dim2;}
    /// useful in composition or inheritance
    Geoshape(){dim1=dim2=0;}
    Geoshape(float _dim1,float _dim2){dim1=_dim1;dim2=_dim2;}
    Geoshape(const Geoshape& old){}
    ~Geoshape(){}
    //pure Virtual Function
    virtual float CArea()=0;
    //virtual void Show(){}
};

class Rect:public Geoshape
{
    
    public:
    Rect(){}
    Rect(float _dim1,float _dim2):Geoshape(_dim1,_dim2)
    {}

    //[override]safety factor -> virual fn
    float CArea() override  
    {
        return dim1*dim2;
    }

    //int Show() override {return 22;}
};

class Square:public Geoshape
{
    public:
    Square(){}
    Square(float dim):Geoshape(dim,dim)
    {
        
    }
    float CArea() override
    {
        return dim1*dim2;
    }
};

class Circle:public Geoshape
{
    public:
    Circle(){}
    Circle(float _radius):Geoshape(_radius,_radius){}
    float CArea() 
    {
        return 3.14* dim1*dim2;
    }
};

class Tri:public Geoshape
{
    public:
    Tri(){}
    Tri(float _base,float _height)
    {
        dim1=_base;
        dim2=_height;
    }
    float CArea() override
    {
        return 0.5*dim1*dim2;
    }

};

int main()
{
    Geoshape obj(3,4);  //Compile Error

    Geoshape* gptr;  //True
    gptr=new Rect(3,4);

    //Search
    delete gptr;  //geoshape dest  //non make sense
    ///How to call dest for object not pointer???
    ///virtual destructor
}


///abstract class
////class we cannot create object from it

///How to make class abstract?
///abstract class is a class Contains
///at least one pure virtual function

//Pure virtual function        ===>abstract function
///virtual function header ONLY =0;


//concrete class : normal class Stack,Complex,Rect


///Pure Virtual function must be overridden


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

    void funOne() override  //-> became virtual fn here
    {
        cout<<"override Fn one inside TypeB";
    }
    //virtual void funTwo()=0;

    void Show(){}
    
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
    void Show(){}
};

int main()
{
    TypeA obja;  ///Compile Error ///abstract class

    TypeB objb; ///Compile Error ///abstract class

    TypeC objc; //TRUE
}


////////////////////////////////////////////////////////


#include<iostream>
#include "graphics.h"

class Shape
{
    protected:
    int color;
    public:
    //setter&getters
    //ctor
    //ctor()
    //~
    //cpy
    virtual void Draw(){}
};
class Point
{
    int x;
    int y;
    public:
    void setX(int _x){x=_x;}
    void setY(int _y){y=_y;}
    int getX(){return x;}
    int getY(){return y;}
    Point(){x=y=0;} //construct start,end
    Point(int _x,int _y){x=_x;y=_y;}
    Point(int _num){x=y=_num;}
    ~Point(){}
    Point(const Point& old){x=old.x;y=old.y;}
    //Point operator=(const Point& right){}
};
///
class Line:public Shape
{
    private:
    Point start;
    Point end;
    public:
    void setStart(Point _start){start=_start;}
    void setEnd(Point _end){end=_end;}
    Point getStart(){return start;}
    Point getEnd(){return end;}
    Line()
    {
        //start x0 y0  end x0 y0   clor 0
    }
    Line(int x1,int y1,int x2,int y2,int _color):
    start(x1,y1),end(x2,y2),Shape(_color)
    {
        
    }
    Line(Point _start,Point _end,int _color)
    {
        start=_start;
        end=_end;  //memberwise copy
        color=_color;
    }
    ~Line(){}
    Line(const Line& old)
    {
        start=old.start;
        this->end=old.end;
        this->color=old.color;
    }
    //
    void Draw()
    {
        //inside graphics.h
        setcolor(color);
        line(start.getX(),start.getY(),end.getX(),end.getY());
    }
};

class Rect:public Shape
{
    Point ul;
    Point lr;
    public:
    void setUL(Point _ul){ul=_ul;}
    void setLR(Point _lr){lr=_lr;}
    Point getUL(){return ul;}
    Point getLR(){return lr;}
    Rect()
    {
    }
    Rect(int x1,int y1,int x2,int y2,int _color):
    ul(x1,y1),lr(x2,y2),Shape(_color)
    {
        
    }
    ~Rect(){}
    Rect(const Rect& old):ul(old.ul),lr(old.lr)
    {
        //ul=old.ul;
        //lr=old.lr;
        color=old.color;
    }
    void Draw()
    {
        //graphics.h
        setcolor(color);
        rectangle(ul.getX(),ul.getY(),lr.getX(),lr.getY());
    }

};

class Circle
{
    Point center;
    int radius;
    int color;

    public:
    void Draw()
    {
        setcolor(color);
        circle(center.getX(),center.getY(),radius);
    }
};

class Triangle
{
    Point p1;
    Point p2;
    Point p3;
    int color;
    public:
    void Draw()
    {
        setcolor(color);
        line(p1,p2);
        line(p2,p3);
        line(p3,p1);
    }
};


class Picture
{
    private:
    Shape** sptr;  ///shape* sptr[???]
    int sSize;
    

    public:
    void setShapes(Shape** _sptr,int _ssize)
    {
        sptr=_sptr;
        sSize=_ssize;
    }

    Picture()
    {
        sptr=NULL;
        sSize=0;
    }
    Picture(Shape** _sPtr,int _sSize)
    {
        sptr=_sPtr;
        sSize=_sSize;
    }

    void DoIt()
    {
        for(int i=0;i<sSize;i++)
        {
            sptr[i]->Draw();
        }
    }
};

int main()
{
    initgraph();
    Line larr[2]={Line(2,2,2,2,2),Line(3,3,3,3,3)};
    Circle carr[2]={Circle(),Circle()};
    Tri t(2,3,4,5,6,7,8);
    Rect r(2,3,4,5,6);

    //
    Shape* sptr[6]={larr,&larr[1],carr,&carr[1],&t,&r};
    //

    Picture p1;

    //
    p1.setShapes(sptr,6);

    //
    p1.DoIt();

    //
    p1.setShapes(NULL,0);

}

////////////////////////////////////////////////////
//Lab 

///1- Aggrigation on picture   abagora
///2- Geoshape abstract and sumOfAreas function
///3- try 2 pure virtual fn in class





