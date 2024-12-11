#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <fstream>
#include <sstream>
using namespace std;
const int V = 66;
float function_1()
{
    float a, b;
    int c, d, e;
    double f;
    cout << "Input 2 floats, 3 ints and 1 double" << endl;
    cin >> a >> b >> c >> d >> e >> f;
    double nums[6] = {a, b, (double)c, (double)d, (double)e, f};
    sort(nums, nums + 6);
    double max_sum = 0, min_sum = 0;
    for (int i = 0; i < 3; i++)
    {
        min_sum += nums[i];
        max_sum += nums[5 - i];
    }
    float x = 0;
    if (max_sum > min_sum * 4)
        x = max_sum + min_sum;
    else if (max_sum > min_sum * 3)
        x = max_sum / min_sum;
    else if (max_sum > min_sum * 2)
        x = max_sum * min_sum;
    x /= V;
    cout << "Result: " << x << endl;

    return x;
}

float **function_2(float &x)
{
    float **matrix = new float *[5];
    for (int i = 0; i < 5; i++)
    {
        matrix[i] = new float[5];
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            matrix[i][j] = x;
        }
    }
    for (int i = 0; i < 5; i++)
    {
        cout << endl;
        for (int j = 0; j < 5; j++)
        {
            matrix[i][j] = matrix[i][j] + V + j - i * (rand() % 100 + 1);
            cout << matrix[i][j] << ' ';
        }
    }
    return matrix;
}
float *function_3(float **m)
{
    float *array = new float[5];
    float array2[5], min, column[5];
    for (int i = 0; i < 5; i++)
    {
        min = m[0][i];
        for (int j = 0; j < 5; j++)
        {
            if (min > m[j][i])
                min = m[j][i];
        }
        array[i] = min;
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            column[j] = m[j][i];
        }
        sort(column, column + 5);
        array2[i] = column[0];
    }
    bool equal = true;
    for (int i = 0; i < 5; i++)
    {
        if (array[i] != array2[i])
            equal = false;
    }
    if (equal)
        cout << endl
             << "Results are the same" << endl;
    else
        cout << endl
             << "OOps, results are different...";
    return array;
}
struct Node
{
    string name, surname;
    float money;
    Node *next = nullptr;
    Node *previous = nullptr;
};
struct DLL
{
    Node *head = nullptr;
    Node *tail = nullptr;
};
DLL function_4(float *array)
{
    DLL list;
    list.head = new Node;
    list.tail = list.head;
    cout << endl
         << "Input name, surname and money of 7 students" << endl;
    cin >> list.head->name >> list.head->surname;
    for (int i = 0; i < 6; i++)
    {
        Node *new_one = new Node;
        cin >> new_one->name >> new_one->surname;

        list.tail->next = new_one;
        new_one->previous = list.tail;
        list.tail = new_one;
    }
    sort(array, array + 5);
    list.head->money = array[4];
    list.tail->money = array[0];
    float sum = 0;
    Node *current = list.head->next;
    for (int i = 0; i < 5; i++)
    {
        sum += array[i];
        current->money = sum;
        current = current->next;
    }
    current = list.head;
    while (current != nullptr)
    {
        cout << endl;
        cout << current->name << ' ' << current->surname << ' ' << current->money;
        current = current->next;
    }
    return list;
}
void help_for_function_5(Node *current, fstream &file)
{
    file << current->money << ',' << current->surname << ',' << current->name << endl;
    if (current->previous != nullptr)
        help_for_function_5(current->previous, file);
}
void help_for_function_5(DLL list, fstream &file)
{
    Node *current = list.head;
    while (current != nullptr)
    {
        file << current->name << ',' << current->surname << ',' << current->money << endl;
        current = current->next;
    }
}
void function_5(DLL list)
{
    fstream MyFile("MyFile.txt", ios::out | ios::trunc);
    if (V % 2 == 0)
        help_for_function_5(list.tail, MyFile);
    else
        help_for_function_5(list, MyFile);
    MyFile.close();
}
void function_6()
{
    fstream MyFile("MyFile.txt", ios::in);
    if(!MyFile.is_open())
    {
        cerr << endl << "Error opening a file";
        return;
    }
    string line, word;
    cout << endl << endl << "Contents of file:"<< endl << endl;
    for (int i = 0; i < 7; i++)
    {
        getline(MyFile, line, '\n');
        stringstream ss(line);
        for(int i = 0; i < 3; i++){
            getline(ss, word, ',');
            cout << word << ' ';
        }
        cout << endl;
    }
}
int main()
{
    float x = function_1();
    float **tower;
    tower = function_2(x);
    float *array;
    array = function_3(tower);
    DLL list;
    list = function_4(array);
    function_5(list);
    function_6();
    return 0;
}