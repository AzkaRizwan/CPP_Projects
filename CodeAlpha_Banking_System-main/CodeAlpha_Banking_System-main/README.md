# Banking System (C++)

This project is a console based Banking System developed in C++ using object oriented programming principles. It simulates basic banking operations including customer management, account handling, deposits, withdrawals, transfers, and transaction history tracking.

The system is designed with multiple interacting classes to model real world banking entities such as Customers, Accounts, and Transactions. It demonstrates strong understanding of OOP concepts including encapsulation, class relationships, static members, and dynamic data management using vectors.

---

## Overview

The Banking System allows users to:

- Create new customers  
- Create multiple accounts for a customer  
- Deposit money into an account  
- Withdraw money with balance validation  
- Transfer funds between accounts  
- View account balance  
- View detailed transaction history  

Each operation is handled through a structured menu driven interface.

---

## System Design and Architecture

The system is built using three main classes:

### Transaction Class

The Transaction class records individual financial activities. Each transaction contains:

- Unique transaction ID generated automatically  
- Transaction type such as Deposit, Withdraw, Transfer In, Transfer Out  
- Transaction amount  
- Date and time of the transaction  

Static members are used to ensure unique transaction IDs. Date and time are captured automatically at the moment the transaction is created.

---

### Account Class

The Account class represents a bank account. Each account includes:

- Unique account number generated automatically  
- Account type such as Saving or Current  
- Current balance  
- List of transactions  

The Account class provides methods to:

- Deposit funds with validation  
- Withdraw funds with insufficient balance checking  
- Transfer funds to another account  
- Display account balance  
- Display transaction history  

All transactions are recorded and stored in a vector, allowing dynamic growth of transaction history.

---

### Customer Class

The Customer class represents a bank customer and contains:

- Unique customer ID generated automatically  
- Customer name  
- Contact information  
- List of accounts  

A customer can own multiple accounts. The system provides functionality to retrieve accounts using account numbers.

---

## Data Management

Customers are stored in a global vector, allowing the system to dynamically manage multiple users during program execution. Helper functions are used to locate customers and accounts safely before performing any financial operation.

All operations validate:

- Customer existence  
- Account existence  
- Positive transaction amounts  
- Sufficient balance before withdrawal or transfer  

This prevents invalid state changes and maintains system integrity.

---

## Key Features

- Object oriented architecture  
- Automatic unique ID generation using static variables  
- Support for multiple customers and multiple accounts per customer  
- Deposit, withdrawal, and transfer operations  
- Transaction history tracking with timestamps  
- Input validation and error handling  
- Menu driven user interface  

---

## Technologies Used

- C++  
- Standard Template Library STL  
- Vectors for dynamic storage  
- Time handling using ctime  
- Formatted output using iomanip  

---

## Program Flow

1. User selects an option from the main menu  
2. System performs validation checks  
3. Requested operation is executed  
4. Transaction is recorded if applicable  
5. Menu reappears until user exits  

---

## Concepts Demonstrated

- Object oriented programming  
- Encapsulation and class design  
- Static data members  
- Dynamic memory handling with vectors  
- Input validation  
- Structured menu driven application design  
- Basic financial transaction logic  

---

## Why This Implementation Is Professional

- Clear separation of responsibilities between classes  
- Realistic modeling of banking entities  
- Proper validation before every financial operation  
- Unique ID management using static variables  
- Clean and readable console output  
- Expandable architecture for future improvements  

---

This project demonstrates practical implementation of object oriented design and financial transaction handling in C++, forming a strong foundation for building more advanced banking or financial management systems.
