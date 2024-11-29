#include <iostream> 
#include <fstream>
#include <string>
using namespace std;
enum FileOpResult {
    Success,
    Failure
};

FileOpResult copy_file(const char *file_from, const char *file_to);
int main(){
    string file_from, file_to;
    

    cout << "Name of file_from: ";
    getline(cin, file_from);
    cout << "Name of file_to: ";
    getline(cin, file_to);

    FileOpResult result = copy_file(file_from.c_str(), file_to.c_str());
    if (result == Success) {
        std::cout << "Запис успішний!" << std::endl;
    } else {
        std::cout << "Помилка запису!" << std::endl;
    }
    return 0;
}


FileOpResult copy_file(const char *file_from, const char *file_to) {
    string copy_text;

    if (file_from == nullptr || file_to == nullptr) {
        return Failure;
    }

    ifstream Filef(file_from);
    if (!Filef.is_open()) {
        return Failure;
    }
    ofstream Filet(file_to);
    if (!Filet.is_open()) {
        return Failure;
    }

    while (getline(Filef, copy_text)) {
        Filet << copy_text << "\n";
    }

    
    if (!Filef.eof() && Filef.fail()) { // eof дивиться чи ми не досягнули кінця файлу
        return Failure;
    }  
    if (Filet.fail()) {
        return Failure;
    }

    Filef.close();
    Filet.close();

    return Success;

}