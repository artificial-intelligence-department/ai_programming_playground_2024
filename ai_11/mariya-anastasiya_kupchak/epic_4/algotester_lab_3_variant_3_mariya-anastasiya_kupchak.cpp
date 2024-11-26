#include <iostream>
#include <string>

using namespace std;

int main() 
{
    string s;
    cin >> s;

    string compressed = "";
    int count = 1;

    for (size_t i = 0; i < s.length(); ++i) 
    {
        if (i < s.length() - 1 && s[i] == s[i + 1]) 
        {
            count++;
        } 
        else 
        {
            compressed += s[i];
            if (count > 1) 
            {
                compressed += to_string(count);
            }
            count = 1;
        }
    }

    cout << compressed << endl;

    return 0;

}