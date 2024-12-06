#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <string>

using namespace std;

struct Figure {
    char name;
    int x, y;
};

// Функція для перевірки можливості атаки
bool canAttack(const Figure &f, int x, int y) {
    switch (f.name) {
        case 'P': 
            return f.x == x - 1 && abs(f.y - y) == 1;
        case 'R': 
            return f.x == x || f.y == y;
        case 'N': 
            return (abs(f.x - x) == 2 && abs(f.y - y) == 1) || (abs(f.x - x) == 1 && abs(f.y - y) == 2);
        case 'B': 
            return abs(f.x - x) == abs(f.y - y);
        case 'K': 
            return abs(f.x - x) <= 1 && abs(f.y - y) <= 1;
        case 'Q': 
            return f.x == x || f.y == y || abs(f.x - x) == abs(f.y - y);
        default: return false;
    }
}

// Функція для зчитування шахової дошки
vector<Figure> readFigures() {
    vector<Figure> figures;
    for (int row = 1; row <= 8; ++row) {
        string line;
        cin >> line;
        for (int col = 0; col < line.size(); ++col) {
            if (line[col] != 'O') {
                figures.push_back({line[col], row, col + 1});
            }
        }
    }
    return figures;
}

// Функція для перевірки позиції
string checkPosition(int x, int y, const vector<Figure> &figures) {
    set<char> attackers;
    bool isOccupied = false;

    for (const auto &figure : figures) {
        if (figure.x == x && figure.y == y) {
            isOccupied = true;
            break;
        }
        if (canAttack(figure, x, y)) {
            attackers.insert(figure.name);
        }
    }

    if (isOccupied) {
        return "X";
    } else if (attackers.empty()) {
        return "O";
    } else {
        string result(attackers.begin(), attackers.end());
        return result;
    }
}

int main() {
    // Зчитуємо шахову дошку
    vector<Figure> figures = readFigures();

    // Зчитуємо кількість запитів
    int n;
    cin >> n;

    // Обробляємо запити
    vector<string> results;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        results.push_back(checkPosition(x, y, figures));
    }

    // Виводимо результати
    for (const auto &result : results) {
        cout << result << endl;
    }

    return 0;
}
