#include <iostream>
#include <set>
using namespace std;

int main() {
    string s;
    cin >> s;

    int x = 0, y = 0;
    set<pair<int, int>> visited; 
    visited.insert({ x, y }); 

    for (char move : s) {
        if (move == 'N') {
            y++; 
        }
        else if (move == 'S') {
            y--; 
        }
        else if (move == 'E') {
            x++; 
        }
        else if (move == 'W') {
            x--; 
        }
        if (visited.count({ x, y })) {
            cout << "Something goes wrong..." << endl;
            return 0;
        }
        visited.insert({ x, y });
    }

    cout << "Looks OK." << endl;
    return 0;
}
