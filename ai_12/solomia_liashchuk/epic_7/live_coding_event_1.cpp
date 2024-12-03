#include <iostream> //в коді не можна використовувати вектори
#include <string>
#include <fstream>
using namespace std;

void function_1()
{
    float a, b; //в коді використана як мінімум одна дійсна змінна
    int c, d, e; //в коді використана як мінімум одна цілочисельна змінна
    double f; //в коді використана як мінімум одна дійсний з подвійною точністю змінна
    cout << "Введіть значення для a, b"; //в коді використано оператори виведення та введення даних
    cin >> a >> b;
    cout << "Введіть значення для c, d, e";
    cin >> c >> d >> e;
    cout << "Введіть значення для f";
    cin >> f;

    int const size = 3; //в коді використана як мінімум одна цілочисельна константа
    int arr[size] = {c, d, e}; //в коді використаний одновимірний масив

    int min = arr[0];
    int max = arr[0];

    for(int i = 0; i < size, i++) //в коді використаний for цикл
    {
        if(arr[i] < min )
        {
            min = arr[i];
        }
        if(arr[i] > max )
        {
            max = arr[i];
        }
    }

    double result;
    double g = 0;
    double find;

    if(max > min*2) //в коді використані умовні оператори та розгалуження
    {
        g = max * min;
    }
    else if(max > min*3) //в коді використано математичні операції та математичні функції
    {
        g = max / min;
    }
    else if(max > min*4)
    {
        g = max + min;
    }

    find = g / 45;
    cout << "Result" << result;

}

void function_2(int arrayA[], int arrayB[], int lengthA, int lengthB, int matrix[5][5], int&) //в коді використано вказівники

{
    for(int i = 0; i < lengthA; i++)
    {
        for (int j = 0; j < lengthB; j++)
        {


        }
    }
}

struct Mystruct //в коді використано свою структуру даних
{
    int number = 78;
    float number2 = 0.12;
    string word = "Hello";
};

enum FileOpResult{Success, Failure}; //в коді використано функції роботи з файлами, для того, щоб зчитати з файлу
FileOpResult write_to_file(const string& content)
{

ofstream outfile("nameFile.txt");
if(!outfile.is_open())
{
    cout << "Error: Unable to creat the file";
    return FileOpResult::Failure;
}

outfile << content;
outfile.close();

ifstream infile("nameFile.txt");
if(!infile.is_open())
{
    cout << "Error: Unable to read the file";
    return FileOpResult::Failure;
}

char c;
while(infile.get(c))
{
    cout << c;
}

return FileOpResult::Success;
}
