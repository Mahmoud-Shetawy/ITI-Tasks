//Operator Overloading Cont'd casting
//return by value,reference,address
//OOR ->Composition ,Aggregation,Association,Inheritance
//////////////////////////////////////////////////////////
// #include<iostream>
// using namespace std;
// class Point2D
// {
//     int x;
//     int y;
//     public:
//     void setX(int _x){x=_x;}
//     void setY(int _y){y=_y;}
//     int getY(){return y;}
//     int getX(){return x;}
//     Point2D(){x=y=0;}
//     Point2D(int _x,int _y){x=_x;y=_y;}
//     Point2D(int _num){x=y=_num;}
//     ~Point2D(){cout<<"dest";}
//     Point2D(const Point2D& old){x=old.x;y=old.y;}
//     void print(){cout<<"("<<x<<","<<y<<")"<<endl;}
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
//     int getY(){return y;}
//     int getX(){return x;}
//     int getZ(){return z;}
//     Point3D(){x=y=z=0;}
//     Point3D(int _x,int _y,int _z){x=_x;y=_y;z=_z;}
//     Point3D(const Point3D& old){x=old.x;y=old.y;z=old.z;}
//     ~Point3D(){}
//     void print()
//     {
//         cout<< "("<<x<<","<<y<<","<<z<<")"<<endl;
//     }
//     //cast to point2d  (point2D)obj
//     operator Point2D()
//     {
//         Point2D retVal(this->x,this->y);
//         return retVal;
//     }
//     //
// };

// int main()
// {
//     Point2D p2d(3,4);   //8B
//     p2d.print(); //(3,4)

//     Point3D p3d(11,22,33); //12B
//     p3d.print(); //(11,22,33)

//     //casting
//     Point2D obj=p3d;
//     Point2D obj=(Point2D)p3d;
//     obj.print();  //(11,22)
// }

////////////////////////////////////////////////////////

int FunVal(int a)
{
    a++;
    return a;
}

int* FunAdd(int* a)
{
    (*a)++;
    return a;
}

int& FunRef(int& a)
{
    a++;
    return a;
}
int main()
{
    // //pass/return by reference
    // int x=60;
    // cout<<FunRef(x); //61
    // FunRef(x)=900;
    // cout<<x ; //900

    // ///pass/Return by address
    // int x=3; //in address 0x10
    // cout<< FunAdd(&x); //AddressOfx //0x10
    // cout<< *(FunAdd(&x))  ; //4
    // //
    // *(FunAdd(&x))=100; //True
    // cout<<x; //100
    // //

    ///pass/Return By Value
    // int x=3;
    // int result=FunVal(x); //4
    // cout<<FunVal(x); //4
    // //
    // FunVal(x)=33;  //Compile Error //LVALUE
    // //
}

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
///Composition
#include<iostream>
using namespace std;
class Point
{
    private:
    int x;
    int y;
    public:
    void setX(int _x){x=_x;}
    void setY(int _y){y=_y;}
    int getX(){return x;}
    int getY(){return y;}
    Point(){x=y=0;}  //create start // create end
    Point(int _x,int _y){x=_x;y=_y;}
    Point(const Point& old){x=old.x;y=old.y;}
    ~Point(){cout<<"pnt dest";}
    
}; 

class Line
{
    private:
    Point start;
    Point end;
    public:
    void setStart(Point _start){start=_start;}
    void setEnd(Point _end){end=_end;}
    Point getStart(){return start;}
    Point getEnd(){return end;}
    //
    Line()
    {
        //compiler
        //start x0 y0   //end x0 y0
        //
        //start.x=0; start.y=0;//Compile Error Inaccessible
        //useless code
        //start.setX(0);
        //start.setY(0);
        //end.setX(0);
        //end.setY(0);
    }
    Line(int x1,int y1,int x2,int y2)
    {
        //#Jump to Point class  #2
        //Compiler start x0 y0    end x0 y0
        //
        start.setX(x1);
        start.setY(y1);
        //Compiler start x1 y2    end x0 y0
        end.setX(x2);
        end.setY(y2);
        //Compiler start x1 y2    end x3 y4
        //#Jump to Point class  #6
    }
    Line(Point _start,Point _end)
    {start=_start;end=_end;}
    Line(const Line& old){start=old.start;end=old.end;}
    ~Line(){cout<<"Line dest";}
    void Print()
    {
        cout<<"Line=>"<<endl;
        cout<<"start" <<"("<<start.getX()<<","<<start.getY()<<")"<<endl;
        cout<<"end" <<"("<<end.getX()<<","<<end.getY()<<")"<<endl;
    }
};

