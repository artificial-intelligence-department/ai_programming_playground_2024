#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct car{
    int year;
    char model[10];
    char driver_name[15];
    double engine_size;
} car;

void print_mycar_stats(car *c){
    printf("Year of car being made: %i, model of car: %s, driver name: %s, engine size: %.1f\n", c -> year, c -> model, c -> driver_name, c -> engine_size);
}

int main(void){
    car *mycar = malloc(sizeof(car));
    mycar -> year = 2025;
    strcpy(mycar -> model, "Tesla");
    strcpy(mycar -> driver_name, "Iryna");
    mycar -> engine_size = 16.5;

    print_mycar_stats(mycar);
}
