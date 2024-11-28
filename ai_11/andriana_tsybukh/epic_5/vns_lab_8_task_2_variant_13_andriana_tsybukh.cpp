#include <iostream>
#include <fstream>
#include <cstring>

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
        {"Команда A", "Київ", 11, 30},
        {"Команда B", "Львів", 12, 25},
        {"Команда C", "Одеса", 10, 20},
        {"Команда D", "Харків", 15, 15},
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

    Team teams[100];
    int count = 0;

    Team team;
    while (readTeam(inputFile, team)) {
        if (team.points >= minPoints) {
            teams[count++] = team;
        }
    }
    inputFile.close();

    ofstream outputFile(filename, ios::binary | ios::trunc);
    if (!outputFile) {
        cerr << "Не вдалося відкрити файл для запису." << endl;
        return;
    }

    for (int i = 0; i < count; ++i) {
        writeTeam(outputFile, teams[i]);
    }
    outputFile.close();
}

void addTeamsToFile(const string &filename, const Team *newTeams, int newCount) {
    ifstream inputFile(filename, ios::binary);
    if (!inputFile) {
        cerr << "Не вдалося відкрити файл для читання." << endl;
        return;
    }

    Team teams[100];
    int count = 0;

    Team team;
    while (readTeam(inputFile, team)) {
        teams[count++] = team;
    }
    inputFile.close();

    ofstream outputFile(filename, ios::binary | ios::trunc);
    if (!outputFile) {
        cerr << "Не вдалося відкрити файл для запису." << endl;
        return;
    }

    for (int i = 0; i < newCount; ++i) {
        writeTeam(outputFile, newTeams[i]);
    }

    for (int i = 0; i < count; ++i) {
        writeTeam(outputFile, teams[i]);
    }
    outputFile.close();
}

int main() {
    string filename = "teams.bin";

    createBinaryFile(filename);
    cout << "Початковий вміст файлу:" << endl;
    printBinaryFile(filename);

    int minPoints = 30;
    deleteTeamsWithFewPoints(filename, minPoints);
    cout << "\nВміст файлу після видалення команд з очками менше " << minPoints << ":" << endl;
    printBinaryFile(filename);

    Team newTeams[] = {
        {"Команда E", "Дніпро", 13, 50},
        {"Команда F", "Тернопіль", 14, 45},
    };
    addTeamsToFile(filename, newTeams, 2);
    cout << "\nВміст файлу після додавання нових команд:" << endl;
    printBinaryFile(filename);

    return 0;
}
