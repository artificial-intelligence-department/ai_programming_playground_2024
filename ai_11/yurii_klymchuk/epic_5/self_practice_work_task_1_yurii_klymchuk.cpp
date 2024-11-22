//Шифрування/дешифрування файлу за рахунок зміщення символів
//на одну позицію по ASCII таблиці

#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

//файл для запису зашифрованого файлу  
void encryptFile(const char* inputFile, const char* outputFile) {
    FILE* print = fopen(inputFile, "rb");
    if (!print) {
        cout << "Error while opening the file " << inputFile << endl;
        return;
    }

    char buffer_for_original[256];
    cout << "Your file:\n";
    while (fgets(buffer_for_original, sizeof(buffer_for_original), print)) {
        cout << buffer_for_original;
    }
    cout << endl;
    fclose(print);

    FILE* input = fopen(inputFile, "rb");
    if (!input) {
        cout << "Error while opening the file " << inputFile << endl;
        return;
    }
    FILE* output = fopen(outputFile, "wb");
    if (!output) {
        cout << "Error while opening the file " << outputFile << endl;
        return;
    }
    
    char buffer[256];
    cout << "\nYour encrypted file:\n";
    while (fgets(buffer, sizeof(buffer), input)) {
        for (size_t i = 0; i < strlen(buffer); i++) {
            if (buffer[i] != '\n' && buffer[i] != '\r') {
                buffer[i] = buffer[i] + 1;
            }
        }
        cout << buffer;
        fputs(buffer, output);
    }
    fclose(input);
    fclose(output);
}

//файл для дешифрування
void decryptFile(const char* inputFile, const char* outputFile) {
    FILE* print = fopen(inputFile, "rb");
    if (!print) {
        cout << "Error while opening the file " << inputFile << endl;
        return;
    }

    char buffer_for_original[256];
    cout << "Your file:\n";
    while (fgets(buffer_for_original, sizeof(buffer_for_original), print)) {
        cout << buffer_for_original;
    }
    cout << endl;
    fclose(print);

    FILE* input = fopen(inputFile, "rb");
    if (!input) {
        cout << "Error while opening the file " << inputFile << endl;
        return;
    }
    FILE* output = fopen(outputFile, "wb");
    if (!output) {
        cout << "Error while opening the file " << outputFile << endl;
        return;
    }

    char buffer[256];
    cout << "\nYour decrypted file:\n";
    while (fgets(buffer, sizeof(buffer), input)) {
        for (size_t i = 0; i < strlen(buffer); i++) {
            if (buffer[i] != '\n' && buffer[i] != '\r') {
                buffer[i] = buffer[i] - 1;
            }
        }
        cout << buffer;
        fputs(buffer, output);
        
    }
    fclose(input);
    fclose(output);
}

int main() {
    const char* inputFile = "input.txt";
    const char* encryptedFile = "encrypted.txt";
    const char* decryptedFile = "decrypted.txt";
    int input = 0;
    //меню для роботи з програмою
    Menu:
    cout << "Welcome to spyware, how can I help you:\n";
    cout << "Enter \"1\" to encrypt the file\n";
    cout << "Enter \"2\" to decrypt the file\n";
    cout << "Press \"0\" to exit the program\n";
    cin >> input;
    switch(input){
        case 0:
            cout << "Goodbye";
            return 0;
        case 1:
            encryptFile(inputFile, encryptedFile);
            break;
        case 2:
            decryptFile(encryptedFile, decryptedFile);
            break;
        default:
            cout << "Wrong option\n";
            goto Menu;
    };
    
    return 0;
}
