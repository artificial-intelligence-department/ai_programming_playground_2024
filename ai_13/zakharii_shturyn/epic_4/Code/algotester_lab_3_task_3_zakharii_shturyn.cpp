#include <iostream>
#include <vector>
using namespace std;

int main() {

    string line;
    cin >> line;
    int size = line.length();
    vector<char> res(0);
    int count = 1;
    for(int i = 0; i < size; i++) {
        if(line[i] == line[i+1] && i + 1 < size) {  //якщо буква дорівнює наступній
            count += 1;

        } else {
            res.push_back(line[i]);     //запихаємо букву, а потім каунт
            if(count > 1) {
                string str_count = to_string(count);
                for(char c : str_count) {
                    res.push_back(c);
                }
            }
            count = 1;
        }
    }
    for(char elm : res) {
        cout << elm;
    }

    return 0;
}