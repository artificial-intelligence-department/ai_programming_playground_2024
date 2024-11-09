#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool audit(const string& word, int start, int end) {
    if (start >= end) {
        return true;
    }
    if (word[start] != word[end]) {
        return false;
    }
    return audit(word, start + 1, end - 1);
}

bool isPolindrom(const string& word) {
    return audit(word, 0, word.size() - 1);
}

bool isPolindrom(int number) {
    string numberStr = to_string(number);
    return audit(numberStr, 0, numberStr.size() - 1);
}

int main(){
    string word;
    cout << "Введіть слово для перевірки: ";
    cin >> word;
    if (isPolindrom(word))
    {
        cout << "Слово є паліндромом." << endl; 
    }else{
        cout << "Слово не є паліндромом." << endl;
    }
    
    int number;
    cout << "Введіть число: ";
    cin >> number;

    if (isPolindrom(number))
    {
        cout << "Число є паліндромом." << endl;
    }else{
        cout << "Число не є паліндромом." << endl;
    }
    return 0;
}