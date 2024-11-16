#include <iostream>
#include <string>

using namespace std;

int minElement(int a[])
{
    int min = 0;
    for (int i = 0; i < 23; i++)
    {
        if (a[i] < a[i + 1])
        {
            min = a[i];
        }
        else if (a[i] >= a[i + 1])
        {
            min = a[i + 1];
        };
    }
    cout << min << endl;
    return min;
}

string minElement(string str)
{
    char a;
    int minLength, currentLength = 0;
    for (char a : str)
    {
        if (a != ' ')
        {
            currentLength++;
        }
        else
        {
            if (currentLength != 0 && currentLength < minLength)
                minLength = currentLength;

            currentLength = 0;
        }
        }
    if (currentLength != 0 && currentLength < minLength)
        minLength = currentLength;

    cout << minLength;
    return " ";
}

int main()
{

    int a[] = {1, 2, 4, 1, 2, 3, 1, 2, 3, 4, 1, 3, 1, 2, 3, 1, 2, 2, 2, 1, 4, 1, 1};
    minElement(a);
    minElement("hi how are you");

    return 0;
}