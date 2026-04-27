#include <iostream>
using namespace std;

// Class 1: Handles only account data
class BankAccount {
private:
    double balance;

public:
    BankAccount(double b) : balance(b) {}

    double getBalance() {
        return balance;
    }

    void setBalance(double b) {
        balance = b;
    }
};

// Class 2: Handles only transactions
class TransactionService {
public:
    void deposit(BankAccount &acc, double amount) {
        acc.setBalance(acc.getBalance() + amount);
    }

    void withdraw(BankAccount &acc, double amount) {
        if (amount <= acc.getBalance()) {
            acc.setBalance(acc.getBalance() - amount);
        } else {
            cout << "Insufficient balance\n";
        }
    }
};

// Class 3: Handles only printing
class AccountPrinter {
public:
    void printBalance(BankAccount &acc) {
        cout << "Balance: " << acc.getBalance() << endl;
    }
};

// Main function
int main() {
    BankAccount acc(1000);
    TransactionService ts;
    AccountPrinter printer;

    ts.deposit(acc, 500);
    ts.withdraw(acc, 200);

    printer.printBalance(acc);

    return 0;
}