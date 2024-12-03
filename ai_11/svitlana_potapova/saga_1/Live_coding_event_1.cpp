#include <iostream> 
#include <vector>
using namespace std;

const int variant = 20;

int function_1(){
    float a, b;
    int c, d, e;
    double f;
    vector<double> arr;

    cout << "Введіть числа" << endl;
    cin >> a >> b >> c >> d >> e >> f;
    arr.push_back(a);
    arr.push_back(b);
    arr.push_back(c);
    arr.push_back(d);
    arr.push_back(e);
    arr.push_back(f);

    double maxSum, minSum;

    for(int i=0; i<6; i++){
        for(int k=0; k<5; k++){
            if(arr[k]>arr[k+1]){
                swap(arr[k], arr[k+1]);
            }
        }
    }

    for(int i=0; i<3; i++){
        minSum+=arr[i];
    }
    
    for(int i=3; i<6; i++){
        maxSum+=arr[i];
    }

    cout << "Сума найібльших: " << maxSum << endl;
    cout << "Сума найменших: " << minSum << endl;

    double x;
    
    if(maxSum>minSum*2){
        x = (maxSum*minSum) / variant;
    }
    else if(maxSum>minSum*3){
        x = (maxSum/minSum) / variant;
    }
    else if(maxSum>minSum*4){
        x = (maxSum+minSum) / variant;
    }

    return x;
}

vector<vector<double>> function_2(double &x){
    vector<vector<double>> matrix(5, vector<double>(5,x));

    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            matrix[i][j] = (x+variant+j-i)* (rand()%100+1);
        }
    }

    cout << "Елементи матриці: " << endl;
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return matrix;
}

vector<double> function_3(vector<vector<double>> &tower){
    vector<double> res;
    double min2;
    for(int i=0; i<5; i++){
        double min = tower[0][i];
        for(int j=0; j<5; j++){
            if(tower[j][i] < min){
                min = tower[j][i];
            }
        } 
        for(int j=0; j<5; j++){
            for(int k=0; k<4; k++){
                if(tower[k][i]> tower[k+1][i]){
                    swap(tower[k][i], tower[k+1][i]);
                }
            }
        }
        min2 = tower[0][i];
        if(min == min2){
            cout << "Результати співпадають" << endl;
        }
        res.push_back(min);
    }

    return res;
}



int main(){
    double x = function_1();

    cout << "Значення з функції №1: " << x << endl;

    vector<vector<double>> tower = function_2(x);

    vector<double> minEls = function_3(tower);
    for(double num : minEls){
        cout << num << " ";
    }


    return 0;




}