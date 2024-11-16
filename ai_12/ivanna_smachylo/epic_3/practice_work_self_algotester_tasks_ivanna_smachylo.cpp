#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;

    string results;
    cin >> results;

    int kolyaWins = 0, vasyaWins = 0;
    int kolyaPoints = 0, vasyaPoints = 0;

    for(char result : results)
    {
        if(result == 'K') kolyaPoints++;
        else if(result == 'V') vasyaPoints++;

        if((kolyaPoints >= 11 || vasyaPoints >= 11) && abs(kolyaPoints - vasyaPoints) >= 2)
        {
            if(kolyaPoints > vasyaPoints) kolyaWins++;
            else vasyaWins++;

            kolyaPoints = 0;
            vasyaPoints = 0;
        }
    }

    cout << kolyaWins << ":" << vasyaWins << "\n";

    if(kolyaPoints > 0 || vasyaPoints > 0)
    {
        cout << kolyaPoints << ":" << vasyaPoints << "\n";
    }

    return 0;
}