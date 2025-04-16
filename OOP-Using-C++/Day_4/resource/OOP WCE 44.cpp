//Operator Overloading Cont'd casting
//return by value,reference,address
//OOR ->Composition ,Aggregation,Association,Inheritance
////////////////////////////////////////////////////////
 #include<iostream>
 using namespace std;
// class Point2D
// {
//     int x;
//     int y;
//     public:
//     void SetX(int _x){x=_x;}
//     void SetY(int _y){y=_y;}
//     int GetX(){return x;}
//     int GetY(){return y;}
//     Point2D(){x=y=0;}
//     Point2D(int _x,int _y){x=_x;y=_y;}
//     Point2D(const Point2D& old){x=old.x;y=old.y;}
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
//     void SetX(int _x){x=_x;}
//     void SetY(int _y){y=_y;}
//     void SetZ(int _z){z=_z;}
//     int GetX(){return x;}
//     int GetY(){return y;}
//     int GetZ(){return z;}
//     Point3D(){x=y=z=0;}
//     Point3D(int _x,int _y,int _z){x=_x;y=_y;z=_z;}
//     Point3D(const Point2D& old){x=old.x;y=old.y;z=old.z;}
//     void Print()
//     {
//         cout<<"("<<x<<","<<y<<","<<z<<")"<<endl;
//     }
//     //
//     operator Point2D()
//     {
//         Point2D result(this->x,this->y);
//         return result;
//         return Point2D(x,y);
//     }
//     //
// };

// int main()
// {
//     Point2D p2d(3,4);
//     Point3D p3d(5,6,7);
//     p2d.Print();
//     p3d.Print();

//     //casting
//     Point2D tmp=p3d;
//     Point2D tmp2=(Point2D)p3d;
//     tmp.Print(); //(5,6)
// }

/////////////////////////////////////////////////////
int PassVal(int x)
{
    x++;
    return x;
}
int main()
{
    int num=10;
    int result= PassVal(num);
    cout<<result ; //11
    PassVal(num)=44; //Compile Error 
}
////////////////////////////////////////
int* PassAdd(int* x)
{
    (*x)++;
    return x;
}

int main()
{
    int num=10;
    int result=*(PassAdd(&num));
    cout<<result; //11

    *(PassAdd(&num))= 44;
    cout<<num; //44

}

///////////////////////////////////////
int& PassRef(int& x)
{
    x++;
    return x;
}

int main()
{
    int num=10;
    int result=PassRef(num);
    cout<<result; //11

    PassRef(num)=44;
    cout<<num; //44
    return 0;
}

//////////////////////////////////////////////////////
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
    ~IntArray(){delete[] arr;}
    IntArray(const IntArray& old)
    {
        size=old.size;
        arr=new int[size];
        for (int i = 0; i < size; i++)
        {
            arr[i]=old.arr[i];
        }
    }
    IntArray operator=(const IntArray& right)
    {
        delete[] arr;
        size=right.size;
        arr=new int[size];
        for (int i = 0; i < size; i++)
        {
            arr[i]=right.arr[i];
        }
        return *this;
    }

    void SetValue(int value,int index)
    {
        if(index>=0&&index<size)
        {arr[index]=value;}
    }

    int GetValue(int index)
    {
        if(index>=0&&index<size)
        {return arr[index];}
    }

    int& operator[](int index)
    {
        if(index>=0&&index<size)
        {
            return this->arr[index];
        }
    }
};

int main()
{
    IntArray obj;
    obj.SetValue(10,0);
    obj.SetValue(20,1);
    obj.SetValue(30,2);
    cout<<obj.GetValue(1);  //20

    cout<<obj[0];
    obj[0]=44;
}

/////////////////////////////////////////////////////
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
        ///class Teacher
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
        ///class Student
        //{
            //id,name,age
            //Department * Dept;
            //ctor(){Dept=null;}
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

///////////////////////////////////////////////////////
//Composition

class Point
{
    int x;
    int y;
    public:
    void SetX(int _x){x=_x;}
    void SetY(int _y){y=_y;}
    int GetX(){return x;}
    int GetY(){return y;}
    //l1 start ctor
    //l1 end ctor
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
    Point(const Point& old){x=old.x;y=old.y;cout<<"pnt cpy ctor";}
    ~Point(){cout<<"Point dest";}
};

