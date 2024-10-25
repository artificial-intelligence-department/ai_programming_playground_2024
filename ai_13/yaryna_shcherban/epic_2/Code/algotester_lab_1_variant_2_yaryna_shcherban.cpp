#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main (){

    long long min_h , max_h;
    string answer[] = { "YES" , "NO" , "ERROR" };
    int ans = 0;

    vector <long long> H(4);
    cin >> H[0] >> H[1] >> H[2] >> H[3] ;

    for (size_t i = 0; i < 4; i++){
        long long d;
        cin >> d;
        H[i] -= d;

        if ( H[i] >= 0){
            min_h = *min_element (H.begin(), H.end());
            max_h = *max_element (H.begin(), H.end());

            if ( max_h >= min_h * 2 || min_h == 0 ) {
                ans = 1;
            }  
        } else {
            ans = 2;
            break;
        }
    }
    
    cout << answer[ans];
    return 0;
}