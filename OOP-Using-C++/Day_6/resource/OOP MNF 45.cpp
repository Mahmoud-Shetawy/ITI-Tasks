///////////////////////////////////////////////////////////////
//template
//[Inheritance]Every Code below[child] will 
//inherit from public
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

    void Show()  //override
    {
        cout<<"I'm Derived ...";
    }
};

int main()
{
    Base b1(3);
    b1.Show(); //i'm base

    Derived d1(2,3);
    d1.Show(); //i'm derived

    Base *bPtr=&b1;
    (*bPtr).Show(); //i'm base
    bPtr->Show(); //i'm base
    ///compiler will retrieve show that 
    ///belongs to pointer DT

    Base *bPtr2=new Base(3);
    bPtr2->Show(); //i'm base

    Derived *dPtr=new Derived(3,4);
    dptr->Show(); //i'm derived
    ///compiler will retrieve show that 
    ///belongs to pointer DT
}

int main()
{
    Base *bPtr = new Derived(3,4);

    // الأب يحتوي جميع ابناؤه
    
    //inheritance [is a]
    //car is a viechle
    //bus is a viechle
    
    //viechle is a car [NOT RIGHT]
    
    bPtr->Show(); //i'm base

    ///compiler will retrieve show that 
    ///belongs to pointer DT

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
    bPtr->Show(); //i'm base
    Base *bPtr2=new Derived2(1,2,3);
    bPtr2->Show(); //i'm base
    Derived *dPtr=new Derived2(1,2,3);
    dPtr->Show(); //i'm derived
    ///when pointer to base points object
    //of its childs
    //and call overridden fn
    //compiler will retrieve copy of fn that
    //belongs to pointer DT
}



class Human
{
    protected:
    string name;
    public:
    void SayName(){cout<<"No name";}
};
class Male:public human
{
    public:
    Male(string _name)
    {
        name=_name;
    }
    void SayName()
    {
        cout<<"I'm "<<name;
    }
};
class Female:public human
{
    public:
    Female(string _name)
    {
        name=_name;
    }
    void SayName()
    {
        cout<<"I'm "<<name;
    }
};

main()
{
    Human * hPtr=new Female("Fatma");
    hPtr->SayName(); //NOOOO Name

    Human * hPtr2=new Male("Moustafa");
    hPtr2->SayName(); //Noooo name
}

//////////////////////////////////////////////////

////Early/static   Binding
////when pointer from parent points
// object from its child
////when call overriden method
////Complier will EARLY [Compile Time] Retrieve
// copy of Pointer DT
/////not copy of Object DT

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
////Complier will Later [Run Time] 
//Retrieve copy of Object DT
/////not copy of Pointer DT


//1-function to be overridden in fst lvl [base class]
///must be public and virtual 
//2-derived class must inherits as public
//3-overridden fn in child DT must be also public
//4- make pointer of base that points object of its childs

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
    void Show() override
    {
        cout<<"I'm Derived ...";
    }
    //override -> safety factor
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
    void Show() //override
    {
        cout<<"I'm Derived TWO";
    }
};

int main()
{
    Base * bPtr=new Derived(2,3,4);
    bPtr->Show(); //i'm Derived
    //with virtual will retrieve copy that belong 
    //to object DT

    Base *  bPtr2=new Derived2(2,3,4);
    bPtr2->Show(); //i'm derived 2

    Derived * dPtr=new Derived2(3,4,5);
    dptr->Show(); //i'm derived 2
}

////////////////////////////////////////////////////

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
    //virtual double CArea()
    //{
        //return -1;
    //}
    virtual double CArea()=0;

    //virtual void TryMe()=0;

};
//
class Rect:public Geoshape
{
    public:
    Rect()
    {
        cout<<"rect ctor";
    } 
    Rect(double _x,double _y):Geoshape(_x,_y)
    {
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
};
//
class Square:public Geoshape 
{
    public:
    Square()
    {}
    Square(double _dim):Geoshape(_dim)
    {
    }
    ~Square(){}
    double CArea()
    {
        return dim1*dim2;
    }
};
//
class Circle:public Geoshape{};
//
class Tri:public Geoshape{};
//
//Failure in open closed principle
double SumOfAreasV1(Rect *rPtr,int rSize,Square *sPtr,int sSize,Circle *cPtr,int cSize)
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
//
int main()
{
    Rect rarr[2]={Rect(3,4),Rect(2,5)};
    Square sarr[3]={Square(10),Square(10),Square(10)};
    Circle c1(7);
    cout<<SumOfAreasV1(rarr,2,sarr,3,&c1,1);
    return 0;
}

//
//succeed in open closed principle
//double SumOfAreasV2(Geoshape* gPtrArr[],int gSize)
double SumOfAreasV2(Geoshape** gPtrArr,int gSize)
{
    double sum=0;
    for (int i = 0; i < gSize; i++)
    {
        sum+=gPtrArr[i]->CArea();
    }
    return sum;
}
//
int main()
{
    Geoshape *gPtr=new Square(10);
    cout<<gPtr->CArea(); //100

    Rect rarr[2]={Rect(3,4),Rect(2,5)};
    Square sarr[3]={Square(10),Square(10),Square(10)};
    Circle c1(7);
    Tri t1(3,4);

    Geoshape *gPtrArr[7]=
    {rarr,&rarr[1],sarr,&sarr[1],&sarr[2],&c1,&t1}; //|||||||
    //gPtrArr[0]=&rarr[0];
    //(*gPtrArr[2]).CArea(); //100
    //gPtrArr[2]->CArea();  //cout  100

    cout<<SumOfAreasV2(gPtrArr,7);

    Geoshape * gArr[2]={rarr,&rarr[1]};
    cout<<SumOfAreasV2(gArr,2); //23
}

/////////////////////////////////////////////////////

int main()
{
    Geoshape obj(3,4);
    //after pure virtual fn
    ///compile Error

    Geoshape *gPtr; ///T
}

//restrict create object from class
//make it abstract class

//abstract class:
// class we cannot create object from it at all

//how to make class to be abstract?
///abstract class is a class contains
///at least one pure virtual function

///what is pure virtual function?
///virtual function header[prototype]() only=0;
///without body

///pure virtual fn [abstract fn] MUST BE OVERRIDDEN
//if not??? no compile error
//but child DT became also abstract class

///////////////////////////////////////////////////////
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
    void FunOne() override 
    {
        cout<<"Hello";
    }
    //virtual void FunTwo()=0;
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
    TypeA o1; // Compile Error [abstract class]

