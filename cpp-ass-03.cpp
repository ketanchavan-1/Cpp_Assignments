#include <iostream>
using namespace std;

class Complex
{
    int real;
    int imag;

public:

    // Default Constructor
    Complex()
    {
        real = 0;
        imag = 0;
    }

    // Parameterized Constructor
    Complex(int r, int i)
    {
        real = r;
        imag = i;
    }

    // Operator Overloading
    Complex operator+(Complex c)
    {
        Complex temp;

        temp.real = real + c.real;
        temp.imag = imag + c.imag;

        return temp;
    }

    // Display function
    void display()
    {
        if (imag >= 0)
            cout << real << " + " << imag << "i";
        else
            cout << real << " - " << -imag << "i";
    }
};

int main()
{
    int real1, imag1, real2, imag2;

    // Taking user input
    cout << "Enter real and imaginary part of first complex number: ";
    cin >> real1 >> imag1;

    cout << "Enter real and imaginary part of second complex number: ";
    cin >> real2 >> imag2;

    // Objects using parameterized constructor
    Complex c1(real1, imag1);
    Complex c2(real2, imag2);

    // Object using default constructor
    Complex c3;

    // Addition using overloaded + operator
    c3 = c1 + c2;

    cout << "\nFirst Complex Number: ";
    c1.display();

    cout << "\nSecond Complex Number: ";
    c2.display();

    cout << "\nAddition: ";
    c3.display();

    return 0;
}