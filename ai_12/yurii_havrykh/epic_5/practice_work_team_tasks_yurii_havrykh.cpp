#include<bits/stdc++.h>
#include<fstream>

using namespace std;

void write_to_file(char *file_name, char *content) {
    ofstream file(file_name);
    if (!file) {
        cout << "Failure" << endl;
        return;
    }
    file << content << endl;
    file.close();
    cout << "Success" << endl;

}

void copy_file(char *file_from_copy, char *file_to_insert) {
    ofstream file_to(file_to_insert);
    ifstream file_from(file_from_copy);
    if ((!file_to) || (!file_from)) {
        cout << "Failure" << endl;
        return;
    }
    bool is_empty_file_from = true;

    string line;
    while (getline(file_from, line)) {
        file_to << line << endl;
        is_empty_file_from = false;
    }
    if (is_empty_file_from)
        cout << "Failure file_from is empty" << endl;
    else {
        cout << "Success" << endl;
    }


}

int main() {
    char content[50];
    char file_name[20];
    cout << "Filename: ";
    cin.getline(file_name, sizeof(file_name));
    cout << "Content: ";
    cin.getline(content, sizeof(content));

    write_to_file(file_name, content);


    char filename_from[20], filename_to[20];
    cout << "Filename from which copy: ";
    cin.getline(filename_from, sizeof(filename_from));
    cout << "Filename in which insert: ";
    cin.getline(filename_to, sizeof(filename_to));
    copy_file(filename_from, filename_to);
}