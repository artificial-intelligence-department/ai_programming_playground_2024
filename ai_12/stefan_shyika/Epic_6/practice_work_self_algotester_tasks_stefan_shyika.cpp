#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <climits>

using namespace std;

int main(){
    int n;
    string word;
    cin >> word;
    cin >> n;
    unordered_map<char, int> wordCount;

    for(char c : word){
        wordCount[c]++; 
    }

    unordered_map<char, int> signCount;

    for (int i = 0; i < n; i++) {
        string sign;
        cin >> sign;
        for (char c : sign) {
            signCount[c]++;
        }
    }

    int max = INT_MAX;

    for(auto& pair : wordCount){
        char c = pair.first;
        int needed = pair.second;

        if(signCount[c] == 0){
            max = 0;
            break;
        }

        max = min(max, signCount[c] / needed);
    }

    cout << max;
}