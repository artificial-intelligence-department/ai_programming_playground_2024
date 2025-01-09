// Коля, Вася і Теніс
#include <iostream>
using namespace std;

int main() 
{
    int n;
    cin >> n;

    string results;
    cin >> results;

    int kWins = 0, vWins = 0; 
    int kCurrent = 0, vCurrent = 0; 

    for (int i = 0; i < n; i++) 
    {
        char c = results[i]; 
        if (c == 'K') 
        {
            kCurrent++;
        } 
        else 
        {
            vCurrent++;
        }

        if ((kCurrent >= 11 || vCurrent >= 11) && (kCurrent - vCurrent >= 2 || vCurrent - kCurrent >= 2)) 
        {
            if (kCurrent > vCurrent) 
            {
                kWins++;
            } 
            else 
            {
                vWins++;
            }

            kCurrent = 0; 
            vCurrent = 0;
        }
    }

    cout << kWins << ":" << vWins << endl;

    if (kCurrent > 0 || vCurrent > 0) 
    {
        cout << kCurrent << ":" << vCurrent << endl;
    }

    return 0;
}
