#include<bits/stdc++.h>

using namespace std;
const int varnum = 49;
double findMin1(double arr[5]){
    for(int i = 0; i < 4; i++){
        for(int j = i; j < 5; j++){
            if(arr[i] > arr[j]){
                swap(arr[i], arr[j]);
            }
        }
    }
    return arr[1];
}
double findMin2(double arr[5]){
    for (int i = 0; i < 4; i++){
        for (int j = 4; j > i; j--) {
            if (arr[j] < arr[j - 1]) {
                swap(arr[j], arr[j - 1]);
            }
        }
    }
    return arr[1];
}
double function_1(){
    float a, b;
    int c, d, e;
    double f;
    cout << "Введіть два дійсні числа а і b ";
    cin >> a >> b;
    cout << "Введіть три цілі числа с, d і е ";
    cin >> c >> d >> e;
    cout << "Введіть дійсне число з подвійною точністю f ";
    cin >> f;
    double arr[6];
    arr[0] = a;
    arr[1] = b;
    arr[2] = c;
    arr[3] = d;
    arr[4] = e;
    arr[5] = f;
    for(int i = 0; i < 5; i++){
        for(int j = i; j < 6; j++){
            if(arr[i] > arr[j]){
                swap(arr[i], arr[j]);
            }
        }
    }
    double sumMin = 0;
    double sumMax = 0;
    double x = 0;
    cout << "Три найменiі числа: ";
    for(int i = 0; i < 3; i++){
        cout << arr[i] << " ";
        sumMin += arr[i];
    }
    cout << endl;
    cout << "Три найбільші числа: ";
    for(int i = 3; i < 6; i++){
        cout << arr[i] << " ";
        sumMax += arr[i];
    }
    cout << endl;
    if(sumMax > sumMin * 2){
        x = sumMax * sumMin;
    }
    else if(sumMax > sumMin * 3){
        x = sumMax / sumMin;
    }
    else if(sumMax > sumMin * 4){
        x = sumMax + sumMin;
    }
    else{
        cout << "Випадок не підпадає під жодну з умов" << endl;
        return 0.0;
    }
    x /= varnum;
    return x;
}
void function_2(double x, double arr[5][5]){
    double matrix[5][5];
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            matrix[i][j] = x;
        }
    }
    srand(static_cast<unsigned int>(time(0)));
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            matrix[i][j] = matrix[i][j] + varnum + j - i * ((rand() % 101) + 1);
        }
    }
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    arr = matrix;
}
void function_3(double tower[5][5], double res[5]){
    double arr0[5];
    double arr1[5];
    double arr2[5];
    double arr3[5];
    double arr4[5];
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if (i == 0){
                arr0[j] = tower[j][i];
            }
            else if (i == 1){
                arr1[j] = tower[j][i];
            }
            else if (i == 2){
                arr2[j] = tower[j][i];
            }
            else if (i == 3){
                arr3[j] = tower[j][i];
            }
            else if (i == 4){
                arr4[j] = tower[j][i];
            }
        }
    }
    double r0 = findMin1(arr0);
    double r1 = findMin1(arr1);
    double r2 = findMin1(arr2);
    double r3 = findMin1(arr3);
    double r4 = findMin1(arr4);
    double l0 = findMin2(arr0);
    double l1 = findMin2(arr1);
    double l2 = findMin2(arr2);
    double l3 = findMin2(arr3);
    double l4 = findMin2(arr4);
    if((r0 != l0) || (r1 != l1) ||(r2 != l2) ||(r3 != l3) ||(r4 != l4)){
        cout << "Результати пошуку мінімального не співпадають";
    }
    else{
        cout << "Результати пошуку співпали";
    }
    res[0] = l0;
    res[1] = l1;
    res[2] = l2;
    res[3] = l3;
    res[4] = l4;
}

int main() {
    double x;
    x = function_1();
    double tower[5][5];
    function_2(x, tower);
    double res[5];
    function_3(tower, res);
    return 0;
}