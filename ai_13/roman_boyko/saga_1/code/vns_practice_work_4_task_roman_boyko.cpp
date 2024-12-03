#include <iostream>
using namespace std;

int main()
{
    int num, k = 0, sum = 0;
    double av;
    while (true)
    {
        cout << "Enter number: ";
        cin >> num;
        if (num <= 0)
        {
            break;
        }
        k++;
        sum += num;
    }
    if (k == 0)
    {
        cout << "The sequence doesn't have any elements!" << endl;
    }
    else
    {
        cout << "sum: " << sum << endl;
        av = static_cast<double>(sum) / k;
        cout << "average: " << av << endl;
    }
}