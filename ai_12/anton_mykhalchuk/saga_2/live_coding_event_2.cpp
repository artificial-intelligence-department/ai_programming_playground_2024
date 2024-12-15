#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

const double m = 1, mi = 1609.344, mi_us = 1609.347; 

int* createID(string userName) {
    int n = userName.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1; ++j) {
            if (userName[j] > userName[j + 1]) {
                swap(userName[j], userName[j + 1]);
            }
        }
    }
    int* id = new int[n];
    for (int i = 0; i < n; ++i) {
        id[i] = int(userName[i]) * 0.4;
    }

    return id;
}

string intArrayToString(int* arr, int n) {
  string returnstring = "";
  for (int temp = 0; temp < n; temp++)
    returnstring += to_string(arr[temp]);
  return returnstring;
}


bool isRegistered(string id, int n) {
    string filename = "collected_distance.txt";

    ifstream file(filename);

    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            if (line.find(id) != string::npos) {
                return true;
            }
        }
        file.close();
    }
    else {
        cerr << "File \"" << filename << "\" is not existing or can't be opened.\n";
    }
    
    return false;

}

void createRecord(string id, double dist) {
    string filename = "collected_distance.txt";
    ofstream file(filename);

    if (file.is_open()) {
        file << id << " " << dist << endl;
    }
    else {
        cerr << "Can't open file for writting: " << filename << endl;
    }
}

void addToRecord(string id, double dist) {
    string filename = "collected_distance.txt";
    vector<pair<string, double>> data;
    ifstream file(filename);

    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            istringstream iss(line);
            string id;
            int value;
            if (iss >> id >> value) {
                data.push_back({id, value});
            }
        }
        file.close();
    }
    else {
        cerr << "File \"" << filename << "\" is not existing or can't be opened.\n";
    }

    bool idFound;
    for (auto& pair : data) {
        if (pair.first == id) {
            
        }
    }


    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "File \"" << filename << "\" is not existing or can't be opened.\n";
    }

    for (int i = 0; i < lenght; ++i) {

    }
}

int main() {
    string userName, measurementSystem;
    double distanceValue;

    cout << "Enter your name: ";
    cin >> userName;
    int n = userName.size();
    int* id = createID(userName);
    string strID = intArrayToString(id, n);

    cout << "Enter distance: ";
    cin >> distanceValue;

    cout << "Enter units of measurement (meter/mile/mile_us): ";
    cin >> measurementSystem;

    if (isRegistered(strID, n)) {
        createRecord(strID, distanceValue);
    }
    else {
        addToRecord(strID, distanceValue);
    }


    return 0;
}