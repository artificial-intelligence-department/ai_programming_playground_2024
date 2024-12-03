#include <iostream>
#include <cstdlib> // для rand()

using namespace std;

const int VARIANT = 81;

// Задача 1
double function_1() {
	double a, b, f;
	int c, d, e;
	// дійсні та цілі числа
	cout << "Введіть 2 дійсних числа a і b: ";
	cin >> a >> b;
	cout << "Введіть 3 цілі числа c, d та e: ";
	cin >> c >> d >> e;
	cout << "Введіть дійсне число з подвійною точністю f: ";
	cin >> f;

	// обчислюємо суми найбільших і найменших
	double numbers[] = { a, b, static_cast<double>(c), static_cast<double>(d), static_cast<double>(e), f };

	// сортування
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

	// порівнюємо суми і виконуємо дії
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
	cout << "Результат function_1: " << result << endl;

	return result;
}

// Задача 2
void function_2(double& x) {
	double tower[5][5];  // tower - двовимірна матриця 5х5
	srand(time(0));

	// заповнюємо матрицю 
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			tower[i][j] = x;
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			tower[i][j] = (tower[i][j] + VARIANT + j - i) * (rand() % 100 + 1);
		}
	}

	cout << "Оновлена матриця:" << endl;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cout << tower[i][j] << " ";
		}
		cout << endl;
	}
}

// Задача 3
void function_3(int tower[5][5]) {
	int min_elements[5];

	// знаходимо мінімальні елементи
	for (int j = 0; j < 5; j++) {
		min_elements[j] = tower[0][j];
		for (int i = 1; i < 5; ++i) {
			if (tower[i][j] < min_elements[j]) {
				min_elements[j] = tower[i][j;
			}
		}
	}

	cout << "Мінімальний елемент в кожному стовпці: " << endl;
	for (int i = 0; i < 5; ++i) {
		cout << min_elements[i] << " ";
	}
	cout << endl;
}