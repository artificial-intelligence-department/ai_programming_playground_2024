#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main() {

    int count = 0;
    int size;
    cin >> size;
    string line;
    vector<string> words;
    for(int i = 0; i <= size; i++) {    //ділимо кожний рядок на слова і додаємо їх
        getline(cin, line);
        stringstream ss(line);
        string word;
        while (ss >> word) {
            words.push_back(word);
        }
    }
    for(string elm : words) {   //пошук останньої #
        if(elm.length() > 1){
            for(int i = 0; i < elm.length(); i++) {
                if(elm[i] == '#' && elm[i+1] != '#') {
                    count += 1;
                }
            }
        } else if(elm[0] == '#') {  //для єдиного елемента
            count += 1;
        }
    }

    cout << count;


    return 0;

}