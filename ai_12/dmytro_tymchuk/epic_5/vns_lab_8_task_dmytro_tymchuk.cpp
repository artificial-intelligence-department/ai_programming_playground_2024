#include<iostream>
#include<stdio.h>
using namespace std;

struct Music_disk
{
    char name[100];
    char author[100];
    int duration;
    double price;
};
//Функція для запису структури у файл
void add_data_in_file(const char* file_name)
{
    Music_disk disks[]{
        {"Meteora", "Linkin park", 40, 30.0},
        {"Nevermind", "Nirvana", 35, 25.5},
        {"Придумано в черзі", "Паліндром", 35, 42.25},
        {"8 роздумів", "OTOY", 28, 25.50},
        {"False light", "White ward", 50, 33.30}
    };

    FILE* music_file;
    music_file = fopen(file_name, "wb");

    if (music_file == nullptr)
    {
        cerr<<"Не вдалося відкрити файл для запису!";
        exit(0);
    }

    for (int i = 0; i < 5; i++)
    {
        if (fwrite(&disks[i], sizeof(Music_disk), 1, music_file) != 1)
        {
            cerr<<"Не вдалося записати дані у файл!";
            exit(0);
        }
    }
    fclose(music_file);
}
//Функція для запису структури у файл

//Функція для виведення даних з файлу
void print_file(const char* file_name)
{
    FILE* music_file;
    music_file = fopen(file_name, "rb");

    if (music_file == nullptr)
    {
        cerr<<"Не вдалося відкрити файл для читання!";
        exit(0);
    }

    Music_disk new_disk;
    while (fread(&new_disk, sizeof(Music_disk), 1, music_file) == 1)
    {
        cout<<"Назва: "<<new_disk.name<<endl;
        cout<<"Автор: "<<new_disk.author<<endl;
        cout<<"Довжина: "<<new_disk.duration<<endl;
        cout<<"Ціна: "<<new_disk.price<<endl;
        cout<<endl;
    }

    fclose(music_file);
}
//Функція для виведення даних з файлу

//Функція для видалення елемента з заданою довжиною
void delete_element_from_file(const char* file_name, int len)
{
    FILE* music_file;
    FILE* new_music_file;
    
    music_file = fopen(file_name, "rb");
    new_music_file = fopen("new_music_disk.dat", "wb");
 
    if (music_file == nullptr)
    {
        cerr<<"Не вдалося відкрити файл для читання!";
        exit(0);
    }
    if (new_music_file == nullptr)
    {
        cerr<<"Не вдалося відкрити файл для запису!";
        exit(0);
    }

    Music_disk new_disk; int flag = 0;
    while (fread(&new_disk, sizeof(Music_disk), 1, music_file))
    {
        if ((flag == 0) && (new_disk.duration == len))
        {
            flag = 1;
            continue;
        }
        else if (fwrite(&new_disk, sizeof(Music_disk), 1, new_music_file) != 1)
        {
            cerr<<"Не вдалося записати дані у файл!";
            exit(0);
        }
    }
    
    fclose(music_file);
    fclose(new_music_file);

    remove(file_name);
    rename("new_music_disk.dat", file_name);
    
    cout<<"Файл після видалення диску з заданою довжиною: "<<endl;
    print_file(file_name);   
}
//Функція для видалення елемента з заданою довжиною

//Функція для додавання двох елементів у файл
void add_elements_to_file (const char* file_name, int num)
{
    FILE* music_file;
    FILE* new_music_file;

    music_file = fopen(file_name, "rb");
    new_music_file = fopen("new_music_disks.dat", "wb");

    if (music_file == nullptr)
    {
        cerr<<"Не вдалося відкрити файл для читання!";
        exit(0);
    }
    if (new_music_file == nullptr)
    {
        cerr<<"Не вдалося відкрити файл для запису!";
        exit(0);
    }

    int i = 1, flag = 0;
    Music_disk new_disk;
    Music_disk new_two_disks[]{
        {"Encore", "Eminem", 45, 18.33},
        {"Amnesiac", "Radiohead", 43, 25.75}
    };
    while (fread(&new_disk, sizeof(Music_disk), 1, music_file) == 1)
    {
        if (fwrite(&new_disk, sizeof(Music_disk), 1, new_music_file) != 1)
        {
            cerr<<"Не вдалося записати дані у файл!";
            exit(0);
        }

        if (i == num)
        {
            if (fwrite(&new_two_disks[0], sizeof(Music_disk), 1, new_music_file) != 1)
            {
                cerr<<"Не вдалося записати дані у файл!";
                exit(0);
            }
            if (fwrite(&new_two_disks[1], sizeof(Music_disk), 1, new_music_file) != 1)
            {
                cerr<<"Не вдалося записати дані у файл!";
                exit(0);
            }

            flag = 1;
        }        
        i++;
    }

    fclose(music_file);
    fclose(new_music_file);

    if (flag == 1)
    {
        remove(file_name);
        rename("new_music_disks.dat", file_name);

        cout<<"Новий файл з доданими елементами: "<<endl;
        print_file(file_name);
    }
    else
    {
        cout<<"Ви не правильно ввели номер елемента, тому ми не змогли додати до файлу нові альбоми";
    }
}
//Функція для додавання двох елементів у файл

int main()
{
    const char* file_name = "music_disk.dat";
    add_data_in_file(file_name);
    print_file(file_name);

    int len;
    cout<<"Ведіть тривалість альбому, який потрібно видалити: ";
    cin>>len;
    delete_element_from_file(file_name, len);
    
    int num;
    cout<<"Введіть номер елемента, після якого потрібно додати ще два: ";
    cin>>num;
    add_elements_to_file(file_name, num);

    return 0;
}