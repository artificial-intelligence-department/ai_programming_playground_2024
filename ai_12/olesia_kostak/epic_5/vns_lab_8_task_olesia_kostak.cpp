#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

typedef struct 
{
    char name[50];
    char surname[50];
    char lastname[50];
    char birthDate[11];
    int height;
    int weight;  

} PERSON;

void readPersonData(PERSON* people, int len);
void printPersonData();
void deleteWithHeightAndWeight(int height, int weight);
void addAfterSurname(const PERSON& new_person, const char* target_surname); 



int main()
{
    int len = 2;
    PERSON* people = new PERSON[len];
    readPersonData(people, len);
    deleteWithHeightAndWeight(170, 50);
    std::cout << "After deliting" << std::endl << std::endl;
    printPersonData();

    std::cout << "After adding a new person" << std::endl << std::endl;
    PERSON newPerson = {"NewSurname", "NewName", "NewLastname", "2000-01-01", 180, 70};
    addAfterSurname(newPerson, "Kostak");
    printPersonData();



    delete[] people;
    return 0;
}

void readPersonData(PERSON* people, int len)
{
    FILE* fptr = fopen("people.bin", "wb");
    if(fptr == NULL)
    {
        cerr << "Error opening file" << endl;
        exit(1);
    }

    for(int i = 0; i < len; i++)
    {
        printf("Enter the information about %d person:\n", i + 1);

        printf("Name: ");
        fgets(people[i].name, sizeof(people[i].name), stdin);
        people[i].name[strcspn(people[i].name, "\n")] = '\0';

        printf("Surname: ");
        fgets(people[i].surname, sizeof(people[i].surname), stdin);
        people[i].surname[strcspn(people[i].surname, "\n")] = '\0';

        printf("Last Name: ");
        fgets(people[i].lastname, sizeof(people[i].lastname), stdin);
        people[i].lastname[strcspn(people[i].lastname, "\n")] = '\0';

        printf("Birth Date: ");
        fgets(people[i].birthDate, sizeof(people[i].birthDate), stdin);
        people[i].birthDate[strcspn(people[i].birthDate, "\n")] = '\0';

        printf("Height: ");
        scanf("%d", &people[i].height);

        printf("Weight: ");
        scanf("%d", &people[i].weight);
        getchar();  // To consume the newline character left by scanf
    }
    fwrite(people, sizeof(PERSON), len, fptr); 
    fclose(fptr);
}

void printPersonData()
{
    FILE* fptr = fopen("people.bin", "rb");
    if (fptr == NULL) 
    {
        cerr << "Error opening file" << endl;
        exit(1);
    }

    PERSON person;
    int i = 1;
    while (fread(&person, sizeof(PERSON), 1, fptr)) 
    {
        printf("Information about %d person:\n", i++);
        printf("Surname: %s\n", person.surname);
        printf("Name: %s\n", person.name);
        printf("Last Name: %s\n", person.lastname);
        printf("Birth Date: %s\n", person.birthDate);
        printf("Height: %i\n", person.height);
        printf("Weight: %i\n", person.weight);
    }
    fclose(fptr);
}

void deleteWithHeightAndWeight(int height, int weight)
{
    FILE* fptr = fopen("people.bin", "rb");
    if (fptr == NULL) 
    {
        cerr << "Error opening file" << endl;
        exit(1);
    }

    FILE* fptr_temp = fopen("temp.bin", "wb");
    if(fptr_temp == NULL)
    {
        cerr << "Error opening file" << endl;
        fclose(fptr);
        exit(1);
    }

    PERSON person;
    int newLen = 0;
    while (fread(&person, sizeof(PERSON), 1, fptr)) 
        if (person.height != height || person.weight != weight) 
        {
            fwrite(&person, sizeof(PERSON), 1, fptr_temp);
            newLen++;
        }
    fclose(fptr);
    fclose(fptr_temp);

    if(remove("people.bin") != 0 || rename("temp.bin", "people.bin"))
        std::cerr << "Error deleting objects" << std::endl;
}

void addAfterSurname(const PERSON& new_person, const char* target_surname) 
{
    FILE* fptr = fopen("people.bin", "rb");
    if (fptr == NULL) 
    {
        std::cerr << "Error opening file" << std::endl;
        exit(1);
    }

    FILE* fptr_temp = fopen("temp.bin", "wb");
    if(fptr_temp == NULL)
    {
        cerr << "Error opening file" << endl;
        fclose(fptr);
        exit(1);
    }

    PERSON person;
    while (fread(&person, sizeof(PERSON), 1, fptr)) 
    {
        fwrite(&person, sizeof(PERSON), 1, fptr_temp);
        if (strcmp(person.surname, target_surname) == 0)
            fwrite(&new_person, sizeof(PERSON), 1, fptr_temp); 
    }

    fclose(fptr);
    fclose(fptr_temp);

    if(remove("people.bin") != 0 || rename("temp.bin", "people.bin"))
        std::cerr << "Error deleting objects" << std::endl;
}