#include "binary_search.h"

using namespace std;

int BinarySearch::search(const vector<int>& elements, int cible) {
    numberComparisons = 0;
    
    int left = 0;
    int right = elements.size() - 1;
    
    while (left <= right) {
        int mid = left+ (right-left)/ 2;
        
        numberComparisons++;
        if (elements[mid] == cible) {
            totalComparisons += numberComparisons;
            totalSearch++;
            averageComparisons = static_cast<double>(totalComparisons) / totalSearch;
            return mid;
        }
        
        numberComparisons++;
        if (elements[mid] < cible) {
            left = mid+1;
        } else {
            right = mid-1;
        }
    }
    
    totalComparisons += numberComparisons;
    totalSearch++;
    averageComparisons = static_cast<double>(totalComparisons) / totalSearch;
    return -1;
}