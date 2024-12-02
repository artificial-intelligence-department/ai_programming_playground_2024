#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int CountConsonants(const string& word, const string& consonants) {
    int count_consonants = 0;
    for (char ch : word) {
        if (consonants.find(ch) != string::npos) {
            count_consonants++;
        }
    }
    return count_consonants;
}

int main() {
    ofstream fout("File1.txt");

    if (!fout.is_open()) {
        cout << "Error in opening file! " << endl;
        return 1;
    }

    fout << "Hello" << endl;
    fout << "Lol Kek" << endl;
    fout << "One" << endl;
    fout << "C plus plus" << endl;
    fout << "Testing" << endl;
    fout << "Programming" << endl;
    fout << "Idk what to write" << endl;
    fout << "Cars" << endl;
    fout << "Cats" << endl;
    fout << "Hello10" << endl;

    fout.close();

    ifstream source("File1.txt");
    ofstream copy_to("File2.txt");

    if (!source.is_open() || !copy_to.is_open()) {
        cout << "Error: Problem with openning or reading files!" << endl;
        return 1;
    }

    string line;
    
    int Maxconsonants = 0;
    string consonants = "BCDFGHJKLMNPQRSTVWXYZbcdfghjklmnpqrstvwxyz";
    string wordWithMaxConsonants;

    while (getline(source, line)) {
        istringstream iss(line);
        string word;
        int wordCount = 0;
        vector <string> words;

        while (iss >> word) {
            wordCount++;
            words.push_back(word);
        }

        if (wordCount == 1) {
            copy_to << line << endl;
        }

        for (const string& word : words) {
            int Consonants = CountConsonants(word, consonants);

            if (Consonants > Maxconsonants) {
                Maxconsonants = Consonants;
                wordWithMaxConsonants = word;
            }
        }
    }

    source.close();
    copy_to.close();

    cout << "Processing complete. Check 'File2.txt'." << endl;
    cout << "Word with the most consonats: " << wordWithMaxConsonants << "\nConsonants: " << Maxconsonants << endl;
    return 0;
}
