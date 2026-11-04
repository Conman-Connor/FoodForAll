#include "../include/CSVParser.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <algorithm>
#include <stdexcept>

using namespace std;

string calculateDate(string purchaseDate, int daysToAdd) {
    //uses the ctime include for the date
    tm date{};

    
    istringstream input(purchaseDate);
    input >> get_time(&date, "%d-%m-%Y");

    if(input.fail()) throw invalid_argument("Invalid date");

    date.tm_mday +=daysToAdd;
    date.tm_hour = 12;
    date.tm_isdst = -1;

    if(mktime(&date) == -1) throw invalid_argument("date calc failed");
    ostringstream output;
    output << put_time(&date, "%m/%d/%Y");
    return output.str();
}

vector<FoodItem> loadCSV(string filename){
    vector<FoodItem> inventory;
    ifstream file(filename);
    if ( !file.is_open()) {
        cout << "Error opening the file" << endl;
        return inventory;
    
    }
    string line;
    getline(file, line);

    while(getline(file, line)) {
        stringstream ss(line);
        string foodType, storageCondition, temperature;
        string humidity, packaging, purchaseDate;
        string expiryDays, quantity;

        getline(ss, foodType, ',');
        getline(ss, storageCondition, ',');
        getline(ss, temperature, ',');
        getline(ss, humidity, ',');
        getline(ss, packaging, ',');
        getline(ss, purchaseDate, ',');
        getline(ss, expiryDays, ',');
        getline(ss, quantity, ',');

        try {
            int days = stoi(expiryDays);
            int qty = stoi(quantity);

            string expirationDate = calculateDate(purchaseDate, days);

            // 2 days before expiration
            string pickupDeadline = calculateDate(purchaseDate, max(0, days - 2));

            FoodItem item(
                foodType,
                storageCondition,
                stod(temperature),
                stoi(humidity),
                packaging,
                purchaseDate,
                days,
                qty,
                expirationDate,
                pickupDeadline
            );

            inventory.push_back(item);

        } catch (const exception& e) {
            continue;
        }
    }

    return inventory;
}
