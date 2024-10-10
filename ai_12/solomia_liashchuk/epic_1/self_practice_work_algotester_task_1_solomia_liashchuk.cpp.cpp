#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

     vector<int> a(n);
    long long total = 0;

    for (int i = 0; i < n; i++) 
    {
        cin >> a[i];
        total += (a[i] - 1);  // Можна з'їсти на 1 печиво менше, ніж є в кожній пачці
    }

    cout << total << endl;
    return 0;
}
