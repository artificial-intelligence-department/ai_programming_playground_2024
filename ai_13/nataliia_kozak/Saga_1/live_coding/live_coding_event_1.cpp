#include <iostream>
#include <algorithm>
using namespace std;
const int V = 66;
float function_1()
{
    float a, b;
    int c, d, e;
    double f;
    cin >> a >> b >> c >> d >> e >> f;
    double array[6] = {a, b, (double)c, (double)d, (double)e, f};
    sort(array, array + 5);
    double max_sum = 0, min_sum = 0;
    for (int i = 0; i < 3; i++)
    {
        min_sum += array[i];
    }
    for (int i = 3; i < 6; i++)
    {
        max_sum += array[i];
    }
    double result;
    if (max_sum > min_sum * 2)
    {
        result = max_sum * min_sum;
    }
    else if (max_sum > min_sum * 3)
    {
        if (min_sum != 0)
        {
            result = max_sum / min_sum;
        }
        else
        {
            cout << endl
                 << "Division by 0";
            result = 1;
        }
    }
    else if (max_sum > min_sum * 4)
    {
        result = min_sum + max_sum;
    }
    else
    {
        cout << "No condition was satisfied";
        result = 1;
    }
    result /= V;
    cout << endl
         << "Result: " << result;
    return result;
}
struct ARRAY_2D
{
    float array[5][5];
};
ARRAY_2D function_2(float &x)
{
    ARRAY_2D arr;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            arr.array[i][j] = x;
        }
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            arr.array[i][j] = arr.array[i][j] + V + j - i * (rand() % 100 + 1);
        }
    }
    for (int i = 0; i < 5; i++)
    {
        cout << endl;
        for (int j = 0; j < 5; j++)
        {
            cout << arr.array[i][j] << ' ';
        }
    }
    return arr;
}
float* function_3(ARRAY_2D matrix){
    float* a1 = new float[5];
    float* a2 = new float[5];
    float min;
    for(int i = 0; i < 5; i++){
        min = matrix.array[0][i];
        for(int j = 0; j < 5 ; j++){
            if(matrix.array[j][i] < min){
                min = matrix.array[j][i];
            }
        }
        a1[i] = min;
    }
    for(int i = 0; i < 5; i++){
        sort(matrix.array[i], matrix.array[i] + 4);
        a2[i] = matrix.array[i][0];
    }
    for(int i = 0 ; i < 5; i++){
        if(a1[i] != a2[i]){
            cout << "Results not equal";
        }
    }
}
int main()
{
    float x = function_1();
    ARRAY_2D tower;
    tower = function_2(x);
    function_3(tower);
}