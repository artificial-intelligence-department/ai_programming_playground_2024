#include <iostream>
#include <ctime>
using namespace std;

const int variant = 36;

float function_1(){
    float a,b;
    int c,d,e;
    double f;

    cout << "Enter 2 float numbers: \n ";
    cin >> a >> b; // читаємо з калвіатури
    cout << "Enter 3 int numbers: \n ";
    cin >> c >> d >> e; 
    cout << "Enter float number: \n ";
    cin >> f; 
    double arr[] = {(double)a, (double)b, (double)c, (double)d, (double)e, (double)f};

    for(int i = 0; i < 6; ++i){
        for(int j = 0; j > 6 - i - 1; ++j){
            if(arr[j] < arr[j - 1]){
                swap(arr[j], arr[j - 1]);  // buble sort
            }
        }
    }

    double sum_min = 0;
    double sum_max = 0;

    cout << "3 maximum numbers:" << endl;
    for(int i = 3; i < 6; ++i){
        cout << arr[i] << ", ";
        sum_max += arr[i];
    }
    cout << endl;

    cout << "3 minimum numbers:" << endl;
    for(int i = 0; i < 3; ++i){
        cout << arr[i] << ", ";
        sum_min += arr[i];
    }

    cout << endl;

    double sum = 0;
if(sum_min != 0){
    if(sum_max > sum_min * 2){
        sum = sum_max * sum_min;
    } else if(sum_max > sum_min*3){
        sum = sum_max / sum_min;
    } else if(sum_max > sum_min * 4){
        sum = sum_max + sum_min;
    }
}
    double x = sum / variant;

    cout << "Final sum = " << x << endl;

    return x;
}

float** function_2(double x){
    srand(static_cast<unsigned>(time(nullptr)));
    float** matrix = new float*[5];

    for(int i = 0; i < 5; ++i){
        matrix[i] = new float[5];
    }

    for(int i = 0; i < 5; ++i){
        for(int j = 0; j < 5; ++j){
            cout << x << " ";
        }
        cout << endl;
    }
    for(int i = 0; i < 5; ++i){
        for(int j = 0; j < 5; ++j){
            matrix[i][j] = x + variant + j - (i * rand() % 100);
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return matrix;
}

float* function_3(float** tower){
    float* min_elements = new float[5];
    float min_elements_new[5];

    for(int j = 0; j < 5; ++j){
        float min_value = tower[0][j];
        for(int i = 1; i < 5; ++i){
            if(tower[i][j] < min_value){
                min_value = tower[i][j];
            }
        }
        min_elements[j] = min_value;
    }
    cout << endl << "First method: ";
    for(int i = 0; i < 5; ++i){
        cout << min_elements[i] << " ";
    }
    cout << endl;

// another method
    for(int j = 0; j < 5; ++j){
        min_elements_new[j] = tower[0][j];
        for(int i = 1; i<5; ++i){
            min_elements_new[j] = min(min_elements_new[j], tower[i][j]);
        }
    }
    cout << endl << "Another method: \n";
    for(int i = 0; i < 5; ++i){
        cout << min_elements[i] << " ";
    }
    cout << endl;

    bool are_same = true;
    for(int i = 0; i < 5; ++i){
        if(min_elements[i] != min_elements_new[i]){
            are_same = false;
            break;
        }
    }
    if(are_same){
        cout << "Results of two searches are the same " << endl;
    } else{
        cout << "Results aren't the same! " << endl;
    }

}

int main(){
    float x = function_1();
    cout << endl;
    float** tower = function_2(x);
    float* min_elements = function_3(tower);



    return 0;
}