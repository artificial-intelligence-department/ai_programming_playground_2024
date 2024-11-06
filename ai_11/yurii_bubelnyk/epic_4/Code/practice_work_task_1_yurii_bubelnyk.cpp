#include<iostream>
#include<string>
using namespace std;

bool isPalindrome(string a, int start, int end);

int main(){

    /*Реалізуйте рекурсивну функцію isPalindrome, 
    яка перевіряє, чи заданий рядок є паліндромом*/
    
    string a;
    getline(cin, a);
    
    int start = 0;
    int end = a.length()-1;

    if(isPalindrome(a, start, end)){
        cout << "Poli";
    }else{
        cout << "Not Poli";
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

