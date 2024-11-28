#include <iostream>
#include <fstream>

using namespace std;

enum FileOpResult { Success, Failure };

FileOpResult copy_file(char* file_from, char* file_to) {
    if (file_from == nullptr || file_to == nullptr) {
        return Failure;
    }

    ifstream source(file_from, ios::binary);
    if (!source.is_open()) {
        return Failure;
    }

    ofstream destination(file_to, ios::binary);
    if (!destination.is_open()) {
        source.close();
        return Failure;
    }

    destination << source.rdbuf(); // копіюємо

    if (!destination) {
        source.close();
        destination.close();
        return Failure;
    }

    source.close();
    destination.close();
    return (source.fail() || destination.fail()) ? Failure : Success;
}

int main() {
    char source_file[256];
    char destination_file[256];

    cout << "Введіть ім'я вихідного файла: ";
    cin >> source_file;

    cout << "Введіть ім'я цільового файла: ";
    cin >> destination_file;

    FileOpResult result = copy_file(source_file, destination_file);

    if (result == Success) {
        cout << "Файл успішно скопійовано." << endl;
    } else {
        cout << "Помилка копіювання файла." << endl;
    }

    return 0;
}
