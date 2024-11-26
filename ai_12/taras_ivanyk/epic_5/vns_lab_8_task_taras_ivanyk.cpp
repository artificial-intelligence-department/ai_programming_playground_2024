#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

struct Buyer{
    char surname[20];
    char name[20];
    char middle_name[20];
    char address[100];
    char telephone_number[20];
    char card_number[20];
};

void create_binary_file(const string& myFile, const vector<Buyer>& buyers){
    ofstream outFile(myFile, ios::binary);
    if(!outFile){
        cout << " Error, can't open a file for writing " << endl;
        return;
    }
    for (const Buyer& buyer : buyers){
        outFile.write(reinterpret_cast<const char*>(&buyer), sizeof(Buyer));
    }
    outFile.close();
    cout << "*****************************************" << endl;
    cout << "File was createn and filled with data " << endl;
}

void print_binary_file(const string& myFile){
    ifstream inFile(myFile, ios::binary);
        if(!inFile){
            cout << " Error, can't open a file for reading " << endl;
            return;
        }
        Buyer buyer;
        while (inFile.read(reinterpret_cast<char*>(&buyer), sizeof(Buyer))){
            cout << "Surname: " << buyer.surname << ", Name: " << buyer.name << ", Middle name: " << buyer.middle_name <<  endl;
            cout << "Address: " << buyer.address << ", Telephone number: " << buyer.telephone_number << ", Card number: " << buyer.card_number << endl;
            cout << "------------------------" << endl;
        }
        inFile.close();
}

void delete_first_three(const string& myFile){
    ifstream inFile(myFile, ios::binary);
    if(!inFile){
        cout << " Error, can't open a file for reading " << endl;
        return;
    }
    vector<Buyer> buyers;
    Buyer buyer;
    int count = 0;
    
    while (inFile.read(reinterpret_cast<char*>(&buyer), sizeof(Buyer))){
        if(count >= 3){
            buyers.push_back(buyer);
        }
        count++;
    }
    inFile.close();

    ofstream outFile(myFile, ios::binary | ios::trunc);
    if(!outFile){
        cout << " Error, can't open a file for reading " << endl;
        return;
    }
    for (const Buyer& buyer : buyers){
        outFile.write(reinterpret_cast<const char*>(&buyer), sizeof(Buyer));
    }
    outFile.close();
    cout << "First 3 elements were deleted from file " << endl;
}

void three_to_end(const string& myFile, const vector<Buyer>& newBuyers){
    ofstream outFile(myFile, ios::binary | ios::app);
    if(!outFile){
        cout << " Error, can't open a file for reading " << endl;
        return;
    }
    for(const Buyer& buyer : newBuyers){
        outFile.write(reinterpret_cast<const char*>(&buyer), sizeof(Buyer));
    }
    outFile.close();
    cout << "3 elements were added to file " << endl;
}

int main(){
    string myFile = "Buyers_Information";

    vector<Buyer> initial_buyers = {
        {"Ivanyk", "Taras", "Yurijovych", "Videnska street 25", "+380-85-465-46-57", "1111-2222-3333-4444"},
        {"Iryna", "Svyrydenko", "Serhijivna", "Videnska street 25", "+380-47-895-09-00", "1451-7822-6983-5604"},
        {"Shyika", "Stefan", "Petrovych", "Konovaltsa street 39", "+380-25-111-22-33", "2233-3778-0003-1423"},
        {"Bobr", "Bobriv", "Bobrovych", "Kohucha street 106", "+380-77-000-44-55", "5566-8764-0987-4096"},
        {"Bilyk", "Pavlo", "Ivanovych", "Pshenychnoho street 87", "+380-66-888-00-22", "3344-4646-0000-9999"},
        {"Kryvychko", "Nazar" ,"Bibkovych" ,"Fariona street 42", "+380-90-880-23-00", "9090-1010-3234-8888"},
    };

    create_binary_file(myFile, initial_buyers);

    cout << "Original file contents: " << endl;
    cout << endl;
    print_binary_file(myFile);

    delete_first_three(myFile);

    vector<Buyer> newBuyers = {
        {"Sementov", "Luka", "Sementovych", "Bohuna street 16", "+48-098-563-46-57", "5555-6666-7777-8888"},
        {"Jov", "Ivan", "Velikovich", "Oksany street 6", "+889-435-436-45-65", "1000-0000-9897-0088"},
        {"Kil", "Hir", "Potapovych", "Michnovskoho street 194", "+380-98-732-36-46", "2435-8374-3782-0000"},
    };
    three_to_end(myFile, newBuyers);

    cout << "New file contents: " << endl;
    cout << endl;
    print_binary_file(myFile);

    return 0;
}