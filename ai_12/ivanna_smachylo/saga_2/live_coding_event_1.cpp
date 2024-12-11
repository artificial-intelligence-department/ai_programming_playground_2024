#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <cmath>
#include <bits/stdc++.h>
#include <stdlib.h>

using namespace std;

struct Node
{
    string name;
    string lastname;
    double wealth;
    Node* prev;
    Node* next;
};

double function_1()
{
    double a, b; // в коді використана як мінімум одна дійсна змінна
    cout << "Введіть два дійсних числа: " << "\n"; // в коді використано оператори виведення та введення даних
    cin >> a >> b;

    int c, d, e; // в коді використана як мінімум одна цілочисельна змінна
    cout << "Введіть три цілі числа: " << "\n";
    cin >> c >> d >> e;

    float f; // в коді використана як мінімум одна дійсний з подвійною точністю змінна
    cout << "Введіть одне дійсне число з подвійною точністю: " << "\n";
    cin >> f;

    double array[6] = {a, b, c, d, e, f}; // в коді використаний одновимірний масив 
    sort(array, array + 6); // сортую свій одновимірний масив(таким чином він буде посортований від найменшого до найбільшого елемента)

    double min1 = array[0];
    double min2 = array[1];
    double min3 = array[2];

    double max1 = array[5];
    double max2 = array[4];
    double max3 = array[3];

    cout << min1 << ", " << min2 << ", " << min3 << ", " << max3 << ", " << max2 << ", " << max1 << "\n";

    double sumMax = max3 + max2 + max1;
    double sumMin = min1 + min2 + min3;

    double answer = 0.0;
    const double variant = 51.0; // в коді використана як мінімум одна цілочисельна константа

    if(sumMax > sumMin * 2.0) // в коді використані умовні оператори та розгалуження
    {
        answer = sumMax * sumMin;
    }
    else if(sumMax > sumMin * 3.0)
    {
        answer = sumMax / sumMin;
    }
    else if(sumMax > sumMin * 4.0)
    {
        answer = sumMax + sumMin;
    }

    double x = answer / variant;
    cout << "Результат: " << x << "\n";
    return x;
}

double** function_2(double &x) // в коді використано вказівники
{
    const int size = 5;
    double** tower = new double*[size]; // в коді використаний двовимірний масив 
    for(int i = 0; i < size; i++) // в коді використаний for цикл 
    {
        tower[i] = new double[size];
        for(int j = 0; j < size; j++)
        {
            tower[i][j] = x;
        }
    }

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            double r = ((double)rand() / RAND_MAX) * 99 + 1;
            tower[i][j] = (tower[i][j] + 51 + j - i) * r; // в коді використано математичні операції та математичні функції
        }
    }

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            cout << tower[i][j] << " ";
        }
        cout << "\n";
    }
    return tower;
}

double* function_3(double** tower)
{
    double* arr = new double[5];
    for(int i = 0; i < 5; i++)
    {
        int minElem = tower[0][i];
        for(int j = 0; j < 5; j++)
        {
            if(tower[j][i] < minElem)
            {
                minElem = tower[j][i];
            }
        }
        arr[i] = minElem;
    }

    for(int i = 4; i > 0; i--)
    {
        for(int j = 0; j < 5; j++)
        {
            if(tower[i][j] < tower[i - 1][j])
            {
                swap(tower[i][j], tower[i - 1][j]);
            }
        }
    }

    bool symmetric = 0;
    for(int i = 0; i < 5; i++)
    {
        if(arr[i] != tower[0][i])
        {
            symmetric = false;
        }
    }
    if(symmetric)
    {
        cout << "Результат пошуку співпадає!" << "\n";
    }
    else
    {
        cout << "Результат пошуку не співпадає!" << "\n";
    }

    return arr;
}

Node* function_4(double* smallest)
{
    Node* first = new Node();
    Node* second = new Node();
    Node* third = new Node();
    Node* fourth = new Node();
    Node* fifth = new Node();
    Node* sixth = new Node();
    Node* seventh = new Node();

    double sum = 0.0;
    for(int i = 0; i < 5; i++)
    {
        sum += smallest[i];
    }

    first->name = "Alex";
    first->lastname = "Turner";
    first->wealth = *max_element(smallest, smallest + 5);
    first->prev = nullptr;
    first->next = second;

    second->name = "Amanda";
    second->lastname = "Seyfried";
    second->wealth = sum;
    second->prev = first;
    second->next = third;

    third->name = "Mark";
    third->lastname = "Barry";
    third->wealth = sum;
    third->prev = second;
    third->next = fourth;

    fourth->name = "Alvaro";
    fourth->lastname = "Morte";
    fourth->wealth = sum;
    fourth->prev = third;
    fourth->next = fifth;

    fifth->name = "Kristine";
    fifth->lastname = "Froseth";
    fifth->wealth = sum;
    fifth->prev = fourth;
    fifth->next = sixth;

    sixth->name = "Diana";
    sixth->lastname = "Silvers";
    sixth->wealth = sum;
    sixth->prev = fifth;
    sixth->next = seventh;

    seventh->name = "Gilbert";
    seventh->lastname = "Blyth";
    seventh->wealth = *min_element(smallest, smallest + 5);
    seventh->prev = sixth;
    seventh->next = nullptr;

    Node* current = first;
    do // в коді використаний do while цикл
    {
        cout << current->name << " " << current->lastname << " " << current->wealth << "\n";
        current = current->next;
    } while (current != nullptr);

    return first;
}

void help_for_function_5(ofstream &file, Node* current, bool odd)
{
    while(current != nullptr) // в коді використаний while цикл
    {
        file << current->name << " " << current->lastname << " " << current->wealth << "\n";
        current = current->next;
    }
}

void function_5(Node* current)
{
    int variant = 51;
    ofstream file("students.txt");
    if(file.is_open())
    {
        if(variant % 2 == 0)
        {
            while(current->next != nullptr)
            {
                current = current->next;
            }
            help_for_function_5(file, current, true);
        }
        file.close();
    }
    else
    {
        cout << "Помилка відкриття файлу!" << "\n";
    }
}

void function_5()
{
    ifstream file("students.txt");
    if(file.is_open())
    {
        string line;
        while(getline(file, line))
        {
            cout << line << "\n";
        }
        file.close();
    }
    else
    {
        cout << "Помилка відкриття файлу!" << "\n";
    }
}

int main()
{
    const int size = 5;
    double x = function_1();
    double** tower = function_2(x);
    double* smallest = function_3(tower);
    Node* head = function_4(smallest);
    function_5(head);
    function_5();

    remove("students.txt");
    return 0;
}