
#ifndef MERGESORT_H
#define MERGESORT_H

#include "FoodItem.h"
#include <vector>

using namespace std;

class MergeSort {

private:

    static void merge(vector<FoodItem>& data,
                      int left,
                      int middle,
                      int right,
                      SortField field);

    static void mergeSortHelper(vector<FoodItem>& data,
                                int left,
                                int right,
                                SortField field);

public:

    static void sort(vector<FoodItem>& data,
                     SortField field);

};

#endif
