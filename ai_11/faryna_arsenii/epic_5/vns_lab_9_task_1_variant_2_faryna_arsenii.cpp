#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <sstream>

using namespace std;

int count_word_in_F2(const string line){
    
    stringstream ss(line);
    string word;
    int count = 0;

    while (ss >> word){
        count++;
    } 

    return count;
}

int main (){

    ofstream file1("F1.txt");
    if(!file1){
        cerr << "ERROR while opening F1.txt for writing" << endl;
        exit(1);
    }

    file1 << "Ananas is orange." << endl;
    file1 << "Mary loves cookies." << endl;
    file1 << "Ann goes to school everyday." << endl;
    file1 << "Mike likes hiking." << endl;
    file1 << "Tomorrow I will go to university." << endl;
    file1 << "Avocado is green." << endl;
    file1 << "Almomds is my favourite nuts." << endl;
    file1 << "Arsenal is my favourite football team." << endl;
    file1 << "John has a cat called Micky." << endl;
    file1 << "My sister plays at piano." << endl;
    
    file1.close();

    ifstream file1_in("F1.txt");
    if(!file1_in){
        cerr << "ERROR while opening F1.txt for reading" << endl;
        exit(2);
    }

    ofstream file2("F2.txt");
    if(!file2){
        cerr << "ERROR while opening F2.txt for writing" << endl;
        exit(3);
    }

    cout << "Lines starting with 'A' will be copied to F2.txt:" << endl;
    
    string line;
    while (getline(file1_in, line)) {
        // Перевіряємо, чи перший символ є літерою 'A' або 'a'
        if (!line.empty() && (toupper(line[0]) == 'A')) {
            file2 << line << endl; // Записуємо рядок у F2
            cout << line << endl; // Виводимо рядок на екран
        }
    }

    file1_in.close();
    file2.close();  

    ifstream file2_in("F2.txt");
    if (!file2_in){
        cerr << "ERROR while opening file F2.txt for reading" << endl;
        exit(4);
    }

    int count_words = 0;
    while(getline(file2_in, line)){
        count_words += count_word_in_F2(line);
    }

    cout << "Numbers of words in F2.txt is " << count_words << endl;
    file2_in.close();

    return 0;
}