#include <iostream>
#include <string>

using namespace std;

int main()
{
    string string;
    cin >> string;
    int counter = 1;
    for (int i = 0; i < string.length(); i++)
    {
        if (string[i] == string[i + 1])
            counter++;
        else
        {
            if (counter == 1)
                cout << string[i];
            else
                cout << string[i] << counter;

            counter = 1;
        }
    }
    return 0;
}