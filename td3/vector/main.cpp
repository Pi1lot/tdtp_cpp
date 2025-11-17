#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    vector<int> v1;

    vector<double> v2(5, 10.5);
    vector<double> v3 = {1.1, 2.2, 3.3, 4.4, 5.5};

    vector<vector<int>> v2D(4, vector<int>(3, 7));

    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    
    cout << v1[0] << endl;

    int v1_size = v1.size();
    cout << v1_size << endl;

    for(int i = 0; i < v1.size(); i++) {
        cout << v1[i] << endl;
    }

    for (auto it = v1.begin(); it != v1.end(); ++it) {
        cout << *it << endl;
    }

    for(int value : v1) {
        cout << value << endl;
    }

    v1.pop_back();

    v1.insert(v1.begin() + 1, 7);

    v1.erase(v1.begin()+1);
    sort(v1.begin(), v1.end());
}
