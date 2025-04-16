//1-Inheritance
//2-Aggregation[association]
////////////////////////////////////////////////////
//OOR
//4- Inheritance

//Inheritance:
///Extending methods and fields from
///DT to another one

///new datatype =>receiving methods and fields
///Was created actually in another datatype

//RULES////////////////////////////////////////////////////
///Child inherits EVERYTHING from Parent except...
///private:member can be acessed inside class/struct ONLY

//////////////////////////////////////////////////////////
///TypeA
////x
////y
////funOne()
////funTwo()

///TypeB
////y
////z
////funTwo()
////funThree()

//Solution//////////////////////////////
///Base
////y
////funTwo()

///TypeA inherits Base
////x
////funOne()

///TypeB inherits Base
////z
////funThree()

#include<iostream>
using namespace std;
class Parent
{
    private:
    int x;
    int y;
    public:
    void SetX(int _x){x=_x;}
    int GetX(){return x;}
    void SetY(int _y){y=_y;}
    int GetY(){return y;}
    //c2 call ctor to initialize inherited data
    Parent()
    {
        x=y=0;
        cout<<"Parent def ctor";
    }
    Parent(int _left,int _right)
    {
        x=_left;y=_right;
        cout<<"Parent 2p ctor";
    }
    ~Parent(){cout<<"PArent dest";}
    Parent(const Parent& old){x=old.x;y=old.y;}
    int SumXY()
    {
        return x+y;
    }

};

////////////////////////////////////////////////////////////////////////////////////////////////////////
//public: type of inheritance inside child 
//Rule #1:Inheritance: CHILD INHERITS EVERYTHING
//private ,public inherited
//??? What child will Access???
//Rule #2:Private member:
//          member accessed inside class ONLY
//      Public member:
//          member accessed inside/outside class
//Rule #3: study??? 
//              1- ctors inherites????
//              2- static inherits????
/////////////////////////////////////////////////
///SOLID  -->O Open for Extension,Closed for modification
/////////////////////////////////////////////////
class Child:public Parent
{
    //x,y,setx,sety,getx,gety,sumxy
    int z;
    public:
    void SetZ(int _z){z=_z;}
    int GetZ(){return z;}
    Child()
    {
        //c1  x|0| y|0| z|?|
        z=0; //T
        //c1  x|0| y|0| z|0|
        //x=y=0; //compile Error //inaccessible
        //useless
        //this->SetX(0);
        //SetY(0);
        cout<<"Child ctor";
    }

    Child(int _x,int _y,int _z):Parent(_x,_y)
    {
        //c2  x|1| y|2| z|?|
        //x=_x,y=_y; //compile Error
        z=_z;
        //c2  x|1| y|2| z|3|
        //after ctor chaining [useless]
        //SetX(_x);
        //SetY(_y);
        cout<<"child 3p ctor"<<endl;  
    }
    Child(const Child& old)//:Parent(old)
    {
        z=old.z;
        SetX(old.GetX());
        SetY(old.GetY());
    }
    ~Child(){cout<<"Ch dest";}
    int SumXYZ()
    {
        //return x+y+z; //compile Error x,y
        return z+GetX()+GetY();
        return z+SumXY();
    }
};


int main()
{
    Parent p1(1,2); //Stack  //8B  x|0| y|0|
    cout<<p1.SumXY(); //3

    Child c1;  //stack  //12B  x|0| y|0| z|$|
    //o/p
    //parent ctor
    //child ctor

    Child c2(1,2,3);
    //o/p
    //parent ctor
    //child ctor
    //child dest
    //parent dest
    cout<< c2.SumXY(); //3
    cout<< c2.SumXYZ();//6
}

////////////////////////////////////////////////////
//protected [smart private]  [inheritance]
//member can be accessed
//inside class
//and accessed inside chain of inheritance
//only
#include<iostream>
using namespace std;
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
    //c2 call ctor to initialize inherited data
    Parent()
    {
        x=y=0;
        cout<<"Parent def ctor";
    }
    Parent(int _left,int _right)
    {
        x=_left;y=_right;
        cout<<"Parent 2p ctor";
    }
    ~Parent(){cout<<"PArent dest";}
    Parent(const Parent& old){x=old.x;y=old.y;}
    int Sum()
    {
        return x+y;
    }

};

class Child:public Parent
{
    //x,y,setx,sety,getx,gety,sumxy
    int z;
    public:
    void SetZ(int _z){z=_z;}
    int GetZ(){return z;}
    Child()
    {
        z=0;
        //x=y=0;  //YES  //useless
        cout<<"Child ctor";
    }

