#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(const string& word, int start, int end){ 
    if (start > end) return true;
    if (word[start] != word[end]) return false;
    return isPalindrome(word, start+1, end-1);  }

bool isPalindrome(int& num) {
    if (num < 0) { 
        return false;
    }
int a = num;
int reversed = 0;
while (num > 0) {
int digit = num % 10;
num = num / 10;
reversed = reversed * 10 + digit;
}
return reversed == a;   }
int main() {
   string word;
   cin >> word;
    if (isPalindrome(word, 0 , word.length() - 1)) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }

    int num;
    cin >> num;
    if (isPalindrome(num)) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
    return 0;
}