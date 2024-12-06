#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ������� ��� ��������� ��������
void removeDuplicates(vector<int>& a) {
    sort(a.begin(), a.end());
    int uniqueCount = 0;
	for (int i = 1; i < a.size(); ++i) { // �������� �� ��������
        if (a[i] != a[uniqueCount]) {
            ++uniqueCount;
            a[uniqueCount] = a[i];
        }
    }
    a.resize(uniqueCount + 1);
}

// ������� ��� ��������� ������
void rotateArray(vector<int>& a, int K) {
    int n = a.size();
    K = K % n;
    vector<int> temp(K);
	for (int i = 0; i < K; ++i) { // �������� ����� K ��������
        temp[i] = a[i];
    }
	for (int i = K; i < n; ++i) { // ��������� �������� �� K ������� ����
        a[i - K] = a[i];
    }
	for (int i = 0; i < K; ++i) { // ��������� �������� �������� �� �����
        a[n - K + i] = temp[i];
    }
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> a(N);

	for (int i = 0; i < N; ++i) { // ���� ��� �������� �������� ������
        cin >> a[i];
    }

    // ��������� ��������
    removeDuplicates(a);

    // ��������� ������ �� K
    rotateArray(a, K);

    // ��������� ����������
    cout << a.size() << endl;
    for (int num : a) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
