#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

typedef std::string str_t;
using std::cin;
using std::cout;
using std::endl;

class Binops {
    private:
        double opnd1;
        char op;
        double opnd2;
    
    Binops(double opnd1, char op, double opnd2) {
        this->opnd1 = opnd1;
        this->op = op;
        this->opnd2 = opnd2;
    }
};