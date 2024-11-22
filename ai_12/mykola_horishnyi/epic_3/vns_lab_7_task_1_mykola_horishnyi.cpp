#include <iostream>
using namespace std;


int sum(int count, int arr[])
{

    int result = 0;
    int previous = arr[0];

    for (int i = 1; i < count; ++i) 
    {
        int current = arr[i]; 
        result = result + previous * current;
        previous = current;
    }

    return result;
}

int main()
{
    int fibonacci5[] = { 1, 1, 2, 3, 5 };
    int fibonacci10[] = { 1, 1, 2, 3, 5, 8, 13, 21, 34, 55 };
    int fibonacci12[] = { 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144 };


    cout << "Sum for 5 elements Fibinacci: " << sum(5, fibonacci5) << endl;
    cout << "Sum for 10 elements Fibinacci : " << sum(10, fibonacci10) << endl;
    cout << "Sum for 12 elements Fibinacci : " << sum(12, fibonacci12) << endl;






    return 0;
}







