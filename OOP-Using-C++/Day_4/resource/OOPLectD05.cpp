//Operator Overloading Cont'd casting ,[]
//return by value,reference,address
//OOR ->Composition [T] ,Aggregation,Association,Inheritance

#include<iostream>
using namespace std;
class Complex
{
    int real;
    int img;
    public:
    //setter
    //getter
    //ctor
    //ctor(int,int)
    //cpy ctor(Complec &old)
    //~Dest()

    //Casting
    operator int()
    {
        return this->real;
    }
};
class Point2D
{
    int x;
    int y;
    public:
    void setX(int _x){x=_x;}
    void setY(int _y){y=_y;}
    int getX(){return x; }
    int getY(){return y; }
    Point2D(){x=y=0;}
    Point2D(int _x,int_y){x=_x;y=_y;}
    Point2D(const Point2D &old)
    {
        this->x=old.x;
        this->y=old.y;
    }
    Point2D& operator=(const Point2D &right)
    {
        this->x=right.x;
        this->y=right.y;
        return *this;
    }
    ~Point2D(){cout<<"Point2d dest";}
    void Print()
    {
        cout<<"("<<x<<","<<y<<")"<<endl;
    }

};

class Point3D
{
    int x,y,z;
    public:
    void setX(int _x){x=_x;}
    void setY(int _y){y=_y;}
    void setZ(int _z){z=_z;}
    int getX(){return x; }
    int getY(){return y; }
    int getZ(){return z; }
    Point3D(){x=y=z=0;}
    Point3D(int _x,int_y,int _z){x=_x;y=_y;z=_z;}
    Point3D(const Point3D &old)
    {
        this->x=old.x;
        this->y=old.y;
        this->z=old.z;
    }
    Point3D& operator=(const Point3D &right)
    {
        this->x=right.x;
        this->y=right.y;
        this->z=right.z;
        return *this;
    }
    ~Point3D(){cout<<"Point3d dest";}
    void Print()
    {
        cout<<"("<<x<<","<<y<<","<<z<<")"<<endl;
    }
    //casting into Point2D
    //this  =>pointer to point3d
    operator Point2D()
    {
        Point2D tmp(this->x,this->y);
        return tmp;
    }


};
int main()
{
    Complex c1(11,22);
    int x;
    //old fashion
    //Explicit casting
    x=(int)c1;
    //new one
    //imlicit casting
    x=c1;
    cout <<x;  //11

    Point2D p2d(1,2);
    Point3D p3d(4,5,6);

    p2d.Print();   //(1,2)
    p3d.Print();   //(4,5,6)

    //Point2D obj=(Point2D)p3d;
    Point2D obj=p3d;
    obj.Print();  //(4,5)

    return 0;    
}

//////////////////////////////////////////////
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



//class represent array
array size 10

