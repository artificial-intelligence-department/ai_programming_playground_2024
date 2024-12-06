// 1) Скопіювати з файлу F1 у файл F2 рядки, починаючи з 4.
// 2) Підрахувати кількість символів в останньому слові F2.

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

int main(){
    string filename_f1 = "F1.txt";
    string filename_f2 = "F2.txt";
    string arr[13] = {
        "- .... .", "--- -. .-.. -.--", ".-- .- -.--", "- ---",
        "-.. ---", "--. .-. . .- -", ".-- --- .-. -.-",
        ".. ...", "- ---", ".-.. --- ...- .", ".-- .... .- -",
        "-.-- --- ..-", "-.. ---"
    };
    size_t nmbr_of_symbols = 0;
    int idx_last = 10;
    int idx_target = 4;
    int idx_now = 0;
    string line;
    ifstream file1(filename_f1, ios::app);
    ifstream file2(filename_f2, ios::app);
    // ofstream file1(filename_f1, ios::app);
    // ofstream file2(filename_f2, ios::app);
    
    if ((file1.is_open()) && (file2.is_open()))
    {
        // for (int i = 0; i < 13; i++)
        // {
        //     file1 << arr[i] << endl;
        // }
        // while (getline(file1, line))
        // {
        //     ++idx_now;
        //     if (idx_now >= idx_target)
        //     {
        //         file2 << line << endl;
        //     }  
        // }
        while (getline(file2, line))
        {
            ++idx_now;
            if (idx_now == idx_last)
            {
                // cout << line << endl;
                nmbr_of_symbols = line.size();
                break;
            }
        }
        cout << nmbr_of_symbols << endl;

    } else {
        cerr << "Error opening file for writing!\n";
    }
    file1.close();
    file2.close();
}
