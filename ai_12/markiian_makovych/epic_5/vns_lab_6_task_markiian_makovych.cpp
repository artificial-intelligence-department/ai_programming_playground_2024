#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

bool checkChar(int a)
{

    for (int i = 34; i < 65; i++)
    {
        if (a == i)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    char s[256] = {};

    int n = 0;

    vector<char> str;
    int count = 0;
    puts("Input your string:");
    gets(s);

    for (int i = 0; i < 256; i++)
    {

        if (checkChar(s[i]))
        {
            for (int j = i; j < 256; j++)
            {
                if (s[j] != ' ')
                {
                    i++;
                }
                else
                {
                    break;
                }
            }
        }
        else
        {
            for (int j = i; j < 256; j++)
            {
                if (s[j] != ' ')
                {
                    str.push_back(s[i]);
                    i++;
                }
                else
                {
                    break;
                }
            }
            str.push_back(' ');
        }
    }

    for (int i = 0; i < str.size(); i++)
    {
        cout << str[i];
    }

    return 0;
}