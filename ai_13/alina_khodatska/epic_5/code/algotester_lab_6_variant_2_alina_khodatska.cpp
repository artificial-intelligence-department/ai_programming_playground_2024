#include <iostream>
#include <vector>
#include <set> // для використання множини
#include <cmath> // для використання функції abs(abs - модуль числа)
#include <algorithm>

using namespace std;

struct Figure { // Структура для зберігання фігури
    char type;
    int x, y;
};

bool canAttack(const Figure& f, int targetX, int targetY) { // Функція для перевірки можливості атаки
    switch (f.type) { // Перевіряємо тип фігури
    case 'P': // Пішак
        return (f.x == targetX - 1 && abs(f.y - targetY) == 1); // Пішак може атакувати на одну клітинку по вертикалі та на одну по горизонталі
    case 'R': // Тура
        return (f.x == targetX || f.y == targetY); // Тура може атакувати по вертикалі або горизонталі
    case 'N': // Кінь
        return (abs(f.x - targetX) == 2 && abs(f.y - targetY) == 1) || (abs(f.x - targetX) == 1 && abs(f.y - targetY) == 2); // Конь може атакувати буквою "Г"
    case 'B': // Слон
        return (abs(f.x - targetX) == abs(f.y - targetY)); // Слон може атакувати по діагоналі
    case 'K': // Король
        return (abs(f.x - targetX) <= 1 && abs(f.y - targetY) <= 1); // Король може атакувати на одну клітинку в будь-якому напрямку
    case 'Q': // Ферзь
        return (f.x == targetX || f.y == targetY || abs(f.x - targetX) == abs(f.y - targetY)); // Ферзь може атакувати по вертикалі, горизонталі або діагоналі
    default:
        return false; // Якщо це невідома фігура
    }
}


vector<string> processQueries(const vector<Figure>& figures, const vector<pair<int, int>>& queries) { // Функція для обробки запитів
    vector<string> results;

	for (const auto& query : queries) { // Цикл для обробки кожного запиту
        int x = query.first;
        int y = query.second;
        set<char> attackers;
        bool isOccupied = false;

		for (const auto& figure : figures) { // Цикл для перевірки кожної фігури
            if (figure.x == x && figure.y == y) {
                isOccupied = true;
                break;
            }
            if (canAttack(figure, x, y)) {
                attackers.insert(figure.type);
            }
        }

		if (isOccupied) { // Додаємо результат в залежності від того, чи зайнята клітинка
            results.push_back("X");
        }
        else if (attackers.empty()) {
            results.push_back("O");
        }
		else { // Формуємо список фігур, які можуть атакувати клітинку
            string attackersList(attackers.begin(), attackers.end());
            results.push_back(attackersList);
        }
    }

    return results;
}

int main() {
    vector<Figure> figures; 
	for (int i = 0; i < 8; ++i) { // Цикл для введення фігур
        string row;
        cin >> row;
		for (int j = 0; j < row.size(); ++j) { // Цикл для перевірки кожної клітинки
            if (row[j] != 'O') {
                figures.push_back({ row[j], i + 1, j + 1 });
            }
        }
    }

    int q;
    cin >> q;
	vector<pair<int, int>> queries(q); // Вектор для зберігання запитів
	for (int i = 0; i < q; ++i) { // Цикл для введення запитів
        cin >> queries[i].first >> queries[i].second;
    }

	vector<string> results = processQueries(figures, queries); // Обробка запитів
	for (const auto& result : results) { // Цикл для виведення результату
        cout << result << endl;
    }

    return 0;
}

посни частину коду з bool canAttack