///Child inherits EVERYTHING from Parent except...
///private:member can be acessed inside class/struct ONLY

//////////////////////////////////////////////////////////
#include<iostream>
using namespace std;
class Parent
{
    //static int counter;
    int x;
    int y;
    public:
    void setX(int _x){x=_x;}
    void setY(int _y){y=_y;}
    int getX(){return x;}
    int getY(){return y;}
    Parent(){x=y=0;}
    Parent(int _x,int _y){x=_x;y=_y;}
    ~Parent(){}
    int SumXY(){return x+y;}
};

//public :type of inheritance
//child inherits everything from parent  ???ctor Search
class Child:public Parent
{
    //x,y  -> private
    //setx,sety,getx,gety,sumxy  -> public
    int z;
    public:
    void setZ(int _z){z=_z;}
    int getZ(){return z;}
    Child()
    {
        // c2  ->  x0  y0  z0
        //
        z=0; //T
        //x=y=0; ???Compile Error //inaccessible
        //useless
        // this->setX(0);
        // setY(0);
    }
    Child(int _x,int _y,int _z):Parent(_x,_y)
    {
        //c3  x1 y2 z3
        z=_z;
        //x=_x; //inaccessible
        // this->setX(_x);
        // this->setY(_y);
    }
    ~Child(){}
    int SumXYZ()
    {
        //return x+y+z;
        //return z+this->getX()+this->getY();
        return z+SumXY();
    }


};

int main()
{

    //
    Child c3(1,2,3);
    cout<<c3.SumXY();  //3
    cout<<c3.SumXYZ(); //6
    //parent def ctor
    //child 3p ctor
    //child dest
    //parent dest
    //
    //
    Child c2; //12B
    //parent def ctor
    //child def ctor
    //child dest
    //parent dest
    //


    Parent p1;  //x0 y0   //8B
    p1.setX(10);
    p1.setY(20);
    cout<<p1.SumXY(); //30


    Child c1;  //x1 y2 //8B
    //c1.x???  //inaccessible
    c1.setX(1);
    c1.setY(2);
    cout<< c1.SumXY();  //3
    
}
////////////////////////////////////////////////
//protected[smart private]  [inheritance]
//member accessed inside class
//and can be accessed inside chain of inheritance
//only
///you cannot access protected in main


#include<iostream>
using namespace std;
class Parent
{
    protected:
    int x;
    int y;
    public:
    void setX(int _x){x=_x;}
    void setY(int _y){y=_y;}
    int getX(){return x;}
    int getY(){return y;}
    Parent(){x=y=0;}
    Parent(int _x,int _y){x=_x;y=_y;}
    ~Parent(){}
    int Sum(){return x+y;}
};

class Child:public Parent
{
    /// x,y protected  inherited and accessed
    ///setters&getters Sum public
    protected:
    int z;
    public:
    Child()
    {
        z=0;
        x=0;
        y=0;
    }
    Child(int _x,int _y,int _z)
    {
        x=_x;
        y=_y;
        z=_z;
    }
    int Sum()
    {
        //return x+y+z;
        //return z+Sum(); //stack overflow
        return z+ Parent::Sum()
    }

};


int main()
{
    Parent p1(3,4); 
    p1.x=22;  //inaccessible
    cout<<p1.Sum(); //7
    Child c1(3,4,7);
    cout<<c1.Sum(); //14
    cout<<c1.Parent::Sum(); //7

}

//Overriding: [inheritance]
//function has same name
//same input parameter
//[ignore return type]
//but implementation/body is different
//in sub/child class



///////////////////////////////////////////

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
};

class Rect:public Geoshape
{
    ///fields??? No   dim1, dim2
    public:
    Rect(){
         //useless -> inheritance will initiate parent fields
         //dim1=dim2=0;
    }
    Rect(float _dim1,float _dim2):Geoshape(_dim1,_dim2)
    {
        //dim1=_dim1;
        //dim2=_dim2;
    }
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
        //dim1=dim2=dim;
    }
    float CArea()
    {
        return dim1*dim2;
    }
};

