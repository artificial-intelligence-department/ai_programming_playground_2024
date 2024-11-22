#include <stdio.h>
#include <iostream>

using namespace std;

// n – розмірність матриці

void checker_for_three(int n, int a[3][3]){
    int s, self_sum = 0;
    bool self_s;
    // перший і другий
    for (int j = 0; j < n; j++)
    {
        s += a[0][j] * a[1][j];
    }
    // cout << s << '\n';

    // перший і третій
    for (int j = 0; j < n; j++)
    {
        s += a[0][j] * a[2][j];
    }
    // cout << s << '\n';

    // другий і третій
    for (int j = 0; j < n; j++)
    {
        s += a[1][j] * a[2][j];
    }
    // cout << s << '\n';

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {   
            self_sum = a[i][j] * a[i][j];
        }
        if (self_sum == 1)
        {
            self_s = true;
        }
        else {self_s = false;}
        
    }
    // cout << self_s << '\n';
    

    if ((s != 0) || (self_s != true)) {cout << "Не ортогоналізована\n";}
    else if ((s == 0) && (self_s == true)) {cout << "Ортогоналізована\n";}

}

void checker_for_four(int n, int a[4][4]){
    int s, self_sum = 0;
    bool self_s;
    // перший і другий
    for (int j = 0; j < n; j++)
    {
        s += a[0][j] * a[1][j];
    }

    // перший і третій
    for (int j = 0; j < n; j++)
    {
        s += a[0][j] * a[2][j];
    }

    // перший і четвертий
    for (int j = 0; j < n; j++)
    {
        s += a[0][j] * a[3][j];
    }

    // другий і третій
    for (int j = 0; j < n; j++)
    {
        s += a[1][j] * a[2][j];
    }

    // другий і четвертий
    for (int j = 0; j < n; j++)
    {
        s += a[1][j] * a[3][j];
    }

    // третій і четвертий
    for (int j = 0; j < n; j++)
    {
        s += a[2][j] * a[3][j];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {   
            self_sum = a[i][j] * a[i][j];
        }
        if (self_sum == 1)
        {
            self_s = true;
        }
        else {self_s = false;}
        
    }
    

    if ((s != 0) || (self_s != true)) {cout << "Не ортогоналізована\n";}
    else if ((s == 0) && (self_s == true)) {cout << "Ортогоналізована\n";}

}

int main(){
    int b[4][4] = {
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}};
    int c[3][3] = {
        {0, 1, 0},
        {1, 0, 0},
        {0, 0, -1}};

    checker_for_four(4, b);
    checker_for_three(3, c);
}