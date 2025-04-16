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
    void SetX(int _x){x=_x;}
    int GetX(){return x;}
    void SetY(int _y){y=_y;}
    int GetY(){return y;}
    Base(){x=y=0;}
    Base(int _x,int _y){x=_x;y=_y;}
    ~Base(){}
    void Show()
    {
        cout<<"I'm Base";
    }
};

class Derived:public Base
{
    protected:
    int z;
    public:
    void SetZ(int _z){z=_z;}
    int GetZ(){return z;}
    Derived(){z=0;}
    Derived(int _x,int _y,int _z){x=_x;y=_y;z=_z;}
    ~Derived(){}
    void Show()
    {
        cout<<"I'm Derived";
    }
};

class Derived2:public Derived
{
    int a;
    public:
    //
    //
    Derived2(){a=0;}
    Derived2(int _x,int _y,int _z,int _a)
    {
        //
    }
    ~Derived2(){}
    void Show()
    {
        cout<<"i'm Derived2";
    }
};

int main()
{
    Base b1(3,4); //stack 8B
    b1.Show(); //i'm base
    Derived d1(1,2,3); //stack  //12B
    d1.Show(); //i'm derived

    Base * bPtr=&b1;  //T
    bPtr->Show(); //i'm base ///o.s will retrieve show() copy of pointer type

    Derived *dPtr=&d1; //T
    dPtr->Show(); //i'm derived ///o.s will retrieve show() copy of pointer type
 
    dPtr=new Derived(1,2,3); //heap
    dPtr->Show(); //i'm derived ///o.s will retrieve show() copy of pointer type
 
    bPtr=new Base(1,2);
    bPtr->Show(); //i'm base ///o.s will retrieve show() copy of pointer type
    
    return 0;
}

int main()
{
    Derived d1(1,2,3);

    //Base* bPtr=&d1;  //T
    //الأب يحتوي جميع ابناؤه
    //you can create pointer of parent carry address object from its childs
    //car is a viechle
    //bus is a viechle 

    Base* bPtr=new Derived(1,2,3);
    bPtr->Show(); //i'm base
    ///o.s will retrieve show() copy of pointer type

    bPtr=new Derived2(1,2,3,4); //new Derived2[4]
    bPtr-> Show(); //i'm base

    Derived *dPtr=new Derived2(4,5,6,7);
    dPtr->Show(); //i'm Derived
    return 0;
}

//////////////////////////////////////////
class Human
{
    protected:
    string name;
    public:
    void MyName()
    {
        cout<<"this functin will be overridden";
    }
};
class Male:public Human
{
    public:
    void MyName()
    {
        cout<<"my name is"<<name;
    }
};
class Female:public Human
{
    public:
    void MyName()
    {
        cout<<"my name is"<<name;
    }
    Female(string _name){}
};

int main()
{
    Human *hPtr=new Female("Aya"); //T
    hPtr->MyName(); //this functin will be overridden
    //Human obj; ???NOOOO
}
//////////////////////////////////////////
//Early/Static Binding


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

///How?
//1-function to be overridden in base class[fst level] must be public and virtual
//2-child class must inherit from public
//3-overridden function also must be public
//4- make pointer from parent that points object from its childs

class Base
{
    protected:
    int x,y;
    public:
    void SetX(int _x){x=_x;}
    int GetX(){return x;}
    void SetY(int _y){y=_y;}
    int GetY(){return y;}
    Base(){x=y=0;}
    Base(int _x,int _y){x=_x;y=_y;}
    ~Base(){}
    virtual void Show()
    {
        cout<<"I'm Base";
    }
};

class Derived:public Base
{
    protected:
    int z;
    public:
    void SetZ(int _z){z=_z;}
    int GetZ(){return z;}
    Derived(){z=0;}
    Derived(int _x,int _y,int _z){x=_x;y=_y;z=_z;}
    ~Derived(){}
    void Show() override
    {
        cout<<"I'm Derived";
    }
};
//override -> safety factor

