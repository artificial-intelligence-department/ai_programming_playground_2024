//копіювати з ф1 до ф2 всі без цифр та підрахувати рядки з початком на "А"
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

int Acount = 0;

void writeToFile(string& filename) {    //заповнення ф1
    ofstream myFile(filename, ios::out);
    if (myFile.is_open()) {
        for(int i = 0; i < 10; i++) {
            string line;
            getline(cin, line);
            myFile << line << endl;
        }
        myFile.close();
    } else {
        cout << "No such file" << endl;
    }
}

void writeToFile(string& filename, string row) {    //конкретний рядок
    ofstream myFile(filename, ios::app);
    if (myFile.is_open()) {
        myFile << row << endl; 
        myFile.close();
    } else {
        cout << "No such file" << endl;
        }
}

void readFromFile(string& filename, string& tofilename) {
    ifstream myFile(filename);
    if (myFile.is_open()) {
        string line;
        while(getline(myFile,line)){
            int count = 0;
            for(int i = 0; i < line.length(); i++) {
                if(!isdigit(line[i])) {     //швидка перевірка на присутність цифр
                    count++;
                }
            }
            if(count == line.length()) {
                if(line[0] == 'A') {
                    Acount++;
                }
                writeToFile(tofilename, line);
            }
        } 
        myFile.close();
    } else {
        cout << "No such file" << endl;
    }
}

int main() {

    string filename1 = "test_lab9_1.txt";
    string filename2 = "test_lab9_2.txt";
    writeToFile(filename1);
    readFromFile(filename1,filename2);
    cout << "Num of A: " << Acount;


    return 0;
}