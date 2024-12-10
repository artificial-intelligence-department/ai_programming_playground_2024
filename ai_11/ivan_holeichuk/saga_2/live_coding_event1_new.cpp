#include <iostream>
#include <cmath>
#include <algorithm>
#include <list>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>

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
    cout << "Enter three integers: ";
    cin >> c >> d >> e;
    cout << "Enter two doubles: ";
    cin >> a >> b;
    cout << "Enter one more double: ";
    cin >> f;

    double val[] = { a, b, static_cast<double>(c), static_cast<double>(d), static_cast<double>(e), f };
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
    else if (max_sum > min_sum * 2) {
        x = max_sum * min_sum;
    }
    else {
        x = max_sum - min_sum;
    }

    x /= v;

    cout << "Result: " << x << endl;
    return x;
}

void function_2(double x, double matrix[5][5]) {
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
        cout << endl;
    }
}

void function_3(double matrix[5][5], double result[5]) {
    for (int j = 0; j < 5; ++j) {
        double min1 = matrix[0][j];
        for (int i = 1; i < 5; ++i) {
            min1 = min(min1, matrix[i][j]);
        }
        result[j] = min1;
    }
}

void function_4(double result[5], list<Student>& students) {
    string names[7] = { "1", "2", "3", "4", "5", "6", "7" };
    string surnames[7] = { "10", "20", "30", "40", "50", "60", "70" };

    for (int i = 0; i < 7; ++i) {
        Student student;
        student.name = names[rand() % 7];
        student.surname = surnames[rand() % 7];
        if (i == 0) {
            student.balance = *max_element(result, result + 5);
        }
        else if (i == 6) {
            student.balance = *min_element(result, result + 5);
        }
        else if (i - 1 < 5) {
            student.balance = result[i - 1];
        }
        else {
            student.balance = 0;
        }
        students.push_back(student);
    }

    cout << "List: " << endl;
    for (const auto& student : students) {
        cout << student.name << " " << student.surname << " Balance: " << student.balance << endl;
    }
}

void help_f5(list<Student> ::reverse_iterator it, list<Student> ::reverse_iterator end, ofstream& file) {
    if (it == end) return;
    file << it->name << it->surname << "Balance" << it->balance << endl;
    help_f5(++it, end, file);


    void help_f5(const list<Student>&students, ofstream & file){
        for (const auto& student::students) {
            file << student.name << student.surname << "Balance" << student.balance << endl;
        }
    }
}
void function_5(list<Student>& students) {

    ofstream file("students.txt");

    if (!file.is_open()) {
        cout << "Failed" << endl;
        return;
    }
    if (6 % 2 == 0) {
        help_f5(students.rbegin(), students.rend(), file);
    }
    
    file.close();
}

void function_6() {
    ifstream file("students.txt");

    if (!file.is_open()) {
        cout << "Not found" << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();
}


int main() {
    srand(static_cast<unsigned>(time(0)));
    double x = function_1();
    double matrix[5][5];
    function_2(x, matrix);

    double result[5];
    function_3(matrix, result);

    list<Student> students;
    function_4(result, students);

    function_5(students);

    function_6();
}
