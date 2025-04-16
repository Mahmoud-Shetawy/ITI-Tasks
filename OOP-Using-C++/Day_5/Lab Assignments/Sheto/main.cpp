#include <iostream>
#include "graphics.h"

using namespace std;


class Shape {
protected:
    int mnfColor;

public:
    Shape() { mnfColor = 0; }
    Shape(int _mnfColor) { mnfColor = _mnfColor; }
    Shape(const Shape& old) { mnfColor = old.mnfColor; }
    ~Shape() {}

    void SetMnfColor(int _mnfColor) { mnfColor = _mnfColor; }
    int GetMnfColor() { return mnfColor; }
};


class Point {
    int x, y;

public:
    Point() : x(0), y(0) {}
    Point(int _x, int _y) : x(_x), y(_y) {}
    Point(const Point& old) : x(old.x), y(old.y) {
        //cout << "Copy constructor called\n";
        }
    ~Point() {}

    void SetX(int _x) { x = _x; }
    int GetX() { return x; }
    void SetY(int _y) { y = _y; }
    int GetY() { return y; }
};


class MNFLine : public Shape {
private:
    Point start;
    Point end;

public:
    MNFLine() : Shape() {}
    MNFLine(int _x1, int _y1, int _x2, int _y2, int _mnfColor)
        : start(_x1, _y1), end(_x2, _y2), Shape(_mnfColor) {}
    MNFLine(const MNFLine& old)
        : start(old.start), end(old.end), Shape(old.mnfColor) {}
    ~MNFLine() {}

    void DrawLine() {
        setcolor(mnfColor);
        line(start.GetX(), start.GetY(), end.GetX(), end.GetY());
    }
};


class MNFRectangle : public Shape {
private:
    Point ul;
    Point lr;

public:
    MNFRectangle() : Shape() {}
    MNFRectangle(int x1, int y1, int x2, int y2, int _mnfColor)
        : ul(x1, y1), lr(x2, y2), Shape(_mnfColor) {}
    MNFRectangle(const MNFRectangle& old)
        : ul(old.ul), lr(old.lr), Shape(old.mnfColor) {}
    ~MNFRectangle() {}

    void DrawRectangle() {
        setcolor(mnfColor);
        rectangle(ul.GetX(), ul.GetY(), lr.GetX(), lr.GetY());
    }
};


class MNFCircle : public Shape {
private:
    Point center;
    int radius;

public:
    MNFCircle() : Shape(), radius(0) {}
    MNFCircle(int x, int y, int _radius, int _mnfColor)
        : center(x, y), radius(_radius), Shape(_mnfColor) {}
    MNFCircle(const MNFCircle& old)
        : center(old.center), radius(old.radius), Shape(old.mnfColor) {}
    ~MNFCircle() {}

    void DrawCircle() {
        setcolor(mnfColor);
        circle(center.GetX(), center.GetY(), radius);
    }
};


class MNFTriangle : public Shape {
private:
    Point p1, p2, p3;

public:
    MNFTriangle() : Shape() {}
    MNFTriangle(int x1, int y1, int x2, int y2, int x3, int y3, int _mnfColor)
        : p1(x1, y1), p2(x2, y2), p3(x3, y3), Shape(_mnfColor) {}
    MNFTriangle(const MNFTriangle& old)
        : p1(old.p1), p2(old.p2), p3(old.p3), Shape(old.mnfColor) {}
    ~MNFTriangle() {}

    void DrawTriangle() {
        setcolor(mnfColor);
        line(p1.GetX(), p1.GetY(), p2.GetX(), p2.GetY());
        line(p2.GetX(), p2.GetY(), p3.GetX(), p3.GetY());
        line(p1.GetX(), p1.GetY(), p3.GetX(), p3.GetY());
    }
};



class Picture {
private:
    Shape** pshapes;
    int ssize;

public:
    Picture()
        : Picture() : pshapes(nullptr), ssize(0) {}

    void SetShapes(Shape** _pshapes, int _ssize) {
        pshapes = _pshapes;
        ssize = _ssize;
    }

    void DrawAll() {
 void DrawAll() {
        for (int i = 0; i < ssize; i++) {
                pshapes[i]->Draw();
            }
    }
};


int main() {
    initgraph();

        MNFCircle circles[2] = {
        MNFCircle(850, 140, 50, 1),
        MNFCircle(850, 400, 100, 9)
    };
    MNFLine lines[4] = {
        MNFLine(830, 145, 800, 400, 3),
        MNFLine(870, 145, 900, 400, 3),
        MNFLine(840, 600, 820, 430, 3),
        MNFLine(860, 600, 860, 430, 3)
    };
    MNFRectangle rect(720, 530, 980, 600, 25);

    MNFTriangle triangle(940, 540, 920, 580, 960, 580, 20);

    Picture picture;
    picture.SetCircle(circles, 2);
    picture.SetLines(lines, 4);
    picture.SetRects(&rect, 1);

    picture.SetTriangle(&triangle, 1);

    picture.DrawAll();

    picture.SetLines(NULL, 0);
    picture.SetRects(NULL, 0);
    picture.SetCircle(NULL, 0);
    picture.SetTriangle(NULL, 0);

    return 0;
}
