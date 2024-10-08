#include <iostream>

using namespace std;

int main ()
{
    int a,b,c;
    cin >> a >> b >> c;
    if (a+c<=b)
    {
        cout << "All";
    }
    else if ((a+c>b) && (a<=b))
    {
        cout << "All registered";
    }
    else 
    {
        cout << "Bad organizers";
    }
}