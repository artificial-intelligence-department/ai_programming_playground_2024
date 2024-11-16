#include <iostream>
#include <string>

using namespace std;

//оголошуємо перевантажену функцію для перевірки паліндрома
bool isPalindrome(string s, int start, int end);
bool isPalindrome(int n);

int main(){
    //створюємо строку для слова і перевіряємо на паліндром
    string line;
    cin >> line;
    if (isPalindrome(line, 0, line.size()-1)){
        cout << line <<" is a palindrome\n";
    }
    else {
        cout << line << " isn`t a palindrome\n";
    }

    //створюємо строку для числа і перевіряємо на паліндром 
    int number;
    cin >> number;
    if (isPalindrome(number)){
        cout << number <<" is a palindrome";
    }
    else {
        cout << number << " isn`t a palindrome";
    }

    return 0;
}

bool isPalindrome(string s, int start, int end){
    //перевірка щоб змінні не зайшли за середину
    if(start <= end){
        //чи співпадають букви з двох кінців
        if(s[start] == s[end]){
            //створюмо рекурсію для перевірки всієї строки
            isPalindrome(s, ++start, ++end);
        }
        else{
            return false;
        }
    }
    return true;
}

bool isPalindrome(int n){
    //змінні для перевернутого і оригінального числа
    int reversed = 0;
    int original = n;

    while (n > 0) {
        //перевертаємо число через остачу ділення на 10
        int digit = n % 10;
        reversed = reversed * 10 + digit;
        n /= 10;
    }
    //звіряємо оригінал і перевернуту строку
    
    return original == reversed;
}