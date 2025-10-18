#include <iostream>
#include <string>
#include <sstream>
typedef std::string str_t;
using std::cout;
using std::endl;
using std::cin;

struct binop {
    double opnd1;
    char op;
    double opnd2;
};

int main() {
    const int MAX_OPERATIONS = 10;

    binop* binops = new binop[MAX_OPERATIONS] { // Allocate on the heap
    };

    cout << "Your operations are to be entered in the form: opnd1 op opnd2" << endl;
    cout << "For instance, 6 / 2" << endl;

    for(int i = 0; i < MAX_OPERATIONS; i++) {
        cout << "Enter operation at index " << i << ": ";
        str_t line;
        std::getline(cin, line);

        std::stringstream ss(line);

        ss >> binops[i].opnd1;  
        ss >> binops[i].op;     
        ss >> binops[i].opnd2;  

        cout << "\n";
    }

    for(int i = 0; i < MAX_OPERATIONS; i++) {
        cout << binops[i].opnd1 << binops[i].op << binops[i].opnd2 << endl;
    }

    delete[] binops;
    return 0;
}