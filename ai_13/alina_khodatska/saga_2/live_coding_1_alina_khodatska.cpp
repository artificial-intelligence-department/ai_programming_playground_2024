#include <iostream>
#include <cstdlib> // для rand()
#include <ctime> 
#include <string>
#include <fstream>

using namespace std;

const int VARIANT = 81;  // цілочисельна константа

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

	// одновимірний масив
	double numbers[] = { a, b, static_cast<double>(c), static_cast<double>(d), static_cast<double>(e), f };

	// сортування
	for (int i = 0; i < 5; i++) { // цикл for
		for (int j = i; j < 6; j++) {
			if (numbers[i] > numbers[j]) {  // умовний оператор
				double temp = numbers[i];
				numbers[i] = numbers[j];
				numbers[j] = temp;
			}
		}
	}

	double sumLargest = numbers[3] + numbers[4] + numbers[5];
	double sumSmallest = numbers[0] + numbers[1] + numbers[2];

	double result = 0.0;

	//умовні оператори та розгалуження
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

// Завдання 4
void function_4(double array[5]) {
	struct Student  // власна структура
	{
		string name;
		string surname;
		double money;
	};

	Student students[7];
	string random_names[] = { "Name1", "Name2", "Name3", "Name4", "Name5", "Name6", "Name7" };
	string random_surnames[] = { "Surname1", "Surname2", "Surname3", "Surname4", "Surname5", "Surname6", "Surname7" };

	for (int i = 0; i < 7; i++) {
		students[i].name = random_names[rand() % 7];
		students[i].surname = random_surnames[rand() % 7];
	}

	students[0].money = array[4];
	for (int i = 1; i <= 5; i++) {
		students[i].money = array[i - 1];
	}

	students[6].money = array[0];

	cout << "List of students: " << endl;
	for (int i = 0; i < 7; i++) {
		cout << students[i].name << " " << students[i].surname << " " << students[i].money << endl;
	}
}

// Завдання 5
void help_for_function_5(ofstream& file, string data[], int size) {
	for (int i = 0; i < size; i++) {
		file << data[i] << endl;
	}
}

void function_5() {
	string students[] = {
		"Name1 Suraname1 100",
		"Name2 Suraname2 80",
		"Name3 Suraname3 60",
		"Name4 Suraname4 55",
		"Name5 Suraname5 35",
		"Name6 Suraname6 25",
		"Name7 Suraname7 5",
	};

	ofstream file("students.txt");  // робота з файлами
	if (!file.is_open()) {
		cout << "Unable to open file to wirte!" << endl;
		return;
	}

	help_for_function_5(file, students, 7);
	file.close();

	ifstream infile("students.txt") {
		if (!file.is_open()) {
			cout << "File was not found!" << endl;
			return;
		}
	}

	cout << "Content of the file: " << endl;
	string line;
	while (getline(infile, line)) {
		cout << line << endl;
	}
	infile.close();
}

//Завдання 6
void function_6() {
	ifstream file("students.txt");
	if (!file.is_open()) {
		cout << "File was not found or unable to open!" << endl;
		return;
	}

	cout << "Content of the file: " << endl;
	string line;
	while (getline(file, line)) {
		cout << line << endl;
	}

	file.close();
}

int main() {
	double x = function_1();
	function_2(x);

	double tower[5][5] = { 0 };
	function_3(tower);

	double array[5] = { 1, 2, 3, 4, 5 };
	function_4(array);

	function_5();
	function_6();

	return 0;
}