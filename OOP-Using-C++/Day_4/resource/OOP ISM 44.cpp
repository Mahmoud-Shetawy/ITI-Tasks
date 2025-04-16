//Operator Overloading Cont'd casting
//return by value,reference,address
//OOR ->Composition ,Aggregation,Association,Inheritance
//////////////////////////////////////////////////////////
// #include<iostream>
// using namespace std;
// class Point2D
// {
//     private:
//     int x;int y;
//     public:
//     void SetX(int _x){x=_x;}
//     void SetY(int _y){y=_y;}
//     int GetX(){return x;}
//     int GetY(){return y;}
//     Point2D(){x=y=0; cout<<"ctor";}
//     Point2D(int _x,int _y){x=_x;y=_y;cout<<"ctor";}
//     ~Point2D(){cout<<"dest";}
//     Point2D(const Point2D& oldObj){x=oldObj.x;y=oldObj.y;}
//     void Print(){cout<<"("<<x<<","<<y<<")"<<endl;}
// };


// class Point3D
// {
//     private:
//     int x;int y;int z;
//     public:
//     void SetX(int _x){x=_x;}
//     void SetY(int _y){y=_y;}
//     void SetZ(int _z){z=_z;}
//     int GetX(){return x;}
//     int GetY(){return y;}
//     int GetZ(){return z;}
//     Point3D(){x=y=z=0; cout<<"ctor";}
//     Point3D(int _x,int _y,int _z){x=_x;y=_y;z=_z;cout<<"ctor";}
//     ~Point3D(){cout<<"dest";}
//     Point3D(const Point2D& oldObj){x=oldObj.x;y=oldObj.y;z=oldObj.z;}
//     void Print(){cout<<"("<<x<<","<<y<<","<<z<<")"<<endl;}

//     operator Point2D()
//     {
//         Point2D tmpObj(this->x,this->y);
//         return tmpObj;
//     }

// };



int main()
{
    Point2D p2d(3,4); //8B

    Point3D p3d(3,4,5);  //12B
    p3d.Print(); //(3,4,5)
    
    //CASTING  [implicit]
    Point2D Obj=p3d;
    Obj.Print(); //3,4
    //CASTING  [explicit]
    Point2D Obj2=(Point2D)p3d;

}

////////////////////////////////////////////////////
int PassVal(int param)
{
    param++;
    return param;
}
//By Value
int main()
{
    int x=10;
    int result=PassVal(x);
    cout<<result; //11

    PassVal(x)=33;  //comile Error   //LValue
}

int& PassReference(int& param)
{
    param++;
    return param;
}
int main()
{
    int x=10;
    int result=PassReference(x);
    cout<< result; //11

    PassReference(x)=100; 
    cout<<x; //100
}

int* PassAddress(int* param)
{
    (*param)++;
    return param;
}

int main()
{
    int x=10;

    int result=*(PassAddress(&x));
    cout<<result; //11

    *(PassAddress(&x))=100;
    cout<<x;//100
}

////////////////////////////////////////////////////

class IntArray
{
    int * arr;
    int size;
    public:
    IntArray()
    {
        size=5;
        arr=new int[size];
    }
    IntArray(int _size)
    {
        size=_size;
        arr=new int[size];
    }
    ~IntArray()
    {
        delete [] arr;
    }
    IntArray(const IntArray& old)
    {
        size=old.size;
        arr=new int [size];
        for(int i=0;i<size;i++)
        {
            arr[i]=old.arr[i];
        }
    }
    IntArray& operator=(const IntArray& right)
    {
        delete[] this->arr;
        this->size=right.size;
        this-.arr=new int[size];
        for(int i=0;i<size;i++)
        {
            arr[i]=right.arr[i];
        }
        return *this;
    }
    void SetValue(int index ,int value)
    {
        if(index>=0&&index<size)
        {arr[index]=value;}
    }
    int GetValue(int index)
    {
        return arr[index];
    }
    //
    int& operator[](int index)
    {
        return this->arr[index]; //10
    }
};

int main()
{
    IntArray o1(10);

    o1.SetValue(0,10);
    cout<<o1.GetValue(0);


    //
    int _index=0;
    cout<<o1[_index];

    o1[_index]=100;

    IntArray o2(5);
    o2=o1;
}

///////////////////////////////////////////////
////////////////////////////////////////////////////////
//Object Oriented Relations
//Relation between classes

//1-Composition [Tightly Coupled]
    //class Contains All Of Another class

//2-Aggregation [loosely coupled]
    //class may contains another class later

