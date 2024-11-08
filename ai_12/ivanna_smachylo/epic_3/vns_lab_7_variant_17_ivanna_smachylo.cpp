#include <iostream>
#include <string>

using namespace std;

int average(int arr[], int size)
{
    int sum = 0;
    for(int i = 0; i < size; i++)
    {
        sum += arr[i];
    }

    return sum / size;
}

int average(string str)
{
    int counter = 0;
    for(char c : str)
    {
        if(isalpha(c))
        {
            counter++;
        }
    }
    return counter;
}


int main()
{
    int intArr[] = {1, 2, 3, 4, 5};
    string str = "My name is Ivanka";

    int intSize = sizeof(intArr) / sizeof(intArr[0]);

    cout << "Average of int array: " << average(intArr, intSize) << "\n";
    cout << "The number of letters in the string: " << average(str) << "\n";
    return 0;
}