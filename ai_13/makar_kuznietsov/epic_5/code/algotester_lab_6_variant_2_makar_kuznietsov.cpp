#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

std::string checkPoint(const std::vector<std::string> &board, int x, int y);
bool onBoard(int x, int y);

int main()
{
    std::vector<std::string> board(8);

    for (int i = 0; i < 8; i++)
    {
        std::cin >> board[i];
    }
    int q;
    std::cin >> q;
    for (int i = 0; i < q; i++)
    {
        int x, y;
        std::cin >> x >> y;
        x--, y--;
        if (board[x][y] != 'O')
        {
            std::cout << "X" << '\n';
        }
        else
        {
            std::cout << checkPoint(board, x, y) << '\n';
        }
    }
    return 0;
}

bool onBoard(int x, int y)
{
    return x >= 0 && x < 8 && y >= 0 && y < 8;
}

std::string checkPoint(const std::vector<std::string> &board, int x, int y)
{
    const std::vector<std::pair<int, int>> P = {{1, -1}, {1, 1}};
    const std::vector<std::pair<int, int>> R = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    const std::vector<std::pair<int, int>> B = {{-1, -1}, {1, 1}, {-1, 1}, {1, -1}};
    const std::vector<std::pair<int, int>> Q = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {-1, -1}, {1, 1}, {-1, 1}, {1, -1}};
    const std::vector<std::pair<int, int>> K = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    const std::vector<std::pair<int, int>> N = {{-2, -1}, {-1, -2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}};
    std::set<char> attack;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            char p = board[i][j];
            if (p == 'O')
            {
                continue;
            }
            if (p == 'P')
            {
                for (auto [dx, dy] : P)
                {
                    int nx = i + dx, ny = j + dy;
                    if (nx == x && ny == y)
                    {
                        attack.insert(p);
                    }
                }
            }
            else if (p == 'R' || p == 'B' || p == 'Q')
            {
                const auto &directions = (p == 'R') ? R : (p == 'B' ? B : Q);
                for (auto [dx, dy] : directions)
                {
                    int nx = i, ny = j;
                    while (true)
                    {
                        nx += dx, ny += dy;
                        if (!onBoard(nx, ny))
                        {
                            break;
                        }
                        if (nx == x && ny == y)
                        {
                            attack.insert(p);
                        }
                    }
                }
            }
            else if (p == 'K' || p == 'N')
            {
                const auto &moves = (p == 'K') ? K : N;
                for (auto [dx, dy] : moves)
                {
                    int nx = i + dx, ny = j + dy;
                    if (nx == x && ny == y)
                    {
                        attack.insert(p);
                    }
                }
            }
        }
    }
    if (attack.empty())
    {
        return "O";
    }
    std::string result(attack.begin(), attack.end());
    std::sort(result.begin(), result.end());
    return result;
}
