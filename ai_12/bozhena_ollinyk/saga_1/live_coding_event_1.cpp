#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdlib.h>

using namespace std;

// в коді використана як мінімум одна цілочисельна змінна
// в коді використана як мінімум одна дійсна змінна
// в коді використана як мінімум одна дійсний з подвійною точністю змінна
// в коді використана як мінімум одна цілочисельна константа
// в коді використані умовні оператори та розгалуження
// в коді використаний одновимірний масив
// в коді використаний двовимірний масив
// в коді використаний do while цикл
// в коді використаний while цикл
// в коді використаний for цикл
// в коді використано оператори break і continue
// в коді використано перевантаження функції
// в коді використано рекурсивну функцію
// в коді використано параметри та аргументи функції
// в коді використано математичні операції та математичні функції
// в коді використано функції роботи з файлами, для того, щоб записати у файл
// в коді використано функції роботи з файлами, для того, щоб зчитати з файлу
// в коді використано оператори виведення та введення даних
// в коді використано свою структуру даних
// в коді використано вказівники
// в коді не можна використовувати вектори

double function_1()
{
    float a, b;
    int c, d, e;
    double f;
    cin >> a >> b;
    cin >> c >> d >> e;
    cin >> f;

    const int length = 6;

    double arr[length] = {a, b, c, d, e, f};

    double min1, min2, min3, max1, max2, max3;

    int n = sizeof(arr) / sizeof(arr[0]);

    sort(arr, arr + n); //сортуєм масив
    min1 = arr[1];// перший мінімум перший елемент посортованого масиву
    max1 = arr[length];// найбільший елемент = останній елемент посортованого масиву
    for (int i = 1; i < length; i++){ // шукаєм другий найменшйи елемент
        if(arr[i] > min1){
            min2 = arr[i];
        }
    }for (int i = 2; i < length; i++){ //шукаєм третій найменший елемент
        if(arr[i] > min1 && arr[i] > min2){
            min3 = arr[i];
        }
    }
    for (int i = length; i >= 0; i--){ // шукаєм ругий найбльший елемент
        if(arr[i] < max1){
            max2 = arr[i];
        }
    }for (int i = length; i >= 0; i--){ // шукаєм третій найбільший елемент
        if(arr[i] < max1 && arr[i] < max2){
            max3 = arr[i];
        }
    }

    // for (int i = 0; i < length; i++)
    // {
    //     bool minimum1 = true;
    //     bool maximum1 = true;
    //     bool minimum2 = true;
    //     bool maximum2 = true;
    //     bool minimum3 = true;
    //     bool maximum3 = true;
    //     for (int j = 0; j < length; j++)
    //     {
    //         if (arr[i] < arr[j])
    //         {
    //             maximum1 = false;
    //         }
    //         if (arr[i] > arr[j])
    //         {
    //             minimum1 = false;
    //         }
    //     }
    //     if (maximum1)
    //     {
    //         max1 = arr[i];
    //     }
    //     if (minimum1)
    //     {
    //         min1 = arr[i];
    //     }
    // }

    // for (int i = 0; i < length; i++)
    // {
    //     bool minimum2 = false;
    //     bool maximum2 = false;
    //     for (int j = 0; j < length; j++)
    //     {
    //         if (arr[i] == max1 || arr[i] == min1)
    //         {
    //             continue;
    //         }
    //         if (arr[i] > arr[j] && arr[i] < max1)
    //         {
    //             maximum2 = true;
    //         }
    //         if (arr[i] < arr[j] && arr[i] > min1)
    //         {
    //             minimum2 = true;
    //         }
    //     }
    //     if (maximum2)
    //     {
    //         max2 = arr[i];
    //     }
    //     if (minimum2)
    //     {
    //         min2 = arr[i];
    //     }
    // }

    // for (int i = 0; i < length; i++)
    // {
    //     bool minimum3 = false;
    //     bool maximum3 = false;
    //     for (int j = 0; j < length; j++)
    //     {
    //         if (arr[i] == max1 || arr[i] == max2 || arr[i] == min1 || arr[i] == min2){
    //             continue;
    //         }
    //         if (arr[i] < arr[j] && arr[i] > min1 && arr[i] > min2){
    //             minimum3 = true;
    //         }
    //         if (arr[i] > arr[j] && arr[i] < max1 && arr[i] < max2){
    //             maximum3 = true;
    //         }
    //         continue;
    //     }
    //     if (maximum3)
    //     {
    //         max3 = arr[i];
    //     }
    //     if (minimum3)
    //     {
    //         min3 = arr[i];
    //     }
    // }

    cout << max1 << " " << min1 << endl;
    cout << max2 << " " << min2 << endl;
    cout << max3 << " " << min3 << endl;

    double result;
    const int var = 48;
// перевіряєм умови і в заоежності від них виводи та повертаєм результат
    if ((max1 + max2 + max3) > (min1 + min2 + min3) * 2)
    {
        double mnoz = (max1 + max2 + max3) * (min1 + min2 + min3);
        result = mnoz / var;
    }
    if ((max1 + max2 + max3) > (min1 + min2 + min3) * 3)
    {
        double dev = (max1 + max2 + max3) / (min1 + min2 + min3);
        result = dev / var;
    }
    if ((max1 + max2 + max3) > (min1 + min2 + min3) * 4)
    {
        double sum = (max1 + max2 + max3) + (min1 + min2 + min3);
        result = sum / var;
    }

    cout << result;
    return result;
}

// double *function_2(double x){
//     srand( (unsigned)time(NULL));
//     double arrX[5][5] = {x};
//     for (int i = 0; i < 5; i++){
//         for (int j = 0; j < 5; j++){
//             double newVal = (arrX[i][j] + 48 + j - i) * rand() % 100 + 1;
//             arrX [i][j] = newVal;
//             cout << arrX[i][j] << " ";
//         }
//         cout << endl;
//     }

//     return arrX;
// }

double function_3(double tower[5][5]){
    double arr[5];
    arr[1] =  min (tower[1][1], tower [5][1]);
    arr[2] =  min (tower[1][2], tower [5][2]);
    arr[3] =  min (tower[1][3], tower [5][3]);
    arr[4] =  min (tower[1][4], tower [5][4]);
    arr[5] =  min (tower[1][5], tower [5][5]);
    for (int i = 0; i < 5; i++){
        cout << arr[i] << " ";
    }
}

int main()
{
    int x = function_1();
    // double tower [5][5] = function_2(x);
    function_3(tower);

    return 0;
}