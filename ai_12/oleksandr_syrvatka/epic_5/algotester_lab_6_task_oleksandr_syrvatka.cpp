#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <cctype>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;  // Зчитуємо кількість слів та мінімум для врахування слова

    unordered_map<string, int> wordCount;  // Для зберігання кількості входжень кожного слова
    vector<string> words(N);

    // Зчитуємо слова та рахуємо кількість входжень кожного слова
    for (int i = 0; i < N; ++i) {
        cin >> words[i];
        // Перетворюємо слово в нижній регістр
        for (char &c : words[i]) {
            c = tolower(c);
        }
        wordCount[words[i]]++;  // Підраховуємо кількість входжень слова  grim Grim GRIM 
    }

    set<char> result;  // Множина для зберігання унікальних літер

    // Перевіряємо кожне слово
    for (const auto &word : words) {
        if (wordCount[word] >= K) {  // Якщо слово зустрічається >= K разів
            for (char ch : word) {
                result.insert(ch);  // Додаємо букву до множини
            }
        }
    }

    // Якщо множина порожня, виводимо "Empty!"
    if (result.empty()) {
        cout << "Empty!" << endl;
    } else {
        // Виводимо унікальні літери в зворотному порядку
        vector<char> sortedResult(result.begin(), result.end());
        sort(sortedResult.rbegin(), sortedResult.rend());  // Зворотне сортування

        cout << sortedResult.size() << endl;
        for (char ch : sortedResult) {
            cout << ch << " ";
        }
        cout << endl;
    }

    return 0;
}
