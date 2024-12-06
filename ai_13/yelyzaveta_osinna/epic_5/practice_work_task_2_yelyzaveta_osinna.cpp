#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    Success,
    Failure
} FileOpResult;

FileOpResult copy_file(char *file_from, char *file_to) {
    // Перевірка на NULL для імен файлів
    if (file_from == NULL || file_to == NULL) {
        return Failure;
    }

    // Відкриваємо файл для читання
    FILE *src_file = fopen(file_from, "rb");
    if (src_file == NULL) {
        return Failure; // Не вдалося відкрити файл для читання
    }

    // Відкриваємо файл для запису
    FILE *dest_file = fopen(file_to, "wb");
    if (dest_file == NULL) {
        fclose(src_file); // Закриваємо джерело, якщо не вдалося відкрити файл для запису
        return Failure; // Не вдалося створити файл для запису
    }

    // Копіюємо вміст
    char buffer[1024];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, sizeof(char), sizeof(buffer), src_file)) > 0) {
        size_t bytes_written = fwrite(buffer, sizeof(char), bytes_read, dest_file);
        if (bytes_written < bytes_read) {
            fclose(src_file);
            fclose(dest_file);
            return Failure; // Помилка запису
        }
    }

    // Перевіряємо на помилки при читанні
    if (ferror(src_file)) {
        fclose(src_file);
        fclose(dest_file);
        return Failure; // Помилка читання
    }

    // Закриваємо файли
    fclose(src_file);
    fclose(dest_file);

    return Success;
}

int main() {
    char file_from[256];
    char file_to[256];

    // Зчитуємо ім'я файлу-джерела
    printf("Введіть ім'я файлу-джерела: ");
    fgets(file_from, sizeof(file_from), stdin);
    file_from[strcspn(file_from, "\n")] = 0; // Видаляємо символ нового рядка

    // Зчитуємо ім'я файлу-призначення
    printf("Введіть ім'я файлу-призначення: ");
    fgets(file_to, sizeof(file_to), stdin);
    file_to[strcspn(file_to, "\n")] = 0; // Видаляємо символ нового рядка

    // Викликаємо функцію копіювання
    FileOpResult result = copy_file(file_from, file_to);
    
    if (result == Success) {
        printf("Файл успішно скопійовано.\n");
    } else {
        printf("Сталася помилка під час копіювання файлу.\n");
    }

    return 0;
}