#include <iostream>
#include <cmath>
#include <algorithm>
#include <fstream>
using namespace std;

const int VARIANT = 69; // цілочисельна константа

struct Student // свою структуру даних
{
    string name;
    string surname;
    double amount;
    Student() : name(""), surname(""), amount(0) {}
};

struct Node
{
    Student st;
    Node *prev;
    Node *next;
    Node(Student s) : st(s), prev(nullptr), next(nullptr) {}
};

double function_1()
{
    double a, b, f; // дійсна змінна
    int c, d, e;    // цілочисельна змінна
    cout << "Enter 3 double values: " << endl;
    cin >> a >> b >> f;
    // математичні операції та математичні функції
    f = round(f * 100) / 100; // дійсна з подвійною точністю змінна
    cout << "Enter 3 int values: " << endl;
    cin >> c >> d >> e;
    double nums[6] = {a, b, double(c), double(d), double(e), f};
    sort(nums, nums + 6);
    double max_sum = nums[5] + nums[4] + nums[3];
    double min_sum = nums[0] + nums[1] + nums[2];

    double x;
    // умовні оператори та розгалуження
    if (max_sum > min_sum * 4)
        x = max_sum + min_sum;
    else if (max_sum > min_sum * 3)
        x = max_sum / min_sum;
    else if (max_sum > min_sum * 2)
        x = max_sum * min_sum;
    else
        x = max_sum - min_sum;
    x /= double(VARIANT);
    return x;
}

double **function_2(double &x)
{
    double **matrix = new double *[5]; // двовимірний масив
    for (int i = 0; i < 5; i++)        // for цикл
    {
        matrix[i] = new double[5];
        for (int j = 0; j < 5; j++)
            matrix[i][j] = x;
    }

    cout << "Original matrix" << endl;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            matrix[i][j] = (matrix[i][j] + VARIANT + i - j) * (rand() % 100 + 1);
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return matrix;
}

double *function_3(double **matrix)
{
    double *min_el = new double[5]; // одновимірний масив
    for (int i = 0; i < 5; i++)
    {
        double min1, min2;
        min1 = matrix[0][i];
        double temp[5];
        for (int j = 0; j < 5; j++)
        {
            min1 = (min1 < matrix[j][i]) ? min1 : matrix[j][i];
            temp[j] = matrix[j][i];
        }

        min2 = *min_element(temp, temp + 5);

        if (min1 != min2)
            cout << "min elements in col " << i << " don't match" << endl;

        min_el[i] = min2;
    }
    return min_el;
}

Node *function_4(double *m)
{
    Student group[7];
    string names[7] = {"name1", "name2", "name3", "name4", "name5", "name6", "name7"};
    string surnames[7] = {"surname1", "surname2", "surname3", "surname4", "surname5", "surname6", "surname7"};
    for (int i = 0; i < 7; i++)
    {
        group[i].name = names[i];
        group[i].surname = surnames[i];
    }

    Node *head = new Node(group[0]);
    head->st.amount = *max_element(m, m + 5);
    Node *current = head;
    for (int i = 1; i < 7; i++)
    {
        Node *newNode = new Node(group[i]);
        current->next = newNode;
        newNode->prev = current;
        current = newNode;
        current->st.amount = m[i - 1];
    }
    current->st.amount = *min_element(m, m + 5);
    current = head;
    cout << "Elements from list" << endl;
    while (current) // while цикл
    {
        cout << current->st.name << " " << current->st.surname << " " << current->st.amount << endl;
        current = current->next;
    }

    return head;
}

void help_for_function_5(ofstream &file, Node *head) // перевантаження функції, рекурсивну функцію
{
    if (head)
        help_for_function_5(file, head->next);
    else
        return;

    file << head->st.name << " " << head->st.surname << " " << head->st.amount << endl;
}

void help_for_function_5(ofstream &file, Node *head, bool t) // перевантаження функції
{
    Node *current = head;
    do
    {
        file << current->st.name << " " << current->st.surname << " " << current->st.amount << endl; // функції роботи з файлами, для того, щоб записати у файл
        current = current->next;
    } while (current); // do while цикл
}

void function_5(Node *head)
{
    ofstream file("file.txt", ios::out);
    if (VARIANT % 2 == 0)
        help_for_function_5(file, head);
    else
        help_for_function_5(file, head, true);

    file.close();
}

void function_6()
{
    ifstream file("file.txt");
    if (!file)
    {
        cout << "Can't open the file" << endl;
        return;
    }

    cout << "Elements from file" << endl;
    string s;
    while (getline(file, s)) // функції роботи з файлами, для того, щоб зчитати з файлу
        cout << s << endl;

    file.close();
}

int main()
{
    double x = function_1();
    double **tower = function_2(x);
    double *min_el = function_3(tower);
    Node *head = function_4(min_el);
    function_5(head);
    function_6();

    for (int i = 0; i < 5; i++)
        delete[] tower[i];
    delete[] tower;
    delete[] min_el;
    
    return 0;
}