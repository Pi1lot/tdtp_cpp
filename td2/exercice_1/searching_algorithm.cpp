#include "searching_algorithm.h"

using namespace std;
SearchingAlgorithm::SearchingAlgorithm() : numberComparisons(0) {}

int SearchingAlgorithm::totalComparisons = 0;

int SearchingAlgorithm::totalSearch = 0;

double SearchingAlgorithm::averageComparisons = 0.0;

void SearchingAlgorithm::displaySearchResults(ostream& os, int target, int results) {
    if (results != -1) {
        os  << "\n";
    } else {
        os << "Cible introuvable\n";
    }

    os << "Nombre de comparaisons:" << numberComparisons << " Tot. comparaisons: " << totalComparisons << " Moy. comparaisons: " << averageComparisons << "\n";

    os << "Element recherché: " << target << " trouvé à index: " << results << ":\n";

}
