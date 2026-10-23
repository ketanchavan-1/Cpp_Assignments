#include <iostream>
using namespace std;

// ---------- Function templates ----------
template <class T>
T maximum(T a, T b) {
    return (a > b) ? a : b;
}

template <class T>
void swapValues(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

// ---------- Class template ----------
template <class T>
class Calculator {
private:
    T a, b;
public:
    Calculator(T x, T y) {
        a = x;
        b = y;
    }
    T add() { return a + b; }
    T subtract() { return a - b; }
    T multiply() { return a * b; }
    bool divide(T &result);              // defined outside the class
};

// Member function of a class template defined outside the class
template <class T>
bool Calculator<T>::divide(T &result) {
    if (b == 0)
        return false;                    // division by zero is not possible
    result = a / b;
    return true;
}

// Function template that uses the class template
template <class T>
void showResults(Calculator<T> c) {
    T quotient = T();
    cout << "Sum = " << c.add()
         << ", Difference = " << c.subtract()
         << ", Product = " << c.multiply();
    if (c.divide(quotient))
        cout << ", Quotient = " << quotient << endl;
    else
        cout << ", Quotient = not possible (division by zero)" << endl;
}

int main() {
    cout << "--- Function template: maximum ---" << endl;
    cout << "Maximum of 10 and 20: " << maximum(10, 20) << endl;
    cout << "Maximum of 7 and 7: " << maximum(7, 7) << endl;
    cout << "Maximum of -5 and -9: " << maximum(-5, -9) << endl;
    cout << "Maximum of 3.5 and 2.5: " << maximum(3.5, 2.5) << endl;
    cout << "Maximum of 'a' and 'z': " << maximum('a', 'z') << endl;

    cout << "\n--- Function template: swapValues ---" << endl;
    int x = 5, y = 8;
    cout << "Before swap: x = " << x << ", y = " << y << endl;
    swapValues(x, y);
    cout << "After swap:  x = " << x << ", y = " << y << endl;
    double p = 1.5, q = 2.5;
    cout << "Before swap: p = " << p << ", q = " << q << endl;
    swapValues(p, q);
    cout << "After swap:  p = " << p << ", q = " << q << endl;

    cout << "\n--- Class template: Calculator ---" << endl;
    Calculator<int> c1(20, 5);
    cout << "int (20, 5) -> ";
    showResults(c1);

    Calculator<double> c2(7.5, 2.5);
    cout << "double (7.5, 2.5) -> ";
    showResults(c2);

    Calculator<int> c3(10, 0);
    cout << "int (10, 0) -> ";
    showResults(c3);

    Calculator<int> c4(7, 2);
    cout << "int (7, 2) -> ";
    showResults(c4);

    Calculator<int> c5(-8, 2);
    cout << "int (-8, 2) -> ";
    showResults(c5);

    return 0;
}
