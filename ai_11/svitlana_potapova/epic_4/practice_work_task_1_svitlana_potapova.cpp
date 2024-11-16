#include <iostream>
using namespace std;

bool isPalindrome(const string& str, int start, int end){
    if (start >= end) return true;

    if (str[start] != str[end]) return false;

    return isPalindrome(str, ++start, --end);
}

bool isPalindrome(int num){
    int reversed = 0;

    int temp = num;
    while (temp != 0) {
        reversed = reversed * 10 + temp % 10;
        temp /= 10;
    }
    return (reversed == num);
}

int main(){
    int num;
    string str; 

    cout << "Enter a string: " << endl; 
    getline(cin,str);

    if(isPalindrome(str, 0, str.length() - 1)){
        cout << str << " is a palindrome" << endl;
    }
    else{
        cout << str << " isn`t a palindrome" << endl;
    }

    cout << "Enter a number: " << endl;
    cin >> num;

    if(isPalindrome(num)){
        cout << num << " is a palindrome" << endl;
    }
    else{
        cout << num << " isn`t a palindrome" << endl;
    }
   
    return 0;
}
