#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

const int var=63;

int function_1(){

    //ввід данних
    float a,b;
    int c,d,e;
    double f;

    cout<<"введіть два дійсних числа "<<endl;
    cin>> a >> b;
    cout<<"введіть три цілі числа "<<endl;
    cin>> c >> d >> e;
    cout<<"введіть одне дійсне число з подвійною точністю "<<endl;
    cin>> f;

    //збереження у векторі
    vector<double> num = {a, b, static_cast<double>(c), static_cast<double>(d), static_cast<double>(e), f};

    //сортування і розрах сумми мін і макс чисел
    sort(num.begin(), num.end());
    double min_sum = num[0] + num[1] + num[2];
    double max_sum = num[3] + num[4] + num[5];

    double result;

    if (max_sum>min_sum*4){
        result = max_sum+min_sum;
    } else if(max_sum>min_sum*3){
        result = max_sum/min_sum;
    }else if(max_sum>min_sum*2){
        result = max_sum*min_sum;
    }else{
       result = 0; 
    }
    
    double x = result / var;
    cout<<"результат:"<<x<<endl;
    return x;
}

vector<vector<double>> function_2(double &x) {

    srand(static_cast<unsigned>(time(0)));

    vector<vector<double>> matrix(5, vector<double>(5, x));

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            double random_factor = static_cast<double>(rand() % 100 + 1);
            matrix[i][j] = (matrix[i][j] + var + j - i) * random_factor;
        }
    }

    // Виводимо матрицю
    cout << "Оновлена матриця:" << endl;
    for (const auto &row : matrix) {
        for (double val : row) {
            cout << val << "\t";
        }
        cout << endl;
    }

    // Повертаємо оновлену матрицю
    return matrix;
}
    

int main() {

    double result = function_1();
    vector<vector<double>> updated_matrix = function_2(x);


    return 0;
}


