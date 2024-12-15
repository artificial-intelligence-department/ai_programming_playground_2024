#include <iostream>
#include <algorithm> 
#include <ctime>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

const int VARIANT = 75;

struct Student {
    string firstName;
    string lastName;
    double balance;
    Student* next;
    Student* prev;
    Student(string fName, string lName, double bal)
        : firstName(fName), lastName(lName), balance(bal), next(nullptr), prev(nullptr) {}
};

double function_1() {
    float a, b;
    int c, d, e;
    double f;

    cin >> a >> b;
    cin >> c >> d >> e;
    cin >> f;

    double values[6] = {a, b, static_cast<double>(c), static_cast<double>(d), static_cast<double>(e), f};
    sort(values, values + 6);

    double sumMax = values[3] +  values[4] + values[5];
    double sumMin = values[0] +  values[1] + values[2];

    double result;
    
    if (sumMax > sumMin*2) {
        result = sumMax*sumMin;
    }
    else if (sumMax > sumMin*3) {
        result = sumMax/sumMin;
    }
    else if (sumMax > sumMin*4) {
        result = sumMax + sumMin;
    }

    result /= VARIANT;
    cout << "Result of function_1: " << result << endl;

    return result;

}

double **function_2(double& x) {
    double **matrix = new double *[5];
    for (int i = 0; i < 5; i++) {
        matrix[i] = new double[5];
        for (int j = 0; j < 5; j++) {
            matrix[i][j] = x;
        }
    }

    srand(time(0));
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int randValue = rand() % 100 + 1;
            matrix[i][j] = (matrix[i][j] + VARIANT + j - i)*randValue;
        }
    }

    cout << "New matrix: " << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << setw(10) << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return matrix;
}

double *function_3(double **tower) {
    double *resultArray = new double[5];
    double *alternateResult = new double[5];

    for (int j = 0; j < 5; j++) {
        double column[5];
        for (int i = 0; i < 5; i++) {
            column[i] = tower[i][j];
        }
    

        // Selection sort
        for (int i = 0; i < 4; i++) {
            for (int k = i + 1; k < 5; k++) {
                if (column[k] < column[i]) {
                    swap(column[i], column[k]);
                }
            }
        }
        resultArray[j] = column[0];
    }

    // Bubble Sort
    for (int j = 0; j < 5; j++) {
        double column[5];
        for (int i = 0; i < 5; i++) {
            column[i] = tower[i][j];
        }

        for (int i = 0; i < 5; i++) {
            for (int k = 0; k < 4 - i; k++) {
                if (column[k] > column[k + 1]) {
                    swap(column[k], column[k + 1]);
                }
            }
        }
        alternateResult[j] = column[0];
    }

    for (int j = 0; j < 5; j++) {
        if (resultArray[j] == alternateResult[j]) {
            cout << "Results match" << endl;
        }
        else {
            cout << "Results do not match" << endl;
        }
    }

    return resultArray;
}

Student* function_4(double* resultArray) {
    string firstName[7] = {"Павло", "Ірина", "Михайло", "Катерина", "Дмитро", "Олена", "Андрій" };
    string lastName[7]  = {"Коваленко", "Шевченко", "Бондаренко", "Петренко", "Сидоренко", "Бондар", "Ткаченко" };

    Student* head = nullptr;
    Student* tail = nullptr;

    double maxElement = resultArray[0];
    for (int i = 1; i < 5; i++) {
        if (resultArray[i] > maxElement) {
            maxElement = resultArray[i];
        }
    }

    double minElement = resultArray[0];
    for (int i = 1; i < 5; i++) {
        if (resultArray[i] < minElement) {
            minElement = resultArray[i];
        }
    }

    double sums[5];
    sums[0] = resultArray[0];
    for (int i = 1; i < 5; i++) {
        sums[i] = sums[i - 1] + resultArray[i];
    }


    for (int i = 0; i < 7; i++) {
        Student* newStudent = new Student(firstName[i], lastName[i], (i == 0 ? maxElement : (i == 6 ? minElement : sums[i - 1])));

        if (head == nullptr) {
            head = newStudent;
            tail = newStudent;
        }
        else {
            tail->next = newStudent;
            newStudent->prev = tail;
            tail = newStudent;
        }

    }

    cout << "List of students: " << endl;
    Student* current = head;
    while (current) {
        cout << current->firstName << " " << current->lastName << " - Balance: " << current->balance << endl;
        current = current->next;
    }

    return head;
}

void help_for_function_5(Student* head) {
    ofstream outputFile("students.txt");
    if (!outputFile) {
        cout << "Failed to open file for writing" << endl;
        return;
    }

    Student* current = head;
    while (current) {
            outputFile << current->firstName << " " << current->lastName << " - Balance: " << current->balance << endl;
            current = current->next;
        }
    outputFile.close();

}

void function_5(Student* head) {
    help_for_function_5(head);

    ifstream inputFile("students.txt");
    if (!inputFile) {
        cout << "File was not found" << endl;
        return;
    }

    string line;
    cout << "Data from file: " << endl;
    while(getline(inputFile, line)) {
        cout << line << endl;
    }
    inputFile.close();
}


int main() {
    double x = function_1();
    double **tower = function_2(x);

    double *resultArray = function_3(tower);

    Student* head = function_4(resultArray);

    function_5(head);

    Student* current = head;
    while (current) {
        Student* next = current->next;
        delete current;
        current = next;
    }

    for (int i = 0; i < 5; i++) {
        delete[] tower[i];
    }

    delete[] tower;

    delete[] resultArray;

    return 0;
}