#include <iostream>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <cstdlib>
#include <string>
#include <list>

using namespace std;

const int v = 6;
struct Student {
	string name;
	string surname;
	double balance;
};
	double function_1() {
		double a, b, f;
		int c, d, e;
		cout << "Enter number: " << endl;
		cin >> c >> d >> e;
		cin >> a >> b;
		cin >> f;

		double val[] = { a,b, static_cast<double>(c), static_cast<double>(d), static_cast<double>(e), f };
		sort(val, val + 6);
		double min_sum = val[0] + val[1] + val[2];
		double max_sum = val[3] + val[4] + val[5];

		double x;

		if (max_sum > min_sum * 4) {
			x = max_sum + min_sum;

		}
		else if (max_sum > min_sum * 3) {
			x = max_sum / min_sum;
		}
		else  if (max_sum > min_sum * 2) {
			x = max_sum * min_sum;
		}
		else {
			x = max_sum - min_sum;
		}

		x /= v;

		cout << "Result" << x << endl;






	return x;
}

	void function_2(double& x, double matrix[5][5]) {
		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 5; ++j) {
				matrix[i][j] = x;
			}
		}



		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 5; ++j) {
				matrix[i][j] = (matrix[i][j] + 6 + j - i) * (rand() % 100 + 1);
			}
		}

		cout << "New matrix: " << endl;
		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 5; ++j) {
				cout << matrix[i][j] << " ";
			}
		}
	}

	void function_3(double matrix[5][5], double result[5]) {

		for (int j = 0; j < 5; ++j) {
			double min1 = matrix[0][j];
			double min2 = matrix[0][j];

		}

		for (int i= 1; i < 5; ++i) {
			if (matrix[i][j] < min1) {
				min1 = matrix[i][j];
			}
		}

		for (int i = 0; i < 5; ++i) {
			min2 = min(min2, matrix[i][j]);
		}
		if (min1 == min) {
			cout << j << "motch found" << endl;
		}
		else {
			cout << j << "no match" << endl;
		}
		result[j] = min1;
	}

	void function_4(double result[5], list<Student>& students) {
		string names[7] = { "1", "2", "3", "4", "5", "6", "7" };
		string surnames[7] = { "10", "20", "30", "40", "50", "60", "70" };

		for (int i = 0; i < 7; ++i) {
			Student student;
			student.name = names[rand() % 7];
			student.surname = surnames[rand() % 7];
			if (i == 0) {
				student.balance = *max_elements(result, result + 5);

			}
			else if (i == 6) {
				student.balance = *min_elements(result, result + 5);
			}
			else {
				student.balance = result[i - 1];
			}
			students.push_back(student);
		}
		cout << "List: " << endl;
		for (const auto& student : students) {
			cout << student.name << student.surname << "Balance: " << student.balance << endl;
		}
	}

	int main() {
		double x = function_1();
		double matrix[5][5];
		function_2(x, matrix);

		double result[5];
		function_3(matrix, result);

		list<Student> students;
		function_4(result, students);
	}