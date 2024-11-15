#include<iostream>
using namespace std;

int transformation (int n,...)
{
    int *p = &n;
    int num_10, num_8;

    while (n > 0)
    {
        p += 2;
        num_10 = *p;
        num_8 = 0;
        while (num_10 > 0)
        {
            num_8 = num_8 * 10 + num_10 % 8;
            num_10 /= 8;
        }
        while (num_8 > 0)
        {
            cout<<num_8 % 10;
            num_8 /= 10;
        }
        cout<<" ";
        n--;
    }
    
    cout<<endl;
    return 0;
}

int main()
{
    transformation(3, 21, 35, 16);
    transformation(5, 21, 35, 16, 46, 60);
    transformation(8, 21, 35, 16, 46, 60, 50, 33, 48);

    return 0;
}