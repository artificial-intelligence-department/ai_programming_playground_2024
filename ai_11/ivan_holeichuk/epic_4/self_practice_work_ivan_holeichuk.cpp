#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int SIZE = 5;

const int MINES = 3;


struct Cell {

    bool mine;

    bool revealed;

    int adjMines;

};

void initfield(Cell field[SIZE][SIZE]) {

    srand(time(0));


    for (int i = 0; i < SIZE; i++) {

        for (int j = 0; j < SIZE; j++) {

            field[i][j].mine = false;

            field[i][j].revealed = false;

            field[i][j].adjMines = 0;
        }
    }


    int minesPlaced = 0;

    while (minesPlaced < MINES) {

        int x = rand() % SIZE;

        int y = rand() % SIZE;

        if (!field[x][y].mine) {

            field[x][y].mine = true;

            minesPlaced++;
        }
    }


    for (int i = 0; i < SIZE; i++) {

        for (int j = 0; j < SIZE; j++) {

            if (field[i][j].mine) continue;

            int count = 0;

            for (int dx = -1; dx <= 1; dx++) {

                for (int dy = -1; dy <= 1; dy++) {

                    int ni = i + dx;

                    int nj = j + dy;

                    if (ni >= 0 && ni < SIZE && nj >= 0 && nj < SIZE && field[ni][nj].mine) {

                        count++;
                    }
                }
            }
            field[i][j].adjMines = count;
        }
    }
}

void showfield(Cell field[SIZE][SIZE]) {

    for (int i = 0; i < SIZE; i++) {

        for (int j = 0; j < SIZE; j++) {

            if (field[i][j].revealed) {

                if (field[i][j].mine) {

                    cout << "* ";
                }else {
                    
                    cout << field[i][j].adjMines << " ";
                }
            } else {

                cout << "# ";
            }
        }
        cout << endl;
    }
}

bool opencell(Cell field[SIZE][SIZE], int x, int y) {

    if (field[x][y].revealed) return false;

    field[x][y].revealed = true;

    if (field[x][y].mine) {

        cout << "BOOM! You hit a mine!" << endl;

        return true;
    }

    return false;
}

int main() {

    Cell field[SIZE][SIZE];

    initfield(field);

    bool gameOver = false;

    while (!gameOver) {

        showfield(field);

        int x, y;

        cout << "Enter row and column (0 to " << SIZE - 1 << "): ";

        cin >> x >> y;

        if (x < 0 || x >= SIZE || y < 0 || y >= SIZE) {

            cout << "Invalid input. Try again." << endl;

            continue;
        }


        gameOver = opencell(field, x, y);
    }






    return 0;
}
