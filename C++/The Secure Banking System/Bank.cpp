#include "Bank.hpp"
#include <iostream>

void Bank::createAccount(string actNum, double initBal)
{
  BankAccount newAccount(actNum, initBal);
  accounts.push_back(newAccount);
  cout << "Account " << actNum << " created with initial balance $" << initBal << endl;
}

BankAccount* Bank::findAccount(string actNum)
{
  for (size_t i = 0; i < accounts.size(); ++i) {
    if (accounts[i].getAccountNumber() == actNum) {
      return &accounts[i];
    }
  }
  cout << "Account " << actNum << " not found." << endl;
  return nullptr;
}

int Bank::transferMoney(string fromActNum, string toActNum, double amount)
{
  BankAccount* fromAccount = findAccount(fromActNum);
  BankAccount* toAccount = findAccount(toActNum);

  if (fromAccount && toAccount) {
    if (fromAccount->getBalance() >= amount) {
      fromAccount->setBalance(fromAccount->getBalance() - amount);
      toAccount->setBalance(toAccount->getBalance() + amount);
      return 1;
    } else {
      return 3;
    }
  } else {
    return 2;
  }
}
