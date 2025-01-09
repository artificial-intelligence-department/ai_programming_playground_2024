#include <iostream>
#include <algorithm>
using namespace std;
const int variant = 64;
float function_1()
{
    float a, b;
    int c, d, e;
    double f;
    cin >> a >> b >> c >> d >> e >> f;
    float minSum = 0.0;
    float maxSum = 0.0;
    double arr[6] = {a, b, c, d, e, f};
    sort(arr, arr + 6);
    cout << "Min elems: ";
    for (int i = 0; i < 3; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\nMax elems: ";
    for (int i = 3; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    minSum = arr[0] + arr[1] + arr[2];
    maxSum = arr[3] + arr[4] + arr[5];
    float x = 0;
    if (maxSum > minSum * 2)
    {
        x = maxSum * minSum;
    }
    else if (maxSum > minSum * 3)
    {
        x = maxSum / minSum;
    }
    else if (maxSum > minSum * 4)
    {
        x = maxSum + minSum;
    }
    x /= variant;
    return x;
}

float **function_2(float &x)
{
    float **arr = new float *[5];
    for (int i = 0; i < 5; i++)
    {
        arr[i] = new float[5];
    }
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
            float newX;
            newX = x + variant + j - i;
            arr[i][j] = newX;
        }
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return arr;
}

float *function_3(float **tower)
{
    float *masiv = new float[5];
    float *masiv2 = new float[5];
    for (int i = 0; i < 5; i++)
    {
        float min = tower[i][0];
        for (int j = 0; j < 5; j++)
        {
            if (min > tower[i][j])
            {
                min = tower[i][j];
            }
            masiv[i] = min;
        }
        cout << endl;
    }
    int i = 0;
    float minimum;
    for (int j = 0; j < 5; j++)
    {
        minimum = min(tower[i][j], tower[i + 5][j]);
    }
    masiv2[i] = minimum;
    bool isEqual = true;
    for (int i = 0; i < 5; i++)
    {
        if (masiv[i] != masiv2[i])
        {
            isEqual = false;
            break;
        }
    }
    if (isEqual)
    {
        cout << "Equal!" << endl;
    }
    else
    {
        cout << "Not equal!" << endl;
    }
    return masiv;
}

int main()
{
    float x = function_1();
    cout << x << endl;
    float **tower = function_2(x);
    float *arr = function_3(tower);
}