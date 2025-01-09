#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <numeric>
using namespace std;
const int Variant = 29;
double function_1(){
    double a, b, f;
    int c, d, e;
    cout << "Enter 2 racional numbers";
    cin >> a >> b >> f;
    cout << "Enter 3 intager numbers";
    cin >> c, d, e;
    cout << "Enter 1 racional number with double accuracy";
    cin >> f;

    double sorting [] = {a, b, (double)c, (double)d, (double)e, f};
    sort(begin(sorting), end(sorting));
    double MAXim =  accumulate(sorting + 3, sorting + 6, 0.0);
    double MINim =  accumulate(sorting, sorting + 3, 0.0);
    double Result;

    if(MAXim > MINim * 4){
        Result = MAXim + MINim;
    }
    else if(MAXim > MINim * 3){
        Result =  MAXim / MINim;
    }
    else if(MAXim > MINim * 2){
        Result =  MAXim * MINim;
    }
    else {
        Result = MAXim - MINim;
    }
    double answ = Result / Variant;
    cout << "Result:" << answ << endl;
    return answ;

}
void function_2 (double &answ){//Посилання на значення в минулій функції
    double matrix [5][5];
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
        matrix [i][j] = answ;
        };
        srand(time(0));
        for (int i = 0; i < 5; i++){
            for (int j = 0; j < 5; j++){
                matrix [i][j] = (matrix [i][j] + Variant + j - i) * (rand()% 100 + 1);
            }
        };
        cout << "Matrix:" << answ << endl;
        for (int i = 0; i < 5; i++){
            for (int j = 0; j < 5; j++){
                cout << setw(10) << matrix[i][j];
        }
        cout << endl;
    }
    }
}