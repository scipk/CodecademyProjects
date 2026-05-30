#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <vector>
#include <memory>
#include "Table.hpp"
#include "Customer.hpp"

using namespace std;


class Restaurant {
private:
  vector<unique_ptr<Table>> tables;
  vector<shared_ptr<Customer>> activeCustomers;
  vector<weak_ptr<Customer>> waitlist;
  void notifyWaitlist();
public:
  Restaurant(int initialTableCount);
  bool reserveTable(shared_ptr<Customer>& reservationName);
  void printWaitlist();
  void releaseTable(int tableNumber);
};

#endif
