#include <vector>
#include <string>
#include <algorithm>

using namespace std;

extern double libraryBudget;

class Library {
  private:
    vector<string> bookList;
    static int totalBorrowedBooks;
    mutable int reservedCount;
    mutable vector<string> reservedBooks;
  public:
    Library() : reservedCount(0) {};
    void addBook(string title, double bookCost);
    bool borrowBook(string title);
    void listBooks();
    int getTotalBorrowedBooks() {return totalBorrowedBooks;};
    void reserveBook(string title) const;
};