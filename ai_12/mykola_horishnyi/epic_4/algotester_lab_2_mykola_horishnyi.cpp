#include <iostream>
#include <unordered_set>
using namespace std;


int main() 
{
    int N;
    cin >> N;

    int* r = new int[N]; 
    for (int i = 0; i < N; ++i)
    {
        cin >> r[i];
    }
    int a, b, c;
    cin >> a >> b >> c;

    unordered_set<int> to_remove = { a, b, c };//  шоб зберігати видалені числа

    int* NewMassive = new int[N];
    int NewMassive_size = 0;

    for (int i = 0; i < N; ++i) {
        if (to_remove.find(r[i]) == to_remove.end())
        {
            NewMassive[NewMassive_size++] = r[i];
        }
    }

    if (NewMassive_size < 2)
    {
        cout << "0" << endl;
        cout << "" << endl; 
    }
    else {

        int* sums = new int[NewMassive_size - 1];
        for (int i = 0; i < NewMassive_size - 1; ++i) 
        {
            sums[i] = NewMassive[i] + NewMassive[i + 1];
        }


        cout << NewMassive_size - 1 << endl;
        for (int i = 0; i < NewMassive_size - 1; ++i)
        {
            cout << sums[i] << " ";
        }
        cout << endl;

        delete[] sums;
    }
    delete[] r;     
    delete[] NewMassive;


    return 0;
}