class Line
{
    Point start;
    Point end;
    int color;
    public:
    void SetMyColor(int _color){color=_color;}
    int GetMyColor(){return color;}
    void SetStart(Point _start){start=_start;}
    Point GetStart(){return start;}
    void SetEnd(Point _end){end=_end;}
    Point GetEnd(){return end;}
    Line()
    {
        //l1 start x0 y0   end x0 y0
        cout<<"Line def ctor";
        //start.x=0;start.y=0; //inaccessible
        color=0;
        // //useless
        // start.SetX(0);
        // start.SetY(0);
        // end.SetX(0);
        // end.SetY(0);
    }
    Line(int x1,int y1,int x2,int y2,int _color)
    {
        //l2 start x0 y0  end x0 y0 color ?
        cout<<"line 5p ctor";
        start.SetX(x1);
        start.SetY(y1);
        end.SetX(x2);
        end.SetY(y2);
        color=_color;
        //
        //l2 start x1 y2  end x3 y4 color5
    }
    Line(const Line& old)
    {
        start=old.start;
        end=old.end;
        color=old.color;
    }
    ~Line(){}
    void DrawLine()
    {
        setcolor(color);
        line(start.GetX(),start.GetY(),end.GetX(),end.GetY());
    }
};

//constructor Chaining
//1- increase performance
//2- reduce code written
class Rect
{
    private:
    Point ul;
    Point lr;
    int color;
    public:
    void SetMyColor(int _color){color=_color;}
    int GetMyColor(){return color;}
    void SetUL(Point _ul){ul=_ul;}
    Point GetUL(){return ul;}
    void SetLR(Point _lr){lr=_lr;}
    Point GetLR(){return lr;}
    Rect()
    {
        //r1 ul x0 y0   lr x0 y0 color?
        cout<<"Rect def ctor";
        color=0;
        //useless //ul.SetX(0);
    }
    Rect(int x1,int y1,int x2,int y2,int _color)
    :ul(x1,y1),lr(x2,y2)
    {
        //r1 ul x1 y2   lr x3 y4  color?
        cout<<"Rect 5p ctor";
        color=_color; 
    }
    ~Rect(){}
    Rect(const Rect& old)
    {
        ul=old.ul;
        lr=old.lr;
        color=old.color;
    }
    void DrawRect()
    {
        setcolor(color);
        rectangle(ul.GetX(),ul.GetY(),lr.GetX(),lr.GetY());
    }
};

class Circle
{
    Point center;
    int radius;
    int color;
    public:
    void SetCenter(Point _center){center=_center;}
    Point GetCenter(){return center;}
    void SetMyColor(int _color){color=_color;}
    int GetMyColor(){return color;}
    //
    //
    Circle()
    {
        cout<<"crcle def ctor";
        color=0;
        radius=0;
    }
    Circle(int x,int y,int _radius,int _color):center(x,y)
    {
        color=_color;
        radius=_radius;
    }
    ~Circle(){}
    Circle(const Circle& old){}
    void DrawCircle()
    {
        setcolor(color);
        circle(center.GetX(),center.GetY(),radius);
    }
};

class Triangle
{
    Point p1,p2,p3;
    int color;
    public:
    //
    //
    //
    //
    //
    //
    //
    void DrawTriangle()
    {
        setcolor(color);
        trainlgle(); //XXXXXX
    }
};

int main()
{
    Rect r2(1,2,3,4,5);
    //o/p ctor chaining
    //pnt 2p ctor ul
    //pnt 2p ctor lr
    //rect  5p ctor

    Rect r1;
    //o/p
    //pnt def ctor ul
    //pnt def ctor lr
    //rect def ctor
}

int main()
{
    initgraph();
    Line l2(1,2,3,4,5);
    l2.SetMyColor(55);
    //o/p
    //point def ctor start
    //point def ctor end
    //line 5p ctor
    l2.Draw();

    Line l1;
    //o/p
    //point def ctor start
    //point def ctor end
    //line def ctor
    //line dest
    //pnt dest end
    //pnt dest start
}


//////////////////////////////////////////////////
///Lab
//point -> Line ->Rect->Circle->Tri
//REMEMBER Debug with& without ctor chaining

//draw ABAGORA

//bonus
//moving fan


