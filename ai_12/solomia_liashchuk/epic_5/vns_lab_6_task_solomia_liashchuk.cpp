#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

string removeWords(const string& input)
{
    stringstream ss(input);  
    string word;
    vector<string> words;

    while (ss >> word) 
        words.push_back(word); 

    string result;  
    for (size_t i = 0; i < words.size(); i++)
    {
        if ((i + 1) % 2 != 0) 
        {
            result += words[i] + " "; 
        }
    }
    if (!result.empty())
    {
        result.pop_back();  
    }

    return result; 
}

int main()
{
    string input;
    cout << "Введіть текст: " << endl;
    getline(cin, input);  

    if (input.length() > 255)
    {
        cout << "Розмір тексту завеликий" << endl;
        return 1; 
    }
    cout << "Текст без парних слів: " << removeWords(input) << endl;

    return 0;
}
