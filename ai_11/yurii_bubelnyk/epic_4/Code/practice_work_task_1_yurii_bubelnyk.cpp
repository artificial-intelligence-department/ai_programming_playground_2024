#include<iostream>
#include<string>
using namespace std;

bool isPalindrome(string a, int start, int end);
bool isPalindrome(int num);

int main(){

    /*Реалізуйте рекурсивну функцію isPalindrome, 
    яка перевіряє, чи заданий рядок є паліндромом*/
    
    string a;
    getline(cin, a);
    
    int start = 0;
    int end = a.length()-1;

    if(isPalindrome(a, start, end)){
        cout << "Pali";
    }else{
        cout << "Not Pali";
    }

    cout << endl;

    int number;
    cin >> number;

    if (isPalindrome(number)) {
        cout << "Pali" << endl;
    } else {
        cout << "Not a Pali" << endl;
    }

    return 0;
}

bool isPalindrome(string a, int start, int end){
    
    if(start >= end)
    return true;

    if (a[start] != a[end])
    return false;

    return isPalindrome(a, ++start, --end);
}

bool isPalindrome(int num) {
    int original = num;
    int reversed = 0;
    
    while (num > 0) {
        int digit = num % 10;
        reversed = reversed * 10 + digit;
        num /= 10;
    }
    
    return original == reversed;
}