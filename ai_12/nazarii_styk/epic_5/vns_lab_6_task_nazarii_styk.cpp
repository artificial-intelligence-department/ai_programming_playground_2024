// Variant 19
// 19. Знищити з рядка всі слова, які не є ідентифікаторами.
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string line;
    cout << "Enter a line: ";
    cin >> line;
    string word = "Hello";

    for (int i = 0; i < line.length(); i++)
    {
        if (line[i] == ' ')
        {
            if (word[0] >= 'a' && word[0] <= 'z' || word[0] >= 'A' && word[0] <= 'Z')
            {
                cout << word << " ";
            }
            word = "";
        }
        else
        {
            word += line[i];
        }
    }
    if (word[0] >= 'a' && word[0] <= 'z' || word[0] >= 'A' && word[0] <= 'Z')
    {
        cout << word << " ";
    }

    return 0;
}
