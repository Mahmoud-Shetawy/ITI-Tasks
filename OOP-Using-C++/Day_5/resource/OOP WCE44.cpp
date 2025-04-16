//1-Inheritance
//2-Aggregation[association]
////////////////////////////////////////////////////////
//OOR
//4- Inheritance

//Inheritance:
///Extending methods and fields from
///class to another one

///new datatype =>receiving methods and fields
///Was created actually in another datatype

//RULES////////////////////////////////////////////////////
///private:member can be acessed inside class/struct ONLY
///Child DT inherits EVERYTHING from Parent except ....ctor,static

/////////////////////////////////////////////////////////
////TypeA
////x
////y
////FunOne()
////FunTwo()

////TypeB
////y
////z
////FunTwo()
////FunThree()
//////////////////////////////////////////////////

////Base
////y
////FunTwo()

////TypeA Inherits Base
////x
////FunOne()

////TypeB Inherits Base
////z
////FunThree()


//////////////////////////////////////////////////////
#include<iostream>
using namespace std;

class Parent
{
    int x;
    int y;
    public:
    void SetX(int _x){x=_x;}
    int GetX(){return x;}
    void SetY(int _y){y=_y;}
    int GetY(){return y;}
    Parent()
    {
        x=y=0;
        cout<<"Parent def ctor";
    }
    Parent(int _x,int _y)
    {
        x=_x;y=_y;
        cout<<"Parent 2p ctor";
    }
    ~Parent(){cout<<"dest";}
    int SumXY()
    {
        return x+y;
    }
};

//public:Types of inheritance
//child Dt inherits everything from parent
class Child: public Parent
{
    //x,y,setx,sety,getx,gety,sumxy
    int z;
    public:
    void SetZ(int _z){z=_z;}
    int GetZ(){return z;}
    Child()
    {
        //c1 x0 y0 z?
        z=0;
        //c1 x0 y0 z0
        //x=0;y=0; //compile Error Inaccessible
        //useless
        // this->SetX(0);
        // SetY(0); 
        cout<<"child def ctor";
    }
    
    Child(int _x,int _y,int _z):Parent(_x,_y)
    {
        //c2 x1 y2 z?
        z=_z;
        //c2 x1 y2 z3
        //this->SetX(_x);
        //this->SetY(_y);
        cout<<"child 3p ctor";
    }
    ~Child(){}
    int SumXYZ()
    {
        return z+GetX()+GetY();
        //return z+this->SumXY();
        //return x+y+z;
    }
};
int main()
{
    ///in main you can access public member by object name
    Parent p1; //8B  x0 y0
    
    Child c2(1,2,3);
    //o/p
    cout<<c2.SumXYZ(); //6
    cout<<c2.SumXY(); //3

    Child c1;  //12B  x0 y0 z?
    //o/p
    //parent def ctor
    //child def ctor
    //child dest
    //parent dest
    return 0;
}

//////////////////////////////////////////////////////
//is there any way to access private member in child class?
//YES if it became protected

///protected[smart private]
//member can be accessed 
//inside class
//and accessed inside chain of inheritance
//ONLY


class Parent
{
    protected:
    int x;
    int y;
    public:
    void SetX(int _x){x=_x;}
    int GetX(){return x;}
    void SetY(int _y){y=_y;}
    int GetY(){return y;}
    Parent()
    {
        x=y=0;
        cout<<"Parent def ctor";
    }
    Parent(int _x,int _y)
    {
        x=_x;y=_y;
        cout<<"Parent 2p ctor";
    }
    ~Parent(){cout<<"dest";}
    int Sum()
    {
        return x+y;
    }
};

class Child:public Parent
{
    protected:
    int z;
    public:
    void SetZ(int _z){z=_z;}
    int GetZ(){return z;}
    Child()
    {
        z=0;
        x=0;y=0;
    }
    Child(int _x,int _y,int _z)//:Parent(_x,_y)
    {
        x=_x;
        y=_y;
        z=_z;
    }
    ~Child(){}
    int Sum()
    {
        return x+y+z;
        return z+Parent::Sum();
    }
};
int main()
{
    ///access public ONLY
    Parent p1;
    //p1.x=10; //compile error inaccessible

    Child c1(1,2,3);
    cout<<c1.Sum(); //6
    cout<<c1.Parent::Sum(); //3
}


///overriding:
///Overriding  [inheritance]
///Function has same name
///same parameters
//but body/implementation
//is different in sub/child class


