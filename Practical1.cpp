#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    int rollNumber;
    string studentName;
    float marks;

public:
    Student() {
        cout <<"Welcome!" << endl;
        cout<<"Constructor invoked - a new Student object is ready."<< endl;
    }
    void getStudentDetails() {
        cout <<"\nEnter Roll Number: ";
        cin>>rollNumber;
        cout<< "Enter Name: ";
        cin>> studentName;
        cout<< "Enter Marks: ";
        cin>>marks;
    }
    void showStudentDetails() {
        cout << "\n--- Student Record ---"<< endl;
        cout<< "Roll Number : "<< rollNumber<< endl;
        cout<<"Name : "<< studentName<< endl;
        cout <<"Marks : "<< marks << endl;
    }
    ~Student() {
        cout<<"\nDestructor invoked -Student object is being destroyed." << endl;
    }
};
int main() {
    Student stud;              
    stud.getStudentDetails();  
    stud.showStudentDetails(); 
    return 0;
}   
