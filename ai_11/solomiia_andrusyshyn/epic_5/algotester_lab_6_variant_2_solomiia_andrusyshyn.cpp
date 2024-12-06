#include <iostream>
#include <cstring>
#include <cmath>
#include <set>

using namespace std;

struct Figure {
    char name;
    int x, y;
};

const char F[] = {'P', 'R', 'N', 'B', 'K', 'Q', 'X', 'O'}; 

int cellCheck(Figure &f, int x, int y) {
    if (f.x == x && f.y == y)
        return 6; 
    switch (f.name) {
    case 'P': 
        if (f.x == x - 1 && abs(f.y - y) == 1)
            return 0; 
        break;
    case 'R': 
        if (f.x == x || f.y == y)
            return 1; 
        break;
    case 'N': 
        if ((abs(f.x - x) == 2 && abs(f.y - y) == 1) || (abs(f.x - x) == 1 && abs(f.y - y) == 2))
            return 2;
        break;
    case 'B': 
        if (abs(f.x - x) == abs(f.y - y))
            return 3; 
        break;
    case 'K': 
        if (abs(f.x - x) <= 1 && abs(f.y - y) <= 1)
            return 4; 
        break;
    case 'Q': 
        if (f.x == x || f.y == y || abs(f.x - x) == abs(f.y - y))
            return 5; 
        break;
    default:
        break;
    }
    return -1;
}

int main() {
    Figure figures[64];
    int figCount = 0; 

    for (int i = 0; i < 8; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < row.size(); j++) {
            if (row[j] != F[7]) {
                figures[figCount++] = {row[j], i + 1, j + 1}; 
            }
        }
    }

    int n;
    cin >> n; 
    string* results = new string [n]; 

    for (int i = 0; i < n; i++) {
        set<char> result;
        int x, y;
        cin >> x >> y;
        bool isEmpty = true; 
        bool onCell = false;

        for (int j = 0; j < figCount; j++) {
            int index = cellCheck(figures[j], x, y);
            if (index >= 0 && index <= 5) { 
                result.insert(F[index]);
                isEmpty = false;
            } else if (index == 6) {
                onCell = true;
                isEmpty = false;
            }
        }


        if (onCell) {
            results[i] = "X"; 
        } else if (isEmpty) {
            results[i] = "O";
        } else {
            for (set<char>::iterator it = result.begin(); it != result.end(); ++it) {
            results[i] += *it;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << results[i] << endl;
    }

    delete[] results;

    return 0;
}