//3-Association [Very Loosely coupled]
    //peer to peer each class may not depend on
        //another one 

//4- inheritance

//A-Association [Very Loosely coupled]
///1- Peer-To-Peer
        //teacher    subject
///2- Temporarily relation
///3- represent in code
        //Pointer of class inside another class
        //C# Reference
        ///cass Teacher
        //{
            //id,name,age
            //Subject * sub;
        //};
//4- 1-1  1-M M-M 
//5- No Dependency


//B-Aggregation [loosely coupled]
///1- Whole vs. part
///      Student       Department
///2- temp. Relation
///3- Resresent in code
    /// Pointer of class inside another class
        //C# Reference
        ///cass Student
        //{
            //id,name,age
            //Department * Dept;
            //ctor(){new dept[10]}
        //};
///4- 1-1   1-M M-M
///5- No Dependency


//C- Composition [Tightly Coupled]
///1- complete ownership
///2- Permenant relationship
        //Room    wall
///3- object of class inside another class
        ///class Room
        //{
            //Wall  w1;
            //Wall  w2;
            //Wall  w3;
            //Wall  w4;
            
        //};
        ///main  room r[10] ||||||||
        //room r1,r2,r3
///4- 1-1 1-m 
///5- Complete Dependency


//Dependency Injection


///SOLID

//principle
//Concept
//Framework

///////////////////////////////////////////////////////
#include<iostream>
#include "graphics.h"
using namespace std;
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

class Line
{
    private:
    Point start;
    Point end;
    int color;
    public:
    void SetStart(Point _start){start=_start;}
    void SetEnd(Point _end){end=_end;}
    Point GetStart(){return start;}
    Point GetEnd(){return end;}
    void SetColor(int _color){color=_color;}
    int GetColor(){return color;}
    Line()
    {
        //Compile Error Inaccessible
        // start.x=0;// start.y=0// end.x=0;// end.y=0;
        //memmory  l1 start x0 y0   end x0 y0
        //useless
        start.SetX(0);
        start.SetY(0);
        end.SetX(0);
        end.SetY(0);
        color=0;
        cout<<"Line def ctor";
    }
    
    Line(int x1,int y1,int x2,int y2,int _color)
    {
        //memmory  l2 start x0 y0   end x0 y0
        this->start.SetX(x1);
        start.SetY(y1);
        this->end.SetX(x2);
        end.SetY(y2);//
        color=_color;
        //memmory  l2 start x1 y2   end x3 y4  color5
        cout<<"Line 5p ctor";
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

///ctor chaining
//1-increase performance
//2-reduce code written
class Rect
{
    private:
    Point ul;
    Point lr;
    int color;
    public:
    void SetUL(Point _ul){ul=_ul;}
    void SetLR(Point _lr){lr=_lr;}
    Point GetUL(){return ul;}
    Point GetLR(){return lr;}
    void SetColor(int _color){color=_color;}
    int GetColor(){return color;}
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

class Circle
{
    private:
    Point center;
    int radius;
    int color;
    public:
    void setCenter(Point _center){center=_center;}
    Point GetCenter(){return center;}
    void SetRadius(int _radius){radius=_radius;}
    int GetRadius(){return radius;}
    void SetColor(int _color){color=_color;}
    int GetColor(){return color;}
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

class Tri
{
    //3 points +int color
    
    void DrawTri()
    {
        setcolor(color);
        //triangle() //XXXXXX
    }
};

int main()
{
    initgraph();
    
    Circle c1(1,2,3,4);
    //o/p
    //point 2p ctor  ctor chaining
    //circle 4p ctor
    //circle dest
    //point dest 
    c1.SetColor(10);
    c1.DrawCircle();


    Rect r2(1,2,3,4,5);
    //o/p
    //point 2p ctor r2 ul
    //point 2p ctor r2 lr
    //rect 5p ctor
    //rect dest
    //point dest lr
    //point dest ul
    r2.DrawRect();
    Rect r1;
    //o/p
    //point def ctor r1 ul
    //point def ctor r1 lr
    //rect def ctor
    
    Line l2(1,2,3,4,5);
    //o/p
    //point def ctor l2 start
    //point def ctor l2 end
    //line 5p ctor

    Line l1;
    //o/p
    //point def ctor l1 start
    //point def ctor l1 end
    //line def ctor

    l1.DrawLine();
    l2.DrawLine();
}



///Lab
//point -> Line ->Rect->Circle->Tri
//REMEMBER Debug with& without ctor chaining

//draw ABAGORA

//bonus
//moving fan