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
        return 6; //фігура на клітинці
    switch (f.name) {
    case 'P': //пішак вниз по діагоналі
        if (f.x == x - 1 && abs(f.y - y) == 1)
            return 0; //P
        break;
    case 'R': //тура по горизонталі та вертикалі
        if (f.x == x || f.y == y)
            return 1; // R
        break;
    case 'N': //кінь в формі "Г"
        if ((abs(f.x - x) == 2 && abs(f.y - y) == 1) || (abs(f.x - x) == 1 && abs(f.y - y) == 2))
            return 2; //N
        break;
    case 'B': //слон атакує по діагоналі
        if (abs(f.x - x) == abs(f.y - y))
            return 3; //B
        break;
    case 'K': //король сусідні клітинки
        if (abs(f.x - x) <= 1 && abs(f.y - y) <= 1)
            return 4; //K
        break;
    case 'Q': //королева атакує по горизонталі, вертикалі та діагоналі
        if (f.x == x || f.y == y || abs(f.x - x) == abs(f.y - y))
            return 5; //Q
        break;
    default:
        break;
    }
    return -1;
}

int main() {
    Figure figures[64];
    int figCount = 0; //лічильник к-сті фігур

    for (int i = 0; i < 8; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < row.size(); j++) {
            if (row[j] != F[7]) {
                figures[figCount++] = {row[j], i + 1, j + 1}; //фігура з координатами
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
            if (index >= 0 && index <= 5) { //атака клітинки
                result.insert(F[index]);
                isEmpty = false;
            } else if (index == 6) { //тут фігура
                onCell = true;
                isEmpty = false;
            }
        }


        if (onCell) {
            results[i] = "X"; //є фігура
        } else if (isEmpty) {
            results[i] = "O"; //не атакована
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
