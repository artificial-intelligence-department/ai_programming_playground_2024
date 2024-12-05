#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[40];       // назва держави
    char language[40];   // мова
    char currency[40];   // грошова одиниця
    double exchangeRate; // курс валюти
} State;//size 128

// додавання записів до файлу
void addStatesToFile(const char *filename, int count) {
    FILE *f = fopen(filename, "wb");
    if (!f) {
        perror("Помилка при відкритті файлу для запису");
        exit(1);
    }

    State s;
    for (int i = 0; i < count; i++) {
        printf("Введіть дані для держави %d\n", i + 1);
        printf("Назва: ");
        scanf("%s", s.name);
        printf("Мова: ");
        scanf("%s", s.language);
        printf("Валюта: ");
        scanf("%s", s.currency);
        printf("Курс до $: ");
        scanf("%lf", &s.exchangeRate);
        fwrite(&s, sizeof(State), 1, f);
    }

    fclose(f);
}

//  виведення шо є в файлі
void printFileContent(const char *filename) {
    FILE *f = fopen(filename, "rb");
    if (!f) {
        perror("Помилка при відкритті файлу для читання");
        exit(1);
    }

    State s;
    printf("\nВміст файлу:\n");
    while (fread(&s, sizeof(State), 1, f)) {
        printf("Назва: %s, Мова: %s, Валюта: %s, Курс: %.2f\n", s.name, s.language, s.currency, s.exchangeRate);
    }

    fclose(f);
}


void deleteStateByName(const char *filename, const char *nameToDelete) {
    FILE *f = fopen(filename, "rb");
    FILE *temp = fopen("temp.dat", "wb");
    if (!f || !temp) {
        perror("Помилка при відкритті файлів");
        exit(1);
    }

    State s;
    while (fread(&s, sizeof(State), 1, f)) {
        if (strcmp(s.name, nameToDelete) != 0) {//для порівняння слів і воно юзає асінк кодування 
        //скіпає той момент коли ми мали би записувати певну державу в тимчасовий файл
            fwrite(&s, sizeof(State), 1, temp);
        }
    }

    fclose(f);
    fclose(temp);

    remove(filename);
    rename("temp.dat", filename);
}

// Функція для додавання двох нових записів до файлу
void appendStatesToFile(const char *filename) {
    FILE *f = fopen(filename, "ab");
    if (!f) {
        perror("Помилка при відкритті файлу для додавання");
        exit(1);
    }

    State s;
    for (int i = 0; i < 2; i++) {
        printf("Введіть дані для нової держави %d\n", i + 1);
        printf("Назва: ");
        scanf("%s", s.name);
        printf("Мова: ");
        scanf("%s", s.language);
        printf("Валюта: ");
        scanf("%s", s.currency);
        printf("Курс до $: ");
        scanf("%lf", &s.exchangeRate);
        fwrite(&s, sizeof(State), 1, f);
    }

    fclose(f);
}

int main() {
    const char *filename = "states.dat";

    // Додавання початкових записів
    printf("Додавання початкових записів:\n");
    addStatesToFile(filename, 5);

    // Виведення вмісту файлу
    printFileContent(filename);

    // Видалення запису за назвою
    char nameToDelete[40];
    printf("\nВведіть назву держави для видалення: ");
    scanf("%s", nameToDelete);

    deleteStateByName(filename, nameToDelete);

    // Виведення вмісту файлу після видалення
    printFileContent(filename);

    // Додавання двох нових записів
    printf("\nДодавання нових записів:\n");
    appendStatesToFile(filename);

    // Виведення фінального вмісту файлу
    printFileContent(filename);

    return 0;
}
