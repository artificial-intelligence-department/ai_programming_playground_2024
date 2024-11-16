#include <iostream>
#include <cstring>

using namespace std;
void CreateFile(const char* filename);
void CreateSecondFile(const char* filename2, const char* filename1);
long getFileSize(const char* filename);
int main(){

    const char* filename1 = "1vns_lab_8.txt";
    const char* filename2 = "2vns_lab_8.txt";

    CreateFile(filename1);
    CreateSecondFile(filename2, filename1);
    long sizeF1 = getFileSize(filename1);
    long sizeF2 = getFileSize(filename2);
    
    cout << "Size of F1: " << sizeF1 << " bytes\n";
    cout << "Size of F2: " << sizeF2 << " bytes\n";

    return 0;
}

void CreateFile(const char* filename)
{
    FILE* file1 = nullptr;
    file1 = fopen(filename, "w");
    if(file1 == nullptr)
    {
        cout << "Error";
        return;
    }

    const char* strings[10] = {
        "First string",
        "Second string",
        "Third string",
        "Fourth string",
        "Fifth string",
        "Sixth string",
        "Seventh string",
        "Eighth string",
        "Ninth string",
        "Tenth string"
    };

    for (int i = 0; i < 10; i++) {
        fputs(strings[i], file1);
        fputs("\n", file1);
    }

    fclose(file1);
}

void CreateSecondFile(const char* filename2, const char* filename1)
{
    FILE* file1;
    file1 = fopen(filename1, "r");
    if(file1 == nullptr)
    {
        cout << "Error";
        return;
    }

    FILE* file2 = fopen(filename2, "w");
    if (file2 == nullptr) {
        cout << "Error opening file F2 for writing.\n";
        fclose(file1);
        return;
    }
    char line[256];
    int index = 1;
    while(fgets(line, sizeof(line), file1) != nullptr)
    {
        if(index % 2 ==0)
        {
            fputs(line, file2);
        }
        index++;
    }
    fclose(file1);
    fclose(file2);

}

long getFileSize(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == nullptr) {
        cout << "Error opening file for size calculation.\n";
        return -1;
    }

    fseek(file, 0, SEEK_END);
    
    long size = ftell(file);
    
    fclose(file);
    
    return size;
}