#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int variant = 69;
double function_1()
{
    double a, b, f;
    int c, d, e;
    cin >> a >> b >> c >> d >> e >> f;
    f = round(100 * f) / 100;
    double arr[6] = {a, b, (double)c, (double)d, (double)e, f};
    for (int i = 0; i < 6; i++)
    {
        for (int j = i - 1; j < 6; j++)
        {
            if (arr[i] > arr[j])
            {
                swap(arr[i], arr[j]);
            }
        }
    }
    double sum_max = arr[3] + arr[4] + arr[5];
    double sum_min = arr[0] + arr[1] + arr[2];
    double x;
    if (sum_max > sum_min * 2)
    {
        x = sum_max * sum_min / variant;
    }
    else if (sum_max > sum_min * 3)
    {
        x = (sum_max / sum_min) / variant;
    }
    else if (sum_max > sum_min * 4)
    {
        x = (sum_max + sum_min) / variant;
    }
    cout << "x = " << x << endl;
    return x;
}

double (*function_2(double &x))[5]
{
    double arr[5][5];

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            arr[i][j] = x;
        }
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            arr[i][j] = (arr[i][j] + variant + i + j) * (rand() % 100 + 1);
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return arr;
}

double *function_3(double (*tower)[5])
{
    double arr[5];
    for (int i = 0; i < 5; i++)
    {
        double temp[5];
        for (int j = 0; j < 5; j++)
        {
            temp[i] = tower[i][j];
        }

        double min1 = *min_element(temp, temp + 5);
        double min2 = tower[0][i];
        for (int j = 1; j < 5; j++)
        {
            min2 = (min2 < tower[j][i]) ? min2 : tower[j][i];
        }
        if (min1 == min2)
        {
            cout << "Min elements of " << i << "col are equal" << endl;
        }
        else
        {
            cout << "Min elements arent equal" << endl;
        }
        arr[i] = min1;
    }
    return arr;
}

struct student
{
    char name[40];
    char surname[40];
    double amount;
};

struct Node
{
    student data;
    Node *next;
    Node *prev;
    Node(student value) : data(value), prev(nullptr), next(nullptr) {};
};

void function_4()
{
    student students[7];
    Node* nodes[7];
    for (int i = 0; i < 7; i++)
    {
        nodes[i] = new Node(students[i]);
    }
    
}

int main()
{
    double x = function_1();

    double(*tower)[5] = function_2(x);

    double *min_el = function_3(tower);

    return 0;
}