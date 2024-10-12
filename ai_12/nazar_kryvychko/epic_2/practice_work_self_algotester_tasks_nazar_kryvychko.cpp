#include <iostream>
#include <string>
#include<algorithm>
using namespace std;

int main() {
    string a, b;

    cin >> a >> b;

    string result;
    int carry = 0;
    int i = a.size() - 1;
    int j = b.size() - 1;

    while (i >= 0 || j >= 0 || carry) {
        int digitA = (i >= 0) ? a[i--] - '0' : 0;
        int digitB = (j >= 0) ? b[j--] - '0' : 0;
        int sum = digitA + digitB + carry;
        result.push_back(sum % 10 + '0');
        carry = sum / 10;
    }

    reverse(result.begin(), result.end());

    cout << result << endl;

    return 0;
}
