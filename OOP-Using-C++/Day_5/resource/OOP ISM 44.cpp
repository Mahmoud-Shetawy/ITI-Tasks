//1-Inheritance
//2-Aggregation[association]
////////////////////////////////////////////////////
//OOR
//4- Inheritance

//Inheritance:
///Extending methods and fields from
///class to another one

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
    //caller c1
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
    //inherits x,y,setx,sety,getx,gety,sumxy
    private:
    int z;
    public:
    void SetZ(int _z){z=_z;}
    int GetZ(){return z;}
    Child()
    {
        //c1 x|0| y|0| z|?|
        z=0;
        //c1 x|0| y|0| z|0|
        //x=0;y=0; //compile Error Inaccessible
        cout<<"child def ctor";
    }
    Child(int _x,int _y,int _z):Parent(_x,_y)
    {
        //c2 x|0| y|0| z|?|
        z=_z;
        //c2 x|0| y|0| z|3|
        //x=_x;y=_y; inaccessible [private]
        this->SetX(_x);this->SetY(_y);  //useless after ctor chaining
        //c2 x|1| y|2| z|3|
        cout<<"child 3p ctor";
    }
    ~Child(){cout<<"Child dest";}
    Child(const Child& old)//:Parent(old)
    {
        z=old.z;
        this->SetX(old.GetX());
        this->SetY(old.GetY());
    }
    int SumXYZ()
    {
        //return x+y+z; //Inaccessible
        return z+this->GetX()+this->GetY();
        return z+this->SumXY();
    }
};

int main()
{



    Child c2(1,2,3);
    //without ctor chaining
    //parent def ctor
    //child 3p ctor
    //P::setx
    //P::sety
    //with ctor chaining
    //parent 2p ctor
    //child 3p ctor


    Child c1; //12B   x|| y|| z||
    //parent def ctor
    //child def ctor
    //child dest
    //parent dest

}

int main()
{
    Parent p1(1,2);
    cout<< p1.SumXY();  //3

    Child c1(1,2,3); //
    cout<<c1.SumXYZ(); //6
    cout<<c1.SumXY(); //3
}

//////////////////////////////////////////////////
//protected [smart private]  [inheritance]
//member can be accessed
//inside class/struct
//and accessed inside chain of inheritance
//ONLY

/////////////////////////////
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
    //caller c1
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
    ~Parent(){cout<<"PArent dest";}
    Parent(const Parent& old){x=old.x;y=old.y;}
    int Sum()
    {
        return x+y;
    }

};

class Child:public Parent
{
    //inherits x,y,setx,sety,getx,gety,sumxy
    private:
    int z;
    public:
    void SetZ(int _z){z=_z;}
    int GetZ(){return z;}
    Child()
    {
        z=0;
        x=0;y=0;  //T  protected
        cout<<"child def ctor";
    }
    Child(int _x,int _y,int _z):Parent(_x,_y)
    {
        //c2 x|0| y|0| z|?|
        z=_z;
        //c2 x|0| y|0| z|3|
        x=_x;y=_y; //T
        
        //c2 x|1| y|2| z|3|
        cout<<"child 3p ctor";
    }
    ~Child(){cout<<"Child dest";}
    Child(const Child& old)//:Parent(old)
    {
        z=old.z;
        x=old.x;
        y=old.y;
    }
    int Sum()
    {
        return z+x+y;
        //return z+Sum();  //Stack overflow
        //return z+ Parent::Sum();
    }
};


int main()
{
    Parent p1(1,2);
    //p1.x =02; //Inaccessible
    cout<<p1.Sum();  //3

    Child c1(1,2,3);
    cout<<c1.Sum(); //6
    cout<<c1.Parent::Sum(); //3
}


//////////////////////////////////////////////
//overriding
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
    double dim1;
    double dim2;
    public:
    void SetDim1(double _dim1){dim1=_dim1;}
    double GetDim1(){return dim1;}
    void SetDim2(double _dim2){dim2=_dim2;}
    double GetDim2(){return dim2;}
    Geoshape()
    {
        dim1=dim2=0;
    }
    Geoshape(double _dim1,double _dim2)
    {
        dim1=_dim1;dim2=_dim2;
    }
    Geoshape(double _num)
    {
        dim1=dim2=_num;
    }
    ~Geoshape(){}

};

class Rect :public Geoshape
{
    //fields??? NO
    public:
    //setters and getters?? No
    Rect()
    {
        //dim1=dim2=0;
    }
    Rect(double _d1,double _d2)//:Geoshape(_d1,_d2)
    {
        dim1=_d1; dim2=_d2;
    }

    double CArea()
    {
        return dim1*dim2;
    }
};


class Square:protected Geoshape
{
    ///dim1 dim2
    //setd1 getdim1,setd2,getd2  became PROTECTED
    public:
    Square(){}
    Square(double _d):Geoshape(_d,_d)
    {
        dim1=dim2=_d;
    }

    double CArea()
    {
        return dim1*dim2;
    }

    //overriding
    void SetDim1(double _dim1){dim1=dim2=_dim1;}
    void SetDim2(double _dim2){dim1=dim2=_dim2;}
    
    void SetDim(double _dim){dim1=dim2=_dim;}
    
    //

};

class SquareV2:public Rect
{
    public:
    SquareV2(){}
    SquareV2(double _d)//:Rect(_d,_d)
    {
        dim1=dim2=_d;
    }
};
class Circle:public Geoshape
{
    public:
    Circle(){}
    Circle(double _radius):Geoshape(_radius,_radius)
    {
        dim1=dim2=_radius;
    }
    double CArea()
    {
        return 3.14 *dim1* dim2;
        ///return 22/7 *dim1 *dim2;
        //return dim1 *dim2*(22/7);
    }
};

