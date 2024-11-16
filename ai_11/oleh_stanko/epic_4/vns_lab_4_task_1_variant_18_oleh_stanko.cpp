#include <iostream>

using namespace std;

int main()
{
    int n = 100;
    int a[n];
    int size;
    cout << "enter size of array: ";
    cin >> size;
    int k;
    cout << "enter by which position you want to rotate: ";
    cin >> k;
    cout << "enter numbers of array: ";
    for (int i = 0; i < size; i++)
    {
        cin >> a[i];
    }
    for (int i = k; i < k+size; i++)
    {
        
        cout << a[i%size] << " "  ;
    }
    int first;
    cout << "\nenter new first number of array: ";
    cin >> first;
    cout << "enter new last number of array: ";
    int last;
    cin >> last;
    for (int i = size; i > 0; i--) 
    { 
        a[i] = a[i - 1]; 
    }
    a[0] = first;
    a[size+1]=last;
    int b[size +1];
    int m=0;
    for (int i = 0; i < size+2; i++)
    {
        if (a[i]%2!=0)
        {
            b[m]=a[i];
            m++;
        }       
    }  
    cout << "Array after removing even elements: ";   
    for (int i = k; i < k+m; i++)
    {
        cout << b[i%m] << " ";
    }
}