#include <iostream>
#include <string>
using namespace std;

bool isUppercasePresent(const string& password) {
    for (char c : password) {
        if (isupper(c)) return true;
    }
    return false;
}

bool isLowercasePresent(const string& password) {
    for (char c : password) {
        if (islower(c)) return true;
    }
    return false;
}

bool isDigitPresent(const string& password) {
    for (char c : password) {
        if (isdigit(c)) return true;
    }
    return false;
}

bool isSpecialCharacterPresent(const string& password) {
    for (char c : password) {
        if (!isalnum(c)) return true;
    }
    return false;
}

int main() {
    string password;
    bool validPassword;
    char choice;
    do {
        do {
            cout << "Enter a password: ";
            cin >> password;

            validPassword = true;

            // Check length
            if (password.length() < 8) {
                cout << "- Password should be at least 8 characters long." << endl;
                validPassword = false;
            }

            // Check presence of uppercase, lowercase, digit, and special characters
            if (!isUppercasePresent(password)) {
                cout << "- Password should contain at least one uppercase letter." << endl;
                validPassword = false;
            }
            if (!isLowercasePresent(password)) {
                cout << "- Password should contain at least one lowercase letter." << endl;
                validPassword = false;
            }
            if (!isDigitPresent(password)) {
                cout << "- Password should contain at least one digit." << endl;
                validPassword = false;
            }
            if (!isSpecialCharacterPresent(password)) {
                cout << "- Password should contain at least one special character." << endl;
                validPassword = false;
            }

            if (!validPassword) {
                cout << "\tPlease choose a stronger password.\n" << endl;
            }
            else {
                cout << "\tPassword is strong. Good job!" << endl;
            }
        } while (!validPassword);
        // Prompt user if they want to check another password
        cout << "\nDo you want to check another password? (Y/N): ";
        cin >> choice;
        cout <<endl;

    } while (choice == 'y' || choice == 'Y');


    return 0;
}