class Triangle:public Geoshape
{
    public:
    Triangle(){}
    Triangle(double _base,double _height)
    :Geoshape(_height,_base)
    {}

    double CArea()
    {
        return 0.5 * dim1* dim2;
    }
};

int main()
{
    Rect r1(3,4);
    //o/p
    //geo def ctor
    //rect 2p ctor
    //rect dest
    //geo dest

    SquareV2 s2(10);
    //o/p
    //geo ctor
    //rect ctor
    //sqv2 ctor

    ///////////////////////////////
    Square s2(10);
    s2.SetDim1(3);   //d13   d23  
    s2.SetDim2(4);   //d14   d24
    s2.Geoshape::SetDim2(4); //Inaccessible
    cout<<s2.CArea(); //16

    s2.SetDim(10);

    Circle c2(10);
    c2.SetDim1(4);
    c2.SetDim2(6);


    ////not make sense to create object from geoshape 
    Geoshape obj;

}

//////////////////////////////////////////////////////
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
        //a,b,c??? Y   members
        a=b=c=0;
        //x? No   y?Y   z?Y
        //setters and getters Sum?Y
    }
    int sum()
    {
        return y+z+a+b+c+getX();
        return a+b+c+ Parent::sum();
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
        //kjl??T  y,z,b,c,j,k,l      [x,a] XXXX
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
        //a,b,c
        //y z
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
        //y,z,a,b,c ,parent setters
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
    //start of l1
    //end of l1
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
    Point p1(3,4);  //Stack 8B

    //anonymous object
    Point(3,4); 
    //compiler call ctor then dest at same time

    Point *pPtr;  //4 or 8 B
    pPtr=new Point(3,4);
    delete pPtr;  //call dest

    Point parr[3] ; //def ctor called 3 times
    Point parr2[3]={Point(1,2),Point(3,4),Point(5,6)};

    pPtr=new Point[3];  //call def ctor 3 times
    //you cannot make default values so ,you cannot call parameterized ctor
    pPtr[0].SetX(3);
    pPtr[0].SetY(4);


    delete[] pPtr;  //dest called 3 times
    return;
}

///////////////////////////////////////////////////
//aggregation /association
class Shape
{
    protected:
    int color;
    public:
    void SetColor(int _color){color=_color;}
    int GetColor(){return color;}
    Shape(){color=0;}
    Shape(int _color){color=_color;}
    ~Shape(){}
};


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
    //start of l1
    //end of l1
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

class Line :public Shape
{
    private:
    Point start;
    Point end;
    public:
    void SetStart(Point _start){start=_start;}
    void SetEnd(Point _end){end=_end;}
    Point GetStart(){return start;}
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
    void DrawLine()
    {
        //cout<<"Line"<<start.GetX()<<start.GetY()<<end.GetX()<<end.GetY()<<color<<endl;
        setcolor(this->color);
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
    void SetLR(Point _lr){lr=_lr;}
    Point GetUL(){return ul;}
    Point GetLR(){return lr;}
    
    Rect()//:ul(),lr()
    {
        //memory r1 ul x0 y0    lr x0 y0
        color=0;
        cout<<"Rect def ctor";
    }
    Rect(int x1,int y1,int x2,int y2,int _color)
    :ul(x1,y1),lr(x2,y2)
    {
        //memory r2 ul x1 y2    lr x3 y4
        color=_color;
        cout<< "Rect 5p ctor";
    }
    Rect(const Rect& old)
    {
        ul=old.ul;
        lr=old.lr;
        color=old.color;
    }
    ~Rect()
    {
        cout<<"Rect dest";
    }
    void DrawRect()
    {
        setcolor(color);
        rectangle(ul.GetX(),ul.GetY(),lr.GetX(),lr.GetY());
    }

};

class Circle:public Shape
{
    private:
    Point center;
    int radius;
    public:
    void setCenter(Point _center){center=_center;}
    Point GetCenter(){return center;}
    void SetRadius(int _radius){radius=_radius;}
    int GetRadius(){return radius;}
    Circle()
    {
        radius=0;
        color=0;
        cout<<"Cir ctor def";
    }
    Circle(int x1,int y1,int _radius,int _color):center(x1,y1)
    {
        radius=_radius;
        color=_color;
        //
    }
    Circle(const Circle& old)
    {
        center=old.center;
        radius=old.radius;
        color=old.color;
    }
    ~Circle(){cout<<"cir dest";}

    void DrawCircle()
    {
        setcolor(color); //graphics.h
        circle(center.GetX(),center.GetY(),radius);
    }
};

class Picture
{
    private:
    Line* lPtr;
    int lSize;
    Circle* cPtr;
    int cSize;
    public:
    Picture()
    {
        lPtr=NULL;
        lSize=0;
        cPtr=NULL;
        cSize=0;
    }

    // ~Picture()
    // {
    //     delete [] lPtr;
    // }

    void SetLines(Line* _lPtr,int _lSize)
    {
        lPtr=_lPtr;
        lSize=_lSize;
    }

    void SetCircles(Circle* _cPtr,int _cSize)
    {
        cPtr=_cPtr;
        cSize=_cSize;
    }

    void DoIt()
    {
        for(int i=0;i<lSize;i++)
        {
            lPtr[i].DrawLine();
        }
        for(int i=0;i<cSize;i++)
        {
            cPtr[i].DrawCircle();
        }
    }
};


int main()
{
    Line larr[3]={Line(),Line(),Line()};
    Circle c1(1,2,3);

    Picture p1;

    //relation
    p1.SetLines(larr,3);
    p1.SetCircles(&c1,1);

    p1.DoIt();

    //Remove relation
    p1.SetLines(NULL,0);
    p1.SetCircles(NULL,0);
}


//////////////////////////

