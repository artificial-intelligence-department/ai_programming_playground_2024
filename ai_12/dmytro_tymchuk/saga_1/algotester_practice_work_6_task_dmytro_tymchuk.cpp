//1951
#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s;
    cin>>s;

    int arr[20];

    if ((s[0] != '5') || ((int)s[1] < 49) || ((int)s[1] > 53)) cout <<"BAD"<<endl;
    else
    {

        for (int i = 0; i < s.length(); i++)
        {
            arr[i] = (int)s[i] - 48;
            if (i % 2 == 0) arr[i] *= 2;
        }

        int sum = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (arr[i] >= 10)
            {
                sum += arr[i] % 10 + arr[i] / 10;
            }
            else sum += arr[i];
        }

        if (sum % 10 == 0) cout<<"VALID"<<endl;
        else cout<<"BAD"<<endl;   
    }
    
    return 0;
}