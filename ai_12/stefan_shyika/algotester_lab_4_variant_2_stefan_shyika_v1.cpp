#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int> vec(N);

    for(int i = 0; i < N; i++){
        cin >> vec[i];
    }

    sort(vec.begin(), vec.end());
    auto last = unique(vec.begin(), vec.end());
    vec.erase(last, vec.end());

    vector<int> mod0, mod1, mod2;
    for (int num : vec) {
        if (num % 3 == 0) {
            mod0.push_back(num);
        } else if (num % 3 == 1) {
            mod1.push_back(num);
        } else {
            mod2.push_back(num);
        }
    }

    sort(mod0.begin(), mod0.end());
    sort(mod2.begin(), mod2.end());
    sort(mod1.begin(), mod1.end(), greater<int>());

    vector<int> result;
    result.insert(result.end(), mod0.begin(), mod0.end());
    result.insert(result.end(), mod1.begin(), mod1.end());
    result.insert(result.end(), mod2.begin(), mod2.end());

    int len = result.size();
    cout << len << endl;
    for (int i = 0; i < len; i++) {
        if(i != len -1){
            cout << result[i] << " ";
        }else{
            cout << result[i];
        }
    }
}