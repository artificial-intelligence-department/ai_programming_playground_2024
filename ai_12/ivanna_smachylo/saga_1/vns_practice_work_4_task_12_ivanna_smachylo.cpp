#include <iostream>

using namespace std;

//рекурсивна функція для обчислення суми елементів масиву
double calculate(double arr[], int ind, int size)
{
    double sum = 0;
    for(int i = 0; i < size; i++)
    {
        if(arr[i] < 0)
        {
            continue;
        }
        sum += arr[i];
        if(sum > 100)
        {
            break;
        }
    }
    return sum;
}

int main() 
{
    const int size = 5;//цілочисельна константа
    double numbers[size]; 
    double sum = 0;

    cout << "Enter " << size << " fractional numbers: " << "\n";
    for(int i = 0; i < size; i++)
    {
        cout << "Number " << i + 1 << " : ";
        cin >> numbers[i];
    }

    sum = calculate(numbers, 0, size);
    double average = sum / size;
    cout << "Arithmetic mean for this numbers is: " << average << "\n";

    return 0;
}