class SquareV2:public Rect
{
    public:
    SquareV2(){}
    SquareV2(float _dim):Rect(_dim,_dim)
    {}
    ///CArea()??? No
    
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


SquareV2 s1;  //dim10 dim20
///geo ctor
///rect ctor
//sqv2 ctor
//sqv2 dest
//rect dest
//geo dest

SquareV2 s2(3); 
s2.CArea();

int main()
{
    Rect r1(3,4);
    cout<<r1.CArea();//12
    r1.setDim1(5);
    r1.setDim2(6);
    cout<<r1.CArea();//30

    Square s1(5);
    cout<<s1.CArea();
    //Business faliure
    s1.setDim1(3);
    s1.setDim2(4);
    cout<<s1.CArea(); //12
    //

    SquareV2 s2(4);
    cout<<s2.CArea();

    Circle c1(7);
    cout<<c1.CArea();
    //Business faliure
    c1.setDim1(5);
    c1.setDim2(6);
    cout<<c1.CArea();
    //


    Tri t1(4,5);
    cout<<t1.CArea();
}
/////////////////////////////////////////////////////
//Types Of Inheritance 
// : public
// : protected
// : private
////////////////////////////////////////////
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
};

class Rect:public Geoshape
{
    ///fields??? No   dim1, dim2
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
    {}
    float CArea()
    {
        return dim1*dim2;
    }
    //fn overriding
    void setDim1(float _dim1){dim1=dim2=_dim1;}
    void setDim2(float _dim2){dim2=dim1=_dim2;}
    //
};

class SquareV2:public Rect
{
    public:
    SquareV2(){}
    SquareV2(float _dim):Rect(_dim,_dim){}
};

class Circle:protected Geoshape
{
    public:
    Circle(){}
    Circle(float _radius):Geoshape(_radius,_radius){}
    //fn overriding
    void setDim1(float _dim1){dim1=dim2=_dim1;}
    void setDim2(float _dim2){dim2=dim1=_dim2;}
    //
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

int main()
{
    Square s1(10);  //10,10
    //
    s1.setDim1(3);   //3,3
    s1.setDim2(4);    //4,4

    s1.Geoshape::setDim1(3);
    s1.Geoshape::setDim2(4);
    //

    //s1.setDim1();??? Noooo

    s1.setDim1(3);
    s1.setDim1(4);
    
    s1.Geoshape::setDim1(4);//???? Compile Error


    Circle c1;

    c1.setDim1(2);
    c1.Geoshape::setDim1(2); //Compile Error
}

/////////////////////////////////////////////////
///Types of inheritance 
//A. Public

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
        //a,b,c??? Y  
        a=b=c=0;
        //x? No   y?Y   z?Y
        //setters and getters?Y
    }
    int sum()
    {
        return y+z+a+b+c+getX();
        return a+b+c+ Parent::sum();
    }
};

class SubChild:public Child
{
    int j;
    protected:
    int k;
    public:
    int l; 
    SubChild()
    {
        //x,y,z,a,b,c,j,k,l
        //??T  y,z,b,c,j,k,l
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
    //p.  x? No    y?No   z?Y sum()?Y setters&getters?Y

    Child c;
    //c.   x?N ,y?N ,z?Y ,a?N , b?N ,c?T  ,setter T

    SubChild sc;

}

//////////////////////////////////////
//B.Protected
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
    //x still private and canno access it
    //y still protected and i can access it
    //z prompte to protected & i can access it
    //setters&getters prompte to protected & i can access it
    //sum prompte to protected & i can access it

    //x,y,z protected ,sss,ggg,sum
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
        //x?N y z       a b c
    }
    int sum()
    {
        //y,z,a,b,c
    }
};

class SubChild:protected Child
{
    //x still private and cannot access it
    //y still protected and can access it
    //z still protected and can access it
    ///xyz setter&getters still protected and can access it
    ///Parent Sum() still protected and can access it
    //a still private and cannot access it
    //b still protected and can access it
    //c promote to protected and can access it
    ///abc setter&getters promote to protected and can access it
    ///child Sum() promote to protected and can access it

