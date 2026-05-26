#include <iostream>
#include "MexicanRestaurant.hpp"
#include "JapaneseRestaurant.hpp"
#include "MexicanJapaneseFusion.hpp"

using namespace std;

int main() {
    cout << "Testing Restaurant Inheritance Hierarchy:" << endl;

    MexicanRestaurant lacasa("La Casa", "123 Spice Lane", 4);

    JapaneseRestaurant sakura("Sakura", "456 Sushi Road", true);

    MexicanJapaneseFusion fusion("Fusion Fiesta", "789 Fusion Ave", 3, true);

    lacasa.displayInfo();
    lacasa.describeCuisine();
    sakura.displayInfo();
    sakura.describeCuisine();
    fusion.displayInfo();
    fusion.describeCuisine();
    fusion.displaySpecialty();

    MenuItem tacos("Tacos", 8.99);
    lacasa.addMenuItem(tacos);
    MenuItem enchiladas("Enchiladas", 12.99);
    lacasa.addMenuItem(enchiladas);
    MenuItem sushi("Sushi Roll", 14.99);
    sakura.addMenuItem(sushi);
    MenuItem ramen("Ramen", 11.99);
    sakura.addMenuItem(ramen);
    MenuItem sushi_tacos("Sushi Tacos", 15.99);
    fusion.addMenuItem(sushi_tacos);
    MenuItem wasabi("Wasabi Guacamole", 7.99);
    fusion.addMenuItem(wasabi);

    lacasa.displayMenu();
    sakura.displayMenu();
    fusion.displayMenu();

    

    return 0;
}
