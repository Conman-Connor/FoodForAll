#ifndef FOODITEM_H
#define FOODITEM_H
#include <string>

using namespace std;



struct FoodItem {
    string name;
    string storageCondition;
    double temperature;
    int humidity;
    string packaging;
    string purchaseDate;
    int expiryDays;
    int quantity;
    string expirationDate;
    string pickupDeadline;

    FoodItem();
    FoodItem(string n, string storage, double temp, int humid, string pack, string purchase, int days, int q, string exp, string pickup);

    string getName() const;
    string getStorageCondition() const;
    double getTemperature() const;
    int getHumidity() const;
    string getPackaging() const;
    string getPurchaseDate() const;
    int getExpiryDays() const;
    int getQuantity() const;
    string getExpirationDate() const;
    string getPickupDeadline() const;

};

enum SortField {
    BY_EXPIRATION = 1,
    BY_PICKUP = 2,
    BY_QUANTITY = 3


};

int compareDates(const string& a, const string& b);
bool compareFood(const FoodItem& a, const FoodItem& b, SortField field);



#endif