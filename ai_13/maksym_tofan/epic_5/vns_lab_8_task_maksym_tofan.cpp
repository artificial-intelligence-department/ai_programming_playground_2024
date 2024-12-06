#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>

using namespace std;

struct Team {
    char name[20];
    char city[20];
    int playerCount;
    int points;
};

void writeInitialData(const char* filename) {
    Team teams[] = {
        {"RealMadrid", "Madrid", 15, 32},
        {"Barcelona", "Barcelona", 18, 19},
        {"Dynamo Kiev", "Kiev", 11, 33},
        {"Karpaty", "Lviv", 16, 39},
        {"Vorskla", "Poltava", 15, 14}
    };

    FILE* file = fopen(filename, "wb");
    if (!file) {
        cerr << "Не вдалося відкрити файл для запису" << endl;
        exit(1);
    }

    for (const auto& team : teams) {
        if (fwrite(&team, sizeof(Team), 1, file) != 1) {
            cerr << "Помилка при записі даних у файл" << endl;
            exit(1);
        }
    }

    fclose(file);
}

void displayDataFromFile(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        cerr << "Не вдалося відкрити файл для зчитування" << endl;
        exit(1);
    }

    Team team;
    while (fread(&team, sizeof(Team), 1, file) == 1) {
        cout << "Команда: " << team.name << endl;
        cout << "Місто: " << team.city << endl;
        cout << "Гравців: " << team.playerCount << endl;
        cout << "Очки: " << team.points << endl << endl;
    }

    fclose(file);
}

void removeTeamsWithLowPoints(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        cerr << "Не вдалося відкрити файл для зчитування" << endl;
        exit(1);
    }

    vector<Team> filteredTeams;
    int minPoints;
    cout << "Введіть мінімальну кількість очок: ";
    cin >> minPoints;

    Team team;
    while (fread(&team, sizeof(Team), 1, file) == 1) {
        if (team.points >= minPoints) {
            filteredTeams.push_back(team);
        }
    }

    fclose(file);

    file = fopen(filename, "wb");
    if (!file) {
        cerr << "Не вдалося відкрити файл для запису" << endl;
        exit(1);
    }

    for (const auto& team : filteredTeams) {
        fwrite(&team, sizeof(Team), 1, file);
    }

    fclose(file);
}

void appendNewTeamsToFile(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        cerr << "Не вдалося відкрити файл для зчитування" << endl;
        exit(1);
    }

    vector<Team> newTeams = {
        {"Shakhtar", "Donetsk", 11, 35},
        {"Chornomorets", "Odesa", 20, 9}
    };

    vector<Team> allTeams = newTeams;
    Team team;
    while (fread(&team, sizeof(Team), 1, file) == 1) {
        allTeams.push_back(team);
    }

    fclose(file);

    file = fopen(filename, "wb");
    if (!file) {
        cerr << "Не вдалося відкрити файл для запису" << endl;
        exit(1);
    }

    for (const auto& team : allTeams) {
        fwrite(&team, sizeof(Team), 1, file);
    }

    fclose(file);
}

int main() {
    const char* filename = "teams_data.bin";

    writeInitialData(filename);         // Записуємо початкові дані в файл
    cout << "Дані з файлу до змін:" << endl;
    displayDataFromFile(filename);      // Виводимо дані з файлу

    removeTeamsWithLowPoints(filename); // Видаляємо команди з малими очками

    appendNewTeamsToFile(filename);    // Додаємо нові команди до файлу

    cout << "Дані з файлу після змін:" << endl;
    displayDataFromFile(filename);     // Виводимо оновлені дані з файлу

    return 0;
}
