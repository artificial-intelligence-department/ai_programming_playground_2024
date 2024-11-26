#include <iostream>
#include <fstream>

using namespace std;

enum FileOpResult { Success, Failure };

FileOpResult copy_file(const char *file_from, const char *file_to) {

    ifstream infile(file_from, ios::binary);  // Відкриваємо файл для читання
    if (!infile) { 
        cerr << "Error: Source file " << file_from << " could not be opened!" << endl;
        return Failure;
    }

    ofstream outfile(file_to, ios::binary);  // Відкриваємо файл для запису
    if (!outfile) {
        cerr << "Error: Destination file " << file_to << " could not be created or opened!" << endl;
        return Failure;
    }

    outfile << infile.rdbuf();  // Читаємо з infile і записуємо в outfile і копіюєм


    if (outfile.fail()) {
        cerr << "Error: writing to the destination file failed" << endl;
        return Failure;
    }

    // Закриваємо файли
    infile.close();
    if (infile.fail()) {
        cerr << "Error: closing the source file failed" << endl;
        return Failure;
    }

    outfile.close();
    if (outfile.fail()) {
        cerr << "Error: closing the destination file failed!" << endl;
        return Failure;
    }

    return Success; 
}

int main() {
    const char *file_from = "source.txt";
    const char *file_to = "destination.txt"; 


    FileOpResult result = copy_file(file_from, file_to);


    if (result == Success) {
        cout << "File copied successfully." << endl;
    } else {
        cout << "Failed to copy the file." << endl;
    }

    return 0;
}
/*rdbuf() — це метод класу ifstream (і інших потоків, таких як ofstream або fstream), який повертає вказівник на буфер потоку. Це дозволяє безпосередньо працювати з буфером потоку для виконання операцій вводу/виводу.

Деталі про rdbuf():
Що таке буфер потоку? Буфер потоку — це внутрішня область пам'яті, яку потік використовує для тимчасового зберігання даних, що передаються між програмою та файлом. Коли ви читаєте з файлу або записуєте в файл, дані часто спочатку потрапляють у цей буфер, а вже потім передаються або отримуються з файлу.

Значення rdbuf():

rdbuf() — це функція, яка повертає вказівник на об'єкт типу streambuf, що є внутрішнім буфером потоку.
Оскільки методи типу ifstream, ofstream, і fstream можуть бути використані для читання і запису через потік, rdbuf() дозволяє передавати вміст одного потоку в інший, використовуючи цей буфер.*/