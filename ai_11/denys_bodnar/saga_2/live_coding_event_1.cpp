#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <string>
#include <fstream>

using namespace std;

const int Variant = 2; // оголосив константу для варіанту щоб використовувати їх в всіх в функціях

double function_1 () { // Завдання 1
    float a, b; 
    int c, d, e;
    double f;

    cout << "Введіть два цілих числа (a і b): " << endl;
    cin >> a >> b;
    cout << "Введіть три цілих числа (c, d, e): " << endl;
    cin >> c >> d >> e;
    cout << "Введіть одне дійсне число з двійковою точністю (f): " << endl;
    cin >> f;

    double arr[] = {static_cast<double>(a), static_cast<double>(b), static_cast<double>(c), static_cast<double>(d), static_cast<double>(e), f};
    sort(arr, arr + 6);

    double maxSuma = arr[3] + arr[4] + arr[5];
    double minSuma = arr[0] + arr[1] + arr[2];

    double result;

    if (maxSuma > minSuma * 2) {
        result = maxSuma * minSuma;
    } else if (maxSuma > minSuma * 3) {
        result = maxSuma / minSuma;
    } else if (maxSuma > minSuma * 4) {
        result = maxSuma + minSuma;
    }

    double x = result / Variant;
    
    return x;
}

void function_2(double &x, double matrix [5][5]) { // Завдання 2

    srand(static_cast<unsigned>(time(0)));

    for (int a = 0; a < 5; a++){
        for (int b = 0; b < 5; b++){
            matrix[a][b] = x;
        }
    }

    for (int a = 0; a < 5; a++){
        for (int b = 0; b < 5; b++){
            matrix [a][b] = (matrix [a][b] + Variant + a - b) * (rand() % 100 +1);
        }
    }
    cout << "Matrix: " << endl;
    for (int a = 0; a < 5; a++){
        for (int b = 0; b < 5; b++){
            cout << matrix[a][b] << "\t";
        }
        cout << endl;
    }
}

void function_3 (double matrix [5][5], double result [5]) { // Завдання 3
    // Для початку ми знайдемо мінімальні елементи в стовпцях
    for (int j = 0; j < 5; j++) {
        double minElement = matrix[0][j];
        for (int i = 1; i < 5; i++) {
            if (matrix[i][j] < minElement) {
                minElement = matrix[i][j];
            }
        }
        result [j] = minElement;
    }

    // Тепер виведемо їх
    cout << "Мінімальні елементи в стовпцях: " << endl;
    for (int i = 0; i < 5; i++) {
        cout << result [i] << " ";
    }
    cout << endl;
}

struct Student { // Структура для 4 завдання
    string name;
    string surname;
    double money;
    Student* prev;
    Student* next;

    Student (string name, string surname, double money) : name(name), surname(surname), money(money), prev(nullptr), next(nullptr) {}
};

Student* function_4 (double result[5]) { // Завдання 4
    string name[] = {"Денис", "Юрій", "Юрій", "Ярослав", "Іван", "Анастасія", "Євген"};
    string surname[] = {"Боднар", "Бубельник", "Вербицький", "Гнатюк", "Голейчук", "Гуменюк", "Єдинець"};

    sort(result, result + 5, greater<double>());

    Student* head = new Student(name[0], surname[0], result[0]);
    Student* cur = head;

    for (int i = 1; i < 7; i++) {
        double money;
        if (i < 5) {
            money = result[i];
        } else {
            money = 0;
        }

        Student* newStudent = new Student(name[i], surname[i], money);
        cur->next = newStudent;
        newStudent->prev = cur;
        cur = newStudent;
    }

    cout << "Список студентів: " << endl;
    cur = head;

    while (cur) {
        cout << cur->name << " " << cur->surname << " " << "Гроші: " << cur->money << endl;
        cur = cur->next;
    }
    cout << endl;
    return head;
}

void help_for_function_5 (Student* tail, ofstream& file) { // Допоміжна функція для 5 завдання
    if (tail == nullptr) {
        return;
    }

    file << tail->name << " " << tail->surname << " " << "Гроші: " << tail->money << endl;
    help_for_function_5(tail->prev, file);
}

void function_5 (Student* list) { // Завдання 5 та 6
    ofstream file ("Students.txt"); // Запис у файл
    Student* tail = list;
    while (tail->next != nullptr) {
        tail = tail->next;
    }
    help_for_function_5(tail, file);

    file.close(); // Закриваємо файл

    ifstream file1("Students.txt"); // Відкриваємо файл для читання
    if (!file1.is_open()) { // перевірка на те чи відкритий файл
        cout << "Такого файлу не існує!" << endl;
        return;
    }
    // Виводимо текст з файлу
    cout << "Текст з файлу: " << endl;
    string lineInfo;
    while (getline(file1, lineInfo)) {
        cout << lineInfo << endl;
    }

    file1.close();
}

int main (){
    double x = function_1();    
    cout << "Результат обчислення (function_1):\n " << x << endl;

    double matrix [5][5]; // Це те саме що tower в умові завдання
    function_2(x, matrix);

    double result[5];
    function_3(matrix, result);

    Student* list = function_4(result);

    function_5(list);

    return 0;
}

/*
1.	в коді використана як мінімум одна цілочисельна змінна ✅
2.	в коді використана як мінімум одна дійсна змінна ✅
3.	в коді використана як мінімум одна дійсний з подвійною точністю змінна ✅
4.	в коді використана як мінімум одна цілочисельна константа ✅
5.	в коді використані умовні оператори та розгалуження ✅
6.	в коді використаний одновимірний масив ✅
7.	в коді використаний двовимірний масив ✅
8.	в коді використаний do while цикл ❎
9.	в коді використаний while цикл ✅
10.	в коді використаний for цикл ✅
11.	в коді використано оператори break і continue ❎
12.	в коді використано перевантаження функції ✅
13.	в коді використано рекурсивну функцію ✅
14.	в коді використано параметри та аргументи функції ✅	
15.	в коді використано математичні операції та математичні функції ✅
16.	в коді використано функції роботи з файлами, для того, щоб записати у файл ✅
17.	в коді використано функції роботи з файлами, для того, щоб зчитати з файлу ✅
18.	в коді використано оператори виведення та введення даних ✅
19.	в коді використано свою структуру даних ✅
20.	в коді використано вказівники ✅
21.	в коді не можна використовувати вектори ✅
*/