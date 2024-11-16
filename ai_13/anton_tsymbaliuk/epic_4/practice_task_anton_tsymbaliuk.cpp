#include <iostream>

bool const isPalindrome(const int l, const int r,const std::string& str){
    if(l >= r) return true;
    if(str[l] == str[r]){
        if(isPalindrome(l + 1, r - 1, str)) return true;
        else return false;
    }
    else return false;
}


int main(){
    std::string str;
    std::cin >> str;
    bool result = isPalindrome(0, str.size() - 1, str);
    std::cout << str << (result ? " is palindrome" : " isn't palindrome") << std::endl;
}