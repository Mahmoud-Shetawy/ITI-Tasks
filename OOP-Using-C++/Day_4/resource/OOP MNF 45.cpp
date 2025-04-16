// Operator Overloading Cont'd casting
// return by value,reference,address
// OOR ->Composition ,Aggregation,Association,Inheritance
//////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
// Object Oriented Relations
// Relation between classes

// 1-Composition [Tightly Coupled]
// class Contains All Of Another class

// 2-Aggregation [loosely coupled]
// class may contains another class later

// 3-Association [Very Loosely coupled]
// peer to peer each class may not depend on
// another one despite there is relation between them

// 4- inheritance

// A-Association [Very Loosely coupled]
/// 1- Peer-To-Peer
// teacher    subject
// 2- Temporarily relation
// 3- represent in code
// Pointer of class inside another class
// C# Reference
/// class Teacher
//{
// id,name,age
// Subject * sub;
// ctor(){sub=NULL;}
//};
// 4- 0-0 1-1  1-M M-M
// 5- No Dependency

// B-Aggregation [loosely coupled]
/// 1- Whole vs. part
///       Student       Department
/// 2- temp. Relation
/// 3- Resresent in code
///  Pointer of class inside another class
// C# Reference
/// class Student
//{
// id,name,age
// Department * Dept;
// ctor(){Dept=NULL;}
//};
/// 4- 0-0 1-1   1-M M-M
/// 5- No Dependency

// C- Composition [Tightly Coupled]
/// 1- complete ownership   has a
/// 2- Permenant relationship
// Room    wall
/// 3- object of class inside another class
/// class Room
//{
// Wall  w1;
// Wall  w2;
// Wall  w3;
// Wall  w4;
//};
/// main  room r[10] ||||||||
// room r1,r2,r3
/// 4- 1-1 1-m
/// 5- Complete Dependency

//////SOLID
// Dependency Inversion
// is how to create losely coupled Application

// principle
// Concept
// Framework

///////////////////////////////////////////////////////
/// REMEMber color
#include <iostream>
#include "graphics.h"
using namespace std;
class Point
{
    int x;
    int y;

public:
    void SetX(int _x) { x = _x };
    int GetX() { return x; }
    void SetY(int _y) { y = _y };
    int GetY() { return y; }

    // l2 call this to construct start
    // l2 call this to construct end
    Point()
    {
        x = y = 0;
        cout << "point def ctor";
    }
    Point(int _x, int _y)
    {
        x = _x;
        y = _y;
        cout << "point 2p ctor";
    }
    Point(const Point &old) // useless //if you write cctor in one DT, then you must implement it in ALL DT coming next related to point
    {
        x = old.x;
        y = old.y;
        cout << "cpy ctor";
    }
    ~Point() { cout << "point dest"; }
};

class MNFLine
{
private:
    Point start;
    Point end;
    int mnfcolor;

public:
    void SetStart(Point _start) { start = _start; }
    Point GetStart() { return start; }
    void SetEnd(Point _end) { end = _end; }
    Point GetEnd() { return end; }
    void SetMnfcolor(int _mnfcolor) { mnfcolor = _mnfcolor; }
    int GetMnfcolor() { return mnfcolor; }

    MNFLine()
    {
        // start.x=0;start.y=0;end.x=0;end.y=0; //compile Error Inaccessible
        // l1 start x|0| y|0|  end x|0| y|0|
        // useless if Zero
        start.SetX(0);
        start.SetY(0);
        end.SetX(0);
        end.SetY(0);
        //
        mnfcolor = 0;
        cout << "Line def ctor";
    }

    MNFLine(int x1, int y1, int x2, int y2, int _mnfcolor)
    {
        // l2 start x|0| y|0|  end x|0| y|0|
        start.SetX(x1);
        start.SetY(y1);
        end.SetX(x2);
        end.SetY(y2);
        // l2 start x|1| y|2|  end x|3| y|4|
        mnfcolor = _mnfcolor;
        cout << "Line 5p ctor";
    }
    MNFLine(const MNFLine &old)
    {
        start = old.start;
        end = old.end;
        mnfcolor = old.mnfcolor;
        cout << "Line cctor";
    }
    ~MNFLine() { cout << "line dest"; }
    void DrawLine()
    {
        setcolor(mnfcolor);
        line(start.GetX(), start.GetY(), end.GetX(), end.GetY());
        // cout<<"line"<<this->start.GetX();
        // cout<<"line"<<this->start.GetY();
        // cout<<"line"<<this->end.GetX();
        // cout<<"line"<<this->end.GetY();
    }
};

/// ctor chaining [redirection]
////1- increase performance
////2- reduce code written
class MNFRectangle
{
private:
    Point ul;
    Point lr;
    int mnfcolor;

public:
    void SetLR(Point _lr) { lr = _lr; }
    void SetUL(Point _ul) { ul = _ul; }
    Point GetUL() { return ul; }
    Point GetLR() { return lr; }

    void SetMnfcolor(int _mnfcolor) { mnfcolor = _mnfcolor; }
    int GetMnfcolor() { return mnfcolor; }
    MNFRectangle() //: ul(0,0),lr(0,0)
    {
        // useless //ul.SetX(0); ul.SetY(0);
        mnfcolor = 0;
        cout << "Rect def ctor";
    }


