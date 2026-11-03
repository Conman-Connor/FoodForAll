
#include "QuickSort.h"

// Recursive Quick Sort using three-way partitioning
void QuickSort::quickSortHelper(vector<FoodItem>& data, int low, int high, SortField field) {

    if (low >= high) {
        return;
    }

    // Select middle element as pivot
    int middle = low + (high - low) / 2;
    FoodItem pivot = data[middle];

    int less = low;
    int current = low;
    int greater = high;

    while (current <= greater) {

        // Current item belongs before pivot
        if (compareFood(data[current], pivot, field)) {

            FoodItem temp = data[less];
            data[less] = data[current];
            data[current] = temp;
            less++;
            current++;
        }

        // Pivot belongs before current item
        else if (compareFood(pivot, data[current], field)) {

            FoodItem temp = data[current];
            data[current] = data[greater];
            data[greater] = temp;
            greater--;
        }

        // Items have equal sorting priority
        else {
            current++;
        }
    }

    // Sort items before pivot
    quickSortHelper(data, low, less - 1, field);

    // Sort items after pivot
    quickSortHelper(data, greater + 1, high, field);
}


// Public sorting function
void QuickSort::sort(vector<FoodItem>& data, SortField field) {

    if (data.empty()) {
        return;
    }
    quickSortHelper(data, 0, static_cast<int>(data.size()) - 1, field);
}
