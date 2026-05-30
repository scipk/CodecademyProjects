#include "Restaurant.hpp"
#include "Customer.hpp"
#include "removeElement.hpp"

#include <iostream>

using namespace std;


Restaurant::Restaurant(int initialTableCount) {
  for (int i = 0; i < initialTableCount; i++) {
    tables.push_back(make_unique<Table>(i));
  }
}

bool Restaurant::reserveTable(shared_ptr<Customer>& reservationName) {
  for (unique_ptr<Table>& table : tables) {
    if (table->getIsAvailable()) {
      table->reserve();
      return true;
    }
  }
  waitlist.push_back(reservationName);
  return false;
}

void Restaurant::printWaitlist() {
  cout << "The following people are waiting for a table:" << endl;
  int position = 1;
  for (auto customer : waitlist) {
    shared_ptr<Customer> customerPtr;
    customerPtr = customer.lock();
    cout << position << ". " << customerPtr->getName() << endl;
    position++;
  }
}

void Restaurant::releaseTable(int tableNumber) {
  for (auto& table : tables) {
    if (((table->getNumber()) == tableNumber) && (!table->getIsAvailable())) {
      table->release();
      notifyWaitlist();
      cout << tableNumber << endl;
    }
  }
}

void Restaurant::notifyWaitlist() {
  if (waitlist.empty()) {
    return;
  } else {
    shared_ptr<Customer> customer;
    customer = waitlist[0].lock(); 
    if (customer) {
      reserveTable(customer);
      removeElement(waitlist, customer);
      cout << customer->getName() << " will now be seated at Table ";
    }
  }
}