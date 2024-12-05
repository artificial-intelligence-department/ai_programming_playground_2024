// vns lab6V13

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

void sortL(char s[]) 
{
    int start = 0, end = 0;
    int n = strlen(s);

    for (int i = 0; i <= n; i++) 
    {
        if (s[i] == ' ' || s[i] == '.' || s[i] == '\0') 
        {
            end = i;
            if (start < end) 
            {
                sort(s + start, s + end, greater<>());
            }
            start = i + 1;
        }
    }
}

int main() 
{
    char s[256];

    cout << "Введіть рядок (до 255 символів, закінчуючи крапкою): ";
    gets(s);

    sortL(s);

    cout << "Перетворений рядок: " << s << endl;

    return 0;
}
