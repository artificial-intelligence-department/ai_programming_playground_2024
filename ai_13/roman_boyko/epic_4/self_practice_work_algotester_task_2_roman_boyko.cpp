#include <iostream>
using namespace std;

int main()
{
    string s, s1;
    int l = 0;
    cin >> s;
    int k = 1;
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == s[i - 1])
        {
            k++;
        }
        else
        {
            s1 += s[i - 1];
            if (k > 1)
            {
                s1 += to_string(k);
            }
            k = 1;
        }
    }
    s1 += s[s.length() - 1];
    if (k > 1)
    {
        s1 += to_string(k);
    }
    cout << s1;
}