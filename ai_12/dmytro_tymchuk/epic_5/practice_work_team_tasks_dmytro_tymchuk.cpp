#include<iostream>
#include<cstring>
using namespace std;

enum FileOpResult { Success, Failure};

FileOpResult add_to_file (const char* file_name_1, const char* content)
{
    if (file_name_1 == nullptr)
    {
        return Failure;
    }

    FILE* f1;
    f1 = fopen(file_name_1, "w");
    if (f1 == nullptr)
    {
        return Failure;
    }

    if (fwrite(content, sizeof(char), strlen(content), f1) != strlen(content))
    {
        fclose(f1);
        return Failure;
    }

    if (fclose(f1) != 0)
    {
        return Failure;
    }

    return Success;
}

FileOpResult copy_file(const char* file_from, const char* file_to)
{
    if (file_from == nullptr || file_to == nullptr)
    {
        return Failure;
    }

    FILE* f1;
    FILE* f2;
    f1 = fopen(file_from, "r");
    f2 = fopen(file_to, "w");

    if (file_from == nullptr || file_to == nullptr)
    {
        return Failure;
    }

    char c[256];

    while (fgets(c, sizeof(c), f1) != nullptr)
    {
        if (fputs(c, f2) == EOF)
        {
            fclose(f1);
            fclose(f2);
            return Failure;
        }
    }
  
    if (fclose(f1) != 0 || fclose(f2) != 0)
    {
        return Failure;
    }

    return Success;
}


int main()
{
    const char* file_name_1 = "file1.txt";
    const char* file_name_2 = "file2.txt";
    char content[256];

    cout<<"Введіть рядок, який треба вписати у файл: ";
    cin.getline(content, sizeof(content));

    if (add_to_file(file_name_1, content) == Failure)
    {
        cout<<"Не вдалося записати рядок до файлу"<<endl;
    }
    else cout<<"Рядок був успішно записаний до файлу"<<endl;

    if (copy_file(file_name_1, file_name_2) == Failure)
    {
        cout<<"Не вдалося скопіювати дані з першого файлу в другий"<<endl;
    }
    else cout<<"Дані з першого файлу були успішно скопійовані в другий"<<endl;

    return 0;
}