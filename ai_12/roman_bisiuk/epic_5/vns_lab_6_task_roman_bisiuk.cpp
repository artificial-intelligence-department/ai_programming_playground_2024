#include <iostream>
#include <string>
#include <climits> 
using namespace std;

int main()
{
    cout << "Введіть рядок для знаходження найменшого слова:\n";
    string s;
    getline(cin, s); 

    int counter = 0, min_length = INT_MAX;

    for (char c : s)
    {
        if (c != ' ')
            counter++;
        else
        {
            if (counter > 0) 
                min_length = min(min_length, counter);
            counter = 0;
        }
    }

    if (counter > 0)
        min_length = min(min_length, counter);

    if (min_length == INT_MAX)
        min_length = 0;

    cout << min_length;

    return 0;
}
