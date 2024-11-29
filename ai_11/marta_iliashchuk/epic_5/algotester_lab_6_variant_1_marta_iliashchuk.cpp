#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    int N, K;
    cin>>N>>K;

    map<char, int> letter_count;

    for (int i = 0; i < N; ++i) {
        string word;
        cin>>word;

       
        set<char> unique_letters;
        for (char c : word) {
            unique_letters.insert(tolower(c));
        }

        
        for (char c : unique_letters) {
            letter_count[c]++;
        }
    }

    vector<char> result;
    for (auto& pair : letter_count) {
        if (pair.second >= K) {
            result.push_back(pair.first);
        }
    }

    sort(result.begin(), result.end());

    if (result.empty()) {
        cout<<"Empty!"<<endl;
    } else {
        cout<<result.size()<<endl;
        for (char c : result) {
            cout<<c<<" ";
        }
        cout<<endl;
    }

    return 0;
}
