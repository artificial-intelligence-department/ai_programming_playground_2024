#include <iostream>
#include <cstdlib> // для rand()

using namespace std;

const int VARIANT = 81;

// Задача 1
double function_1() {
	double a, b, f;
	int c, d, e;

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

