#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
using vint = vector<int>;
using ving = vector<string>;

int main()
{
    fstream F1("F1.txt", ios::in);
    fstream F2("F2.txt", ios::out);
    if (!F1.is_open() || !F2.is_open())
    {
        cerr << "file error or file F1 doesn`t exist";
        return 1;
    }
    ving lines;
    string line;
    int N1, N2, acc = 1, maxI = 0, maxN = 0, acc1 = 0;

    cout << "Enter start and end values: ";
    cin >> N1 >> N2;

    while (getline(F1, line) && acc < N2)
    {
        if (acc > N1 && (line[line.size() - 1] == 'a' || line[line.size() - 1] == 'A'))
        {
            acc1++;
            int acc2 = 0;
            for (char ch : line)
            {
                if (ch == 'a' || ch == 'A')
                    acc2++;
            }
            if (acc2 > maxN)
            {
                maxN = acc2;
                maxI = acc1;
            }
            F2 << line << endl;
        }
        acc++;
    }
    if (maxI > 0)
        cout << "\nthe max amount of A symbol is in " << maxI << " row";
    else
        cout << "There are no rows in  F2 file";
    return 0;
}