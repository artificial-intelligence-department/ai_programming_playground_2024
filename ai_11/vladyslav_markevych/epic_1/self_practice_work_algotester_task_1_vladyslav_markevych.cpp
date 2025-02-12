#include <iostream>
#include <vector>

using namespace std;


int NumBills(int b)
{
  
    vector<int> bills = {500, 200, 100, 50, 20, 10, 5, 2, 1};
    int count = 0;

    for (int bill : bills)
    {
        if (b >= bill) 
        {
            count += b / bill;
            b %= bill;
        }
    }

    return count; 
}

int main()
{
    int n;
    const int min_sum =1;
    const long long max_sum =10e9;
    cout << "Enter a price of present: " << endl;
    cin >> n;
    if(n < min_sum||n > max_sum)
    {
        cout<<"Your number is not within the limits"<<endl;
    }
    else if(n<0)
    {
        cout<<"Sorry, I cannot do it now"<<endl;
    }
    else{
    int result = NumBills(n);
    cout << result << endl;
}

    return 0;
}
