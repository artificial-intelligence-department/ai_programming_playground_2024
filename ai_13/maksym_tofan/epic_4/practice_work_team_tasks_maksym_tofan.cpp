#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isPalindrome(string t, int s, int e)
{
    return (s >= e ? true : (t[s] != t[e] ? false : isPalindrome(t, ++s, --e)));
}

bool isPalindrome(int n, int s, int e)
{
    int h = n % int(pow(10, s));
    int first = (h / int(pow(10, int(log10(h)))));
    int last = (int(n / pow(10, e)) % 10);
    return (s >= e ? true : (first != last ? false : isPalindrome(n, ++s, --e)));
}

int main()
{
    string str;
    cout << "enter string: ";
    cin >> str;
    try
    {
        int num = stoi(str); 
        cout << (isPalindrome(num, 1, log10(num)) ? "yes, it is a polindrom" : "it`s not a polindrom");
    }
    catch (exception &e)
    {
        cout << (isPalindrome(str, 0, str.size() - 1) ? "yes, it is a polindrom" : "it`s not a polindrom");
    }
    
    return 0;
}