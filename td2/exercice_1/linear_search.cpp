#include "linear_search.h"

using namespace std;

int LinearSearch::search(const vector<int>& elements, int cible) {
    numberComparisons = 0;
    
    for (size_t i = 0; i < elements.size(); i++) {
        numberComparisons++;
        if (elements[i] == cible) {
            totalComparisons += numberComparisons;
            totalSearch++;
            averageComparisons = static_cast<double>(totalComparisons) / totalSearch;
            return i;
        }
    }
    
    totalComparisons += numberComparisons;
    totalSearch++;
    averageComparisons = static_cast<double>(totalComparisons) / totalSearch;
    return -1;
}