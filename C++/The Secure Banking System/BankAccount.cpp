#include "BankAccount.hpp"

string BankAccount::getAccountNumber()
{
  return accountNumber;
}

double BankAccount::getBalance()
{
  return balance;
}

void BankAccount::setAccountNumber(string actNum)
{
  accountNumber = actNum;
  cout << "Account number updated to: " << accountNumber << endl;
}

void BankAccount::setBalance(double bal)
{
  balance = bal;
  cout << "Balance updated to: $" << balance << endl;
}

void BankAccount::Transaction::deposit(BankAccount &account, double amount)
{
  account.setBalance(account.getBalance() + amount);
  cout << "Deposited $" << amount << " to account " << account.getAccountNumber() << endl;
}

void BankAccount::Transaction::withdraw(BankAccount &account, double amount)
{
  account.setBalance(account.getBalance() - amount);
  cout << "Withdrew $" << amount << " from account " << account.getAccountNumber() << endl;
}
