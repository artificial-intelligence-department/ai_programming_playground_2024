#include<iostream>
#include<string>
using namespace std;
void bubble_sort(int* arr_of_code, string& s, int n)
{
    int change_code;
    char change_symbol;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n - 1; j++)
        {
            if (arr_of_code[j] > arr_of_code[j + 1])
            {
                change_code = arr_of_code[j];
                arr_of_code[j] = arr_of_code[j +1];
                arr_of_code[j + 1] = change_code;

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
    bubble_sort(arr_of_code,s, s.length());

    cout<<s<<endl;
    return 0;
}