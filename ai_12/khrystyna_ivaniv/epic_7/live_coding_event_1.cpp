#include <iostream>
#include <algorithm>
#include <ctime>
#include <string>
#include <fstream>

using namespace std;

const int var = 37; // цілочисельна константа

float function_1()
{

    float a, b; // дійсна змінна
    cin >> a >> b; // оператор введення даних
    int c, d, e; // цілочисельна змінна
    cin >> c >> d >> e;
    double f;
    cin >> f; // одна дійсна з подвійною точністю змінна

    double array[6]; // одновимірний масив
    array[0] = a;
    array[1] = b;
    array[2] = c;
    array[3] = d;
    array[4] = e;
    array[5] = f;

    sort(array, array + 6);

    double array1[3];
    array1[0] = array[0];
    array1[1] = array[1];
    array1[2] = array[2];

    double sum_smaller = 0;
    for (int i = 0; i < 3; i++) // for цикл
    {
        sum_smaller += array1[i];
    }

    double array2[3];
    array2[0] = array[3];
    array2[1] = array[4];
    array2[2] = array[5];

    double sum_bigger = 0;
    for (int i = 0; i < 3; i++)
    {
        sum_bigger += array2[i];
    }

    double result = 0;
    if (sum_bigger > sum_smaller * 4) // умовні оператори та розгалуження
    {
        result = sum_bigger + sum_smaller;
    }
    if (sum_bigger > sum_smaller * 3) // математичні операції та математичні функції
    {
        result = sum_bigger / sum_smaller;
    }
    if (sum_bigger > sum_smaller * 2)
    {
        result = sum_bigger * sum_smaller;
    }

    float x = result / float(var);
    cout << "x = " << x << endl; // оператор виведення даних

    return x;
}

float **function_2(float &x) //параметри та аргументи функції
{
    int size = 5;
    float **arraymatrix = new float *[size]; // двовимірний масив
    for (int i = 0; i < size; i++)
    {
        arraymatrix[i] = new float[size];
        for (int j = 0; j < size; j++)
        {
            arraymatrix[i][j] = x;
        }
    }

    srand(time(0));
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            arraymatrix[i][j] = (arraymatrix[i][j] + float(var) + float(j) + float(i)) * float(rand() % 100 + 1);
        }
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << arraymatrix[i][j] << " ";
        }
        cout << endl;
    }

    return arraymatrix;
}

double *function_3(float **tower) // вказівники
{
    double *array = new double[5];
    double *array1 = new double[5];

    for (int i = 0; i < 5; i++)
    {
        double min = tower[0][i];
        for (int j = 0; j < 5; j++)
        {
            if (tower[j][i] < min)
            {
                min = tower[j][i];
            }
        }
        array[i] = min;
    }

    for (int i = 0; i < 5; i++)
    {
        double temp[5];
        for (size_t j = 0; j < 5; j++)
        {
            temp[j] = tower[j][i];
        }

        sort(temp, temp + 5);

        for (size_t j = 0; j < 5; j++)
        {
            tower[j][i] = temp[j];
        }
    }

    for (int i = 0; i < 5; i++)
    {
        array1[i] = tower[0][i];
    }

    bool the_same = true;
    for (int i = 0; i < 5; i++)
    {
        if (array[i] != array1[i])
        {
            the_same = false;
            break; // оператор break
        }
    }

    if (the_same)
    {
        cout << "Результати співпадають)" << endl;
    }
    else
    {
        cout << "Результати не співпадають(" << endl;
    }

    return array;
}

struct Node // структура даних
{
    string name;
    string surname;
    double balance;
    Node *next;
    Node *previous;
    Node(string _name, string _surname, double _balance) : name(_name), surname(_surname), balance(_balance), next(nullptr), previous(nullptr) {};
};

struct DoublyLinkedList
{
    Node *head;
    Node *tail;
};

double find_max(double *array)
{
    double max = array[0];
    for (int i = 0; i < 5; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }
    return max;
}

double find_min(double *array)
{
    double min = array[0];
    for (int i = 0; i < 5; i++)
    {
        if (array[i] < min)
        {
            min = array[i];
        }
    }
    return min;
}

DoublyLinkedList function_4(double *array)
{
    string names[7] = {"Alina", "Marta", "Nastya", "Viktoria", "Svyatoslav", "Ivan", "Roksolana"};
    string surnames[7] = {"A", "M", "N", "V", "S", "I", "R"};
    Node *head = new Node(names[0], surnames[0], find_max(array));
    Node *current = head;

    for (int i = 1; i < 6; i++)
    {
        double sum = 0;
        for (int j = 0; j < i; j++)
        {
            sum += array[j];
        }
        Node *newNode = new Node(names[i], surnames[i], sum);
        current->next = newNode;
        newNode->previous = current;
        current = newNode;
    }

    Node *tail = new Node(names[6], surnames[6], find_min(array));

    current->next = tail;
    tail->previous = current;
    current = head;

    do // do while цикл
    {
        cout << current->name << " " << current->surname << " " << current->balance << endl;
        current = current->next;
    } while (current);

    DoublyLinkedList result;
    result.head = head;
    result.tail = tail;
    return result;
}

void help_for_function_5(Node *students, ofstream &file)
{
    Node *current = students;
    while (current)
    {
        file << current->name << " " << current->surname << " " << current->balance << endl;
        current = current->next;
    }
}

void function_5(double *array)  // перевантаження функції(якщо змінти назву функції)
{
    DoublyLinkedList studentList = function_4(array);

    ofstream file("students.txt"); //запис у файл
    if (!file)
    {
        cerr << "Не вдалось відкрити файл для запису" << endl;
    }

    help_for_function_5(studentList.head, file); // рекурсивну функцію(якщо реалізовувати для парних варіантів) 
    file.close();

    ifstream in_file("students.txt"); // зчитування з файлу
     if (!in_file)
    {
        cerr << "Не вдалось відкрити файл" << endl;
    }

    string line;

    while(getline(in_file, line)){ // while цикл
        cout << line << endl;
    }
    file.close();
}

int main()
{
    float x = function_1(); 
    float **tower = function_2(x); //параметри та аргументи функції
    double *array = function_3(tower);
    for (int i = 0; i < 5; i++)
    {
        delete[] tower[i];
    }
    delete[] tower;

    DoublyLinkedList studentList = function_4(array);
    function_5(array);
    delete[] array;

    return 0;
}