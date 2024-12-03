#include <iostream>
#include <vector>
#include <cstdlib>
#include<ctime>
#include <algorithm> 
using namespace std;

const int Variant = 26;
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    bool swapped;
  
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}



double function_1();
vector<vector<double>> function_2(double &x);
vector<double> function_3(vector<vector<double>>& tower);



int main(){
    double n1 = function_1();
    vector<vector<double>> matrix = function_2(n1);
    vector<double> min_elements = function_3(matrix);

    for(double elem : min_elements){
        cout << elem << " ";
    }
    cout << endl;
    return 0;
}



double function_1(){
    float a, b;
    int c, d, e;
    double f;
    cout << "Два дійсних числа";
    cin >> a >> b;
    cout << "Три  цілих числа";
    cin >> c >> d >> e;

    cout << "Одне дійсне з подвійною точністю";
    cin >> f;
    vector<double> num = {a, b, static_cast<double>(c), static_cast<double>(d), static_cast<double>(e), static_cast<double>(f)};
    sort(num.begin(), num.end());

    double min = num[0] + num[1] + num[3];
    double max = num[4] + num[5] + num[6];
    double result;
    if(max > min*4){
        result = min+max;
    }
    else if(max > min*3){
        result = max / min;
    }
    else if(max > min*2){
        result = max*min;
    }
    else{
        result = 0;
    }

    result /= Variant;
    cout << "Результат: " << result << endl;
    return result;
}



vector<vector<double>> function_2(double &x){
    vector<vector<double>> matrix (5, vector<double>(5, x));
    srand(time(0));

    for(int i = 0; i<5; i++){
        for(int j = 0; j<5; j++){
            matrix[i][j] = (matrix[i][j] + Variant + j-i) * (rand()%100+1);
        }
    }
    cout << "Оновлена матриця: \n";

    for(int i = 0; i<5; i++){
        for(int j = 0; j<5; j++){
            cout << matrix[i][j] << "\t";
            }
        cout << "\n";
        }
    return matrix;
}


vector<double> function_3(vector<vector<double>>& tower){
    vector<double> min_el (5);
    for(int j = 0; j<5; j++){ /*перший алгоритм пошуку*/
        double min_value_1 = tower[0][j];
        for(int i = 0; i<5; i++){
            if(tower[i][j] < min_value_1){
                min_value_1 = tower[i][j];
            }
        }
        double min_value_2 = tower[0][j]; // другий алгоритм пошуку
        for(int i = 0; i<5; i++){
            if(tower[i][j] < min_value_2){
                min_value_2 = tower[i][j];
            }
        }


        if(min_value_1 == min_value_2){
            cout << "Мінімальні значення у стовпці " << j << " співпадають: " << min_value_1 << endl;
        } else{
            cout << "Мінімальні значення у стовпці " << j << " НЕ співпадають: " << min_value_1 << " та " << min_value_2 << endl;
        }

        min_el[j] = min_value_1; 
    }

    return min_el;
}