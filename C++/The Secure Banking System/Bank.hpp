#include <vector>
#include "BankAccount.hpp"

class Bank {
  private:
    vector<BankAccount> accounts;
  public:
    void createAccount(string actNum, double initBal);
    BankAccount* findAccount(string actNum);
    int transferMoney(string fromActNum, string toActNum, double amount);
};