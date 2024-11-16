#include <iostream>
using namespace std;
bool isPalindrome(const string& str, int start, int end){
    if(start >= end){
        return true;
    }
    if(str[start] == str[end]){
        return isPalindrome(str, start + 1, end - 1);
    }
    else{
        return false;
    }
}

bool isPalindrome(int n){
    int ld, reverse = 0, num = n;
    while(num > 0){
        ld = num % 10;
        reverse = reverse*10 + ld;
        num /= 10;
    }
    if(reverse == n){
        return true;
    }
    return false;
}
int main(){
    int x;
    string y;
    cout << endl << "Input string: "; 
    cin >> y ;
    if(isPalindrome(y, 0, y.size()-1)){
        cout << endl << "It is a palindrome!";
    }
    else{
        cout << endl << "It is NOT a palindrome!";
    }
    cout << endl << "Input integer: ";
    cin >> x;
    if(isPalindrome(x)){
        cout << endl << "It is a palindrome!";
    }
    else{
        cout << endl << "It is NOT a palindrome!";
    }
    return 0;
}