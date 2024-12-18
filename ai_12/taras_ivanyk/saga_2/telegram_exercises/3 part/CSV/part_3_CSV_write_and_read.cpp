#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

int main() {
//write
    ofstream file_write("data.csv"); 
    if (!file_write.is_open()) {
        cerr << "Error opening file!" << endl;
        return 1;
    }
    file_write << "Name,Age,City\n";  // name age city will be like columns
    file_write << "Alice,30,New York\n"; 
    file_write << "Bob,25,Los Angeles\n";

    file_write.close();
    cout << "Data written to output.csv!" << endl;

// read
    ifstream file_read("data.csv"); 
    if (!file_read.is_open()) {
        cerr << "Error opening file_read!" << endl;
        return 1;
    }

    string line;
    while (getline(file_read, line)) { 
        stringstream ss(line);   // split fields
        vector<string> fields;
        string field;

        while (getline(ss, field, ',')) { // Split by commas
            fields.push_back(field);
        }
        for (const auto& col : fields) {
            cout << col << " ";
        }
        cout << endl;
    }
    file_read.close();

    return 0;
}

