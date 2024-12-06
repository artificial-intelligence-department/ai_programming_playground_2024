#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printSet(const vector<int>& result) { // ������� ��� ��������� ������
    cout << result.size() << endl;
	for (int num : result) { // ���� ��� ��������� ����� ������
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    int N, M;

    // ����� ���
    cin >> N;
	vector<int> set1(N); // ����� ����� ������� N ��� ��������� �������� �����
	for (int i = 0; i < N; ++i) { // ���� ��� �������� ����� ������
        cin >> set1[i];
    }

    cin >> M;
	vector<int> set2(M); // ����� ����� ������� M ��� ��������� �������� �����
	for (int i = 0; i < M; ++i) { // ���� ��� �������� ����� ������
        cin >> set2[i];
    }

    // ������� ������
    sort(set1.begin(), set1.end());
    sort(set2.begin(), set2.end());

    // г����� N-M
    vector<int> diff1;
    set_difference(set1.begin(), set1.end(), set2.begin(), set2.end(), back_inserter(diff1));
    printSet(diff1);

    // г����� M-N
    vector<int> diff2;
    set_difference(set2.begin(), set2.end(), set1.begin(), set1.end(), back_inserter(diff2));
    printSet(diff2);

    // �������
    vector<int> inter;
    set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), back_inserter(inter));
    printSet(inter);

    // ��'�������
    vector<int> uni;
    set_union(set1.begin(), set1.end(), set2.begin(), set2.end(), back_inserter(uni));
    printSet(uni);

    // ���������� ������
    vector<int> symDiff;
    set_symmetric_difference(set1.begin(), set1.end(), set2.begin(), set2.end(), back_inserter(symDiff));
    printSet(symDiff);

    return 0;
}
