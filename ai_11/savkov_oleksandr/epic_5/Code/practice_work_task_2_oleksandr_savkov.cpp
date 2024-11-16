#include <iostream>
#include <fstream>

using namespace std;

enum FileOpResult { Success, Failure };

FileOpResult copy_file(const char *file_from, const char *file_to) {
    if (file_from == NULL || file_to == NULL) {
        cerr << "Неправильні вхідні дані: ім'я вхідного або вихідного файлу є NULL.\n";
        return Failure;
    }

    ifstream in(file_from, ios::binary);
    if (!in.is_open()) {
        cerr << "Не вдалося відкрити файл для читання." << endl;
        return Failure;
    }

    ofstream out(file_to, ios::binary); 
    if (!out.is_open()) {
        cerr << "Не вдалося відкрити файл для запису." << endl; 
        return Failure;
    }

    out << in.rdbuf(); 
    if (!out) {
        cerr << "Помилка під час запису у файл." << endl;
        return Failure;
    }

    in.close();
    out.close();

    return Success;
}

int main() {
    char in[256];
    char out[256];

    cout << "Введіть файл, з якого хочете скопіювати дані: ";
    cin.getline(in, 256);
    cout << "Введіть файл, в який хочете скопіювати дані: ";
    cin.getline(out, 256);

    FileOpResult result = copy_file(in, out);

    if (result == Success) {
        cout << "Копіювання виконано успішно" << endl;
    } else if (result == Failure) {
        cout << "Копіювання не виконано, сталася помилка" << endl;
    }

    return 0;
}
