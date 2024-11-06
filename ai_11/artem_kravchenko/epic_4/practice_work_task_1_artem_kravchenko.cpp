#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isPolindrom (const string& word){
    string reversedWord = word;
    reverse(reversedWord.begin(), reversedWord.end());
    return word == reversedWord;
}

bool isPolindrom( int number){
    string numberStr = to_string(number);
    string reversedStr = numberStr;
    reverse(reversedStr.begin(), reversedStr.end());
    return numberStr == reversedStr;
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