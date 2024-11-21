#include <iostream>
#include <vector>

using namespace std;

int main() {
    // ������� �����
    int N;
    cin >> N;
    vector<int> r(N);
    for (int i = 0; i < N; i++) {
        cin >> r[i];
    }

    int a, b, c;
    cin >> a >> b >> c;

    // ���� 1: ��������� �������� a, b, c
    vector<int> newArray;

    // ������ �� ��������, �� �� ��� a, b �� c
    for (int i = 0; i < N; i++) {
        if (r[i] != a && r[i] != b && r[i] != c) {
            newArray.push_back(r[i]);
        }
    }

    // �������� �� ������� �������� ���� ���������
    int M = newArray.size();

    if (M < 2) {
        // ���� �������� ���� ��������� ����� �� 2, �� ��������� �������� ����� ���
        cout << 0 << endl;
        return 0;
    }

    // ���� 2: ��������� ������ ������ ���
    vector<int> sumArray;
    for (int i = 0; i < M - 1; i++) {
        sumArray.push_back(newArray[i] + newArray[i + 1]);
    }

    // ���� 3: ��������� ����������
    cout << sumArray.size() << endl;
    for (int i = 0; i < sumArray.size(); i++) {
        cout << sumArray[i] << " ";
    }
    cout << endl;

    return 0;
}
