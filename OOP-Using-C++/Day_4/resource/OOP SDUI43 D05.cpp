//Operator Overloading Cont'd casting
//return by value,reference,address
//OOR ->Composition [T] ,Aggregation,Association,Inheritance
//////////////////////////////////////////////////////////
// #include<iostream>
// using namespace std;
// class Point2D
// {
//     private:
//     int x;
//     int y;
//     public:
//     void setX(int _x){x=_x;}
//     void setY(int _y){y=_y;}
//     int getX(){return x;}
//     int getY(){return y;}
//     Point2D(){x=y=0;}
//     Point2D(int _x,int _y){x=_x;y=_y;}
//     Point2D(int _num){x=y=_num;}
//     ~Point2D(){cout<<"Point2D Dest"<<endl;}
//     Point2D(Point2D& old){x=old.x;y=old.y;}
//     void Print()
//     {
//         cout<<"("<<x<<","<<y<<")"<<endl;
//     }
// };

// class Point3D
// {
//     private:
//     int x;
//     int y;
//     int z;
//     public:
//     void setX(int _x){x=_x;}
//     void setY(int _y){y=_y;}
//     void setZ(int _z){z=_z;}
//     int getX(){return x;}
//     int getY(){return y;}
//     int getZ(){return z;}
//     Point3D(){x=y=z=0;}
//     Point3D(int _x,int _y,int _z){x=_x;y=_y;z=_z}
//     Point3D(int _num){x=y=z=_num;}
//     ~Point3D(){cout<<"Point2D Dest"<<endl;}
//     Point3D(Point3D& old){x=old.x;y=old.y;z=old.z;}
//     //casting  //p3d caller 10 20 30
//     operator Point2D()
//     {
//         Point2D retVal(this->x,this->y);
//         return retVal();
//     }
//     //
//     void Print()
//     {
//         cout<<"("<<x<<","<<y<<","<<z<<")"<<endl;
//     }
// };

// int main()
// {
//     Point2D p1(3,4);
//     p1.Print();  //(3,4)

//     Point3D p3d(10,20,30);
//     p3d.Print(); //(10,20,30)

//     Point2D tmp=p3d;
//     Point2D tmp=(Point2D)p3d;
//     tmp.Print();  //(10,20)
//     return 0;
// }

////////////////////////////////////////////////////

//Ret by val,Ref,Add
#include<iostream>
using namespace std;

int FunVal(int x)
{
    x++;
    return x;
}

int& FunRef(int &x)
{
    x++;
    return x;
}

int* FunAdd(int* x)
{
    *x++;
    return x;
}
int main()
{
    //Return by Address
    int num=22;
    int res=*(FunAdd(&num));
    cout<<res;
    cout<<FunAdd(&num); //0x10
    cout<<*(FunAdd(&num)); //22

    *(FunAdd(&num))=1000;
    // [value] *(address of num or x) =1000
    cout<<num  ; 1000





    //Return By Reference
   int num=100;
   int res=FunRef(num);
   cout<<res;
   cout<<FunRef(num);   //101

    FunRef(num)=55;  //TRUE
    //x or num=55;
    cout<<num ;   //55;
   




    /* //Return By Value
    int num=10;
    cout<< FunVal(num);   //11
    int res=FunVal(num);
    cout<<res;
    FunVal(num)=88;  //Compile Error //LValue
    //11=88;
    //return value  Lvalue XXXX
    //return value  Rvalue True
    */

   
    return 0;
}

////////////////////////////////////////////////////
//Object Oriented Relations
//Relation between classes

//1-Composition [Tightly Coupled]
    //class Contains All Of Another class

//2-Aggregation [loosely coupled]
    //class may contains another class later

//3-Association [Very Loosely coupled]
    //peer to peer each class may not depend on
        //another one 



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
///      Employee       Department
///2- temp. Relation
///3- Resresent in code
    /// Pointer of class inside another class
        //C# Reference
        ///cass Employee
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
        ///cass Room
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

//////////////////////////////////////////////////

#include<iostream>
#include "graphics.h"

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
class Line
{
    private:
    Point start;
    Point end;
    int color;
    public:
    void setStart(Point _start){start=_start;}
    void setEnd(Point _end){end=_end;}
    Point getStart(){return start;}
    Point getEnd(){return end;}
    void setColor(int _color){color=_color;}
    int getColor(){return color;}

    Line()
    {
        //start.x=0; ///XXXX  inaccessible
        //Compiler  start x0 y0    end x0 y0
        //start.setX(0);
        //start.setY(0);
        //end.setX(0);
        //end.setY(0);
        color=0;
    }
    Line(int x1,int y1,int x2,int y2,int _color)
    {
        ///start x1 y2  end x3 y4   color5
        start.setX(x1);
        start.setY(y1);
        end.setX(x2);
        end.setY(y2);
        color=_color;
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

///Ctor chaining
//increase performance
//reduce code written

class Rect
{
    Point ul;
    Point lr;
    int color;
    public:
    void setUL(Point _ul){ul=_ul;}
    void setLR(Point _lr){lr=_lr;}
    Point getUL(){return ul;}
    Point getLR(){return lr;}
    void setColor(int _color){color=_color;}
    int getColor(){return color;}
    Rect()
    {
        color=0;
    }
    Rect(int x1,int y1,int x2,int y2,int _color):
    ul(x1,y1),lr(x2,y2)
    {
        ///Compiler ul 1,2     lr 3,4
        color=_color;
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

int main()
{
    Line l1;
    //point def ctor start
    //point def ctor end
    //line def ctor
    //line dest
    //point des end
    //point dest start

    Line l2(1,2,3,4,5);
    //point def ctor start
    //point def ctor end
    //line 5p ctor
    //line dest
    //point dest end
    //point dest start


    Rect r1(1,2,3,4,5);
    //pnt 2p ctor ul
    //pnt 2p ctor lr
    //rect 5p ctor
    //rect dest
    //point dest lr 
    //point dest ul 

}