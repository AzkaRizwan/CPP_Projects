#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <iomanip>

using namespace std;

/* ---------- Transaction Class ---------- */
class Transaction
{
private:
    static int nextTransactionID;

public:
    int transactionID;
    string type;
    double amount;
    string dateTime;

    Transaction(string t, double a)
    {
        transactionID = ++nextTransactionID;
        type = t;
        amount = a;

        // Record date/time
        time_t now = time(0);
        char *dt = ctime(&now);
        dateTime = string(dt);
        dateTime.pop_back(); // remove newline
    }

    void displayTransaction()
    {
        cout << left << setw(5) << transactionID
             << setw(12) << type
             << setw(10) << fixed << setprecision(2) << amount
             << setw(25) << dateTime << endl;
    }
};
int Transaction::nextTransactionID = 0;

/* ---------- Account Class ---------- */
class Account
{
private:
    static int nextAccountNumber;

public:
    int accountNumber;
    string accountType;
    double balance;
    vector<Transaction> transactions;

    Account(string type, double initialBalance)
    {
        accountNumber = ++nextAccountNumber;
        accountType = type;
        balance = initialBalance;
    }

    void deposit(double amount)
    {
        if (amount <= 0)
        {
            cout << "Invalid deposit amount.\n";
            return;
        }
        balance += amount;
        transactions.push_back(Transaction("Deposit", amount));
        cout << "Deposited successfully.\n";
    }

    void withdraw(double amount)
    {
        if (amount <= 0)
        {
            cout << "Invalid withdrawal amount.\n";
            return;
        }
        if (amount > balance)
        {
            cout << "Insufficient balance.\n";
            return;
        }
        balance -= amount;
        transactions.push_back(Transaction("Withdraw", amount));
        cout << "Withdrawal successful.\n";
    }

    void transfer(Account &receiver, double amount)
    {
        if (amount <= 0)
        {
            cout << "Invalid transfer amount.\n";
            return;
        }
        if (amount > balance)
        {
            cout << "Insufficient balance to transfer.\n";
            return;
        }
        balance -= amount;
        receiver.balance += amount;
        transactions.push_back(Transaction("Transfer Out", amount));
        receiver.transactions.push_back(Transaction("Transfer In", amount));
        cout << "Transfer successful.\n";
    }

    void showBalance()
    {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Type: " << accountType << endl;
        cout << "Current Balance: " << fixed << setprecision(2) << balance << endl;
    }

    void showTransactions()
    {
        if (transactions.empty())
        {
            cout << "No transactions yet.\n";
            return;
        }
        cout << left << setw(5) << "ID"
             << setw(12) << "Type"
             << setw(10) << "Amount"
             << setw(25) << "Date & Time" << endl;
        for (auto &t : transactions)
        {
            t.displayTransaction();
        }
    }
};
int Account::nextAccountNumber = 1000;

/* ---------- Customer Class ---------- */
class Customer
{
private:
    static int nextCustomerID;

public:
    int customerID;
    string name;
    string contact;
    vector<Account> accounts;

    Customer(string n, string c)
    {
        customerID = ++nextCustomerID;
        name = n;
        contact = c;
    }

    void addAccount(string type, double initialBalance)
    {
        accounts.push_back(Account(type, initialBalance));
        cout << "Account created successfully. Account Number: "
             << accounts.back().accountNumber << endl;
    }

    void displayCustomer()
    {
        cout << "Customer ID: " << customerID << endl;
        cout << "Name: " << name << endl;
        cout << "Contact: " << contact << endl;
        cout << "Accounts: " << accounts.size() << endl;
    }

    Account *getAccountByNumber(int accNum)
    {
        for (auto &acc : accounts)
        {
            if (acc.accountNumber == accNum)
                return &acc;
        }
        return nullptr;
    }
};
int Customer::nextCustomerID = 500;

/* ---------- Global Customer Storage ---------- */
vector<Customer> customers;

/* ---------- Helper Functions ---------- */

Customer *findCustomerByID(int customerID)
{
    for (auto &cust : customers)
    {
        if (cust.customerID == customerID)
            return &cust;
    }
    return nullptr;
}

/* ---------- Main Menu Functions ---------- */

void createCustomer()
{
    string name, contact;
    cout << "Enter Customer Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Contact Info: ";
    getline(cin, contact);

    customers.push_back(Customer(name, contact));
    cout << "Customer created successfully. Customer ID: "
         << customers.back().customerID << endl;
}

