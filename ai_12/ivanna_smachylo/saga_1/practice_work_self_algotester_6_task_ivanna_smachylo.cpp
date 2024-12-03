#include <iostream>
#include <string>

using namespace std;

int main() 
{
    string number;
    cin >> number;

    int minNum = 0, maxNum = 0;
    int multip = 1;

    for (int i = number.size() - 1; i >= 0; i--) 
    {
        if (number[i] == '*') 
        {
            minNum += (i == 0) ? 1 * multip : 0;
            maxNum += 9 * multip;
        } 
        else 
        {
            minNum += (number[i] - '0') * multip;
            maxNum += (number[i] - '0') * multip;
        }
        multip *= 10;
    }

    cout << minNum << " " << maxNum << "\n";

    return 0;
}