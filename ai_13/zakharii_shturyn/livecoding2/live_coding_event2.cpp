#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

string filename = "collected_distance.txt";

struct Person
{
    string index;
    int distance;
    int bonus = 0;
};

int mile_us_to_meter(int distance) {
    return distance * 1609.347;
}

int mile_to_meter(int distance) {
    return distance * 1609.344;
}

void saveData() {

}

void checkUser(string& index, int distance) {
    ifstream myFile(filename, ios::in);
    if (myFile.is_open()) {
        string line;
        while(getline(myFile,line)){
            Person newPerson;
            istringstream lineStream(line);
            lineStream >> newPerson.index >> ;
            if(idx == index) {
                
            }
    }
    myFile.close();
}
}

void generateuser(string& name, int distance) {
    double arrname[30];
        string index = "";
        for(int i = 0;i < name.length(); i++) {
            arrname[i] = name[i];
        }

        for(int i = 0;i < name.length(); i++) {
            arrname[i] = arrname[i] * 0.4;
            index += to_string((int)arrname[i]);
        }
    
    checkUser(index,distance);
}


int main() {

    int opt;
    string name;
    cout << "Enter your name: ";
    cin >> name;
    int namesize = name.length();
    cout << "Which metric system do you prefer to use?\n1)Meter\n2)Mile\n3)Mile us" << endl;
    cin >> opt;
    if(opt == 1) {
        int distance;
        cout << "Enter distance: ";
        cin >> distance;
        generateuser(name,distance);

    } else if(opt == 2) {
        int distance;
        cout << "Enter distance: ";
        cin >> distance;
        distance = mile_to_meter(distance);
        generateuser(name,distance);
    } else if(opt == 3) {
        int distance;
        cout << "Enter distance: ";
        cin >> distance;
        distance = mile_us_to_meter(distance);
        generateuser(name,distance);
    }else {
        cout << "Invalid option!" << endl;
    }

    return 0;
}