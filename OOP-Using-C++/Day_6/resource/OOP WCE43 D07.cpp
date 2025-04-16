///////////////////////////////////////////////////////////////
//[Inheritance]Every Code below will inherit from public
///////////////////////////////////////////////////////////////
#include<iostream>
using namespace std;

class Base
{
    protected:
    int x,y;
    public:
    void setX(int _x){x=_x;}
    void setY(int _y){y=_y;}
    int getX(){return x;}
    int getY(){return y;}
    Base(){x=y=0;}
    Base(int _x,int _y){}
    ~Base(){cout<<"Base Dest";}
    void Show()
    {cout<<"I'm Base"<<endl;}
};

class Derived:public Base
{
    protected:
    int z;
    public:
    void setZ(int _z){z=_z;}
    int getZ(){return z;}
    Derived(){x=y=z=0;}
    Derived(int _x,int _y,int _z):Base(_x,_y)
    {z=_z;}
    ~Derived(){cout<<"Derived dest";}
    
    void Show()
    {cout<<"I'm Derived"<<endl;}
};

class Derived2:public Derived
{
    protected:
    int a;
    public:
    void setA(int _a){a=_a;}
    int getA(){return a;}
    Derived2(){a=0;}
    Derived2(int _x,int _y,int _z,int _a):Derived(_x,_y,_z){a=_a;}
    ~Derived2(){cout<<"Derived2 Dest";}
    void Show()
    {
        cout<<"I'm Derived2"<<endl;
    }
};

//V01
int main()
{
    Base b1(3,4);  //8B  //in Stack
    b1.Show(); //i'm Base

    Derived d1(2,3,4);   //12B   //in Stack
    d1.Show(); //i'm Derived
    
    Base* bPtr=&b1;
    (*bPtr).Show();  //i'm Base
    bPtr->Show();    //i'm Base

    Derived* dPtr=new Derived(3,4,5); //=>in heap
    //delete dPtr; //call derived dest 
    dPtr->Show();  //i'm Derived
    
    //When call overridden fn
    //compiler call show of pointer type


    Base* bPtr2=new Base(1,2);
    bPtr2-> show();
    ///calling show of pointer  type

    return 0;
}


//V02
int main()
{
    Base b1(1,2);
    Derived d1(3,4,5);

    Base* bPtr=&d1;
    ///we can do object from Derived and can be pointed by
    ///pointer of its base
    ///الأب يحتوي جميع ابناؤه

    ///car is a viechle
    ///Truck is a viechle

    bPtr->Show();  //i'm Base
    //when call overriden fn
    //o.S will call fn of pointer Type


    Derived* dPtr=new Derived2(1,2,3,4);
    dPtr->Show();  //i'm Derived

    Base* bPtr=new Derived2(3,4,5,6);
    bPtr->Show();  //i'm Base
}

/////////////////////////////////////////////////////

///Early/ Static Binding


////Early/static   Binding
////when pointer from parent points
// object from its child
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


class Base
{
    protected:
    int x,y;
    public:
    void setX(int _x){x=_x;}
    void setY(int _y){y=_y;}
    int getX(){return x;}
    int getY(){return y;}
    Base(){x=y=0;}
    Base(int _x,int _y){}
    ~Base(){cout<<"Base Dest";}
    virtual void Show()
    {cout<<"I'm Base"<<endl;}
};

class Derived:public Base
{
    protected:
    int z;
    public:
    void setZ(int _z){z=_z;}
    int getZ(){return z;}
    Derived(){x=y=z=0;}
    Derived(int _x,int _y,int _z):Base(_x,_y)
    {z=_z;}
    ~Derived(){cout<<"Derived dest";}
    //override -> safety factor
    void Show() override 
    {cout<<"I'm Derived"<<endl;}
};

class Derived2:public Derived
{
    protected:
    int a;
    public:
    void setA(int _a){a=_a;}
    int getA(){return a;}
    Derived2(){a=0;}
    Derived2(int _x,int _y,int _z,int _a):Derived(_x,_y,_z){a=_a;}
    ~Derived2(){cout<<"Derived2 Dest";}
    void Show() override
    {
        cout<<"I'm Derived2"<<endl;
    }
};

int main ()
{
    Base *bPtr=new Derived2(1,2,3);
    bPtr->Show(); //i'm derived2

    Derived *dptr=new Derived2(5,6,7);
    dptr->Show(); //i'm  Derived2

    Base * bPtr=new Derived(3,4);
    bPtr->show(); //i'm derived

    //NOOOOOO
    //Derived2* dPtr=new Base(1,2);

    ////Search
    Base* bPtr=new Derived2(3,4,4,4);
    delete bPtr; //call base dest
    ///Solution??? Y  -> virtual destructor
    ////
}

///////////////////////////////////////////////////