void createAccount()
{
    int custID;
    string type;
    double balance;

    cout << "Enter Customer ID: ";
    cin >> custID;
    Customer *cust = findCustomerByID(custID);
    if (!cust)
    {
        cout << "Customer not found.\n";
        return;
    }

    cout << "Enter Account Type (Saving/Current): ";
    cin >> type;
    cout << "Enter Initial Balance: ";
    cin >> balance;

    cust->addAccount(type, balance);
}

void depositMoney()
{
    int custID, accNum;
    double amount;

    cout << "Enter Customer ID: ";
    cin >> custID;
    Customer *cust = findCustomerByID(custID);
    if (!cust)
    {
        cout << "Customer not found.\n";
        return;
    }

    cout << "Enter Account Number: ";
    cin >> accNum;
    Account *acc = cust->getAccountByNumber(accNum);
    if (!acc)
    {
        cout << "Account not found.\n";
        return;
    }

    cout << "Enter Amount to Deposit: ";
    cin >> amount;
    acc->deposit(amount);
}

void withdrawMoney()
{
    int custID, accNum;
    double amount;

    cout << "Enter Customer ID: ";
    cin >> custID;
    Customer *cust = findCustomerByID(custID);
    if (!cust)
    {
        cout << "Customer not found.\n";
        return;
    }

    cout << "Enter Account Number: ";
    cin >> accNum;
    Account *acc = cust->getAccountByNumber(accNum);
    if (!acc)
    {
        cout << "Account not found.\n";
        return;
    }

    cout << "Enter Amount to Withdraw: ";
    cin >> amount;
    acc->withdraw(amount);
}

void transferMoney()
{
    int senderID, senderAcc, receiverID, receiverAcc;
    double amount;

    cout << "Enter Sender Customer ID: ";
    cin >> senderID;
    Customer *senderCust = findCustomerByID(senderID);
    if (!senderCust)
    {
        cout << "Sender not found.\n";
        return;
    }

    cout << "Enter Sender Account Number: ";
    cin >> senderAcc;
    Account *sender = senderCust->getAccountByNumber(senderAcc);
    if (!sender)
    {
        cout << "Sender account not found.\n";
        return;
    }

    cout << "Enter Receiver Customer ID: ";
    cin >> receiverID;
    Customer *receiverCust = findCustomerByID(receiverID);
    if (!receiverCust)
    {
        cout << "Receiver not found.\n";
        return;
    }

    cout << "Enter Receiver Account Number: ";
    cin >> receiverAcc;
    Account *receiver = receiverCust->getAccountByNumber(receiverAcc);
    if (!receiver)
    {
        cout << "Receiver account not found.\n";
        return;
    }

    cout << "Enter Amount to Transfer: ";
    cin >> amount;

    sender->transfer(*receiver, amount);
}

void viewBalance()
{
    int custID, accNum;

    cout << "Enter Customer ID: ";
    cin >> custID;
    Customer *cust = findCustomerByID(custID);
    if (!cust)
    {
        cout << "Customer not found.\n";
        return;
    }

    cout << "Enter Account Number: ";
    cin >> accNum;
    Account *acc = cust->getAccountByNumber(accNum);
    if (!acc)
    {
        cout << "Account not found.\n";
        return;
    }

    acc->showBalance();
}

void viewTransactions()
{
    int custID, accNum;

    cout << "Enter Customer ID: ";
    cin >> custID;
    Customer *cust = findCustomerByID(custID);
    if (!cust)
    {
        cout << "Customer not found.\n";
        return;
    }

    cout << "Enter Account Number: ";
    cin >> accNum;
    Account *acc = cust->getAccountByNumber(accNum);
    if (!acc)
    {
        cout << "Account not found.\n";
        return;
    }

    acc->showTransactions();
}

/* ---------- Main Function ---------- */

int main()
{
    int choice;
    do
    {
        cout << "\n===== Banking System Menu =====\n";
        cout << "1. Create Customer\n";
        cout << "2. Create Account\n";
        cout << "3. Deposit\n";
        cout << "4. Withdraw\n";
        cout << "5. Transfer\n";
        cout << "6. View Balance\n";
        cout << "7. View Transactions\n";
        cout << "8. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            createCustomer();
            break;
        case 2:
            createAccount();
            break;
        case 3:
            depositMoney();
            break;
        case 4:
            withdrawMoney();
            break;
        case 5:
            transferMoney();
            break;
        case 6:
            viewBalance();
            break;
        case 7:
            viewTransactions();
            break;
        case 8:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice.\n";
            break;
        }

    } while (choice != 8);

    return 0;
}