#include <iostream>
typedef std::string str_t;
using std::cin;
using std::cout;
using std::endl;

class Human
{
public:
    str_t name = "Dummy";
    str_t occupation = "Vacant";
    int age = 0;

    void eat()
    {
        cout << name << " is eating" << endl;
    }
};

class Student
{
public:
    str_t name;
    int age;
    double gpa;

    Student(str_t name, int age, double gpa)
    {
        this->name = name;
        this->age = age;
        this->gpa = gpa;
    }
};

class Pizza
{
public:
    str_t topping1;
    str_t topping2;

    Pizza() {}

    Pizza(str_t topping1)
    {
        this->topping1 = topping1;
    }

    Pizza(str_t topping1, str_t topping2)
    {
        this->topping1 = topping1;
        this->topping2 = topping2;
    }
};

class Stove
{
private:
    int temp = 0;

public:
    int getTemp()
    {
        return temp;
    }

    void setTemp(int temp)
    {
        this->temp = temp;
    }
};

class Animal
{
public:
    bool alive = true;

    void eat()
    {
        cout << "This animal is eating" << endl;
    }
};

class Dog : public Animal
{
public:
    void woof()
    {
        cout << "This dog is woofing" << endl;
    }
};

int main()
{

    Human h1;

    h1.name = "Joe";
    // h1.occupation = "IT Technician";
    h1.age = 90;

    cout << h1.name << endl;
    cout << h1.occupation << endl;

    h1.eat();

    Student s1("Keith", 58, 5.0);

    cout << s1.gpa << endl;

    Pizza p1("Cheese");
    Pizza p2("Mushrooms", "Anchovies");
    Pizza p3;

    cout << "Pizza p1 has topping: " << p1.topping1 << endl;

    Stove stove;

    cout << stove.getTemp() << endl;

    stove.setTemp(50);

    cout << stove.getTemp() << endl;

    Dog dog;

    cout << dog.alive << endl;
    dog.eat();
    dog.woof();

    return 0;
}