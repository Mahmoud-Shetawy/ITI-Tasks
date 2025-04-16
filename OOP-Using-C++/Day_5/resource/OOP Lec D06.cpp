//1-Inheritance
//2-Aggregation[association]

//OOR
//4- Inheritance

//Inheritance:
///Extending methods and fields from
///class to another one

///new datatype =>receiving methods and fields
///Was created actually in another datatype

///Open for extension - Close for modification//////////////////////////////////
///
//////SOLID Principles///////////
//o => inheritance
//l => inheritance
//D => Dependency Inversin

/////////////////////////////////////////

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

///////////////////////////////////
#include<iostream>
using namespace std;

class Parent
{
    int x;
    int y;
    public:
    void setX(int _x){x=_x;}
    void setY(int _y){y=_y;}
    int getX(){return x;}
    int getY(){return y;}
    Parent()  //MIP in Field
    {
        cout<<"Parent ctor";
        x=y=0;
    }
    Parent(int _x,int _y)
    {
        cout<<"Parent ctor";
        x=_x;
        y=_y;
    }
    ~Parent(){cout<<"Parent dest";}
    int sumXY()
    {
        return x+y;
    }
};
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

class Child:public Parent
{
    //Inherits Everythig 
    //x,y,setx,sety,getx,gety,sumxy
    int z;
    public:
    void setZ(int _z){z=_z;}
    int getZ(){return z;}
    Child()//:Parent() //useless
    {
        z=0;
        //x=0;   //XXX
        //y=0;   //XXX inaccessible
        //this->setX(0);
        //this->setY(0);
    }
    Child(int _x,int _y,int _z):Parent(_x,_y)
    {
        z=_z;
        //x=_x;
        //y=_y;  //inaccessible
        //this->setX(_x);
        //this->setY(_y);
    }
    ~Child(){cout<<"child Dest called ";}
    int sumXYZ()
    {
        //return x+y+z;  //WRONG
        return z+this->getX()+this->getY();
        return z+ this->sumXY();
    }
    
};
int main()
{
    Parent p;  //memory x  , y  
    Child c;   //memory x  ,  y  , z
    //c.x 
    //c.y

    Child c2(1,2,3); //memory x  ,  y  , z
    cout<<c2.sumXY();  //3
    cout<<c2.sumXYZ(); //6
    //c1.x
    //c1.y
    //c1.z
//Rule #4: in main YOU CANNOT ACCESS ANYTHING
//          BUT PUBLIC ONLYYYYYYYY
    return 0;
}


////////////////////////////////////////////
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
    Parent()  //MIP in Field
    {
        cout<<"Parent ctor";
        x=y=0;
    }
    Parent(int _x,int _y)
    {
        cout<<"Parent ctor";
        x=_x;
        y=_y;
    }
    ~Parent(){cout<<"Parent dest";}
    int sum()
    {
        return x+y;
    }
};

class Child:public Parent
{
    //Inherits Everythig 
    //x,y,setx,sety,getx,gety,sumxy
    int z;
    public:
    void setZ(int _z){z=_z;}
    int getZ(){return z;}
    Child()
    {
        z=0;
        //x=0;  
        //y=0;    //True =>accessible [protected]
    }
    Child(int _x,int _y,int _z):Parent(_x,_y)
    {
        z=_z;
        //x=_x;
        //y=_y;
    }
    ~Child(){cout<<"child Dest called ";}
    int sum()
    {
        //return x+y+z; 
        //return z+this->sum();//parent =>Infinit loop
        return z+ Parent::sum();
    }
    //child has # sum() ???
    //polymorphism :1- overload 2-override
    
    //Overriding =>inheritance:
    //                   function has same name
    //                          ,same params
    //            ignore return type
    //            but body/implementation is different
    //            in sub/child class   

    
};
int main()
{
    Parent p(2,3);
    cout<<p.sum(); //5
    //p.x
    //p.y  inaccessible
    Child c(1,2,3);
    cout<<c.sum(); //6
    cout<< c.Parent::sum(); //3
    //parent ctor
    //child ctor 
    //child dest 
    //parent dest 
}

/////////////////////////////////////////
//Protected:smart private
//          member -accessed inside class
//                 -accessed inside 
//                  chain of inheritance
//But in main => its like private
/////////////////////////////////////////


////////////////////////////////////////////

class GeoShape
{
    protected:
    //double
    int dim1;
    int dim2;
    public:
    void setDim1(int _dim1){dim1=_dim1;}
    void setDim2(int _dim2){dim2=_dim2;}
    int getDim1(){return dim1;}
    int getDim2(){return dim2;}
    GeoShape()  //MIP
    {
        //cout
        dim1=dim2=0;
    }
    GeoShape(int _dim1,int _dim2)
    {
        dim1=_dim1;
        dim2=_dim2;
    }
    ~GeoShape(){cout<< "Geoshape Dest";}

};

