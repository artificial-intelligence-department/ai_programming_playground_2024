#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <set>

int main()
{
    int n, k;
    std::cin >> n >> k;
    std::unordered_map<std::string, int> freq_map;
    std::set<char> letterset;
    std::string word;
    for (int i = 0; i < n; i++)
    {
        std::cin >> word;
        std::transform(word.begin(), word.end(), word.begin(), [](char c) { return std::tolower(c); });
        freq_map[word]++;
    }

    for (const auto& [word, count] : freq_map) 
    {
        if (count >= k) 
        {
            letterset.insert(word.begin(), word.end());
        }
    }

    std::vector<char> letters(letterset.begin(), letterset.end());
    std::sort(letters.begin(), letters.end(), [](char a, char b) { return a > b; });
    if (!letters.size())
    {
        std::cout << "Empty!";
        exit(0);
    }
    std::cout << letters.size() << std::endl;
    for (char c : letters)
    {
        std::cout << c << " ";
    }
}