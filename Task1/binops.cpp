#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

typedef std::string str_t;
using std::cin;
using std::cout;
using std::endl;

struct binop
{
    double opnd1;
    char op;
    double opnd2;
};

int main()
{
    const int MAX_OPERATIONS = 3;

    std::ofstream filetxt;

    binop *binops = new binop[MAX_OPERATIONS]{
        // Allocate on the heap
    };

    cout << "Your operations are to be entered in the form: opnd1 op opnd2" << endl;
    cout << "For instance, 6 / 2" << endl;

    for (int i = 0; i < MAX_OPERATIONS; i++)
    {
        cout << "Enter operation at index " << i << ": ";
        str_t line;
        std::getline(cin, line);

        std::stringstream ss(line);

        ss >> binops[i].opnd1;
        ss >> binops[i].op;
        ss >> binops[i].opnd2;

        cout << "\n";
    }

    for (int i = 0; i < MAX_OPERATIONS; i++)
    { // PRINTER
        cout << binops[i].opnd1 << binops[i].op << binops[i].opnd2 << endl;
    }

    filetxt.open("results.txt");
    if (!filetxt.is_open())
    {
        std::cerr << "File failed to open. Terminating program... " << endl;
        return 1;
    }
    else
    {
        double result = 0.0;
        for (int i = 0; i < MAX_OPERATIONS; i++)
        {
            double result = 0.0;
            bool valid_op = true;

            switch (binops[i].op)
            {
            case '+':
                result = binops[i].opnd1 + binops[i].opnd2;
                break;

            case '-':
                result = binops[i].opnd1 - binops[i].opnd2;
                break;

            case '*':
                result = binops[i].opnd1 * binops[i].opnd2;
                break;

            case '/':
                if (binops[i].opnd2 == 0)
                {
                    filetxt << binops[i].opnd1 << " " << binops[i].op << " " << binops[i].opnd2 << " -> undefined" << endl;
                    valid_op = false; // Mark this operation as "handled"
                }
                else
                {
                    result = binops[i].opnd1 / binops[i].opnd2;
                }
                break;

            default:
                cout << "Invalid operator " << binops[i].op << " at index " << i << endl;
                valid_op = false;
                break;
            }

            // Only write if valid (true)
            if (valid_op)
            {
                filetxt << binops[i].opnd1 << " " << binops[i].op << " " << binops[i].opnd2 << " -> " << result << endl;
            }
        }

        filetxt.close();
    }

    delete[] binops;
    return 0;
}