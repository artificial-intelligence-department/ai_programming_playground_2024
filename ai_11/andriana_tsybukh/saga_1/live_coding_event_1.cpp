#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

const int VARIANT = 27;

double function_1() {
    double a, b, f;
    int c, d, e;

    cout << "Введіть два дійсних числа (a, b): ";
    cin >> a >> b;
    cout << "Введіть три цілі числа (c, d, e): ";
    cin >> c >> d >> e;
    cout << "Введіть одне дійсне число з подвійною точністю (f): ";
    cin >> f;

    vector<double> values = {a, b, static_cast<double>(c), static_cast<double>(d), static_cast<double>(e), f};
    sort(values.begin(), values.end());

    double min_sum = values[0] + values[1] + values[2];
    double max_sum = values[3] + values[4] + values[5];
    double result;

    if(max_sum > min_sum * 4){
        result = min_sum + max_sum;
    } else if(max_sum > min_sum * 3) {
        result = max_sum / min_sum;
    } else if (max_sum > min_sum * 2) {
        result = max_sum * min_sum;
    } else {
        result = 0;
    }

    result /= VARIANT;

    // cout << "Результат: " << result << endl;
    return result;
}

vector<vector<double>> function_2(double &x) {
    srand(time(0));

    vector<vector<double>> matrix(5, vector<double>(5, x));

    for(int i = 0; i < 5; ++i) {
        for(int j = 0; j < 5; ++j) {
            int random_zn = rand() % 100 + 1;
            matrix[i][j] = (matrix[i][j] + VARIANT + j - i) * random_zn;
        }
    }

    cout << "Нова матриця:" << endl;
    for(const auto &row : matrix) {
        for(double value : row) {
            cout << value << "\t";
        }
        cout << endl;
    }
    return matrix;
}

vector<double> function_3(const vector<vector<double>> &tower) {
    vector<double> min_elements(5, 0.0);

    for(int j = 0; j < 5; ++j) {
        double min_1 = tower[0][j];
        double min_2 = tower[0][j];

        for(int i = 1; i < 5; ++i) {
            if(tower[i][j] < min_1) {
                min_1 = tower[i][j];
            }
        }

        min_2 = *min_element(tower.begin(), tower.end());
        
    }
}

int main() {
    double x = function_1();
    cout << "Результат 1: " << x << endl;
    vector<vector<double>> tower = function_2(x);
    return 0;
}