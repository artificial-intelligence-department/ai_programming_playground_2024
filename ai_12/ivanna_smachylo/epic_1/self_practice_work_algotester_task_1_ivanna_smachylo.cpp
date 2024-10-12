#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int number;
    int pack;

    cout << "How many packs of cookies you have(up to a hundred): " << "\n";
    cin >> number;
    
    if(number >= 100)
    {
        cout << "That's a lot!" << "\n";
        cin >> number;
        pack = number;
    }
       else
     {
        pack = number;
     }

    int cookies[100];
    for(int i = 0; i < pack; i++)
    {
        cout << "How many cookies in the pack №" << i << " :" << "\n";
        cin >> cookies[i];
    }

    cout << "How many cookies Marichka can eat: " << "\n";
    int end = 0;
    for(int i = 0; i < pack; i++)
    {
        end = end + (cookies[i] - 1);
    }
    cout << end;

    return 0;
}