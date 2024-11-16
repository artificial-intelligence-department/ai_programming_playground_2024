#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;

void output(vector<int> arr)
{
    cout << arr.size() << endl;
    sort(arr.begin(), arr.end());
    for (int el : arr)
        cout << el << " ";
    cout << "\n\n";
}

int main()
{
    int s;
    cin >> s;
    vector<int> N, M, A1, A3, A4, A5;
    while (s--)
    {
        int a;
        cin >> a;
        N.push_back(a);
    }
    cin >> s;
    while (s--)
    {
        int a;
        cin >> a;
        M.push_back(a);
    }

    vector<int> bufferM = M;
    for (int &el1 : N)
    {
        bool acc1 = true;
        for (int i = 0; i < bufferM.size(); i++)
        {
            if (el1 == bufferM[i])
            {
                A3.push_back(bufferM[i]);
                bufferM.erase(bufferM.begin() + i);
                acc1 = false;
                break;
            }
        }
        if (acc1)
            A1.push_back(el1);
    }

    // залишок в буфері це не N елементи що є M 
    // об'єднання A1 і залишку дає симетричну різницю
    // додавши до симетричної різниці(А5) перетин(А3) отримаємо об'єднання 

    sort(A1.begin(), A1.end());
    output(A1);
    sort(bufferM.begin(), bufferM.end());
    output(bufferM);
    sort(A3.begin(), A3.end());
    output(A3);

    //bufferM --> A2
    A5.insert(A5.end(), A1.begin(), A1.end());//N-M
    A5.insert(A5.end(), bufferM.begin(), bufferM.end());//M-N
    sort(A5.begin(), A5.end());

    A4.insert(A4.end(), A5.begin(), A5.end());
    A4.insert(A4.end(), A3.begin(), A3.end());//M&N
    sort(A4.begin(), A4.end());
    output(A4);
    output(A5);

    return 0;
}