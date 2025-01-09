// Офісна вулиця. Частина 1

#include <iostream>
#include <algorithm>

using namespace std;

struct Office 
{
    int index;
    int length;
};

bool compare(const Office &a, const Office &b) 
{
    return a.length < b.length;
}

int main() 
{
    int n;
    cin >> n;

    Office *offices = new Office[n];

    for (int i = 0; i < n; i++) 
    {
        cin >> offices[i].length;
        offices[i].index = i + 1;
    }

    sort(offices, offices + n, compare);

    for (int i = 0; i < n; i++) 
    {
        cout << offices[i].index << " ";
    }
    cout << endl;

    delete[] offices;

    return 0;
}
