#include <iostream>
#include <cstring>
using namespace std;

char *in_string(char *a, char x)
{
    for (int i = 0; i < strlen(a); i++)
        if (x == a[i])
            return &a[i];
    return nullptr;
}

int main()
{
    char s[10000];
    char name[10000];

    cin.getline(s, 10000);
    cin.getline(name, 10000);

    bool t = true;
    for (int i = 0; i < strlen(name); i++)
    {
        char *pos = in_string(s, name[i]);
        if (pos != nullptr)
            *pos = ' ';
        else
        {
            t = false;
            break;
        }
    }

    if (t)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
