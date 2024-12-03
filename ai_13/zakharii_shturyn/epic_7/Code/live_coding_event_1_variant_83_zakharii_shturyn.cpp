#include <iostream>
#include <algorithm>
using namespace std;

double function_1() {
    double a,b;
    int c,d,e;
    double f;
    cin >> a >> b >> c >> d >> e >> f;
    double arr[6] = {a,b,double(c),double(d),double(e),f};

    sort(arr, arr + 6);

    double biggersum = arr[3] + arr[4] + arr[5];
    double smallersum = arr[0] + arr[1] + arr[2];
    double res = 0;

    if(biggersum > smallersum * 4) {
        res = biggersum* smallersum;
    } else if(biggersum > smallersum * 3) {
        if(smallersum != 0) {
            res = biggersum / smallersum;
        } else {
            cout << "Ділення на нуль недоступне" << endl;
        }
    } else if(biggersum > smallersum * 2) {
        res = biggersum + smallersum;
    } else {
        cout << "Не задовільняється жодна з умов" << endl;
    }


    res /= 83;

    return res;
}

double** function_2(double x) {

    double** array2D = 0;
      array2D = new double*[5];
    
      for (int h = 0; h < 5; h++)
      {
            array2D[h] = new double[5];
    
            for (int w = 0; w < 5; w++)
            {
                  array2D[h][w] = x;
            }
      }

    for (int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            array2D[i][j] = (array2D[i][j] + 83 + j + i) * (rand() % 101);
            cout << array2D[i][j] << " ";
        }
        cout << endl;
    }

    return array2D;
}

double** function_3(double** tower) {
    double arr[5];
    double arr1min[5];
    double arr2min[5];
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            arr[j] = tower[j][i];
        }
        sort(arr, arr + 5);
        arr1min[i] = arr[0];

        sort_heap(arr, arr + 5);
        arr2min[i] = arr[0];
    }
}

int main() {

    double x = function_1();
    double** tower = function_2(x);
    function_3(tower);

    return 0;
}