    MNFRectangle(int x1, int y1, int x2, int y2, int _mnfcolor)
        : ul(x1, y1), lr(x2, y2)
    {
        // r2 ul x|1| y|2|   lr x|3| y|4|   mnfcolor|$|
        // ul.SetX(x1);
        // ul.SetY(y1);
        // lr.SetX(x2);
        // lr.SetY(y2);
        mnfcolor = _mnfcolor;
        cout << "Rect 5p ctor";
    }
    MNFRectangle(const MNFRectangle &old)
    {
        ul = old.ul;
        lr = old.lr;
        mnfcolor = old.mnfcolor;
        //
    }
    ~MNFRectangle() { cout << "dest"; }
    void DrawRect()
    {
        setcolor(mnfcolor);
        rectangle(ul.GetX(), ul.GetY(), lr.GetX(), lr.GetY());
    }
};

class MNFCircle
{
    Point center;
    int radius;
    int mnfcolor;

public:
    void SetCenter(Point _center) { center = _center; }
    Point GetCenter() { return center; }
    void SetRadius(int _radius) { radius = _radius; }
    int GetRadius() { return radius; }
    void SetMnfcolor(int _mnfcolor) { mnfcolor = _mnfcolor; }
    int GetMnfcolor() { return mnfcolor; }
    MNFCircle()
    {
        radius = 0;
        mnfcolor = 0;
    }
    MNFCircle(int x, int y, int _radius, int _mnfcolor)
        : center(x, y)
    {
        // center.SetX(x);
        // center.SetY(y);
        mnfcolor = _mnfcolor;
        radius = _radius;
    }
    MNFCircle(const MNFCircle &old)
    {
        center = old.center;
        radius = old.radius;
        mnfcolor = old.mnfcolor;
    }
    ~MNFCircle() { cout << "C dest"; }
    void DrawCircle()
    {
        setcolor(mnfcolor);
        // circle(center.GetX(),center.GetY(),diameter);
        circle(center.GetX(), center.GetY(), radius);
    }
};

class MNFTriangle
{
    Point p1;
    Point p2;
    Point p3;
    int mnfcolor;

public:
    void SetP1(Point _p1) { p1 = _p1; }
    Point GetP1() { return p1; }
    void SetP2(Point _p2) { p2 = _p2; }
    Point GetP2() { return p2; }
    void SetP3(Point _p3) { p3 = _p3; }
    Point GetP3() { return p3; }
    void SetMnfcolor(int _mnfcolor) { mnfcolor = _mnfcolor; }
    int GetMnfcolor() { return mnfcolor; }
    MNFTriangle()
    {
        mnfcolor = 0;
    }
    MNFTriangle(int x1, int y1, int x2, int y2, int x3, int y3, int _mnfcolor)
        : p1(x1, y1), p2(x2, y2), p3(x3, y3)
    {
        mnfcolor = _mnfcolor;
    }
    MNFTriangle(const MNFTriangle &old)
    {
    }
    ~MNFTriangle() {}
    void DrawTriangle()
    {
        setcolor(mnfcolor);
        // triangle() //this fn isnt exists in graphics.h
        // line(p1,p2);
        // line(p2,p3);
        // line(p1,p3);
    }
};

int main()
{
    initgraph();
    MNFRectangle r2(1, 2, 3, 4, 5);
    r2.DrawRect();

    MNFRectangle r1;
    // point def ctor ul
    // point def ctor lr
    // rect def ctor

    MNFLine l2(1, 2, 3, 4, 5);
    l2.DrawLine();
    // o/p
    // point def ctor start
    // point def ctor end
    // line 5p ctor

    MNFLine l1;
    // o/p
    // point def ctor start
    // point def ctor end
    // line def ctor
    // line dest
    // point dest end
    // point dest start

    anonymous object
    int arr[5] = {1, 2, 3, 4, 5};

     MNFRectangle(1,2,3,4,5);
    ////call  rect ctor and then at same time go to dest
    // use it with array initialization

    MNFRectangle r1(1, 2, 3, 4, 5);
    MNFRectangle r2(1, 2, 3, 4, 5);
    MNFRectangle r3(1, 2, 3, 4, 5);
    MNFRectangle r4(1, 2, 3, 4, 5);

    MNFRectangle rarr[4] =
        {
            MNFRectangle(1, 2, 3, 4, 5),
            MNFRectangle(1, 2, 3, 4, 5),
            MNFRectangle(1, 2, 3, 4, 5),
            r1};
    ////
    return 0;
}

///////////////////////////////////////////////////////

int funVal(int param)
{
    param++;
    return param; // value
}

int main()
{
    int x = 22;

     int result=funVal(x);
     cout<<result;  //23

    cout<<funVal(x); ///23

    funVal(x) = 100; 
}

/////////////////

int *funAddress(int *param)
{
    (*param)++;
    return param; // address param|0x10|
}

int main()
{
    int x = 22;

    int result = *(funAddress(&x));
    cout << result; // 23

    cout << *(funAddress(&x)); // 23

    *(funAddress(&x)) = 100; // T


    cout << x;               // 100
}

////////////////////////////////////////

int &funRef(int &param)
{
    param++;
    return param; // reference 
}

int main()
{
    int x = 22;

    int result=funRef(x);

    cout<<result; //23

    cout << funRef(x); // 23

    funRef(x) = 100;

    cout << x; // 100
}

///////////////////////////////////////////////
/// lab assignments

// 1-composition
////point,MNFLine,MNFRect,MNFCir,MNFTti
////data + mnfcolor
////setters & getters
/// ctor
/// ctor(,,,,)
// cctor
// dest
// Draw() {call function inside graphics.h}

// in main
/// MNFTriangle t1(33,33,66,77,77,77,7);
/// MNFCirc c1(11,22,44,8);
//
/
    /
    /
    /
    // t1.drawTri()
    // l1.drawline()
    // c1.DrawCircle()

    /// DRAW Abagora

    ///[bonus]moving fan
