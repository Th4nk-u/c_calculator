#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    string input;
    float num1, num2;
    char op;

    cout << "Enter an arithmetic equation: ";
    getline(cin, input);

    stringstream ss(input);
    ss >> num1 >> op >> num2;

    switch (op)
    {
    case '+':
        cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;
        break;

    case '-':
        cout << num1 << " - " << num2 << " = " << num1 - num2 << endl;
        break;

    case '*':
        cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;
        break;

    case '/':
        if (num2 == 0)
        {
            cout << "Error: Cannot divide by zero!" << endl;
        }
        else
        {
            cout << num1 << " / " << num2 << " = " << num1 / num2 << endl;
        }
        break;

    default:
        cout << "Error: Invalid operator!" << endl;
        break;
    }

    return 0;
}
