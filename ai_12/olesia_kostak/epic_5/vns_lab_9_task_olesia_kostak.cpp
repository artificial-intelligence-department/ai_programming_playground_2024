#include <stdio.h>
#include <stdlib.h> //for exit

void copy_file(const char* from_file, const char* to_file, int target);
int count_vowels(const char* filename2);

int main()
{
    const char* filename1 = "file1.txt";
    const char* filename2 = "file2.txt";
    printf("Enter the number of the line: ");
    int target;
    scanf("%d", target);
    copy_file(filename1, filename2, 2);
    printf("Number of vowel in file 2: %d", count_vowels(filename2));

    return 0;
}


void copy_file(const char* from_file, const char* to_file, int target)
{
    FILE* in = fopen(from_file, "r");
    FILE* out = fopen(to_file, "w");

    if (in == nullptr || out == nullptr)
    {
        perror("Error opening files");
        exit(1);
    }
    int current_point = 1;
    char buffer[256];
    while(fgets(buffer, sizeof(buffer), in) != NULL)
    {
        if(current_point >= target && current_point <= target + 5)
            fputs(buffer, out);
        current_point++;
    }
    if(fclose(in) != 0 || fclose(out) != 0)
    {
        perror("Error opening files");
        exit(1);
    }
}

int count_vowels(const char* filename2)
{
    FILE* fptr = fopen(filename2, "r");
    if(fptr == NULL)
    {
        perror("Error opening file");
        exit(1);
    }

    char buffer[256];
    int counter = 0;
    while(fgets(buffer, sizeof(buffer), fptr) != NULL)
        for(int i = 0; buffer[i] != '\0'; i++)
        {
            char ch = buffer[i];
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                counter++;
        }

    if(fclose(fptr) != 0)
    {
        perror("Error closing a file");
        exit(1);
    } 
    return counter;
}