#include <iostream>
#include <string>

bool isPalindrome(const std::string &word, int current_position_1, int current_position_2){

if(current_position_1 == current_position_2)
    return true;

return (word[current_position_1] == word[current_position_2]) && isPalindrome(word, current_position_1 + 1, current_position_2 - 1);



}

bool isPalindrome(int a, int n){

if( a < 10)
    return true;

while (a / n >= 10) {
        n *= 10;
    }
int firstDigit = a / n;
int lastDigit = a % 10;


return (firstDigit == lastDigit) && isPalindrome((a%n)/n, n*10);
}

int main(){

std::string word;
std::cout << "Enter you word: ";
std::cin >> word;

bool result_word = isPalindrome(word, 0, word.size()-1);

if(result_word)
    std::cout << "Your word is a palindrome" << std::endl;
else
    std::cout << "You word is not a palindrome" << std::endl;


int digit;
std::cout << "Enter you digit: ";
std::cin >> digit;


bool result_digit = isPalindrome(digit, 10);
if(result_digit)
    std::cout << "Your digit is a palindrom";
else
    std::cout << "Your digit is not a palindrom";

    return 0;
}