#include <iostream>

using namespace std;

int main() 
{
    int N, M;
    cin >> N;
    int a[N]; // Перший масив
    for (int i = 0; i < N; i++) 
    {
        cin >> a[i];
    }

    cin >> M;
    int b[M]; // Другий масив
    for (int i = 0; i < M; i++) 
    {
        cin >> b[i];
    }

    // Знаходження кількості спільних елементів
    int countSame = 0;
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < M; j++) 
        {
            if (a[i] == b[j]) 
            {
                countSame++;
                break; // Знайшли спільний елемент, переходимо до наступного елемента з a
            }
        }
    }
    cout << countSame << endl;

    // Знаходження кількості унікальних елементів
    bool unique[201] = {false}; // Масив для відстеження унікальних елементів (0-100 для a і 101-200 для b)
    for (int i = 0; i < N; i++) 
    {
        unique[a[i]] = true;
    }
    for (int i = 0; i < M; i++) 
    {
        unique[b[i]] = true;
    }

    int countUnique = 0;
    for (int i = 0; i <= 100; i++) 
    {
        if (unique[i]) 
        {
            countUnique++;
        }
    }
    cout << countUnique << endl;

    return 0;
}