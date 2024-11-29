#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct Stadion {
    char name[40];
    int year;
    int platforms;
    char sport[40];
};

void input_stadion(Stadion &st) {
    cout << "Enter name: ";
    cin >> st.name;
    cout << "Enter year: ";
    cin >> st.year;
    cout << "Enter number of platforms: ";
    cin >> st.platforms;
    cout << "Enter type of sport: ";
    cin >> st.sport;
}

void print_stadion(const Stadion &st) {
    cout << "Name: " << st.name << endl;
    cout << "Year: " << st.year << endl;
    cout << "Number of platforms: " << st.platforms << endl;
    cout << "Sport: " << st.sport << endl;
}

void add_stadion(const char *filename) {
    FILE *file = fopen(filename, "ab");
    if (!file) {
        cerr << "Error opening file for appending!" << endl;
        return;
    }
    Stadion st;
    input_stadion(st);
    fwrite(&st, sizeof(Stadion), 1, file);
    fclose(file);
}

void show_all(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        cerr << "Error opening file for reading!" << endl;
        return;
    }
    cout << "\nList of stadions:\n";
    Stadion st;
    while (fread(&st, sizeof(Stadion), 1, file)) {
        print_stadion(st);
        cout << "-------------------\n";
    }
    fclose(file);
}

void delete_old_stadions(const char *filename, int target_year) {
    FILE *file = fopen(filename, "rb");
    FILE *temp = fopen("temp.dat", "wb");
    if (!file || !temp) {
        cerr << "Error opening file for deletion!" << endl;
        return;
    }
    Stadion st;
    while (fread(&st, sizeof(Stadion), 1, file)) {
        if (st.year >= target_year) {
            fwrite(&st, sizeof(Stadion), 1, temp);
        }
    }
    fclose(file);
    fclose(temp);
    remove(filename);
    rename("temp.dat", filename);
    cout << "Old stadions deleted.\n";
}

void add_before_position(const char *filename, int position, const Stadion &st1, const Stadion &st2) {
    FILE *file = fopen(filename, "rb");
    FILE *temp = fopen("temp.dat", "wb");
    if (!file || !temp) {
        cerr << "Error opening file for updating!" << endl;
        return;
    }
    Stadion st;
    int current = 1;
    while (fread(&st, sizeof(Stadion), 1, file)) {
        if (current == position) {
            fwrite(&st1, sizeof(Stadion), 1, temp);
            fwrite(&st2, sizeof(Stadion), 1, temp);
        }
        fwrite(&st, sizeof(Stadion), 1, temp);
        current++;
    }
    fclose(file);
    fclose(temp);
    remove(filename);
    rename("temp.dat", filename);
    cout << "New stadions added.\n";
}

int main() {
    const char *filename = "database.dat";

    FILE *file = fopen(filename, "wb");
    if (!file) {
        cerr << "Error creating file!" << endl;
        return 1;
    }
    fclose(file);

    int stadion_count;
    cout << "Enter the number of stadions you want to create: ";
    cin >> stadion_count;

    for (int i = 0; i < stadion_count; i++) {
        cout << "Enter details for stadion " << i + 1 << ":\n";
        add_stadion(filename);
    }

    int year;
    cout << "Enter the minimum year to keep: ";
    cin >> year;
    delete_old_stadions(filename, year);

    Stadion st1, st2;
    int position;
    cout << "Enter position to insert before: ";
    cin >> position;
    cout << "Enter 2 new stadions:\n";
    input_stadion(st1);
    input_stadion(st2);
    add_before_position(filename, position, st1, st2);

    show_all(filename);

    return 0;
}