arr[10] error`
arr[11] error
arr[5] =4
arr[-1] error

#include<iostream>
using namespace std;
class IntArray
{
    int size;
    int *arr;
    public:
    IntArray()
    {
        size=10;
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
    IntArray(const IntArray &old)
    {
        this->size=old.size;
        arr=new int[size];
        for(int i=0;i<size;i++)
        {
            arr[i]=old.arr[i];
        }
    }
    IntArray operator=(const IntArray &right)
    {
        delete [] this->arr;
        size=right.size;
        arr=new int[size];
        for(int i=0;i<size;i++)
        {
            arr[i]=right.arr[i];
        }
    }
    void setValue(int value,int index)
    {
        if(index>=0&&index<size)
        {
            this->arr[index]=value;
        }
    }
    int getValue(int index)
    {
        int retVal=-12121;

        if(index>=0&&index<size)
        {
            retVal=this->arr[index];
        }
        return retVal;
    }

    int& operator[](int  index)
    {

        //setter & getter
        if(index>=0&&index<size)
        {
            return this->arr[index];
        }
        /*int retval=-22222;
        if(index>=0&&index<size)
        {
            retval= this->arr[index];
        }
        return retval;*/
    } 

};
int main()
{
    IntArray obj(10);




    obj.setValue(10,0);
    obj.setValue(11,1);
    obj.setValue(12,2);
    obj.setValue(13,3);
    obj.setValue(14,4);
    obj.setValue(15,5);
    obj.setValue(16,6);
    obj.setValue(17,77);
    obj.setValue(18,8);
    obj.setValue(19,9);
    obj.setValue(20,10);

    cout<<obj.getValue(44); //rubbish
    cout<<obj.getValue(2); //12
    int ind=2
    cout<<obj[2] ; 12
    obj[2]=44;  //lvalue
    cout<<obj[2] ; 44
    // int  obj.operator[](index)


    return 0;
}


//assignments
///1- complex casting to int

///2- cast employee to person
#include<string.h>
class Person
{
    public:
    char fullName[21];
    float netSalary;
};
class Employee
{
    public:
    char fname[10];
    char lname[10];
    float salary;
    float commission;
    float deduction;

    operator Person()
    {

    }
};

main()
{
    Employee emp;
    strcpy(emp.fname,"Ahmed");
    strcpy(emp.lname,"Osama");
    //emp.fname="Sara"; XXXXX
    emp.salary=1000;
    emp.commission=100;
    emp.deduction=50;

    Person p=emp;
    ///p.fullname (ahmed osama)
    //p.netsalary  (1050)
}

///3-pass & return   by   val ,add,ref

///4-IntArray   remember 
//overload [] operator  setter and getter

//5- Abagora
//Class Point,Rect,Line,Circle,Tri  [include color]

///////////////////////////////////////////
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


//////////////////////////////////////////
////////////////Composition///////////////
///Line
////  Line Depends  on Two Points

///Triangle
////Depends on 3 Points

///Rectangle
//  Depends on 2 Points  upperLeft LowerRight

///Circle 
////  One Point   + int radius


///Point
    //(int x,int y)



/////////////////////////////////////////

class Point
{
    int x,y;
    public:
    //#5
    void setX(int _x){x=_x;}
    void setY(int _y){y=_y;}
    int getX(){return x;}
    int getY(){return y;}
    //#2ul #3lr
    Point(){x=y=0;}
    Point(int _x,int _y){x=_x;y=_y;}
    Point(int _num)
    {x=y=_num;}
    Point(const Point2D &old)
    {
        this->x=old.x;
        this->y=old.y;
    }
    Point& operator=(const Point &right)
    {
        this->x=right.x;
        this->y=right.y;
        return *this;
    }
    ~Point(){cout<<"Point2d dest";}
};

class Rect
{
    Point ul,lr;
    int color;
    public:
    void setUL(Point _ul){ul=_ul;}
    void setLR(Point _lr){lr=_lr;}
    void setColor(int _color){color=_color;}
    Point getUL(){return ul;}
    Point getLR(){return lr;}
    int getColor(){return color;}
    Rect()//:ul(),lr()//useless
    {
        //ul.setX(0);
        //ul.setY(0);
        //lr.setX(0);
        //lr.setY(0);
        color=0;
    }
    //#1
    //constructor chaining
    //1-Faster
    //2-Reduce code
    Rect(int x1,int y1,int x2 ,int y2 ,int c):
    ul(x1,y1),lr(x2,y2)
    {
       //#4
        //ul.setX(x1);
        //ul.setY(y1);
        //lr.setX(x2);
        //lr.setY(y2);
        color=c;
    }
    Rect(Point _ul,Point _lr,int c):
    ul(_ul),lr(_lr)
    {
        //ul=_ul;
        //lr=_lr;
        color=c;
    }
    Rect(const Rect & old)
    {
        ul=old.ul;
        lr=old.lr;
        color=old.color;
    }
    void draw()
    {
        setcolor(color);
        rectangle(ul.getX(),ul.getY(),lr.getX(),lr.getY());
    }
};

class Circle
{
    Point center;
    int raduis,color;
    public:
    //setter & getter
    Circle()//:center()
    {  
        raduis=0;
        color=0;
    }
    Circle(int x,int y,int r ,int c):
    center(x,y)
    {
        raduis=r;
        color=c;
    }
    Circle(Point _center,int r ,int c):center(_center)
    {
        raduis=r;
        color=c;
    }
    void Draw()
    {
        setcolor(color);
        circle(center.getX(),center.getY(),raduis);
    }
}


class Tri
{
    3 points

    Draw()
    {
        line()
        line()
        line()
    }
};
main()
{
    initgraph();
    Rect r(11,22,33,44,5);
    Rect r(11,22,33,44,5);


    Rect r2;
    //Compiler
    // 0- header of ctor r
    //1- constructor default point ul
    //2- constructor default point lr
    //3- constructor Rect r
    //    6 moves to Point class 

    r.draw(); 
    Circle c(66,77,88,9); 
    c.Draw();
    //Trace

    Point P1(11,22);
    Point P2(11,22);

    Rect r5(p1,p2,3);


    //destruct
    //1- destruct rect
    //2- destruct ul
    //3- destruct lr
    
}