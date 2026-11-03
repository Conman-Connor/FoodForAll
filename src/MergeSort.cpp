
#include "MergeSort.h"

// Merge two sorted sections

void MergeSort::merge(vector<FoodItem>& data, int left, int middle, int right, SortField field) {

    int leftSize = middle - left + 1;
    int rightSize = right - middle;
    vector<FoodItem> leftArray(leftSize);
    vector<FoodItem> rightArray(rightSize);

    // Copy left section
    for (int i = 0; i < leftSize; i++) {
        leftArray[i] = data[left + i];
    }

    // Copy right section
    for (int j = 0; j < rightSize; j++) {
        rightArray[j] = data[middle + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;

    // Merge both sections
    while (i < leftSize && j < rightSize) {
        if (!compareFood(rightArray[j], leftArray[i], field)) {
            data[k] = leftArray[i];
            i++;
        }

        else {
            data[k] = rightArray[j];
            j++;
        }
        k++;
    }

    // Copy remaining left elements
    while (i < leftSize) {
        data[k] = leftArray[i];
        i++;
        k++;
    }

    // Copy remaining right elements
    while (j < rightSize) {
        data[k] = rightArray[j];
        j++;
        k++;
    }
}


// Recursive Merge Sort
void MergeSort::mergeSortHelper(vector<FoodItem>& data, int left, int right, SortField field) {

    if (left >= right) {
        return;
    }

    int middle = left + (right - left) / 2;
    mergeSortHelper(data, left, middle, field);
    mergeSortHelper(data, middle + 1, right, field);
    merge(data, left, middle, right, field);
}


// Public sorting function
void MergeSort::sort(vector<FoodItem>& data, SortField field) {
    if (data.empty()) {
        return;
    }

    mergeSortHelper(data, 0, static_cast<int>(data.size()) - 1, field);
}

