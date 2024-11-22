#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct INFORMATION {
    char carrier[40];
    float volume;
    char title[40];
    char author[40];
};

//к-сть записів для початкового створення файлу
const int N = 2;

void create_file(const char* filename) {
    FILE* file = fopen(filename, "wb");  // відкриваємо файл для запису в двійковому режимі
    if (file == NULL) {
        printf("ERROR: Unable to open file for writing.\n");
        exit(1);
    }

    struct INFORMATION info;  //створюємо змінну типу INFORMATION

    for (int i = 0; i < N; i++) {

        printf("Enter carrier: ");
        scanf("%s", info.carrier);
        printf("Enter volume: ");
        scanf("%f", &info.volume);
        printf("Enter title: ");
        scanf("%s", info.title);
        printf("Enter author: ");
        scanf("%s", info.author);

        //записуємо структуру в файл
        fwrite(&info, sizeof(struct INFORMATION), 1, file);
        if (ferror(file)) {
            printf("ERROR: Problem while writing to file.\n");
            fclose(file);
            exit(2);
        }
    }
    fclose(file); 
}

void print_file(const char* filename) {
    FILE* file = fopen(filename, "rb");  //відкриваємо файл для читання
    if (file == NULL) {
        printf("ERROR: Unable to open file for reading.\n");
        exit(3);
    }

    struct INFORMATION info;
    printf("File contents:\n");

    //читаємо файл по одному запису
    while (fread(&info, sizeof(struct INFORMATION), 1, file) == 1) {
        printf("Carrier: %s, Volume: %.2f, Title: %s, Author: %s\n", 
               info.carrier, info.volume, info.title, info.author);
    }

    fclose(file); 
}

void delete_first_with_volume(const char* filename, float target_volume) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("ERROR: Unable to open file for reading.\n");
        exit(4);
    }

    FILE* temp_file = fopen("temp.dat", "wb");
    if (temp_file == NULL) {
        printf("ERROR: Unable to create temporary file.\n");
        fclose(file);
        exit(5);
    }

    struct INFORMATION info;
    int deleted = 0;

    while (fread(&info, sizeof(struct INFORMATION), 1, file) == 1) {
        if (!deleted && info.volume == target_volume) {
            deleted = 1;
        } else {
            fwrite(&info, sizeof(struct INFORMATION), 1, temp_file);
        }
    }

    fclose(file);
    fclose(temp_file);

    remove(filename);
    rename("temp.dat", filename);

    if (deleted) {
        printf("First element with volume %.2f removed.\n", target_volume);
    } else {
        printf("Element with volume %.2f not found.\n", target_volume);
    }
}

void add_information_before(const char* filename, struct INFORMATION newInfo, int position) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("ERROR: Unable to open file for reading.\n");
        exit(6);
    }

    FILE* temp_file = fopen("temp.dat", "wb");
    if (temp_file == NULL) {
        printf("ERROR: Unable to create temporary file.\n");
        fclose(file);
        exit(7);
    }

    struct INFORMATION info;
    int index = 1;

    //читаємо оригінальний файл
    while (fread(&info, sizeof(struct INFORMATION), 1, file) == 1) {
        //додаємо новий елемент перед певною позицією
        if (index == position) {
            fwrite(&newInfo, sizeof(struct INFORMATION), 1, temp_file);  // запис нового елемента
        }
        fwrite(&info, sizeof(struct INFORMATION), 1, temp_file);  // запис поточного елемента
        index++;
    }

    fclose(file);
    fclose(temp_file);

    remove(filename);  // видаляємо оригінальний файл
    rename("temp.dat", filename);  // перейменовуємо тимчасовий файл в оригінальний

    printf("New element added before position %d.\n", position);
}

int main() {
    const char* filename = "information.dat";

    create_file(filename);

    print_file(filename);

    struct INFORMATION newInfo = {"USB", 5.0, "Programming Guide", "Smith"};
    add_information_before(filename, newInfo, 2);

    delete_first_with_volume(filename, 3.0);

    printf("\nAfter deletion and addition:\n");
    print_file(filename);

    return 0;
}
