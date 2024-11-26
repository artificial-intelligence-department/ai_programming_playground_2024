#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

void AddNote(const char* filename);
void ShowNote(const char* filename);
void DeleteNote(const char* filename, int index);
void RenumberNotes(const char* filename);

int main() {
    const char* filename = "Note.txt";
    int choice, index;
    do {
        cout << "1. Add note\n2. Show note\n3. Delete note\n4. Exit\n";
        cin >> choice;
        cin.ignore();  

        switch (choice) {
            case 1:
                AddNote(filename);
                break;
            case 2:
                ShowNote(filename);
                break;
            case 3:
                cout << "Enter index to be deleted: ";
                cin >> index;
                DeleteNote(filename, index);
                break;
            case 4:
                break;
            default:
                cerr << "Invalid choice!" << endl;
        }

    } while (choice != 4);

    return 0;
}

void AddNote(const char* filename) {
    FILE* file = fopen(filename, "a"); 
    if (!file) {
        cerr << "Failed to open Note\n";
        return;
    }

    string content;
    cout << "Enter text: ";
    getline(cin, content); 


    fprintf(file, "%s\n", content.c_str());  
    cout << "Text written to the Note\n";
    fclose(file); 


    RenumberNotes(filename);
}

void ShowNote(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        cerr << "Failed to open Note\n";
        return;
    }

    char line[256]; 
    cout << "Notes:\n";
    while (fgets(line, sizeof(line), file)) {
        cout << line;  
    }

    fclose(file);
    RenumberNotes(filename);
}

void DeleteNote(const char* filename, int index) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        cerr << "Error opening file for reading!\n";
        return;
    }
    
    const char* filename2 = "temp.txt";
    FILE* tempFile = fopen(filename2, "w");
    if (!tempFile) {
        cerr << "Error opening temporary file for writing!\n";
        fclose(file);
        return;
    }

    int currentLine = 1;
    char line[256];
    
    while (fgets(line, sizeof(line), file)) {
        if (currentLine != index) {
            fputs(line, tempFile);
        }
        currentLine++;
    }

    fclose(file);
    fclose(tempFile);

    remove(filename);
    rename(filename2, filename);

    cout << "Note " << index << " deleted successfully.\n";

    RenumberNotes(filename);
}

void RenumberNotes(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        cerr << "Error opening file for reading!\n";
        return;
    }
    
    vector<string> lines;
    char line[256];
    
    while (fgets(line, sizeof(line), file)) {
        lines.push_back(line);
    }
    fclose(file);

    // Перезаписуємо файл з новими номерами
    file = fopen(filename, "w");
    if (!file) {
        cerr << "Error opening file for writing!\n";
        return;
    }
    for (int i = 0; i < lines.size(); i++) {
        fprintf(file, "%d) %s", i + 1, lines[i].c_str());
    }

    fclose(file);
}
