#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // ���� 1: ��������� ������ ���������� �����
    srand(time(0));  // ����������� ���������� ���������� �����
    int n = 10;  // ����� ������ (����� ������)
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;  // ���������� ����� ����������� ������� �� 0 �� 99
    }

    // ���� 2: ��������� ����������� ������
    cout << "Step 1: Initial array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // ���� 3: ̳����� ������ ��������� � ������������ ��������
    int minIndex = 0, maxIndex = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }
    // ̳����� ������ ��������� � ������������ ��������
    swap(arr[minIndex], arr[maxIndex]);

    // �������� ����� ���� ���� ���������� �� �������������
    cout << "Step 2: After swapping min and max elements: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // ���� 4: ��������� ��������, �� ����������� ������ �������� �� 10%
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    double average = sum / (double)n;
    double threshold = average * 1.1;

    vector<int> filteredArr;
    for (int i = 0; i < n; i++) {
        if (arr[i] <= threshold) {
            filteredArr.push_back(arr[i]);
        }
    }

    // �������� ����� ���� ��������� ��������, �� ����������� ������ �� 10%
    cout << "Step 3: After removing elements greater than 10% above average: ";
    for (int i = 0; i < filteredArr.size(); i++) {
        cout << filteredArr[i] << " ";
    }
    cout << endl;

    return 0;
}
