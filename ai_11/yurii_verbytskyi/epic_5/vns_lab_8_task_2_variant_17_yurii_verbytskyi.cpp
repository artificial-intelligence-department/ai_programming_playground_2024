#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

typedef struct {
    char title[100];
    char director[100];
    int year;
    float price;
} Film;

void createFilmFile(const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        perror("Error: can`t open file");
        return;
    }

    Film films[] = {
        {"The Godfather", "Francis Ford Coppola", 1972, 9.99},
        {"The Shawshank Redemption", "Frank Darabont", 1994, 14.99},
        {"The Dark Knight", "Christopher Nolan", 2008, 19.99}
    };

    size_t filmCount = sizeof(films) / sizeof(films[0]);
    fwrite(films, sizeof(Film), filmCount, file);

    fclose(file);
}

void addFilmBeforeDirector(const char *filename, const char *director, Film newFilm1, Film newFilm2) {
    FILE *file = fopen(filename, "rb+");
    if (file == NULL) {
        perror("Error: can`t open file");
        return;
    }

    Film films[MAX_LEN];
    size_t count = 0;

    while (fread(&films[count], sizeof(Film), 1, file)) {
        count++;
    }

    size_t i;
    for (i = 0; i < count; i++) {
        if (strcmp(films[i].director, director) == 0) {
            break;
        }
    }

    if (i < count) {
        memmove(&films[i + 2], &films[i], sizeof(Film) * (count - i));

        films[i] = newFilm1;
        films[i + 1] = newFilm2;
        count += 2;

        freopen(filename, "wb", file); 
        fwrite(films, sizeof(Film), count + 2, file); 
    } else {
        printf("Director not found.\n");
    }

    fclose(file);
}

void deleteFilmByIndex(const char *filename, size_t index) {
    FILE *file = fopen(filename, "rb+");
    if (file == NULL) {
        perror("Error: can`t open file");
        return;
    }

    Film films[MAX_LEN];
    size_t count = 0;

    while (fread(&films[count], sizeof(Film), 1, file)) {
        count++;
    }

    if (index >= count) {
        printf("The movie with this index was not found.\n");
        fclose(file);
        return;
    }

    for (size_t i = index; i < count - 1; i++) {
        films[i] = films[i + 1];
    }
    count--; 

    freopen(filename, "wb", file);  
    fwrite(films, sizeof(Film), count, file); 

    fclose(file);
}

void printFilms(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Error: can`t open file");
        return;
    }

    Film film;
    while (fread(&film, sizeof(Film), 1, file)) {
        if (strlen(film.title) == 0 && strlen(film.director) == 0 && film.year == 0 && film.price == 0) {
            continue;  
        }
        printf("Name: %s\n", film.title);
        printf("Director: %s\n", film.director);
        printf("Year of release: %d\n", film.year);
        printf("Price: %.2f\n\n", film.price);
    }

    fclose(file);
}

int main() {
    const char *filename = "films.dat";

    createFilmFile(filename);

    printf("Contents of the file before changes:\n");
    printFilms(filename);

    Film newFilm1 = {"Inception", "Christopher Nolan", 2010, 15.99};
    Film newFilm2 = {"Memento", "Christopher Nolan", 2000, 12.99};
    addFilmBeforeDirector(filename, "Christopher Nolan", newFilm1, newFilm2);

    printf("Contents of the file after changes:\n");
    printFilms(filename);

    deleteFilmByIndex(filename, 1);

    printf("The contents of the file after deleting the element:\n");
    printFilms(filename);

    return 0;
}
