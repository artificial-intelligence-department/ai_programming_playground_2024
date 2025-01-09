#include <iostream>
#include <string>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    string result = "";
    int carry = 0;


    while (a.length() < b.length()) a = "0" + a;
    while (b.length() < a.length()) b = "0" + b;


    for (int i = a.length() - 1; i >= 0; i--) {
        int sum = (a[i] - '0') + (b[i] - '0') + carry;
        carry = sum / 10; 
        result = char(sum % 10 + '0') + result;
    }


    if (carry > 0) {
        result = char(carry + '0') + result;
    }


    cout << result << endl;

    return 0;
}
