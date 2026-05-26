#include <iostream>
#include "Bank.hpp"

using namespace std;

int main() {

  Bank myBank;

  myBank.createAccount("1001", 5000);
  myBank.createAccount("1002", 3000);
  myBank.createAccount("1003", 2000);

  BankAccount* account1 = myBank.findAccount("1001");
  BankAccount* account2 = myBank.findAccount("1002");
  BankAccount* account3 = myBank.findAccount("1003");

  BankAccount::Transaction transaction;
  transaction.deposit(*account1, 1500);
  transaction.withdraw(*account2, 500);
  
  int result = myBank.transferMoney("1001", "1002", 1000);

  if (result == 1) {
    cout << "Transfer successful." << endl;
  } else if (result == 2) {
    cout << "Error: One or both of the accounts involved in the transfer were not found.." << endl;
  } else if (result == 3) {
    cout << "Error: There are insufficient funds in the source account for the transfer." << endl;
  }

  

  return 0;
}
