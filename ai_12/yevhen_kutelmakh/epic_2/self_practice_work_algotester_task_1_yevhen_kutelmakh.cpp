/*
Коля, Вася і Теніс
https://algotester.com/uk/ArchiveProblem/DisplayWithEditor/13
*/
#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n; // вводимо кількітсь подач
    char a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i]; // вводимо рузельтати подач
    }
    int K = 0, V = 0, PK = 0, PV = 0; //K,V - подачі, що виграв Коля і Вася, PK і PV - партії
    for(int i = 0; i < n; i++) {
        if(a[i] == 'K')
        K++;
        if(a[i] == 'V')
        V++;
        if(K==11 && V < 10) { // 1 умова для перемоги Колі
            PK++;
            K = 0;
            V = 0;
        }
        else if(K > 11 && K >= V+2){  // 2 умова для перемоги Колі
            PK++;
            K = 0;
            V = 0;
        }
        if(V==11 && K < 10) { // аналогічно для Васі
            PV++;
            K = 0;
            V = 0;
        }
        else if(V > 11 && V >= K+2){ // аналогічно для Васі
            PV++;
            K = 0;
            V = 0;
        }
    }
    cout << PK <<":"<< PV << "\n"; // вивід рахунку по партіх
    if(K != 0 || V != 0) {
        cout << K <<":"<< V; // вивід рахунку останньої партії, якщо вона не була закінчена
    }
    return 0;
}