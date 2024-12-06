#include <iostream>

using namespace std;
const int var = 37; // варіант
float function_1()
{
    float a, b;
    cin >> a >> b;
    int c, d, e;
    cin >> c, d, e;
    double f;
    cin >> f;
    double array[6];
    array[0] = a;
    array[1] = b;
    array[2] = c;
    array[3] = d;
    array[4] = e;
    array[5] = f;
    sort(array, array + 6);
    double array1[3];
    array1[0] = array[0];
    array1[1] = array[1];
    array1[2] = array[2];

    double array2[3];
    array2[0] = array[3];
    array2[1] = array[4];
    array2[2] = array[5];
    double sum1 = 0; // найменших
    for (int i = 0; i < 3; i++)
    {
        sum1 += array1[i];
    }
    double sum2 = 0; // найбільших
    for (int i = 0; i < 3; i++)
    {
        sum2 += array2[i];
    }
    double result;
    if (sum2 > sum1 * 4)
    {
        result = sum1 + sum2;
    }
    if (sum2 > sum1 * 3)
    {
        result = sum2 / sum1;
    }
    if (sum2 > sum1 * 2)
    {
        result = sum1 * sum2;
    }
    float x = result / var;
    cout << x << endl;
    return x;
}

float** function_2(float &x)
{
    int size = 5;
float **arraymatrix = new float*[size];
for(int i = 0; i < size; i ++){
    arraymatrix[i] = new float[size];
for(int j = 0; j < size; j ++){
arraymatrix[i][j] = x;
};
}
srand(100);
for(int i = 0; i < size; i ++){
for(int j = 0; j < size; j ++){
arraymatrix[i][j] = (arraymatrix[i][j] + float(var) + float(i) + float(j)) * rand();
}}
for(int i = 0; i < size; i ++){
for(int j = 0; j < size; j ++){
cout << arraymatrix[i][j] << " ";
};
cout << endl ;
}
return arraymatrix;
};

float function_3(float tower){
int array[5];
for(int i = 0; i < 5; i ++){

}
}

int main()
{
    float x = function_1();
    float** tower= function_2(x);


    return 0;
}