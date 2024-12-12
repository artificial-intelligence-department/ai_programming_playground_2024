#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int* convert_name(string name)
{
    char c;
    for (int i = 0; i < name.length() - 1; i++)
    {
        for (int j = 0; j < name.length() - i - 1; j++)
        {
            if ((int)name[j] > (int)name[j + 1])
            {
                c = name[j];
                name[j] = name[j + 1];
                name[j + 1] = c;
            }
        }
    }
    
    int* user_index = new int[name.length()];
    for (int i = 0; i < name.length(); i++)
    {
        user_index[i] = (int)name[i] * 0.4;
    }
    
    return user_index;
}

double convert_value(double value, string measurementSystem)
{
    if (measurementSystem == "mile") return value * 1609.344;
    else if (measurementSystem == "mile_us") return value * 1609.347;
    else if (measurementSystem == "meter") return value;
    else 
    {
        cerr<<"Неправильно введена система числення"<<endl;
        return 0;
    }
}

void write_data_in_file(string file_name, int* user_index, int len_of_user_index)
{
    if (is_this_user_in_file(file_name, user_index, len_of_user_index))
    {
    }
    else 
    {
        
    }
}

bool is_this_user_in_file(string file_name, int* user_index, int len_of_user_index)
{
    ifstream in(file_name);
    if(!in.is_open())
    {
        cerr<<"Не вдалося відкрити файл"<<endl;
        return false;
    }

    int user_index_in_file, distance;
    while(in>>user_index_in_file>>distance)
    {
        int user = user_index_in_file;
        int len = len_of_user_index - 1;
        while ((user > 0) && (len >= 0))
        {
            if (user % 10 == user_index[len] % 10)
            {
                user /= 10;
                user_index[len] /= 10;
            }
            else break;
            
            if (user % 10 == user_index[len] % 10)
            {
                user /= 10;
                user_index[len] /= 10;
            }
            else break;

            len--;
        }

        if ((len < 0) && (user <= 0 )) 
        {
            in.close();
            return true;
        }
    }
    

    in.close();
    return false;
}




int main()
{
    string file_name_for_colecting_distance = "collected_distance.txt";

    string name;
    cout<<"Введіть ваше ім'я: ";
    cin>>name;
    
    int* user_index = new int[name.length()];
    user_index = convert_name(name);

    
    double value;
    cout<<"Введіть відстань: ";
    cin>>value;

    string measurementSystem;
    cout<<"Введіть одиницю виміру(meter / mile / mile_us): ";
    cin>>measurementSystem;

    double converted_value;
    converted_value = convert_value(value, measurementSystem);

    
    cout<<is_this_user_in_file(file_name_for_colecting_distance, user_index, name.length());

    return 0;
}