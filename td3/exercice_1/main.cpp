#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void countFrequencyBruteForce(const vector<int> &numbers)
{
    vector<int> sorted;
    sorted = numbers;
    sort(sorted.begin(), sorted.end());
    cout << "Seconde liste triée: ";
    for (int value : sorted){
        cout << value << " ";
    }

    cout << "Itération" << endl;

    int currentIndex = 0;
    //= sort(numbers.begin(), numbers.end());
    for (int i = 0; i < sorted.size(); ++i)
    {
        int occurence = 0;

        for (int j = 0; j < sorted.size(); ++j)
        {
            if (sorted[i] == sorted[j])
            {
                occurence++;
            }
        }

        // On affiche uniquement si on n'a pas déjà affiché cet élément
        if (currentIndex != sorted[i]) {
            cout << sorted[i] << ": " << occurence << " times" << endl;
            currentIndex = sorted[i];
        }
    }
}

map<int, int> countFrequencyOptimal(const vector<int> &numbers)
{
    map<int, int> frequencyMap;
    for (const int &num : numbers)
    {
        frequencyMap[num]++;
    }
    return frequencyMap;
}

int main()
{
vector<int> numbers = {1, 1, 1, 1,  2, 3, 2, 4, 6, 1, 5, 5, 6};

// Test countFrequencyBruteForce
cout << "Frequency (Brute Force):" << endl;
countFrequencyBruteForce(numbers);

// Test countFrequencyOptimal
cout << "\nFrequency (Optimal):" << endl;
map<int, int> frequencyMapOptimal = countFrequencyOptimal(numbers);
for (const auto &entry : frequencyMapOptimal)
{
    cout << entry.first << ": " << entry.second << " times" << endl;
}

return 0;
}