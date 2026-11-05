#ifndef MENU_H
#define MENU_H

#include "FoodItem.h"
#include <vector>

class Menu
{
    public:
        static void displayMenu();
        static void displaySortingMenu();
        static void displayPerformanceMenu();
        static void run(const std::vector<FoodItem>& donations);
        static void runMergeSort(const std::vector<FoodItem>& donations);
        static void runQuickSort(const std::vector<FoodItem>& donations);
        static void comparePerformance(const std::vector<FoodItem>& donations);
};

#endif