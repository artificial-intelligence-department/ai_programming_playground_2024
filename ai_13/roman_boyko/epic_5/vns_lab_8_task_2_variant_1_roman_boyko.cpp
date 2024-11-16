#include <iostream>
#include <vector>
using namespace std;
const int SIZE = 50;
const int ArrS = 3;
struct Abiturient
{
    char firstName[SIZE];
    char secondName[SIZE];
    int age;
    int marks[ArrS];
    int average;
};
enum FileOpResult
{
    Success,
    Failure
};

void addAbit(Abiturient &a);
void outputAbit(Abiturient &a);
FileOpResult writeDataToFile(Abiturient *a, int size, char *filename);
FileOpResult readDataFromFile(char *filename);
FileOpResult DeleteElemFromFile(char *filename, int index);
FileOpResult AddElemBySurname(char *filename, char surn[]);

int main()
{
    int size, index;
    char surn[SIZE];
    char filename[] = "Labs";
    cout << "Enter amount of abiturients you want to add: ";
    cin >> size;
    Abiturient *a = new Abiturient[size];
    for (int i = 0; i < size; i++)
    {

        cin.ignore();
        cout << "Abiturient: " << i + 1 << endl;
        addAbit(a[i]);
    }
    FileOpResult r = writeDataToFile(a, size, filename);
    if (r == Success)
    {
        cout << "Information added succesfully!" << endl;
    }
    else
    {
        cerr << "Error in adding information to file!" << endl;
    }
    readDataFromFile(filename);
    cout << "\nEnter index of abiturient you wanna to delete: ";
    cin >> index;
    FileOpResult r2 = DeleteElemFromFile(filename, index);
    if (r2 == Success)
    {
        cout << "Information deleted by index succesfully!" << endl;
    }
    else
    {
        cerr << "Error in deleting information from the file!" << endl;
    }
    cout << "\nEnter surname of abiturient: ";
    cin.ignore();
    cin.getline(surn, SIZE);
    FileOpResult r3 = AddElemBySurname(filename, surn);
    if (r3 == Success)
    {
        cout << "Information added by surname succesfully!" << endl;
    }
    else
    {
        cerr << "Error in adding information to the file!" << endl;
    }
    delete[] a;
}

void addAbit(Abiturient &a)
{
    cout << "Enter name: ";
    cin.getline(a.firstName, SIZE);
    cout << "Enter surname: ";
    cin.getline(a.secondName, SIZE);
    cout << "Enter age: ";
    cin >> a.age;
    int sum = 0;
    for (int j = 0; j < ArrS; j++)
    {
        cout << "Enter mark " << j + 1 << ": ";
        cin >> a.marks[j];
        sum += a.marks[j];
    }
    int averageMark = sum / 3;
    a.average = averageMark;
}

void outputAbit(Abiturient &a)
{
    cout << "Name: " << a.firstName << endl;
    cout << "Second name: " << a.secondName << endl;
    cout << "Age: " << a.age << endl;
    for (int i = 0; i < ArrS; i++)
    {
        cout << "Mark " << i + 1 << ": " << a.marks[i] << endl;
    }
    cout << "Average mark: " << a.average << endl;
}

FileOpResult writeDataToFile(Abiturient *a, int size, char *filename)
{
    FILE *fileStream = fopen(filename, "wb");
    if (fileStream != nullptr)
    {
        size_t write = fwrite(a, sizeof(Abiturient), size, fileStream);

        if (write != size)
        {
            return Failure;
        }
        fclose(fileStream);
        return Success;
    }
    else
    {
        return Failure;
    }
}

FileOpResult readDataFromFile(char *filename)
{
    FILE *fileStream = fopen(filename, "rb");
    Abiturient a;
    if (!fileStream)
    {
        return Failure;
    }
    while (fread(&a, sizeof(Abiturient), 1, fileStream))
    {
        outputAbit(a);
    }
    fclose(fileStream);
    return Success;
}

FileOpResult DeleteElemFromFile(char *filename, int index)
{
    FILE *fileStream = fopen(filename, "rb");
    Abiturient a;
    if (!fileStream)
    {
        return Failure;
    }
    vector<Abiturient> abiture;
    while (fread(&a, sizeof(Abiturient), 1, fileStream))
    {
        abiture.push_back(a);
    }
    fclose(fileStream);

    if (index < 0 || index >= abiture.size())
    {
        return Failure;
    }
    abiture.erase(abiture.begin() + index);

    fileStream = fopen(filename, "wb"); // Corrected variable name
    if (!fileStream)
    {
        return Failure;
    }

    size_t write = fwrite(abiture.data(), sizeof(Abiturient), abiture.size(), fileStream); // Fixed fwrite size
    if (write != abiture.size())
    {
        fclose(fileStream);
        return Failure;
    }
    fclose(fileStream);
    return Success;
}

FileOpResult AddElemBySurname(char *filename, char surn[])
{
    FILE *fileStream = fopen(filename, "rb");
    Abiturient a;
    if (!fileStream)
    {
        return Failure;
    }
    vector<Abiturient> abiture;
    while (fread(&a, sizeof(Abiturient), 1, fileStream))
    {
        abiture.push_back(a);
    }
    fclose(fileStream);
    Abiturient abit;
    cout << "Adding new abiturient: " << endl;
    addAbit(abit);
    bool found = true;
    for (int i = 0; i < abiture.size(); i++)
    {
        bool surnFound = true;
        for (int j = 0; j < SIZE; j++)
        {

            if (abiture[i].secondName[j] != surn[j])
            {
                surnFound = false;
                break;
            }
            if (abiture[i].secondName[j] == '\0' && surn[j] == '\0')
            {
                break;
            }
        }
        if (surnFound)
        {
            abiture.insert(abiture.begin() + i + 1, abit);
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "Surname is not found!" << endl;
        return Failure;
    }
    FILE *filestream = fopen(filename, "wb");
    if (!fileStream)
    {
        return Failure;
    }
    if (fileStream != nullptr)
    {
        size_t write = fwrite(abiture.data(), sizeof(abiture), abiture.size(), fileStream);
        if (write != abiture.size())
        {
            return Failure;
        }
        fclose(fileStream);
        return Success;
    }
    else
    {
        return Failure;
    }
}