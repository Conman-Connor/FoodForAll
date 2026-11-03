
#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "FoodItem.h"
#include <vector>

using namespace std;

class QuickSort {

private:

    static void quickSortHelper(vector<FoodItem>& data, int low, int high, SortField field);

public:

    static void sort(vector<FoodItem>& data, SortField field);

};

#endif
