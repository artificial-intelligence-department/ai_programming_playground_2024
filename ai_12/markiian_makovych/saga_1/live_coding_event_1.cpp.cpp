#include <iostream>
#include <cstdlib>

using namespace std;

const double var = 46.0;

int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);

    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}
double function1()
{
    float a, b;
    double f;
    int c, d, e;
    cin >> a;
    cin >> b;
    cin >> c;
    cin >> d;
    cin >> e;
    cin >> f;
    int maxInt = 0;
    double arr[6] = {a, b, c, d, e, f};
    double min[3] = {};
    double max[3] = {};

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }

    for (int i = 0; i < 3; i++)
    {
        min[i] = arr[i];
    }
    for (int i = 0; i < 3; i++)
    {
        max[i] = arr[i + 3];
    }

    double sumMin = min[0] + min[1] + min[2];
    double sumMax = max[0] + max[1] + max[2];

    double mult;
    if (sumMax > sumMin * 2)
    {
        mult = sumMax * sumMin;
    }
    else if (sumMax > sumMin * 3)
    {
        mult = sumMax / sumMin;
    }
    else if (sumMax > sumMin * 4)
    {
        mult = sumMax + sumMin;
    }
    double x = mult / var;
    cout << x;

    return x;
}

double function2(double &x)
{
    float arr[5][5] = {};
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            arr[i][j] = x;
        }
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            arr[i][j] = (arr[i][j] + var + j - i) * getRandomNumber(1, 100);
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return **arr;
}

double function3(double *tower)
{
    double arr[5] = {};
    double min = 0.0;
    cout << tower[1];
}

int main()
{

    double x = function1();
    double tower = function2(x);
    function3(&tower);

    return 0;
}