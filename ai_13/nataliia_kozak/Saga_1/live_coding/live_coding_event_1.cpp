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
    sort(array, array + 6);
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
float *function_3(ARRAY_2D matrix)
{
    float *a1 = new float[5];
    float *a2 = new float[5];
    float min;
    for (int i = 0; i < 5; i++)
    {
        min = matrix.array[0][i];
        for (int j = 0; j < 5; j++)
        {
            if (matrix.array[j][i] < min)
            {
                min = matrix.array[j][i];
            }
        }
        a1[i] = min;
    }
    float column[5];
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            column[j] = matrix.array[j][i];
        }
        sort(column, column + 5);
        a2[i] = column[0];
    }
    for (int i = 0; i < 5; i++)
    {
        if (a1[i] != a2[i])
        {
            cout << endl
                 << "Results not equal";
            // break;
        }
    }
    return a1;
}
struct Student{
    string name, surname;
    float money;
    Student* next;
    Student* previous;
};
Student* function_4(float* a){
    Student* array = new Student[7];
    for(int i = 0; i < 7; i++){
        array[i].name = "Nata";
        array[i].surname = "Kozak";
    }
    sort(a, a+5);
    array[0].money = a[4];
    float sum = 0;
    int index = 0;
    for(int i = 1; i < 6; i++){
        sum += a[index++];
        array[i].money = sum;
    }
    array[6].money = a[0];
    for(int i = 0; i < 7; i++){
        cout << endl;
        cout << array[i].name << " "<< array[i].surname << " "<< array[i].money;
    }
    return array;
}
int main()
{
    float x = function_1();
    ARRAY_2D tower;
    tower = function_2(x);
    float *array;
    array = function_3(tower);
    Student* stud_array;
    stud_array = function_4(array);
    function_5
}