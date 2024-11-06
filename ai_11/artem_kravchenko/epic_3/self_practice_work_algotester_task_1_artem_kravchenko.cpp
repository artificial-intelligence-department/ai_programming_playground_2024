#include <iostream>
#include <string>

using namespace std;

int main(){
    int n;
    string c;
    cin >> n;
    cin >> c;

    int k_s = 0;
    int v_s = 0;
    int k_w = 0;
    int v_w = 0;
    int score_dif = 0;

    for (int i = 0; i < n; i++)
    {
        if (c[i] == 'K')
        {
            k_s++;
            score_dif++;
        }else{
            v_s++;
            score_dif--;
        }
        if ((k_s >= 11 || v_s >= 11) && abs(score_dif) >= 2)
        {if (k_s > v_s)
        {
            k_w++;
        }else{
            v_w++;
        }
        k_s = 0;
        v_s = 0;
        score_dif = 0;
    }
    }
    cout << k_w << ":" << v_w << endl;

    if (k_s != 0 || v_s != 0)
    {
        cout << k_s << ":" << v_s;
    }else if (k_w == 0 && v_w == 0) {
        cout << "0:0\n";
    }

    return 0;
}