#include <iostream>
#include <vector>
#include <deque> // ��� ��������� �����
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
    int height;
};

// ���������� ������� �����
void fillHeightMap(vector<vector<int>>& heightMap, int N, int M, int peakX, int peakY) {
    deque<Point> dq; // ����� ��� ������ � ������
    dq.push_back({ peakX, peakY, 0 }); // ��������� ������ - 0 ��� ���������
    heightMap[peakX][peakY] = 0;

    // �������� ��� ���������� (������, ����, ����, �����)
    int directions[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

    while (!dq.empty()) {
        Point p = dq.front();
        dq.pop_front();

        for (auto& dir : directions) {
            int newX = p.x + dir[0];
            int newY = p.y + dir[1];

            if (newX >= 0 && newX < N && newY >= 0 && newY < M && heightMap[newX][newY] == -1) {
                heightMap[newX][newY] = p.height + 1;
                dq.push_back({ newX, newY, p.height + 1 });
            }
        }
    }

    // ����������� ������ - ������� �� ��� �� ������������ �����
    int maxHeight = 0;
    for (const auto& row : heightMap) {
        maxHeight = max(maxHeight, *max_element(row.begin(), row.end()));
    }

    // ������������ ����� �� �������� ��������
    for (auto& row : heightMap) {
        for (auto& height : row) {
            height = maxHeight - height;
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    int peakX, peakY;
    cin >> peakX >> peakY;

    // ����������� ��������� ��� 0-����������
    peakX--;
    peakY--;

    vector<vector<int>> heightMap(N, vector<int>(M, -1));

    fillHeightMap(heightMap, N, M, peakX, peakY);

	for (const auto& row : heightMap) { // ��������� ������� ����� �� �����
        for (const auto& height : row) {
            cout << height << " ";
        }
        cout << endl;
    }

    return 0;
}
