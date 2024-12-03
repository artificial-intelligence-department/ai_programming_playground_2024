#include <iostream>
#include <vector>
#include <ctime>
using namespace std;
double function_1();
void Sort(vector<double>& arr);
vector<vector<double>> function_2(double &x);
void ShowArray(vector<vector<double>> &arr, double x);

int main()
{
    srand(time(NULL));
    double x = function_1(); 
    vector<vector<double>> matrix = function_2(x); 
    ShowArray(matrix, x);

    return 0;
}

double function_1()
{
    double a, b, f;
    int c, d, e;
    cin >> a >> b >> f >> c >> d >> e;
    vector<double> numbers = {a, b, static_cast<double>(c), static_cast<double>(d), static_cast<double>(c),f};
    Sort(numbers);

    double min = numbers[0] + numbers[1] + numbers[2];
    //cout << "Min value of 3 number: " << min;
    double max = numbers[3] + numbers[4] + numbers[5];
    //cout << "Max value of 3 number: " << max;

    double result = 0;
    if ( max > min*2 )
    {
        result = max*min;
    }
    else if ( max > min*3 )
    {
        result = max/min;
    }
    else if (  max > min*4 )
    {
        result = max + min;
    }
    
    return result/3;
}
vector<vector<double>> function_2(double &x)
{
    vector<vector<double>> arr(5, vector<double>(5, x));

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
            arr[i][j] = (x + 3 + j - i) * (rand() % 100 + 1);
        }    
    }  

    return arr;
     
}
void ShowArray(vector<vector<double>> &arr, double x)
{
    vector<vector<double>> matrix = function_2(x);
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
}
void Sort(vector<double>& arr)
{
    int count = arr.size();
    for (int i = 0; i < count - 1; i++){
        for (int j = i + 1; j < count; j++){
            if(arr[j] < arr[i]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}