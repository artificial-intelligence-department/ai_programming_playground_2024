#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

int main() {
    string line;
    getline(cin, line);

    stringstream ss(line);
    vector<int> a;
    int number;

    while (ss >> number) {
        a.push_back(number);
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < a.size(); i++) {
        if (i > 0) cout << " ";
        cout << a[i];
    }
    cout << endl;

    return 0;
}