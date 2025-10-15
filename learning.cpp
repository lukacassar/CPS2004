// BRO CODE LEARNING C++ TUTORIAL

#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>

typedef std::vector<std::pair<std::string, int>> pairlist_t;
typedef std::string str_t;
using integer = int;

void bakePizza();
std::string bakePizza(std::string top1);


namespace first{
    int x = 25;
}
namespace second{
    int x = 35;
}

int length(std::vector<int> arr) { // discrete math!
    if (arr.empty()) {
        return 0;
    }
    arr.erase(arr.begin());
    return (1 + length(arr));
}

void birthday() {
    for (int i = 0; i <= 3; i++) {
        if(i == 2) {
            printf("Happy Birthday dear (name) \n");
            continue;
        }
        std::cout << "Happy Bithday to (name)" << std::endl;
    }
}

int main(){
    using std::cout;
    using std::endl;
    using std::cin;
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

    double pi = (int) 3.14; // Implicit Typecast
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

    cout << std::max(x,y) << endl;
    cout << pow(3,6) << endl; // included cmath for this

    if (std::max(x,y) == x) {
        cout << "x is larger but could also be equal" << endl;
    } else {
        cout << "y is larger but could also be equal" << endl;
    }

    std::max(x,y) == x ? cout << "x is larger but could also be equal" << endl : cout << "y is larger but could also be equal" << endl;
    cout << (std::max(x,y) == x ? "x is larger but could also be equal" : "y is larger but could also be equal") << endl;
    // condition ? true : false
    
    cout << "Enter the month" << endl;
    int month = 2; 
    // cin >> month;

    switch(month) {
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
    std::vector<int> arr = {1,5,8,3,2,5,7,4,3};
    cout << length(arr) << endl;

    srand(time(NULL));

    int num = (rand() % 6) + 1;
    cout << num << endl;
    
    birthday();

    str_t yay = "hi";
    cout << yay << " " << name << endl;
    cout << yay + " " + name << endl;

    bakePizza();
    std::cout << bakePizza("pineapple") << std::endl;

    return 0;

}

void bakePizza() {
    std::cout << "Here is your plain pizza!" << std::endl;
}
std::string bakePizza(std::string top1) {
    return "Here is your pizza with " + top1 + "!\n";
}

