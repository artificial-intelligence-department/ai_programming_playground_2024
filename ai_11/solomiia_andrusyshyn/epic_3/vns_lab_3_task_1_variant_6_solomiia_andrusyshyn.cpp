#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.141592653589793;
const double TOLERANCE = 0.0001;

double analyticalFunction(double x) 
{
    double angle_cos = cos(PI / 4);
    double angle_sin = sin(PI / 4);
    return exp(x * angle_cos) * cos(x * angle_sin);
}

double computeCoefficient(double x, int n) {
    double coefficient = 1.0;
    for (int i = 1; i <= n; i++) 
    {
        coefficient *= (x / i); // C_n = x^n / n!
    }
    return coefficient;
}

double computeSeriesTerm(double x, int n) {
    double angle_term = cos(n * PI / 4);    // cos(n * π / 4)
    double coefficient = computeCoefficient(x, n); // x^n / n!
    return angle_term * coefficient;       // S_n = cos(n * π / 4) * C_n
}

int main() 
{
    double start = 0.1, end = 1.0;
    int steps = 10;
    double increment = (end - start) / steps;

    for (double x = start; x <= end; x += increment) {
        double partialSumFixed = 1.0; 
        double partialSumTolerance = 1.0; 
        double currentTerm;

        for (int i = 1; i <= 25; i++) {
            currentTerm = computeSeriesTerm(x, i);
            partialSumFixed += currentTerm;
        }

        int termIndex = 1;
        while (true) {
            currentTerm = computeSeriesTerm(x, termIndex);
            if (abs(currentTerm) < TOLERANCE) break;
            partialSumTolerance += currentTerm;
            termIndex++;
        }

        cout << "X = " << x 
             << "\tSN = " << partialSumFixed 
             << "\tSE = " << partialSumTolerance 
             << "\tY = " << analyticalFunction(x) 
             << endl;
    }

    return 0;
}
