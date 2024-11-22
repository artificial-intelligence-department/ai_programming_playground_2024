#include <iostream>
#include <string>
using namespace std;

int main() 
{
    string s;
    getline(cin, s);
    
    bool was_changed;
    for (int i = 0; i < s.length(); i++) 
    {
        was_changed = false;
        for (int j = 0; j < s.length() - 1; j++) 
        { 
            if (s[j] > s[j + 1]) {
                char temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
                was_changed = true;
            }
        }
        if (!was_changed) 
        {
            break;
        }
    }

    int rez = 0; 
    for (int i = 0; i < s.length() - 1; i++) 
    { 
        if (s[i] != s[i + 1]) 
        {
            rez++;
        }
    }
    rez++;
    cout << rez;

    return 0;
}
