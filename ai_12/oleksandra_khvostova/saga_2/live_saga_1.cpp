#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

const int variant = 5;

float function_1() {
    float a, b;
    cout << "Введіть два дійсних значення: ";
    cin >> a >> b;

    int c, d, e;
    cout << "Введіть три цілих значення: ";
    cin >> c >> d >> e;

    double f;
    cout << "Введіть значення double: ";
    cin >> f;

    double forSort[6] = {a, b, static_cast<double>(c), static_cast<double>(d), static_cast<double>(e), f};

    for (int step = 0; step < 6 - 1; step++) {
        int min_idx = step;
        for (int i = step + 1; i < 6; i++) {
            if (forSort[i] < forSort[min_idx])
                min_idx = i;
        }
        swap(forSort[min_idx], forSort[step]);
    }

    double summ = 0, sumM = 0;
    int i = 0;
    while (i != 3) {
        summ += forSort[i];
        i++;
    }
    do {
        sumM += forSort[i];
        i++;
    } while (i != 6);

    double result;
    if (sumM > summ * 4) 
        result = sumM + summ;
    else if (sumM > summ * 3)
        result = sumM / summ;
    else if (sumM > summ * 2)
        result = sumM * summ;
    else 
        result = 0; 

    float x = result / variant;
    return x;
}

float** function_2(float x) {
    float** matrix = new float*[5];
    for (int i = 0; i < 5; i++) {
        matrix[i] = new float[5];
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            matrix[i][j] = x;
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            matrix[i][j] += variant + j - i;
            matrix[i][j] *= 1 + rand() % 101;
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    return matrix;
}

float* function_3(float** tower) {
    float* array = new float[5];
    float array1[5], array2[5];

    for (int j = 0; j < 5; j++) {
        float min = tower[0][j];
        for (int i = 1; i < 5; i++) {
            if (tower[i][j] < min)
                min = tower[i][j];
        }
        array1[j] = min;
    }

    float tMatrix[5][5];
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            tMatrix[j][i] = tower[i][j];
        }
    }

    for (int i = 0; i < 5; i++) {
        sort(tMatrix[i], tMatrix[i] + 5);
        array2[i] = tMatrix[i][0];
    }

    bool equal = true;
    for (int i = 0; i < 5; i++) {
        if (array1[i] != array2[i]) 
            equal = false;
    }

    cout << (equal ? "Результати пошуку однакові" : "Пошук працює некоректно") << endl<<endl;

    for (int i = 0; i < 5; i++) {
        array[i] = array1[i];
    }

    sort(array, array+5);
    return array;
}

struct Student {
    string name;
    string surname;
    double money;

    Student* previous;
    Student* next;
};

void Write(Student* s0) {
    Student* current = s0;
    while (current != nullptr) {
        cout << current->name << " " << current->surname << " " << endl<<current->money << " "<<endl;
        current = current->next;
    }
    cout<<endl;
}

Student* function_4(float* array) {
    Student* s0 = new Student{"Sasha", "Khvostova", array[4], nullptr, nullptr};
    Student* s1 = new Student{"Sasha", "Tostova", array[1], s0, nullptr};
    s0->next = s1;
    Student* s2 = new Student{"Masha", "Tostova", array[1] + array[1], s1, nullptr};
    s1->next = s2;
    Student* s3 = new Student{"Masha", "Lotova", array[1] + array[2], s2, nullptr};
    s2->next = s3;
    Student* s4 = new Student{"Pasha", "Lotov", array[2] + array[3], s3, nullptr};
    s3->next = s4;
    Student* s5 = new Student{"Pasha", "Gotov", array[1] + array[3], s4, nullptr};
    s4->next = s5;
    Student* s6 = new Student{"Pasha", "Lotovoi", array[0], s5, nullptr};
    s5->next = s6;

    Write(s0);
    return s0;
}

void help_for_function_5(ofstream& outFile, Student* s0) {
    Student* current = s0;
    while (current != nullptr) {
        outFile << current->name << " " << current->surname << endl;
        outFile << current->money << endl << endl;
        current = current->next;
    }
}

void function_5(Student* s0) {
    ofstream outFile("students.txt");
    help_for_function_5(outFile, s0);
    outFile.close();

    ifstream inFile("students.txt");
    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }
    inFile.close();
}

int main() {
    float x = function_1();

    float** tower = function_2(x);
    float* array = function_3(tower);

    for (int i = 0; i < 5; i++) {
        delete[] tower[i];
    }
    delete[] tower;

    Student* s0 = function_4(array);
    function_5(s0);

    Student* current = s0;
    while (current != nullptr) {
        Student* temp = current;
        current = current->next;
        delete temp;
    }

    delete[] array;

    return 0;
}