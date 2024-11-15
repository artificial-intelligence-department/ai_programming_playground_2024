#include <iostream>
#include <sstream>
#include <string>
#include <vector>

void splitString(std::string &s, std::vector<std::string> &b);
void foo(std::vector<int> &a);
void foo(std::vector<std::string> &b);

int main()
{
    std::vector<int> a = {3, 21, 323, 421, 4, 12, 45};
    std::string s = "I loved nulp before deadlines";
    std::vector<std::string> b;
    splitString(s, b);
    foo(a);
    foo(b);
    for (int i = 0; i < a.size(); i++)
    {
        std::cout << a[i] << " ";
    }
    for (int i = 0; i < b.size(); i++)
    {
        std::cout << b[i] << " ";
    }
    return 0;
}

void foo(std::vector<int> &a)
{
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] % 2 == 0)
        {
            a.erase(a.begin() + i);
            --i;
        }
    }
}

void foo(std::vector<std::string> &b)
{
    for (int i = 0; i < b.size(); i++)
    {
        if (b[i].length() % 2 == 0)
        {
            b.erase(b.begin() + i);
            --i;
        }
    }
}

void splitString(std::string &s, std::vector<std::string> &b)
{
    std::stringstream ss(s);
    std::string word;
    while (ss >> word)
    {
        b.push_back(word);
    }
}
