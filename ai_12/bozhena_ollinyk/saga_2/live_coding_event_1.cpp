#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdlib.h>
#include <fstream>

using namespace std;

// в коді використана як мінімум одна цілочисельна змінна
// в коді використана як мінімум одна дійсна змінна
// в коді використана як мінімум одна дійсний з подвійною точністю змінна
// в коді використана як мінімум одна цілочисельна константа
// в коді використані умовні оператори та розгалуження
// в коді використаний одновимірний масив
// в коді використаний двовимірний масив
// в коді використаний do while цикл
// в коді використаний while цикл
// в коді використаний for цикл
// в коді використано оператори break і continue
// в коді використано перевантаження функції
// в коді використано рекурсивну функцію
// в коді використано параметри та аргументи функції
// в коді використано математичні операції та математичні функції
// в коді використано функції роботи з файлами, для того, щоб записати у файл
// в коді використано функції роботи з файлами, для того, щоб зчитати з файлу
// в коді використано оператори виведення та введення даних
// в коді використано свою структуру даних
// в коді використано вказівники
// в коді не можна використовувати вектори

struct Node
{
    string name;
    string lastname;
    double wealth;
    Node *prev;
    Node *next;
};

double function_1()
{
    float a, b;
    int c, d, e;
    double f;

    cin >> a >> b;
    cin >> c >> d >> e;
    cin >> f;

    double arr[6] = {a, b, c, d, e, f}; // створюєм масив з введений користувачем значенб
    sort(arr, arr + 6);                 // сортуєм його по зростанню

    double min1, min2, min3, max1, max2, max3;
    min1 = arr[0];              // найменший елемент масиву перши
    max1 = arr[5];              // наібйльший елемент масиву останній
    for (int i = 1; i < 6; i++) // пошук другого найменшого елеенту, він йде далі по списку і має бути більшим за перший мінімум
    {
        if (arr[i] > min1)
        {
            min2 = arr[i];
            break;
        }
    }
    for (int i = 2; i < 6; i++)
    {
        if (arr[i] > min2)
        {
            min3 = arr[i];
            break;
        }
    }
    for (int i = 4; i >= 0; i--) // пошук другого найбільшого елеенту, він йде далі по списку і має бути меншим за перший мвксимум
    {
        if (arr[i] < max1)
        {
            max2 = arr[i];
            break;
        }
    }

    for (int i = 3; i >= 0; i--)
    {
        if (arr[i] < max2)
        {
            max3 = arr[i];
            break;
        }
    }

    cout << min1 << "  " << max1 << endl;
    cout << min2 << "  " << max2 << endl;
    cout << min3 << "  " << max3 << endl;

    double maxsum = max1 + max2 + max3;
    double minsum = min1 + min2 + min3;
    double sums;
    double result;
    const int var = 48;
    // перевіряєм умови і в залежності від тієї яка справдується шукаєм результат за заданою формулою, виводи його і повертаєм
    if (maxsum > minsum * 2)
    {
        if (maxsum > minsum * 3)
        {
            if (maxsum > minsum * 4)
            {
                sums = maxsum + minsum;
            }
            else
            {
                sums = maxsum / minsum;
            }
        }
        else
        {
            sums = maxsum * minsum;
        }
    }
    result = sums / var;
    cout << result << endl;
    return result;
}

double **function_2(double &x)
{
    // для коректної роботи функції рандом
    srand((unsigned)time(NULL));
    double **matrix = new double *[5];
    // задаєм всі елементам матриці значення х
    for (int i = 0; i < 5; i++)
    {
        matrix[i] = new double[5];
        for (int j = 0; j < 5; j++)
        {
            matrix[i][j] = x;
        }
    }
    // обчислюєм нове значення кожного елемента матриці за заданою формулою
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            double newVal = (matrix[i][j] + 48 + j - i) * ((rand() % 100) + 1);
            matrix[i][j] = newVal;
        }
    }
    // виводим матрицю
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return matrix;
}
double *function_3(double **tower)
{
    double *arr = new double[5];
    // шукаєм мінімальний елемент кожного стовпця через звичайну функцію мін і присвоюєм знайдене значення в масив арр
    for (int i = 0; i < 5; i++)
    {
        double temp[5];
        for (int j = 0; j < 5; j++)
        {
            temp[j] = tower[j][i];
        }
        arr[i] = *min_element(temp, temp + 5);
    }

    // шукаєм найменші елементи в стовпці бульбашковим методом, тобто найменші елементи стовпців знаходитимуться в першому рядку
    for (int i = 4; i > 0; i--)
    {
        for (int j = 0; j < 5; j++)
        {
            if (tower[i][j] < tower[i - 1][j])
            {
                swap(tower[i][j], tower[i - 1][j]);
            }
        }
    }
    // перевіряєм чи обидва способи пошуку дали той самий результат і виводим в консоль відповідь
    bool symmetric = true;
    for (int i = 0; i < 5; i++)
    {
        if (arr[i] != tower[0][i])
        {
            symmetric = false;
        }
    }
    if (symmetric)
    {
        cout << endl
             << "Обидва способи дали однаковий результат!" << endl
             << endl;
    }
    else
    {
        cout << endl
             << "Різні способи дали різний результат!" << endl
             << endl;
    }
    return arr;
}

