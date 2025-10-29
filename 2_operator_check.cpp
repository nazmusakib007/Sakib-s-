#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    cout << "Enter expression: ";
    getline(cin, input);

    string operators = "+-*/%=";
    for (char c : input) {
        if (operators.find(c) != string::npos)
            cout << "Operator: " << c << endl;
    }

    return 0;
}
