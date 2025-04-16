///////////////////////////////////////////////////////////////
//[Inheritance]Every Code below will inherit from public
///////////////////////////////////////////////////////////////
#include<iostream>
using namespace std;
class Base
{
    protected:
    int x;
    public:
    void SetX(int _x){x=_x;}
    int GetX(){return x;}
    Base(){x=0;}
    Base(int _x){x=_x;}
    ~Base(){}
    void Show()
    {
        cout<<"I'm BASE ...";
    }
};

class Derived:public Base
{
    protected:
    int y;
    public:
    void SetY(int _y){y=_y;}
    int GetY(){return y;}
    Derived(){x=y=0;}
    Derived(int _x,int _y):Base(_x){y=_y;}
    ~Derived(){}
    void Show()
    {
        cout<<"I'm Derived ...";
    }
};

int main()
{
    Base b1;
    b1.Show(); //i'm base

    Derived d1;
    d1.Show(); //i'm derived

    Base* bPtr;

    bPtr=&b1;
    bPtr->Show();
    (*bPtr).Show();  //i'm base

    Derived *dPtr=new Derived(3,4);
    (*dPtr).Show();
    dPtr->Show();  //i'm derived


    Base *bPtr2=new Base(3);
    bPtr2->Show();  //i'm base


    Base *bPtr3=new Derived(3,4);
    bPtr3->Show(); //i'm BASE
    //الأب يحتوي جميع ابناؤه
    //car is a viechcle
    //truck is a viechle

    Derived d1;
    Base *bPtr4=&d1;
    bPtr4->Show(); //i'm BASE
}

class Derived2:public Derived
{
    protected:
    int z;
    void SetZ(int _z){z=_z;}
    int GetZ(){return z;}
    Derived2(){z=0;}
    Derived2(int _x,int _y,int _z):Derived(_x,_y){z=_z;}
    ~Derived2(){}
    
    void Show()
    {
        cout<<"I'm Derived TWO";
    }
};

int main()
{
    Base *bPtr=new Derived(1,2);
    bPtr->Show(); //i'm bae
    Base *bPtr2=new Derived2(1,2,3);
    bPtr2->Show();
    //i'm base
    Derived *dPtr=new Derived2(1,2,3);
    dPtr->Show(); //i'm Derived
}



class Human
{
    public:
    void TryMe(){cout<<"native name";}
};

class Male:public human
{
    public:
    void TryMe()
    {
        cout<<"I'm Mohamed";
    }
};
class Female:public human{};

main()
{
    Human * hPtr=new Male();
    hPtr->TryMe(); //native name
}

//////////////////////////////////////////////////

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


//1-function to be overridden in fst lvl must be public and virtual 
//2-derived class must inherits as public
//3-overridden fn in child DT must be also public
//4- make pointer of base that points object of its childs


class Base
{
    protected:
    int x;
    public:
    void SetX(int _x){x=_x;}
    int GetX(){return x;}
    Base(){x=0;}
    Base(int _x){x=_x;}
    ~Base(){}
    virtual void Show()
    {
        cout<<"I'm BASE ...";
    }
};

class Derived:public Base
{
    protected:
    int y;
    public:
    void SetY(int _y){y=_y;}
    int GetY(){return y;}
    Derived(){x=y=0;}
    Derived(int _x,int _y):Base(_x){y=_y;}
    ~Derived(){}
    void Show()
    {
        cout<<"I'm Derived ...";
    }
};


class Derived2:public Derived
{
    protected:
    int z;
    void SetZ(int _z){z=_z;}
    int GetZ(){return z;}
    Derived2(){z=0;}
    Derived2(int _x,int _y,int _z):Derived(_x,_y){z=_z;}
    ~Derived2(){}
    
    void Show()
    {
        cout<<"I'm Derived TWO";
    }
};

int main()
{
    Base *bPtr=new Derived(2,3);
    bPtr->Show(); //i'm Derived

    Base *bPtr2=new Derived2();
    bPtr2->Show(); //i'm der 2

    Derived * dPtr=new Derived2();
    dptr-> Show(); //i'm der 2
}

/////////////////////////////////////////////////////

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

    virtual double CArea()
    {
        return -1;
    }

};

class Rect :public Geoshape
{
    public:
    Rect()
    {
    }
    Rect(double _d1,double _d2):Geoshape(_d1,_d2)
    {
    }
    double CArea() override   
    {
        return dim1*dim2;
    }
    //override-> safety factor
};


class Square:public Geoshape
{
   
    public:
    Square(){}
    Square(double _d):Geoshape(_d,_d)
    {
        dim1=dim2=_d;
    }

    double CArea() override
    {
        return dim1*dim2;
    }
};

class Circle:public Geoshape{};

