#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string addStrings(string num1, string num2)
{
    string result;
    int carry = 0;

    while (num1.size() < num2.size())
        num1 = "0" + num1;
    while (num2.size() < num1.size())
        num2 = "0" + num2;

    for (int i = num1.size() - 1; i >= 0; i--)
    {
        int digit1 = num1[i] - '0';
        int digit2 = num2[i] - '0';
        int sum = digit1 + digit2 + carry;

        carry = sum / 10;
        result.push_back((sum % 10) + '0');
    }

    if (carry)
        result.push_back('1');

    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    string a, b;
    cin >> a >> b;

    string sum = addStrings(a, b);
    cout << sum << endl;

    return 0;
}
