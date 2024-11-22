#include <iostream>

using namespace std;

const int ROW = 3;
const int COL = 6;

int fMax(int Mas[][COL], int row) 
{
    int maxEl = Mas[row][0];
    for (int j = 1; j < COL; ++j) 
    {
        if (Mas[row][j] > maxEl) 
        {
            maxEl = Mas[row][j];
        }
    }

    return maxEl;
}

void shiftR(int Mas[][COL], int row, int shift, int maxEl) 
{
    shift = 0;
    for (int j = 0; j < COL; ++j)
    {
        if (Mas[row][j] == maxEl)
        {
            shift++;
        }
    }
    
    int temp[COL];
    for (int j = 0; j < COL; ++j) 
    {
        temp[(j + shift) % COL] = Mas[row][j];
    }
        
    for (int j = 0; j < COL; ++j) 
    {
        Mas[row][j] = temp[j];
    }
    
}

int main() 
{
    int Mas[ROW][COL];

    for (int i = 0; i < ROW; ++i) 
    {
        for (int j = 0; j < COL; ++j) 
        {
            cout << "Введіть елемент " << i << j << endl;
            cin >> Mas[i][j];
        }
        cout << endl;
    }

    cout << "Початковий масив:" << endl;
    for (int i = 0; i < ROW; ++i) 
    {
        for (int j = 0; j < COL; ++j) 
        {
            cout << Mas[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < ROW; ++i) 
    {
        int maxElement = fMax(Mas, i);

        int shift;

        shiftR(Mas, i, shift, maxElement);
    }

    cout << endl << "Кінцевий масив:" << endl;
    for (int i = 0; i < ROW; ++i) 
    {
        for (int j = 0; j < COL; ++j) 
        {
            cout << Mas[i][j] << " ";
        }
        cout << endl;
    }

    return 0;

}