#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;

    string score; 
    cin >> score;

    int gamescoreK = 0;
    int gamescoreV = 0;
    int scoreK = 0; 
    int scoreV = 0;

    for(char result : score)
    {
        if(result == 'K')
        {
            scoreK++;
        }
        else if(result == 'V')
        {
            scoreV++;
        }

     if ((scoreK >= 11 || scoreV >= 11) && abs(scoreK - scoreV) >= 2)
     {
            if (scoreK > scoreV) 
            {
                gamescoreK++;
            } 
            else 
            {
                gamescoreV++;
            }

            scoreK = 0;
            scoreV = 0;
        }
    }

    cout << gamescoreK << ":" << gamescoreV << endl;
    if (scoreK > 0  || scoreV > 0) 
    {
        cout << scoreK << ":" << scoreV << endl;
    }

    return 0;
}