#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <exception>
#include <stdexcept>

typedef std::string str_t;
using std::cin;
using std::cout;
using std::endl;

const int MAX_OPERATIONS = 3;
std::ofstream filetxt;

class Binops
{
private:
    double opnd1;
    char op;
    double opnd2;

public:
    Binops() {}
    Binops(double opnd1, char op, double opnd2) // not used, since we wrote this, we had to write the default constructor - it wasn't given for "free" now
        : opnd1(opnd1), op(op), opnd2(opnd2)
    {
    }

    double getOpnd1() const { return opnd1; }
    char getOp() const { return op; }
    double getOpnd2() const { return opnd2; }

    void setOpnd1(double v) { opnd1 = v; }
    void setOp(char c) { op = c; }
    void setOpnd2(double v) { opnd2 = v; }

    double evaluate() const
    {
        double result = 0.0;
        switch (op)
        {
        case '+':
            result = opnd1 + opnd2;
            break;
        case '-':
            result = opnd1 - opnd2;
            break;
        case '*':
            result = opnd1 * opnd2;
            break;
        case '/':
            result = opnd1 / opnd2;
            break;
        default:
            result = 0.0;
            break;
        }
        return result;
    }
};

int main()
{
    Binops *binops = new Binops[MAX_OPERATIONS];

    cout << "Your operations are to be entered in the form: opnd1 op opnd2" << endl;
    cout << "For instance, 6 / 2" << endl;

    for (int i = 0; i < MAX_OPERATIONS; i++)
    {
        while (true) // Keep looping until we get valid input for index i
        {
            cout << "Enter operation at index " << i << ": ";
            str_t line;
            std::getline(cin, line);

            std::stringstream ss(line);

            double temp_opnd1, temp_opnd2;
            char temp_op;

            if (!(ss >> temp_opnd1 >> temp_op >> temp_opnd2))
            {
                cout << "Error: Invalid format. Please use 'number op number'." << endl;
                continue; // Go back to the start of the while(true) loop
            }
            char junk;
            if (ss >> junk)
            {
                cout << "Error: Trailing characters found. Please use 'number op number' only." << endl;
                continue; // Go back to the start of the while(true) loop
            }
            if (temp_op != '+' && temp_op != '-' && temp_op != '*' && temp_op != '/')
            {
                cout << "Error: Invalid operation. Please ensure your operation is one of the following: + - * /" << endl;
                continue; // go back!
            }

            // Reaching here indicates the input is clean
            binops[i].setOpnd1(temp_opnd1);
            binops[i].setOp(temp_op);
            binops[i].setOpnd2(temp_opnd2);

            cout << "\n";
            break;
        }
    }

    filetxt.open("resultsOOP.txt");
    if (!filetxt.is_open())
    {
        throw std::runtime_error("Failed to open file for writing.");
        return 1;
    }

    for (int i = 0; i < MAX_OPERATIONS; i++)
    {
        char currentOp = binops[i].getOp();

        double result = binops[i].evaluate();
        if (result == -0.0)
        {
            result = 0.0;
        }

        filetxt << binops[i].getOpnd1() << " "
                << binops[i].getOp() << " "
                << binops[i].getOpnd2() << " -> "
                << result << endl;
    }
    filetxt.close();
    delete[] binops;
    return 0;
}