#include <iostream>
#include <vector>
#include <cstring> 
#include <unordered_map>

using namespace std;

int main() {
    cout << "Введіть строку: ";
    char base[256];
    gets(base); 

    
    vector<string> slova;
    vector<string> slova2;

    
    char* word = strtok(base, " "); 
    while (word != nullptr) {
        slova.push_back(string(word));
        word = strtok(nullptr, " ");  
    }

    unordered_map<string, int> sort;


    for (const auto& word : slova) {
        sort[word]++;
    }

   
    cout << "Слова, що зустричаються лише один раз:" << endl;
     for ( auto final : sort) {
        if (final.second == 1) {
            cout <<  final.first << endl;
        }
    }
    return 0;
}
