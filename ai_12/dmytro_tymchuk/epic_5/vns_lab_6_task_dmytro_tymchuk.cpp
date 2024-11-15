#include<iostream>
#include<string>
using namespace std;
void bubble_sort(string& s)
{
    char change_symbol;

    for (int i = 0; i < s.length() - 1; i++)
    {
        for (int j = 0; j < s.length() - i; j++)
        {
            if ((int)s[j] > (int)s[j + 1])
            {
                change_symbol = s[j];
                s[j] = s[j + 1];
                s[j + 1] = change_symbol;
            }
        }
    }
}

int main()
{
    string s;
    cin>>s;
    bubble_sort(s);

    cout<<s<<endl;
    return 0;
}