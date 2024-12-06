#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> grades(n);
    bool fail = false;
    bool excellent = true;

    for (int i = 0; i < n; ++i)
    {
        cin >> grades[i];
        if (grades[i] < 51)
        {
            fail = true;
        }
        if (grades[i] < 90)
        {
            excellent = false;
        }
    }

    if (fail)
    {
        cout << "scholarship wont be your";
    }
    else if (excellent)
    {
        cout << "You will have the best scholarship";
    }
    else
    {
        cout << "You will have scholarship";
    }

    return 0;
}