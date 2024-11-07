#include <iostream>
#include <string>

using namespace std;

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
    string str = "My name is Ivanna";

    cout << "The number of letters in the string: " << average(str) << "\n";
    return 0;
}