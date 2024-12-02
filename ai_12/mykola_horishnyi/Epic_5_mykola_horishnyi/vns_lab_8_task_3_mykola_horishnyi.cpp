#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

struct State 
{
    char name[100];
    char capital[50];
    int population;
    double area;
};

const char* filename = "states.bin";

// Функція для створення файлу
void createFile() 
{
    FILE* file = fopen(filename, "wb");
    if (!file) 
    {
        cerr << "Error with file." << "\n";
        return;
    }

    int n;
    cout << "Enter number of country: ";
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        State state;
        cout << "Name: ";
        cin.ignore();
        cin.getline(state.name, 100);
        cout << "Capital: ";
        cin.getline(state.capital, 50);
        cout << "Population: ";
        cin >> state.population;
        cout << "Square: ";
        cin >> state.area;

        fwrite(&state, sizeof(State), 1, file);
    }

    fclose(file);
}

// Функція для друку вмісту файлу
void printFile() 
{
    FILE* file = fopen(filename, "rb");
    if (!file) 
    {
        cerr << "Error with file for reading" << "\n";
        return;
    }

    State state;
    bool isEmpty = true;

    while (fread(&state, sizeof(State), 1, file)) 
    {
        isEmpty = false;
        cout << "Name: " << state.name
            << ", Capital: " << state.capital
            << ", Population: " << state.population
            << ", Square: " << state.area << " км²" << "\n";
    }

    if (isEmpty) 
    {
        cout << "File is empty" << "\n";
    }

    fclose(file);
}

// Функція для видалення держав з високою площею
void deleteLargeStates(double maxArea) 
{
    FILE* file = fopen(filename, "rb");
    if (!file) {
        cerr << "Error with file for reading" << "\n";
        return;
    }

    vector<State> states;
    State state;

    while (fread(&state, sizeof(State), 1, file)) 
    {
        if (state.area <= maxArea) {
            states.push_back(state);
        }
    }

    fclose(file);

    file = fopen(filename, "wb");
    if (!file) 
    {
        cerr << "Error with file for looking" << "\n";
        return;
    }

    for (const auto& s : states) 
    {
        fwrite(&s, sizeof(State), 1, file);
    }

    fclose(file);
}

// Функція для додавання нової держави в початок файлу
void addStateToStart() 
{
    State newState;
    cout << "Do you wanna to add new country? :" << "\n";
    cout << "Name: ";
    cin.ignore();
    cin.getline(newState.name, 100);
    cout << "Capital: ";
    cin.getline(newState.capital, 50);
    cout << "Population : ";
    cin >> newState.population;
    cout << "Square: ";
    cin >> newState.area;

    FILE* file = fopen(filename, "rb");
    if (!file) 
    {
        cerr << "Error with file for reading" << "\n";
        return;
    }

    vector<State> states;
    State state;

    while (fread(&state, sizeof(State), 1, file))
    {
        states.push_back(state);
    }

    fclose(file);

    file = fopen(filename, "wb");
    if (!file) {
        cerr << "Error with file for writing" << "\n";
        return;
    }

    fwrite(&newState, sizeof(State), 1, file);

    for (const auto& s : states) {
        fwrite(&s, sizeof(State), 1, file);
    }

    fclose(file);
}

int main() 
{
    createFile();

    cout << "\n" << "File after all chenges:" << "\n";
    printFile();

    double maxArea;
    cout << "\n" << "Max square available: ";
    cin >> maxArea;
    deleteLargeStates(maxArea);

    cout << "\n" << "List contest after deleting too heavy country:" << "\n";
    printFile();

    addStateToStart();

    cout << "\n" << "List contest after adding new country:" << "\n";
    printFile();

    return 0;
}











