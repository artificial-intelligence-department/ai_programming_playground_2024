#include <iostream>
#include <string>
using namespace std;

int main()
{
    string num;
    long long count = 0;
    cin >> num;
    for (int i = 0; i < num.size(); i++)
    {
        if (num[i] == '4' || num[i] == '7')
            count++;
    }
    cout << count;
    return 0;
}