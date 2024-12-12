#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// max and min elements in columns
void func_1(int **m)
{
    int min[5];
    int max[5];
    cout << "Min elements for cols: \n";
    for (int i = 0; i < 5; i++)
    {
        min[i] = m[0][i];
        max[i] = m[0][i];
        for (int j = 1; j < 5; j++)
        {
            min[i] = (min[i] < m[j][i]) ? min[i] : m[j][i];
            max[i] = (max[i] > m[j][i]) ? max[i] : m[j][i];
        }
        cout << min[i] << " ";
    }
    cout << "\nMax elements for cols: \n";
    for (auto el : max)
    {
        cout << el << " ";
    }
}

// max and min elements in rows
void func_2(int **m)
{
    int min[5];
    int max[5];
    for (int i = 0; i < 5; i++)
    {
        min[i] = *min_element(m[i], m[i] + 5);
        max[i] = *max_element(m[i], m[i] + 5);
    }
    cout << "\nMin elements for row:\n";
    for (auto el : min)
    {
        cout << el << " ";
    }
    cout << "\nMax elements for row:\n";
    for (auto el : max)
    {
        cout << el << " ";
    }
}

// print the matrix from the lower right corner up and down the columns
void func_3(int **m)
{
    cout << "\nprint the matrix from the lower right corner up and down the columns\n";
    for (int i = 4; i >= 0; i--)
    {
        for (int j = 4; j >= 0; j--)
        {
            cout << m[j][i] << " ";
        }
        cout << endl;
    }
}

// rotate the matrix value relative to the diagonal
void func_4(int **&m)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = i; j < 5; j++)
        {
            swap(m[i][j], m[j][i]);
        }
    }
}

// rotate the matrix by 90 degrees
void func_5(int **&m)
{
    for (int i = 0; i < 5; ++i)
    {
        for (int j = i + 1; j < 5; ++j)
        {
            swap(m[i][j], m[j][i]);
        }
        reverse(m[i], m[i] + 5);
    }
}

// check if the matrix is symmetrical
bool func_6(int **m)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = i; j < 5; j++)
        {
            if (m[i][j] != m[j][i])
            {
                return false;
            }
        }
    }
    return true;
}

// transpose a 5*6 matrix
void func_7(int **m, int **&tm)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            tm[j][i] = m[i][j];
        }
    }
}

void output(int **m, int n, int k)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int **m = new int *[5];
    for (int i = 0; i < 5; i++)
    {
        m[i] = new int[5];
        for (int j = 0; j < 5; j++)
        {
            m[i][j] = rand() % 100 + 1;
        }
    }

    int **m2 = new int *[5];
    int **tm = new int *[6];
    for (int i = 0; i < 6; i++)
    {
        tm[i] = new int[5];
    }

    for (int i = 0; i < 5; i++)
    {
        m2[i] = new int[6];
        for (int j = 0; j < 6; j++)
        {
            m2[i][j] = rand() % 100 + 1;
        }
    }

    cout << "original matrix\n";
    output(m, 5, 5);
    func_1(m);
    func_2(m);
    func_3(m);
    func_4(m);
    cout << "\nrotated relative to the diagonal matrix\n";
    output(m, 5, 5);
    func_5(m);
    cout << "\nrotated by 90 degrees matrix\n";
    output(m, 5, 5);

    if (func_6(m))
        cout << "\nmatrix is symmetrical\n";
    else
        cout << "\nmatrix isn't symmetrical\n";

    func_7(m2, tm);
    cout << "\noriginal matrix\n";
    output(m2, 5, 6);
    cout << "\ntrasposed matrix\n";
    output(tm, 6, 5);

    return 0;
}