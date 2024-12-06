#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

struct Human {
    string firstname;
    string lastname;
    string middlename;
    string address;
    string phonenumber;
    string age;
};

void writeRecord(ofstream &outFile, const Human &person) {
    size_t length;

    // Write `firstname`
    length = person.firstname.size();
    outFile.write(reinterpret_cast<const char*>(&length), sizeof(length));
    outFile.write(person.firstname.c_str(), length);

    // Write `lastname`
    length = person.lastname.size();
    outFile.write(reinterpret_cast<const char*>(&length), sizeof(length));
    outFile.write(person.lastname.c_str(), length);

    // Write `middlename`
    length = person.middlename.size();
    outFile.write(reinterpret_cast<const char*>(&length), sizeof(length));
    outFile.write(person.middlename.c_str(), length);

    // Write `address`
    length = person.address.size();
    outFile.write(reinterpret_cast<const char*>(&length), sizeof(length));
    outFile.write(person.address.c_str(), length);

    // Write `phonenumber`
    length = person.phonenumber.size();
    outFile.write(reinterpret_cast<const char*>(&length), sizeof(length));
    outFile.write(person.phonenumber.c_str(), length);

    // Write `age`
    length = person.age.size();
    outFile.write(reinterpret_cast<const char*>(&length), sizeof(length));
    outFile.write(person.age.c_str(), length);
}

void readRecord(ifstream &inFile, Human &person) {
    size_t length;

    // Read `firstname`
    inFile.read(reinterpret_cast<char*>(&length), sizeof(length));
    person.firstname.resize(length);
    inFile.read(&person.firstname[0], length);

    // Read `lastname`
    inFile.read(reinterpret_cast<char*>(&length), sizeof(length));
    person.lastname.resize(length);
    inFile.read(&person.lastname[0], length);

    // Read `middlename`
    inFile.read(reinterpret_cast<char*>(&length), sizeof(length));
    person.middlename.resize(length);
    inFile.read(&person.middlename[0], length);

    // Read `address`
    inFile.read(reinterpret_cast<char*>(&length), sizeof(length));
    person.address.resize(length);
    inFile.read(&person.address[0], length);

    // Read `phonenumber`
    inFile.read(reinterpret_cast<char*>(&length), sizeof(length));
    person.phonenumber.resize(length);
    inFile.read(&person.phonenumber[0], length);

    // Read `age`
    inFile.read(reinterpret_cast<char*>(&length), sizeof(length));
    person.age.resize(length);
    inFile.read(&person.age[0], length);
}

void displayRecord(const Human &person) {
    cout << "--------------------------" << endl;
    cout << "First Name : " << person.firstname << endl;
    cout << "Last Name  : " << person.lastname << endl;
    cout << "Middle Name: " << person.middlename << endl;
    cout << "Address    : " << person.address << endl;
    cout << "Phone No.  : " << person.phonenumber << endl;
    cout << "Age        : " << person.age << endl;
    cout << "--------------------------" << endl;
}


int main(){
    int idx;
    cout << "index of record, after which to put new record: ";
    cin >> idx;

    vector<Human> records;
    Human person;
    // Human people[3] = {
    //     {"Roman", "Yatsyshyn", "Olehowych", "city Lviv", "+38666", "18"},
    //     {"Vitsliy", "Portnikov", "Batkowych", "city Kyiv", "+38666069", },
    //     {"Orest", "Melnyk", "Mykhaylowych", "city NONe", " ", "60"}
    // };

    Human newRecord = {"Olersandr", "Matrunych", "", "village Domazhyr", "+38096969696", "17"};

    // ofstream outFile("humans.bin", ios::binary);
    // if (!outFile) {
    //     cerr << "Failed to open file for writing." << endl;
    //     return 1;
    // }

    // // Write each record to the file
    // for (const Human &person : people) {
    //     writeRecord(outFile, person);
    // }

    // outFile.close();
    // cout << "Records written successfully to 'humans.dat'." << endl;
    
    ifstream file("humans.bin", ios::binary);

    if (file){
        while (file.peek() != EOF) { // Check for end of file
            readRecord(file, person);
            displayRecord(person);
            records.push_back(person);
        }
    }
    else {
        cerr << "Failed to open file for writing." << endl;
    } 

    file.close();

    records.insert(records.begin() + idx + 1, newRecord);

    ofstream tempFile("temp.bin", ios::binary);
    if (!tempFile) {
        cerr << "Failed to open temporary file for writing." << endl;
        return 0;
    }

    for (const Human &record : records) {
        if (record.age.empty() != true) {
            writeRecord(tempFile, record);
        }
    }
    tempFile.close();

    string filename = "humans.bin";
    string tempfilename = "temp.bin";

    if (remove(filename.c_str()) != 0) {
        cerr << "Error deleting original file." << endl;
        return 0;
    }
    if (rename(tempfilename.c_str(), filename.c_str()) != 0) {
        cerr << "Error renaming temporary file." << endl;
        return 0;
    }

    cout << "Record added successfully." << endl;

    return 0;
}

