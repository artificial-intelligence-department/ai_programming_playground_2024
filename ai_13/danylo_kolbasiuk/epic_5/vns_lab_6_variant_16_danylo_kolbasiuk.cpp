#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>

int main()
{
    char str[256];
    std::cout << "Enter a string (less than 255 symbols, with a dot at the end.)" << std::endl;
    gets(str);
    std::string str1 (str);
    if(str1.back() == '.')
    {
        str1.pop_back();
    }
    std::stringstream stream(str1);
    std::string word;
    std::map<std::string, int> word_c;
    while(stream >> word)
    {
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        word_c[word]++;
    }
    for(const auto& temp : word_c)
    {
        if (temp.second==1)
        {
            std::cout << temp.first << std::endl;
        }
    }
}