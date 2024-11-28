#include <string.h>
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
} FILM;
istream &operator>>(istream &is, FILM &film)
{
    cout << "\nname = ";
    is >> film.name;
    cout << "director = ";
    is >> film.director;
    cout << "country = ";
    is >> film.country;
    cout << "profit = ";
    is >> film.profit;
    return is;
}
ostream &operator<<(ostream &os, FILM &film)
{
    os << "name = " << film.name << ", "
       << "director = " << film.director << ", "
       << "country = " << film.country << ", "
       << "profit = " << film.profit;
    return os;
}
FILE *delete_2_last(FILE *f)
{
    FILE *new_f;
    FILM temp[3];
    new_f = fopen("f_new.dat", "wb+");
    if (new_f == NULL)
        exit(1);
    fread(temp, sizeof(FILM), 3, f);
    fwrite(temp, sizeof(FILM), 3, new_f);
    rewind(new_f);
    return new_f;
}
FILE *add_new_film(int index, FILE *f, FILM newfm)
{
    FILE *new_f;
    FILM temp[3];
    new_f = fopen("f_new2.dat", "wb+");
    if (new_f == NULL)
        exit(1);
    fread(temp, sizeof(FILM), 3, f);

    fwrite(temp, sizeof(FILM), index + 1, new_f);
    fwrite(&newfm, sizeof(FILM), 1, new_f);
    fwrite(&temp[index + 1], sizeof(FILM), 2 - index, new_f);
    rewind(new_f);
    return new_f;
}
int main()
{
    FILE *f;
    FILM films[5];

    for (int i = 0; i < 5; i++)
    {
        cin >> films[i];
    }

    f = fopen("f.dat", "wb+");
    if (f == NULL)
        exit(1);

    fwrite(films, sizeof(FILM), 5, f);
    for (int i = 0; i < 5; i++)
    {
        cout << films[i] << endl;
    }
    rewind(f);
    f = delete_2_last(f);
    cout << "After which film to add a new one?" << endl;
    char name[40];
    cin >> name;
    int index = -1;
    for (int i = 0; i < 3; i++)
    {
        if (!strcmp(name, films[i].name))
        {
            index = i;
            break;
        }
    }
    if (index == -1)
    {
        cout << "No such film";
        exit(1);
    }
    FILM newfm;
    cout << "Add new film after that:" << endl;
    cin >> newfm;
    f = add_new_film(index, f, newfm);

    fread(films, sizeof(FILM), 4, f);
    for (int i = 0; i < 4; i++)
    {
        cout << films[i] << endl;
    }
    return 0;
}
