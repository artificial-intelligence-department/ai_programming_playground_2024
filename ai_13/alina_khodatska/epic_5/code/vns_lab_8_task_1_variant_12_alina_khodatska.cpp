#include <iostream>
#include <fstream>  // ��� ������ � �������
#include <cstring>  // ��� ������ � �������

using namespace std;

struct MusicDisk {
    char title[100];
    char author[100];
    int duration;  // ��������� � ��������
    float price;
};

// ������� ��� ��������� ���������� ��� �������� ����
void printDisk(const MusicDisk& disk) {
    cout << "Title: " << disk.title << endl;
    cout << "Author: " << disk.author << endl;
    cout << "Duration: " << disk.duration << " seconds" << endl;
    cout << "Price: " << disk.price << " USD" << endl;
    cout << "----------------------------------------" << endl;
}

// ������� ��� ��������� �������� �����
void createBinaryFile(const char* filename) {
    ofstream file(filename, ios::binary);  // ofstream ��� ������ � ������� ����, ios::binary - �������� ����� � �������� �����
    if (!file) {  // !file - �������� �� ������� �������� �����
        cerr << "Error opening file for writing!" << endl;
        return;
    }

    // ������� ����� ��� ������
    MusicDisk disks[] = {
        {"Album 1", "Artist 1", 3600, 15.99},
        {"Album 2", "Artist 2", 4200, 20.99},
        {"Album 3", "Artist 3", 3900, 18.49},
        {"Album 4", "Artist 4", 3000, 12.99}
    };

    // �������� ��� � ������� ����
    file.write(reinterpret_cast<char*>(&disks), sizeof(disks));
    // reinterpret_cast - ������������ ���� �����(MusicDisk* � char*), &disks - ������ ������� �������� ������, sizeof(disks) - ����� ������ � ������
    file.close();
    cout << "File created successfully!" << endl;
}

// ������� ��� ����� ����� �������� �����
void printFileContents(const char* filename) {
    ifstream file(filename, ios::binary);  // ifstream ��� ������� � �������� �����
    if (!file) {
        cerr << "Error opening file for reading!" << endl;
        return;
    }

    file.seekg(0, ios::end);  // file.seekg - ���������� ios::end - ��������� � ����� �����
    size_t fileSize = file.tellg();  // file.tellg - ������� ������� ��������� ���������
    file.seekg(0, ios::beg);   // ����������� �� ������� �����

	size_t numRecords = fileSize / sizeof(MusicDisk);  // ʳ������ ������ � ����
    MusicDisk disk;

	for (size_t i = 0; i < numRecords; ++i) { // ���� ��� ������� ��� ������
        file.read(reinterpret_cast<char*>(&disk), sizeof(MusicDisk));
        cout << "Disk #" << i + 1 << ":" << endl;
        printDisk(disk);
    }

    file.close();
}

// ������� ��� ��������� �������� �� ���������
void deleteDiskByDuration(const char* filename, int duration) {
    fstream file(filename, ios::in | ios::out | ios::binary);  // fstream ��� ������� �� ������ � ������� ����
    // ios::in - �������� ����� ��� �������, ios::out - �������� ����� ��� ������, ios::binary - �������� ����� � �������� �����
    if (!file) {
        cerr << "Error opening file for modification!" << endl;
        return;
    }

	file.seekg(0, ios::end); 
	size_t fileSize = file.tellg(); // ������� ��������� ���������
	size_t numRecords = fileSize / sizeof(MusicDisk); // ʳ������ ������ � ����

    MusicDisk disk;
	bool found = false; // �������� ������� ��� ���������
    size_t deletePos = 0; 

	for (size_t i = 0; i < numRecords; ++i) { // ���� ��� ������ �������� �� ���������
        file.seekg(i * sizeof(MusicDisk), ios::beg); 
        file.read(reinterpret_cast<char*>(&disk), sizeof(MusicDisk)); 

		if (disk.duration == duration) { // ���� �������� ������� ��� ���������
            found = true; 
            deletePos = i;
            break;
        }
    }

	// ���� ������� ��������
    if (found) {
        // ��������� �� �������� ���� ���������� �� ���� ������� �����
        for (size_t i = deletePos + 1; i < numRecords; ++i) {
            file.seekg(i * sizeof(MusicDisk), ios::beg);
            file.read(reinterpret_cast<char*>(&disk), sizeof(MusicDisk));

            file.seekp((i - 1) * sizeof(MusicDisk), ios::beg);  // file.seekp - ���������� ��������� ������ ios::beg - �� ������� �����
            file.write(reinterpret_cast<char*>(&disk), sizeof(MusicDisk));
        }

        // ��������� ����� �����
        file.seekp((numRecords - 1) * sizeof(MusicDisk), ios::beg);
        MusicDisk emptyDisk = {};  // ������� ����
        file.write(reinterpret_cast<char*>(&emptyDisk), sizeof(MusicDisk));
        cout << "Disk with duration " << duration << " seconds deleted." << endl;
    }
    else {
        cout << "Disk with specified duration not found." << endl;
    }

    file.close();
}

// ������� ��� ��������� ���� �������� ���� ��������� ��������
void addDisksAfterIndex(const char* filename, size_t index, const MusicDisk& newDisk1, const MusicDisk& newDisk2) {
    fstream file(filename, ios::in | ios::out | ios::binary);
    if (!file) {
        cerr << "Error opening file for modification!" << endl;
        return;
    }

    file.seekg(0, ios::end);
    size_t fileSize = file.tellg();
    size_t numRecords = fileSize / sizeof(MusicDisk);

	if (index >= numRecords) { // �������� �� ����������� �������
        cerr << "Invalid index!" << endl;
        file.close();
        return;
    }

    // ��������� ���������� ����� ��� ���������� �������� ���� �������
    MusicDisk* tempDisks = new MusicDisk[numRecords - index];
    file.seekg((index + 1) * sizeof(MusicDisk), ios::beg);
    file.read(reinterpret_cast<char*>(tempDisks), (numRecords - index - 1) * sizeof(MusicDisk));

    // ��������� �������� �� ���� ���������
    file.seekp((index + 1) * sizeof(MusicDisk), ios::beg);

    // �������� ��� ��������
    file.write(reinterpret_cast<const char*>(&newDisk1), sizeof(MusicDisk));
    file.write(reinterpret_cast<const char*>(&newDisk2), sizeof(MusicDisk));

    // �������� �� ���� �������� ���� �������
    file.write(reinterpret_cast<const char*>(tempDisks), (numRecords - index - 1) * sizeof(MusicDisk));

    delete[] tempDisks;
    cout << "Two disks added after disk #" << index + 1 << endl;

    file.close();
}

int main() {
    const char* filename = "music_disks.dat";

    // ��������� �������� �����
    createBinaryFile(filename);

    // ���� ����� �����
    cout << "File contents:" << endl;
    printFileContents(filename);

    // ��������� ����� �� ���������
    deleteDiskByDuration(filename, 4200);

    // ��������� ���� ����� �����
    MusicDisk newDisk1 = { "Album 5", "Artist 5", 4500, 22.99 };
    MusicDisk newDisk2 = { "Album 6", "Artist 6", 3600, 19.99 };
    addDisksAfterIndex(filename, 1, newDisk1, newDisk2);

    // ���� ���������� ����� �����
    cout << "Updated file contents:" << endl;
    printFileContents(filename);

    return 0;
}