//////////////////////////////////////////////////////

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
    double CArea()
    {
        return dim1*dim2;
    }

    // void SetDim1(double _dim1){dim1=dim2=_dim1;}
    // void SetDim2(double _dim2){dim2=dim1=_dim2;}
     void SetDim(double _dim1){dim1=dim2=_dim1;}

};

class Square:protected Geoshape
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

class SquareV2:public Rect
{
    public:
    SquareV2(){}
    SquareV2(double d):Rect(d,d){}
    ~SquareV2(){}
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
int main()
{
    // Square s1;
    // //o/p
    // //geo ctor
    // //sq ctor

    // SquareV2 s2;
    // //o/p
    // //geo ctor
    // //rect ctor
    // //sq ctor

    Rect r1(3,4);
    cout<<r1.CArea(); //12

    Square s1(10);  //s1 dim1 10  dim2 10
    s1.SetDim1(3);  //s1 dim1 3  dim2 3
    s1.SetDim2(4);  //s1 dim1 4  dim2 4
    s1.Geoshape::SetDim2(4);  //compile Error
    cout<<s1.CArea(); //16

    Circle c1(7);
    c1.SetDim1(5);
    c1.SetDim2(6);
    cout<<c1.CArea();

    return 0;
}


///////////////////////////////////////////
//TYPES OF INHERITANCE
//A. Public

class Parent
{
    int x;
    protected:
    int y;
    public:
    int z;
    void setX(int _x){x=_x;}
    void setY(int _y){y=_y;}
    void setZ(int _z){z=_z;}
    int getX(){return x;}
    int getY(){return y;}
    int getZ(){return z;}
    Parent()
    {
        //x,y,z
        x=y=z=0;
    }
    int sum()
    {
        return x+y+z;
    }

};
class Child :public Parent
{
    //x,y,z,sss,ggg,sum
    int a;
    protected:
    int b;
    public:
    int c;
    void setA(int _a){a=_a;}
    void setB(int _b){b=_b;}
    void setC(int _c){c=_c;}
    int getA(){return a;}
    int getB(){return b;}
    int getC(){return c;}
    Child()
    {
        a=b=c=y=z=0;   //x XXX
    }
    int sum()
    {
        return getX()+y+z+a+b+c;
        return a+b+c+Parent::sum();
    }
};

class SubChild:public Child
{
    ///  
    int j;
    protected:
    int k;
    public:
    int l; 
    SubChild()
    {
        y=z=b=c=j=k=l=0;  //x,a XXX
    }
    int sum()
    {
        
    }
}

main()
{
    Parent p;
    //p. PUBLIC ONLY  z

    Child c;
    //c. PUBLIC ONLY  z,c

    SubChild sc; //PUBLIC ONLY z,c,l
     

}

/////////////////////////////////////////////////////////
//B. Protected
class Parent
{
    int x;
    protected:
    int y;
    public:
    int z;
    void setX(int _x){x=_x;}
    void setY(int _y){y=_y;}
    void setZ(int _z){z=_z;}
    int getX(){return x;}
    int getY(){return y;}
    int getZ(){return z;}
    Parent()
    {
        //x,y,z
        x=y=z=0;
    }
    int sum()
    {
        return x+y+z;
    }

};
class Child :protected Parent
{
    //x private still private , cannot access it
    //y protected still protected can be accessed
    //z ,sss,ggg,sum public promotes to protected can be accessed
    int a;
    protected:
    int b;
    public:
    int c;
    void setA(int _a){a=_a;}
    void setB(int _b){b=_b;}
    void setC(int _c){c=_c;}
    int getA(){return a;}
    int getB(){return b;}
    int getC(){return c;}
    Child()
    {
        //x XXXX
    }
    int sum()
    {
        
    }
};

class SubChild:protected Child
{
    //x,a private still priv cannot access
    //y protected still prot can be accessed
    //z protected still prot can be accessed
    //b protected still prot can be accessed
    //c public promotes to prot can be accessed
    int j;
    protected:
    int k;
    public:
    int l; 
    SubChild()
    {
        //XXX  x,a
    }
    int sum()
    {
       
    }
};

main()
{
    Child c;
    //c. setZ

    SubChild sc;  //l
    //sc.x,y,z,a,b,c ???? XXXX
    //sc.setC() 
}


/////////////////////////////////////////////
//C. Private  RARELY USED
class Parent
{
    int x;
    protected:
    int y;
    public:
    int z;
    void setX(int _x){x=_x;}
    void setY(int _y){y=_y;}
    void setZ(int _z){z=_z;}
    int getX(){return x;}
    int getY(){return y;}
    int getZ(){return z;}
    Parent()
    {
        //x,y,z
        x=y=z=0;
    }
    int sum()
    {
        return x+y+z;
    }

};
class Child :private Parent
{
    //x priv [not accessed here]
    //y protected promotes to private [accessed here]
    //z public promotes to private [accessed here]  
    //setters&getters  sum private [accessed here]
    
