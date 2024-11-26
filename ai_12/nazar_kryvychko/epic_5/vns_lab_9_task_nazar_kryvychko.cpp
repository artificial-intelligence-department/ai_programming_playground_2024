#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int countWordsInFile(const char* filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return -1;
    }

    int wordCount = 0;
    char line[100];  

    while (fgets(line, sizeof(line), file) != NULL) {
        line[strcspn(line, "\n")] = '\0';

        if (line[0] != '\0') {
            wordCount++;
        }
    }

    fclose(file);
    return wordCount;
}

int main() {
    FILE *inputFile = fopen("F1.txt", "r");
    FILE *outputFile = fopen("F2.txt", "w");
    FILE *oFRptr = fopen("F2.txt","r");

    if (inputFile == NULL) {
        perror("Error opening input file");
        return EXIT_FAILURE;
    }
    if (outputFile == NULL) {
        perror("Error opening output file");
        fclose(inputFile);  
        return EXIT_FAILURE;
    }

    char word[100];

    while (fscanf(inputFile, "%99s", word) == 1) {  
        if (word[0] == 'A') { 
            fprintf(outputFile, "%s\n", word); 
        }
    }
    fclose(inputFile);
    fclose(outputFile);

    int count = countWordsInFile("F2.txt");
    
    printf("Words in F2: %u", count);

   


    return EXIT_SUCCESS;
}
