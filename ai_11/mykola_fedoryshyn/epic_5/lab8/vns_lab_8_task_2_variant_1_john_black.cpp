#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>

using namespace std;

struct Stadium {
    char name[40];
    char address[40];
    int capacity;
    char sports[40];
};

const int N = 2;

void create_file(const char* filename) {
    FILE* file;

    file = fopen(filename, "wb");
    if (file == NULL) {
        cerr << "ERROR while opening file for writing." << endl;
        exit(1);
    }

    Stadium stadium;

    for (int i = 0; i < N; i++) {
        cout << "Name: "; cin >> stadium.name;
        cout << "Address: "; cin >> stadium.address;
        cout << "Capacity: "; cin >> stadium.capacity;
        cout << "Sports: "; cin >> stadium.sports;

        fwrite(&stadium, sizeof(Stadium), 1, file);
        if (ferror(file)) {
            cerr << "ERROR while writing in file." << endl;
            exit(2);
        }
    }
    fclose(file);
}

void print_file(const char* filename) {
    FILE* file;
    file = fopen(filename, "rb");
    if (file == NULL) {
        cerr << "ERROR while opening file for reading." << endl;
        exit(3);
    }

    Stadium stadium;
    cout << "File contains:" << endl;

    while (fread(&stadium, sizeof(Stadium), 1, file) == 1) {
        cout << stadium.name << ", " << stadium.address << ", " 
             << stadium.capacity << ", " << stadium.sports << endl;
    }

    fclose(file);
}

void add_stadium(const char* filename, Stadium newStadium) {
    FILE* file;
    file = fopen(filename, "ab");
    if (file == NULL) {
        cerr << "ERROR while opening file for writing." << endl;
        exit(4);
    }

    fwrite(&newStadium, sizeof(Stadium), 1, file);
    if (ferror(file)) {
        cerr << "ERROR writing while adding stadium." << endl;
        exit(5);
    }

    fclose(file);
}


void add_stadium_after(const char* filename, const char* stadium_name, Stadium newStadium) {
    FILE* file;
    file = fopen(filename, "rb");
    if (file == NULL) {
        cerr << "ERROR while opening file for reading." << endl;
        exit(4);
    }

    FILE* temp_file;
    temp_file = fopen("temp.dat", "wb");
    if (temp_file == NULL) {
        cerr << "ERROR while creating temporary file" << endl;
        fclose(file);
        exit(5);
    }

    Stadium stadium;
    bool found = false;

    while (fread(&stadium, sizeof(Stadium), 1, file) == 1) {
        fwrite(&stadium, sizeof(Stadium), 1, temp_file); 
        if (strcmp(stadium.name, stadium_name) == 0 && !found) {
            fwrite(&newStadium, sizeof(Stadium), 1, temp_file); 
            found = true;
        }
    }

    fclose(file);
    fclose(temp_file);

    if (found) {
        remove(filename);
        rename("temp.dat", filename);
        cout << "Stadium added after " << stadium_name << endl;
    } else {
        cout << "Stadium with name " << stadium_name << " isn't found." << endl;
        remove("temp.dat");
    }
}

void delete_stadium_by_name(const char* filename, const char* stadium_name) {
    FILE* file;
    file = fopen(filename, "rb");
    if (file == NULL) {
        cerr << "ERROR while opening file for deleting." << endl;
        exit(6);
    }

    FILE* temp_file;
    temp_file = fopen("temp.dat", "wb");
    if (temp_file == NULL) {
        cerr << "ERROR while creating temporary file" << endl;
        fclose(file);
        exit(7);
    }

    Stadium stadium;
    bool deleted = false;
    while (fread(&stadium, sizeof(Stadium), 1, file)) {
        if (strcmp(stadium.name, stadium_name) == 0) {
            deleted = true;
        } else {
            fwrite(&stadium, sizeof(Stadium), 1, temp_file);
        }
    }

    fclose(file);
    fclose(temp_file);

    if (deleted) {
        remove(filename);
        rename("temp.dat", filename);
        cout << "Stadium " << stadium_name << " removed from file." << endl;
    } else {
        cout << "Stadium with name " << stadium_name << " isn't found." << endl;
        remove("temp.dat");
    }
}

int main() {
    const char* filename = "stadiums.dat";
    string name_to_delete;
    cout << "Стадіон який будемо видаляти: ";
    getline(cin, name_to_delete);

    cout << "\nСтворення файлу\n";
    create_file(filename);

    cout << "\nДрук файлу\n";
    print_file(filename);

    cout << "\nДодавання нового стадіону\n"; 
    Stadium newStadium = {"Arena Lviv", "Lviv, Ukraine", 35000, "Football"};
    add_stadium(filename, newStadium);

    cout << "\nДодавання нового стадіону після певного стадіону\n"; 
    Stadium anotherStadium = {"Dnipro Arena", "Dnipro, Ukraine", 31000, "Football"};
    add_stadium_after(filename, "Arena Lviv", anotherStadium);

    cout << "\nВидалення стадіону за назвою\n";
    delete_stadium_by_name(filename, name_to_delete.c_str());

    cout << "\nПісля змін: \n";
    print_file(filename);

    return 0;
}


/*
name1
name1
address1
100
sports1
name2
address2
200
sports2
*/