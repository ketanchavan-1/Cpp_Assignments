#include <iostream>
using namespace std;

// 1. Compile-time polymorphism: function overloading
class Area {
public:
    int area(int side) {                                // square
        if (side <= 0) return 0;                        // invalid size
        return side * side;
    }
    int area(int l, int b) {                            // rectangle
        if (l <= 0 || b <= 0) return 0;                 // invalid size
        return l * b;
    }
    double area(double r) {                             // circle
        if (r <= 0) return 0;                           // invalid size
        return 3.14 * r * r;
    }
};

// 2. Compile-time polymorphism: operator overloading
class Complex {
    int real, imag;
public:
    Complex(int r = 0, int i = 0) {
        real = r;
        imag = i;
    }
    Complex operator+(const Complex &c) const {         // overloads +
        return Complex(real + c.real, imag + c.imag);
    }
    void show() const {
        if (imag < 0)
            cout << real << " - " << -imag << "i" << endl;
        else
            cout << real << " + " << imag << "i" << endl;
    }
};

// 3. Run-time polymorphism: virtual function
class Shape {
public:
    virtual void draw() const { cout << "Drawing a shape" << endl; }
    virtual ~Shape() {}
};
class Circle : public Shape {
public:
    void draw() const override { cout << "Drawing a circle" << endl; }
};
class Rectangle : public Shape {
public:
    void draw() const override { cout << "Drawing a rectangle" << endl; }
};

int main() {
    cout << "--- Function Overloading ---" << endl;
    Area a;
    cout << "Area of square: " << a.area(5) << endl;
    cout << "Area of rectangle: " << a.area(4, 6) << endl;
    cout << "Area of circle: " << a.area(2.0) << endl;
    cout << "Square with negative side: " << a.area(-3) << endl;
    cout << "Rectangle with negative length: " << a.area(-4, 6) << endl;
    cout << "Circle with negative radius: " << a.area(-1.5) << endl;

    cout << "\n--- Operator Overloading ---" << endl;
    Complex c1(3, 4), c2(1, 2), c4(-2, -7);
    Complex c3 = c1 + c2;
    Complex c5 = c4 + c1;
    cout << "c1 = "; c1.show();
    cout << "c2 = "; c2.show();
    cout << "c1 + c2 = "; c3.show();
    cout << "c4 = "; c4.show();
    cout << "c4 + c1 = "; c5.show();

    cout << "\n--- Virtual Function (Run-time Polymorphism) ---" << endl;
    Shape s;
    Circle c;
    Rectangle r;
    Shape *ptr;

    ptr = &s;
    ptr->draw();
    ptr = &c;
    ptr->draw();
    ptr = &r;
    ptr->draw();

    return 0;
}
