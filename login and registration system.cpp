#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool usernameExists(const string& username) {
    ifstream file("users.txt");
    string line;
    while (getline(file, line)) {
        string storedUsername = line.substr(0, line.find(','));
        if (storedUsername == username) {
            return true;
        }
    }
    return false;
}

void registerUser() {
    string username, password;

    cout << "Enter username: ";
    cin >> username;

    if (usernameExists(username)) {
        cout << " Username already exists. Please choose another.\n";
        return;
    }

    cout << "Enter password: ";
    cin >> password;

    ofstream file("users.txt", ios::app);
    file << username << "," << password << endl;

    cout << " Registration successful!\n";
}
void loginUser() {
    string username, password;

    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    ifstream file("users.txt");
    string line;
    while (getline(file, line)) {
        size_t delimiter = line.find(',');
        string storedUsername = line.substr(0, delimiter);
        string storedPassword = line.substr(delimiter + 1);

        if (storedUsername == username && storedPassword == password) {
            cout << "Login successful. Welcome, " << username << "!\n";
            return;
        }
    }

    cout << " Login failed. Invalid username or password.\n";
}
int main() {
    int choice;
    do {
        cout << "\n===== Login & Registration System =====\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
        case 1: registerUser(); break;
        case 2: loginUser(); break;
        case 3: cout << "Goodbye!\n"; break;
        default: cout << "Invalid option!\n";
        }

    } while (choice != 3);

    return 0;
}
