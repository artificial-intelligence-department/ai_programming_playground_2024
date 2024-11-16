#include <iostream>
#include <cstring>

using namespace std;

void createAndWriteToFile(const char* filename);
void printFile(const char* filename);
bool hasDuplicateWords(const char* line);
void createNewFileWithNoDuplicates(const char* fromFileName, const char* toFileName);
int countVowelsInFirstLine(const char* filename);

int main() {
    const char *filename1 = "F1.txt";
    const char *filename2 = "F2.txt";
    createAndWriteToFile(filename1);
    printFile(filename1);
    createNewFileWithNoDuplicates(filename1, filename2);
    printFile(filename2);
    cout << endl << "Number of vowels in the first line of F2: " << countVowelsInFirstLine(filename2) << endl;
}

void createAndWriteToFile(const char* filename) {
    FILE *file = fopen(filename, "w"); 
    if (file == NULL) {
        cerr << "Не вдалося відкрити файл для запису" << endl;
        exit(1);
    }

    const char* lines[] = {
        "line 1\n",
        "line 2: line\n",
        "line 3\n",
        "line 4: line line\n",
        "line 5\n",
        "line 6\n",
        "line 7: line\n",
        "line 8\n",
        "line 9: line line\n",
        "line 10\n"
    };

    for (int i = 0; i < 10; i++) {
        fputs(lines[i], file);
    }

    cout << "Дані успішно записані у файл " << filename << endl;
    fclose(file); 
}

void printFile(const char* filename) {
    FILE *f = fopen(filename, "r"); 
    if (f == NULL) {
        cerr << "Не вдалося відкрити файл для читання" << endl;
        exit(2);
    }

    char line[256];

    cout << "Вміст файлу " << filename << ":\n";
    cout << "---------------------------------\n";

    while (fgets(line, sizeof(line), f)) {
        cout << line;
    }

    fclose(f);
}

bool hasDuplicateWords(char* line){
    char tmpLine[256];
    strncpy(tmpLine, line, sizeof(tmpLine) - 1);
    tmpLine[sizeof(tmpLine) - 1] = '\0';

    const char* words[50];
    int wordCount = 0;

    char* word = strtok(tmpLine, " \n");
    while (word != nullptr) {

        for (int i = 0; i < wordCount; ++i) {
            if (strcmp(words[i], word) == 0) {
                return true; 
            }
        }

        words[wordCount++] = word;
        word = strtok(nullptr, " \n");
    }
    return false;
}

void createNewFileWithNoDuplicates(const char* fromFileName, const char* toFileName){
    FILE *from = fopen(fromFileName, "r");
    FILE *to = fopen(toFileName, "w"); 
    if (from == NULL || to == NULL) {
        cerr << "Не вдалося відкрити файл для читання" << endl;
        exit(3);
    }

    char line[256];

    while(fgets(line, sizeof(line), from)){
        if(!hasDuplicateWords(line)){
            fputs(line, to);
        }
    }

    fclose(from);
    fclose(to);

    cout << "Lines without repeated words copied successfully." << endl;
}

int countVowelsInFirstLine(const char* filename){
    FILE* f = fopen(filename, "r");

    if(f == NULL){
        cerr << "Не вдалося відкрити файл для читання" << endl;
        exit(4);
    }

    char line[256];
    if (fgets(line, sizeof(line), f) == NULL) {
        fclose(f);
        return 0;  // No lines in file
    }

    int counter = 0;

    for(int i = 0; line[i] != '\0'; i++){
        char ch = tolower(line[i]);
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
            counter++;
        }
    }

    return counter;
}
