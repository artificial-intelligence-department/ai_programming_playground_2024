#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_NUMBER_LENGTH 20

int main(void)
{
    // Open the phonebook file in append mode
    FILE *file = fopen("phonebook.csv", "a");
    if (file == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    // Allocate memory for name and number
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];

    // Get the name from the user
    printf("name: ");
    if (fgets(name, sizeof(name), stdin) == NULL)
    {
        printf("Error reading name\n");
        fclose(file);
        return 1;
    }
    // Remove the newline character at the end of the name
    name[strcspn(name, "\n")] = '\0';

    printf("number: ");
    if (fgets(number, sizeof(number), stdin) == NULL)
    {
        printf("Error reading number\n");
        fclose(file);
        return 1;
    }
    number[strcspn(number, "\n")] = '\0';

    fprintf(file, "%s,%s\n", name, number);

    fclose(file);

    return 0;
}
