#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(const string &neline, int a){
    if (a >= neline.length()/2){
        return true;
    }
    
    if (neline[a] != neline[neline.length() - a - 1]){
        return false;
    }

    return isPalindrome(neline, a+1);
}

bool isPalindrome(int number1){
    
    int number_reversed = 0;
    int a = 0;
    int n = 10;
    
    while(number1 >= n/10){
        number_reversed += (number1 % n - a)/(n/10);
        a = number1 % n;
        number_reversed *= 10;
        n = n*10;
    }
    
    if(number_reversed/10 == number1){
        return true;
    }else{
        return false;
    }
}

int main(){
    string line;
    int number;
    getline(cin, line);

    if (isPalindrome(line, 0)){
        cout << "Yes, your line is a palindrome." << endl;
    }else{
        cout << "No, your line is not a palindrome." << endl;
    }
    
    cin >> number;
    
    if (isPalindrome(number)){
        cout << "Yes, your number is a palindrome." << endl;
    }else{
        cout << "No, your number is not a palindrome." << endl;
    }    
    return 0;
}