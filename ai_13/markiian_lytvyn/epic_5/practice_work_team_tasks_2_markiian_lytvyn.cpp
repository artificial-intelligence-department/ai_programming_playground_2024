#include <iostream>
#include <fstream>
#include <string>

using namespace std;

enum FileOpResult {
    Success,
    Failure
};

FileOpResult copy_file(const char* file_from, const char* file_to) {
    if (file_from == nullptr || file_to == nullptr) {
        return Failure;
    }

    ifstream file1(file_from, ios::binary);
    if (file1.fail()) {
        return Failure;
    }

    ofstream file2(file_to, ios::binary);
    if (file2.fail()) {
        file1.close();
        return Failure;
    }

    file2 << file1.rdbuf();

    if (file1.fail() || file2.fail()) {
        file1.close();
        file2.close();
        return Failure;
    }

    file1.close();
    file2.close();
    return Success;
}

int main() {
    const char* n = "Epic5";
    int m = 123;
    const char* k = "NULP.AI";
    char name1[100];
    cin.getline(name1, 100);
    char name2[100];
    cin.getline(name2, 100);
    const int size = 3;
    double arr[size] = {3031, 20203.5, 1231};

    ofstream fileStream(name1);
    if (!fileStream.is_open()) {
        return 1; 
    }

    fileStream << m << "\n" << n << " " << k << "\n";
    for (int i = 0; i < size; i++) {
        fileStream << arr[i] << " ";
    }
    fileStream.close();

    if (copy_file(name1, name2) == Success) {
        cout << "Success!" << endl;
    } 
    else {
        cout << "Failed!" << endl;
    }

    return 0;
}
