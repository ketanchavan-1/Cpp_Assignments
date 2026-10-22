#include <iostream>
using namespace std;

// Base class
class Animal {
public:
    void eat() { cout << "Animal eats food" << endl; }
};

// 1. Single inheritance: Animal -> Dog
class Dog : public Animal {
public:
    void bark() { cout << "Dog barks" << endl; }
};

// 2. Multilevel inheritance: Animal -> Dog -> Puppy
class Puppy : public Dog {
public:
    void weep() { cout << "Puppy weeps" << endl; }
};

// 3. Hierarchical inheritance: Animal -> Dog and Animal -> Cat
class Cat : public Animal {
public:
    void meow() { cout << "Cat meows" << endl; }
};

// 4. Multiple inheritance: Father, Mother -> Child
class Father {
public:
    void fatherSkill() { cout << "Father plays cricket" << endl; }
};
class Mother {
public:
    void motherSkill() { cout << "Mother sings" << endl; }
};
class Child : public Father, public Mother {
public:
    void childSkill() { cout << "Child draws" << endl; }
};

// 5. Hybrid inheritance: Person -> Student, Employee -> Intern
class Person {
public:
    void showPerson() { cout << "Person has a name" << endl; }
};
class Student : virtual public Person {
public:
    void showStudent() { cout << "Student studies" << endl; }
};
class Employee : virtual public Person {
public:
    void showEmployee() { cout << "Employee works" << endl; }
};
class Intern : public Student, public Employee {
public:
    void showIntern() { cout << "Intern studies and works" << endl; }
};

int main() {
    cout << "--- Single Inheritance ---" << endl;
    Dog d;
    d.eat();
    d.bark();

    cout << "\n--- Multilevel Inheritance ---" << endl;
    Puppy p;
    p.eat();
    p.bark();
    p.weep();

    cout << "\n--- Hierarchical Inheritance ---" << endl;
    Cat c;
    c.eat();
    c.meow();

    cout << "\n--- Multiple Inheritance ---" << endl;
    Child ch;
    ch.fatherSkill();
    ch.motherSkill();
    ch.childSkill();

    cout << "\n--- Hybrid Inheritance ---" << endl;
    Intern i;
    i.showPerson();
    i.showStudent();
    i.showEmployee();
    i.showIntern();

    return 0;
}
