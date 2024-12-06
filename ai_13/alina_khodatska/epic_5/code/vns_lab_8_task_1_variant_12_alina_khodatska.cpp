#include <iostream>
#include <fstream>  // для роботи з файлами
#include <cstring>  // для роботи з рядками

using namespace std;

struct MusicDisk {
    char title[100];
    char author[100];
    int duration;  // тривалість у секундах
    float price;
};

// Функція для виведення інформації про музичний диск
void printDisk(const MusicDisk& disk) {
    cout << "Title: " << disk.title << endl;
    cout << "Author: " << disk.author << endl;
    cout << "Duration: " << disk.duration << " seconds" << endl;
    cout << "Price: " << disk.price << " USD" << endl;
    cout << "----------------------------------------" << endl;
}

// Функція для створення бінарного файлу
void createBinaryFile(const char* filename) {
    ofstream file(filename, ios::binary);  // ofstream для запису в бінарний файл, ios::binary - відкриття файлу в бінарному режимі
    if (!file) {  // !file - перевірка на помилку відкриття файлу
        cerr << "Error opening file for writing!" << endl;
        return;
    }

    // Приклад даних для запису
    MusicDisk disks[] = {
        {"Album 1", "Artist 1", 3600, 15.99},
        {"Album 2", "Artist 2", 4200, 20.99},
        {"Album 3", "Artist 3", 3900, 18.49},
        {"Album 4", "Artist 4", 3000, 12.99}
    };

    // Записуємо дані в бінарний файл
    file.write(reinterpret_cast<char*>(&disks), sizeof(disks));
    // reinterpret_cast - перетворення типів даних(MusicDisk* в char*), &disks - адреса першого елемента масиву, sizeof(disks) - розмір масиву в байтах
    file.close();
    cout << "File created successfully!" << endl;
}

// Функція для друку вмісту бінарного файлу
void printFileContents(const char* filename) {
    ifstream file(filename, ios::binary);  // ifstream для читання з бінарного файлу
    if (!file) {
        cerr << "Error opening file for reading!" << endl;
        return;
    }

    file.seekg(0, ios::end);  // file.seekg - переміщення ios::end - вказівника в кінець файлу
    size_t fileSize = file.tellg();  // file.tellg - повертає поточне положення вказівника
    file.seekg(0, ios::beg);   // повертаємось на початок файлу

	size_t numRecords = fileSize / sizeof(MusicDisk);  // Кількість записів в файлі
    MusicDisk disk;

	for (size_t i = 0; i < numRecords; ++i) { // Цикл для читання всіх записів
        file.read(reinterpret_cast<char*>(&disk), sizeof(MusicDisk));
        cout << "Disk #" << i + 1 << ":" << endl;
        printDisk(disk);
    }

    file.close();
}

// Функція для видалення елемента за тривалістю
void deleteDiskByDuration(const char* filename, int duration) {
    fstream file(filename, ios::in | ios::out | ios::binary);  // fstream для читання та запису в бінарний файл
    // ios::in - відкриття файлу для читання, ios::out - відкриття файлу для запису, ios::binary - відкриття файлу в бінарному режимі
    if (!file) {
        cerr << "Error opening file for modification!" << endl;
        return;
    }

	file.seekg(0, ios::end); 
	size_t fileSize = file.tellg(); // Поточне положення вказівника
	size_t numRecords = fileSize / sizeof(MusicDisk); // Кількість записів в файлі

    MusicDisk disk;
	bool found = false; // Знайдено елемент для видалення
    size_t deletePos = 0; 

	for (size_t i = 0; i < numRecords; ++i) { // Цикл для пошуку елемента за тривалістю
        file.seekg(i * sizeof(MusicDisk), ios::beg); 
        file.read(reinterpret_cast<char*>(&disk), sizeof(MusicDisk)); 

		if (disk.duration == duration) { // Якщо знайдено елемент для видалення
            found = true; 
            deletePos = i;
            break;
        }
    }

	// Якщо елемент знайдено
    if (found) {
        // Переміщаємо всі елементи після видаленого на одну позицію назад
        for (size_t i = deletePos + 1; i < numRecords; ++i) {
            file.seekg(i * sizeof(MusicDisk), ios::beg);
            file.read(reinterpret_cast<char*>(&disk), sizeof(MusicDisk));

            file.seekp((i - 1) * sizeof(MusicDisk), ios::beg);  // file.seekp - переміщення вказівника запису ios::beg - на початок файлу
            file.write(reinterpret_cast<char*>(&disk), sizeof(MusicDisk));
        }

        // Оновлюємо розмір файлу
        file.seekp((numRecords - 1) * sizeof(MusicDisk), ios::beg);
        MusicDisk emptyDisk = {};  // Порожній диск
        file.write(reinterpret_cast<char*>(&emptyDisk), sizeof(MusicDisk));
        cout << "Disk with duration " << duration << " seconds deleted." << endl;
    }
    else {
        cout << "Disk with specified duration not found." << endl;
    }

    file.close();
}

// Функція для додавання двох елементів після вказаного елемента
void addDisksAfterIndex(const char* filename, size_t index, const MusicDisk& newDisk1, const MusicDisk& newDisk2) {
    fstream file(filename, ios::in | ios::out | ios::binary);
    if (!file) {
        cerr << "Error opening file for modification!" << endl;
        return;
    }

    file.seekg(0, ios::end);
    size_t fileSize = file.tellg();
    size_t numRecords = fileSize / sizeof(MusicDisk);

	if (index >= numRecords) { // Перевірка на правильність індексу
        cerr << "Invalid index!" << endl;
        file.close();
        return;
    }

    // Створюємо тимчасовий масив для збереження елементів після індексу
    MusicDisk* tempDisks = new MusicDisk[numRecords - index];
    file.seekg((index + 1) * sizeof(MusicDisk), ios::beg);
    file.read(reinterpret_cast<char*>(tempDisks), (numRecords - index - 1) * sizeof(MusicDisk));

    // Переміщаємо вказівник на місце додавання
    file.seekp((index + 1) * sizeof(MusicDisk), ios::beg);

    // Записуємо нові елементи
    file.write(reinterpret_cast<const char*>(&newDisk1), sizeof(MusicDisk));
    file.write(reinterpret_cast<const char*>(&newDisk2), sizeof(MusicDisk));

    // Записуємо всі інші елементи після вставки
    file.write(reinterpret_cast<const char*>(tempDisks), (numRecords - index - 1) * sizeof(MusicDisk));

    delete[] tempDisks;
    cout << "Two disks added after disk #" << index + 1 << endl;

    file.close();
}

int main() {
    const char* filename = "music_disks.dat";

    // Створення бінарного файлу
    createBinaryFile(filename);

    // Друк вмісту файлу
    cout << "File contents:" << endl;
    printFileContents(filename);

    // Видалення диска за тривалістю
    deleteDiskByDuration(filename, 4200);

    // Додавання двох нових дисків
    MusicDisk newDisk1 = { "Album 5", "Artist 5", 4500, 22.99 };
    MusicDisk newDisk2 = { "Album 6", "Artist 6", 3600, 19.99 };
    addDisksAfterIndex(filename, 1, newDisk1, newDisk2);

    // Друк оновленого вмісту файлу
    cout << "Updated file contents:" << endl;
    printFileContents(filename);

    return 0;
}

