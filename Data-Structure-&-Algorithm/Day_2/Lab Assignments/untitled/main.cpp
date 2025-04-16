#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////
class A                   //base class
{

    int privdataA;      //(functions have the same access
protected:              //rules as the data shown here)
   static  int protdataA;
public:
    int pubdataA;


};
////////////////////////////////////////////////////////////////
class B : public A        //publicly-derived class
{
public:
    static void funct()
    {
        int a;
        // a = privdataA;    //error: not accessible

         a = pubdataA;       //OK
    }
    void functd() {
        int a;
        a = protdataA;
    }     //OK
};

////////////////////////////////////////////////////////////////
class C : private A         //privately-derived class
{
public:
    void funct()
    {
        int a;
        // a = privdataA; //error: not accessible
        a = protdataA; //OK
        a = pubdataA; //OK
    }
};

class Tester {
public:
    int x;
    static int var ;
    Tester(int a) { x = a;}
    static void myFunction(int a) {
        Tester obj(9) ;
        obj.x=a ;
        cout<< obj.x;
    }
};

    // Line 1
    // Line 2
int main() {
    int a;
    privdataA =3;
    B objB;
    // a = objB.privdataA; //error: not accessible
    // a = objB.protdataA; //error: not accessible
    // a = objB.pubdataA; //OK (A public to B)
    C objC;
    // a = objC.privdataA; //error: not accessible
    // a = objC.protdataA; //error: not accessible
    // a = objC.pubdataA; //error: not accessible (A private to C)
    return 0;
}
