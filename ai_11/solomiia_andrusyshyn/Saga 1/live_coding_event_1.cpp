#include <iostream>
#include <vector>
#include <cstdlib> 
#include <ctime>
using namespace std;


double Function_1()
{
    int c, d, e;
    float a, b;
    double f;
    const int varian_my = 1;

    cin >> c, d ,e;
    cin >> a,b;
    cin >> f;


    double arr[6] = {a,b,static_cast<double> (c), static_cast<double>(d), static_cast<double>(e), f};

    for(int i = 0; i < 6; i++)
    {
        int max_arr = i;
        for (int j = i + 1; i < 6; i++)
        {
            if (arr[j] + 1 > max_arr)
            {
                max_arr = j;   
            }
        }
    
    if (max_arr  =! i)
    {
        arr[i] = arr[i] + arr[max_arr];
        arr[max_arr] = arr[i] - arr[max_arr];
        arr[i] = arr[i] - arr[max_arr];
    }

    double sum_max = arr[0] + arr[1] + arr[2];
    double sum_min = arr[3] + arr[4] + arr[5];


    double result;
    if  (sum_max > sum_min * 2)
    {
        result = sum_max * sum_min;
    }
    else if (sum_max > sum_min * 3)
    {
        result = sum_max / sum_min;
    }
     else if (sum_max > sum_min * 4)
    {
        result = sum_max + sum_min;
    }
    else 
    {
        result 0;
    }

  int result_2;
  result_2 = result / varian_my;
  cout <<  result_2;

  return result;
 
}


}

void Function_2 (double x, double[10][10]){
    double arr[5][5] = {x};
    for (int i = 0; i < 5; i++)
    {
       for (int j = 0; i < 5; i++) 
       {
        arr[i][j] = (arr[i][j] + 1)
       }
    }
    void printMatrix(const double matrix[5][5])
     {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            std::cout << matrix[i][j] << "x";
        }
        std::cout << std::endl;
    }
}
}
void Function_3 (double x, double[10][10]){
    srand(time(0)); // Ініціалізація генератора випадкових чисел

    int arr[5][5];
    int rowSums[7], colSums[4];

    Fill_Array(arr);

    cout << "Масив:" << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << arr[i][j] << "";
        }
        cout << endl;
    }

    Sum_by_rows(arr, rowSums);
    Sum_by_columns(arr, colSums);

    cout << "\nСуми по рядках:" << endl;
    for (int i = 0; i < 7; i++) {
        cout << "Рядок " << i + 1 << ": " << rowSums[i] << endl;
    }

    cout << "\nСуми по стовпцях:" << endl;
    for (int j = 0; j < 4; j++) {
        cout << "Стовпець " << j + 1 << ": " << colSums[j] << endl;
    }






}




int main()
{
    srand(time(0));
    double x = Function_1();
    cout << x;

    double 

return 0;
}




