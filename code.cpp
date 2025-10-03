#include <iostream>

using namespace std;

struct MyClass{

private:

string field1;

int field2;

public:

// Default constructor

MyClass();

// Destructor

~MyClass();

string getField1();

int getField2();

void setField1(string field1);

void setField2(int field2);

};

MyClass::MyClass() {

field1 = "Default";

field2 = 0;

cout << "Default constructor called" << endl;

}

MyClass::~MyClass() {

cout << "Destructor called" << endl;

}

string MyClass::getField1() {

return field1;

}

int MyClass::getField2() {

return field2;

}

void MyClass::setField1(string field1) {

this->field1 = field1;

}

void MyClass::setField2(int field2) {

this->field2 = field2;

}

int main(int, char**){

MyClass obj1;//Stack

MyClass* obj2;//Heap

cout << "Struct field values: field1: " << obj1.getField1() << ", field2: " << obj1.getField2() << endl;

obj2 = new MyClass();

cout << "Struct field values: field1: " << obj2 -> getField1() << ", field2: " << obj2 -> getField2() << endl;

delete obj2;//Free allocated memory

return 0;

}

