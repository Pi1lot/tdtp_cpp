#include <iostream>
#include <vector>

#include "linear_search.h"
#include "jump_search.h"
#include "binary_search.h"

using namespace std;

int main() {
    vector<int> elements = {1, 2, 4, 6, 12, 14, 17, 18, 25, 32, 45, 57, 61, 73, 79, 81, 92, 110, 238, 555};
    int cible = 79;
    
    int results;

    std::cout <<"Binaire" << "\n";
    BinarySearch binary;
    results = binary.search(elements, cible);
    binary.displaySearchResults(cout, results, cible);
    std::cout << "\n";

    std::cout <<"Linéaire" << "\n";
    LinearSearch linear;
    results = linear.search(elements, cible);
    
    linear.displaySearchResults(cout, results, cible);
    std::cout << "\n";
    
    std::cout <<"Jump" << "\n";
    JumpSearch jump;
    results = jump.search(elements, cible);
    jump.displaySearchResults(cout, results, cible);
    std::cout << "\n";


    return 0;
}
