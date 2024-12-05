#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    string results;
    cin >> results;

    int kolya_wins = 0, vasya_wins = 0;
    int kolya_points = 0, vasya_points = 0;

    for (char c : results) {
        if (c == 'K') kolya_points++;
        else if (c == 'V') vasya_points++;

        // Перевірка, чи закінчилася поточна партія
        if ((kolya_points >= 11 || vasya_points >= 11) &&
            abs(kolya_points - vasya_points) >= 2) {
            if (kolya_points > vasya_points) kolya_wins++;
            else vasya_wins++;

            kolya_points = 0;
            vasya_points = 0;
        }
    }

    cout << kolya_wins << ":" << vasya_wins << endl;

    if (kolya_points > 0 || vasya_points > 0) {
        cout << kolya_points << ":" << vasya_points << endl;
    }

    return 0;
}
