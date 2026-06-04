#include "RestaurantIO.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <limits>

using namespace std;

void addRestaurant(vector<Restaurant>& database) {
  int restaurantId, menuItemCount;
  string restaurantName, cuisineType, itemName;
  double itemPrice;

  cout << "Enter restaurant ID: ";
  cin >> restaurantId;
  if (cin.fail()) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Invalid restaurant ID.\n";
    return;
  }
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  cout << "Enter restaurant name: ";
  getline(cin, restaurantName);
  cout << "Enter cuisine type: ";
  getline(cin, cuisineType);

  Restaurant restaurant(restaurantId, restaurantName, cuisineType);

  cout << "Enter the number of menu items: ";
  cin >> menuItemCount;
  if (cin.fail()) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Invalid number.\n";
    return;
  }
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  for (int i = 0; i < menuItemCount; i++) {
    stringstream itemEntryStream;
    itemEntryStream << fixed << setprecision(2);

    cout << "Enter item " << i << " name: ";
    getline(cin, itemName);
    if (cin.fail()) {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Invalid item name.\n";
      return;
    }

    cout << "Enter item " << i << " price: ";
    cin >> itemPrice;
    if (cin.fail()) {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Invalid item price.\n";
      return;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    itemEntryStream << itemName << " - $" << itemPrice;
    restaurant.addMenuItem(itemEntryStream.str());
  }

  database.push_back(restaurant);
}

void displayRestaurants(const vector<Restaurant>& database) {
  for (const auto& restaurant : database) {
    cout << "\nID: " << restaurant.getId()
         << "\nName: " << restaurant.getName()
         << "\nCuisine: " << restaurant.getCuisine()
         << "\nMenu:\n";

    for (const auto& menuItemEntry : restaurant.getMenu()) {
      cout << "  - " << menuItemEntry << '\n';
    }
  }
}

bool loadDatabase(vector<Restaurant>& database, const string& filename) {
  ifstream inputFile(filename);
  if (!inputFile) {
    cout << "[WARN] Could not open " << filename << " for reading." << endl;
    return false;
  }

  Restaurant restaurant;

  while (inputFile >> restaurant) {
    database.push_back(restaurant);
  }
  return true;
}

void saveDatabase(const vector<Restaurant>& database, const string& filename) {
  ofstream outputFile(filename);
  if (!outputFile) {
    cout << "[ERR] Could not open " << filename << " for writing." << endl;
    return;
  }

  for (const auto& restaurant : database) {
    outputFile << restaurant << endl;
  }
  outputFile.close();
}
