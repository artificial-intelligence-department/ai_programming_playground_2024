#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <cctype>
using namespace std;

string to_lowercase(const string &s) {
    string result = s;
    for (char &c : result) {
        c = tolower(c);
    }
    return result;
}

void RASU(vector<char> &arr) {
    set<char> unique_chars(arr.begin(), arr.end());
    arr.assign(unique_chars.rbegin(), unique_chars.rend()); //  в зворотному порядку  rbegin і rend створюють зворотній ітераційний прохід
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<string> arr(n);
    unordered_map<string, int> word_count;//as js object
    vector<char> result;

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        arr[i] = to_lowercase(arr[i]);
        word_count[arr[i]]++; // Підраховує кількість появ
    }

    for (const auto &entry : word_count) {//get very key: value
        if (entry.second >= k) {
            for (char c : entry.first) {
                result.push_back(c);
            }
        }
    }

    RASU(result);//sort & erasing zayvi
    if (result.empty()) {
        cout << "Empty!" << endl;
    } else {
        cout << result.size() << endl;
        for (char el : result) {
            cout << el << " ";
        }
        cout << endl;
    }

    return 0;
}

