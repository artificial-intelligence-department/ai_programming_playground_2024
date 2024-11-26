#include <iostream>
#include <string>
#include <unordered_map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

//конвертуємо усі букви в нижній регістр
void LowerCase(string& str) {
    for (char& c : str) {
        c = tolower(c);
    }
}

int main() {
    //приймаємо значення для кількості слів
    int N, K;
    cin >> N >> K;

    //створюємо непосортовану хеш-таблицю для запису слів і їх кількості
    unordered_map<string, int> wordCount;
    vector<string> words(N);
    //записуємо слова у вектор, паралельно переводимо у нижній
    //регістр і записуємо в хеш-таблицю
    for (int i = 0; i < N; i++) {
        cin >> words[i];
        LowerCase(words[i]);
        wordCount[words[i]]++; 
    }

    //створюємо набір і записуємо  туди слова які проходять 
    //по кількості повторень
    set<char> validLetters;

    for (const auto& [word, count] : wordCount) {
        if (count >= K) {
            for (char c : word) {
                validLetters.insert(c);
            }
        }
    }

    //у разі відсутності таких слів виводимо "Пусто!"
    if (validLetters.empty()) {
        cout << "Empty!" << endl;
        return 0;
    }

    //записуємо слова з набору у вектор і сортуємо їх, у зворотньому
    //алфавітному порядку
    vector<char> sortedLetters(validLetters.begin(), validLetters.end());
    sort(sortedLetters.rbegin(), sortedLetters.rend());

    //виводимо кількість таких літер і їх самих через пробіл
    cout << sortedLetters.size() << endl;
    for (size_t i = 0; i < sortedLetters.size(); i++) {
        cout << sortedLetters[i];
        if (i != sortedLetters.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}
