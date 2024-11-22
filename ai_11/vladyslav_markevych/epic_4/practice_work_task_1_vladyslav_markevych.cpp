#include <iostream>
#include <vector>

using namespace std;

bool isPalindrome(const string& str, int start, int end){
    if(start>=end) return true;
    if(str[start] != str[end]) return false;
    return isPalindrome(str, start + 1, end - 1 );
}

bool isPalindrome(const string& str){
    return isPalindrome(str, 0, str.length() - 1);
}

bool isPalindrome(int numbers){
    string str = to_string(numbers);
    return isPalindrome(str);
}


int main(){
    string str1;
    string str2;
    cout<<"Введіть два слова: "<<endl;
    cin>>str1;
    cin>>str2;
    
    cout<<"Чи "<<str1<<" є паліндромом?\n"<<(isPalindrome(str1) ? "Так" : "Ні")<<endl;;
    cout<<"Чи "<<str2<<" є паліндромом?\n"<<(isPalindrome(str2) ? "Так" : "Ні")<<endl;

    int num1;
    int num2;

    cout<<"Введіть два числа:"<<endl;
    cin>>num1;
    cin>>num2;

    cout<<"Чи "<<num1<<" є паліндромом?\n"<<(isPalindrome(num1) ? "Так" : "Ні")<<endl;;
    cout<<"Чи "<<num2<<" є паліндромом?\n"<<(isPalindrome(num2) ? "Так" : "Ні");

    return 0;
}