/// Constructor Chaining 
///Increase performance
///reduce code written
class Rect
{
    private:
    Point ul;
    Point lr;
    public:
    void setUL(Point _ul){ul=_ul;}
    void setLR(Point _lr){lr=_lr;}
    Point getUL(){return ul;}
    Point getLR(){return lr;}
    Rect()//:ul(0,0),lr() //useless code
    {
        //Compiler ul 0 0    lr 0 0
    }
    Rect(int x1,int y1,int x2,int y2):ul(x1,y1),lr(x2,y2)
    {
        //
        //Compiler ul x1 y2     lr x3 y4
        //
    }
    Rect(Point _ul,Point _lr)
    {
        ul=_ul;
        lr=_lr;
    }
    Rect(const Rect& old)
    {
        ul=old.ul;lr=old.lr;
    }
    ~Rect(){cout<<"Rect dest";}
    void Print()
    {
        cout<<"Rectangle=>"<<endl;
        cout<<"ul" <<"("<<ul.getX()<<","<<ul.getY()<<")"<<endl;
        cout<<"lr" <<"("<<lr.getX()<<","<<lr.getY()<<")"<<endl;
    }
};

class Circle
{
    private:
    Point center;
    int radius;
    public:
    void setCenter(Point _center){center=_center;}
    Point getCenter(){return center;}
    void setRadius(int _radius){radius=_radius;}
    int getRadius(){return radius;}
    Circle()
    {
        radius=0;
    }
    Circle(int x,int y,int _radius):center(x,y)
    {
        radius=_radius;
    }
    Circle(Point _center,int _radius)
    {
        center=_center;
        radius=_radius;
    }
    Circle(const Circle& old)
    {
        center=old.center;
        radius=old.radius;
    }
    ~Circle(){}
    void Print()
    {
        cout<<"Circle=>"<<endl;
        cout<<"center" <<"("<<center.getX()<<","<<center.getY()<<")"<<endl;
        cout<<"radius " <<radius<<endl;
    }
};

class Tri
{
    private:
    Point p1,p2,p3;
    public:
    //setters& getters
    Tri(){}
    Tri(int x1,int y1,int x2,int y2,int x3,int y3):
    p1(x1,y1),p2(x2,y2),p3(x3,y3)
    {}
    //
    //
    //
    //
};
int main()
{
    Point p1(3,4),p2(5,6);
    //o/p
    //point 2p ctor
    //point 2p ctor
    //point 2p ctor
    //point dest

    Line l1;  //Debugging
    //point start ctor
    //point end ctor
    //line def ctor
    //line dest
    //point dest end
    //point dest start

    Line l2(1,2,3,4);
    //point start ctor
    //point end ctor
    //line 4p int ctor
    //line dest
    //point dest end
    //point dest start


    Rect r1;
    //point def ctor ul
    //point def ctor lr
    //Rect def ctor

    Rect r2(1,2,3,4);
    //point 2p ctor
    //point 2p ctor
    //rect 4p ctor
    //rest dest
    //pnt dest
    //pnt dest
    Rect r3(p1,p2);
    ///point cpy ctor p1
    ///point cpy ctor p2
    //rect 2p points ctor
    //rest dest
    //pnt dest
    //pnt dest
}

/////////////////////////////////////////////////

///@12.15

///Casting with point2d and point3d
///pass ,return    by val,add,ref

///try Composition with point,line,rect,circle,tri
///make sude to be aware of debugging