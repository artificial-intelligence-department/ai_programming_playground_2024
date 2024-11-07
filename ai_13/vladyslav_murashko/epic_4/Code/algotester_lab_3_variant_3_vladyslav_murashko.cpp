#include <iostream>
using namespace std;

int main()
{
    string input, compressed;
    cin >> input;
    int count = 0;
    int j = 0;
    for (size_t i = 0; i < input.length(); i++)
    {
        count = 0;
        j = i;
        if (i != input.length()-1 && input[i] == input[i + 1])
        {
            while (input[j] == input[i] && i < input.length())
            {
                count++;
                i++;
            }
            i--;
        }
        compressed += input[j] + (count > 1 ? to_string(count) : "");
    }
    cout << compressed;
    return 0;
}