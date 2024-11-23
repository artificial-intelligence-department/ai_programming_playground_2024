//vns task 4 V-7
#include<iostream>
using namespace std;

int main()
{
    int n, sum = 0;
    
    cout<<"Введіть кінцеве число ряду: ";
    cin>>n;

    for (int i = 1; i < n; i+= 2)
    {
        sum += i;
    }
    
    cout<<"Сума ряду: "<<sum<<endl;

    return 0;
}