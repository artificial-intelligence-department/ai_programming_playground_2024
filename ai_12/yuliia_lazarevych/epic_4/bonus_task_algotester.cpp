#include <iostream>
#include <vector>
#include <string>

using namespace std;

//використовую функцію для підрахунку мінімальної кількості ритуалів
int countHealingRituals(vector<string>& lines) {
    int rituals = 0;

    for (const string& line : lines) {
        bool inDamagedWord = false;
        for (char c : line) {
            if (c == '#') {
                if (!inDamagedWord) {
                    inDamagedWord = true;
                    rituals++;
                }
            } else {
                inDamagedWord = false;
            }
        }
    }
    return rituals;
}

int main() {
    int N;
    cin >> N;
    cin.ignore();
    //використовую динамічний масив для зберігання рядків закляття
    vector<string> lines(N);

    for (int i = 0; i < N; i++) {
        getline(cin, lines[i]);
    }

    int result = countHealingRituals(lines);

    cout << result << endl;

    return 0;
}
