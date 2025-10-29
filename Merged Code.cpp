#include <iostream>
#include <string>
#include <cctype>
using namespace std;

//  Function 1: Check Numeric Constant 
void checkNumeric() {
    string input;
    cout << "Enter input: ";
    cin >> input;

    bool isNumeric = true;
    for (char c : input) {
        if (!isdigit(c)) {
            isNumeric = false;
            break;
        }
    }

    if (isNumeric)
        cout << "Numeric constant" << endl;
    else
        cout << "Not numeric" << endl;
}

// Function 2: Check Operators 
void checkOperator() {
    string input;
    cout << "Enter expression: ";
    cin.ignore();
    getline(cin, input);

    string operators = "+-*/%=";
    for (char c : input) {
        if (operators.find(c) != string::npos)
            cout << "Operator: " << c << endl;
    }
}

// Function 3: Check Comments 
void checkComment() {
    string input;
    cout << "Enter a line: ";
    cin.ignore();
    getline(cin, input);

    if (input.substr(0, 2) == "//")
        cout << "Single line comment" << endl;
    else if (input.substr(0, 2) == "/*" && input.size() >= 4 &&
             input.substr(input.size() - 2) == "*/")
        cout << "Multi-line comment" << endl;
    else
        cout << "Not a comment line" << endl;
}

// Function 4: Check Identifier 
bool isIdentifier(const string& s) {
    if (s.empty()) return false;
    if (!isalpha(s[0]) && s[0] != '_') return false;

    for (size_t i = 1; i < s.size(); i++) {
        if (!isalnum(s[i]) && s[i] != '_')
            return false;
    }
    return true;
}

void checkIdentifier() {
    string input;
    cout << "Enter input: ";
    cin >> input;

    if (isIdentifier(input))
        cout << "Valid Identifier" << endl;
    else
        cout << "Invalid Identifier" << endl;
}

//  Function 5: Average of Array 
void arrayAverage() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    int sum = 0;
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    double avg = (double)sum / n;
    cout << "Average = " << avg << endl;
}

// Function 6: Min and Max of Array 
void minMaxArray() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int minVal = arr[0], maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < minVal) minVal = arr[i];
        if (arr[i] > maxVal) maxVal = arr[i];
    }

    cout << "Minimum = " << minVal << endl;
    cout << "Maximum = " << maxVal << endl;
}

// Function 7: Full Name 
void fullName() {
    string first, last;
    cout << "Enter first name: ";
    cin >> first;
    cout << "Enter last name: ";
    cin >> last;

    string fullName = first + " " + last;
    cout << "Full name: " << fullName << endl;
}

// Main Code
int main() {
    int choice;
    do {
        cout << "\n========= CD LAB TASKS =========\n\n";
        cout << "1. Check Numeric Constant\n";
        cout << "2. Check Operator\n";
        cout << "3. Check Comment Line\n";
        cout << "4. Check Identifier\n";
        cout << "5. Find Array Average\n";
        cout << "6. Find Min and Max in Array\n";
        cout << "7. Concatenate Full Name\n";
        cout << "0. Exit\n\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1: checkNumeric(); break;
            case 2: checkOperator(); break;
            case 3: checkComment(); break;
            case 4: checkIdentifier(); break;
            case 5: arrayAverage(); break;
            case 6: minMaxArray(); break;
            case 7: fullName(); break;
            case 0: cout << "Exiting program..." << endl; break;
            default: cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
