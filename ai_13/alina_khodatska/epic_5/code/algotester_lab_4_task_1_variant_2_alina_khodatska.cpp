#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> a(N);  // ������������� ������, �� ����� �� ���� �������� ����� �� ��� ���������

    for (int i = 0; i < N; ++i) {  // ���� ��� �������� �������� ������
        cin >> a[i];
    }

    // ��������� ��������
    sort(a.begin(), a.end()); 
	auto last = unique(a.begin(), a.end()); // ������� �������� �� ������ �������
	a.erase(last, a.end()); // ��������� ��������

    // ��������� ������ �� K
    int M = a.size(); // ����� ������ ���� ��������� ��������
    K = K % M; // � �������, ���� K ����� �� ����� ������
    rotate(a.begin(), a.begin() + K, a.end()); 

    // ��������� ����������
    cout << M << endl;
    for (int num : a) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
