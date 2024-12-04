#include <iostream>
#include <cstdio>
#include <cstring>

enum FileOpResult{
    Success,
    Failure,
};

FileOpResult write_to_file(char *name, char *content){

    FILE *file = fopen(name, "w");
    if (!file) {
        std::cerr << "Error" << std::endl;
        return Failure;
    }

    auto written = fwrite(content, sizeof(char), strlen(content), file);
    if (written != strlen(content))
    return Failure;

    auto close = fclose(file);
    if(close != 0)
        return Failure;
    return Success;
}


FileOpResult copy_file(char *file_from, char *file_to){

    FILE *file1 = fopen(file_from, "r");
    if(!file1){
        std::cerr << "Error occured during openning \"file_from \"";
        return Failure;
    }
    
    FILE *file2 = fopen(file_to, "w"); 
    if(!file2){
        std::cerr << "Error occurred during openning \"file_to \"";
        return Failure;
    }
    char temp[30];
    while(fread(temp, sizeof(char), 1, file1) == 1){
        auto written = fwrite(temp, sizeof(char), 1, file2);
        if(written != 1){
            std::cerr << "Error occured during copying data. ";
            return Failure;
        }
    }

    auto close1 = fclose(file1);
    if(close1 != 0){
        std::cerr << "Error occured during cloing \"file_from\"";
        return Failure;
    }
    auto close2 = fclose(file2);
    if(close2 != 0){
        std::cerr << "Error occured during cloing \"file_to\"";
        return Failure;
    }

    return Success;

}




int main(){
    
    char content[30], name[15];
    std::cout << "Enter the name of your file: ";
    fgets(name, 15, stdin);
    name[strcspn(name, "\n")] = '\0';

    std::cout << "Enter content for your file: ";
    fgets(content, 30, stdin);
    content[strcspn(content, "\n")] = '\0';

    FileOpResult f1 = write_to_file(name, content);
    if(f1 == Success){
        std::cout << "Your data has benn successfuly saved. ";
    }
    else
        std::cout << "An error occured during saving your data. ";
    


    char name2[20];
    std::cout << "\nEnter the name of second file: ";
    fgets(name2, 20, stdin);
    name2[strcspn(name2, "\n")] = '\0';
    FileOpResult f2 = copy_file(name, name2);


    if(f2 == Success)
        std::cout << "Your data has been successfuly copied! ";

    return 0;
}