class Rect:public GeoShape
{
    public:
    //int dim1,int dim2;//???? No
    Rect()//:GeoShape()
    {
       
    }
    Rect(int _d1,int _d2):GeoShape(_d1,_d2)
    {
        //dim1=d1;
        //dim2=d2;
    }
    int CArea()
    {
        return dim1*dim2;
    }
};

class Square:public GeoShape
{
    public:
    Square()
    {

    }
    Square(int dim):GeoShape(dim,dim)
    {
        //dim1=dim2=dim;
    }
    int CArea()
    {
        return dim1*dim2;
    }
};

class Squarev2:public Rect
{
    public:
    Square()
    {

    }
    Square(int dim):GeoShape(dim,dim)
    {
        //dim1=dim2=dim;
    }
};

class Circle:public GeoShape
{
    public:
    Circle()
    {

    }
    Circle(int Rad):GeoShape(rad,rad)
    {
        //dim1=dim2=rad;
    }
    int CArea()
    {
        return 3.14 *dim1 *dim2;
    }
};

class Triangle:public GeoShape
{
    public:
    Triangle(){}
    Triangle(int b,int h):GeoShape(b,h)
    {
        //dim1=h;
        //dim2=b;
    }
    int CArea()
    {
        return 0.5 * dim1*dim2;
    }
};


main()
{
    Rect r;
    r.CArea();//0
    //geoghape def ctor
    //rect def ctor
    //carea()
    //dest rect
    //dest geoshape

    Rect r(4,5);
    r.CArea();  //20


    Square s(9);
    s.CArea(); //81


    Squarev2 s2;
    s2.CArea();//Rect

    Circle c(7);
    c.CArea();  //154


    Squarev2 s3(9);     //dim1 4   dim2 9
    //s3.setDim1(4);
    cout<<s3.CArea();   //36


    Circle c(7); //154   //dim1 7   dim2 8
    //c.setDim2(8)
    cout<<c.CArea();



}

////////////////////////////////////////////
//Types Of Inheritance 
// : public
// : protected
// : private
////////////////////////////////////////////
class GeoShape
{
    //private:
    //int tmp;
    protected:
    //double
    int dim1;
    int dim2;
    public:
    void setDim1(int _dim1){dim1=_dim1;}
    void setDim2(int _dim2){dim2=_dim2;}
    int getDim1(){return dim1;}
    int getDim2(){return dim2;}
    GeoShape()  //MIP
    {
        //cout
        dim1=dim2=0;
    }
    GeoShape(int _dim1,int _dim2)
    {
        dim1=_dim1;
        dim2=_dim2;
    }
    ~GeoShape(){cout<< "Geoshape Dest";}

};

class Rect:public GeoShape
{
    //private:
    //int tmp;
    //protected
    //int dim1,int dim2; //inherited
    public:
    //setdim1, setdim2,getdim1,getdim2  //inherited
    Rect()//:GeoShape()
    {
       
    }
    Rect(int _d1,int _d2):GeoShape(_d1,_d2)
    {
        //dim1=d1;
        //dim2=d2;
    }
    int CArea()
    {
        return dim1*dim2;
    }
};

class Squarev2:protected Rect
{
    //private
    //tmp
    //protected
    //setdim1, setdim2,getdim1,getdim2//carea()
    //dim1 dim2

    //Every thing in parent 
    //Will be inherited protected
    //Except private
    public:
    Squarev2()
    {

    }
    Squarev2(int dim):GeoShape(dim,dim)
    {
        //dim1=dim2=dim;
    }
    void setDim(int _dim){dim1=dim2=_dim;}
    int getDim(){return dim1;};
    int CArea()
    {
        return dim2*dim1;
        return Rect::Carea();
    }
};

class Circle:public GeoShape
{
    public:
    Circle()
    {

    }
    Circle(int Rad):GeoShape(rad,rad)
    {
        //dim1=dim2=rad;
    }

    void setDim1(int _dim1){dim1=dim2=_dim1;};
    void setDim2(int _dim2){dim1=dim2=_dim2;};
    int getDim1(){return dim1;}
    int getDim2(){return dim2}

    int CArea()
    {
        return 3.14 *dim1 *dim2;
    }
};

class Triangle:public GeoShape
{
    public:
    Triangle(){}
    Triangle(int b,int h):GeoShape(b,h)
    {
        //dim1=h;
        //dim2=b;
    }
    int CArea()
    {
        return 0.5 * dim1*dim2;
    }
};

