#include <iostream>
#include <vector>
#include <sstream>

using namespace std;
// lab 3 variant 1

int main() {
    // Зчитуємо кількість рядків
    int N;
    cin >> N;
    cin.ignore();  // ігноруємо переведення на новий рядок після N

    int totalRituals = 0;

    // Обробляємо кожен рядок
    for (int i = 0; i < N; ++i) {
        string line;
        getline(cin, line);

        stringstream ss(line);
        string word;

        // Обробляємо кожне слово в рядку
        while (ss >> word) {
            int rituals = 0;
            bool inRitual = false;

            // Перевіряємо кожен символ в слові
            for (char c : word) {
                if (c == '#') {
                    if (!inRitual) {
                        // Початок нової послідовності пошкоджених символів
                        rituals++;
                        inRitual = true;
                    }
                }
                else {
                    // Завершення послідовності пошкоджених символів
                    inRitual = false;
                }
            }

            totalRituals += rituals;
        }
    }

    // Виводимо загальну кількість ритуалів
    cout << totalRituals << endl;

    return 0;
}