Node *function_4(double *money)
{
    // свторюєм двозв'язний список з 7 елементів та заповнюєм значення кожного елемента
    Node *one = new Node();
    Node *two = new Node();
    Node *three = new Node();
    Node *four = new Node();
    Node *five = new Node();
    Node *six = new Node();
    Node *seven = new Node();

    double sum = 0;
    for (int i = 0; i < 5; i++)
    {
        sum += money[i];
    }

    one->name = "Dean";
    one->lastname = "Winchester";
    one->wealth = *max_element(money, money + 5);
    one->prev = nullptr;
    one->next = two;

    two->name = "Lucifer";
    two->lastname = "Morningstar";
    two->wealth = sum;
    two->prev = one;
    two->next = three;

    three->name = "Sponge";
    three->lastname = "Bob";
    three->wealth = sum;
    three->prev = two;
    three->next = four;

    four->name = "Adrian";
    four->lastname = "Agreste";
    four->wealth = sum;
    four->prev = three;
    four->next = five;

    five->name = "TV";
    five->lastname = "Girl";
    five->wealth = sum;
    five->prev = four;
    five->next = six;

    six->name = "Michael";
    six->lastname = "Jackson";
    six->wealth = sum;
    six->prev = five;
    six->next = seven;

    seven->name = "Dorian";
    seven->lastname = "Grey";
    seven->wealth = *min_element(money, money + 5);
    seven->prev = six;
    seven->next = nullptr;

    // виводим список
    Node *current = one;
    do
    {
        cout << current->name << " " << current->lastname << " " << current->wealth << endl;
        current = current->next;
    } while (current != nullptr);

    // повертаєм перший елемент списку
    return one;
}

void help_for_function_5(ofstream &file, Node *current)
{ // заисуєм у файл список задом наперед через рекурсивну функцію
    if (current != nullptr)
    {
        file << current->name << " " << current->lastname << " " << current->wealth << endl;
        help_for_function_5(file, current->prev);
    }
}

void help_for_function_5(ofstream &file, Node *current, bool unodd)
{ // записуєм список у файл в його оригінальному порядку через цикл
    while (current != nullptr)
    {
        file << current->name << " " << current->lastname << " " << current->wealth << endl;
        current = current->next;
    }
}

void function_5(Node *current)
{
    // створюєям файл та в залежності від варіанту записсуєм в нього список
    int var = 48;
    ofstream file("students.txt");
    if (file.is_open())
    {

        if (var % 2 == 0)
        {
            while (current->next != nullptr)
            {
                current = current->next;
            }
            cout << endl
                 << "Вивід з файлу якщо варіант парний: " << endl;
            help_for_function_5(file, current);
        }
        else
        {
            cout << endl
                 << "Вивід з файлу якщо варіант непарний: " << endl;
            help_for_function_5(file, current, true);
        }

        file.close();
    }
    else
    {
        cout << "Помилка відкриття файлу чи його створення!" << endl;
    }
}

void function_6()
{
    // відкриваєм файл та зчитуєм з нього список
    ifstream file("students.txt");
    if (file.is_open())
    {
        string line;

        while (getline(file, line))
        {
            cout << line << endl;
        }

        file.close();
    }
    else
    {
        cout << "Помилка відкриття файлу!" << endl;
    }
}

int main()
{
    double x = function_1();
    double **tower = function_2(x);
    double *money = function_3(tower);
    Node *head = function_4(money);
    function_5(head);
    function_6();

    remove("students.txt");
    return 0;
}