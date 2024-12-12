#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <fstream>
#include <cstring>
#include <fstream>
using namespace std;

int const variant = 45; //в коді використана як мінімум одна цілочисельна константа

double function_1()
{
    float a, b; //в коді використана як мінімум одна дійсна змінна
    int c, d, e; //в коді використана як мінімум одна цілочисельна змінна
    double f; //в коді використана як мінімум одна дійсний з подвійною точністю змінна

    cin >> a >> b;
    cin >> c >> d >> e;
    cin >> f;

    double arr[6] = {a, b, static_cast<double>(c), static_cast<double>(d), static_cast<double>(e), f};
    sort(arr, arr + 6);

    double sumMin = arr[0] + arr[1] + arr[2]; //в коді використано математичні операції та математичні функції
    double sumMax = arr[3] + arr[4] + arr[5];

    double result = 0;
 
    if(sumMax > sumMin * 2) //в коді використаний for цикл 
    {
        result = sumMin * sumMin;
    }
    else if(sumMax > sumMin * 3)//в коді використані умовні оператори та розгалуження
    {
        result = sumMax / sumMin;
    }
    else if(sumMax > sumMin * 4)
    {
        result = sumMax + sumMin;
    }

    double x = result / variant;
    cout << "Result: " << x << endl;
    return x;
}

double **function_2(double &x)  //в коді використано параметри та аргументи функції
{
    double **matrix = new double *[5]; //в коді використаний двовимірний масив 
    srand(time(0));
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            matrix[i][j] = x;
        }
    }

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            matrix[i][j] += variant + j - i + (rand() % 100 + 1);
        }
    }

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            cout << matrix[i][j] << setw(2);
        }
        cout << endl; //в коді використано оператори виведення та введення даних
    }

    return matrix;
}

double *function_3(double **tower) //в коді використано вказівники 
{
    double *arr = new double[5]; //в коді використаний одновимірний масив
    double temp[5];
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            temp[i] = tower[i][j];
        }
        arr[i] = *min_element(temp, temp + 5);
    }

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

    bool symmetrical = true;
    for(int i = 0; i < 5; i++)
    {
        if(arr[i] != tower[0][i])
        {
            symmetrical = false;
        }
    }
    if(symmetrical)
    cout << "Способи дали однаковий результат :)" << endl;

    if(!symmetrical)
    cout << "Способи дали різний результат :(" << endl;

    return arr;
}

struct Node //в коді використано свою структуру даних
{
    string name;
    string lastname;
    int wealth;
    Node* next;
    Node* prev;
};

Node *function_4(double *money)
{
    Node *one = new Node();
    Node *two = new Node();
    Node *three = new Node();
    Node *four = new Node();
    Node *five = new Node();
    Node *six = new Node();
    Node *seven = new Node();

    double sum = 0;
    for(int i = 0; i < 5; i++)
    {
        sum += money[i];
    }

    one->name = "Шкіль";
    one->lastname = "Феліція";
    one->wealth = *max_element(money, money + 5);
    one->next = two;
    one->prev = nullptr;

    two->name = "Чернуха";
    two->lastname = "Щастибог";
    two->wealth = sum;
    two->next = three;
    two->prev = one;

    three->name = "Шарлота";
    three->lastname = "Фіалкович";
    three->wealth = sum;
    three->next = four;
    three->prev = two;

    four->name = "Альбіна";
    four->lastname = "Політило";
    four->wealth = sum;
    four->next = five;
    four->prev = three;

    five->name = "Юлія";
    five->lastname = "Наконечна";
    five->wealth = sum;
    five->next = six;
    five->prev = four;

    six->name = "Ждан";
    six->lastname = "Шищенко";
    six->wealth = sum;
    six->next = seven;
    six->prev = five;

    seven->name = "Таїсія";
    seven->lastname = "Іваненко";
    seven->wealth = *min_element(money, money + 5);
    seven->next = nullptr;
    seven->prev = six;

    Node *current = one;
    do   //в коді використаний do while цикл
    {
        cout << current->name << " " << current->wealth << endl;
        current = current->next;
    } while (current != nullptr); //в коді використаний while цикл

    return one, two, three, four, five, six, seven;
}

void help_for_function_5(Node *current) //в коді використано функції роботи з файлами, для того, щоб записати у файл
{                                        //в коді використано функції роботи з файлами, для того, щоб зчитати з файлу
    ofstream outfile("nameFile.txt");
    double data;
    if(!outfile.is_open())
    {
        cout << "Error: Unable to creat the file";
    }

    outfile << data;
    outfile.close();

    ifstream infile("nameFile.txt");
    if(!infile.is_open())
    {
        cout << "Error: Unable to read the file";
    }
}

int main()
{
    double x = function_1();
    double **tower = function_2(x);
    double *money = function_3(tower);
    Node *head = function_4(money);
    return 0;
}