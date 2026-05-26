#include "JapaneseRestaurant.hpp"
#include <iostream>

void JapaneseRestaurant::describeCuisine(){
  if (hasTatami == true){
    cout << "Traditional Japanese cuisine with tatami seating available" << endl;
  } else {
    cout << "Traditional Japanese cuisine" << endl;
  }
};