#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <array>

using namespace std;

double function_1(const int var){
    int c, d, e;
    cout << "Введдіть три цілі числа c , d , e:";
    cin >> c >> d >> e;

    float a , b;
    cout << "Введдіть два дійсних числа a, b:";
    cin >> a >> b ;

    double f;
    cout << "Введіть одне число з подвійною точністю f:";
    cin >> f;

    double arr [6] = {static_cast<double>(a), static_cast<double>(b) , static_cast<double>(c), static_cast<double>(d), static_cast<double>(e), f};

    sort (arr, arr +6);

    double max_sum = arr[3] + arr[4] + arr[5];
    double min_sum = arr [0] + arr[1] + arr[2];
    double x = 0;

    if(max_sum > min_sum * 4){
        x = max_sum + min_sum;


    }
    else if (max_sum > min_sum *3){
        x = max_sum / min_sum;

    }
    else if (max_sum > min_sum * 2) {
        x = max_sum * min_sum ;
    }
    x /=var;
    cout << x;

    return x;
}


void function_2(double&x, const int var, double matrix[5][5]){
    double matrixx [5] [5];

    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            matrixx [i] [j] = x;
        }
    }
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            matrixx [i] [j] = (matrixx[i][j] + var + j - i) * (rand()%100+1) ;
        }
    }
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            cout << matrixx [i][j] << "";
        }
        cout << endl;
    }
    matrix = matrixx;
}


void function_3 (double tower[5][5], double minstovp[5]){
    double minstovpp1 [5];
    double minstovpp2 [5];
    double minelem = 0;
    for (int j = 0; j < 5; j++){
        minelem = tower [0][j];
        for (int i = 1; i < 5; i++){
            if(minelem > tower[i][j]){
                minelem = tower[i][j];


            }
        
        minstovpp1[j] = minelem;

        }
    }

    for (int j = 0; j < 5; j++){
        array<double,5> column;
        for (int i = 0; i < 5; i++){
            column[i]=tower[i][j];
            


            }
    sort(column.begin(),column.end());

    minstovpp2[j] == column[0];
   
    }
    for (int i = 0 ; i < 5; i++ ){
        if (minstovpp1[i] == minstovpp2[i]){
            cout << "Елемент" << i << "співпадає";
        }
    }
    minstovp = minstovpp2;
}
/*У головній функції:
Присвоїти отримані дані з function_2 у масив tower.
Передати масив tower у функцію function_3.
У функції function_3:
Оголосити одновимірний масив розміром 5 елементів.
Для кожного стовпця матриці 5x5 знайти найменший елемент.
Для кожного стовпця матриці 5x5 знайти найменший елемент іншим алгоритмом пошуку.
Звірити чи результати обох пошуків співпадають та повідомити про це в консоль.
Записати ці знайдені елементи у створений масив.
Повернути масив у головну функцію.
*/

int main(){

    const int var = 50;
    double x = function_1(var);
    double tower [5][5];
    function_2(x,var,tower);

    double minstovp[5];
    function_3(tower,minstovp);





    return 0;
}
