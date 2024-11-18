#include <iostream>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;
    cin.ignore(); // Ігноруємо символ нового рядка після N

    int ritualCount = 0;
    bool damagedSymbols = false;

    for (int i = 0; i < N; ++i) {
        string line;
        getline(cin, line);

        for (char c : line) {
            if (c == '#') {
                if (!damagedSymbols) {
                    damagedSymbols = true;
                    ++ritualCount;
                }
            } else {
                damagedSymbols = false;
            }
        }
    }

    cout << ritualCount << endl;
    return 0;
}
