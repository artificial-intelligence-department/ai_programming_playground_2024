#include <iostream>
#include <string>

bool canFormSubstring(const std::string &t, const std::string &s)
{
    int t_len = t.length();
    int s_len = s.length();

    for (int i = 0; i <= t_len - s_len; ++i)
    {
        bool match = true;
        for (int j = 0; j < s_len; ++j)
        {
            if (t[i + j] != '?' && t[i + j] != s[j])
            {
                match = false;
                break;
            }
        }
        if (match)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    std::string t, s;
    std::cin >> t >> s;

    if (canFormSubstring(t, s))
    {
        std::cout << "YES";
    }
    else
    {
        std::cout << "NO";
    }

    return 0;
}
