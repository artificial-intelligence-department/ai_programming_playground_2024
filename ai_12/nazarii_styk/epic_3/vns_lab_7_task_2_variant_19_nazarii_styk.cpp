#include <iostream>
#include <string>

using namespace std;

// Розв’язати зазначене у варіанті завдання, використовуючи функції зі змінною кількістю параметрів.
// а) для масиву цілих чисел знаходить мінімальний елемент;
// б) для рядка знаходить довжину найкоротшого слова .

int MinNumber(int array[], int size)
{
    int min = array[0];

    for (int i = 0; i < size; i++)
    {
        if (array[i] < min)
        {
            min = array[i];
        }
    }
    return min;
}

int MinWord(string str)
{
    int min = str.length();
    int count = 0;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != ' ')
        {
            count++;
        }
        else
        {
            if (count < min)
            {
                min = count;
            }
            count = 0;
        }
    }
    return min;
}
int main()
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = sizeof(array) / sizeof(array[0]);
    cout << "Minimum number in array: " << MinNumber(array, size) << endl;

    string str = "This is aaa test string";
    cout << "Length of the shortest word: " << MinWord(str) << endl;

    return 0;
}