    TypeB o2; // Compile Error [abstract class]

    TypeC o3; // Runs Successfully
}

/////////////////////////////////////////////////////
//SEARCH
int main()
{
    Rect *rPtr=new Rect(3,4);
    cout<<rPtr->CArea(); //12
    delete rPtr;
    //rect dest called


    Geoshape *gPtr=new Rect(3,4);
    cout<<gPtr->CArea(); //12
    delete gPtr;
    //geoshape dest called
    
    //rect dest called [search][virtual dest]
    return 0;
}

/////////////////////////////////////////////////////
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

    virtual void Draw()=0;
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
    void Draw()
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
    void Draw()
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
    void Draw()
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
    void Draw()
    {
        setcolor(mnfcolor);
        //triangle() //this fn isnt exists in graphics.h
        //line(p1,p2);
        //line(p2,p3);
        //line(p1,p3);
    }
};

//old picture failed in open closed principles
class Picture
{
    private:  
    Shape ** SPtr;  //as an array of pointers of shapes
    int sSize;
    public:
    Picture()
    {
        SPtr=NULL;
        sSize=0;
    }
    Picture(Shape **_sPtr,int _sSize)
    {
        SPtr=_sPtr;
        sSize=_sSize;
    }
    void SetShapes(Shape **_sPtr,int _sSize)
    {
        SPtr=_sPtr;
        sSize=_sSize;
    }
    
    void DrawAll()
    {
        for (int i = 0; i < sSize; i++)
        {
            SPtr[i]->Draw();
        }
    }
    
};

int main()
{
    initgraph();
    MNFRectangle rarr[2]={MNFRectangle(),MNFRectangle()};
    MNFLine larr[3]={MNFLine(),MNFLine(),MNFLine()};
    MNFCircle carr[2]={MNFCircle(),MNFCircle()};
    MNFTriangle t1(1,2,3,4,5,6,7);
    
    //Shape *sPtr=new MNFRectangle[size];

    //Shape *sPtr=new MNFRectangle(1,2,33,44,5);
    //sPtr->Draw(); 
    //delete ...
    
    Shape * pShapes[8]=
    {rarr,&rarr[1],larr,&larr[1],&larr[2],carr,&carr[1],&t1};

    Picture p1;

    //set relation
    p1.SetShapes(pShapes,8);

    p1.DrawAll();

    //remove relation
    p1.SetShapes(NULL,0);

    return 0;
}


//////////////////////////////////////////////////////
//template -> generics
///you can write DT once
///and can be container for Any DT

///Template -> Containers class   stack,queue,list
///work with class only -> not struct

template<class FA>
class Stack
{
    FA * arr;
    int tos;
    int size;
    public:
    Stack()
    {
        cout<<"Stack Const";
        tos=0;
        size=5;
        arr=new FA[size];
    }
    Stack(int _size)
    {
        cout<<"Stack Const";
        tos=0;
        size=_size;
        arr=new FA[size];
    }
    //
    ~Stack()
    {
        cout<<"Stack Dest"<<endl;
        //USELESS
        for(int i=0;i<size;i++)
        {
            arr[i]=-1;
        }
        //
        delete [] arr;
    }
    int isFull()
    {
        return tos==size;
    }
    int isEmpty() 
    {
        return tos==0;
    }
    void push(FA num)
    {
        if(!isFull())
        {
            arr[tos]=num;
            tos++
        }
        else
        {
            cout<<"FULL !!!"<<endl;
        }  
    }
    FA pop()
    {
        FA retVal=-12345;
        if(!isEmpty())
        {
            tos--;
            retVal=arr[tos];
            //return retVal;
        }
        else
        {
            //cout<<"EMPTY !!!"<<endl;
        }
        return retVal;  
    }
};


int main()
{
    //Stack s1(10); //Compile Error

    Stack<int> s1(10);
    s1.push(2);

    Stack<char> s2(5);
    s2.push('A');
}

/////////////////////////////////////////////////////
//Lab Assignments
///1- geoshape ,rect,circle,tri,sq
//////SumOfAreas(Geoshapes ** ,int )

///2-Draw abagora via picture class {shape ** pshapes;int ssize }



//TRY
///try pure virtual fn  TypeA,TypeB,TypeC