class Tri:public Geoshape{};

//Failed in open closed principles
double SumOfAreasV1(Rect* rarr,int rsize,Square* sarr,int ssize,Circle *carr,int csize)
{
    double sum=0;
    for(int i=0;i<rsize;i++)
    {sum+=rarr[i].CArea();}
    for(int i=0;i<ssize;i++)
    {sum+=sarr[i].CArea();}
    for(int i=0;i<csize;i++)
    {sum+=carr[i].CArea();}
    return sum;
}

//double SumOfAreasV2(Geoshape* gArr[],int gSize)
double SumOfAreasV2(Geoshape** gArr,int gSize)
{
    double sum=0;
    for(int i=0;i<gSize;i++)
    {
        sum+=gArr[i]->CArea();
    }
    return sum;
}

int main()
{
    Rect rarr[3]={Rect(1,2),Rect(3,4),Rect(5,2)};
    Square s1(10);
    Circle carr[2]={Circle(7),Circle(8)};
    Tri t1(3,4);
    cout<< SumOfAreasV1(rarr,3,&s1,1,carr,2);
}


int main()
{
    Geoshape *gPtr=new Rect(3,4);
    cout<< gPtr->CArea(); //12

    Rect rarr[3]={Rect(1,2),Rect(3,4),Rect(5,2)};
    Square s1(10);
   
    Geoshape* gArr[4];
    gArr[0]=&rarr[0];
    gArr[0]=rarr;
    gArr[1]=&rarr[1];
    gArr[2]=&rarr[2];
    gArr[3]=&s1;

    Geoshape *gArr[4]={rarr,&rarr[1],&rarr[2],&s1};
    (*gArr[0]).CArea();
    gArr[0]->CArea();
    gArr[1]->CArea();
    gArr[3]->CArea();
}


int main()
{
    Rect rarr[3]={Rect(1,2),Rect(3,4),Rect(5,2)};
    Square s1(10);
    Tri t1(4,5);
    Geoshape* gPtrArr[5]={rarr,&rarr[1],&rarr[2],&s1,&t1};

    cout<< SumOfAreasV2(gPtrArr,5);
   
}

int main()
{
    Geoshape obj; //
}

//abstract class:
//class we cannot create objct from it

//how to make class to be abstract?
//abstract class is class contains 
//at least ONE PURE VIRTUAL Function


//Pure virtual function:
// virtual function heaader only =0

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

    //pure virtual fn
    virtual double CArea()=0;
};

int main()
{
    Geoshape obj; //Compile Error

    Geoshape* gPtr; //T
}


////////////////////////////////////////
class TypeA
{
    protected:
    int x;
    public:
    //
    //
    //
    virtual void FunOne()=0;
    virtual void FunTwo()=0;
};

class TypeB:public TypeA
{
    protected:
    int y;
    public:
    void FunOne() override    //virtual fn
    {
        cout<<"Hello";
    }
};

class TypeC:public TypeB
{
    public:
    void FunTwo() override
    {
        cout<<"Bye";
    }
}


int main()
{
    TypeA o1; //Compile Erro  abstract

    TypeB o2; //compile Error

    TypeC o3; //Runs Successfully
}


//SEARCH
int main()
{
    Rect* rPtr=new Rect(3,4);
    cout<<rPtr->CArea(); //12
    delete rPtr; //call rect dest


    Geoshape* gPtr=new Rect(3,4);
    cout<<gPtr->CArea(); //12
    delete gPtr; //call geoshape dest

}
/////////////////////////////////////////////
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

    virtual void Draw()=0;
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
    void Draw() override
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
    void Draw()
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

    void Draw()
    {
        setcolor(color); //graphics.h
        circle(center.GetX(),center.GetY(),radius);
    }
};

class Picture
{
    private:
    Shape** sPtr;
    int sSize;
    public:
    Picture()
    {
        sPtr=NULL;
        sSize=0;
    }

    // ~Picture()
    // {
    //     delete [] lPtr;
    // }

    void SetShapes(Shape** _sPtr,int _sSize)
    {
        sPtr=_sPtr;
        sSize=_sSize;
    }

    void DoIt()
    {
       for(int i=0;i<sSize;i++)
       {
            sPtr[0]->Draw();
       }
    }
};



int main()
{
    //
    Shape* sPtr=new Rect(1,2,3,4,5);
    sPtr->Draw();

    Rect rarr[2]={Rect(),Rect()};
    Tri t1();
    Circle carr[2]={Circle(),Circle()};
    Line l1();
    Shape* sPtrArr[6]={rarr,&rarr[1],&t1,carr,&carr[1],&l1};


    Picture p1;
    p1.SetShapes(sPtrArr,6);
    p1.DoIt();

    p1.SetShapes(NULL,0);
}


