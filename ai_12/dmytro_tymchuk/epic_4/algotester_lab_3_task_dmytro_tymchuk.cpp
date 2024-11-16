#include<iostream>
#include<string>
using namespace std;

int compresion(string s)
{
    int len = 1;

    for (int i = 1; i <= s.length(); i++)
    {
        if (s[i] == s[i-1]) 
        {
            len++;
        }
        else 
        {
            cout<<s[i-1];
            if (len > 1) cout<<len;
            len = 1;
        }
    }
    
    return 0;
}

int main()
{
    string s;
    cin>>s;

    compresion(s);
    return 0;
}