#include <iostream>

using namespace std;

int main()
{
    int n;
    char temp1,temp2;
    cin >> n;
    char* a=new char[n];
    char* b=new char[n];
    int* ai=new int[n];
    int* bi=new int[n];
    for (int i=0; i<n; i++)
    {
        cin >> temp1;
        a[i]=temp1;
        ai[i]=a[i]-'0';
    }
    for (int i=0; i<n; i++)
    {
        cin >> temp2;
        b[i]=temp2;
        bi[i]=b[i]-'0';
    }
    for (int i=0; i<n; i++)
    {
        if (ai[i]==1)
        {
            if (ai[i]==bi[i])
            {
            cout << "Yes";
            return 0;
            }
        }  
    }
    cout << "No";
}
