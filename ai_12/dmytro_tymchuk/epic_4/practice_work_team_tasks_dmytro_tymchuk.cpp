#include<iostream>
#include<string>
using namespace std;

bool is_palindrom (const string& s, int begin, int end)
{
    if (begin > end)
    {
        return true;
    }
    else if (s[begin] == s[end])
    {
        return (s, begin + 1, end - 1);
    }
    else return false;
}
bool is_palindrom (int num)
{
    int m = 0;
    int n = num;
    while (n > 0)
    {
        m = m * 10 + n % 10;
        n /= 10;
    }

    if (num == m)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    string s;
    int num;
    cout<<"Введіть рядок: ";
    cin>>s;
    if (is_palindrom(s, 0, s.length() - 1))
    {
        cout<<"Введений рядок є паліндромом\n\n";
    }
    else cout<<"Введений рядок не є паліндромом\n\n";

    cout<<"Введіть число: ";
    cin>>num;
    if (is_palindrom(num))
    {
        cout<<"Введене число є паліндромом\n\n";
    }
    else cout<<"Введене число не є паліндромом\n\n";

    return 0;
}