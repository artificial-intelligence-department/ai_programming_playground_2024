#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    // ������� ����������� ����� ������
    vector<vector<char>> cave(N, vector<char>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> cave[i][j];
        }
    }

    // ������� ��� �� ����� �� ������
    cout << endl;

    // ������� ������� �������
    for (int j = 0; j < M; j++) {
        int emptyPos = N - 1;  // �������, ���� ������ ������ ����

        // ��������� �������� ����� �����
        for (int i = N - 1; i >= 0; i--) {
            if (cave[i][j] == 'S') {
                // ���� �� ����, ������� ���� � ������� ����� �������
                cave[i][j] = 'O';  // ������� ������� �������
                cave[emptyPos][j] = 'S';  // ������� ���� � �������� ����� ����
                emptyPos--;  // ������� ������� ��� ���������� ����
            }
            // ���� �� �����, ������ ����������
            else if (cave[i][j] == 'X') {
                emptyPos = i - 1;  // ����� ����� ������ ����
            }
        }
    }

    // ��������� ������ ����� ������
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << cave[i][j];
        }
        cout << endl;
    }

    return 0;
}
