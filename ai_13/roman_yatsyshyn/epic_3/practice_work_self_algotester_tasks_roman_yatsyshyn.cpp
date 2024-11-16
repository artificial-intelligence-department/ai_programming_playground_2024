#include <stdio.h>
#include <iostream>
#include <string>
// #include <math.h>

using namespace std;

int main(){
    int n = 0;
    cin >> n;
    string a;
    cin >> a;

    char _k = 'K';
    char _v = 'V';

    int k_win = 0;
    int v_win = 0;

    int advantage_k_over_v = 0;
    int nmbr_wins_k = 0;
    int nmbr_wins_v = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == _k)
        {
            k_win++;
        }
        else if (a[i] == _v)
        {
            v_win++;
        }
        advantage_k_over_v = k_win - v_win;
        if ((k_win >= 11) && (advantage_k_over_v >= 2))
        {
            k_win = 0;
            v_win = 0;
            nmbr_wins_k++;
        }
        else if ((v_win >= 11) && (advantage_k_over_v <= -2))
        {
            k_win = 0;
            v_win = 0;
            nmbr_wins_v++;
        }
    }
    cout << nmbr_wins_k << ":" << nmbr_wins_v;
    if ((k_win != 0) || (v_win != 0))
    {
        cout << "\n" << k_win << ":" << v_win;
    }
}