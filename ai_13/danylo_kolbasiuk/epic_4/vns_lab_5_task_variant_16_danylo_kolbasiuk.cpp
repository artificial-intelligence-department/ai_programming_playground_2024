#include <iostream>
#include <algorithm>

void sort(int** array, int n)
{
    for (int i=0; i<n; i++) {
        int* temp=new int[n];
        for (int j=0; j<n; j++) {
            temp[j] = array[j][i];
        }
        std::sort(temp, temp + n, std::greater<int>());
        for (int j = 0; j<n; j++) {
            array[j][i]=temp[j];
        }
        delete[] temp;
    }
    
}
int main()
{
    int n;
    std::cin >> n;
    int** arr = new int*[n];
    for(int i=0; i<n; i++)
    {
        arr[i]=new int[n];
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            std::cin >> arr[i][j];
        }
    }
    sort(arr, n);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
    bool diagonal=true;
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-1; j++)
        {
            if(arr[i][j]<=arr[i+1][j+1])
            {
                diagonal=false;
                break;
            }

        }
    }
    if(diagonal)
    {
        std::cout << "It's possible to sort the columns in a way that the side diagonal goes from lowest to highest.";
    }
    else
    {
        std::cout << "It's not possible to sort the columns in a way that the side diagonal goes from lowest to highest.";
    }
    for(int i=0; i<n; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
    return 0;
}