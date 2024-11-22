#include <bits/stdc++.h>

using namespace std;

int main()
{
    char s[256];
    gets(s);

    char *token = strtok(s, " ");

    vector<string> SeparatedWords;

    while (token != nullptr)
    {
        SeparatedWords.push_back(token);

        token = strtok(nullptr, " ");
    }

    for(int i = 0; i < SeparatedWords.size(); i++)
    {
        reverse(SeparatedWords[i].begin(), SeparatedWords[i].end());
        cout << SeparatedWords[i] << " ";
    }

    return 0;
}