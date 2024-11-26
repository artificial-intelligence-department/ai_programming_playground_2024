#include <iostream>
#include <string>
using namespace std;

int main() 
{
    string s;
    cin >> s;  

    string result = ""; 
    int n = s.length();

    int i = 0;
    while (i < n)
    {
        char currentChar = s[i];
        int count = 1;  

        while (i + 1 < n && s[i + 1] == currentChar) 
        {
            count++;
            i++;
        }

        if (count > 1)
        {
            result += currentChar + to_string(count);
        }
        else {
            result += currentChar;
        }

        i++;
    }

    cout << result << endl; 


    return 0;
}














