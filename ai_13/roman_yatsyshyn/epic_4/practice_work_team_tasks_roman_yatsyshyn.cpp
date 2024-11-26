#include <stdio.h>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool isPalindrome(string str, int start, int end){
    
    if (start < end) {
        if (str[start] == str[end])
        {
            bool recursion = isPalindrome(str, start+1, end-1);
            return recursion;
        }
        else
        {
            return 0;
        }
    }
    else{
        return 1;
    }
}

bool isPalindrome(const int a){
    int counter = 1;

    int start = 0;
    
    for (int i = 1; ; i*=10)
    {
        if (a / i >= 10)
        {
            counter++;
        }
        else{
            break;
        }  
    }

    int end = counter-1;
    string str_from_int = to_string(a);

    while (start < end) {
        if ((str_from_int[start] != str_from_int[end]))
        {
            return 0;
        }
        ++start;
        --end; 
    }
    return 1;
}

int main(){
    cout << isPalindrome("level", 0, 4);
    cout << isPalindrome(1234321);
    cout << isPalindrome("bob", 0, 2);
    cout << isPalindrome(1231);
    cout << isPalindrome("manipulation", 0, 11);
    cout << isPalindrome(55);
}