#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;


vector<int> BooksIndx(0);
vector<int> BooksIndxInventory(0);

void showlist(string& archive) {
    cout << endl;

    vector<string> Books(0);
    ifstream myFile(archive);
    if (myFile.is_open()) {
        string line;
        while(getline(myFile,line)){
            Books.push_back(line);
            }
        myFile.close();
    } else {
        cout << "No such file" << endl;
    }

    int size = Books.size();
    for(int i = 0; i < size; i++) {
        cout << i + 1 << " |" << Books[i] << "| " ;
        if(BooksIndx[i] == 1){
            printf("(+)", BooksIndx);
        } else{
            printf("(-)", BooksIndx);
        }
        cout << endl;
    }
    cout << endl;
}

void takebook(string& archive, string& inventory) {
    cout << endl << "Which book do you want to take?" << endl;

    int indx;
    cin >> indx;

    if(indx <= BooksIndx.size() && BooksIndx[indx - 1] == 1 && indx > 0) {
        BooksIndx[indx - 1] = 0;

        ifstream lib(archive);
        ofstream myFile(inventory, ios::app);
        if(myFile.is_open() && lib.is_open()) {
            string line;
            int curline = 1;
            while(getline(lib, line)) {
                if(curline == indx) {
                    myFile << line << endl;
                }
                curline++;
            }
        } else {
            cout << "Mistake occurred" << endl;
        }

        BooksIndxInventory.push_back(indx - 1);
    } else {
        cout << "Invalid book number" << endl;
    }
    cout << endl;
}

void returnbook(string& inventory) {
    cout << endl << "Which book do you want to return?" << endl;
    int indx;
    cin >> indx;
    if(indx <= BooksIndxInventory.size() && indx > 0) {
        BooksIndx[BooksIndxInventory[indx - 1]] = 1;
        BooksIndxInventory.erase(BooksIndxInventory.begin() + indx - 1);

        ifstream myFile(inventory);
        ofstream tmpFile("temp.txt");
        if (!myFile.is_open() || !tmpFile.is_open()) {
            cout << "No such file" << endl;
            return;
        }

        string line;
        int currentLine = 1;
        int deleteLine = indx;
        while(getline(myFile, line)) {
            if(currentLine != deleteLine) {
                tmpFile << line << endl;
            }
            currentLine++;
        }

        myFile.close();
        tmpFile.close();

        remove(inventory.c_str());
        rename("temp.txt", inventory.c_str());


    } else {
        cout << "Invalid book number" << endl << endl;
    }
    cout << endl;
}

void showinventory(string& archive) {
    cout << endl;
    ifstream myFile(archive);
    vector<string> Inventory(0);
    if (myFile.is_open()) {
        string line;
        while(getline(myFile,line)){
            Inventory.push_back(line);
            }
        myFile.close();
    } else {
        cout << "No such file" << endl;
    }

    int size = Inventory.size();
    for(int i = 0; i < size; i++) {
        cout << i + 1 << " |" << Inventory[i] << "| " << endl;
    }
    cout << endl;
}

void addbook(const string& archive) {
    ofstream myFile(archive, ios::app);
    if(myFile.is_open()) {
        string bookname;
        cout << "Enter the name of book you want to add:" << endl;
        cin.ignore();
        getline(cin,bookname);
        if(bookname.length() > 0) {
            myFile << bookname << endl;
            BooksIndx.push_back(1);
        } else {
            cout << "Wrong name" << endl;
        }
    } else {
        cout << "Mistake occurred" << endl;
    }
    cout << endl;
}

void removefromlibrary(string& archive) {
    cout << "Enter the book you want to remove: " << endl;
    int indx;
    cin >> indx;
    if(indx <= BooksIndx.size() && indx > 0 && BooksIndx[indx - 1] == 1) {
        BooksIndx.erase(BooksIndx.begin() + indx - 1);
        for(int i = 0; i < BooksIndxInventory.size(); i++) {
            if(indx - 1 < BooksIndxInventory[i]) {
                BooksIndxInventory[i]--;
            }
        }
        ifstream myFile(archive);
        ofstream tmpFile("temp.txt");
        if (!myFile.is_open() || !tmpFile.is_open()) {
            cout << "No such file" << endl;
            return;
        }

        string line;
        int currentLine = 1;
        int deleteLine = indx;
        while(getline(myFile, line)) {
            if(currentLine != deleteLine) {
                tmpFile << line << endl;
            }
            currentLine++;
        }

        myFile.close();
        tmpFile.close();

        remove(archive.c_str());
        rename("temp.txt", archive.c_str());


    } else {
        cout << "Invalid book number" << endl << endl;
    }
    cout << endl;

}

int  main() {
    string lib_archive = "books.txt";
    string my_archive = "inventory.txt";
option:
    int opt;

    printf("Chose the option please:\n0)Exit menu\n1)Show anaviable books\n2)Take book\n3)Return book\n4)Inventory\n5)Add book\n6)Remove from library\n\n");
    cin >> opt;
    switch (opt)
    {
    case 0:
        return 0;
    case 1:
        showlist(lib_archive);
        break;
    case 2:
        takebook(lib_archive,my_archive);
        break;
    case 3:
        returnbook(my_archive);
        break;
    case 4:
        showinventory(my_archive);
        break;
    case 5:
        addbook(lib_archive);
        break;
    case 6:
        removefromlibrary(lib_archive);
        break;        
    default:
        cout << "Invalid option" << endl << endl;
        goto option;
        break;
    }
    goto option;

    return 0;
}
