#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>

#define VARIANT 54
using namespace std;


// Завдання 1

void SortArray(double array[], int size)
{
    for (int i = 0; i < size - 1; i++) // 10. використаний for цикл 
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if(array[j] < array[j + 1])
            {
                double temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

float function_1()
{
    float a, b, x;  // Дійсні числа                         // 2. дійсна змінна
    int c, d, e;    // Цілі числа                           // 1. цілочисельна змінна
    double f;       // Дійсне число з подвійною точністю    // 3. дійсна з подвійною точністю змінна

    cout << "Введіть два дійсних числа з клавіатури: "; // 18. використано оператори виведення та введення даних
    cin >> a >> b;
    cout << "Введіть три цілих числа з клавіатури: ";
    cin >> c >> d >> e;
    cout << "Введіть одне число з подвійною точністю: ";
    cin >> f;

    double numArray[6] = {a, b, c + 0.0, d + 0.0, e + 0.0, f}; // 6. одновимірний масив 
    SortArray(numArray, 6);

    cout << "Відсортовані числа: " << endl;
    for (int i = 0; i < 6; i++)
    {
        cout << numArray[i] << " "; 
    }
    cout << endl;

    double sumOfBigger = numArray[0] + numArray[1] + numArray[2];
    double sumOfLess = numArray[3] + numArray[4] + numArray[5];

    if (sumOfBigger > sumOfLess * 4)    // 5. умовні оператори та розгалуження
    {
        x = sumOfBigger + sumOfLess;
    }
    else if(sumOfBigger > sumOfLess * 3)
    {
        x = sumOfBigger / sumOfLess;
    }
    else if(sumOfBigger > sumOfLess * 2)
    {
        x = sumOfBigger * sumOfLess;
    }
    else
    {
        x = 0.0;
    }

    x /= VARIANT;

    cout << "Значення x = " << x << endl;

    return x;

}


// Завдання 2

void PrintMatrix(float matrix[5][5])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

void function_2(float &x, float matrix[5][5])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            matrix[i][j] = x;
        }
    }

    cout << "Матриця зі значеннми х: " << endl;
    PrintMatrix(matrix);
    cout << endl;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            matrix[i][j] = (matrix[i][j] + VARIANT + j - i) * (rand() % 100 + 1); // 15. використано математичні операції та математичні функції
        }
    }

    cout << "Матриця з новими значеннми х: " << endl;
    PrintMatrix(matrix);
    cout << endl;
}


// Завдання 3

// 1-й Спосіб
float FindMinFirst(float martix[5][5], int column)
{
    float min = martix[0][column];
    for(int i = 0; i < 5; i++)
    {
        if (martix[i][column] < min)
        {
            min = martix[i][column];
        }
    }

    return min;
}

// 2-й Спосіб
float FindMinSecond(float martix[5][5], int column)
{
    float min = martix[0][column];
    for(int i = 0; i < 5; i++)
    {
        min = min < martix[i][column] ? min : martix[i][column];
    }

    return min;
}


void function_3(float matrix[5][5], float resultArray[5])
{
    for(int col = 0; col < 5; col++)
    {
        float min1 = FindMinFirst(matrix, col);
        float min2 = FindMinSecond(matrix, col);

        if (min1 == min2)
        {
            cout << "Результати співпадають" << endl;
        }
        else
        {
            cout << "Результати не співпадають" << endl;
        }

        resultArray[col] = min1;
    }
}

// Завдання 4
struct Student // 19. використано свою структуру даних
{
    string firstName;
    string lastName;
    float balance;
};

string getRandomFirstName()
{
    const string names[] = {"Іван", "Оксана", "Роман", "Микола", "Катерина", "Дмитро", "Софія"};
    return names[rand() % 7];
}

string getRandomLastName()
{
    const string lastNames[] = {"Шевченко", "Коваленко", "Мельник", "Іваненко", "Сидоренко", "Зінченко", "Мироненко"};
    return lastNames[rand() % 7];
}

void SortResult(float array[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if(array[j] < array[j + 1])
            {
                float temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

void function_4(float resultArray[5], Student students[7])
{
    SortResult(resultArray, 5);

    float max = resultArray[0];
    float min = resultArray[4];


    for (int i = 0; i < 7; i++)
    {
        students[i].firstName = getRandomFirstName();
        students[i].lastName = getRandomLastName();

        if (i == 0)
        {
            students[i].balance = max;
        }
        else if (i == 6)
        {
            students[i].balance = min;
        }
        else
        {
            students[i].balance = resultArray[i-1];
        }
    }

    cout << "Список студентів: " << endl;
    for (int i = 0; i < 7; i++)
    {
        cout << students[i].firstName << " " << students[i].lastName << " - Баланс: " << students[i].balance << endl;
    } 
    cout << endl;
}


// Завдання 5
void help_for_function_5(Student students[], int index, ofstream &file) // 13. використано рекурсивну функцію 
{
    if (index < 0)
    {
        return;
    }

    file << students[index].firstName << " " << students[index].lastName << " - Баланс: " << students[index].balance << endl;

    help_for_function_5(students, index - 1, file);
}

void function_5(Student students[], int size)
{
    ofstream file("students.txt"); // 16. використано функції роботи з файлами, для того, щоб записати у файл

    if (!file.is_open())
    {
        cout << "Не вдалось відкрити файл :(" << endl;
    }

    help_for_function_5(students, size - 1, file);
    file.close();

    cout << "Список студентів записано у файл в зворотньому порядку!" << endl;
}


// Завдання 6
void function_6()
{
    string fileName = "students.txt";
    ifstream file(fileName); // 17. використано функції роботи з файлами, для того, щоб зчитати з файлу

    if (file.is_open())
    {
        cout << "Дані з файлу: " << endl;
        string line;
        while(getline(file, line))
        {
            cout << line << endl;
        } 
    }
    else
    {
        cout << "Помилка! Файл не вдалось відкрити!" << endl;
    }
}


int main()
{
    const int CONST = 5; // 4. цілочисельна константа

    float x = function_1();
    float tower[5][5]; // 7. двовимірний масив 
    float resultArray[5];

    function_2(x, tower); // 14. використано параметри та аргументи функції	

    function_3(tower, resultArray);
    cout << "Масив результату: " << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << resultArray[i] << " ";
    }
    cout << endl;

    Student students[7];
    function_4(resultArray, students);

    function_5(students, 7);

    cout << endl;
    function_6();
    

    return 0;
}

// 8. використаний do while цикл
/*do{
    cout << "Hello ";
}while(true);*/

// 9. використаний while цикл
/*while(true)
{
    cout << "Hello ";
}*/

// 11. використано оператори break і continue
/*switch(choise)
{
    case 1:
        cout << " " << endl;
        break;
}*/

// 12. використано перевантаження функції 
/*int Add(int a, int b)
{
    return a + b;
}
float Add(float a, float b)
{
    return a + b;
}
*/

// 20. використано вказівники
/*
int a = 7;
std::cout << a << '\n'; 
std::cout << &a << '\n'; 
std::cout << *&a << '\n'; 
*/
