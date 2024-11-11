#include <iostream>
#include <vector>
using namespace std;

void showlist(vector<string>& Books, vector<int>& BooksIndx, int& size) {
    cout << endl;
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

void takebook(vector<string>& Books,vector<int>& Booksindx, int& size, vector<string>& Inventory, vector<int>& BooksIndxInventory) {
    cout << endl << "Which book do you want to take?" << endl << endl;
    int BookIndx;
    cin >> BookIndx;
    if(BookIndx <= size && Booksindx[BookIndx - 1] == 1) {
        Booksindx[BookIndx - 1] = 0;
        Inventory.push_back(Books[BookIndx - 1]);
        BooksIndxInventory.push_back(BookIndx - 1);
    } else {
        cout << "Invalid book number" << endl << endl;
    }
}

void returnbook(vector<int>& BooksIndx, vector<string>& Inventory, int InventorySize, vector<int>& BooksIndxInventory) {
    cout << endl << "Which book do you want to return?" << endl << endl;
    int InventoryIndx;
    cin >> InventoryIndx;
    if(InventoryIndx <= InventorySize) {
        BooksIndx[BooksIndxInventory[InventoryIndx - 1]] = 1;
        Inventory.erase(Inventory.begin() + InventoryIndx);
    } else {
        cout << "Invalid book number" << endl << endl;
    }
}

void showinventory(vector<string>& Inventory, int size) {
    cout << endl;
    for(int i = 0; i < size; i++) {
        cout << i + 1 << " |" << Inventory[i] << "|" << endl;
    }
    cout << endl;
}

int  main() {
    vector<string> Books = {
    "1984", 
    "Lord Of The Rings",
    "The Bible", 
    "Harry Potter",
    "Hamlet", 
    "To Kill A Mockingbird", 
    "Don Quixote", 
    "Divine comedy", 
    "Fahrenheit 451",
    "The Witcher"};
    int size = Books.size();
    vector <string> Inventory;
    vector<int> BooksIndx(size,1);
    vector<int> BooksIndxInventory;
option:
    int opt;
    do {
        printf("Chose the option please:\n0)Exit menu\n1)Show anaviable books\n2)Take book\n3)Return book\n4)Inventory\n\n");
        cin >> opt;
        switch (opt)
        {
        case 0:
            return 0;
        case 1:
            showlist(Books, BooksIndx, size);
            break;
        case 2:
            takebook(Books, BooksIndx, size, Inventory, BooksIndxInventory);
            break;
        case 3:
            returnbook(BooksIndx, Inventory, Inventory.size(), BooksIndxInventory);
            break;
        case 4:
            showinventory(Inventory, Inventory.size());
            break;
        
        default:
            cout << "Invalid option" << endl << endl;
            goto option;
            break;
        }
    } while(opt != 0);

    return 0;
}