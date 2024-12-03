#include <iostream>
#include <stdlib.h> 
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;
#define CONSTT 54

void BubbleSort(double array[])
{
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 6 - i - 1; j++)
        {
            if (array[j] < array[j+1])
            {
                double temp = array[j+1];
                array[j+1] = array[j];
                array[j] = temp;
            }
        }
    }
}


int function_1()
{
    float a, b, x; // дійсні числа                  // 2. дійсна змінна
    int c, d, e; // цілі числа                      // 1. цілочислельна змінна
    double f; // дійсне число з подвійною точністю  // 3. дійсна з подвійною точністю змінна

    cout << "Введіть два дійсних числа: " << endl;
    cin >> a >> b;
    cout << "Введіть три цілих чсила: " << endl;
    cin >> c >> d >> e;
    cout << "Введіть дійсне число з подвійною точністю: " << endl;
    cin >> f;
    
    // знайти три найбільші, три найменші
    double numArray[6] = {a, b, c, d, e, f};  //6. одновимірний масив
    BubbleSort(numArray);

    for(int i = 0; i < 6; i ++)
    {
        cout << numArray[i] << " ";
    }
    cout << endl;

    double sumOfBigger, sumOfLess;
    sumOfBigger = numArray[0] + numArray[1] + numArray[2];
    sumOfLess = numArray[3] + numArray[4] + numArray[5];


    if(sumOfBigger > sumOfLess * 2)   // 5. умовні оператори та розгалуження
    {
        x = sumOfBigger * sumOfLess;
    }
    else if(sumOfBigger > sumOfLess * 3)
    {
        x = sumOfBigger / sumOfLess;
    }
    else if(sumOfBigger > sumOfLess * 4)
    {
        x = sumOfBigger + sumOfLess;
    }

    
    x = x / CONSTT;
    cout << "Значення х: " << x << endl;\

    return x;
}

// void UpdateMatrix(float matrix[][])
// {
//     for(int i = 0; i < 4; i++)
//     {
//         for(int j = 0; j < 4; j++)
//         {
//             matrix[i][j] = (matrix[i][j]+CONSTT + 2 − 55) ∗ rand(1,100); // 7. двовимірний масив
//         }
//     }
// }

// void PrintMatrix(float matrix[][])
// {
//     for(int i = 0; i < 4; i++)
//     {
//         for(int j = 0; j < 4; j++)
//         {
//             cout << matrix[i][j] << " ";
//         }
//         cout << endl;
//     }
// }

void function_2(float &x)
{
    float matrix[5][5];
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            matrix[i][j] = x;
        }
    }


    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            matrix[i][j] = (matrix[i][j]+CONSTT + 2 - 55); // 7. двовимірний масив
        }
    }

}




// Завдання 6
void function_5()
{
    string fileName = "file.txt";

    ifstream myFile(fileName);

    if(myFile.is_open())
    {
        string line;
        while (getline(myFile, line))
        cout << line << endl;
    }
    else
    {
        cout << "Помилка! Файл не знайдено!" << endl;
    }
}

int main()
{
    const int CONST = 54; // 4. цілочисельна константа
    float x = function_1();
    function_2;

    


    return 0;
}