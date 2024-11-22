#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Team {
    char name[50];
    char city[50];
    int players;
    int points;
};

void writeTeam(ofstream &file, const Team &team) {
    file.write(reinterpret_cast<const char*>(&team), sizeof(Team));
}

bool readTeam(ifstream &file, Team &team) {
    return file.read(reinterpret_cast<char*>(&team), sizeof(Team)) ? true : false;
}

void createBinaryFile(const string &filename) {
    ofstream file(filename, ios::binary);
    if (!file) {
        cerr << "Не вдалося відкрити файл для запису." << endl;
        return;
    }

    Team teams[] = {
        {"Ukraine", "Lviv", 11, 50},
        {"Sport", "kyiv", 12, 30},
        {"Gym", "Mykolaiv", 10, 20},
        {"Power", "Kharkiv", 9, 70}
    };

    for (const auto &team : teams) {
        writeTeam(file, team);
    }

    file.close();
    cout << "Файл створено успішно." << endl;
}

void printBinaryFile(const string &filename) {
    ifstream file(filename, ios::binary);
    if (!file) {
        cerr << "Не вдалося відкрити файл для читання." << endl;
        return;
    }

    Team team;
    while (readTeam(file, team)) {
        cout << "Назва: " << team.name << ", Місто: " << team.city
             << ", Гравці: " << team.players << ", Очки: " << team.points << endl;
    }

    file.close();
}

void deleteTeamsWithFewPoints(const string &filename, int minPoints) {
    ifstream inputFile(filename, ios::binary);
    if (!inputFile) {
        cerr << "Не вдалося відкрити файл для читання." << endl;
        return;
    }

    vector<Team> teams;
    Team team;
    while (readTeam(inputFile, team)) {
        if (team.points >= minPoints) {
            teams.push_back(team);
        }
    }
    inputFile.close();

    ofstream outputFile(filename, ios::binary | ios::trunc);
    if (!outputFile) {
        cerr << "Не вдалося відкрити файл для запису." << endl;
        return;
    }

    for (const auto &t : teams) {
        writeTeam(outputFile, t);
    }
    outputFile.close();
}

void addTeamsToFile(const string &filename, const vector<Team> &newTeams) {
    ifstream inputFile(filename, ios::binary);
    if (!inputFile) {
        cerr << "Не вдалося відкрити файл для читання." << endl;
        return;
    }

    vector<Team> teams(newTeams);
    Team team;
    while (readTeam(inputFile, team)) {
        teams.push_back(team);
    }
    inputFile.close();

    ofstream outputFile(filename, ios::binary | ios::trunc);
    if (!outputFile) {
        cerr << "Не вдалося відкрити файл для запису." << endl;
        return;
    }

    for (const auto &t : teams) {
        writeTeam(outputFile, t);
    }
    outputFile.close();
}

int main() {
    string filename = "teams.bin";

    createBinaryFile(filename);
    cout << "Початковий вміст файлу:" << endl;
    printBinaryFile(filename);

    int minPoints = 40;
    deleteTeamsWithFewPoints(filename, minPoints);
    cout << "\nВміст файлу після видалення команд з очками менше " << minPoints << ":" << endl;
    printBinaryFile(filename);

    vector<Team> newTeams = {
        {"Leaders", "Donetsk", 15, 60},
        {"Strong", "Odesa", 13, 80}
    };
    addTeamsToFile(filename, newTeams);
    cout << "\nВміст файлу після додавання нових команд:" << endl;
    printBinaryFile(filename);

    return 0;
}
