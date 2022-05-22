#ifndef quick_sort_h
#define quick_sort_h

#include <iostream>
#include <vector>

using namespace std;

vector<int> quick_sort(vector<int> unsorted) {
    int n = unsorted.size();
    // Base case
    if (n <= 1) {
        return unsorted;
    }

    // Create partition vectors
    vector<int> LT;
    vector<int> EQ;
    vector<int> GT;

    // Randomize pivot
    int random_index = rand()%unsorted.size();
    int pivot = unsorted[random_index];

    // Partition the input vector
    for (int i = 0; i < unsorted.size(); ++i) {
        if (unsorted[i] < pivot) {
            LT.push_back(unsorted[i]);
        } else if (unsorted[i] == pivot) {
            EQ.push_back(unsorted[i]);
        } else {
            GT.push_back(unsorted[i]);
        }
    }

    // Recurse through quick_sort
    vector<int> LT_Sorted = quick_sort(LT);
    vector<int> GT_Sorted = quick_sort(GT);

    // Append LT_Sorted, EQ, and GT_Sorted
    vector<int> sorted;
    for (int i = 0; i < LT_Sorted.size(); ++i) {
        sorted.push_back(LT_Sorted[i]);
    }
    for (int i = 0; i < EQ.size(); ++i) {
        sorted.push_back(EQ[i]);
    }
    for (int i = 0; i < GT_Sorted.size(); ++i) {
        sorted.push_back(GT_Sorted[i]);
    }

    // Return the sorted vector
    return sorted;
}

#endif /* quick_sort_h */