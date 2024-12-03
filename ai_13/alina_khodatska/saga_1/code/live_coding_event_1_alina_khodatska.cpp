#include <iostream>
#include <cstdlib> // ��� rand()

using namespace std;

const int VARIANT = 81;

// ������ 1
double function_1() {
	double a, b, f;
	int c, d, e;

	cout << "������ 2 ������ ����� a � b: ";
	cin >> a >> b;
	cout << "������ 3 ��� ����� c, d �� e: ";
	cin >> c >> d >> e;
	cout << "������ ����� ����� � �������� ������� f: ";
	cin >> f;

	// ���������� ���� ��������� � ���������
	double numbers[] = { a, b, static_cast<double>(c), static_cast<double>(d), static_cast<double>(e), f };

	// ����������
	for (int i = 0; i < 5; i++) {
		for (int j = i; j < 6; j++) {
			if (numbers[i] > numbers[j]) {
				double temp = numbers[i];
				numbers[i] = numbers[j];
				numbers[j] = temp;
			}
		}
	}

	double sumLargest = numbers[3] + numbers[4] + numbers[5];
	double sumSmallest = numbers[0] + numbers[1] + numbers[2];

	double result = 0.0;

	// ��������� ���� � �������� 䳿
	if (sumLargest > sumSmallest * 4) {
		result = sumLargest + sumSmallest;
	}
	else if (sumLargest > sumSmallest * 3) {
		result = sumLargest / sumSmallest;
	}
	else if (sumLargest > sumSmallest * 2) {
		result = sumLargest * sumSmallest;
	}

	result /= VARIANT;
	cout << "��������� function_1: " << result << endl;

	return result;
}

