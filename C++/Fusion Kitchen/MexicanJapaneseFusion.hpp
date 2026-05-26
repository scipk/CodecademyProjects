#ifndef MEXICAN_JAPANESE_FUSION_HPP
#define MEXICAN_JAPANESE_FUSION_HPP

#include "MexicanRestaurant.hpp"
#include "JapaneseRestaurant.hpp"
#include "Restaurant.hpp"

class MexicanJapaneseFusion : public MexicanRestaurant, public JapaneseRestaurant {
  public:
    MexicanJapaneseFusion(string n, string addy, int spceLvl, bool tatami) : MexicanRestaurant(n, addy, spceLvl), JapaneseRestaurant(n, addy, tatami), Restaurant(n, addy) {};
    void describeCuisine();
    void displaySpecialty();
};

#endif