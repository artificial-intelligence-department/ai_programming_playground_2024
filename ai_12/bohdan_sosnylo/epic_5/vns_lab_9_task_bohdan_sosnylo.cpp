#include <iostream>
#include <fstream>
using namespace std;

void formfile(const string& filename){
    ofstream file(filename);
    if (!file) {
        cerr << "Помилка відкриття файлу!" << endl;
        return;
    }
    cout << "к-сть рядків(не менше 10): ";
    int k;
    cin >> k;

    for(int i = 0; i<k;i++){
        string m;
        cin >> m;
        file << m << " ";
    }

file.close();
}

void inputinf(const string& filename, const string& filename1){
    ifstream file(filename);
    ofstream file1(filename1);
    if(!file || !file1){
        cerr << "Помилка відкриття файлу!" << endl;
        return;
    }
    int i = 0;
    string strinput;
    while(file >> strinput){
        i++;
        if(i >=4){
            file1 << strinput << " ";
        }
        
    }
    file1.close();
    file.close();
    ifstream file2(filename1);
    string strinput1;
    string last1;
    while(file2 >> strinput1){
        last1.assign(strinput1);

    }
    if (!last1.empty()) {
        cout << "Кількість символів в останньому слові файлу F2: " << last1.length() << endl;
    } else {
        cout << "Файл F2 порожній." << endl;
    }

}

int main(){

string file = "F1.txt";
string file1 = "F2.txt";
formfile(file);
inputinf(file, file1);

    return 0;
}