int main()
{
    Squarev2 s(9);
    //s.setDim1(22);///???WRONG ???
    //s.getDim2();//WRONG
    cout<<s.CArea(); //??? NOOOO  inaccessible
    //Carea() protected



    //After overriding
    cout<<s.CArea(); 
    cout<< s.Rect::CArea(); //WRONG




    Circle c(9);
    c.setDim1(7);



    Squarev2 s(9);
    s.setDim(5);
    s.getDim();
    
}

////////////////////////////////////////////////
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

/////////////////////////////////////////////////////////
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
        
    }
};

class SubChild:protected Child
{
    //c ,z  protected
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
    //c. c  setter&getter child ONLY

    SubChild sc;
    //sc. public only   l  setter subchild
}


/////////////////////////////////////////////

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

//Association
//picture  2 circles
//picture rect , line


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
    int* p;
    p=new int;
    delete p;


    Point p(3,4); //Store in stack
    
    Point *ptr; //8 byte //store in stack

    ptr=new Point(3,4);  //store in heap

    delete [] ptr;//????No
    delete ptr; //fire  dest point

    //
    Point parr[3]; //array of 3 object of point
    //3 stored in stack
    //firing 3 def ctor

    Point parr[3]={Point(3,4),Point(4,5),Point(6,7)};
    //3 stored in stack
    //firing 3 overloaded ctor


    Point * ptr;
    ptr=new Point[3];
    //3 stored in heap
    //ALWAYS firing 3 def ctor

    //ptr[0].
    //*(ptr+1)->

    delete [] ptr;
    //fire 3 dest


}

///////////////////////////////////////////
class Point
{
    int x,y;
    public:
    void setX(int _x){x=_x;}
    void setY(int _y){y=_y;}
    int getX(){return x;}
    int getY(){return y;}
    Point(){x=y=0;}
    Point(int _x,int _y){x=_x;y=_y}
    ~Point(){cout<<"point dest";}
    Point(const Point &old){x=old.x;y=old.y;}
};

class Shape
{
    protected:
    int color;
    public:
    void setColor(int _c){color=c;}
    int getColor(){return color;}
    Shape()
    {
        color=0;
    }
    Shape(int _c)
    {
        color=_c;
    }
    ~Shape(){cout<<"Shape dest";}
    Shape(Shape &old){color=old.color;}
};

class Rect:public Shape
{
    Point ul,lr;  //has A
    public:
    void setUL(Point _ul){ul=_ul;}
    void setLR(Point _lr){lr=_lr;}
    Point getLR(){return lr;}
    Point getUL(){return ul;}
    Rect()//:ul(),lr(),Shape()
    {}
    Rect(int x1,int y1,int x2,int y2,int c):
    ul(x1,y1),lr(x2,y2),Shape(c)
    {

    }
    void Draw()
    {
        setcolor(color);
        rectangle(ul.getX(),,,);
    }

    
};

class Circle:public Shape
{
    Point center;
    int rad;
    public:
    Circle(){}
    Circle(int x,int y,int r,int c):
    center(x,y),Shape(c)
    {
        rad=r;
    }
    void Draw()
    {
        setcolor(color);
        circle(center.getX(),,);
    }
    
};

class Picture
{
    Rect * r;
    int rectsize;   //for loop paint
    Circle * c;
    int circlesize;
    public:
    Picture()
    {
        r=null;
        c=null;
        rectsize=0;
        circlesize=0;
    }
    Picture(Rect * _r,int _rs,Circle * _c,int _cs)
    {
        r=_r;
        rectsize=_rs;
        c=_c;
        circlesize=_cs;
    }
    void setCircles(Circle *_c,int _cs)
    {
        c=_c;
        circlesize=_cs;
    }
    void setRects(Rect * _r,int _rs)
    {
        r=_r;
        rectsize=_rs;
    }
    void Paint()
    {
        for(int i=0;i<rectsize;i++)
        {
            r[i].Draw();
            //*(r+i)->Draw();
        }
        for(int i=0;i<circlesize;i++)
        {
            c[i].Draw();
        }
    }
};

main()
{
    rect * r=new Rect(1,2,3,4,5);
    Circle* carr=new Circle[2];
    carr[0]=Circle(1,2,3,4);
    carr[1]=Circle(4,5,6,7);

    //Picture pic;
    Picture pic(r,1,carr,2);
    pic.Paint();







    //pic.setCircles(carr,2);

    pic.setCircles(null,0);
    pic.setRects(null,0);

    //Rect  heap
    //circle circle  heap     ALIVE

    //Pic   Stack   Alive


    Point p1(1,2);
    Point p2(3,4);
    Rect r(p1,p2);

}


/////////////////////////////////////
/// 

///1- area Geoshape   :public :protected
///2- types of inheritance
///      parent    child:[]parent   subchild:[]child
///3- class picture [aggreagation] + class shape[color]


                    class GrandFather{x};

class parent:GrandFather{x}; class parent2:GrandFather{x};

                class child:parent,parent2{???x};