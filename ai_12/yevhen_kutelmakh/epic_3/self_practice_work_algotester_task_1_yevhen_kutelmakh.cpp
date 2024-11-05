/*
https://algotester.com/uk/ArchiveProblem/DisplayWithEditor/20070
Існує дві дороги: Одна пряма, а інша ...
*/
#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int n; //кількість виборчих дільниць.
    cin >> n;
    int m[n][4];//масив для позначення координат. Перші два значення — координати виборчої дільниці.
    //Наступні два — координати відповідного регіонального представництва.
    for(int i = 0; i < n; i++) {
        for(int k = 0; k < 4; k++) {
            cin >> m[i][k];
        }
    }
    int x[n];//Результуючий масив для зберігання відстаней
    int s = 0;//Сумма відстаней
    for(int i = 0; i < n; i++) {
        x[i] = sqrt(pow(m[i][2] - m[i][0],2) + pow(m[i][3] - m[i][1],2));//Формула довжини вектора
        s += x[i];
    }
    cout << s;
    return 0;
}