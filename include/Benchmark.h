
#ifndef BENCHMARK_H
#define BENCHMARK_H

#include "FoodItem.h"
#include <vector>
#include <string>

using namespace std;

struct BenchmarkResult {

    string algorithm;
    double executionTime;
    bool correct;
};

class Benchmark {
public:

    static bool verifySorted(const vector<FoodItem>& data, SortField field);
    static BenchmarkResult testMergeSort(const vector<FoodItem>& original, SortField field);
    static BenchmarkResult testQuickSort(const vector<FoodItem>& original, SortField field);
    static void displayResults(const BenchmarkResult& merge, const BenchmarkResult& quick, int datasetSize);
};

#endif
