#include <iostream>
#include <string>
#include <vector>

class BankAccount {
private:
    std::string accountNumber;
    std::string accountHolder;
    double balance;

public:
    // Constructor to initialize a BankAccount object
    BankAccount(std::string number, std::string holder, double initialBalance = 0.0)
        : accountNumber(number), accountHolder(holder), balance(initialBalance) {}

    // Function to deposit money into the account
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << amount << " USD deposited. New balance: " << balance << " USD" << std::endl;
        } else {
            std::cout << "Invalid amount. Please enter a positive value." << std::endl;
        }
    }

    // Function to withdraw money from the account
    bool withdraw(double amount) {
        if (amount > 0 && balance >= amount) {
            balance -= amount;
            std::cout << amount << " USD withdrawn. New balance: " << balance << " USD" << std::endl;
            return true;
        } else if (amount <= 0) {
            std::cout << "Invalid amount. Please enter a positive value." << std::endl;
            return false;
        } else {
            std::cout << "Insufficient balance." << std::endl;
            return false;
        }
    }

    // Function to display the account balance
    void displayBalance() const {
        std::cout << "Account Number: " << accountNumber << std::endl;
        std::cout << "Account Holder: " << accountHolder << std::endl;
        std::cout << "Current Balance: " << balance << " USD" << std::endl;
    }

    // Getter function for the account number
    std::string getAccountNumber() const {
        return accountNumber;
    }
};

int main() {
    std::vector<BankAccount> accounts;

    while (true) {
        std::cout << "\nBank Account Simulation" << std::endl;
        std::cout << "1. Create Account" << std::endl;
        std::cout << "2. Deposit" << std::endl;
        std::cout << "3. Withdraw" << std::endl;
        std::cout << "4. Display Balance" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string number, holder;
                double initial;
                std::cout << "Account Number: ";
                std::cin >> number;
                std::cout << "Account Holder: ";
                std::cin >> holder;
                std::cout << "Initial Balance: ";
                std::cin >> initial;
                accounts.push_back(BankAccount(number, holder, initial));
                std::cout << "Account created." << std::endl;
                break;
            }
            case 2: {
                std::string number;
                double amount;
                std::cout << "Enter the account number to deposit into: ";
                std::cin >> number;
                std::cout << "Enter the amount to deposit: ";
                std::cin >> amount;
                for (BankAccount& account : accounts) {
                    if (account.getAccountNumber() == number) {
                        account.deposit(amount);
                        goto deposit_continue; // Simple exit using goto
                    }
                }
                std::cout << "Account not found." << std::endl;
                deposit_continue:;
                break;
            }
            case 3: {
                std::string number;
                double amount;
                std::cout << "Enter the account number to withdraw from: ";
                std::cin >> number;
                std::cout << "Enter the amount to withdraw: ";
                std::cin >> amount;
                for (BankAccount& account : accounts) {
                    if (account.getAccountNumber() == number) {
                        account.withdraw(amount);
                        goto withdraw_continue; // Simple exit using goto
                    }
                }
                std::cout << "Account not found." << std::endl;
                withdraw_continue:;
                break;
            }
            case 4: {
                std::string number;
                std::cout << "Enter the account number to view balance: ";
                std::cin >> number;
                for (const BankAccount& account : accounts) {
                    if (account.getAccountNumber() == number) {
                        account.displayBalance();
                        goto display_continue; // Simple exit using goto
                    }
                }
                std::cout << "Account not found." << std::endl;
                display_continue:;
                break;
            }
            case 5: {
                std::cout << "Exiting..." << std::endl;
                return 0;
            }
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}
