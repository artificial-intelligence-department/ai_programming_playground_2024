#include <iostream>
#include <vector>
#include <ctime>
#include <fstream>
#include <cstdio>
#include <sstream>
#include <algorithm>

using namespace std;
using vint = vector<int>;
using ving = vector<string>;

struct type_auto
{
    string brand;
    int year;
    int price;
    ving colors;

    void saveToBinary(fstream &db) const
    {
        if (!db.is_open())
        {
            cerr << "Could not open database file.\n";
            return;
        }
        int brandSize = brand.size();
        db.write(reinterpret_cast<const char *>(&brandSize), sizeof(int));
        db.write(brand.c_str(), brandSize);

        db.write(reinterpret_cast<const char *>(&year), sizeof(int));
        db.write(reinterpret_cast<const char *>(&price), sizeof(int));

        int colorsCount = colors.size();
        db.write(reinterpret_cast<const char *>(&colorsCount), sizeof(int));
        for (const string &color : colors)
        {
            int colorSize = color.size();
            db.write(reinterpret_cast<const char *>(&colorSize), sizeof(int));
            db.write(color.c_str(), colorSize);
        }
    }

    void loadFromBinary(fstream &db)
    {
        if (!db.is_open())
        {
            cerr << "Could not open database file.\n";
            return;
        }

        int brandSize;
        if (!db.eof() && db.read(reinterpret_cast<char *>(&brandSize), sizeof(int)))
        {
            brand.resize(brandSize);
            db.read(&brand[0], brandSize);
            db.read(reinterpret_cast<char *>(&year), sizeof(int));
            db.read(reinterpret_cast<char *>(&price), sizeof(int));
            int colorsCount;
            db.read(reinterpret_cast<char *>(&colorsCount), sizeof(int));

            colors.resize(colorsCount);
            for (int i = 0; i < colorsCount; ++i)
            {
                int colorSize;
                db.read(reinterpret_cast<char *>(&colorSize), sizeof(int));
                colors[i].resize(colorSize);
                if (!db.read(&colors[i][0], colorSize))
                    ;
            }
        }
    }
};
class DasAuto
{

private:
    type_auto autoData;
    static string dbPath;
    bool delete_Flag = false;
    bool start_flag = false;

    static int CurrentYear()
    {
        time_t now = time(nullptr);
        tm *local = localtime(&now);
        return 1900 + local->tm_year;
    }

public:
    DasAuto(string brand = "unknown", int year = CurrentYear(), int price = 0, ving colors = {"white"})
    {
        this->autoData.brand = brand;
        this->autoData.year = year;
        this->autoData.price = price;
        this->autoData.colors = colors;
    }

    void saveAuto()
    {
        // якщо структуру не видалено то додає її в файл в кінці програми
        if (!delete_Flag)
        {
            fstream db((start_flag ? "temp" : dbPath), ios::out | ios::app | ios::binary);
            if (!db.is_open())
            {
                cerr << "\tfile error 1\t";
                return;
            }

            autoData.saveToBinary(db);// if temp it will be only this car here

            if (start_flag)
            {
                fstream db1(dbPath, ios::in | ios::binary);
                type_auto tempAuto;
                while (db1)
                {
                    tempAuto.loadFromBinary(db1);
                    if (db1)
                        tempAuto.saveToBinary(db);// write every next car agter its one
                }
                db.close();
                db1.close();
                remove(dbPath.c_str());
                rename("temp", dbPath.c_str());
            }
            else
                db.close();
        }
    }
    //////////////////////setters/getters///////////////////////////////////
    DasAuto &changeBrand(string data)
    {
        this->autoData.brand = data;
        return *this;
    }

    DasAuto &changePrice(int data)
    {
        this->autoData.price = data;
        return *this;
    }

    DasAuto &changeYear(int data)
    {
        this->autoData.year = data;
        return *this;
    }

    DasAuto &addColor(string color)
    {
        this->autoData.colors.push_back(color);
        return *this;
    }

    template <typename... Colors>
    DasAuto &addColor(string color, Colors... colors)
    {
        this->autoData.colors.push_back(color);
        return addColor(colors...);
    }

    DasAuto &deleteColors(string color)
    { // дуже крутий спосіб видалення
        this->autoData.colors.erase(remove(this->autoData.colors.begin(), this->autoData.colors.end(), color), this->autoData.colors.end());
        return *this;
    }

