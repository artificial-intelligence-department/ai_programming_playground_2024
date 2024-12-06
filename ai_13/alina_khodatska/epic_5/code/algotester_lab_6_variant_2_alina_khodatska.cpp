#include <iostream>
#include <vector>
#include <set> // ��� ������������ �������
#include <cmath> // ��� ������������ ������� abs(abs - ������ �����)
#include <algorithm>

using namespace std;

struct Figure { // ��������� ��� ��������� ������
    char type;
    int x, y;
};

bool canAttack(const Figure& f, int targetX, int targetY) { // ������� ��� �������� ��������� �����
    switch (f.type) { // ���������� ��� ������
    case 'P': // ϳ���
        return (f.x == targetX - 1 && abs(f.y - targetY) == 1); // ϳ��� ���� ��������� �� ���� ������� �� �������� �� �� ���� �� ����������
    case 'R': // ����
        return (f.x == targetX || f.y == targetY); // ���� ���� ��������� �� �������� ��� ����������
    case 'N': // ʳ��
        return (abs(f.x - targetX) == 2 && abs(f.y - targetY) == 1) || (abs(f.x - targetX) == 1 && abs(f.y - targetY) == 2); // ���� ���� ��������� ������ "�"
    case 'B': // ����
        return (abs(f.x - targetX) == abs(f.y - targetY)); // ���� ���� ��������� �� �������
    case 'K': // ������
        return (abs(f.x - targetX) <= 1 && abs(f.y - targetY) <= 1); // ������ ���� ��������� �� ���� ������� � ����-����� ��������
    case 'Q': // �����
        return (f.x == targetX || f.y == targetY || abs(f.x - targetX) == abs(f.y - targetY)); // ����� ���� ��������� �� ��������, ���������� ��� �������
    default:
        return false; // ���� �� ������� ������
    }
}


vector<string> processQueries(const vector<Figure>& figures, const vector<pair<int, int>>& queries) { // ������� ��� ������� ������
    vector<string> results;

	for (const auto& query : queries) { // ���� ��� ������� ������� ������
        int x = query.first;
        int y = query.second;
        set<char> attackers;
        bool isOccupied = false;

		for (const auto& figure : figures) { // ���� ��� �������� ����� ������
            if (figure.x == x && figure.y == y) {
                isOccupied = true;
                break;
            }
            if (canAttack(figure, x, y)) {
                attackers.insert(figure.type);
            }
        }

		if (isOccupied) { // ������ ��������� � ��������� �� ����, �� ������� �������
            results.push_back("X");
        }
        else if (attackers.empty()) {
            results.push_back("O");
        }
		else { // ������� ������ �����, �� ������ ��������� �������
            string attackersList(attackers.begin(), attackers.end());
            results.push_back(attackersList);
        }
    }

    return results;
}

int main() {
    vector<Figure> figures; 
	for (int i = 0; i < 8; ++i) { // ���� ��� �������� �����
        string row;
        cin >> row;
		for (int j = 0; j < row.size(); ++j) { // ���� ��� �������� ����� �������
            if (row[j] != 'O') {
                figures.push_back({ row[j], i + 1, j + 1 });
            }
        }
    }

    int q;
    cin >> q;
	vector<pair<int, int>> queries(q); // ������ ��� ��������� ������
	for (int i = 0; i < q; ++i) { // ���� ��� �������� ������
        cin >> queries[i].first >> queries[i].second;
    }

	vector<string> results = processQueries(figures, queries); // ������� ������
	for (const auto& result : results) { // ���� ��� ��������� ����������
        cout << result << endl;
    }

    return 0;
}

����� ������� ���� � bool canAttack