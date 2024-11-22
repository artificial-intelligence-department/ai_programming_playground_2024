#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "people.dat"

//Структура для запису інформації про людину
typedef struct {
    char surname[50];
    char name[50];
    char patronymic[50];
    char address[100];
    char phone[15];
    int age;
} Person;

// Функція для додавання людини у файл
void addPerson() {
    FILE *file = fopen(FILE_NAME, "ab");
    if (!file) {
        perror("Error opening file");
        exit(1);
    }

    Person person;
    printf("Enter details of the person:\n");
    printf("Surname: "); scanf("%s", person.surname);
    printf("Name: "); scanf("%s", person.name);
    printf("Patronymic: "); scanf("%s", person.patronymic);
    printf("Address: "); scanf("%s", person.address);
    printf("Phone: "); scanf("%s", person.phone);
    printf("Age: "); scanf("%d", &person.age);

    fwrite(&person, sizeof(Person), 1, file);

    fclose(file);
    printf("Person added successfully.\n");
}

//Функція для виводу вмісту файлу
void printFile() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (!file) {
        perror("Error opening file");
        exit(1);
    }

    Person person;
    printf("File contents:\n");
    while (fread(&person, sizeof(Person), 1, file)) {
        printf("Surname: %s, Name: %s, Patronymic: %s\n", person.surname, person.name, person.patronymic);
        printf("Address: %s, Phone: %s, Age: %d\n", person.address, person.phone, person.age);
        printf("---------------------------------\n");
    }

    fclose(file);
}

//Функція для видалення людини за віком
void deleteByAge(int age) {
    FILE *file = fopen(FILE_NAME, "rb");
    if (!file) {
        perror("Error opening file");
        exit(1);
    }
    //Створюємо тимчасовий файл
    FILE *temp = fopen("temp.dat", "wb");
    if (!temp) {
        perror("Error creating temporary file");
        fclose(file);
        exit(1);
    }

    //Записуємо у тимчасовий файл всіх людей окрім вказаного віку
    Person person;
    int found = 0;
    while (fread(&person, sizeof(Person), 1, file)) {
        if (person.age != age) {
            fwrite(&person, sizeof(Person), 1, temp);
        } else {
            found = 1;
        }
    }

    fclose(file);
    fclose(temp);

    //замінюємо наш початковий тимчасовим файлом
    remove(FILE_NAME);
    rename("temp.dat", FILE_NAME);

    if (found) {
        printf("Records with age %d have been deleted.\n", age);
    } else {
        printf("No records found with age %d.\n", age);
    }
}

//Функція для додавання людини після конкретного номера телефону
void addAfterPhone(char *phone) {
    FILE *file = fopen(FILE_NAME, "rb");
    if (!file) {
        perror("Error opening file");
        exit(1);
    }
    //Створюємо тимчасовий файл
    FILE *temp = fopen("temp.dat", "wb");
    if (!temp) {
        perror("Error creating temporary file");
        fclose(file);
        exit(1);
    }

    Person person, newPerson;
    int found = 0;

    printf("Enter details of the new person:\n");
    printf("Surname: "); scanf("%s", newPerson.surname);
    printf("Name: "); scanf("%s", newPerson.name);
    printf("Patronymic: "); scanf("%s", newPerson.patronymic);
    printf("Address: "); scanf("%s", newPerson.address);
    printf("Phone: "); scanf("%s", newPerson.phone);
    printf("Age: "); scanf("%d", &newPerson.age);

    //додаємо введену інформацію після запису із вказаним номером телефону
    while (fread(&person, sizeof(Person), 1, file)) {
        fwrite(&person, sizeof(Person), 1, temp);
        if (strcmp(person.phone, phone) == 0) {
            fwrite(&newPerson, sizeof(Person), 1, temp);
            found = 1;
        }
    }

    fclose(file);
    fclose(temp);

    //замінюємо наш початковий тимчасовим файлом
    remove(FILE_NAME);
    rename("temp.dat", FILE_NAME);

    if (found) {
        printf("New record added after the record with phone number %s.\n", phone);
    } else {
        printf("No record found with phone number %s.\n", phone);
    }
}

int main() {
    int choice, age;
    char phone[15];
    //реалізація меню
    while (1) {
        printf("\nMenu:\n");
        printf("1. Add a person\n");
        printf("2. Print file contents\n");
        printf("3. Delete records by age\n");
        printf("4. Add a record after a specific phone number\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPerson();
                break;
            case 2:
                printFile();
                break;
            case 3:
                printf("Enter age to delete records: ");
                scanf("%d", &age);
                deleteByAge(age);
                break;
            case 4:
                printf("Enter phone number: ");
                scanf("%s", phone);
                addAfterPhone(phone);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
