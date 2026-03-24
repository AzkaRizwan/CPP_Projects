# Login & Registration System (C++)

This project is a console based Login and Registration System developed in C++. It allows users to register with a username and password and securely stores their credentials in a file. The system also provides a login feature that verifies user credentials against stored data.

The program follows a modular design approach, dividing functionality into clearly defined sections including validation, file handling, user authentication, and menu management. User data is stored in a text file named `users.txt`, which acts as a simple database.

---

## Project Structure and Code Organization

The program is divided into logical modules for clarity and maintainability.

### Module 1: Headers and Global Constants

The program includes standard libraries for input and output handling, file operations, string manipulation, and input validation. A global constant `DATABASE_FILE` is defined to store the filename used for saving user credentials.

---

### Module 2: Function Prototypes

All functions are declared before implementation to improve readability and maintain a clean structure. These include:

- userExists
- isValidUsername
- isValidPassword
- registerUser
- loginUser
- clearInputBuffer

---

### Module 3: Utility and Validation Functions

The system includes validation functions to ensure data integrity.

#### Username Validation
- Username must not be empty  
- Username must not contain spaces  

#### Password Validation
- Password must contain at least 6 characters  
- Password must not contain spaces  

Input buffer clearing is handled using `clearInputBuffer()` to prevent invalid input from breaking program flow.

---

### Module 4: Registration System

The registration function performs the following steps:

1. Prompts the user to enter a username  
2. Validates the username format  
3. Checks if the username already exists in the database  
4. Prompts the user to enter a password  
5. Validates password rules  
6. Stores the username and password in `users.txt` using file append mode  

If any validation fails, appropriate error messages are displayed. If successful, the system confirms registration.

---

### Module 5: Login System

The login function verifies user credentials by:

1. Prompting for username and password  
2. Opening the database file  
3. Comparing entered credentials with stored records  
4. Confirming successful login or displaying an error message  

If no users are registered yet, the system informs the user accordingly.

---

### Module 6: Menu Driven Interface

The main function implements a continuous menu driven system with three options:

1. Register  
2. Login  
3. Exit  

The program runs inside a loop until the user selects Exit. Input validation ensures only numeric choices are accepted.

---

## Key Features

- File based credential storage  
- Username uniqueness checking  
- Input validation for both username and password  
- Modular and structured function design  
- Menu driven user interface  
- Clear error and success messages  

---

## Technologies Used

- C++  
- File Handling using fstream  
- Standard Input and Output  
- String manipulation  

---

## How to Run

1. Compile the source file using a C++ compiler such as g++  

   ```cpp
   g++ Login_Registration_System.cpp -o login_system
