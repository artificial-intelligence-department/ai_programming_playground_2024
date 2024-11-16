#include <iostream>
#include <string>
using namespace std;
const int maxCol = 60;
const int maxRow = 3;
void words(char arr[maxCol]);
int main()
{
    char arr[maxRow][maxCol] = {
        "123023402303450",
        "234450234567010",
        "234455677670450"};

    for (int j = 0; j < maxRow; j++)
    {
        words(arr[j]);
    }
}
void words(char arr[maxCol])
{
    string s = "";
    for (int i = 0; i < maxCol && arr[i] != '\0'; i++)
    {
        if (arr[i] == '0')
        {
            s += ',';
        }
        else
        {
            s += arr[i];
        }
    }

    if (!s.empty())
    {
        s.pop_back();
    }

    cout << "(" << s << ")";
}