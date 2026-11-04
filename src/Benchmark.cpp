
#include "Benchmark.h"
#include "MergeSort.h"
#include "QuickSort.h"

#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;


// Verify that the dataset is sorted

bool Benchmark::verifySorted(
        const vector<FoodItem>& data,
        SortField field) {

    for (int i = 1; i < static_cast<int>(data.size()); i++) {

        if (compareFood(data[i], data[i - 1], field)) {
            return false;
        }
    }
    return true;
}


// Merge Sort benchmark
BenchmarkResult Benchmark::testMergeSort(const vector<FoodItem>& original,SortField field) {

    vector<FoodItem> data = original;
    auto start = steady_clock::now();
    MergeSort::sort(data, field);
    auto end = steady_clock::now();
    double elapsed =
        duration<double, milli>(end - start).count();
    BenchmarkResult result;

    result.algorithm = "Merge Sort";
    result.executionTime = elapsed;
    result.correct = verifySorted(data, field);

    return result;
}


// Quick Sort benchmark
BenchmarkResult Benchmark::testQuickSort(
        const vector<FoodItem>& original,
        SortField field) {

    vector<FoodItem> data = original;
    auto start = steady_clock::now();
    QuickSort::sort(data, field);
    auto end = steady_clock::now();
    double elapsed =
        duration<double, milli>(end - start).count();
    BenchmarkResult result;

    result.algorithm = "Quick Sort";
    result.executionTime = elapsed;
    result.correct = verifySorted(data, field);

    return result;
}


// Display results
void Benchmark::displayResults(
        const BenchmarkResult& merge,
        const BenchmarkResult& quick,
        int datasetSize) {

    cout << "\n=====================================\n";
    cout << "       SORTING BENCHMARK RESULTS\n";
    cout << "=====================================\n";

    cout << "Dataset Size: " << datasetSize << endl;

    cout << "\nMerge Sort:\n";

    cout << "Execution Time: "
         << merge.executionTime << " ms\n";

    cout << "Correctness: "
         << (merge.correct ? "PASS" : "FAIL") << endl;

    cout << "\nQuick Sort:\n";

    cout << "Execution Time: "
         << quick.executionTime << " ms\n";

    cout << "Correctness: "
         << (quick.correct ? "PASS" : "FAIL") << endl;

    cout << "\n=====================================\n";

    if (!merge.correct || !quick.correct) {

        cout << "Sorting verification failed!\n";
    }

    else if (merge.executionTime < quick.executionTime) {

        cout << "Merge Sort was faster.\n";
    }

    else if (quick.executionTime < merge.executionTime) {

        cout << "Quick Sort was faster.\n";
    }

    else {

        cout << "Both algorithms had equal execution times.\n";
    }

    cout << "=====================================\n";
}
