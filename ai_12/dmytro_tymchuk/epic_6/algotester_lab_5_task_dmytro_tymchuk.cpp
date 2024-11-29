#include<iostream>
#include<cstdint>
#include<cmath>
using namespace std;

//Розкладання початкового числа в матрицю
void make_board (uint64_t starting_board, bool* matrix)
{
    int count = 0;

    while (starting_board > 0)
    {
        while (starting_board  % 2 == 0)
        {
            starting_board /= 2;
            count++;
        }
        
        *(matrix + count) = true;
        starting_board--;
    }

}

//формування числа з матриці
uint64_t making_final_board(bool* matrix)
{
    int count = 0;
    uint64_t final_board = 0;
    while (count < 64)
    {
        if (*(matrix + count) == true) 
        {
            uint64_t a = pow(2, count);
            final_board += a;
        }

        count++;
    }

    return final_board;
}

int main()
{
    uint64_t  starting_board;

    cin>>starting_board;
    bool board[8][8]{};
    make_board(starting_board, &board[0][0]);

    int rows[8]{}, columns[8]{};
    int n, row, column;

    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>row>>column;

        board[row - 1][column - 1] = !board[row - 1][column - 1];

        for (int j = 0; j < 8; j++)
        {
            board[row - 1][j] = !board[row - 1][j];
            board[j][column - 1] = !board[j][column - 1];
        }
        
    }

    uint64_t final_board;
    final_board = making_final_board(&board[0][0]);
    cout<<final_board<<endl;

    return 0;
}