
#include "Menu.h"
#include "Benchmark.h"
#include "MergeSort.h"
#include "QuickSort.h"

#include <iostream>

using namespace std;


void Menu::displayMenu() {
    cout << "\n=============================================\n";
    cout << "             PANTRY PRIORITIZER\n";
    cout << "       Food Donation Sorting System\n";
    cout << "=============================================\n";
    cout << "1. Run Merge Sort\n";
    cout << "2. Run Quick Sort\n";
    cout << "3. Compare Performance Metrics\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
}


void Menu::displaySortingMenu() {
    cout << "\nSelect a sorting criterion:\n";
    cout << "1. Expiration Date\n";
    cout << "2. Quantity\n";
    cout << "3. Pickup Deadline\n";
    cout << "4. Return to Main Menu\n";
    cout << "Enter your choice: ";
}


void Menu::displayPerformanceMenu() {
    cout << "\nCompare Merge Sort vs Quick Sort by:\n";
    cout << "1. Expiration Date\n";
    cout << "2. Quantity\n";
    cout << "3. Pickup Deadline\n";
    cout << "4. Return to Main Menu\n";
    cout << "Enter your choice: ";
}


void Menu::run(const vector<FoodItem>& donations) {
    int choice;
    while(choice!=4)
    {
        displayMenu();
        cin>>choice;
        if (choice ==1)
        {
            runMergeSort(donations);
    
        }
        else if(choice ==2)
        {
            runQuickSort(donations);
        }
        else if(choice ==3)
        {
            comparePerformance(donations);
        }
        else if(choice ==4)
        {
            cout << "\nExiting Pantry Prioritizer. Goodbye!\n";
        }
        else
        {
            cout << "\nInvalid choice. Please try again.\n";
        }


    }
}

void Menu::runMergeSort(const vector<FoodItem>& donations) {
    int choice;
    displaySortingMenu();
    cin >> choice;
    SortField field;

    if(choice == 1)
    {
        field = SortField::BY_EXPIRATION;
    }
    else if(choice == 2)
    {
        field = SortField::BY_QUANTITY;
    }
    else if(choice == 3)
    {
        field = SortField::BY_PICKUP;
    }
    else
    {
        cout << "\nInvalid choice.\n";
        return;
    }

    vector<FoodItem> sortedData = donations;
    MergeSort::sort(sortedData, field);

    

    cout << "\nMerge Sort completed successfully!\n";
    cout << "Records sorted: " << sortedData.size() << endl;

//     for (int i = 0; i < sortedData.size(); i++) {
//     cout << "Name: " << sortedData[i].getName() << endl;
//     cout << "Quantity: " << sortedData[i].getQuantity() << endl;
//     cout << "Expiration Date: " << sortedData[i].getExpirationDate() << endl;
// }
}


    


void Menu::runQuickSort(const vector<FoodItem>& donations) {
     int choice;
    displaySortingMenu();
    cin >> choice;
    SortField field;

    if(choice == 1)
    {
        field = SortField::BY_EXPIRATION;
    }
    else if(choice == 2)
    {
        field = SortField::BY_QUANTITY;
    }
    else if(choice == 3)
    {
        field = SortField::BY_PICKUP;
    }
    else
    {
        cout << "\nInvalid choice.\n";
        return;
    }

    vector<FoodItem> sortedData = donations;
    QuickSort::sort(sortedData, field);

    

    cout << "\nQuick Sort completed successfully!\n";
    cout << "Records sorted: " << sortedData.size() << endl;

//     for (int i = 0; i < sortedData.size(); i++) {
//     cout << "Name: " << sortedData[i].getName() << endl;
//     cout << "Quantity: " << sortedData[i].getQuantity() << endl;
//     cout << "Expiration Date: " << sortedData[i].getExpirationDate() << endl;
// }
}

void Menu::comparePerformance(const vector<FoodItem>& donations) {
    int choice;

    displayPerformanceMenu();
    cin >> choice;

    SortField field;

    if (choice == 1) {
        field = SortField::BY_EXPIRATION;
        }
        else if (choice == 2) {
    field = SortField::BY_QUANTITY;
            }
        else if (choice == 3) {
     field = SortField::BY_PICKUP;
        }
        else if (choice == 4) {
    return;
        }
else {
    cout << "\nInvalid choice.\n";
    return;
}
    BenchmarkResult merge =
        Benchmark::testMergeSort(donations, field);

    BenchmarkResult quick =
        Benchmark::testQuickSort(donations, field);

    Benchmark::displayResults(merge, quick, donations.size());
}
