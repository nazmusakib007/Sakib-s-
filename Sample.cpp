/*#include <iostream>
using namespace std;

int main() {
    string input;
    cout << "Enter an input: ";
    cin >> input;


    if (!(isalpha(input[0]) || input[0] == '_')) {
        cout << "Not a valid identifier." << endl;
        return 0;
    }

    for (int i = 1; i < input.length(); i++) {
        if (!(isalnum(input[i]) || input[i] == '_')) {
            cout << "Not a valid identifier." << endl;
            return 0;
        }
    }

    cout << "valid identifier" << endl;
    return 0;
}*/


#include <iostream>
#include <fstream>
#include <string>

using namespace std;


void isIdentifier(string apolo)
{

    for (int i = 0; apolo[i] != '\0'; i++) {
        if (apolo[i] == ' ') {
            cout << "\"" << apolo << "\" is not a valid identifier (contains space)" << endl;
            return;
        }
    }


    if (!((apolo[0] >= 'A' && apolo[0] <= 'Z') ||
          (apolo[0] >= 'a' && apolo[0] <= 'z') ||
           apolo[0] == '_')) {
        cout << "\"" << apolo << "\" is not a valid identifier (invalid first character)" << endl;
        return;
    }


    for (int i = 1; apolo[i] != '\0'; i++) {
        if (!((apolo[i] >= 'A' && apolo[i] <= 'Z') ||
              (apolo[i] >= 'a' && apolo[i] <= 'z') ||
              (apolo[i] >= '0' && apolo[i] <= '9') ||
               apolo[i] == '_')) {
            cout << "\"" << apolo << "\" is not a valid identifier (invalid character)" << endl;
            return;
        }
    }


    cout << "\"" << apolo << "\" is a valid identifier" << endl;
}

int main()
{
    string filename;


    cout << "Please enter the name of the file to check : ";
    cin >> filename;

    ifstream file(filename);
    string apolo;


    if (!file) {
        cout << "File \"" << filename << "\" not found or unable to open!" << endl;
        return 0;
    }


    while (getline(file, apolo)) {
        cout << "Reading from file: \"" << apolo << "\"" << endl;
        isIdentifier(apolo);
    }


    file.close();
    return 0;
}


