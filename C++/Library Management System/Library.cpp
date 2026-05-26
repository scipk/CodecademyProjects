#include "Library.hpp"
#include "removeElement.hpp"
#include <iostream>

using namespace std;

int Library::totalBorrowedBooks = 0;

void Library::listBooks() {
  for (auto book : bookList) {
    cout << book << endl;
  }
}

void Library::addBook(string title, double bookCost) {
  if ((bookList.size() < 100) && (libraryBudget > bookCost)) {
    bookList.push_back(title);
    libraryBudget -= bookCost;
    cout << title << " added to library." << endl;
  } else if (libraryBudget < bookCost) {
    cout << "The library cannot afford this book!" << endl;
  } else {
    cout << "Library is full!" << endl;
  }
}

bool Library::borrowBook(string title) {
  for (auto book : bookList) {
    if (book == title) {
      removeElement(bookList, book);
      cout << "Book '" << title << "' borrowed!" << endl;
      totalBorrowedBooks++;
      return true;
    }
  }
  cout << "Book not found!" << endl;
  return false;
}

void Library::reserveBook(string title) const {
  bool existsInBookList = std::find(bookList.begin(), bookList.end(), title) != bookList.end();
  bool notInReserved = std::find(reservedBooks.begin(), reservedBooks.end(), title) == reservedBooks.end();

  if (existsInBookList && notInReserved) {
    reservedBooks.push_back(title);
    reservedCount++;
    cout << "Book reserved: " << title << endl;
    cout << "Reserved book count: " << reservedCount << endl;
  } else if (!notInReserved) {
      cout << "That book is already reserved." << endl;   
  } else {
    cout << "Book does not exist in this library." << endl;
  }
}