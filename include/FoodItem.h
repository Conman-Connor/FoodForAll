#ifndef FOODITEM_H
#define FOODITEM_H

#include <string>

using namespace std;

struct FoodItem {
    string name;
    string expirationDate;  // MM/DD/YYYY
    string pickupDeadline;  // MM/DD/YYYY
    int quantity;

    FoodItem() {
        name = "";
        expirationDate = "";
        pickupDeadline = "";
        quantity = 0;
    }

    FoodItem(string n, string exp, string pickup, int q) {
        name = n;
        expirationDate = exp;
        pickupDeadline = pickup;
        quantity = q;
    }
};

enum SortField {
    BY_EXPIRATION = 1,
    BY_PICKUP = 2,
    BY_QUANTITY = 3
};

inline int compareDates(const string& a, const string& b) {
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

inline bool compareFood(const FoodItem& a,
                        const FoodItem& b,
                        SortField field) {
    if (field == BY_EXPIRATION) {
        return compareDates(a.expirationDate, b.expirationDate) < 0;
    }
    else if (field == BY_PICKUP) {
        return compareDates(a.pickupDeadline, b.pickupDeadline) < 0;
    }
    else if (field == BY_QUANTITY) {
        return a.quantity > b.quantity;
    }

    return false;
}

#endif

