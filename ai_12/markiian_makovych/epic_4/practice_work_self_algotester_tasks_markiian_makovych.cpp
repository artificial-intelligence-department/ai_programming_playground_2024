#include <iostream>

using namespace std;

int main()
{
    long long numOfTeeth = 0, sharpness = 0, count = 0, maxCount = 0;
    cin >> numOfTeeth >> sharpness;
    long long sharpnesses[numOfTeeth] = {};
    for (int i = 0; i < numOfTeeth; i++)
    {
        cin >> sharpnesses[i];
    }
    for (int i = 0; i < numOfTeeth; i++)
    {
        if (sharpnesses[i] >= sharpness)
        {
            count++;
        }
        else
        {
            if (count > maxCount)
            {
                maxCount = count;
            }
            count = 0;
        }
    }

    if (count >= maxCount)
    {
        maxCount = count;
    }

    cout << maxCount << endl;
    return 0;
}