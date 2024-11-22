#include <iostream>
#include <string>
using namespace std;
bool isPalindrome(const string& str, int start, int end){
    if (end <= start){
        return true;
    }
    if(str[start] == str[end - 1]){
        return isPalindrome(str, start + 1, end - 1);
    }
    else{
        return false;
    }
}
bool isPalindrome(int num){
    int temp = num, reverseNum = 0;
    while(num > 0){
        reverseNum *= 10;
        reverseNum += num % 10;
        num /= 10;
    }
    if (reverseNum == temp) return true;
    else return false;
}
int main(){
    int number;
    string word;
    cin >> word;
    if (isPalindrome(word, 0, word.length())) cout << "Слово є паліндромом" << endl;
    else cout << "Слово не є паліндромом" << endl;
    cin >> number;
    if (isPalindrome(number)) cout << "Число є паліндромом" << endl;
    else cout << "Число не є паліндромом" << endl;
    return 0;
}