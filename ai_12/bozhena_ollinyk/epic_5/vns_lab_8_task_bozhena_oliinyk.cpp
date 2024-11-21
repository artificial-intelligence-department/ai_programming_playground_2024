#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Human
{
    string initials;
    string adress;
    long long phone;
    int age;
};

void formFile(const char *filename)
{
    ofstream file(filename, ios::binary);
    if (file.is_open())
    {
        Human person[] = {
            {"Serhiy S. O.", "Shevchenka", 380954862571, 50},
            {"Maria O. R.", "Bandery", 380501486571, 20},
            {"Arsen B. B.", "Gorbachevskogo", 380965874855, 14},
            {"Matviy T. A.", "Naukova", 380954887215, 42},
            {"Juliett N. K.", "Struyska", 380501452369, 33},
        };

        for (const auto &human : person)
        {
            file << "Initials: " << human.initials << "\n";
            file << "Address: " << human.adress << "\n";
            file << "Phone number: " << human.phone << "\n";
            file << "Age: " << human.age << "\n";
            file << "--------------------------\n";
        }

        file.close();
    }
    else
    {
        cout << "Помилка у відкритті файлу!" << endl;
    }
}

void printFile(const char *filename)
{
    ifstream file(filename, ios::binary);
    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            cout << line << endl;
        }
        file.close();
    }
    else
    {
        cout << "Помилка у відкритті файлу!" << endl;
    }
}

void deleteAge(const char *filename, int targetAge)
{
    ifstream file(filename);
    ofstream tempFile("temp.txt");

    if (file.is_open() && tempFile.is_open())
    {
        string line;
        bool isDeleting = false;

        while (getline(file, line))
        {
            if (line.find("Age: ") != string::npos)
            {
                int age = stoi(line.substr(line.find(": ") + 2));
                if (age == targetAge)
                {
                    tempFile << "--------------------------\n";
                    while (getline(file, line) && line != "--------------------------")
                        ; 
                    continue;
                }
            }

            tempFile << line << "\n";
        }

        file.close();
        tempFile.close();
        remove(filename);
        rename("temp.txt", filename);
    }
    else
    {
        cout << "Помилка у відкритті файлу!" << endl;
    }
}



void addStatus(const char *filename, const string &targetPhone, const string &status)
{
    ifstream file(filename);
    ofstream tempFile("temp.txt");

    if (file.is_open() && tempFile.is_open())
    {
        string line;
        bool addStatusAfterPhone = false;

        while (getline(file, line))
        {
            tempFile << line << "\n";

            if (line.find("Phone number: ") != string::npos)
            {
                string phone = line.substr(line.find(": ") + 2);
                if (phone == targetPhone)
                {
                    addStatusAfterPhone = true;
                }
            }

            if (addStatusAfterPhone && line == "--------------------------")
            {
                tempFile << "Note: " << status<< endl;
                tempFile << "--------------------------\n";
                addStatusAfterPhone = false; 
            }
        }

        file.close();
        tempFile.close();
        remove(filename);
        rename("temp.txt", filename);
    }
    else
    {
        cout << "Помилка у відкритті файлу!" << endl;
    }
}


int main()
{
    const char *filename = "humans.txt";
    formFile(filename);
    cout << "Initial file content:" << endl << endl;
    printFile(filename);

    int targetAge = 20;
    cout << "\nDeleting person with age " << targetAge  << endl << endl;
    deleteAge(filename, targetAge);
    printFile(filename);

    string phone = "380501452369"; 
    cout << "\nAdding status after person with that phone number " << phone << endl << endl;
    addStatus(filename, phone, "мама");
    printFile(filename);

    return 0;
}
