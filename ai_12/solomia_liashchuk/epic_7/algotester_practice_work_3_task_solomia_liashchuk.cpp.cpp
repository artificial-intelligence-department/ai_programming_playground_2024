#include <iostream>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    int totalCells = N * M;

    if(totalCells % 2 == 1) 
    {
        cout << "Imp" << endl; 
    } 
    else 
    {
        cout << "Dragon" << endl; 
    }

    return 0;
}