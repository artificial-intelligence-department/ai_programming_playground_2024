#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct stadium {
    string name;
    int year;
    int fields;
    string sports;
};

void create(const string& fname, const vector<stadium>& data) {
    ofstream f(fname, ios::binary);
    if (!f) {
        cerr << "File opening error" << endl;
        return;
    }
    for (const auto& s : data) {
        f.write((char*)&s, sizeof(stadium));
    }
    f.close();
}

void print(const string& fname) {
    ifstream f(fname, ios::binary);
    if (!f) {
        cerr << "File opening error" << endl;
        return;
    }
    stadium s;
    while (f.read((char*)&s, sizeof(stadium))) {
        cout << "Name: " << s.name << ", Year: " << s.year
            << ", Fields: " << s.fields
            << ", Sports: " << s.sports << endl;
    }
    f.close();
}

void del(const string& fname, int y) {
    ifstream f(fname, ios::binary);
    if (!f) {
        cerr << "File opening error" << endl;
        return;
    }
    vector<stadium> data;
    stadium s;
    while (f.read((char*)&s, sizeof(stadium))) {
        if (s.year >= y) {
            data.push_back(s);
        }
    }
    f.close();
    ofstream out(fname, ios::binary | ios::trunc);
    if (!out) {
        cerr << "File opening error" << endl;
        return;
    }
    for (const auto& item : data) {
        out.write((char*)&item, sizeof(stadium));
    }
    out.close();
}

void add(const string& fname, const stadium& e1, const stadium& e2, int pos) {
    ifstream f(fname, ios::binary);
    if (!f) {
        cerr << "File opening error" << endl;
        return;
    }
    vector<stadium> data;
    stadium s;
    while (f.read((char*)&s, sizeof(stadium))) {
        data.push_back(s);
    }
    f.close();
    if (pos < 0 || pos > data.size()) {
        cerr << "Invalid position" << endl;
        return;
    }
    data.insert(data.begin() + pos, { e1, e2 });
    ofstream out(fname, ios::binary | ios::trunc);
    if (!out) {
        cerr << "File opening error" << endl;
        return;
    }
    for (const auto& item : data) {
        out.write((char*)&item, sizeof(stadium));
    }
    out.close();
}

int main() {
    string fname = "stadiums.dat";
    vector<stadium> data = {
        {"Olympic", 1990, 5, "Football, Basketball"},
        {"Lviv Arena", 2012, 3, "Football"},
        {"Dnipro Arena", 1985, 4, "Football, Volleyball"}
    };

    create(fname, data);
    cout << "File content after creation:" << endl;
    print(fname);

    int y = 2000;
    del(fname, y);
    cout << "\nFile content after deletion:" << endl;
    print(fname);

    stadium e1 = { "New Stadium 1", 2023, 6, "Football, Tennis" };
    stadium e2 = { "New Stadium 2", 2024, 8, "Basketball, Hockey" };
    int pos = 1;
    add(fname, e1, e2, pos);
    cout << "\nFile content after addition:" << endl;
    print(fname);

    return 0;
}