    int j;
    protected:
    int k;
    public:
    int l; 
    SubChild()
    {
        //??T  y,z,b,c,j,k,l
    }
    int sum()
    {
        return y+z+b+c+j+k+l+getX()+getA();
        return j+k+l+Child::sum();
    }
};

main()
{

    Child tmp;
    //tmp.   x N, y N,z N,a N,b N,c Y

    SubChild sc;
    //sc .  xN yN zN aN bN cN jN kN lY





    Child c;
    //c. c  setter&getter child ONLY

    SubChild sc;
    //sc. public only   l  setter subchild
}


////////////////////////////////////////////////
//C. Private

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
    //y private [accessed here]
    //z private [accessed here]  
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
        //x?N
        //y?T
        //z?T
        //setter T
        //sum parent T
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
        
    }
    int sum()
    {
        
    }
};
//////////////////////////////////////////////

//Most Commonly used class:public class
//C# java ONLY class: class   public

//////////////////////////////////////////////

class Point
{
    int x,y;
    public:
    void setX();
    void setY();
    int getX();
    int getY();
    Point();
    Point(int ,int);
    ~Point();
    Point(const Point &)
};
main()
{
    Point p1;  //8B  //Stack

    Point parr[3];   //3*8  //stack
    //def cotor
    //def cotor
    //def cotor
    //dest
    //dest
    //dest

    Point parr[3]={Point(1,2),Point(3,4),Point(5)};
    //2p ctor
    //2p ctor
    //1p ctor
    //dest
    //dest
    //dest

    Point(3,4);
    //same time ctor dest


    Point* ptr; 
    ptr=new Point;
    //create only one object in heap
    //pnt def ctor

    delete ptr; //call dest


    Point *ptr=new Point[3];
    //pnt def ctor
    //pnt def ctor
    //pnt def ctor

    delete[] ptr;  //call dest 3 times


    //with dynamic allocation
    ///you cannot create object via parametrized ctor
    ///ONLY def ctor
    Point *ptr=new Point[3];

    ptr[0].setX(2);
}
//////////////////////////////////////////////
///Aggregation/Association

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
    Line* lptr;
    int lsize;
    Rect* rptr;
    int rsize;

    public:
    void setLines(Line* _lptr,int _lsize)
    {
        lptr=_lptr;
        lsize=_lsize;
    }

    void setRects(Rect* _rptr,int _rsize)
    {
        rptr=_rptr;
        rsize=_rsize;
    }
    Picture()
    {
        lptr=NULL;
        lsize=0;
        rptr=NULL;
        rsize=0;
    }
    Picture(Line* _lptr,int _lsize,Rect* _rptr,int _rsize)
    {
        lptr=_lptr;
        lsize=_lsize;
        rptr=_rptr;
        rsize=_rsize;
    }

    void DoIt()
    {
        for(int i=0;i<lsize;i++)
        {
            lptr[i].Draw();
        }
        for(int i=0;i<rsize;i++)
        {
            rptr[i].Draw();
        }
    }
};

int main()
{
    initgraph();
    Picture p1;  
    //  lptr=null ,lsize=0 ,rptr=null,rsize=0

    Line larr[3]={Line(1,2,3,4,5),Line(33,44,55,66,7),Line(1,1,1,1,1)};
    //Rect* rptr=new Rect[3];
    Rect r1(1,2,3,4,5);

    //Make Relationship
    p1.setLines(larr,3);
    p1.setRects(&r1,1);

    //p1 //  lptr=0x10 ,lsize=3 ,rptr=0x50,rsize=3

    p1.DoIt();

    ///cancel relationship
    p1.setLines(NULL,0);
    p1.setRects(NULL,0);
    //p1 //  lptr=null ,lsize=0 ,rptr=null,rsize=0
    //


    delete[]rptr;
}