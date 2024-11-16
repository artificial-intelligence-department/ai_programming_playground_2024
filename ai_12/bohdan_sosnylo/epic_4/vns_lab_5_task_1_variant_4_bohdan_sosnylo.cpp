#include <iostream>
#include <cmath>

using namespace std;

const int maximum = 100;

double dobutok(double m1[], double m2[], int n){
    double result = 0.0;
    for(int i = 0;i<n;i++){
         result += m1[i] * m2[i];
    }
    return result;
}

bool ortogonal(double matrix[maximum][maximum], int n){
    double mn;
    for(int i = 0; i<n;i++){
        for(int j = 0;j<n;j++){
            mn = dobutok(matrix[i], matrix[j], n);
            if(i == j){
                if(mn != 1){
                    return false;
                }
            }
            else if(mn != 0){
                return false;
            }
        }
    }
    return true;
}

int main(){

int n;
double m[maximum][maximum];
h:
cout << "Введіть розміри матриці, але менше за " << maximum <<": ";
cin >> n;
if(n > maximum || n<=0){
    cout << "Неправильний ввід" <<endl;;
    goto h;
}
cout << "Введіть елементи матриці:" << endl;
    for(int i=0; i<n;i++){
        for(int j = 0; j<n;j++){
            cin >>m[i][j];
        }
    }

if(ortogonal(m, n)) cout << "Матриця є ортонормованою";

else cout << "Матриця не ортонормована";

    return 0;
}