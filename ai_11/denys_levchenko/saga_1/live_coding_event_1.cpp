#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <limits>

const int VARIANT = 15;
using namespace std;
int function_1(){
    double a, b, f;
    int c, d, e;
    double result;

    cout << "Enter a b" << endl;
    cin >> a >> b;
    cout << "Enter c d e" << endl;
    cin >> c >> d >> e;
    cout << "Enter f" << endl;
    cin >> f;
    
    vector<double> numbers = {a, b, static_cast<double>(c), static_cast<double>(d), static_cast<double>(e), f};

    std::sort(numbers.begin(), numbers.end());
    double largesum = numbers[3] + numbers[4] + numbers[5];
    double smallsum = numbers[0] + numbers[1] + numbers[2];
    
    if(largesum > smallsum*2){
        result = largesum*smallsum;
    } else if(largesum > smallsum*3){
        result = largesum/smallsum;
    } else if(largesum > smallsum*4){
        result = largesum + smallsum;
    }

    result /= VARIANT;
    std::cout << "Result: " << result << endl;
    return result; 
}

void function_2(double& x, double matrix[5][5]){
    for (int i = 0; i < 5; ++i){
        for (int j = 0; j < 5; ++j){
            matrix[i][j] = x;
        }
    }

    for (int i = 0; i < 5; ++i){
        for (int j = 0; j < 5; ++j){
            matrix[i][j] = (matrix[i][j] + VARIANT + j - i) * (rand() % 100 + 1);
        }
    }
    cout << "New matrix:" << endl;
    for (int i = 0; i < 5; ++i){
        for (int j = 0; j < 5; ++j){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int* function_3(int tower[5][5]){
    static int result[5];

    for (int col = 0; col < 5; col++) {
        int min1 = numeric_limits<int>::max();
        int min2 = numeric_limits<int>::max();

        for (int row = 0; row < 5; row++) {
            if (tower[row][col] < min1) {
                min1 = tower[row][col];
            }
        }
    min2 = *min_element(&tower[0][col], &tower[5][col]);
    
    if (min1 != min2){
        cout << "search" << col + 1 << "not match" << endl;
    } else {
        cout << "search" << col + 1 << "match" << endl;
    }

    result[col] = min1;
}
    return result;
}

int main(){
    double x = function_1();
    double matrix[5][5];
    function_2(x, matrix);
    int tower[5][5];
    int* result = function_3(tower);
    cout << "minimal elements: ";
    for (int i = 0; i < 5; i++){
        cout << result[i] << " ";
    
    }
    return 0;
}