    template <typename... Colors>
    DasAuto &deleteColors(string color, Colors... colors)
    { // тут такий самий
        this->autoData.colors.erase(remove(this->autoData.colors.begin(), this->autoData.colors.end(), color), this->autoData.colors.end());
        return deleteColors(colors...);
    }

    string getBrand()
    {
        return this->autoData.brand;
    }
    /////////////////////////////////////////////////////////////////////////
    DasAuto &outputAutos()
    {
        fstream db(dbPath, ios::in | ios::binary);
        if (!db.is_open())
            cerr << "\tfile error 2\t";

        while (!db.eof())
        {
            type_auto autoData;
            autoData.loadFromBinary(db);
            if (!db)
                break;

            cout << "\n\n:::::::Auto:::::::\nbrand: " << autoData.brand
                 << "\ncolors: ";
            for (const string &color : autoData.colors)
                cout << color << " ";
            cout << "\nyear: " << autoData.year
                 << "\nprice: " << autoData.price;
        }
        db.close();
        return *this;
    }

    DasAuto &deleteOlder(int year)
    {
        // бере структуру з файлу якщо вона підходить по року то записує її у temp і так для всіх для поточної структури тільки ставить прапорець і вкінці видаляє попередній файл і перейменовує temp

        fstream db(dbPath, ios::in | ios::binary);
        fstream temp("temp", ios::out | ios::binary);
        if (!db.is_open() || !temp.is_open())
        {
            cerr << "\tfile error 3\t";
            return *this;
        }

        while (db)
        {
            type_auto autoData;
            autoData.loadFromBinary(db);
            if (!db)
                break;

            if (autoData.year >= year)
                autoData.saveToBinary(temp);
        }

        if (this->autoData.year < year)
            delete_Flag = true;

        temp.close();
        db.close();
        remove(dbPath.c_str());
        rename("temp", dbPath.c_str());
        return *this;
    }

    DasAuto &addInStart()
    {
        this->start_flag = true;
        return *this;
    }
};

void userInterface(bool error);
void userInterface();

void userActions(DasAuto Auto)
{
    cout << "\n\navaible actions for " << Auto.getBrand() << ": \n1 - save this auto\n2 - set another one\n3 - delete older year\n4 - output all saved autos\n5 - add this auto in start\n6 - leave it\nour autos have more actions, but I don`t wanna draw larger block-schema, so sorry :/\n";
    try
    {
        int action;
        cin >> action;

        switch (action)
        {
        case 1:
            Auto.saveAuto();
            break;
        case 2:
            userInterface(false);
            break;
        case 3:
        {
            int year;
            try
            {
                cout << "enter year: ";
                cin >> year;
            }
            catch (exception &e)
            {
                cerr << "error year\n";
                return userActions(Auto);
            }
            Auto.deleteOlder(year);
        }
        break;
        case 4:
            Auto.outputAutos();
            break;
        case 5:
            Auto.addInStart();
            break;
        case 6:
            return;
            break;
        default:
            cerr << "error action\n";
            return;
            break;
        }
        return userActions(Auto);
    }
    catch (exception &e)
    {
        cerr << "\nerror occured\n";
        return;
    }
}
void userInterface(bool error)
{
    type_auto newCar;
    try
    {
        cout << (error ? "try one more\nBrand: " : "hello here are automobile base!\n Please, enter your one: \nBrand: ");
        getline(cin, newCar.brand);
        if (newCar.brand.empty())
        {
            getline(cin, newCar.brand);
        }
    }
    catch (exception &e)
    {
        cerr << "error brand\n";
        return userInterface(true);
    }
    try
    {
        cout << "colors: ";
        string colors, color;
        getline(cin, colors);
        stringstream ss(colors);
        while (ss >> color)
            newCar.colors.push_back(color);
    }
    catch (exception &e)
    {
        cerr << "error colors\n";
        return userInterface(true);
    }
    try
    {
        cout << "year: ";
        cin >> newCar.year;
    }
    catch (exception &e)
    {
        cerr << "error year\n";
        return userInterface(true);
    }
    try
    {
        cout << "price: ";
        cin >> newCar.price;
    }
    catch (exception &e)
    {
        cerr << "error price\n";
        return userInterface(true);
    }
    DasAuto newAuto(newCar.brand, newCar.year, newCar.price, newCar.colors);
    userActions(newAuto);
}
void userInterface()
{
    userInterface(false);
}

string DasAuto::dbPath = R"(database.bin)";

int main()
{
    userInterface();
    return 0;
}