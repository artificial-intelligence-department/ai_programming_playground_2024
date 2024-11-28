#include <iostream>
#include <string>

using namespace std;

int main() {
    int n; 
    cin >> n;
    string results; 
    cin >> results;

    int totalK = 0, totalV = 0;
    int nowK = 0, nowV = 0;

    for (char c : results) {
        if (c == 'K') nowK++; 
        else nowV++;          


        if ((nowK >= 11 || nowV >= 11) && abs(nowK - nowV) >= 2) {

            if (nowK > nowV) totalK++;
            else totalV++;


            nowK = 0;
            nowV = 0;
        }
    }


    cout << totalK << ":" << totalV << endl;

  
    if (nowK > 0 || nowV > 0) {
        cout << nowK << ":" << nowV << endl;
    }

    return 0;
}
