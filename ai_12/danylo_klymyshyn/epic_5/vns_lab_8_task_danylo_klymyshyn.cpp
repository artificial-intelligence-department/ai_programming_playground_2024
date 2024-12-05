#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <limits>

struct CarOwner{

    char FirstNameSurname[50];
    int autoNumber;
    int licenseNumber;


};


void fillFile(int n){
    FILE* file = fopen("data.bin", "wb");
    if (!file) {
        std::cerr << "Error" << std::endl;
        return ;
    }


    CarOwner temp;
    bool check = false;
    for (int i = 0; i < n; ++i) {
        std::cout << i + 1<< " person:\n";
        std::cout << "Enter full name: ";
        std::cin.ignore();
        fgets(temp.FirstNameSurname, 50, stdin);
        
        size_t len = strlen(temp.FirstNameSurname);
        if (len > 0 && temp.FirstNameSurname[len - 1] == '\n') {
            temp.FirstNameSurname[len - 1] = '\0';
        }
        
        std::cout << "Enter auto number: ";
        std::cin >> temp.autoNumber;
        std::cout << "Enter license number: ";
        std::cin >> temp.licenseNumber;
        auto written = fwrite(&temp, sizeof(CarOwner), 1, file);
        if(written != 1)
            check = true;
    }
    if(check)
        std::cerr << "Error" << std::endl;
    else
        std::cout << "Your data has been saved" << std::endl;
    fclose(file);
    }





void readFile(){

    FILE* file = fopen("data.bin", "rb");
    if (!file) {
        std::cerr << "Error" << std::endl;
        return ;
    }

    std::cout << "\tYour current data: \n";
    CarOwner temp;
    while (fread(&temp, sizeof(CarOwner), 1, file) == 1){
        fputs(temp.FirstNameSurname, stdout);
        std::cout << " ";
        std::cout << temp.autoNumber << " ";
        std::cout << temp.licenseNumber << " \n";

    }
    fclose(file);

}


void deleteNumber(int n){

FILE *file_read = fopen("data.bin", "rb");
if(!file_read){
    std::cerr << "Error openning file.";
    return ;
}

CarOwner temp;

CarOwner *array = new CarOwner[n];

int i = 0;
while(fread(&temp, sizeof(CarOwner), 1, file_read) == 1){
    array[i] = temp;
    ++i;
}

fclose(file_read);

FILE *file_delete = fopen("data.bin", "wb");

if(!file_delete){
    std::cerr << "Error openning file.";
    delete[] array;
    return ;
}


int delete_number;
std::cout << "Enter auto number of person you want to delete: ";
std::cin >> delete_number;

bool check = false;
for(int i = 0; i < n; ++i){
    if(array[i].autoNumber == delete_number)
        continue;
    auto written = fwrite(&array[i], sizeof(CarOwner), 1, file_delete);
    if( written != 1)
        check = true;
}
    if(!check)
        std::cout << "Data has benn successfully deleted." << std::endl;
    else{
        std::cerr << "Error deleting data. " << std::endl;
        delete[] array;
        return ;
    }

fclose(file_delete);
delete[] array;

readFile();

}



void addTwoEl(int n){
    FILE *read_file = fopen("data.bin", "rb");

    struct CarOwner *temp_arr = new CarOwner[n + 2];

if(!read_file){
    std::cerr << "Error openning file.";
    delete[] temp_arr;
    return ;
}
    char surn[50];
    std::cout << "Enter surname: ";
    std::cin.ignore();
    fgets(surn, 50, stdin);
    int len = strlen(surn);
    
    if (len > 0 && surn[len - 1] == '\n') {
        surn[len - 1] = '\0';
    }
    
    const char delimiters[] = " ,.";
    
    CarOwner temp;
    int i = 0;
    while (fread(&temp, sizeof(CarOwner), 1, read_file) == 1){
        temp_arr[i] = temp;
        ++i;
    }

    fclose(read_file);

    for (int i = 0; i < n + 1; i++) {
        if (strcmp(temp_arr[i].FirstNameSurname, surn) == 0) {

            for (int j = n ; j > i ; --j) {
                temp_arr[j+1] = temp_arr[j-1];
            }

            std::cout << "Enter first new full name: ";
            char x[30];
            std::cin.getline(temp_arr[i].FirstNameSurname, sizeof(temp));
            len = strlen(temp_arr[i].FirstNameSurname);
            if (len > 0 && temp_arr[i].FirstNameSurname[len - 1] == '\n') {
                temp_arr[i].FirstNameSurname[len - 1] = '\0';
            }
            std::cout << "Enter auto number: ";
            std::cin >> temp_arr[i].autoNumber;
            std::cout << "Enter license number: ";
            std::cin >> temp_arr[i].licenseNumber;

            std::cout << "Enter second new full name: ";
            std::cin.ignore();
            std::cin.getline(temp_arr[i+1].FirstNameSurname, sizeof(temp));
            len = strlen(temp_arr[i+1].FirstNameSurname);
            if (len > 0 && temp_arr[i+1].FirstNameSurname[len - 1] == '\n') {
                temp_arr[i+1].FirstNameSurname[len - 1] = '\0';
            }
            std::cout << "Enter auto number: ";
            std::cin >> temp_arr[i+1].autoNumber;
            std::cout << "Enter license number: ";
            std::cin >> temp_arr[i+1].licenseNumber;
            break;
        }
    }
    
    FILE *write_file = fopen("data.bin", "wb");

    bool check = false;
    for(int i = 0; i < n + 1; ++i){
        auto written = fwrite(&temp_arr[i], sizeof(CarOwner), 1, write_file);
        if(written == 0)
            check = true;
    }
    if(check){
        std::cerr << "Error during changing data." << std::endl;
        delete[] temp_arr;
        return ;
    }
    else
        std::cout << "Data has been changed." << std::endl;
    fclose(write_file);
    delete[] temp_arr;

    readFile();

}






int main(){

int n;
std::cout << "How much elements you want to enter: ";
std::cin >> n;

fillFile(n);

///readFile();
deleteNumber(n);

addTwoEl(n);



    return 0;
}