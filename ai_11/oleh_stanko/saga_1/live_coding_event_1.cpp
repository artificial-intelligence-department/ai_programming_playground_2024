#include <iostream>
#include <random>

using namespace std;

const int var = 24;

double function_1()
{
    float a,b;
    cin >> a >> b;
    int c,d,e;
    cin >> c >> d >> e;
    double f;
    cin >> f;
    double arr[6] = {a,b,c,d,e,f};
    for (int i=0; i<6; i++)
    {
        bool was_changed=0;
        for (int j=0; j<6; j++)
        {
            if (arr[j]<arr[j+1])
            {
                double temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                was_changed=1;
            }
        } 
        if (!was_changed)
        {
            break;
        }
    }
    cout << arr[0] << arr[1] << arr[2] << endl;
    cout << arr[3] << arr[4] << arr[5] << endl;
    double smax = arr[0] + arr[1] + arr[2];
    double smin = arr[3] + arr[4] + arr[5];
    
    double x=0;
    if (smax > smin*4)
    {
        x = smax + smin;
    }
    else if (smax > smin*3)
    {
        x = smax / smin;
    }
    else if (smax > smin*2)
    {
        x=smax*smin;
    }  
    x /= var;
    cout << x;
    return x;
} 

double function_2(double* x)
{
    double matrix[5][5];
    for (int i; i<5; i++)
    {
        for (int j; j<5; j++)
        {
            matrix[i][j]=*x;
        }
    }
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 500);

    for (int i; i<5; i++)
        {
        for (int j; j<5; j++)
        {
            matrix[i][j]=((matrix[i][j]+var+j-i)*rand()%100+1);

        }
    }  
}

int main()
{
    double x = function_1();
    function_2(&x);
}