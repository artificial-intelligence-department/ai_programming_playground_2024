#include <iostream>
#include <algorithm>
#include <string.h>

const int VARIANT = 61;

double function_1()
{
    float a, b;
    int c, d, e;
    double f;
    std::cin >> a >> b;
    std::cin >> c >> d >> e;
    std::cin >> f;
    double* arr = new double[6];
    arr[0] = a;
    arr[1] = b;
    arr[2] = c;
    arr[3] = d;
    arr[4] = e;
    arr[5] = f;
    std::sort(arr, arr + 6);
    double sum_biggest = arr[3] + arr[4] + arr[5];
    double sum_smallest = arr[0] + arr[1] + arr[2];
    double x = 0;
    if (sum_biggest > sum_smallest * 4) 
        x = sum_biggest + sum_smallest;
    else if (sum_biggest > sum_smallest * 3) 
        x = sum_biggest / sum_smallest;
    else if (sum_biggest > sum_smallest * 2) 
        x = sum_biggest * sum_smallest;
    x /= VARIANT;
    std::cout << x << std::endl;
    return x;
}

double** function_2(double& x)
{
    srand(time(0)); // init randomizer
    double** matrix = new double*[5];
    for (int i = 0; i < 5; i++)
    {
        matrix[i] = new double[5];
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
        for (int j = 0; j < 5; j++)
        {
            matrix[i][j] = (matrix[i][j] + VARIANT + j - i) * (rand() % 100 + 1);
        }
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    return matrix;
}

double* function_3(double** tower)
{
    double* arr = new double[5];
    double min0, min1, min2, min3, min4;
    double min0a = tower[0][0], 
    min1a = tower[0][1], 
    min2a = tower[0][2], 
    min3a = tower[0][3], 
    min4a = tower[0][4];
    min0 = std::min({tower[0][0], tower[1][0], tower[2][0], tower[3][0], tower[4][0]});
    min1 = std::min({tower[0][1], tower[1][1], tower[2][1], tower[3][1], tower[4][1]});
    min2 = std::min({tower[0][2], tower[1][2], tower[2][2], tower[3][2], tower[4][2]});
    min3 = std::min({tower[0][3], tower[1][3], tower[2][3], tower[3][3], tower[4][3]});
    min4 = std::min({tower[0][4], tower[1][4], tower[2][4], tower[3][4], tower[4][4]});
    for (int i = 0; i < 5; i++)
    {
        if (min0a > tower[i][0]) min0a = tower[i][0];
    }
    for (int i = 0; i < 5; i++)
    {
        if (min1a > tower[i][1]) min1a = tower[i][1];
    }
    for (int i = 0; i < 5; i++)
    {
        if (min2a > tower[i][2]) min2a = tower[i][2];
    }
    for (int i = 0; i < 5; i++)
    {
        if (min3a > tower[i][3]) min3a = tower[i][3];
    }
    for (int i = 0; i < 5; i++)
    {
        if (min4a > tower[i][4]) min4a = tower[i][4];
    }
    if (min0 == min0a && min1 == min1a && min2 == min2a && min3 == min3a && min4 == min4a)
    {
        std::cout << "Mins are equal" << std::endl;
    }
    else
    {
        std::cout << "Mins are not equal" << std::endl;
    }
    arr[0] = min0;
    arr[1] = min1;
    arr[2] = min2;
    arr[3] = min3;
    arr[4] = min4;
    return arr;
}

struct Student
{
    std::string name;
    std::string surname;
    double money;
};

struct Node
{
    Student value;
    Node* next = NULL;
    Node* prev = NULL;
};

Node* function_4(double* arr)
{
    Node* head = new Node{};
    Node* curr = head;
    for (int i = 1; i < 7; i++)
    {
        curr->next = new Node{Student(), NULL, curr};
        curr = curr->next;
    }
    curr = head;
    while (curr != NULL)
    {
        curr->value.name = "Aaaaaaaaaa";
        curr->value.surname = "Aaaaaaaaaa";
        curr->value.name[0] = (char)(rand() % 26 + 0x41);
        for (int i = 1; i < 10; i++)
        {
            curr->value.name[i] = (char)(rand() % 26 + 0x61);
        }
        curr->value.surname[0] = (char)(rand() % 26 + 0x41);
        for (int i = 1; i < 10; i++)
        {
            curr->value.surname[i] = (char)(rand() % 26 + 0x61);
        }
        curr = curr->next;
    }
    curr = head;
    curr->value.money = *(std::max_element(arr, arr + 5));
    curr = curr->next;
    for (int i = 0; i < 5; i++)
    {
        curr->value.money = arr[i];
        curr = curr->next;
    }
    curr->value.money = *(std::min_element(arr, arr + 5));
    curr = head;
    while (curr != NULL)
    {
        std::cout << curr->value.name << " " 
            << curr->value.surname << " " 
            << curr->value.money << std::endl;
        curr = curr->next;
    }
    return head;
}

int main() 
{
    double x = function_1();
    double** tower = function_2(x);
    double* arr = function_3(tower);
    Node* ll = function_4(arr);
}