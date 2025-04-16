//1-Inheritance
//2-Aggregation[association]

//OOR
//4- Inheritance

//Inheritance:
///Extending methods and fields from
///class to another one

///new datatype =>receiving methods and fields
///Was created actually in another datatype

/////////////////////////////////////////////////////

//Type A
//x
//y
//Fun1()
//Fun2()

//Type B
//y
//z
//Fun2()
//Fun3()


///////is-A/////////////////////////////////

//Type Base/Parent
//y
//Fun2()

//Type A   is-A   Type Base
//x
//Fun1()

//Type B  is-A Type Base
//z
//Fun3()

////////////////////////////////////////////////
#include<iostream>
using namespace std;
class Parent
{
    private:
    static int counter;
    int x;
    int y;
    public:
    void setX(int _x){x=_x;}
    void setY(int _y){y=_y;}
    int getX(){return x;}
    int getY(){return y;}
    Parent(){x=y=0;}
    Parent(int _x,int _y){x=_x;y=_y;}
    Parent(const Parent& old){x=old.x;y=old.y;}
    ~Parent(){}
    int SumXY()
    {
        return x+y;
    }
};
////////////////////////////////////////////////
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
    //implicitly
    ///x  y    setx  sety  getx   gety sumxy
    //parent() ,Parent(_x,_y)
    int z;
    public:
    void setZ(int _z){z=_z;}
    int getZ(){return z;}
    Child()
    {
        /// c1   x0  y0   z?   
        z=0;
        /// c1   x0  y0   z0
        //x=0;y=0; //Compile Error Inaccessible
        
        //useless
        //this->setX(0);
        //this->setY(0);
    }

    Child(int _x,int _y,int _z):Parent(_x,_y)
    {
        //c2  x0  y0  z?
        z=_z;
        //c2  x0  y0  z3
        
        //replaced by ctor chaining
        //this->setX(_x);
        //this->setY(_y);
    }
    Child(const Child& old)//:Parent(old)
    {
        z=old.z;
        setX(old.getX());
        setY(old.getY());
    }
    ~Child(){}
    int SumXYZ()
    {
        //return z+getX()+getY();
        return z +this->SumXY();
    }
};
/////////////////////////////////////////////////
int main()
{

    Child c2(1,2,3);
    cout<<c2.SumXY();  //3
    cout<<c2.SumXYZ();  //6
    ///o/p
    //parent ctor
    //child ctor
    //child dest
    //parent dest


    Parent p1(1,2);  //8B   //x0   y0
    //p1.Public ONLY
    cout<<p1.SumXY();  //3

    Child c1; //12B    //x?   y?  z
    //parent def ctor
    //child def ctor
    //child dest
    //parent dest
}

///////////////////////////////////////////////////
///protected [Inheritance]
 ///[smart private]

 ///mamber can be accessed inside class scope
 /// and accessed inside chain of inheritance
 //ONLY

//////////////////////////////////////////////////
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
    Parent(const Parent& old){x=old.x;y=old.y;}
    ~Parent(){}
    int Sum()
    {
        return x+y;
    }
};
class Child:public Parent
{
    //implicitly
    ///x  y    setx  sety  getx   gety sum
    int z;
    public:
    void setZ(int _z){z=_z;}
    int getZ(){return z;}
    Child()
    {
        z=0;
        //x=0; //inherited and accessed [protected]
        //y=0;
    }
    Child(int _x,int _y,int _z)
    {
        z=_z; x=_x; ,y=_y;
    }
    ~Child(){}
    int Sum()
    {
        //return z+x+y;
        //return z+Sum(); //Stack Overflow
        return z+ Parent::Sum();
    }
};


int main()
{
    Parent p1(1,2);
    //p1.public ONLY

    Child c1(1,2,3);
    cout<<c1.Sum(); //6
    cout<<c1.Parent::Sum(); //3

}

/////////////////////////////////////////
///Overriding  [inheritance]
///Function has same name
///same parameters
//but body/implementation
//is different in sub/child class

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

class Square:protected Geoshape
{
    public:
    Square(){}
    Square(float _dim):Geoshape(_dim,_dim)
    {dim1=dim2=_dim;}
    ~Square(){}
    float CArea(){return dim1*dim2;}
    ///Overriding
    void setDim1(float _dim1){dim1=dim2=_dim1;}
    void setDim2(float _dim2){dim2=dim1=_dim2;}
    ///
};

class SquareV2:public Rect
{
    public:
    SquareV2(){}
    SquareV2(float _dim):Rect(_dim,_dim)
    {dim1=dim2=_dim;}
    ~SquareV2(){}
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

int main()
{
    Rect r1(3,4);
    //geo ctor
    //rect ctor
    //rect dest
    //geo dest

    SquareV2 s2(10);
    //geo ctor
    //rect ctor
    //sq ctor
    //sq dest
    //rect dest
    //geo dest


    Square s1(10);
    s1.setDim1(3);  //3  3
    s1.setDim2(4);  //4  4
    s1.Geoshape::setDim1(5); 
    cout<< s1.CArea();  //20

    Circle c1(7);
    c1.setDim1(4);
    c1.setDim2(5);
    cout<<c1.CArea(); //???
}

////////////////////////////////////////////////////
////////////////////////////////////////////////////
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
        //kjl??T  y,z,b,c,j,k,l
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

    SubChild sc; //l ,c ,z 

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
    //x,y,z protected ,sss,ggg,sum
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
        //x?N y z       a b c
    }
    int sum()
    {
        //a,b,c ,z,y,getX()
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
    Child c;
    //c. xN yN zN aN bN  c  setter&getter of child ONLY

    SubChild sc;  //l
    //sc. public only   l  setter subchild
}


/////////////////////////////////////////////
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

//Association
//picture  2 circles
//picture rect , line


//////////////////////////////////////////////


class Point
{
    int x;
    int y;
    public:
    //setters
    //getters
    Point(){}
    Point(int _x,int _y){}
    Point(int _x){}
    ~Point(){}
    int Sum(){}
};

int main()
{
    Point p1(3,4);  //stored in Stack  //8B

    Point* pPtr; //stored in Stack  //4B or 8B

    pPtr=new Point(3,4);  // new Point(3,4) stored in Heap
    delete pPtr; //call dest

    Point parr[3];  
    //24B in Stack
    //point def ctor 
    //point def ctor 
    //point def ctor 

    //Point(2,3) anonymous object
    Point parr[3]={Point(2,3),Point(3,4),Point(5)};


    Point(4,5);//ctor and dest called at the same time

    //
    //
    //
    Point* pPtr=new Point[3];
    //new Point[3]; in heap
    //call def ctor 3 times ALWAYS
    //you cannot declare def values like before
    pPtr[0].setX(3);
}

//////////////////////////////////////////////////

//Association
//picture  2 circles
//picture rect , line


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


class Picture
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

int main()
{
    initgraph();
    Line l1(1,2,3,4,5);
    Rect rarr[3]={Rect(),Rect(),Rect()};

    Picture p1;

    p1.setRects(rarr,3);
    p1.setLines(&l1,1);

    p1.DoIt();

    p1.setRects(NULL,0);
    p1.setLines(NULL,0);
}


///////////////////////////////

//abagora via picture
//types of inheritance
///1- area Geoshape   :public :protected