    Child(int _x,int _y,int _z):Parent(_x,_y)
    {
        z=_z;
        //x=_x;y=_y; //YES //useless with ctor chaining
        cout<<"child 3p ctor"<<endl;  
    }
    Child(const Child& old)//:Parent(old)
    {
        z=old.z;
        x=old.x;
        y=old.y;
    }
    ~Child(){cout<<"Ch dest";}
    int Sum()
    {
        return z+x+y;
        return z+Sum(); //stack overflow
        return z+ Parent::Sum();
    }
};

int main()
{
    Parent p1(1,2);
    //p1.x=22; //compile Error inaccessible
    Child c1(1,2,3);
    cout<<c1.Sum(); //6
    cout<<c1.Parent::Sum(); //3 //not make sense
    return 0;
}

////////////////////////////////////////////////////
// overriding [inheritance]
// function has the same name and same parameters but body is different in child DT


///
//////////////////////////////////////////////////////

class Geoshape
{
    protected:
    double dim1;
    double dim2;
    public:
    void SetDim1(double _dim1)
    {dim1=_dim1;}
    double GetDim1()
    {return dim1;}
    void SetDim2(double _dim2)
    {dim2=_dim2;}
    double GetDim2()
    {return dim2;}
    Geoshape()
    {
        dim1=dim2=0;
        cout<<"geo def ctor";
    }
    Geoshape(double _dim1,double _dim2)
    {
        dim1=_dim1;
        dim2=_dim2;
        cout<<"gep 2p ctor";
    }
    Geoshape(double _dim)
    {
        dim1=dim2=_dim;
        cout<<"geo 1p ctor";
    }
    ~Geoshape(){cout<<"Geo dest";}
};

class Rect:public Geoshape
{
    //fields???NOOOO
    public:
    Rect()
    {
        //dim1=dim2=0; //useless
        cout<<"rect ctor";
    } 
    Rect(double _x,double _y)//:Geoshape(_x,_y)
    {
        dim1=_x;
        dim2=_y;
        cout<<"rect ctor";
    }
    ~Rect()
    {
        cout<<"Rect dest";
    }
    double CArea()
    {
        return dim1*dim2;
    }
    //overriding
    void SetDim1(double _dim1)
    {dim1 =dim2=_dim1;}
    void SetDim2(double _dim2)
    {dim2=dim1=_dim2;}
    //

};
//
class Square:protected Geoshape  //all public in parent inherited here as a protected
{
    //dim1,dim2 prot
    //set set get get //proteected
    public:
    Square()
    {}
    Square(double _dim):Geoshape(_dim)//Geoshape(_dim,_dim)
    {
        //dim1=dim2=_dim;
    }
    ~Square(){}
    double CArea()
    {
        return dim1*dim2;
    }
};
//
class SquareV2:public Rect
{
    public:
    SquareV2(){}
    SquareV2(double _d):Rect(_d,_d){}
    ~SquareV2(){}
};
//
class Circle:public Geoshape
{
    public:
    Circle(){}
    Circle(double _radius):Geoshape(_radius)
    {}
    ~Circle(){}
    double CArea()
    {
        return   dim1 * dim2 *(22/7);
        return   dim1 * dim2 * 3.14;
        return   dim1 * dim2 * math.pi; //M_PI
    }
};
//
class Tri:public Geoshape
{
    public:
    Tri(){}
    Tri(double _base,double _height):Geoshape(_height,_base)
    {}
    ~Tri(){}
    double CArea()
    {
        return 0.5 * dim1 *dim2;
    }
};

int main()
{
    SquareV2 s2(10);
    //o/p
    //geo ctor
    //rect ctor
    //sqv2 ctor
    //sqv2 dest
    //rect dest
    //geo dest

    Rect r1;
    //o/p
    //geo ctor
    //rect ctor
    //rect dest
    //geo dest

    Rect r2(3,4);
    Square s1(10);

    Tri t1(3,4);
    cout<<t1.CArea(); //6

    ///square ,circle
    Square s3(10); //s3 dim1|10| dim2|10|
    s3.Geoshape::SetDim1(3); //s3 dim1|3| dim2|10|
    s3.Geoshape::SetDim2(4); //s3 dim1|3| dim2|4|

    s3.SetDim1(3); 
    s3.SetDim2(4);  
    cout<<s3.CArea(); //12


    return 0;
}
///////////////////////////////////////////////////
//TYPES OF INHERITANCE
//A. Public [Most Commonly used]

