#include <iostream>
using namespace std;

class Complex
{
private:
    int real;
    int img;
public:
    void SetReal(int _real)
    {
        real = _real;
    }
    void SetImg(int _img)
    {
        img = _img;
    }
    int GetReal()
    {
        return real;
    }
    int GetImg()
    {
        return img;
    }

    //////////////////////////////////////////////////

    void Print()
    {
        if (real == 0 && img == 0)
        {
            cout << "0" << endl;
        }
        else if (real == 0)
        {
            if (img == -1)
            {
                cout <<"-i" << endl;
            }
            else
            {
                cout << img << "i" << endl;
            }
        }
        else if (img == 0)
        {
            cout << real << endl;
        }
        else if (img == 1)
        {
            cout << real << "+i" << endl;
        }
        else if (img == -1)
        {
            cout << real << "-i" << endl;
        }
        else if (img < 0)
        {
            cout << real << img << "i" << endl;
        }
        else
        {
            cout << real << "+" << img << "i" << endl;
        }
    }



    Complex Add(Complex right)
    {
        Complex result;
        result.real = real + right.real;
        result.img = img + right.img;
        return result;
    }
};

Complex AddComplex(Complex& left, Complex& right)
{
    Complex result;
    int r = left.GetReal() + right.GetReal();
    int i = left.GetImg() + right.GetImg();
    result.SetReal(r);
    result.SetImg(i);
    return result;
}

int main()
{
    Complex c1, c2, c3;

    int real1, img1;
    cout << "Enter the real of the first complex number = : ";
    cin >> real1 ;
    c1.SetReal(real1);

    cout << "Enter the  imag of the first complex number = : ";
    cin>> img1;
    c1.SetImg(img1);


    int real2, img2;

    cout << "Enter the real of the second complex number = : ";
    cin >> real2 ;
    c2.SetReal(real2);

    cout << "Enter the  imag of the second complex number = : ";
    cin>> img2;
    c2.SetImg(img2);


    cout << "First complex number: ";
    c1.Print();
    cout << "Second complex number: ";
    c2.Print();


    c3 = c1.Add(c2);
    cout << "Sum using member function: ";
    c3.Print();
    c3 = AddComplex(c1, c2);
    cout << "Sum using standalone function: ";
    c3.Print();
    c2.Print();
    c1.Print();

    return 0;
}
