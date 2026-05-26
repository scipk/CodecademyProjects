#ifndef PET_HPP
#define PET_HPP

#include <string>
using namespace std;

class Pet {
  private:
    string name;
    int age;
  public:
    string getName();
    int getAge();
    void setName(string newName) {name = newName;};
    void setAge(int newAge) {age = newAge;};
    virtual void makeSound() = 0;
};

#endif
