#include <iostream>
#include <sstream>
#include <stdio.h>
#include <cstring>
#include <vector>
using namespace std;

struct comparator
{
    bool operator()(const std::string &a, const std::string &b) const
    {
        return a > b; // Міняємо оператор на "більше"
    }
};

int main()
{
    vector<pair<string, int>> words;
    char s[255];
    gets(s);//типу getline тільки сішна
    int len = strlen(s);
    if (len > 0 && s[len - 1] != '.')
    {
        cout << "de krapka?";
    }
    else
    {

        {//просто розділяє на слова і по ключ значення збільшує у мапі
            string sss;
            istringstream ss(s);
            while (ss >> sss)
            {
                bool acc = true;
                for (size_t i = 0; i < words.size(); i++)
                {
                    if (sss == words[i].first)
                    {
                        words[i].second += 1;
                        acc = false;
                    }
                }
                if (acc)
                    words.push_back({sss, 1});
            }
        }
    }
    pair<string, int> acc = {"", 0};
    for (pair<string, int> el : words)//витягає ключ з найбільшим значенням
        if (el.second > acc.second)
            acc = el;
    cout << acc.first;

    return 0;
}