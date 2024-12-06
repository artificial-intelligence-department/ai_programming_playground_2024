#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    Success,
    Failure
} FileOpResult;

FileOpResult write_to_file(char *name, char *content) {
    // Перевірка на NULL для імені файлу
    if (name == NULL) {
        return Failure;
    }
    
    // Відкриваємо файл для запису (перезаписуємо його вміст, якщо існує)
    FILE *file = fopen(name, "w");
    
    // Перевірка на успішне відкриття файлу
    if (file == NULL) {
        return Failure;
    }
    
    // Записуємо вміст у файл
    if (content != NULL) {
        size_t written = fwrite(content, sizeof(char), strlen(content), file);
        // Перевірка на успішність запису
        if (written < strlen(content)) {
            fclose(file);
            return Failure;
        }
    }

    // Закриваємо файл
    if (fclose(file) != 0) {
        return Failure;
    }
    
    return Success;
}

int main() {
    char filename[256];
    char content[1024];

    // Зчитуємо ім'я файлу з вводу
    printf("Введіть ім'я файлу: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = 0; // Видаляємо символ нового рядка

    // Зчитуємо вміст для запису
    printf("Введіть вміст для запису у файл: ");
    fgets(content, sizeof(content), stdin);
    content[strcspn(content, "\n")] = 0; // Видаляємо символ нового рядка

    // Викликаємо функцію запису
    FileOpResult result = write_to_file(filename, content);
    
    if (result == Success) {
        printf("Файл успішно записано.\n");
    } else {
        printf("Сталася помилка під час запису у файл.\n");
    }

    return 0;
}