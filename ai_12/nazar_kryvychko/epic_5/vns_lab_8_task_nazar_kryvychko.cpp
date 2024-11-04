#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

static size_t aLength = 2;

typedef struct {
    char name[50];
    char surname[50];
    char last_name[50];
    char position[50];
    char birth_date[11];
    unsigned int salary;
} EMPLOYEE;

void print_emp(const EMPLOYEE& emp) {
    printf("Name: %s\nSurname: %s\nLast name: %s\nPosition: %s\nBirthdate: %s\nSalary: %u\n",
           emp.name, emp.surname, emp.last_name, emp.position, emp.birth_date, emp.salary);
}

void delete_with_surname(const char* surname) {
    EMPLOYEE* fEmps = new EMPLOYEE[aLength];
    FILE* fPtr = fopen("employees.bin", "rb");
    fread(fEmps, sizeof(EMPLOYEE), aLength, fPtr);
    fclose(fPtr);

    size_t cNewEms = aLength;
    for (size_t i = 0; i < aLength; i++) {
        if (strcmp(fEmps[i].surname, surname) == 0) {
            cNewEms--;
        }
    }

    EMPLOYEE* dEmps = new EMPLOYEE[cNewEms];
    size_t dEmpsI = 0;
    for (size_t i = 0; i < aLength; i++) {
        if (strcmp(fEmps[i].surname, surname) != 0) {
            dEmps[dEmpsI++] = fEmps[i];
        }
    }

    FILE* fnPtr = fopen("employees.bin", "wb");
    fwrite(dEmps, sizeof(EMPLOYEE), cNewEms, fnPtr);
    fclose(fnPtr);

    aLength = cNewEms;
    delete[] fEmps;
    delete[] dEmps;
}

void add_after(FILE* fptr, const unsigned int& number, const EMPLOYEE& newEmp) {
    EMPLOYEE* emps = new EMPLOYEE[aLength];
    fread(emps, sizeof(EMPLOYEE), aLength, fptr);
    
    EMPLOYEE* newEmps = new EMPLOYEE[aLength + 1];
    size_t empsI = 0;

    for (size_t i = 0; i < number - 1; i++) {
        newEmps[empsI++] = emps[i];
    }

    newEmps[empsI++] = newEmp;

    for (size_t i = number - 1; i < aLength; i++) {
        newEmps[empsI++] = emps[i];
    }

    FILE* fCptr = fopen("employees.bin", "wb");
    fwrite(newEmps, sizeof(EMPLOYEE), aLength + 1, fCptr);
    fclose(fCptr);

    delete[] emps;
    delete[] newEmps;
}

void read_employee_data(EMPLOYEE* emps, int count) {
    for (int i = 0; i < count; i++) {
        printf("Enter details for employee %d:\n", i + 1);
        printf("Name: ");
        fgets(emps[i].name, sizeof(emps[i].name), stdin);
        emps[i].name[strcspn(emps[i].name, "\n")] = '\0';

        printf("Surname: ");
        fgets(emps[i].surname, sizeof(emps[i].surname), stdin);
        emps[i].surname[strcspn(emps[i].surname, "\n")] = '\0';

        printf("Last Name: ");
        fgets(emps[i].last_name, sizeof(emps[i].last_name), stdin);
        emps[i].last_name[strcspn(emps[i].last_name, "\n")] = '\0';

        printf("Position: ");
        fgets(emps[i].position, sizeof(emps[i].position), stdin);
        emps[i].position[strcspn(emps[i].position, "\n")] = '\0';

        printf("Birth Date (YYYY-MM-DD): ");
        fgets(emps[i].birth_date, sizeof(emps[i].birth_date), stdin);
        emps[i].birth_date[strcspn(emps[i].birth_date, "\n")] = '\0';

        printf("Salary: ");
        scanf("%u", &emps[i].salary);
        getchar();
    }
}

int main() {
    FILE* fPtr;

    fPtr = fopen("employees.bin", "wb");
    if (!fPtr) {
        perror("Error opening file for writing");
        return EXIT_FAILURE;
    }

    EMPLOYEE* emps = new EMPLOYEE[aLength];  
    read_employee_data(emps, aLength); 

    fwrite(emps, sizeof(EMPLOYEE), aLength, fPtr);
    fclose(fPtr);
    delete[] emps; 

    fPtr = fopen("employees.bin", "rb");
    if (!fPtr) {
        perror("Error opening file for reading");
        return EXIT_FAILURE;
    }

    EMPLOYEE* rEmpArr = new EMPLOYEE[aLength];
    fread(rEmpArr, sizeof(EMPLOYEE), aLength, fPtr);
    fclose(fPtr);

    printf("\nEmployee Data from File:\n");
    for (int i = 0; i < aLength; i++) {
        printf("\n");
        print_emp(rEmpArr[i]);
        printf("\n");
    }

    printf("\nAfter delete with surname Olex\n");
    delete_with_surname("Olex");

    fPtr = fopen("employees.bin", "rb");
    if (!fPtr) {
        perror("Error opening file for reading");
        return EXIT_FAILURE;
    }

    EMPLOYEE* updatedEmps = new EMPLOYEE[aLength];
    fread(updatedEmps, sizeof(EMPLOYEE), aLength, fPtr);
    fclose(fPtr);

    printf("\nUpdated Employee Data from File:\n");
    for (size_t i = 0; i < aLength; i++) {
        printf("\n");
        print_emp(updatedEmps[i]);
        printf("\n");
    }

    EMPLOYEE newEmp;
    printf("Enter details for new employee to add:\n");
    printf("Name: ");
    fgets(newEmp.name, sizeof(newEmp.name), stdin);
    newEmp.name[strcspn(newEmp.name, "\n")] = '\0';  

    printf("Surname: ");
    fgets(newEmp.surname, sizeof(newEmp.surname), stdin);
    newEmp.surname[strcspn(newEmp.surname, "\n")] = '\0';

    printf("Last Name: ");
    fgets(newEmp.last_name, sizeof(newEmp.last_name), stdin);
    newEmp.last_name[strcspn(newEmp.last_name, "\n")] = '\0';

    printf("Position: ");
    fgets(newEmp.position, sizeof(newEmp.position), stdin);
    newEmp.position[strcspn(newEmp.position, "\n")] = '\0';

    printf("Birth Date (YYYY-MM-DD): ");
    fgets(newEmp.birth_date, sizeof(newEmp.birth_date), stdin);
    newEmp.birth_date[strcspn(newEmp.birth_date, "\n")] = '\0';

    printf("Salary: ");
    scanf("%u", &newEmp.salary);
    getchar();

    unsigned int position;
    printf("Enter the position (1 to %zu) after which to add the new employee: ", aLength);
    scanf("%u", &position);
    getchar();

    if (position > 0 && position <= aLength) {
        fPtr = fopen("employees.bin", "rb+");
        add_after(fPtr, position, newEmp);
        fclose(fPtr);
    } else {
        printf("Invalid position!\n");
    }

    fPtr = fopen("employees.bin", "rb");
    if (!fPtr) {
        perror("Error opening file for reading");
        return EXIT_FAILURE;
    }

    EMPLOYEE* finalEmps = new EMPLOYEE[aLength + 1];
    fread(finalEmps, sizeof(EMPLOYEE), aLength + 1, fPtr);
    fclose(fPtr);

    printf("\nFinal Employee Data from File:\n");
    for (size_t i = 0; i < aLength + 1; i++) {
        printf("\n");
        print_emp(finalEmps[i]);
        printf("\n");
    }

    delete[] rEmpArr; 
    delete[] updatedEmps; 
    delete[] finalEmps; 

    return 0;
}
