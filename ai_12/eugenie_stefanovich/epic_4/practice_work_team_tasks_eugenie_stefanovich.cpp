#include <iostream>


using namespace std;

bool isPalindrome(const string& s, int start, int end){
    if(start >= end) 
        return true;
    if(s[start] != s[end]) 
        return false;
    return isPalindrome(s, start+1, end-1);
}

bool isPalindrome(int n) {
    if (n < 0) 
        return false;

    int original = n; 
    int reversed = 0;

    while (n > 0) {
        int p = n % 10;
        reversed = reversed * 10 + p;
        n /= 10;
    }

    return original == reversed; 
}

int main(){
    string s;
    int n;
    cout << "Строка: ";
    getline(cin, s);
    cout << "Число: ";
    cin >> n;
    cout << endl;

    cout << "Строка є паліндромом? - " << (isPalindrome(s, 0, s.length()-1) ? "Так" : "Ні") << endl;
    cout << "Число є паліндромом? - " << (isPalindrome(n) ? "Так" : "Ні") << endl;
}