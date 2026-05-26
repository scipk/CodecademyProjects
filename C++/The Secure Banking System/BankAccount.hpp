#include <string>
#include <iostream>

using namespace std;

class BankAccount {
  private:
    string accountNumber;
    double balance;
  public:
    BankAccount(string actNum, double bal) : accountNumber(actNum), balance(bal) {};
    string getAccountNumber();
    double getBalance();
    void setAccountNumber(string actNum);
    void setBalance(double bal);

    class Transaction {
      public:
        void deposit(BankAccount& account, double amount);
        void withdraw(BankAccount& account, double amount);
    };
    
};

using namespace std;