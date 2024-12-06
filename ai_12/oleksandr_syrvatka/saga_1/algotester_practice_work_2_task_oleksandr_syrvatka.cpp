#include <bits/stdc++.h>
#include <string>
#include<iostream>
using namespace std;

//Допоможе 

int main() {
    int n, k;
    cin >> n;
    k = 0;
    string a;
    cin.ignore();
    getline(cin, a);
    for(int i = 0; i < a.length();){
        if (a[i] == 'T' && a[i+1] == 'O' && a[i+2] == 'I' && a[i+3] == 'L' && a[i+4] == 'E' && a[i+5] == 'T'){
            i += 6;
            k++;
        }
        else{
            i++;
        }
    }
    if (k >= n) {
        cout << "YES";
    }
    else{
        cout << "NO";
    }
    
    return 0;
}