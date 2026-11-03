#include "FoodItem.h"
using namespace std;

FoodItem::FoodItem() {
    name = "";
    storageCondition = "";
    temperature = 0.0;
    humidity = 0;
    packaging = "";
    purchaseDate = "";
    expiryDays = 0;
    quantity = 0;
    expirationDate = "";
    pickupDeadline = "";
}
FoodItem::FoodItem(string n, string storage, double temp,
                   int humid, string pack, string purchase,
                   int days, int q, string exp, string pickup) {

    name = n;
    storageCondition = storage;
    temperature = temp;
    humidity = humid;
    packaging = pack;
    purchaseDate = purchase;
    expiryDays = days;
    quantity = q;
    expirationDate = exp;
    pickupDeadline = pickup;
}

int compareDates(const string& a, const string& b) {
    int monthA = stoi(a.substr(0, 2));
    int dayA = stoi(a.substr(3, 2));
    int yearA = stoi(a.substr(6, 4));

    int monthB = stoi(b.substr(0, 2));
    int dayB = stoi(b.substr(3, 2));
    int yearB = stoi(b.substr(6, 4));

    if (yearA < yearB) return -1;
    if (yearA > yearB) return 1;

    if (monthA < monthB) return -1;
    if (monthA > monthB) return 1;

    if (dayA < dayB) return -1;
    if (dayA > dayB) return 1;

    return 0;
}

// Compare FoodItems based on sorting field
bool compareFood(const FoodItem& a,
                 const FoodItem& b,
                 SortField field) {

    if (field == BY_EXPIRATION) {
        return compareDates(a.expirationDate,
                            b.expirationDate) < 0;
    }
    else if (field == BY_PICKUP) {
        return compareDates(a.pickupDeadline,
                            b.pickupDeadline) < 0;
    }
    else if (field == BY_QUANTITY) {
        return a.quantity > b.quantity;
    }

    return false;
}