#include "jump_search.h"

using namespace std;

int JumpSearch::search(const vector<int>& elements, int cible) {
    numberComparisons = 0;
    
    int n = elements.size();
    int step = sqrt(n);
    int prev = 0;
    
    while (prev < n) {
        numberComparisons++;
        if (elements[min(step, n) - 1] >= cible) {
            break;
        }
        prev = step;
        step += sqrt(n);
    }
    
    for (int i = prev; i < min(step, n); i++) {
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