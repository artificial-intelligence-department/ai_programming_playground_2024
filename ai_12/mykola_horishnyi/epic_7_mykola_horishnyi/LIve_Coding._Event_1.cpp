#include <iostream>
#include <algorithm>
using namespace std;


void function_1(double a, double b, double f, int c, int d, int e) {
    double numbers[6] = { a, b, f, static_cast<double>(c), static_cast<double>(d), static_cast<double>(e) };

    sort(numbers, numbers + 6);

    cout << "3 min numbers: ";
    for (int i = 0; i < 3; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    for (int i = 3; i < 6; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    double minSum = numbers[0] + numbers[1] + numbers[2];
    double maxSum = numbers[3] + numbers[4] + numbers[5];

    cout << "Min sum: " << minSum << endl;
    cout << "Max sum: " << maxSum << endl;

    double relust = 0;
    if (maxSum > minSum * 2) {
        double result = minSum + maxSum;
        cout << "Sum of min and max: " << result << endl;
    }
    else if (maxSum > minSum * 3) {
        if (minSum != 0) {
            double result = maxSum / minSum;
            cout << "Max sum divided min sum: " << result << endl;
        }
        else {
            cout << " I cant do it " << endl;
        }
    }
    else if (maxSum > minSum * 2) {
        double result = minSum * maxSum;
        cout << ": " << result << endl;
    }
    else {
        cout << "" << endl;
    }
    return result;
}

int main() 
{
    double a, b, f;
    int c, d, e;

    cout << "Enter number a, b, f ";
    cin >> a >> b >> f;
    cout << "Enter number c, d, e ";
    cin >> c >> d >> e;


    double x = function_1 (a, b, c, d, e, f);


    function_2(x);

    int matrix[5][5];
    cout << "fill matrix" << x;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            matrix[i][j] = x;
            cout << matrix[i][j] << " ";

        }
        cout << endl;

    }
    int var = 34;

    cout << "new matrix" << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            matrix[i][j] = matrix[i][j] + var + j - i;
            cout << matrix[i][j];
        }
        cout << endl;
    }


    return 0;
}




