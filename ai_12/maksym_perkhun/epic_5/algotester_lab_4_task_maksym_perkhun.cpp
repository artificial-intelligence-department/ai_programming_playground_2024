#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int main() {
    int n, t, ost0 = 0, ost1 = 0, ost2 = 0;
    cin >> n;
    vector <int> vec, ostVec(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> t;
        vec.push_back(t);
        if (t % 3 == 0){
            ostVec.insert(ostVec.begin() + ost0, t);
            ost0++;
            ost1++;
            ost2++;
        }
        else if (t % 3 == 1){
            ostVec.insert(ostVec.begin() + ost1, t);
            ost1++;
            ost2++;
        }
        else{
            ostVec.insert(ostVec.begin() + ost2, t);
            ost2++;
        }
    }
    sort(ostVec.begin(), ostVec.begin() + ost0);
    sort(ostVec.begin() + ost0, ostVec.begin() + ost1, greater<int>());
    sort(ostVec.begin() + ost1, ostVec.begin() + ost2);
    auto new_end = unique(ostVec.begin(), ostVec.end());
    ostVec.erase(new_end, ostVec.end());
    int last = distance(ostVec.begin(), new_end) - 1;
    cout << last << endl;
    for (int i = 0; i < last; i++)
    {
        cout << ostVec[i] << " ";
    }
    return 0;
}