#include <iostream>
#include <string>
using namespace std;

void replaceMin(string &num, int index) {
    if (index == num.length()) return; 
    if (num[index] == '*') {
        num[index] = (index == 0) ? '1' : '0';
    }
    replaceMin(num, index + 1); 
}

void replaceMax(string &num, int index) {
    if (index == num.length()) return; 
    if (num[index] == '*') {
        num[index] = '9'; 
    }
    replaceMax(num, index + 1); 
}

int main() {
    string input;
    cin >> input;

    string min_num = input;
    string max_num = input;

    replaceMin(min_num, 0); 
    replaceMax(max_num, 0); 

    cout << min_num << " " << max_num << endl;
    return 0;
}
