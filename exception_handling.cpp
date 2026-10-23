#include <iostream>
using namespace std;

// 1. try, throw and catch
double divide(int a, int b) {
    if (b == 0)
        throw "Division by zero";                 // throws a const char*
    return static_cast<double>(a) / b;
}

void showDivide(int a, int b) {
    try {
        double result = divide(a, b);             // may throw, so print afterwards
        cout << a << " / " << b << " = " << result << endl;
    }
    catch (const char *msg) {
        cout << a << " / " << b << " -> Error: " << msg << endl;
    }
}

// 2. Multiple catch blocks and catch-all
void throwTest(int choice) {
    if (choice == 1) throw 10;                    // int
    if (choice == 2) throw "Text exception";      // const char*
    if (choice == 3) throw 3.5;                   // double
    cout << "Choice " << choice << ": no exception thrown" << endl;
}

void runTest(int choice) {
    try {
        throwTest(choice);
    }
    catch (int n) {
        cout << "Choice " << choice << ": int caught = " << n << endl;
    }
    catch (const char *s) {
        cout << "Choice " << choice << ": string caught = " << s << endl;
    }
    catch (...) {
        cout << "Choice " << choice << ": unknown exception caught" << endl;
    }
}

// 3. User-defined exception classes (base class and derived classes)
class MyError {
public:
    virtual const char *what() const { return "Error"; }
    virtual ~MyError() {}
};

class InsufficientBalance : public MyError {
public:
    const char *what() const override { return "Insufficient balance"; }
};

class InvalidAmount : public MyError {
public:
    const char *what() const override { return "Amount must be positive"; }
};

class IndexOutOfRange : public MyError {
public:
    const char *what() const override { return "Index out of range"; }
};

class Account {
    int balance;
public:
    Account(int b) { balance = b; }
    void withdraw(int amount) {
        if (amount <= 0)
            throw InvalidAmount();
        if (amount > balance)
            throw InsufficientBalance();
        balance = balance - amount;
        cout << "Withdrawn " << amount << ", balance = " << balance << endl;
    }
};

void tryWithdraw(Account &acc, int amount) {
    try {
        acc.withdraw(amount);
    }
    catch (const InsufficientBalance &e) {        // derived class first
        cout << "Withdraw " << amount << " -> " << e.what() << endl;
    }
    catch (const MyError &e) {                    // base class later
        cout << "Withdraw " << amount << " -> " << e.what() << endl;
    }
}

// 4. Array bounds checking
int getElement(const int arr[], int size, int index) {
    if (index < 0 || index >= size)
        throw IndexOutOfRange();
    return arr[index];
}

void showElement(const int arr[], int size, int index) {
    try {
        int value = getElement(arr, size, index); // may throw, so print afterwards
        cout << "Element at index " << index << ": " << value << endl;
    }
    catch (const IndexOutOfRange &) {
        cout << "Index " << index << " is out of range" << endl;
    }
}

// 5. Rethrowing an exception
void inner() {
    try {
        throw "Problem in inner()";
    }
    catch (const char *msg) {
        cout << "inner() caught: " << msg << " - rethrowing" << endl;
        throw;                                    // passes it to the caller
    }
}

int main() {
    cout << "--- try, throw and catch ---" << endl;
    showDivide(10, 2);
    showDivide(7, 2);
    showDivide(0, 5);
    showDivide(-9, 3);
    showDivide(10, 0);

    cout << "\n--- Multiple catch blocks and catch-all ---" << endl;
    for (int i = 1; i <= 4; i++)
        runTest(i);

    cout << "\n--- User-defined exceptions ---" << endl;
    Account acc(1000);
    tryWithdraw(acc, 500);
    tryWithdraw(acc, 500);
    tryWithdraw(acc, 1);
    tryWithdraw(acc, 0);
    tryWithdraw(acc, -50);

    cout << "\n--- Array bounds checking ---" << endl;
    int arr[3] = {10, 20, 30};
    showElement(arr, 3, 2);
    showElement(arr, 3, 3);
    showElement(arr, 3, -1);

    cout << "\n--- Rethrowing an exception ---" << endl;
    try {
        inner();
    }
    catch (const char *msg) {
        cout << "main() caught: " << msg << endl;
    }

    return 0;
}
