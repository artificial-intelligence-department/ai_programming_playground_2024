#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;
const int VARIANT = 7; //цілочисельна константа

double function_1(){
        double a, b; //дійсна змінна
        int c, d, e; // цілочисельна зміннa
        double f; //дійсна змінна

        cout << "Ведіть різні значення для аргументів 6 шт:";
        cin >> a >> b;
        cin >> c >> d >> e;
        cin >> f;

        double numbers[6] = {a, b, static_cast<double> (c), static_cast<double> (d), static_cast<double> (e), f};//одновимірний масив
        sort (numbers, numbers +6);

        double min[3] = {numbers[0], numbers[1], numbers[2]};
        double max[3] = {numbers[3], numbers[4], numbers[5]};
            
        double result = 0;
        double sum_min = numbers[0]+ numbers[1]+ numbers[2];
        double sum_max = numbers[3] + numbers[4] + numbers[5];
        if (sum_max > (sum_min*2)){ // умовні оператори та розгалуження
            result = sum_min * sum_max;}
        else if (sum_max > (sum_min*3)){
            result = sum_min / sum_max;}
        else if (sum_max > (sum_min*4)){
            result = sum_min + sum_max;}
        else 
            cout << "Error" << endl;
               
    
        result /= VARIANT;
        return result;
    }

void function_2(int& x, int matrix[5][5]){
    for (int i = 0; i < 5; i++){ //в коді використаний for
        for (int j = 0; j < 5; j++){
            matrix[i][j] = x;
        }
    }
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            matrix[i][j] =  matrix[i][j] + VARIANT + i + j + rand() % 100;
        }
    }

    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void function_3(int matrix[5][5], int tower[5]){
int Colmin1[5];
int Colmin2[5];
for (int i = 0; i < 5; i++) {
        int min = matrix[0][i];
        for (int j = 1; j < 5 - 1; j++) {
            if (matrix[j][i] < min){
                 min=matrix[j][i];
            }
        Colmin1[i] = matrix[j][i];
        }
    }
for (int i = 0; i < 5; i++){
    int min = min_element(matrix[0][i], matrix[0][i] + 5 );
    Colmin2[i] = min;
}
bool equal = true;
    for (int i = 0; i < 5; i++){
        if( Colmin1[i] != Colmin2[i]){
            equal = false;
            break; //використано оператори break
        }
    }
    if (equal == true){
        cout << "equal"<< endl;}
    else 
        cout << " not equal"<< endl;
    
    for (int i = 0; i < 5; i++){
        tower[i] = Colmin1[i];
    }
    for (int i = 0; i < 5; i++){
        cout << tower[i];
    }
 }   
int main()
{
    int array[5][5]; // двовимірний масив 
    int tower[5];
    int x = function_1();
    function_2(x, array);
    function_3(array, tower);
    return 0;
}