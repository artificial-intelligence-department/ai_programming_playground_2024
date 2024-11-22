#include <iostream>
#include <cstdlib>

using namespace std;

int main() 
{
    int n;
    int Mas[100];
    
    cout << "Введіть розмір масиву: ";
    cin >> n;

    for (int i = 0; i < n; ++i) 
    {
        Mas[i] = rand(); 
    }

    cout << "Початковий масив: ";
    for (int i = 0; i < n; ++i) 
    {
        cout << Mas[i] << " ";
    }

    int mini = 0; 
    int maxi = 0;
    for (int i = 1; i < n; ++i) 
    {
        if (Mas[i] < Mas[mini]) 
        {
            mini = i;
        }
        if (Mas[i] > Mas[maxi]) 
        {
            maxi = i;
        }
    }
    
    int a = Mas[mini];
    Mas[mini] = Mas[maxi];
    Mas[maxi] = a;

    double sum = 0;
    for (int i = 0; i < n; ++i) 
    {
        sum += Mas[i];
    }

    double average = sum / n;
    double cond = average * 1.1; 

    int massz = 0;
    for (int i = 0; i < n; ++i) 
    {
        if (Mas[i] <= cond) 
        {
            Mas[massz++] = Mas[i];
        }
    }

    cout << endl << "Кінцевий масив: ";
    for (int i = 0; i < massz; ++i) 
    {
        cout << Mas[i] << " ";
    }
    cout << endl;
    
    return 0;

}