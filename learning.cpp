// BRO CODE LEARNING C++ TUTORIAL

#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
template <typename T, typename U> // add another typename so it accepts different data types

auto max(T x, U y)
{ // compiler deduces what the return type should be
    return (x > y) ? x : y;
}

typedef std::vector<std::pair<std::string, int>> pairlist_t;
typedef std::string str_t;
using integer = int;

void bakePizza();
std::string bakePizza(std::string top1);

void printNum();
void swapByValue(std::string x, std::string y);
void swapByReference(std::string &x, std::string &y);

namespace first
{
    int x = 25;
}
namespace second
{
    int x = 35;
}

int length(std::vector<int> arr)
{ // discrete math!
    if (arr.empty())
    {
        return 0;
    }
    arr.erase(arr.begin());
    return (1 + length(arr));
}

void birthday()
{
    for (int i = 0; i <= 3; i++)
    {
        if (i == 2)
        {
            printf("Happy Birthday dear (name) \n");
            continue;
        }
        std::cout << "Happy Bithday to (name)" << std::endl;
    }
}

int myNum = 10; // global var

struct student
{
    str_t name;
    double gpa;
    bool enrolled;
};

void printStudent(student &student);

enum Numbers
{
    one = 1,
    two = 2
};

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    std::cout << "M and W" << std::endl;
    std::cout << "You" << '\n';
    // Commenting!
    /*
    Hi
    */

    int x;
    std::string name = "Luka";
    std::cout << name << std::endl;
    std::cout << "Hello " << name << std::endl;
    x = 10;
    std::cout << x * 2 << std::endl;
    std::cout << first::x << std::endl;
    std::cout << second::x * 2 << std::endl;

    const double VAT = 0.18;
    std::cout << "Current VAT is at " << VAT << '\n';

    std::cout << x << std::endl;
    using namespace first;
    std::cout << x << std::endl; // If we did not declare x = 10 in main(), this would print 25

    cout << "No STD" << endl;

    pairlist_t pairlist;
    str_t fullName = "Luka Cassar";
    cout << fullName << endl;
    cout << (fullName.empty() ? "String is empty" : "String is not empty") << endl;

    integer age = 18;
    cout << age << endl;

    double pi = (int)3.14; // Implicit Typecast
    cout << pi << endl;

    char c = 49; // prints 1 - Explicit Typecast
    cout << c << endl;

    // cout << "Enter your age" << endl;
    // std::cin >> age;

    // cout << "What is your mother's name?" << endl;
    // std::getline(cin >> std::ws, name); // add >> std::ws to remove the newline character

    cout << name << endl;
    int y;
    x = 50;
    y = 60;

    cout << std::max(x, y) << endl;
    cout << pow(3, 6) << endl; // included cmath for this

    if (std::max(x, y) == x)
    {
        cout << "x is larger but could also be equal" << endl;
    }
    else
    {
        cout << "y is larger but could also be equal" << endl;
    }

    std::max(x, y) == x ? cout << "x is larger but could also be equal" << endl : cout << "y is larger but could also be equal" << endl;
    cout << (std::max(x, y) == x ? "x is larger but could also be equal" : "y is larger but could also be equal") << endl;
    // condition ? true : false

    cout << "Enter the month" << endl;
    int month = 2;
    // cin >> month;

    switch (month)
    {
    case 1:
    case 2:
    case 3:
        cout << "It's Spring!" << endl;
        break;
    case 4:
    case 5:
    case 6:
        cout << "It's Summer!" << endl;
        break;
    case 7:
    case 8:
    case 9:
        cout << "It's Autumn!" << endl;
        break;
    case 10:
    case 11:
    case 12:
        cout << "It's Winter!" << endl;
        break;
    default:
        cout << "Invalid Month!" << endl;
        break; // Optional here
    }
    std::vector<int> arr = {1, 5, 8, 3, 2, 5, 7, 4, 3};
    cout << length(arr) << endl;

    srand(time(NULL));

    int num = (rand() % 6) + 1; // 0-5 but now chooses 1-6
    cout << num << endl;

    birthday();

    str_t yay = "hi";
    cout << yay << " " << name << endl;
    cout << yay + " " + name << endl;

    bakePizza();
    std::cout << bakePizza("pineapple");

    int myNum = 19;
    cout << ::myNum << endl; // :: for the global variable
    cout << myNum << endl;
    printNum();

    std::string women[4];
    women[0] = "Joanne";
    women[1] = "Phyllis";
    women[3] = "Doris";
    std::string men[] = {"Joe", "Jim", "Billy", "Peter", "Herbert", "Sliem"};

    cout << men[1] << endl;
    cout << women[3] << endl;

    cout << "Men array has " << sizeof(men) / sizeof(men[0]) << " elements!" << endl;

    for (int i = 0; i < sizeof(women) / sizeof(women[0]); i++)
    {
        cout << "Woman at index " << i << " is called " << women[i] << endl;
    }

    for (std::string man : men)
    { //  a for each loop
        cout << man << endl;
    }

    std::string foods[10];

    fill(foods, foods + 5, "apple");

    // for (int i = 5; i < 10; i++) {
    //   cout << "Enter food at index #" << i << endl;
    //    std::getline(cin, foods[i]);
    // }

    for (std::string food : foods)
    {
        cout << food << endl;
    }

    int grid[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    for (int i = 0; i < sizeof(grid) / sizeof(grid[0]); i++)
    {
        for (int j = 0; j < sizeof(grid[0]) / sizeof(grid[0][0]); j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "Mem addr of yay " << &yay << endl;

    str_t ax = "Hello";
    str_t bx = "Hi";

    swapByValue(ax, bx);     // pass by value, we're creating copies!
    swapByReference(ax, bx); // pass by reference

    cout << ax << endl;
    cout << bx << endl;

    str_t strink = "Pizza";
    str_t *pStrink = &strink;
    cout << *pStrink << endl; // de referencing the pointer
    cout << pStrink << endl;  // prints the memory address, &strink

    str_t pizzas[] = {"hawaiian", "boneless"};
    str_t *pPizzas = pizzas;
    cout << *pPizzas << endl; // prints the first element of pizzas[]

    int *pointa = nullptr;
    int numb = 123;

    pointa = &numb;

    cout << *pointa << endl;

    // Dynamic Memory
    int *pNum = nullptr;

    pNum = new int;

    *pNum = 23;

    cout << *pNum << endl; // stored in the heap

    delete pNum; // freeing up the memory at this address

    cout << max('B', 3) << endl;

    student student1;
    student1.name = "Pietru";
    student1.gpa = 3.5;
    student1.enrolled = false;

    cout << student1.name << endl;

    printStudent(student1);

    Numbers numbr = two;

    switch (numbr)
    {
    case 1:
        cout << "It's the number 1" << endl;
        break;

    case 2:
        cout << "It's the number 2" << endl;
        break;

    default:
        cout << "Well you'll never reach this case!" << endl;
    }

    return 0;
}

void printStudent(student &student)
{
    std::cout << "Name: " << student.name << std::endl;
    std::cout << "GPA: " << student.gpa << std::endl;
    std::cout << "Enrolled: " << (student.enrolled ? "Yes" : "No") << std::endl;
}
void swapByValue(std::string x, std::string y)
{
    std::string temp;
    temp = x;
    x = y;
    y = temp;
}

void swapByReference(std::string &x, std::string &y)
{
    std::string temp;
    temp = x;
    x = y;
    y = temp;
}

void bakePizza()
{
    std::cout << "Here is your plain pizza!" << std::endl;
}
std::string bakePizza(std::string top1)
{
    return "Here is your pizza with " + top1 + "!\n";
}

void printNum()
{
    std::cout << "myNum called via printNum() " << myNum << std::endl;
}
