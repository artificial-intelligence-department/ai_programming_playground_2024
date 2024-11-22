#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
        cin >> n;
        string s;
    cin >> s;

    int kolya_games = 0, vasya_games = 0;
    int kolya_points = 0, vasya_points = 0;

    for (int i = 0; i < n; ++i) {
        if (s[i] == 'K') {
            kolya_points++;
        }
        else {
            vasya_points++;
        }

        
        if (kolya_points >= 11 && kolya_points - vasya_points >= 2) {
            kolya_games++;
            kolya_points = 0;
            vasya_points = 0;   
        }
        else if (vasya_points >= 11 && vasya_points - kolya_points >= 2) {
            vasya_games++;
            kolya_points = 0;
            vasya_points = 0;
        }
    }


    cout << kolya_games << ":" << vasya_games << endl;


    cout << kolya_points << ":" << vasya_points << endl;

    return 0;
}
