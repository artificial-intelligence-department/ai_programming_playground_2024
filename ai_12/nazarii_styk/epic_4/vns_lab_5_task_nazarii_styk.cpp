#include <iostream>
#include <string>

using namespace std;

// Функція для перевірки, чи можна розбити рядок на підстрічки довжиною N
bool canFormMatrix(const string& str, int N) 
{
    if (str.length() != N * N) 
    {
        return false;
    }

    // Створення двовимірного масиву N x N
    char matrix[100][100]; // Припускаємо, що N <= 100

    // Заповнення двовимірного масиву
    int index = 0;
    for (int i = 0; i < N; ++i) 
    {
        for (int j = 0; j < N; ++j) 
        {
            matrix[i][j] = str[index++];
        }
    }

    // Перевірка, чи елементи першого стовпця розташовані в порядку зростання
    for (int i = 1; i < N; ++i) 
    {
        if (matrix[i][0] < matrix[i - 1][0]) 
        {
            return false;
        }
    }

    return true;
}

int main() 
{
    string input;
    int N;

    // Введення рядка та значення N
    cout << "Enter the string: ";
    cin >> input;
    cout << "Enter the value of N: ";
    cin >> N;

    // Перевірка, чи можна розбити рядок на підстрічки довжиною N і розташувати їх у порядку зростання в першому стовпці
    if (canFormMatrix(input, N)) 
    {
        cout << "Yes, it is possible to form the matrix with the first column in ascending order." << endl;
    } 
    else 
    {
        cout << "No, it is not possible to form the matrix with the first column in ascending order." << endl;
    }

    return 0;
}