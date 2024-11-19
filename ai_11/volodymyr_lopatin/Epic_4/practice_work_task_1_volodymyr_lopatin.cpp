#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(const string& str, int start, int end) {
    if (start >= end) return true;
    if (str[start] != str[end]) return false;
    return isPalindrome(str, start+1, end-1);
}

bool isPalindrome(int num) {
    string str = to_string(num);
    return isPalindrome(str, 0, str.length()-1);
}

int main() {
    string str;
    int start, end, num;
    cin >> str >> start >> end >> num;
    cout << "For string: " << isPalindrome(str, start, end) << endl;
    cout << "For number: " << isPalindrome(num);
    return 0;
}