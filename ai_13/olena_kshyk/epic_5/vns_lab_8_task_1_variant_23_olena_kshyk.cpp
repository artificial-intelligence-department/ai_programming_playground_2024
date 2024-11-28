#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct stadion
{
    char name[40];
    int year;
    int platforms;
    char sport[40];
    friend istream &operator>>(istream &is, stadion &obj);
    friend ostream &operator<<(ostream &is, stadion &obj);
};

istream &operator>>(istream &is, stadion &obj)
{
    cout << "Enter name: ";
    is >> obj.name;
    cout << "Enter year: ";
    is >> obj.year;
    cout << "Enter number of platforms: ";
    is >> obj.platforms;
    cout << "Enter type of sport: ";
    is >> obj.sport;

    return is;
}

ostream &operator<<(ostream &os, stadion &obj)
{
    os << "Name: " << obj.name << endl;
    os << "Year: " << obj.year << endl;
    os << "Number of platforms: " << obj.platforms << endl;
    os << "Sport: " << obj.sport << endl;

    return os;
}

void add_new(FILE *f)
{
    stadion st;
    cin >> st;
    size_t result = fwrite(&st, sizeof(stadion), 1, f);
    if (result != 1)
        cerr << "Error writing to file" << endl;
}

void show_all(char *name)
{
    FILE *f;
    f = fopen(name, "rb");
    if (f == NULL)
    {
        cerr << "Error opening the file" << endl;
        return;
    }
    cout << endl;
    cout << "List of stadions" << endl;
    cout << "-------------------" << endl;
    stadion st;
    while (fread(&st, sizeof(st), 1, f))
    {
        cout << st;
        cout << endl;
    }

    fclose(f);
}

void delete_some(char *name, int target_year)
{
    FILE *f;
    f = fopen(name, "rb");
    if (f == NULL)
    {
        cerr << "Error opening the file" << endl;
        return;
    }

    FILE *temp = fopen("temp.dat", "wb");
    if (temp == NULL)
    {
        cerr << "Error opening the file" << endl;
        return;
    }

    stadion st;
    int deleted = 0;
    while (fread(&st, sizeof(st), 1, f))
    {
        if (st.year >= target_year)
        {
            size_t res = fwrite(&st, sizeof(stadion), 1, temp);
            if (res != 1)
            {
                cerr << "Error writing to file" << endl;
                return;
            }
        }
        else
            deleted = 1;
    }

    fclose(f);
    fclose(temp);
    if (deleted)
    {
        remove(name);
        rename("temp.dat", name);
    }
    else
        remove("temp.dat"); 
    cout << "Elements deleted" << endl;
}

void add_new_elem(char *name, int n, stadion &new_st1, stadion &new_st2)
{
    FILE *f;
    f = fopen(name, "rb");
    if (f == NULL)
    {
        cerr << "Error opening the file" << endl;
        return;
    }
    FILE *temp = fopen("temp.dat", "wb");
    if (temp == NULL)
    {
        cerr << "Error opening the file" << endl;
        return;
    }
    stadion st;
    int current = 1;
    int inserted = 0;

    while (fread(&st, sizeof(st), 1, f))
    {
        if (current == n && !inserted)
        {
            int res1 = fwrite(&new_st1, sizeof(new_st1), 1, temp);
            int res2 = fwrite(&new_st2, sizeof(new_st2), 1, temp);
            if (res1 != 1 || res2 != 1)
            {
                cerr << "Error writing to file" << endl;
                return;
            }
            else
                inserted = 1;
        }
        fwrite(&st, sizeof(st), 1, temp);
        current++;
    }
    if (!inserted && n == current)
    {
        int res1 = fwrite(&new_st1, sizeof(new_st1), 1, temp);
        int res2 = fwrite(&new_st2, sizeof(new_st2), 1, temp);
        if (res1 != 1 || res2 != 1)
        {
            cerr << "Error writing to file" << endl;
            return;
        }
    }

    fclose(f);
    fclose(temp);
    remove(name);
    rename("temp.dat", name);
    cout << "Elements added" << endl;
}

int main()
{
    char name[] = "database.dat";
    FILE *file;
    file = fopen(name, "wb");
    if (file == NULL)
    {
        cerr << "Error opening the file" << endl;
        return 1;
    }

    for (int i = 0; i < 5; i++)
        add_new(file);
    fclose(file);

    int y;
    cout << "Enter year: ";
    cin >> y;
    delete_some(name, y);

    stadion st1;
    stadion st2;
    int pos;
    cout << "Enter position: ";
    cin >> pos;
    cout << "Enter 2 new stadions: \n";
    cin >> st1;
    cin >> st2;
    add_new_elem(name, pos, st1, st2);

    show_all(name);

    return 0;
}