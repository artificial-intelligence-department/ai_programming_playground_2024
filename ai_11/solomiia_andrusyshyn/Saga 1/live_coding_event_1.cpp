#include <iostream>
#include <vector>
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

int main()
{
    double x = Function_1();
    cout << x;

return 0;
}




