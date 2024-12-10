//робот

#include <iostream>
#include <string>

using namespace std;

void countCommands(const string& s, int index, int& countU, int& countR) {//рекурсивна функція для підрахунку кількості команд
    if (index == s.length()) return;
    if (s[index] == 'U') countU++;
    if (s[index] == 'R') countR++;
    
    countCommands(s, index + 1, countU, countR); //рекурсивний виклик
}

int main() {
    string s;
    int x, y;
    cin >> s >> x >> y;
    int countU = 0, countR = 0;
    countCommands(s, 0, countU, countR);
    if (countR >= x && countU >= y) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
