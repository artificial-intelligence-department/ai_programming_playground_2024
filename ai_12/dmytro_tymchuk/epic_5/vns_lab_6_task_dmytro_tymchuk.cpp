#include<iostream>
#include<string>
using namespace std;
void bubble_sort(string& s)
{
    int change_code;
    char change_symbol;

    for (int i = 0; i < s.length() - 1 ; i++)
    {
        for (int j = 0; j < s.length() - i - 1; j++)
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
    int arr_of_code[1000];
    for (int i = 0; i < s.length(); i++)
    {
        arr_of_code[i] = (int)s[i];
    }
    bubble_sort(s);

    cout<<s<<endl;
    return 0;
}