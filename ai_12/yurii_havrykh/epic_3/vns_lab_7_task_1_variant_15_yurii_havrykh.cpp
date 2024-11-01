#include<bits/stdc++.h>

using namespace std;

vector<int> convert(int k, ...) {
    va_list numbers;
    va_start(numbers, k);
    vector<int> a;
    for (int i = 0; i < k; i++) {
        int num = va_arg(numbers, int);
        string s = to_string(num);
        reverse(s.begin(), s.end());
        int cur = 0;
        int rez = 0;
        for (auto j: s) {
            rez += (j - '0') * pow(8, cur);
            cur++;
        }
        a.push_back(rez);
    }
    va_end(numbers);
    return a;

}

int main() {
    vector<int> b = convert(3, 7, 11, 34);
    for (int i: b) {
        cout << i << " ";
    }
    cout << endl;

    b = convert(6, 4, 12, 13, 15, 16, 17);
    for (int i: b) {
        cout << i << " ";
    }
    cout << endl;

    b = convert(7, 20, 21, 22, 23, 24, 25, 26);
    for (int i: b) {
        cout << i << " ";
    }
    cout << endl;
}