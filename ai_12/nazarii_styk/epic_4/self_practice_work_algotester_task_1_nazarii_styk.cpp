#include <iostream>

using namespace std;

int main()
{
    int girlCount[4];
    for (int i = 0; i < 4; i++)
    {
        cin >> girlCount[i];
    }

    int presentsCount = 0;
    for (int i = 0; i < 4; i++)
    {
        presentsCount += girlCount[i];
    }

    cout << presentsCount << endl;


    return 0;
}