class Parent
{
    private:
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
    //x priv,   y prot,   z,sss,ggg,sum  public
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
        getX()=y=z=a=b=c=0; //x XXXX   
    }
    int sum()
    {
        return y+z+a+b+c+getX();
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
        y=z=b=c=j=k=l=0; //x,a
    }
    int sum()
    {
        return y+z+b+c+j+k+l+getX()+getA();
        return j+k+l+Child::sum();
    }
}

main()
{
    Parent p;
    //p. PUBLIC ONLY  z sss ggg sum 

    Child c;
    //c. PUBLIC ONLY  z,c,  Parent::sssggg ,chils::sssggg ,sum 

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
    //x private still private cannot access
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
        y=z=a=b=c=0;  //x
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

    //(x,y,z)=> SETTERS&Getters [protected]
    //(a,b,c)=> SETTERS&Getters [protected]
    //(j,k,l)=> SETTERS&Getters [public]

    //
    int j;
    protected:
    int k;
    public:
    int l; 
    //
    //
    SubChild()
    {
        y=z=b=c=j=k=l=0; //x,a
    }
    int sum()
    {
        return y+z+b+c+j+k+l+getX()+getA();
        return j+k+l+Child::sum();
    }
};

main()
{
    Parent p1; p1.z=22;
    Child c1; // c1.Parent::sum()=77; //compile Error 
    //c. setZ

    SubChild sc;   //x y z a b c j k l
    //sc.x,y,z,a,b,c ???? XXXX
    //sc.setC() //XXXX
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
        y=z=a=b=c=getx()=0; //x
    }
    int sum()
    {
        return y+z+a+b+c+getX();
    }
};

class SubChild:/*private*/Child
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
//
//Most Commonly used class:public class
//C# java ONLY class X:Y class   public

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
    Point p1(3,4);
    //call 2p ctor
    //call point dest

    Point parr[3]; //Stack   //24B
    //call def ctor
    //call def ctor
    //call def ctor

    Point(3,4);
    //anonymous object
    //compiler call ctor and then dest sequentially

    Point parr[3]={Point(3,4),Point(3,4),Point(3,4)};
    //call 2p ctor
    //call 2p ctor
    //call 2p ctor

    Point *pPtr= new Point(3,4);
    //call 2p ctor
    delete pPtr; //remove protection on non array [object]
    //call dest

    Point *pParr= new Point[3];
    //call def ctor
    //call def ctor
    //call def ctor
    ///dynamic allocation to array
    ///Compiler will always create by def ctor
    pParr[0].SetX(3);
    pParr[0].SetY(4);

    delete [] pParr;
    //call dest
    //call dest
    //call dest

}

////////////////////////////////////////////////////////
//Aggregation / Association

#include<iostream>
#include"graphics.h"
using namespace std;

class Shape
{
    protected:
    int mnfcolor;
    public:
    void SetMnfcolor(int _mnfcolor){mnfcolor=_mnfcolor;}
    int GetMnfcolor(){return mnfcolor;}
    Shape()
    {
        mnfcolor=0;
    }
    Shape(int _mnfcolor)
    {
        mnfcolor=_mnfcolor;
    }
    ~Shape(){}
    Shape(const Shape& old)
    {
        mnfcolor=old.mnfcolor;
    }
};

class Point
{
    int x;
    int y;
    public:
    void SetX(int _x){x=_x};
    int GetX(){return x;}
    void SetY(int _y){y=_y};
    int GetY(){return y;}
    //l2 call this to construct start
    //l2 call this to construct end
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
    Point(const Point& old) //useless //if you write cctor in one DT, then you must implement it in ALL DT coming next related to point
    {x=old.x;y=old.y;cout<<"cpy ctor";}
    ~Point(){cout<<"point dest";}
};

class MNFLine:public Shape
{
    private:
    Point start;
    Point end;
    public:
    void SetStart(Point _start){start=_start;}
    Point GetStart(){return start;}
    void SetEnd(Point _end){end=_end;}
    Point GetEnd(){return end;}
    MNFLine()
    {
        
    }
    
    MNFLine(int x1,int y1,int x2,int y2,int _mnfcolor)
    :start(x1,y1),end(x2,y2),Shape(_mnfcolor)
    {
    }
    MNFLine(const MNFLine& old)
    {
        start=old.start;
        end=old.end;
        mnfcolor=old.mnfcolor;
        cout<<"Line cctor";
    }
    ~MNFLine(){cout<<"line dest";}
    void DrawLine()
    {
        setcolor(mnfcolor);
        line(start.GetX(),start.GetY(),end.GetX(),end.GetY());
        //cout<<"line"<<this->start.GetX();
        //cout<<"line"<<this->start.GetY();
        //cout<<"line"<<this->end.GetX();
        //cout<<"line"<<this->end.GetY();
    }
};

