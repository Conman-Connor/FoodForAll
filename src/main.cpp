#include "Menu.h"
#include "FoodItem.h"
#include <vector>
using namespace std;
int main()
{
    vector<FoodItem> donations;
    Menu menu;
    menu.run(donations);

    return 0;
}