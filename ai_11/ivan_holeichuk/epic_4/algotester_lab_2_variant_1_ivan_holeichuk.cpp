#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int fatigue(vector<int>& r, int n) {

    int max_val = *max_element(r.begin(), r.end());

    int min_val = *min_element(r.begin(), r.end());

    int res = max_val - min_val;

    vector<int> temp = r;

    if (count(r.begin(), r.end(), max_val) == 1) {

        temp.erase(remove(temp.begin(), temp.end(), max_val), temp.end());

        int new_max = *max_element(temp.begin(), temp.end());

        res = min(res, new_max - min_val);

    }

    temp = r;

    if (count(r.begin(), r.end(), min_val) == 1) {

        temp.erase(remove(temp.begin(), temp.end(), min_val), temp.end());

        int new_min = *min_element(temp.begin(), temp.end());

        res = min(res, max_val - new_min);
    }

    return res;
}

int main() {

    int n;

    cin >> n;

    vector<int> r(n);


    for (int i = 0; i < n; i++) {

        cin >> r[i];
    }

    cout << fatigue(r, n) << endl;

    return 0;
}