    int a;
    protected:
    int b;
    public:
    int c;
    void setA(int _a){a=_a;}
    void setB(int _b){b=_b;}
    void setC(int _c){c=_c;}
    int getA(){return a;}
    int getB(){return b;}
    int getC(){return c;}
    Child()
    {
        //y,z,a,b,c ,parent setters   ///x XXX
    }
    int sum()
    {
        return y+z+a+b+c+getX();
    }
};

class SubChild:private Child
{
    //x private [not accessed] 
    //y private [not accessed]
    //z private [not accessed]
    //a private [not accessed]
    //b private [accessed]
    //c private [accessed]
    //child setter and getter private [accessed]
    //parent setter and getter private [not accessed]
    //sum() parent private [not accessed]
    //sum() child private [accessed]
    int j;
    protected:
    int k;
    public:
    int l; 
    SubChild()
    {
        //xN yN zN aN bT cT
    }
    int sum()
    {
        
    }
};

int main()
{
    Child c1;  //c //setter&getters of child
    SubChild sc1; //l
}

//////////////////////////////////////////////

//Most Commonly used class:public class
//C# java ONLY class: class   public

//////////////////////////////////////////////
class Point
{
    private:
    int x;
    int y;
    public:
    void SetX(int _x){x=_x;}
    void SetY(int _y){y=_y;}
    int GetX(){return x;}
    int GetY(){return y;}
    
    Point()
    {
        x=y=0;
        cout<<"Point def ctor";
    }
    Point(int _x,int _y)
    {
        x=_x;y=_y;
        cout<<"Point 2p ctor";
    }
    ~Point(){cout<<"Point dest";}
    Point(const Point& old){x=old.x;y=old.y;cout<<"cpy ctor";}
};

int main()
{
    Point p1(3,4);  //stack 8B

    //anonymous object
    Point(3,4);
    //call ctor & then dest at same time

    Point parr[3]; //stack  8*3B
    //point def ctor
    //point def ctor
    //point def ctor
    
    Point p1,p2,p3
    Point parr3[3]={p1,p2,p3};

    Point parr2[3]={Point(3,4),Point(3,4),Point(3,4)};
    //point 2p ctor
    //point 2p ctor
    //point 2p ctor

    Point* pPtr=new Point(3,4);
    //o/p
    //point 2p ctor
    delete pPtr;  //use without[] when delete one object
    //point dest

    Point * pPtr2=new Point[3]; ///|0,0||0,0||0,0|
    //point def ctor
    //point def ctor
    //point def ctor
    //pPtr2[0].SetX(3);

    delete[] pPtr2;
    //point dest
    //point dest
    //point dest
}

////////////////////////////////////////////////////

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
    void DrawLine()
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
    void DrawRect()
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
    void DrawCircle()
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
    void DrawTriangle()
    {
        setcolor(color);
        trainlgle(); //XXXXXX
    }
};


class Picture
{
    private:
    Rect *rPtr;
    int rSize;
    public:
    Picture()
    {
        rPtr=NULL;
        rSize=0;
        //
    }
    void SetRects(Rect *_rPtr,int _rSize)
    {
        rPtr=_rPtr;
        rSize=_rSize;
    }

    void DoIt()
    {
        //
        for (int i = 0; i < rSize; i++)
        {
            rPtr[i].DrawRect();
        }
        
        
    }
};


int main()
{
    Rect r1(2,3,4,5,6);
    Rect rarr[2]={Rect(),Rect()};

    Picture p1;

    //build relationship
    p1.SetRects(&r1,1);

    p1.DoIt();

    //Remove relationship
    p1.SetRects(NULL,0);
}

/////////////////////////////////////////

//abagora via picture  -> dont forget class shape{color}; 
//types of inheritance
///1- area Geoshape   :public :protected




