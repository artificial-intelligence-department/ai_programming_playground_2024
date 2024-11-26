#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool contains(const string& line) {
    string words[100];
    int count = 0;
    string word = "";
    
    for (char ch : line) 
    {
        if (ch == ' ') 
        {
            if (!word.empty()) 
            {
                words[count++] = word;
                word = "";
            }
        } else {
            word += ch;
        }
    }
    if (!word.empty()) 
    {
        words[count++] = word;
    }
    
    for (int i = 0; i < count; i++) 
    {
        for (int j = i + 1; j < count; j++) 
        {
            if (words[i] == words[j]) 
            {
                return true;
            }
        }
    }
    return false;
}

int find_word(const string& line) {
    string word = "";
    int maxDigits = 0;
    int wordIndex = -1;
    int currentIndex = 0;
    
    for (char ch : line) 
    {
        if (ch == ' ') 
        {
            if (!word.empty()) {
                int digitCount = 0;
                for (char c : word) 
                {
                    if (isdigit(c)) 
                    {
                        digitCount++;
                    }
                }
                if (digitCount > maxDigits) 
                {
                    maxDigits = digitCount;
                    wordIndex = currentIndex;
                }
                ++currentIndex;
                word = "";
            }
        } else {
            word += ch;
        }
    }
    
    if (!word.empty()) 
    {
        int digitCount = 0;
        for (char c : word) 
        {
            if (isdigit(c)) 
            {
                digitCount++;
            }
        }
        if (digitCount > maxDigits) 
        {
            wordIndex = currentIndex;
        }
    }
    
    return wordIndex;
}

int main() {
    ifstream input("F1.txt");
    ofstream output("F2.txt");

    if (!input) {
        cerr << "Помилка: не вдалося відкрити вхідний файл." << endl;
        return 1;
    }
    if (!output) {
        cerr << "Помилка: не вдалося відкрити вихідний файл." << endl;
        return 1;
    }

    string line;
    while (getline(input, line)) 
    {
        if (contains(line)) 
        {
            output << line << endl;
        }
    }
    
    input.clear();
    input.seekg(0, ios::beg);

    cout << "Індекс слова з найбільшою кількістю цифр у кожному рядку:" << endl;
    while (getline(input, line)) 
    {
        int index = find_word(line);
        if (index == -1) {
            cout << "У рядку не знайдено слово з цифрами" << endl;
        } else {
            cout << index << endl;
        }
    }
    
    return 0;
}
