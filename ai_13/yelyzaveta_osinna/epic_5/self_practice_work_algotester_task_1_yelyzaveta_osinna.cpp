#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    cin.ignore(); // Ігноруємо символ нового рядка після зчитування чисел

    unordered_map<string, int> word_count;

    // Зчитуємо N слів
    for (int i = 0; i < N; ++i) {
        string word;
        getline(cin, word);
        // Перетворюємо слово на малі літери
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        word_count[word]++;
    }

    unordered_set<char> letter_set;

    // Збираємо літери, які зустрічаються в словах, що зустрічаються не менше ніж K разів
    for (const auto& entry : word_count) {
        if (entry.second >= K) {
            const string& word = entry.first;
            for (char c : word) {
                letter_set.insert(c);
            }
        }
    }

    // Перетворюємо множину літер у вектор для сортування
    vector<char> letters(letter_set.begin(), letter_set.end());
    
    // Сортуємо літери у зворотному алфавітному порядку
    sort(letters.rbegin(), letters.rend());

    // Виводимо результати
    if (!letters.empty()) {
        cout << letters.size() << endl;
        for (char c : letters) {
            cout << c << " ";
        }
        cout << endl;
    } else {
        cout << "Empty!" << endl;
    }

    return 0;
}