#include <iostream>

int main()
{
    int n1, a, b, c;
    std::cin >> n1;
    int* arr1=new int[n1];
    for(int i=0; i<n1; i++)
    {
        std::cin >> arr1[i];
    }
    std::cin >> a >> b >> c;
    int arr2[10000];
    int n2=0;
    for(int i=0; i<n1; i++)
    {
        if(arr1[i]!=a && arr1[i]!=b && arr1[i]!=c)
        {
            arr2[n2++]=arr1[i];
        }
    }
    int arr3[10000];
    int n3=0;
    for (int i=0; i<(n2-1); i++)
    {
        arr3[n3++]=arr2[i]+arr2[i+1];
    }
    std::cout << n3 << std::endl;
    for(int i=0; i<n3; i++)
    {
        std::cout << arr3[i] << " ";
    }
}