class Geoshape
{
    protected:
    float dim1;
    float dim2;
    public:
    void setDim1(float _dim1){dim1=_dim1;}
    void setDim2(float _dim2){dim2=_dim2;}
    float getDim1(){return dim1;}
    float getDim2(){return dim2;}
    Geoshape(){dim1=dim2=0;}
    Geoshape(float _dim1,float _dim2)
    {dim1=_dim1;dim2=_dim2;}
    ~Geoshape(){}
    virtual float CArea()
    {return -1;}
};

class Rect:public Geoshape
{
    //fields??? No
    public:
    Rect(){}
    Rect(float _d1,float _d2):Geoshape(_d1,_d2)
    {dim1=_d1;dim2=_d2;}
    ~Rect(){}
    float CArea(){return dim1*dim2;}
};

class Square:public Geoshape
{
    public:
    Square(){}
    Square(float _dim):Geoshape(_dim,_dim)
    {dim1=dim2=_dim;}
    ~Square(){}
    float CArea(){return dim1*dim2;}
};
class Circle:public Geoshape
{
    public:
    Circle(){}
    Circle(float _radius): Geoshape(_radius,_radius)
    {dim1=dim2=_radius;}
    ~Circle(){}
    float CArea()
    {return 3.14*dim1*dim2;}
};
class Tri:public Geoshape
{
    public:
    Tri(){}
    Tri(float _base,float _height):Geoshape(_base,_height)
    {}
    ~Tri(){}
    float CArea()
    {return 0.5*dim1*dim2;}
};

///Failure on Open closed principle
float SumOfAreas(Square* sarr,int sSize,Rect* rarr,int rSize)
{
    float sum=0;
    for(int i=0;i<sSize;i++)
    {
        sum+=sarr[i].CArea();
    }
    for(int i=0;i<rSize;i++)
    {
        sum+=rarr[i].CArea();
    }
    return sum;
}


//Fill in O C Principle
float SumOfAreas2(Geoshape* gArr[],int size)
{
    float sum=0;
    for(int i=0;i<size;i++)
    {
        //sum+=(*gArr[i]).CArea();
        sum+=gArr[i]->CArea();
    }
    return sum;
}

float SumOfAreas2(Geoshape** gArr,int size)
{
    float sum=0;
    for(int i=0;i<size;i++)
    {
        //sum+=(*gArr[i]).CArea();
        sum+=gArr[i]->CArea();
    }
    return sum;
}
//V02
int main()
{
    Square sarr[2]={Square(10),Square(5)};
    Rect rarr[3]={Rect(1,1),Rect(2,3),Rect(3,4)};
    Circle c1(3);

    Geoshape* gPtrArr[6]=
    {sarr,&sarr[1],&sarr[2],rarr,&rarr[1],&c1};

    cout<<SumOfAreas2(gPtrArr,6);


    Tri t1(2,3);
    Circle c(3);
    Square s2(10);
    Geoshape* gptrArr[3]={&t1,&c,&s2};
    cout<<SumOfAreas2(gptrArr,3);


    Geoshape obj(3,4);
    cout<<obj.CArea();  //-1
}

//V01
int main()
{
    Square sarr[2]={Square(10),Square(5)};
    Rect rarr[3]={Rect(1,1),Rect(2,3),Rect(3,4)};

    cout<< SumOfAreas(sarr,2,rarr,3); //144
    cout<< SumOfAreas(NULL,0,rarr,3); //144


    Geoshape*gPtr=new Square(10);
    gPtr->CArea();  //100
    return 0;
}

////////////////////////////////////////////

//Restrict Create object from Geoshape
class Geoshape
{
    protected:
    float dim1;
    float dim2;
    public:
    void setDim1(float _dim1){dim1=_dim1;}
    void setDim2(float _dim2){dim2=_dim2;}
    float getDim1(){return dim1;}
    float getDim2(){return dim2;}
    //important for data initiation in inheritance
    Geoshape(){dim1=dim2=0;}
    Geoshape(float _dim1,float _dim2)
    {dim1=_dim1;dim2=_dim2;}
    ~Geoshape(){}
    //abstract [pure virtual] method
    virtual float CArea();

    //pure virtual fn
    //virtual void Hello();
};

class Rect:public Geoshape
{
    //fields??? No
    public:
    Rect(){}
    Rect(float _d1,float _d2):Geoshape(_d1,_d2)
    {dim1=_d1;dim2=_d2;}
    ~Rect(){}
    float CArea() override
    {return dim1*dim2;}
};

class Square:public Geoshape
{
    public:
    Square(){}
    Square(float _dim):Geoshape(_dim,_dim)
    {dim1=dim2=_dim;}
    ~Square(){}
    float CArea() override
    {return dim1*dim2;}
};

int main()
{
    Geoshape obj ;//Compile Error
}

///abstract class
////class we cannot create object from it

///How to make class abstract?
///abstract class is a class Contains
///at least one pure virtual function

//Pure virtual function        ===>abstract function
///virtual function header ONLY =0;


//concrete class : normal class Stack,Complex,Rect


///Pure Virtual function MUST be overridden


////////////////////////////////////////////////

///Abstract method [pure virtual method] Impact