class MNFRectangle:public Shape
{
    private:
    Point ul;
    Point lr; 
    public:
    void SetLR(Point _lr){lr=_lr;}
    void SetUL(Point _ul){ul=_ul;}
    Point GetUL(){return ul;}
    Point GetLR(){return lr;}
    
    MNFRectangle()
    {
    }
    MNFRectangle(int x1,int y1,int x2,int y2,int _mnfcolor)
    :ul(x1,y1),lr(x2,y2),Shape(_mnfcolor)
    {
       
    }
    MNFRectangle(const MNFRectangle& old)
    {
        ul=old.ul;
        lr=old.lr;
        mnfcolor=old.mnfcolor;
        //
    }
    ~MNFRectangle(){cout<<"dest";}
    void DrawRect()
    {
        setcolor(mnfcolor);
        rectangle(ul.GetX(),ul.GetY(),lr.GetX(),lr.GetY());
    }
};

class MNFCircle:public Shape
{
    Point center;
    int radius;
    public:
    void SetCenter(Point _center){center=_center;}
    Point GetCenter(){return center;}
    void SetRadius(int _radius){radius=_radius;}
    int GetRadius(){return radius;}
    MNFCircle()
    {
        radius=0;
    }
    MNFCircle(int x,int y ,int _radius,int _mnfcolor)
    :center(x,y),Shape(_mnfcolor)
    {
        radius=_radius;
    }
    MNFCircle(const MNFCircle& old)
    {
        center=old.center;
        radius=old.radius;
        mnfcolor=old.mnfcolor;
    }
    ~MNFCircle(){cout<<"C dest";}
    void DrawCircle()
    {
        setcolor(mnfcolor);
        //circle(center.GetX(),center.GetY(),diameter);
        circle(center.GetX(),center.GetY(),radius);
    }
};

class MNFTriangle:public Shape
{
    Point p1;
    Point p2;
    Point p3;
    public:
    void SetP1(Point _p1){p1=_p1;}
    Point GetP1(){return p1;}
    void SetP2(Point _p2){p2=_p2;}
    Point GetP2(){return p2;}
    void SetP3(Point _p3){p3=_p3;}
    Point GetP3(){return p3;}
    MNFTriangle()
    {
        
    }
    MNFTriangle(int x1,int y1,int x2,int y2,int x3,int y3,int _mnfcolor)
    :p1(x1,y1),p2(x2,y2),p3(x3,y3),Shape(_mnfcolor)
    {
    }
    MNFTriangle(const MNFTriangle& old)
    {}
    ~MNFTriangle(){}
    void DrawTriangle()
    {
        setcolor(mnfcolor);
        //triangle() //this fn isnt exists in graphics.h
        //line(p1,p2);
        //line(p2,p3);
        //line(p1,p3);
    }
};

class Picture
{
    private:  //8 fields
    MNFLine *lPtr;
    int lSize;
    MNFRectangle *rPtr;
    int rSize;
    public:
    Picture()
    {
        lPtr=NULL;
        lSize=0;
        rPtr=NULL;
        rSize=0;
        //+ null 0
    }

    void SetRects(MNFRectangle *_rPtr,int _rSize)
    {
        rPtr=_rPtr;
        rSize=_rSize;
    }

    void SetLines(MNFLine *_lPtr,int _lSize)
    {
        lPtr=_lPtr;
        lSize=_lSize;
    }
    //set tri
    //set cir
    void DrawAll()
    {

        for (int i = 0; i < rSize; i++)
        {
            rPtr[i].DrawRect();
        }
        for (int i = 0; i < lSize; i++)
        {
            lPtr[i].DrawLine();
        }
        //for

        //for
        
        
    }
    
};

int main()
{
    MNFLine l1(1,2,3,4,5);
    MNFRectangle rarr[2]={MNFRectangle(),MNFRectangle()};
    MNFCircle carr[2]={MNFCircle(334,444,33),MNFCircle()};

    Picture p1;  //stack p1 rptr|N| rsize|0| lptr|N| lsize|0|


    //set relation between picture and rectangles
    p1.SetRects(rarr,2);
    p1.SetLines(&l1,1);
    //stack p1 rptr|Address rarr| rsize|2| lptr|N| lsize|0|

    p1.DrawAll();

    //remove relation between picture and rectangles
    p1.SetRects(NULL,0);
    p1.SetLines(NULL,0);

}

/////////////////////////////////////////////////////
///Lab Assignments

///Try All in lecture

///2- Draw abajora via picture 
///class Shape{color};






