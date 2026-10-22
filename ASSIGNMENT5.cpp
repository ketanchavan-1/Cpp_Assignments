#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    int rollNo;
    string name;
    int marks;
    static int count;                 // shared by all objects

public:
    // Constructor: 'this' separates data members from parameters
    Student(int rollNo, string name, int marks) {
        this->rollNo = rollNo;
        this->name = name;
        this->marks = marks;
        count++;
    }

    // Functions returning *this, so calls can be chained
    Student& setName(string name) {
        this->name = name;
        return *this;
    }
    Student& setMarks(int marks) {
        this->marks = marks;
        return *this;
    }

    // Inline function (defined inside the class)
    inline bool isPass() { return marks >= 40; }

    // Inline function (defined outside the class)
    inline void display();

    // Static member function
    static int getCount() { return count; }

    friend class Teacher;             // Teacher can access private data
};

int Student::count = 0;

inline void Student::display() {
    cout << "Roll No: " << rollNo << ", Name: " << name
         << ", Marks: " << marks
         << ", Result: " << (isPass() ? "Pass" : "Fail") << endl;
}

// Friend class
class Teacher {
public:
    void addGraceMarks(Student &s, int grace) {
        s.marks = s.marks + grace;    // accessing private member
    }
};

int main() {
    Student s1(101, "Ketan", 35);
    Student s2(102, "Rahul", 78);

    cout << "Total students: " << Student::getCount() << endl;

    cout << "\n--- Initial details ---" << endl;
    s1.display();
    s2.display();

    cout << "\n--- Function chaining using this pointer ---" << endl;
    s2.setName("Rahul Patil").setMarks(80);
    s2.display();

    cout << "\n--- Friend class adds 10 grace marks to s1 ---" << endl;
    Teacher t;
    t.addGraceMarks(s1, 10);
    s1.display();

    return 0;
}
