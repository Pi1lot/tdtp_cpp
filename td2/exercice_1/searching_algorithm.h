#ifndef SEARCHING_ALGORITHM_H
#define SEARCHING_ALGORITHM_H
#include <vector>
#include <iostream>
using namespace std;


class SearchingAlgorithm {
    public:
        SearchingAlgorithm();
        
        virtual ~SearchingAlgorithm() = default;

        virtual int search(const vector<int>& elements, int cible) = 0;

        void displaySearchResults(ostream& os, int target, int results);

        static int totalComparisons, totalSearch;
        static double averageComparisons;

    protected:
        int numberComparisons;

};

#endif