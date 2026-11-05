#include "../include/Menu.h"
#include "../include/FoodItem.h"
#include "../include/CSVParser.h"
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<FoodItem> donations = loadCSV("resources/food_expiration_with_quantity.csv");

    cout << "Loaded " << donations.size() << " donations." << endl;

    if (donations.empty()) {
        cerr << "Error: No donations were loaded!" << endl;
        return 1;
    }


    Menu menu;
    menu.run(donations);

    return 0;
}