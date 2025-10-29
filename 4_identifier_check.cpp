#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool isIdentifier(const string& s) {
    if (s.empty()) return false;
    if (!isalpha(s[0]) && s[0] != '_') return false;

    for (size_t i = 1; i < s.size(); i++) {
        if (!isalnum(s[i]) && s[i] != '_')
            return false;
    }
    return true;
}

int main() {
    string input;
    cout << "Enter input: ";
    cin >> input;

    if (isIdentifier(input))
        cout << "Valid Identifier" << endl;
    else
        cout << "Invalid Identifier" << endl;

    return 0;
}
