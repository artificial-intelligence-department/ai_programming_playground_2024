#include <iostream>

using namespace std;

int count(string &s, char x)
{
    int k = 0;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == x)
        {
            k++;
            s[i] = '_';
        }
    return k;
}

int main()
{
    string s;
    getline(cin, s);

    int result = 0;
    for (char c : s)
        if (c != '_')
            result += count(s, c) % 2;

    if (result <= 1)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}