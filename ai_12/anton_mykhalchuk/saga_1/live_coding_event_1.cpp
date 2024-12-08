#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int var = 47;



double function_1() {
    float a, b;
    int c, d, e;
    double f;

    cout << "Enter 2 numbers: ";
    cin >> a >> b;

    cout << "Enter 3 numbers: ";
    cin >> c >> d >> e;
    static_cast<double>(c);
    static_cast<double>(d);
    static_cast<double>(e);

    cout << "Enter 1 number: ";
    cin >> f;

    double arr[6] = {a, b, f, c, d, e};
    bool swapped;
    for (int i = 0; i < 6 - 1; i++)
    {
        swapped = false;
        for (int j = 0; j < 6 - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                double temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }

    double sumMin = 0, sumMax = 0;

    for (int i = 0; i < 3; i++) {
        sumMin += arr[i];
    }
    for (int i = 3; i < 6; i++) {
        sumMax += arr[i];
    }

    double out = 0;

    if (sumMax > sumMin * 2) {
        out = sumMin*sumMax;
    }
    else if (sumMax > sumMin * 3) {
        if (sumMin != 0) {
            out = sumMax / sumMin;
        }
        else if (sumMax != 0) {
            out = sumMin / sumMax;
        }
    }
    else if (sumMax > sumMin * 4) {
        out = sumMax + sumMin;
    }

    double x = out / var;

    return x;

}


double** function_2(double x) {
    double** arr2 = new double*[5];
    for (int i = 0; i < 5; i++) {
        arr2[i] = new double[5];
        for (int j = 0; j < 5; j++) {
            arr2[i][j] = x; 
        }
    }

    srand(time(nullptr));

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int randomValue = rand() % 99 + 1;
            arr2[i][j] += var + i + j + randomValue; 
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << arr2[i][j] << "   ";
        }
        cout << endl;
    }

    return arr2;
}


double** function_3(double** arr) {
    double out[5];

    
}

int main() {

    cout << "Task 1" << endl;
    double x = function_1();
    cout << x << endl << endl;

    cout << "Task 2" << endl;

    double** tower = function_2(x);

    cout << endl << endl;

    cout << "Task 3" << endl;

    function_3(tower);


    return 0;


}