class Derived2:public Derived
{
    int a;
    public:
    //
    //
    Derived2(){a=0;}
    Derived2(int _x,int _y,int _z,int _a)
    {
        //
    }
    ~Derived2(){}
    void Show() override
    {
        cout<<"i'm Derived2";
    }
};


int main()
{
    Base *bPtr=new Derived(1,2,3);
    bPtr->Show(); //i'm Derived

    Base *bPtr2=new Derived2(1,2,3,34);
    bPtr2->Show(); //i'm derived2

    Derived *dPtr=new Derived2(5,6,7,8);
    dptr->Show(); //i'm derived2
    return 0;
}

////////////////////////////////////////////////////////
class Geoshape
{
    protected:
    double dim1;
    double dim2;
    public:
    void SetDim1(double _dim1){dim1=_dim1;}
    double GetDim1(){return dim1;}
    void SetDim2(double _dim2){dim2=_dim2;}
    double GetDim2(){return dim2;}
    Geoshape()
    {
        cout<<"Geo def ctor";
        dim1=dim2=0;
    }
    Geoshape(double _dim1,double _dim2)
    {
        cout<<"Geo 2p ctor";
        dim1=_dim1;dim2=_dim2;
    }
    ~Geoshape(){cout<<"";}
    virtual double CArea()
    {
        return -1;
    }
};

class Rect:public Geoshape
{
    //fields? No
    public:
    Rect()
    {
        //dim1=dim2=0;
        cout<<"Rect ctor";
    }
    Rect(double d1,double d2)//:Geoshape(d1,d2)
    {
        dim1=d1;dim2=d2;
        cout<<"Rect ctor";
    }
    ~Rect(){}
    double CArea() //override /*safety factor*/ 
    {
        return dim1*dim2;
    }
};

class Square:public Geoshape
{
    public:
    Square()
    {
    }
    Square(double _dim):Geoshape(_dim,_dim)
    {
        // dim1=dim2=_dim;
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
    Circle(double _radius):Geoshape(_radius,_radius)
    {}
    ~Circle(){}
    double CArea()
    {
        return dim1*dim2*(22/7); 
    }
};
class Tri:public Geoshape
{
    public:
    Tri(){}
    Tri(double _base,double _height):Geoshape(_height,_base)
    {}
    ~Tri(){}
    double CArea()
    {
        return 0.5 * dim1* dim2;
    }

}; 
//failure in Open closed principle  SOLID

double SumOfAreas(Rect *rPtr,int rSize,Square *sPtr,int sSize,Circle *cPtr,int cSize)
{
    double sum=0;
    for (int i = 0; i < rSize; i++)
    {
        sum+=rPtr[i].CArea();
    }
    for (int i = 0; i < sSize; i++)
    {
        sum+=sPtr[i].CArea();
    }
    for (int i = 0; i < cSize; i++)
    {
        sum+=cPtr[i].CArea();
    }
    return sum;
}

//succeed in Open closed principle
// void MultipleArray(int arr[] ,int _size){}
// void MultipleArray(int* arr ,int _size){}
// void MultipleArray(int* arr[] ,int _size){}
// void MultipleArray(int** arr ,int _size){}
// double SumOfAreasV2(Geoshape* garr[],int gSize)
double SumOfAreasV2(Geoshape** garr,int gSize)
{
    double sum=0;
    for (int i = 0; i < gSize; i++)
    {
        sum+=garr[i]->CArea();
        //sum+=(*garr[i]).CArea();
    }
    return sum;
}
//
// int main()
// {
//     Rect rarr[3]={Rect(2,3),Rect(2,5),Rect(2,50)};
//     Square s(10);
//     Circle c(7);
//     Tri tarr[2]={Tri(3,4),Tri(5,6)};
//     cout<< SumOfAreas(rarr,3,&s,1);
//     return 0;
// }

int main()
{
    Geoshape *gPtr=new Rect(3,4);   //T
    cout<< gPtr->CArea(); //12

    // Geoshape *gPtr1;
    // Geoshape *gPtr2;
    // Geoshape *gPtr3;
    // Geoshape *gPtr4;
    // Geoshape *gPtr5;

    Rect rarr[3]={Rect(2,3),Rect(2,5),Rect(2,50)};
    Square s(10);
    Circle c(7);
    Tri tarr[2]={Tri(),Tri()};
    Geoshape* garr[7]={rarr,&rarr[1],&rarr[2],&s,&c,tarr,&tarr[1]};
    cout<< SumOfAreasV2(garr,7);

    // cout<< (*garr[0]).CArea(); //12
    // cout<< garr[0]->CArea(); //12


    //Geoshape obj;
    //object from geoshape
    //is there any way to restrict create object
    //from Geoshape? 
    //YES
    //If geoshape class became abstract class
    return 0;
}

//abstract class:
//class we cannot create object from it

//how to make class to be abstract
//abstract class is class contains
//at least one pure virtual function 

//pure virtual function?
//virtual function prototype[header] only =0;

/// pure virtual fn you MUST Override it
//if not  ,child class will be also abstract class

//concrete class:norrmal class

class Trial
{
    public:
    int x;
    //pure virtual fn
    virtual void Show()=0;
};
int main()
{
    Trial obj; //Compile Error //cannot create instance from Trial
}

class Geoshape
{
    protected:
    double dim1;
    double dim2;
    public:
    void SetDim1(double _dim1){dim1=_dim1;}
    double GetDim1(){return dim1;}
    void SetDim2(double _dim2){dim2=_dim2;}
    double GetDim2(){return dim2;}
    Geoshape()
    {
        cout<<"Geo def ctor";
        dim1=dim2=0;
    }
    Geoshape(double _dim1,double _dim2)
    {
        cout<<"Geo 2p ctor";
        dim1=_dim1;dim2=_dim2;
    }
    ~Geoshape(){cout<<"";}
    virtual double CArea()=0;
    