class TypeA
{
    protected:
    int x;
    public:
    void setX(int _x){x=_x;}
    int getX(){return x;}
    TypeA(){x=0;}
    TypeA(int _x){x=_x;}

    virtual void Show()
    {
        cout<<"Hello";
    }  //virtual fn can[not must] be overridden

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
    //    virtual void funTwo()=0;
    //void Show(){}
    
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
    //void Show(){}
};

int main()
{
    TypeA obja;  ///Compile Error //Abstract class

    TypeB objb; ///Compile Error //Abstract class

    TypeC objc; //RUN SUCCESSFUL
}

/////////////////////////////////////////////////////

#include<iostream>
#include"graphics.h"
using namespace std;
class Shape
{
    protected:
    int color;
    public:
    void setColor(int _color){color=_color;}
    int getColor(){return color;}
    Shape(){color=0;}
    Shape(int _color){color=_color;}
    ~Shape(){}
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
    Point(){x=y=0;} //#1 construct start then #2 construct end
    Point(int _x,int _y)
    {x=_x;y=_y;}
    Point(const Point& old)
    {x=old.x;y=old.y;}
    ~Point(){}
};

class Line:public Shape
{
    private:
    Point start;
    Point end;
    public:
    void setStart(Point _start){start=_start;}
    Point getStart(){return start;}
    void setEnd(Point _end){end=_end;}
    Point getEnd(){return end;}
    
    Line()
    {}
    Line(int x1,int y1,int x2,int y2,int _color):
    start(x1,y1),end(x2,y2),Shape(_color)
    {}
    Line(Point _start,Point _end,int _color)
    {
        start=_start;
        end=_end;
        color=_color;
    }
    Line(const Line& old)
    {
        start=old.start;
        end=old.end;
        color=old.color;
    }
    ~Line(){}
    void Draw()
    {
        setcolor(color);
        line(start.getX(),start.getY(),end.getX(),end.getY());
    }
};

class Rect:public Shape
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
    }
    Rect(int x1,int y1,int x2,int y2,int _color):
    ul(x1,y1),lr(x2,y2),Shape(_color)
    {
    }
    ~Rect(){}
    Rect(const Rect& old):ul(old.ul),lr(old.lr),Shape(old.color)
    {
        // ul=old.ul;
        // lr=old.lr;
        // color=old.color;
    }

    void Draw()
    {
        setcolor(color);
        rectangle(ul.getX(),ul.getY(),lr.getX(),lr.getY());
    }

};

//Failure in Open Closed Principle
class OldPicture
{
    Line* lPtr;
    int lSize;
    Rect* rPtr;
    int rSize;
    //
    void setLines(Line* _lPtr,int _lSize)
    {
        lPtr=_lPtr;
        lSize=_lSize;
    }
    void setRects(Rect* _rPtr,int _rSize)
    {
        rPtr=_rPtr;
        rSize=_rSize;
    }
    //
    Picture()
    {
        lPtr=NULL;
        rPtr=NULL;
        lSize=0;
        rSize=0;
    }

    //
    void DoIt()
    {
        for(int i=0;i<rSize;i++)
        {
            rPtr[i].Draw();
        }

        for(int i=0;i<lSize;i++)
        {
            lPtr[i].Draw();
        }
    }
};

class Picture
{
    private:
    Shape** sptr;
    int size;
    public:
    Picture()
    {
        sptr=NULL;
        size=0;
    }
    void setShapes(Shape** ssptr,int _size)
    {
        sptr=ssptr;
        size=_size
    }

    void DoIt()
    {
        for(int i=0;i<size;i++)
        {
            sptr[i]->Draw();
        }
    }
};

int main()
{
    //initgraph
    Shape* sPtr=new Line(1,2,3,4,5);
    sPtr->Draw();  //do nothing  //copy of ptr
    //after virtual
    sPtr->Draw(); //call draw of line

    Line lArr[2]={Line(),Line()};
    Circle cArr[2]={Circle(),Circle()};
    Tri t(2,3,4,5,6,7,8);
    Rect r1(1,2,3,4,5);
    Shape* sPtrArr[6]=
    {lArr,&lArr[1],cArr,&cArr[1],&r1,&t}; 
    for (int i = 0; i < 6; i++)
    {
        sPtrArr[i]->Draw();
    }

    Picture p1;
    
    p1.setShapes(sPtrArr,6);
    p1.DoIt();
    p1.setShapes(NULL,0);

}

int main()
{
    Line lArr[2]={Line(),Line()};
    Circle cArr[2]={Circle(),Circle()};
    Tri tArr[2]={Tri(),Tri()};
    Rect r1(1,2,3,4,5);
    Shape* sPtrArr[7]=
    {lArr,&lArr[1],cArr,&cArr[1],&r1,&tArr,&tArr[1]}; 

    Picture p1;
    p1.setShapes(sPtrArr,7);
    p1.DoIt();
}

////////////////////////////////////////
//Lab 

///1- Aggrigation on picture   abagora
///2- Geoshape abstract and sumOfAreas function
///3- try 2 pure virtual fn in class


