// Module 1: Headers & Global Constants
#include <iostream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

const string DATABASE_FILE = "users.txt";

// Module 2: Function Prototypes
bool userExists(const string &username);
bool isValidUsername(const string &username);
bool isValidPassword(const string &password);
void registerUser();
void loginUser();
void clearInputBuffer();

// Module 3: Utility Functions
// Clear Input Buffer
void clearInputBuffer()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Username Validation
// Rules:
//     Not empty
//     No spaces

bool isValidUsername(const string &username)
{
    if (username.empty())
        return false;

    for (char ch : username)
    {
        if (isspace(ch))
            return false;
    }

    return true;
}

// Password Validation

//     Rules:
//     Minimum 6 characters
//     No spaces

bool isValidPassword(const string &password)
{
    if (password.length() < 6)
        return false;

    for (char ch : password)
    {
        if (isspace(ch))
            return false;
    }

    return true;
}

// Check if User Already Exists
bool userExists(const string &username)
{
    ifstream file(DATABASE_FILE);

    string storedUsername, storedPassword;

    while (file >> storedUsername >> storedPassword)
    {
        if (storedUsername == username)
        {
            return true;
        }
    }

    return false;
}

// Module 4: Registration Function
void registerUser()
{
    string username, password;

    cout << "\n=== Registration ===\n";

    cout << "Enter username: ";
    cin >> username;

    if (!isValidUsername(username))
    {
        cout << "Error: Invalid username (no spaces, not empty).\n";
        return;
    }

    if (userExists(username))
    {
        cout << "Error: Username already taken.\n";
        return;
    }

    cout << "Enter password: ";
    cin >> password;

    if (!isValidPassword(password))
    {
        cout << "Error: Password must be at least 6 characters and contain no spaces.\n";
        return;
    }

    ofstream file(DATABASE_FILE, ios::app);

    if (!file)
    {
        cout << "Error: Unable to open database file.\n";
        return;
    }

    file << username << " " << password << endl;

    cout << "Registration successful.\n";
}

// Module 5: Login Function
void loginUser()
{
    string username, password;
    bool found = false;

    cout << "\n=== Login ===\n";

    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    ifstream file(DATABASE_FILE);

    if (!file)
    {
        cout << "Error: No users registered yet.\n";
        return;
    }

    string storedUsername, storedPassword;

    while (file >> storedUsername >> storedPassword)
    {
        if (storedUsername == username && storedPassword == password)
        {
            found = true;
            break;
        }
    }

    if (found)
        cout << "Login successful.\n";
    else
        cout << "Invalid username or password.\n";
}

// Module 6: Main Menu System
int main()
{
    int choice;

    while (true)
    {
        cout << "\n===== Login & Registration System =====\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice))
        {
            cout << "Invalid input. Please enter a number.\n";
            clearInputBuffer();
            continue;
        }

        switch (choice)
        {
        case 1:
            registerUser();
            break;

        case 2:
            loginUser();
            break;

        case 3:
            cout << "Exiting program.\n";
            return 0;

        default:
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}