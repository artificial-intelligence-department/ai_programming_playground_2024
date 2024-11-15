//покупці, три перших видалити і додати ще 3
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

struct Address {
    string city;
    string street;
    int streetNumber;
};

struct Customer
{
    string firstName;
    string lastName;
    string patronymic;
    Address address;
    string phoneNumber;
    string cardNumber;

};

void saveCustomer(string& filename, int n) {
    ofstream myFile(filename, ios::app);
    if (myFile.is_open()) {
    cout << "Please enter |First name||Last name||Patronymic||Phone number||Card number||City||Street||Street number|" << endl;
        for(int i = 0;i < n; i++) {
            Customer newcust;
            cin >> newcust.firstName >> newcust.lastName >> newcust.patronymic >> newcust.phoneNumber >> newcust.cardNumber >> newcust.address.city >> newcust.address.street >> newcust.address.streetNumber;
            myFile << newcust.firstName << " " << newcust.lastName << " " << newcust.patronymic << " " << newcust.phoneNumber << " " << newcust.cardNumber << " " << newcust.address.city << " " << newcust.address.street << " " << newcust.address.streetNumber << endl;
        }
        myFile.close();
    } else {
        cout << "No such file" << endl;
    }
}

void readCustomer(string& filename) {
    ifstream myFile(filename, ios::in);
    if (myFile.is_open()) {
        string line;
        while(getline(myFile,line)){
            Customer newcust;
            istringstream lineStream(line);
            lineStream >> newcust.firstName >> newcust.lastName >> newcust.patronymic >> newcust.phoneNumber >> newcust.cardNumber >> newcust.address.city >> newcust.address.street >> newcust.address.streetNumber;
            cout << newcust.firstName << " " << newcust.lastName << " " << newcust.patronymic << " " << newcust.phoneNumber << " " << newcust.cardNumber << " " << newcust.address.city << " " << newcust.address.street << " " << newcust.address.streetNumber << endl;
        }
        myFile.close();
    } else {
        cout << "No such file" << endl;
    }
}

void deleteCusomer(string& filename) {
    ifstream myFile(filename);
    ofstream tmpFile("temp.txt");
    if (!myFile.is_open() || !tmpFile.is_open()) {
        cout << "No such file" << endl;
        return;
    }

    string line;
    int currentLine = 1;
    int deleteLine = 3;
    while(getline(myFile, line)) {
        if(currentLine > deleteLine) {
            tmpFile << line << endl;
        }
        currentLine++;
    }

    myFile.close();
    tmpFile.close();

    remove(filename.c_str());
    rename("temp.txt", filename.c_str());
}

int main() {
    int n;
    string filename = "test_lab8.txt";
    cout << "How many customers do you have?" << endl;
    cin >> n;
    if(n > 0){
        saveCustomer(filename, n);
        cout << endl <<"Available customers:" << endl;;
        readCustomer(filename);
        cout << endl << "Performing task..." << endl;
        deleteCusomer(filename);
        cout << endl << "Available customers:" << endl;;
        readCustomer(filename);
        cout << endl << "Adding 3 more..." << endl;
        saveCustomer(filename, 3);
        cout << endl << "Available customers:" << endl;;
        readCustomer(filename);
    }


    return 0;
}