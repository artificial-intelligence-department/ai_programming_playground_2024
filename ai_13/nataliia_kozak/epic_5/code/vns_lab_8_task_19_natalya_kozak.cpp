#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;

typedef struct 
{
    char name[40];
    char director[40];
    char country[40];
    int profit;
}FILM;
istream &operator>> (istream &is, FILM &film){
    cout << "name = ";
    is >> film.name;
    cout << "director = ";
    is >> film.director;
    cout << "country = ";
    is >> film.country;
    cout << "profit = ";
    is >> film.profit;
    return is;
}
ostream &operator<< (ostream &os, FILM &film){
    os << "name = " << film.name << ", ";
    os << "director = " << film.director << ", ";
    os << "country = " << film.country << ", ";
    os << "profit = " << film.profit;
    return os;
}
FILE* delete_2_last(FILE *f){
    remove("f_new.dat");
    FILE *new_f;
    FILM temp[3];
    new_f = fopen("f_new.dat", "wb+");
    if(new_f == NULL)exit(1);
    fread(temp, sizeof(FILM), 3, f);
    fwrite(temp, sizeof(FILM), 3, new_f);
    rewind(new_f);
    return new_f;
}
FILE* add_new_film(char name[40], FILE *f, FILM newfm){
    remove("f_new2.dat");
    FILE *new_f;
    FILM temp[3];
    new_f = fopen("f_new2.dat", "wb+");
    if(new_f == NULL)exit(1);
    fread(temp, sizeof(FILM), 3, f);
    int index;
    for(int i = 0; i < 3; i++){
        if(name == temp[i].name){
            index = i;
        }
    }
    fwrite(temp, sizeof(FILM), index+1, new_f);
    if(fwrite(&newfm, sizeof(FILM), 1, new_f) != 1){
        cout << "problem is here";
    }
    fwrite(&temp[index+1], sizeof(FILM), index+1, new_f);
    rewind(new_f);
    return new_f;
}
int main(){
    remove("f.dat");
    FILE *f; 
    FILM films[5];

    for(int i = 0; i < 5; i++){
        cin >> films[i];  
    }
    
    f = fopen("f.dat", "wb+");
    if(f == NULL)exit(1);

    fwrite(films, sizeof(FILM), 5, f);
    for(int i = 0; i < 5; i++){
        cout << films[i] << endl;
    }
    rewind(f);
    f = delete_2_last(f);
    cout << "After which film to add a new one?" << endl;
    char name[40];
    cin >> name;
    bool is_in_file = false, letters_same;
    int j;
    for(int i = 0; i < 3; i++){
        j = 0;
        letters_same = true;
        while(name[j] != 0){
            if(name[j] != films[i].name[j]){
                letters_same = false;
                break;
            }
            j++;
        }
        if(letters_same){
            is_in_file = true;
            break;
        }
    }
    if(!is_in_file){
        cout << "no such film";
        return 0;
    }
    FILM newfm;
    cout << "Add new film after that:"<< endl;
    cin >> newfm;
    f = add_new_film(name, f, newfm);

    
    fread(films, sizeof(FILM), 4, f);
    for(int i = 0; i < 4; i++){
        cout << films[i] << endl;
    }
    return 0;
}

