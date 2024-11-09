#include <iostream>

using namespace std;

int main()
{
    long long hp, mana;

    cin >> hp;
    cin >> mana;

    bool win = 1;

    for (int i = 0; i < 3; ++i)
    {
        long long h_i, m_i;
        cin >> h_i >> m_i;

        if (h_i != 0 && m_i != 0)
        {
            win = 0;
            break;
        }

        hp = hp - h_i;
        mana = mana - m_i;
    }

    if (win && hp > 0 && mana > 0)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    
    return 0;
}