    //virtual void Hello()=0;
};

int main()
{
    Geoshape obj ; //Compile Error
    //Geoshape* gPtr; //T  //pointer not object
    Geoshape garr[5]; //compile Error
    Geoshape* garr[5]; //T

    //Search
    Rect* rPtr=new Rect(3,4);
    delete rPtr;  //call rect dest
    //
    Geoshape * gPtr=new Rect(3,4);
    delete gPtr; //call geoshape dest
    delete gPtr; //call rect dest //virtual destructor
}


///////////////////////////////////////////////////////
class TypeA
{
    protected:
    int x;
    public:
    //
    //
    TypeA(){x=0;}
    TypeA(int _x){x=_x;}
    ~TypeA(){}
    virtual void FunOne()=0;
    virtual void FunTwo()=0;
    virtual void Show(){cout<<"Hello";}
};

class TypeB:public TypeA
{
    protected:
    int y;
    public:
    //
    //
    TypeB(){y=0;}
    TypeB(int _x,int _y){x=_x;y=_y;}
    ~TypeB(){}
    void FunOne()
    {
        cout<<"Override from class typeB";
    }
    //    virtual void FunTwo()=0;
};

class TypeC:public TypeB
{
    protected:
    int z;
    public:
    //
    //
    //
    //
    //
    void FunTwo()
    {
        cout<<"Override inside typeC";
    }
};

int main()
{
    TypeA objA; //Compile Error
    TypeB objB; //Compile error
    TypeC objC; //T 
}

//////////////////////////////////////////////////////


class Shape
{
    protected:
    int color;
    public:
    void SetMyColor(int _color){color=_color;}
    int GetMyColor(){return color;}
    Shape(){color=0;}
    Shape(int _color){color=_color;}
    ~Shape(){}
    Shape(const Shape& old){}
    virtual void Draw()=0;
};

class Point
{
    int x;
    int y;
    public:
    void SetX(int _x){x=_x;}
    void SetY(int _y){y=_y;}
    int GetX(){return x;}
    int GetY(){return y;}
    //l1 start ctor
    //l1 end ctor
    Point()
    {
        x=y=0;
        cout<<"point def ctor";    
    }
    Point(int _x,int _y)
    {
        x=_x;y=_y;
        cout<<"point 2p ctor";    
    }
    Point(const Point& old){x=old.x;y=old.y;cout<<"pnt cpy ctor";}
    ~Point(){cout<<"Point dest";}
};

class Line:public Shape
{
    Point start;
    Point end;
    public:
    void SetStart(Point _start){start=_start;}
    Point GetStart(){return start;}
    void SetEnd(Point _end){end=_end;}
    Point GetEnd(){return end;}
    Line()
    {  
    }
    Line(int x1,int y1,int x2,int y2,int _color)
    :start(x1,y1),end(x2,y2),Shape(_color)
    {
        
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
        line(start.GetX(),start.GetY(),end.GetX(),end.GetY());
    }
};

class Rect:public Shape
{
    private:
    Point ul;
    Point lr;
    public:
    void SetUL(Point _ul){ul=_ul;}
    Point GetUL(){return ul;}
    void SetLR(Point _lr){lr=_lr;}
    Point GetLR(){return lr;}
    Rect()
    {
        
    }
    Rect(int x1,int y1,int x2,int y2,int _color)
    :ul(x1,y1),lr(x2,y2),Shape(_color)
    {
    }
    ~Rect(){}
    Rect(const Rect& old)
    {
        ul=old.ul;
        lr=old.lr;
        color=old.color;
    }
    void Draw()
    {
        setcolor(color);
        rectangle(ul.GetX(),ul.GetY(),lr.GetX(),lr.GetY());
    }
};

class Circle:public Shape
{
    Point center;
    int radius;
    public:
    void SetCenter(Point _center){center=_center;}
    Point GetCenter(){return center;}
    //
    //
    Circle()
    {
        radius=0;
    }
    Circle(int x,int y,int _radius,int _color):center(x,y),Shape(_color)
    {
        radius=_radius;
    }
    ~Circle(){}
    Circle(const Circle& old){}
    void Draw()
    {
        setcolor(color);
        circle(center.GetX(),center.GetY(),radius);
    }
};

class Triangle:public Shape
{
    Point p1,p2,p3;
    public:
    //
    //
    //
    //
    //
    //
    //
    void Draw()
    {
        setcolor(color);
        trainlgle(); //XXXXXX
    }
};

class Polygon:public Shape{};

//open close principle??? YES
class Picture
{
    private:
    Shape ** sPtr;
    int SSize;
    public:
    Picture()
    {
       sPtr=NULL;
       SSize=0;
    }
    void SetShapes(Shape ** _sPtr,int _sSize)
    {
       sPtr=_sPtr;
       SSize=_sSize;
    }

    void DoIt()
    {
        for (int i = 0; i < SSize; i++)
        {
            sPtr[i]->Draw();
        }
        
    }
};


int main()
{
    Shape *sPtr=new Rect(1,2,3,4,5);
    sPtr->Draw(); //hello

    //Shape obj; //compile error

    Circle carr[2]={Circle(),Circle()};
    Line larr[2]={Line(),Line()};
    Tri t1(1,2,3,4,5,6,7);
    Rect r1(1,2,3,4,5);

    Shape* sPtrArr[6]={&r1,carr,larr,&carr[1],&larr[1],&t1};

    Picture p1;

    //build relationship
    p1.SetShapes(sPtrArr,6);

    p1.DoIt();
    //remove relationship without any loss or dependenciies
    p1.SetShapes(NULL,0);
}


//////////////////////////////////////////////////////
///Lab 

///1- Aggrigation on picture   abagora
///2- Geoshape abstract and sumOfAreas function
///3- try 2 pure virtual fn in class TypeA,TypeB,TypeC










