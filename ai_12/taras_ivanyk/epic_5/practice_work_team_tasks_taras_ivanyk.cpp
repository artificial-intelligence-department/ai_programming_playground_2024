#include <iostream>
#include <fstream>
#include <cstring>
#include <map>
#include <vector>
#include <string>
using namespace std;

enum FileOpResult {
    Success = 0,
    Failure = 1,
};
static map<FileOpResult, string> OperationStr = { 
    { Success, "Success" },
    { Failure, "Failure" } // для виведення результатів
};
bool sameEnd(const string& s_full, const string& s_end) {
    if (s_full.length() >= s_end.length()) {
        return (0 == s_full.compare(s_full.length() - s_end.length(), s_end.length(), s_end));
    } else { // перевірка чи s_full = s_end
        return false;
    }
}
FileOpResult write(const char* name, const char* content) {
    if (name == nullptr || strcmp(name, "") == 0 || !sameEnd(name, ".txt")) {
        name = "default.txt"; // якщо ім'я порожнє або не закінчується на ".txt", то йде далі
    }
    ofstream f_out(name, ios::out | ios::trunc);
    if (!f_out.is_open()) {
        return FileOpResult::Failure;
    }
    f_out << content;
    if (!f_out.good()) { // Check if writing to file was successful
        return FileOpResult::Failure;
    }
    f_out.close();
    return f_out.fail() ? FileOpResult::Failure : FileOpResult::Success;
}
unsigned int FileRead(istream& is, vector<char>& buff) {
    is.read(&buff[0], buff.size());
    return is.gcount();
}
void FileRead(ifstream& f_in, string& s) {
    const unsigned int BUFSIZE = 64 * 1024;
    vector<char> buffer(BUFSIZE);

    while (unsigned int n = FileRead(f_in, buffer)) {
        s.append(&buffer[0], n);
    }
}
FileOpResult copy(const char* file_from, const char* file_to) {
    if (file_from == nullptr || strcmp(file_from, "") == 0 ||
        file_to == nullptr || strcmp(file_to, "") == 0 ||
        !sameEnd(file_from, ".txt") || !sameEnd(file_to, ".txt")) {
        return FileOpResult::Failure;
    }
    ifstream f_in(file_from, ios::in);
    if (!f_in.is_open()) {
        return FileOpResult::Failure;
    }
    ofstream f_out(file_to, ios::out | ios::trunc);
    if (!f_out.is_open()) {
        f_in.close();
        return FileOpResult::Failure;
    }
    string fileContent;
    FileRead(f_in, fileContent);
    f_out << fileContent;
    bool failure = f_in.bad() || f_out.bad();

    f_in.close();
    f_out.close();
    return failure ? FileOpResult::Failure : FileOpResult::Success;
}
int main() {

    string contentLine, fileName;
    cout << "Enter content: ";
    getline(cin, contentLine);
    cout << "Enter file name: (*.txt) (default name = \"default.txt\"): ";
    getline(cin, fileName);
    FileOpResult writeResult = write(fileName.c_str(), contentLine.c_str());
    cout << "Operation Result: " << OperationStr[writeResult] << endl;

    string fromFile, toFile;
    cout << "Enter file name {from}: ";
    getline(cin, fromFile);
    cout << "Enter file name {to}: ";
    getline(cin, toFile);
    FileOpResult copyResult = copy(fromFile.c_str(), toFile.c_str());
    cout << "Copy Operation Result: " << OperationStr[copyResult] << endl;

    return 0;
}
