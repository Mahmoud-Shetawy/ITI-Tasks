//Operator Overloading Cont'd casting
//return by value,reference,address
//OOR ->Composition ,Aggregation,Association,Inheritance
//////////////////////////////////////////////////////////
#include<iostream>
using namespace std;

// class Point2D
// {
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
//     ~Point2D(){}
//     Point2D(Point2D& old){x=old.x;y=old.y;}
//     void Print()
//     {
//         cout<<"("<<x<<","<<y<<")"<<endl;
//     }
// };

// class Point3D
// {
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
//     Point3D(int _x,int _y,int _z)
//     {x=_x;y=_y;z=_z;}
//     ~Point3D(){}
//     void Print()
//     {
//         cout<<"("<<x<<","<<y<<","<<z<<")"<<endl;
//     }

//     //(Point2D)obj3D
//     operator Point2D()
//     {
//         Point2D retVal(this->x,this->y);
//         return retVal;
//     }
//     //

// };
// int main()
// {

//     Point2D obj2D(3,4);
//     obj2D.Print();  //(3,4);

//     Point3D obj3D(5,6,7);
//     obj3D.Print(); //(5,6,7)

//     /////CASTING
//     Point2D tmpObj=obj3D;
//     //Point2D tmpObj=(Point2D)obj3D;
//     tmpObj.Print(); //(5,6)
//     /////

//     ////////CPY CTOR
//     // Point2D obj1(3,4);
//     // Point2D obj2(obj1); //call cpy ctor

//     // Point2D obj3=obj1;  //call cpy ctor  Point2d obj3(obj1)
    
//     // Point2D obj4;
//     // obj4=obj3;  //call = operator
//     return 0;
// }

/////////////////////////////////////////////////////
int funVal(int x)
{
    x++;
    return x; //return VALUE
}

int main()
{
    int a=10;
    cout<<funVal(a); //pass VALUE  //11
    int res=funVal(a);
    //
    funVal(a)=33;  //Compile Error  //LAVALUE
    //
}


int* funAdd(int* x)
{
    (*x)++;
    return x;
}

int main()
{
    int a=10;
    cout<< funAdd(&a); //0x10
    cout<< *(funAdd(&a)); //11
    int res=*(funAdd(&a));

    //
    *(funAdd(&a))=33;
    cout<<a; //33
    //
}

int& funRef(int& x)
{
    x++;
    return x;
}
int main()
{
    int a=10;
    cout<<funRef(a);  //11
    int res=funRef(a);

    //
    funRef(a)=33;
    cout<<a; //33
    //
}

///////////////////////////////////////////////////
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
            //Subject* sub;
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


//C- Composition [Tightly Coupled]  has a
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



///////////////////////////////////////////////////
#include<iostream>
#include"graphics.h"
using namespace std;

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

class Line
{
    private:
    Point start;
    Point end;
    int color;
    public:
    void setStart(Point _start){start=_start;}
    Point getStart(){return start;}
    void setEnd(Point _end){end=_end;}
    Point getEnd(){return end;}
    void setColor(int _color){color=_color;}
    int getColor(){return color;}
    /*Compiler*/Line()
    {
        //l1   start x0 y0    end  x0 y0   color?
        start.setX(0);
        start.setY(0);
        end.setX(0);
        end.setY(0);
        color=0;
        //l1   start x0 y0    end  x0 y0   color0
    }
    Line(int x1,int y1,int x2,int y2,int _color)
    {
        //l2   start x0 y0    end x0 y0   color?
        start.setX(x1);
        start.setY(y1);
        end.setX(x2);
        end.setY(y2);
        color=_color;
        //l2   start x1 y2    end x3 y4   color5
    }
    Line(Point _start,Point _end)
    {
        start=_start;
        end=_end;
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
        ///setcolor() -> built in inside graphics.h
        setcolor(color);
        ///line(x1,y1,x2,y2) -> built in inside graphics.h
        line(start.getX(),start.getY(),end.getX(),end.getY());
    }
};

//ctor Chaining
//1- increase performance
//2- reduce code written
class Rect
{
    private:
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
        //ul  x0 y0   lr x0 y0  color?
        color=0;
        //ul  x0 y0   lr x0 y0  color0
    }
    Rect(int x1,int y1,int x2,int y2,int _color):
    ul(x1,y1),lr(x2,y2)
    {
        //r2 ul x1 y2     lr x3 y4  color?
        color=_color;
        //r2 ul x1 y2     lr x3 y4  color5
    }
    ~Rect(){}
    Rect(const Rect& old):ul(old.ul),lr(old.lr)
    {
        ul=old.ul;
        lr=old.lr;
        color=old.color;
    }

    void Draw()
    {
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
        circle(center.getX(),center.getY(),radius );
    }
};

class Tri
{
    Point p1;
    Point p2;
    Point p3;
    int color;
    public:

    void Draw()
    {
        setcolor(color);
        line(p1 p2)
        line(p2 p3)
        line(p3 p1)
    }
};

int main()
{
    initgraph();
    //////

    Rect r2(1,2,3,4,5);
    r2.Draw();



    Rect r1;
    //o/p
    //point ctor ul
    //point ctor lr
    //rect ctor
    //rect dest
    //point dest lr
    //point dest ul


    Line l2(1,2,3,4,5);
    //o/p
    //point ctor start
    //point ctor end
    //line ctor
    //line dest
    // //point dest end
    // //point dest start

    // Line l1;
    // //o/p
    // //point ctor start
    // //point ctor end
    // //Line ctor 
    // //line dest
    // //point dest end
    // //point dest start
    //////
    int x;
    cin>>x;
    return 0;
}






///////////////////////////////////////

///lab 

//Draw abagora via composition


Line l1();
Line l1();

Circle c1();
Circle c2();

l1.Draw();











